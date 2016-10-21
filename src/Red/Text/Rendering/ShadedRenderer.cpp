#include <Red/Text/Rendering/ShadedRenderer.h>
#include <Xenon/Geometry/Primitives.h>

#include <float.h>
#include <cmath>

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
	RegistrationX ( kRegistrationMetric_BaseLine_Start ),
	RegistrationY ( kRegistrationMetric_BaseLine_Start ),
	Justify ( kJustificationMode_Left ),
	TabWidth ( 4.0 ),
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
	
	if ( QuadMesh != NULL )
		QuadMesh -> Reference ();
	
}

Red::Text::Rendering::ShadedRenderer :: ~ShadedRenderer ()
{
	
	SetRenderTarget ( NULL, NULL, Xenon::Math::Vec2 ( 0.0, 0.0 ) );
	SetFontData ( NULL );
	
	GPUResourceFree ();
	
	if ( QuadMesh != NULL )
	{
		
		QuadMesh -> Dereference ();
		QuadMesh = NULL;
		
	}
	
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
	
	if ( this -> RenderTarget != RenderTarget )
	{
		
		if ( this -> RenderTarget != NULL )
			this -> RenderTarget -> Reference ();
		
		this -> RenderTarget = RenderTarget;
		
		if ( this -> RenderTarget != NULL )
			this -> RenderTarget -> Reference ();
		
	}
	
	if ( this -> Cont != Cont )
	{
		
		if ( ( this -> Cont != NULL ) && ( Cont != NULL ) )
		{
			
			bool GPUAlloc = GPUAllocated;
			
			GPUResourceFree ();
			this -> Cont -> Dereference ();
			
			this -> Cont = Cont;
			this -> Cont -> Reference ();
			
			if ( GPUAlloc )
				GPUResourceAlloc ();
			
		}
		else
		{
			
			if ( this -> Cont != NULL )
				this -> Cont -> Dereference ();
			
			this -> Cont = Cont;
			
			if ( this -> Cont != NULL )
				this -> Cont -> Reference ();
			
		}
		
	}
	
	this -> RenderTargetDimensions = Dimensions;
	
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

void Red::Text::Rendering::ShadedRenderer :: SetRegistrationMetrics ( RegistrationMetric X, RegistrationMetric Y )
{
	
	this -> RegistrationX = X;
	this -> RegistrationY = Y;
	
}

void Red::Text::Rendering::ShadedRenderer :: SetJustificationMode ( JustificationMode Justify )
{
	
	this -> Justify = Justify;
	
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
	
	uint32_t StringLength = static_cast <uint32_t> ( String.size () );
	
	if ( StringLength == 0 )
		return;
	
	PreAllocBuffer ( StringLength );
	
	typedef struct
	{
		
		uint32_t StartRenderCharIndex;
		uint32_t RenderCharCount;
		
		double MinX;
		double MinY;
		
		double Width;
		double Height;
		
		double CursorEndX;
		double CursorEndY;
		
	} LineData;
	
	uint32_t LineCount = 1;
	
	uint32_t I;
	
	for ( I = 0; I < String.size (); I ++ )
	{
		
		if ( String [ I ] == U'\n' )
			LineCount ++;
		
	}
	
	LineData * Lines = new LineData [ LineCount ];
	
	uint32_t StringIndex = 0;
	uint32_t RenderCharIndex = 0;
	char32_t CurrentCharachter = U'\0';
	char32_t LastCharachter = 0;
	
	uint32_t LineIndex = 0;
	
	Xenon::Math :: Vec2 Cursor ( 0.0, 0.0 );
	
	double BitmapWidth = CurrentAtlas -> GetBitmapWidth ();
	double BitmapHeight = CurrentAtlas -> GetBitmapHeight ();
	
	const IFontLayoutSource * Layout = FontData -> GetLayoutSource ();
	
	double BitmapScalingFactor = Layout -> GetScalingFactor ( CurrentAtlas, PixelSize );
	double ScalingFactorX = 2.0 / RenderTargetDimensions.X;
	double ScalingFactorY = 2.0 / RenderTargetDimensions.Y;
	
	double MinX = DBL_MAX;
	double MaxX = - DBL_MAX;
	double MinY = DBL_MAX;
	double MaxY = - DBL_MAX;
	
	double LineMinX = DBL_MAX;
	double LineMaxX = - DBL_MAX;
	double LineMinY = DBL_MAX;
	double LineMaxY = - DBL_MAX;
	
	double CursorEndXMax = - DBL_MAX;
	double CursorEndXMin = DBL_MAX;
	double CursorEndYMax = - DBL_MAX;
	double CursorEndYMin = DBL_MAX;
	
	Lines [ LineIndex ].StartRenderCharIndex = 0;
	Lines [ LineIndex ].RenderCharCount = 0;
	
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
			
			TranslationX += BitmapScalingFactor * OffsetX;
			TranslationY -= static_cast <double> ( Metrics.Height ) * BitmapScalingFactor - BitmapScalingFactor * OffsetY;
			
			if ( LastCharachter != U'\t' )
				Layout -> GetAdvance ( CurrentAtlas, CurrentCharachter, LastCharachter, OffsetX, OffsetY );
			else	
			{
				
				OffsetX = 0.0;
				OffsetY = 0.0;
				
			}
			
			Cursor.X += BitmapScalingFactor * OffsetX;
			Cursor.Y += BitmapScalingFactor * OffsetY;
			
			TranslationX += Cursor.X;
			TranslationY += Cursor.Y;
			
			Xenon::Math::Matrix3x3 :: AppendTranslation ( CharTransform, TranslationX, TranslationY );
			
			if ( LineMinX > TranslationX )
				LineMinX = TranslationX;
			
			if ( LineMinY > TranslationY )
				LineMinY = TranslationY;
			
			if ( LineMaxX < TranslationX + BitmapScalingFactor * Metrics.Width )
				LineMaxX = TranslationX + BitmapScalingFactor * Metrics.Width;
			
			if ( LineMaxY < TranslationY + BitmapScalingFactor * Metrics.Height )
				LineMaxY = TranslationY + BitmapScalingFactor * Metrics.Height;
			
			Xenon::Math :: Vec4 & TexCoords = TextureCoordinateArray [ RenderCharIndex ];
			
			TexCoords.X = ( static_cast <double> ( Metrics.OffsetX ) / BitmapWidth );
			TexCoords.Y = ( static_cast <double> ( Metrics.OffsetY + Metrics.Height ) / BitmapHeight );
			TexCoords.Z = static_cast <double> ( Metrics.Width ) / BitmapWidth;
			TexCoords.W = - static_cast <double> ( Metrics.Height ) / BitmapHeight;
			
			RenderCharIndex ++;
			
		}
		else
		{
			
			if ( CurrentCharachter == U'\t' )
			{
				
				if ( LineMinX > Cursor.X )
					LineMinX = Cursor.X;
				
				if ( LineMinY > Cursor.Y )
					LineMinY = Cursor.Y;
				
				if ( LineMaxX < Cursor.X )
					LineMaxX = Cursor.X;
				
				if ( LineMaxY < Cursor.Y )
					LineMaxY = Cursor.Y;
				
				double OffsetX = 0;
				double OffsetY = 0;
				
				Layout -> GetAdvance ( CurrentAtlas, U' ', LastCharachter, OffsetX, OffsetY );
				
				if ( OffsetX == 0.0 && OffsetY == 0.0 )
				{
					
					Layout -> GetAdvance ( CurrentAtlas, U' ', U' ', OffsetX, OffsetY );
					
				}
				
				Cursor.X += BitmapScalingFactor * OffsetX * TabWidth;
				Cursor.Y += BitmapScalingFactor * OffsetY * TabWidth;
				
				if ( LineMinX > Cursor.X )
					LineMinX = Cursor.X;
				
				if ( LineMinY > Cursor.Y )
					LineMinY = Cursor.Y;
				
				if ( LineMaxX < Cursor.X )
					LineMaxX = Cursor.X;
				
				if ( LineMaxY < Cursor.Y )
					LineMaxY = Cursor.Y;
				
			}
			else if ( CurrentCharachter == U'\n' )
			{
				
				if ( MinX > LineMinX )
						MinX = LineMinX;
				
				if ( MinY > LineMinY )
					MinY = LineMinY;
				
				if ( MaxX < LineMaxX )
					MaxX = LineMaxX;
				
				if ( MaxY < LineMaxY )
					MaxY = LineMaxY;
				
				Lines [ LineIndex ].RenderCharCount = RenderCharIndex - Lines [ LineIndex ].StartRenderCharIndex;
				Lines [ LineIndex ].Width = LineMaxX - LineMinX;
				Lines [ LineIndex ].Height = LineMaxY - LineMinY;
				Lines [ LineIndex ].CursorEndX = Cursor.X;
				Lines [ LineIndex ].CursorEndY = Cursor.Y;
				
				if ( CursorEndXMin > Cursor.X )
					CursorEndXMin = Cursor.X;
				
				if ( CursorEndXMax < Cursor.X )
					CursorEndXMax = Cursor.X;
				
				if ( CursorEndYMin > Cursor.Y )
					CursorEndYMin = Cursor.Y;
				
				if ( CursorEndYMax < Cursor.Y )
					CursorEndYMax = Cursor.Y;
				
				LineMinX = DBL_MAX;
				LineMaxX = - DBL_MAX;
				LineMinY = DBL_MAX;
				LineMaxY = - DBL_MAX;
				
				Lines [ LineIndex ].MinX = LineMinX;
				Lines [ LineIndex ].MinY = LineMinY;
				
				if ( Layout -> GetLayoutDirection () == IFontLayoutSource :: kLayoutDirection_Horizontal )
				{
									
					Cursor.X = 0;
					Cursor.Y -= Layout -> GetFontHeight ( CurrentAtlas ) * BitmapScalingFactor;
					
				}
				else
				{
					
					Cursor.Y = 0;
					Cursor.X += Layout -> GetFontHeight ( CurrentAtlas ) * BitmapScalingFactor;
					
				}
				
				LineIndex ++;
				
				Lines [ LineIndex ].StartRenderCharIndex = RenderCharIndex;
				
			}
			else
			{
				
				double OffsetX = 0;
				double OffsetY = 0;
				
				Layout -> GetAdvance ( CurrentAtlas, CurrentCharachter, LastCharachter, OffsetX, OffsetY );
				
				Cursor.X += OffsetX;
				Cursor.Y += OffsetY;
				
			}
							
		}
		
		StringIndex ++;
		
	}
	
	if ( MinX > LineMinX )
		MinX = LineMinX;
	
	if ( MinY > LineMinY )
		MinY = LineMinY;
	
	if ( MaxX < LineMaxX )
		MaxX = LineMaxX;
	
	if ( MaxY < LineMaxY )
		MaxY = LineMaxY;
	
	if ( CursorEndXMin > Cursor.X )
		CursorEndXMin = Cursor.X;
	
	if ( CursorEndXMax < Cursor.X )
		CursorEndXMax = Cursor.X;
	
	if ( CursorEndYMin > Cursor.Y )
		CursorEndYMin = Cursor.Y;
	
	if ( CursorEndYMax < Cursor.Y )
		CursorEndYMax = Cursor.Y;
	
	Lines [ LineIndex ].RenderCharCount = RenderCharIndex - Lines [ LineIndex ].StartRenderCharIndex;
	Lines [ LineIndex ].Width = LineMaxX - LineMinX;
	Lines [ LineIndex ].Height = LineMaxY - LineMinY;
	
	Lines [ LineIndex ].MinX = LineMinX;
	Lines [ LineIndex ].MinY = LineMinY;
	
	Xenon::Math::Matrix3x3 :: Identity ( GlobalTransform );
	
	double DeltaX = 0.0;
	double DeltaY = 0.0;
	
	switch ( RegistrationX )
	{
		
		case kRegistrationMetric_BaseLine_End:
			DeltaX = - ( std :: abs ( CursorEndXMax ) > std :: abs ( CursorEndXMin ) ) ? CursorEndXMax : CursorEndXMin;
			break;
		
		case kRegistrationMetric_Center:
			DeltaX = ( MinX + MaxX ) * - 0.5;
			break;
		
		case kRegistrationMetric_Min:
			DeltaX = - MinX;
			break;
		
		case kRegistrationMetric_Max:
			DeltaX = - MaxX;
			break;
		
		default:
			break;
		
	}
	
	switch ( RegistrationY )
	{
		
		case kRegistrationMetric_BaseLine_End:
			DeltaY = - ( std :: abs ( CursorEndYMax ) > std :: abs ( CursorEndYMin ) ) ? CursorEndYMax : CursorEndYMin;
			break;
		
		case kRegistrationMetric_Center:
			DeltaY = ( MinY + MaxY ) * - 0.5;
			break;
		
		case kRegistrationMetric_Min:
			DeltaY = - MinY;
			break;
		
		case kRegistrationMetric_Max:
			DeltaY = - MaxY;
			break;
		
		default:
			break;
		
	}
	
	switch ( Justify )
	{
		
		case kJustificationMode_Center:
		{
			
			if ( Layout -> GetLayoutDirection () == IFontLayoutSource :: kLayoutDirection_Horizontal )
			{
			
				for ( I = 0; I < LineCount; I ++ )
				{
					
					double LineOffsetX = ( ( MaxX - MinX ) - Lines [ I ].Width ) * 0.5;
					
					uint32_t L;
					
					for ( L = 0; L < Lines [ I ].RenderCharCount; L ++ )
					{
						
						Xenon::Math::Matrix3x3 & CharTransform = TransformArray [ Lines [ I ].StartRenderCharIndex + L ];
						
						Xenon::Math::Matrix3x3 :: AppendTranslation ( CharTransform, LineOffsetX, 0.0 );
						
					}
					
				}
				
			}
			else
			{
				
				for ( I = 0; I < LineCount; I ++ )
				{
					
					double LineOffsetY = ( ( MaxY - MinY ) - Lines [ I ].Height ) * 0.5;
					
					uint32_t L;
					
					for ( L = 0; L < Lines [ I ].RenderCharCount; L ++ )
					{
						
						Xenon::Math::Matrix3x3 & CharTransform = TransformArray [ Lines [ I ].StartRenderCharIndex + L ];
						
						Xenon::Math::Matrix3x3 :: AppendTranslation ( CharTransform, LineOffsetY, 0.0 );
						
					}
					
				}
			
			}
			
			break;
			
		}
		
		case kJustificationMode_Right:
		{
			
			if ( Layout -> GetLayoutDirection () == IFontLayoutSource :: kLayoutDirection_Horizontal )
			{
			
				for ( I = 0; I < LineCount; I ++ )
				{
					
					double LineOffsetX = ( MaxX - MinX ) - Lines [ I ].Width;
					
					uint32_t L;
					
					for ( L = 0; L < Lines [ I ].RenderCharCount; L ++ )
					{
						
						Xenon::Math::Matrix3x3 & CharTransform = TransformArray [ Lines [ I ].StartRenderCharIndex + L ];
						
						Xenon::Math::Matrix3x3 :: AppendTranslation ( CharTransform, LineOffsetX, 0.0 );
						
					}
					
				}
				
			}
			else
			{
				
				for ( I = 0; I < LineCount; I ++ )
				{
					
					double LineOffsetY = ( MaxY - MinY ) - Lines [ I ].Height;
					
					uint32_t L;
					
					for ( L = 0; L < Lines [ I ].RenderCharCount; L ++ )
					{
						
						Xenon::Math::Matrix3x3 & CharTransform = TransformArray [ Lines [ I ].StartRenderCharIndex + L ];
						
						Xenon::Math::Matrix3x3 :: AppendTranslation ( CharTransform, LineOffsetY, 0.0 );
						
					}
					
				}
			
			}
			
			break;
			
		}
		
		default:
			break;
		
	}
	
	delete [] Lines;
	
	Xenon::Math::Matrix3x3 :: SetAsTranslation ( GlobalTransform, DeltaX, DeltaY );
	Xenon::Math::Matrix3x3 :: Prepend ( GlobalTransform, ExternalGlobalTransform );
	Xenon::Math::Matrix3x3 :: PrependScale ( GlobalTransform, ScalingFactorX, ScalingFactorY );
	GlobalTransformUniform.SetDirty ();
	
	Cont -> GetDefaultFrameBuffer () -> Clear ();
	Cont -> SetCullingEnabled ( false );
	Cont -> SetDepthTestEnabled ( DepthTesting );
	Cont -> SetFrontFace ( Xenon::GPU::Context :: kFrontFace_Clockwise );
	Cont -> SetCullingFace ( Xenon::GPU::Context :: kCullingFace_Back );
	Cont -> BlendFunc ( Xenon::GPU::Context :: kBlendFactor_SourceAlpha, Xenon::GPU::Context :: kBlendFactor_OneMinusSourceAlpha, Xenon::GPU::Context :: kBlendFactor_One, Xenon::GPU::Context :: kBlendFactor_Zero );
	Cont -> BlendEquation ( Xenon::GPU::Context :: kBlendOperator_Add, Xenon::GPU::Context :: kBlendOperator_Add );
	
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
