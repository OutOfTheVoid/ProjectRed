#include <Red/Text/Rendering/ShadedRenderer.h>
#include <Xenon/Geometry/Primitives.h>

#include <iostream>

const char * _ShadedRenderer_VertexShader =
"#version 150\n"

"in vec2 Position;\n"
"in mat3 CharachterTransform;\n"
"in vec4 TexturePosition;\n"

"uniform mat3 GlobalTransform;\n"
"uniform float RenderDepth;\n"

"out vec2 TransformedTexturePosition;\n"

"void main ()\n"
"{\n"

"	TransformedTexturePosition = vec2 ( TexturePosition.x + Position.x * TexturePosition.z, TexturePosition.y + Position.y * TexturePosition.w );\n"

"	gl_Position = vec4 ( vec2 ( vec3 ( Position, 1.0 ) * CharachterTransform * GlobalTransform ), RenderDepth, 1.0 );\n"

"}";


const char * _ShadedRenderer_FragmentShader =
"#version 150\n"

"in vec2 TransformedTexturePosition;\n"

"uniform vec4 Color;\n"
"uniform sampler2D AtlasSampler;\n"

"out vec4 OutputColor;\n"

"void main ()\n"
"{\n"

"	OutputColor = vec4 ( Color.rgb, Color.a * texture ( AtlasSampler, TransformedTexturePosition ).r );\n"

"}";

Red::Text::Rendering::ShadedRenderer :: ShadedRenderer ( FontRenderData * FontData ):
	FontData ( FontData ),
	CurrentAtlas ( NULL ),
	AtlasTexture (),
	AtlasSamplerUniform ( 0 ),
	TextureUploaded ( false ),
	PixelSize ( 20.0 ),
	ScalingTolerance ( 4.0 ),
	QuadMesh ( NULL ),
	CharachterTransformBuffer ( Xenon::GPU::VertexBuffer :: kUsageType_Dynamic_Draw ),
	CharachterTexturePositionBuffer ( Xenon::GPU::VertexBuffer :: kUsageType_Dynamic_Draw ),
	CurrenBufferLength ( 0 ),
	TextureCoordinateArray ( NULL ),
	TransformArray ( NULL ),
	VShader ( _ShadedRenderer_VertexShader, "ShadedRenderer :: VertexShader" ),
	FShader ( _ShadedRenderer_FragmentShader, "ShadedRenderer :: FragmentShader" ),
	Program ( "ShadedRenderer :: Program" ),
	Uniforms (),
	Color ( 0.0f, 0.0f, 0.0f, 1.0f ),
	ColorUniform ( & Color ),
	ExternalGlobalTransform (),
	GlobalTransform ( Xenon::Math::Matrix3x3 :: NO_INIT ),
	GlobalTransformUniform ( & GlobalTransform, false ),
	DepthUniform ( 0.5 ),
	DepthTesting ( false ),
	Bounds ( kWidth_Unbounded, kHeight_Unbounded ),
	VArray (),
	Cont ( NULL ),
	RenderTarget ( NULL ),
	RenderTargetDimensions ( 0.0, 0.0 ),
	CachedRenderDirty ( true ),
	LastString ( U"" ),
	GPUAllocated ( false )
{
	
	if ( FontData != NULL )
		FontData -> Reference ();
	
	// Prevent automatic destruction on destruction of Uniforms.
	AtlasSamplerUniform.Reference ();
	DepthUniform.Reference ();
	ColorUniform.Reference ();
	GlobalTransformUniform.Reference ();
	
	Program.Reference ();
	
	Uniforms.AddFloatUniform ( "RenderDepth", & DepthUniform );
	Uniforms.AddFloatVec4Uniform ( "Color", & ColorUniform );
	Uniforms.AddMatrix3x3Uniform ( "GlobalTransform", & GlobalTransformUniform );
	Uniforms.AddIntUniform ( "AtlasSampler", & AtlasSamplerUniform );
	
	Xenon::Geometry::Primitives :: Quad2DSpec RenderQuadSpec;
	RenderQuadSpec.WindOutwardFacesClockwise = true;
	RenderQuadSpec.Attributes = Xenon::Geometry::Primitives :: kAttributeFlags_Position;
	RenderQuadSpec.CompositionMode = Xenon::Geometry::Primitives :: kStaticAttributeCompositionMode_Interleaved;
	RenderQuadSpec.TexturePositionCount = 0;
	RenderQuadSpec.PositionSpec.Positions [ Xenon::Geometry::Primitives :: kQuad2DVertexIndex_XNeg_YNeg ] = Xenon::Math :: Vec2 ( 0.0, 0.0 );
	RenderQuadSpec.PositionSpec.Positions [ Xenon::Geometry::Primitives :: kQuad2DVertexIndex_XPos_YNeg ] = Xenon::Math :: Vec2 ( 1.0, 0.0 );
	RenderQuadSpec.PositionSpec.Positions [ Xenon::Geometry::Primitives :: kQuad2DVertexIndex_XNeg_YPos ] = Xenon::Math :: Vec2 ( 0.0, 1.0 );
	RenderQuadSpec.PositionSpec.Positions [ Xenon::Geometry::Primitives :: kQuad2DVertexIndex_XPos_YPos ] = Xenon::Math :: Vec2 ( 1.0, 1.0 );
	RenderQuadSpec.PositionSpec.AttributeName = "Position";
	RenderQuadSpec.PositionSpec.Static = true;
	Xenon::Geometry::Primitives :: GenerateQuad2DMesh ( & QuadMesh, RenderQuadSpec );
	
}

Red::Text::Rendering::ShadedRenderer :: ~ShadedRenderer ()
{
	
	SetRenderTarget ( NULL, NULL, Xenon::Math::Vec2 ( 0.0, 0.0 ) );
	SetFontData ( NULL );
	
	GPUResourceFree ();
	
}

void Red::Text::Rendering::ShadedRenderer :: SetFontData ( FontRenderData * FontData )
{
	
	if ( this -> FontData != FontData )
	{
		
		CachedRenderDirty = true;
		
		if ( this -> FontData != NULL )
		{
			
			if ( CurrentAtlas != NULL )
			{
				
				this -> FontData -> RetireFontTextureAtlas ( CurrentAtlas );
				
				CurrentAtlas = NULL;
				
			}
			
			this -> FontData -> Dereference ();
			
		}
		
		this -> FontData = FontData;
		
		if ( this -> FontData != NULL )
		{
			
			this -> FontData -> Reference ();
			
			CurrentAtlas = this -> FontData -> CreateFontTextureAtlas ( PixelSize, ScalingTolerance );
			
		}
		
	}
	
}

void Red::Text::Rendering::ShadedRenderer :: PreAllocBuffer ( uint32_t MaxCharCount )
{
	
	if ( CurrenBufferLength >= MaxCharCount )
		return;
	
	if ( TextureCoordinateArray != NULL )
		delete [] TextureCoordinateArray;
	
	if ( TransformArray != NULL )
		delete [] TransformArray;
	
	TextureCoordinateArray = new Xenon::Math :: Vec4 [ MaxCharCount ];
	TransformArray = new Xenon::Math :: Matrix3x3 [ MaxCharCount ];
	
	CachedRenderDirty = true;
	
}

void Red::Text::Rendering::ShadedRenderer :: TrimBuffer ( uint32_t MaxCharCount )
{
	
	if ( CurrenBufferLength <= MaxCharCount )
		return;
	
	if ( TextureCoordinateArray != NULL )
		delete [] TextureCoordinateArray;
	
	if ( TransformArray != NULL )
		delete [] TransformArray;
	
	TextureCoordinateArray = new Xenon::Math :: Vec4 [ MaxCharCount ];
	TransformArray = new Xenon::Math :: Matrix3x3 [ MaxCharCount ];
	
	CachedRenderDirty = true;
	
}

void Red::Text::Rendering::ShadedRenderer :: SetScalingTolerance ( double ScalingTolerance )
{
	
	if ( ScalingTolerance > this -> ScalingTolerance )
	{
		
		this -> ScalingTolerance = ScalingTolerance;
		
		return;
		
	}
	
	CachedRenderDirty = true;
	
	if ( ( FontData != NULL ) && ( CurrentAtlas != NULL ) )
		FontData -> RetireFontTextureAtlas ( CurrentAtlas );
	
	this -> ScalingTolerance = ScalingTolerance;
	
	if ( FontData != NULL )
	{
		
		CurrentAtlas = FontData -> CreateFontTextureAtlas ( PixelSize, ScalingTolerance );
		
		UploadTexture ( true );
		
	}
	
}

double Red::Text::Rendering::ShadedRenderer :: GetScalingTolerance ()
{
	
	return ScalingTolerance;
	
}

void Red::Text::Rendering::ShadedRenderer :: SetSize ( double PixelSize )
{
	
	if ( ( FontData != NULL ) && ( CurrentAtlas != NULL ) )
		FontData -> RetireFontTextureAtlas ( CurrentAtlas );
	
	this -> PixelSize = PixelSize;
	
	if ( FontData != NULL )
	{
		
		CurrentAtlas = FontData -> CreateFontTextureAtlas ( PixelSize, ScalingTolerance );
		
		UploadTexture ( true );
		
	}
	
	CachedRenderDirty = true;
	
}

double Red::Text::Rendering::ShadedRenderer :: GetSize ()
{
	
	return PixelSize;
	
}

void Red::Text::Rendering::ShadedRenderer :: SetRenderTarget ( Xenon::GPU :: Context * Cont, Xenon::GPU :: FrameBuffer * RenderTarget, Xenon::Math::Vec2 Dimensions )
{
	
	if ( this -> RenderTarget != NULL )
		this -> RenderTarget -> Dereference ();
	
	bool GPUAlloc = false;
	
	if ( this -> Cont != NULL )
	{
		
		GPUAlloc = GPUAllocated;
		
		this -> Cont -> Dereference ();
		
		GPUResourceFree ();
		
	}
	
	this -> RenderTarget = RenderTarget;
	this -> Cont = Cont;
	this -> RenderTargetDimensions = Dimensions;
	
	if ( this -> RenderTarget != NULL )
		this -> RenderTarget -> Reference ();
	
	if ( this -> Cont != NULL )
	{
		
		this -> Cont -> Reference ();
	
		if ( GPUAlloc )
			GPUResourceAlloc ();
		
	}
	
}

void Red::Text::Rendering::ShadedRenderer :: SetColor ( const Xenon::Math :: Vec4 Color )
{
	
	this -> Color = Color;
	
	ColorUniform.SetDirty ();
	
}

Xenon::Math :: Vec4 Red::Text::Rendering::ShadedRenderer :: GetColor ()
{
	
	return Color;
	
}

void Red::Text::Rendering::ShadedRenderer :: SetGlobalTransform ( const Xenon::Math :: Matrix3x3 & Transform )
{
	
	Xenon::Math::Matrix3x3 :: Copy ( this -> ExternalGlobalTransform, Transform );
	
}

void Red::Text::Rendering::ShadedRenderer :: SetBounds ( Xenon::Math :: Vec2 Bounds )
{
	
	this -> Bounds = Bounds;
	
	CachedRenderDirty = true;
	
}

Xenon::Math :: Vec2 Red::Text::Rendering::ShadedRenderer :: GetBounds ()
{
	
	return Bounds;
	
}

void Red::Text::Rendering::ShadedRenderer :: SetRenderDepth ( double Depth )
{
	
	DepthUniform.SetValue ( Depth );
	
}

double Red::Text::Rendering::ShadedRenderer :: GetRenderDepth ()
{
	
	return DepthUniform.GetValue ();
	
}

void Red::Text::Rendering::ShadedRenderer :: SetDepthTestEnabled ( bool Enabled )
{
	
	DepthTesting = Enabled;
	
}

bool Red::Text::Rendering::ShadedRenderer :: GetDepthTestEnabled ()
{
	
	return DepthTesting;
	
}

void Red::Text::Rendering::ShadedRenderer :: RenderUnicodeString ( const std :: u32string & String )
{
	
	if ( ( FontData == NULL ) || ( RenderTarget == NULL ) || ( QuadMesh == NULL ) || ( Cont == NULL ) )
		return;
	
	if ( CurrentAtlas == NULL )
	{
		
		CurrentAtlas = FontData -> CreateFontTextureAtlas ( PixelSize, ScalingTolerance );
		
		if ( CurrentAtlas == NULL )
			return;
		
	}
	
	if ( ! GPUAllocated )
		GPUResourceAlloc ();
	
	UploadTexture ( false );
	
	uint32_t StringLength = String.size ();
	
	if ( StringLength == 0 )
		return;
	
	PreAllocBuffer ( StringLength );
	
	uint32_t StringIndex = 0;
	uint32_t RenderCharIndex = 0;
	char32_t CurrentCharachter = U'\0';
	char32_t LastCharachter = 0;
	
	Xenon::Math :: Vec2 Cursor ( 0.0, 0.0 );
	
	// TODO: Implement baseline repositioning to align text to upper left corner.
	/*double MinX = 0.0;
	double MinY = 0.0;*/
	
	double BitmapWidth = CurrentAtlas -> GetBitmapWidth ();
	double BitmapHeight = CurrentAtlas -> GetBitmapHeight ();
	
	const IFontLayoutSource * Layout = FontData -> GetLayoutSource ();
	
	double BitmapScalingFactor = Layout -> GetScalingFactor ( CurrentAtlas, PixelSize );
	double ScalingFactorX = 2.0 / RenderTargetDimensions.X;
	double ScalingFactorY = 2.0 / RenderTargetDimensions.Y;
	
	while ( StringIndex < StringLength )
	{
		
		LastCharachter = CurrentCharachter;
		CurrentCharachter = String [ StringIndex ];
		
		if ( CurrentAtlas -> GlyphExists ( CurrentCharachter ) )
		{
			
			RawFontTextureAtlas :: GlyphMetrics Metrics = CurrentAtlas -> GetGlyphMetrics ( CurrentCharachter );
			
			Xenon::Math::Matrix3x3 & CharTransform = TransformArray [ RenderCharIndex ];
			
			Xenon::Math::Matrix3x3 :: SetAsScale ( CharTransform, BitmapScalingFactor * Metrics.Width, BitmapScalingFactor * Metrics.Height );
			
			double TranslationX = 0;
			double TranslationY = 0;
			
			double OffsetX = 0;
			double OffsetY = 0;
			
			Layout -> GetOffset ( CurrentAtlas, CurrentCharachter, OffsetX, OffsetY );
			
			TranslationX += OffsetX;
			TranslationY += OffsetY;
			
			Layout -> GetAdvance ( CurrentAtlas, CurrentCharachter, LastCharachter, OffsetX, OffsetY );
			
			Cursor.X += OffsetX;
			Cursor.Y += OffsetY;
			
			TranslationX += Cursor.X;
			TranslationY += Cursor.Y;
			
			Xenon::Math::Matrix3x3 :: AppendTranslation ( CharTransform, BitmapScalingFactor * TranslationX, BitmapScalingFactor * TranslationY );
			
			Xenon::Math :: Vec4 & TexCoords = TextureCoordinateArray [ RenderCharIndex ];
			
			TexCoords.X = ( static_cast <double> ( Metrics.OffsetX ) / BitmapWidth );
			TexCoords.Y = ( static_cast <double> ( Metrics.OffsetY + Metrics.Height ) / BitmapHeight );
			TexCoords.Z = static_cast <double> ( Metrics.Width ) / BitmapWidth;
			TexCoords.W = - static_cast <double> ( Metrics.Height ) / BitmapHeight;
			
			RenderCharIndex ++;
			
		}
		else
		{
			
			double OffsetX = 0;
			double OffsetY = 0;
			
			Layout -> GetAdvance ( CurrentAtlas, CurrentCharachter, OffsetX, OffsetY );
			
			if ( ( OffsetX != 0 ) || ( OffsetY != 0 ) )
			{
				
				Cursor.X += OffsetX;
				Cursor.Y += OffsetY;
				
			}
			
		}
		
		StringIndex ++;
		
	}
	
	Cont -> GetDefaultFrameBuffer () -> Clear ();
	Cont -> SetCullingEnabled ( false );
	Cont -> SetDepthTestEnabled ( DepthTesting );
	Cont -> SetFrontFace ( Xenon::GPU::Context :: kFrontFace_Clockwise );
	Cont -> SetCullingFace ( Xenon::GPU::Context :: kCullingFace_Back );
	Cont -> BlendFunc ( Xenon::GPU::Context :: kBlendFactor_SourceAlpha, Xenon::GPU::Context :: kBlendFactor_OneMinusSourceAlpha, Xenon::GPU::Context :: kBlendFactor_One, Xenon::GPU::Context :: kBlendFactor_Zero );
	Cont -> BlendEquation ( Xenon::GPU::Context :: kBlendOperator_Add, Xenon::GPU::Context :: kBlendOperator_Add );
	
	Xenon::Math::Matrix3x3 :: Identity ( GlobalTransform );
	//TODO: Translate so text is reference to upper left corner.
	Xenon::Math::Matrix3x3 :: Append ( GlobalTransform, ExternalGlobalTransform );
	Xenon::Math::Matrix3x3 :: PrependScale ( GlobalTransform, ScalingFactorX, ScalingFactorY );
	GlobalTransformUniform.SetDirty ();
	
	RenderTarget -> Bind ();
	VArray.Bind ();
	
	CharachterTexturePositionBuffer.Buffer ( TextureCoordinateArray, 16 * RenderCharIndex );
	CharachterTransformBuffer.Buffer ( TransformArray, 36 * RenderCharIndex );
	
	Uniforms.UpdateUniforms ();
	
	glDrawElementsInstanced ( QuadMesh -> GetDrawMode (), QuadMesh -> GetIndexCount (), QuadMesh -> GetIndexType (), 0, RenderCharIndex );
	
}

void Red::Text::Rendering::ShadedRenderer :: RenderASCIIString ( const std :: string & String )
{
	
	std :: u32string UnicodeString;
	UnicodeString.resize ( String.length () + 1 );
	
	for ( uint32_t I = 0; I < String.size (); I ++ )
		UnicodeString [ I ] = static_cast <char32_t> ( String [ I ] );
	
	RenderUnicodeString ( UnicodeString );
	
}

void Red::Text::Rendering::ShadedRenderer :: SetPreviousStringDirty ()
{
	
	CachedRenderDirty = true;
	
}

void Red::Text::Rendering::ShadedRenderer :: GPUResourceAlloc ()
{
	
	if ( GPUAllocated )
		return;
	
	if ( Cont != NULL )
		Cont -> MakeCurrent ();
	
	AtlasTexture.GPUResourceAlloc ();
	AtlasTexture.AssignToTextureUnit ( 0 );
	
	AtlasTexture.SetFiltering ( Xenon::GPU::Texture2D :: kMinimizingFilter_Linear, Xenon::GPU::Texture2D :: kMagnificationFilter_Linear );
	AtlasTexture.SetWrapMode ( Xenon::GPU::Texture2D :: kWrapMode_EdgeClamp );
	
	CharachterTransformBuffer.GPUResourceAlloc ();
	CharachterTexturePositionBuffer.GPUResourceAlloc ();
	
	if ( QuadMesh != NULL )
		QuadMesh -> GPUResourceAlloc ();
	
	VArray.GPUResourceAlloc ();
	
	VShader.GPUResourceAlloc ();
	FShader.GPUResourceAlloc ();
	Program.GPUResourceAlloc ();
	
	if ( ! VShader.Compile ( true, true ) )
	{
		
		std :: cout << "VShader failed to compile:" << std :: endl << VShader.GetCompilationLog () << std :: endl;
		
		VShader.FreeCompilationLog ();
		
	}
	
	if ( ! FShader.Compile ( true, true ) )
	{
		
		std :: cout << "FShader failed to compile:" << std :: endl << FShader.GetCompilationLog () << std :: endl;
		
		FShader.FreeCompilationLog ();
		
	}
	
	Program.AddShader ( VShader );
	Program.AddShader ( FShader );
	
	Program.Link ();
	
	Uniforms.SetProgram ( & Program );
	
	Uniforms.Link ();
	
	if ( QuadMesh != NULL )
	{
		
		QuadMesh -> FlushData ();
		QuadMesh -> BuildVertexArray ( VArray );
		
	}
	
	VArray.AddFPAttribute ( "CharachterTransform", 3, Xenon::GPU::VertexArray :: kFPAttributeInputType_Float, false, 36, reinterpret_cast <void *> ( 0 ), & CharachterTransformBuffer, 1, 0 );
	VArray.AddFPAttribute ( "CharachterTransform", 3, Xenon::GPU::VertexArray :: kFPAttributeInputType_Float, false, 36, reinterpret_cast <void *> ( sizeof ( GLfloat ) * 3 ), & CharachterTransformBuffer, 1, 1 );
	VArray.AddFPAttribute ( "CharachterTransform", 3, Xenon::GPU::VertexArray :: kFPAttributeInputType_Float, false, 36, reinterpret_cast <void *> ( sizeof ( GLfloat ) * 6 ), & CharachterTransformBuffer, 1, 2 );
	
	VArray.AddFPAttribute ( "TexturePosition", 4, Xenon::GPU::VertexArray :: kFPAttributeInputType_Float, false, 16, 0, & CharachterTexturePositionBuffer, 1, 0 );
	
	VArray.SetProgram ( & Program );
	VArray.Build ();
	
	GPUAllocated = true;
	
}

void Red::Text::Rendering::ShadedRenderer :: GPUResourceFree ()
{
	
	if ( ! GPUAllocated )
		return;
	
	Program.GPUResourceFree ();
	FShader.GPUResourceFree ();
	VShader.GPUResourceFree ();
	
	VArray.GPUResourceFree ();
	
	Uniforms.ResetUniformStates ();
	
	if ( QuadMesh != NULL )
		QuadMesh -> GPUResourceFree ();
	
	CharachterTexturePositionBuffer.GPUResourceFree ();
	CharachterTransformBuffer.GPUResourceFree ();
	AtlasTexture.GPUResourceFree ();
	
	GPUAllocated = false;
	
}

bool Red::Text::Rendering::ShadedRenderer :: GPUResourceAllocated ()
{
	
	return GPUAllocated;
	
}

void Red::Text::Rendering::ShadedRenderer :: UploadTexture ( bool ForceReupload )
{
	
	if ( ( ! GPUAllocated ) || ( TextureUploaded && ( ! ForceReupload ) ) )
		return;
	
	if ( CurrentAtlas == NULL )
		return;
	
	if ( CurrentAtlas -> GetFormat () == RawFontTextureAtlas :: kBitmapFormat_Alpha_8 )
		AtlasTexture.TextureImage ( 0, Xenon::GPU::Texture2D :: kInternalFormat_RGBA, CurrentAtlas -> GetBitmapWidth (), CurrentAtlas -> GetBitmapHeight (), Xenon::GPU::Texture2D :: kExternalLayout_UByte, Xenon::GPU::Texture2D :: kExternalFormat_R, CurrentAtlas -> GetBitmapData () );
	else
		AtlasTexture.TextureImage ( 0, Xenon::GPU::Texture2D :: kInternalFormat_RGBA, CurrentAtlas -> GetBitmapWidth (), CurrentAtlas -> GetBitmapHeight (), Xenon::GPU::Texture2D :: kExternalLayout_UByte, Xenon::GPU::Texture2D :: kExternalFormat_RGBA, CurrentAtlas -> GetBitmapData () );
	
	TextureUploaded = true;
	
}
