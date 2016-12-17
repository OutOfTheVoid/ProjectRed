#include <Red/Graphics/DeferredModelRenderer.h>

#include <string>
#include <iostream>

#include <Xenon/Geometry/Primitives.h>

#include <Xenon/GPU/GLInclude.h>

const std :: string Red::Graphics::DeferredModelRenderer :: kModelAttributeName_Position = "Position";
const std :: string Red::Graphics::DeferredModelRenderer :: kModelAttributeName_Normal = "Normal";
const std :: string Red::Graphics::DeferredModelRenderer :: kModelAttributeName_Tangent = "Tangent";
const std :: string Red::Graphics::DeferredModelRenderer :: kModelAttributeName_Color = "Color";
const std :: string Red::Graphics::DeferredModelRenderer :: kModelAttributeName_TextureCoords = "TextureCoord";

const std :: string Red::Graphics::DeferredModelRenderer :: kModelAttributeName_InstancedModelMatrix = "InstancedModelMatrix";
const std :: string Red::Graphics::DeferredModelRenderer :: kModelAttributeName_InstancedNormalMatrix = "InstancedNormalMatrix";

const std :: string Red::Graphics::DeferredModelRenderer :: kUniformName_ModelMatrix = "ModelMatrix";
const std :: string Red::Graphics::DeferredModelRenderer :: kUniformName_NormalMatrix = "NormalMatrix";

const std :: string Red::Graphics::DeferredModelRenderer :: kUniformName_DoInstancedTransforms = "DoInstancedTransformation";

const std :: string Red::Graphics::DeferredModelRenderer :: kUniformName_DoNormalTexture = "DoNormalTexture";
const std :: string Red::Graphics::DeferredModelRenderer :: kUniformName_DoColorTexture = "DoColorTexture";

//kUniformName_DoNormalTexture

const std :: string _DeferredModelRenderer_VShader_Geometry =
"#version 330 core\n"

"in vec3 Position;\n"
"in vec3 Normal;\n"
"in vec3 Tangent;\n"
"in vec3 Color;\n"
"in vec2 TextureCoord;\n"

"in mat4 InstancedModelMatrix;\n"
"in mat4 InstancedNormalMatrix;\n"

"uniform mat4 ModelMatrix;\n"
"uniform mat4 NormalMatrix;\n"
"uniform mat4 ViewProjectionMatrix;\n"

"uniform bool DoNormalTexture;\n"

"uniform bool DoInstancedTransformation;\n"

"out vec3 FragPosition;\n"
"out vec3 FragNormal;\n"
"out vec3 FragTangent;\n"
"out vec3 FragBinormal;\n"
"out vec3 FragColor;\n"
"out vec2 FragTextureCoords;\n"

"void main ()\n"
"{\n"

"	vec4 WorldPosition;\n"

"	if ( DoInstancedTransformation )\n"
"	{\n"
"		WorldPosition = vec4 ( Position, 1.0 ) * InstancedModelMatrix;\n"
"		if ( DoNormalTexture )\n"
"		{\n"
"			FragTangent = normalize ( ( vec4 ( Tangent, 1.0 ) * InstancedNormalMatrix ).xyz );\n"
"			FragBinormal = normalize ( ( vec4 ( cross ( Tangent, Normal ), 1.0 ) * InstancedNormalMatrix ).xyz );\n"
"			FragNormal = normalize ( ( vec4 ( Normal, 1.0 ) * InstancedNormalMatrix ).xyz );\n"
"		}\n"
"	}\n"
"	else\n"
"	{\n"
"		WorldPosition = vec4 ( Position, 1.0 ) * ModelMatrix;\n"
"		if ( DoNormalTexture )\n"
"		{\n"
"			FragTangent = normalize ( ( vec4 ( Tangent, 1.0 ) * NormalMatrix ).xyz );\n"
"			FragBinormal = normalize ( ( vec4 ( cross ( Tangent, Normal ), 1.0 ) * NormalMatrix ).xyz );\n"
"			FragNormal = normalize ( ( vec4 ( Normal, 1.0 ) * NormalMatrix ).xyz );\n"
"		}\n"
"	}\n"


"	FragPosition = WorldPosition.xyz;\n"
"	FragColor = Color;\n"
"	FragTextureCoords = TextureCoord;\n"
"	gl_Position = WorldPosition * ViewProjectionMatrix;\n"

"}\n";

const char * _DeferredModelRenderer_FShader_Geometry =
"#version 330 core\n"

"in vec3 FragPosition;\n"
"in vec3 FragNormal;\n"
"in vec3 FragTangent;\n"
"in vec3 FragBinormal;\n"
"in vec3 FragColor;\n"
"in vec2 FragTextureCoords;\n"

"uniform float BaseSpecular;\n"

"uniform bool DoColorTexture;\n"
"uniform bool DoNormalTexture;\n"

"uniform sampler2D ColorSampler;\n"
"uniform sampler2D NormalSampler;\n"

"layout ( location = 0 ) out vec4 AlbedoSpecularOut;\n"
"layout ( location = 1 ) out vec3 NormalOut;\n"
"layout ( location = 2 ) out vec3 PositionOut;\n"

"void main ()\n"
"{\n"

"	vec3 TotalColor = FragColor;\n"
"	vec3 TotalNormal = FragNormal;\n"

"	if ( DoColorTexture )\n"
"		TotalColor *= texture ( ColorSampler, FragTextureCoords ).rgb;\n"

"	if ( DoNormalTexture )\n"
"	{\n"

"		TotalNormal += texture ( NormalSampler, FragTextureCoords ).xyz * mat3 ( FragTangent, FragBinormal, FragNormal );"
"		TotalNormal = normalize ( TotalNormal );\n"

"	}\n"

"	AlbedoSpecularOut = vec4 ( TotalColor, BaseSpecular );\n"
"	NormalOut = FragNormal;\n"
"	PositionOut = FragPosition;\n"

"}\n";

const char * _DeferredModelRenderer_VShader_Lighting =
"#version 330 core\n"

"in vec2 Position;\n"

"out vec2 TexturePosition;\n"

"void main ()\n"
"{\n"

"	TexturePosition = Position;\n"
"	gl_Position = vec4 ( Position, 0.5, 1.0 );\n"

"}\n";

const char * _DeferredModelRenderer_FShader_Lighting =
"#version 330 core\n"

"const int LightCount_Directional = 2;\n"
"const int LightCount_Point = 20;\n"

"struct PointLight\n"
"{\n"

"	vec3 Position;\n"
"	vec3 Intensity;\n"

"};\n"

"struct DirectionalLight\n"
"{\n"

"	vec3 Position;\n"
"	vec3 Intensity;\n"
"	vec3 Direction;\n"

"};\n"

"struct Spotlight\n"
"{\n"

"	vec3 Position;\n"
"	vec3 Intensity;\n"
"	vec3 Direction;\n"
"	float Radius;\n"

"};\n"


"in vec2 TexturePosition;\n"

"uniform sampler2D AlbedoSpecularSampler;\n"
"uniform sampler2D NormalSampler;\n"
"uniform sampler2D PositionSampler;\n"

//"uniform vec3 ViewPosition;\n"

//"uniform vec3 AmbientLight;\n"

"out vec4 OutColor;\n"

"void main ()\n"
"{\n"

//"	vec4 AlbedoSpecular = texture ( AlbedoSpecularSampler, TexturePosition );\n"
//"	vec3 Normal = texture ( NormalSampler, TexturePosition ).xyz;\n"
//"	vec3 Position = texture ( PositionSampler, TexturePosition ).xyz;\n"

//"	vec3 ViewDirection = normalize ( ViewPosition - Position );"

//"	vec3 Accumulator = AlbedoSpecular.rgb * AmbientLight;\n"

	/* Various lighting calculations... */

"	OutColor = vec4 ( TexturePosition.x, 0.0, TexturePosition.y, 1.0 );\n"


"}\n";

const Red::Graphics::Model :: ModelShaderConfigurationNames & Red::Graphics::DeferredModelRenderer :: GetShaderConfigurationNames ()
{
	
	static bool NamesCondfigured = false;
	static Red::Graphics::Model :: ModelShaderConfigurationNames Names;
	
	if ( ! NamesCondfigured )
	{
		
		Names.InstancedModelTransformAttributeName = & kModelAttributeName_InstancedModelMatrix;
		Names.InstancedNormalTransformAttributeName = & kModelAttributeName_InstancedNormalMatrix;
		
		Names.ModelMatrixUniformName = & kUniformName_ModelMatrix;
		Names.NormalMatrixUniformName = & kUniformName_NormalMatrix;
		
		Names.DoInstancedTransformUniformName = & kUniformName_DoInstancedTransforms;
		Names.DoNormalTextureUniformName = & kUniformName_DoNormalTexture;
		Names.DoColorTextureUniformName = & kUniformName_DoColorTexture;
		
		Names.PositionAttributeName = & kModelAttributeName_Position;
		Names.NormalAttributeName = & kModelAttributeName_Normal;
		Names.TangentAttributeName = & kModelAttributeName_Tangent;
		Names.ColorAttributeName = & kModelAttributeName_Color;
		Names.TextureCoordAttributeName = & kModelAttributeName_TextureCoords;
		
	}
	
	return Names;
	
}

Red::Graphics::DeferredModelRenderer :: DeferredModelRenderer ():
	RefCounted (),
	GPUContext ( NULL ),
	RenderTarget ( NULL ),
	GPUAllocated ( false ),
	GeometryUniforms (),
	GBuffer (),
	AttachmentList { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2 },
	AlbedoSpecularTexture (),
	NormalTexture (),
	PositionTexture (),
	DepthBuffer (),
	GeometryVShader ( _DeferredModelRenderer_VShader_Geometry, "DeferredModelRenderer :: GeometryVShader" ),
	GeometryFShader ( _DeferredModelRenderer_FShader_Geometry, "DeferredModelRenderer :: GeometryFShader" ),
	GeometryProgram ( "DeferredModelRenderer :: GeometryProgram" ),
	ProjectionMatrixSource ( NULL ),
	ViewMatrixSource ( NULL ),
	LastProjectionIteration ( - 1 ),
	LastViewIteration ( - 1 ),
	ViewProjectionMatrix (),
	ViewProjectionMatrixUniform ( & ViewProjectionMatrix, true ),
	LightingDrawCall ( Xenon::GPU::IndexedDrawCall :: NO_INIT ),
	LightingVAO (),
	LightingUniforms (),
	AlbedoSpecularSamplerUniform ( 0 ),
	NormalSamplerUniform ( 1 ),
	PositionSamplerUniform ( 2 ),
	LightingVShader ( _DeferredModelRenderer_VShader_Lighting, "DeferredModelRenderer :: LightingVShader" ),
	LightingFShader ( _DeferredModelRenderer_FShader_Lighting, "DeferredModelRenderer :: LightingFShader" ),
	LightingProgram ( "DeferredModelRenderer :: LightingProgram" ),
	RenderQuad ( NULL ),
	RenderDataSet ()
{
	
	Xenon::Geometry::Primitives :: Quad2DSpec RenderQuadSpec;
	RenderQuadSpec.WindOutwardFacesClockwise = true;
	RenderQuadSpec.Attributes = Xenon::Geometry::Primitives :: kAttributeFlags_Position;
	RenderQuadSpec.CompositionMode = Xenon::Geometry::Primitives :: kStaticAttributeCompositionMode_Interleaved;
	RenderQuadSpec.TexturePositionCount = 0;
	Xenon::Geometry::Primitives :: SetupNormalQuad2DPositionSpec ( RenderQuadSpec.PositionSpec, "Position", true );
	Xenon::Geometry::Primitives :: GenerateQuad2DMesh ( & RenderQuad, RenderQuadSpec );
	
	if ( RenderQuad != NULL )
	{
		
		RenderQuad -> Reference ();
		RenderQuad -> ConfigureIndexedDrawCall ( LightingDrawCall );
		
	}
	
	ViewProjectionMatrixUniform.Reference ();
	
	GeometryUniforms.AddMatrix4x4Uniform ( "ViewProjectionMatrix", & ViewProjectionMatrixUniform, false );
	
	LightingProgram.Reference ();
	GeometryProgram.Reference ();
	
	ViewProjectionMatrixUniform.Reference ();
	AlbedoSpecularSamplerUniform.Reference ();
	NormalSamplerUniform.Reference ();
	PositionSamplerUniform.Reference ();
	
	LightingUniforms.AddIntUniform ( "AlbedoSpecularSampler", & AlbedoSpecularSamplerUniform, false );
	LightingUniforms.AddIntUniform ( "NormalSampler", & NormalSamplerUniform, false );
	LightingUniforms.AddIntUniform ( "PositionSampler", & PositionSamplerUniform, false );
	
}

Red::Graphics::DeferredModelRenderer :: ~DeferredModelRenderer ()
{
	
	DestroyRender ();
	
	if ( RenderQuad != NULL )
	{
		
		RenderQuad -> Dereference ();
		RenderQuad = NULL;
		
	}
	
}

void Red::Graphics::DeferredModelRenderer :: Initialize ( Xenon::GPU :: Context * GPUContext )
{
	
	if ( GPUAllocated )
		DestroyRender ();
	
	if ( this -> GPUContext != NULL )
		this -> GPUContext -> Dereference ();
	
	this -> GPUContext = GPUContext;
	
	if ( this -> GPUContext != NULL )
		this -> GPUContext -> Reference ();
	
}

void Red::Graphics::DeferredModelRenderer :: SetProjectionSource ( Xenon::GPU :: IMatrix4x4UniformSource * ProjectionMatrixSource )
{
	
	if ( this -> ProjectionMatrixSource != NULL )
		this -> ProjectionMatrixSource -> Dereference ();
	
	this -> ProjectionMatrixSource = ProjectionMatrixSource;
	
	if ( this -> ProjectionMatrixSource != NULL )
		this -> ProjectionMatrixSource -> Reference ();
	
}

void Red::Graphics::DeferredModelRenderer :: SetViewSource ( Xenon::GPU :: IMatrix4x4UniformSource * ViewMatrixSource )
{

	if ( this -> ViewMatrixSource != NULL )
		this -> ViewMatrixSource -> Dereference ();
	
	this -> ViewMatrixSource = ViewMatrixSource;
	
	if ( this -> ViewMatrixSource != NULL )
		this -> ViewMatrixSource -> Reference ();

}

void Red::Graphics::DeferredModelRenderer :: SetupRender ( Xenon::GPU :: FrameBuffer * RenderTarget, Xenon::Math :: Vec2 Dimensions )
{
	
	if ( RenderQuad == NULL )
		return;
	
	if ( GPUContext == NULL )
		return;
	
	if ( RenderTarget == NULL )
		return;
	
	GPUContext -> MakeCurrent ();
	
	if ( this -> RenderTarget != NULL )
		this -> RenderTarget -> Dereference ();
	
	this -> RenderTarget = RenderTarget;
	
	if ( this -> RenderTarget != NULL )
		this -> RenderTarget -> Reference ();
	else
		return;
	
	std :: cout << "GL Error: " << glGetError () << std :: endl;
	
	DepthBuffer.AllocateStorage ( Xenon::GPU::Texture2D :: kInternalFormat_Depth, Dimensions.X, Dimensions.Y );
	
	std :: cout << "GL Error: " << glGetError () << std :: endl;
	
	AlbedoSpecularTexture.BlankTextureImage ( 0, Xenon::GPU::Texture2D :: kInternalFormat_RGBA, Dimensions.X, Dimensions.Y );
	NormalTexture.BlankTextureImage ( 0, Xenon::GPU::Texture2D :: kInternalFormat_RGB32f, Dimensions.X, Dimensions.Y );
	PositionTexture.BlankTextureImage ( 0, Xenon::GPU::Texture2D :: kInternalFormat_RGB32f, Dimensions.X, Dimensions.Y );
	
	std :: cout << "GL Error: " << glGetError () << std :: endl;
	
	AlbedoSpecularTexture.SetFiltering ( Xenon::GPU::Texture2D :: kMinimizingFilter_Nearest, Xenon::GPU::Texture2D :: kMagnificationFilter_Nearest );
	NormalTexture.SetFiltering ( Xenon::GPU::Texture2D :: kMinimizingFilter_Nearest, Xenon::GPU::Texture2D :: kMagnificationFilter_Nearest );
	PositionTexture.SetFiltering ( Xenon::GPU::Texture2D :: kMinimizingFilter_Nearest, Xenon::GPU::Texture2D :: kMagnificationFilter_Nearest );
	
	AlbedoSpecularTexture.SetWrapMode ( Xenon::GPU::Texture2D :: kWrapMode_EdgeClamp );
	NormalTexture.SetWrapMode ( Xenon::GPU::Texture2D :: kWrapMode_EdgeClamp );
	PositionTexture.SetWrapMode ( Xenon::GPU::Texture2D :: kWrapMode_EdgeClamp );
	
	std :: cout << "GL Error: " << glGetError () << std :: endl;
	
	GBuffer.Bind ();
	
	GBuffer.SetRenderTexture2D ( Xenon::GPU::FrameBuffer :: kOutputAttachment_ColorBuffer, 0, AlbedoSpecularTexture, 0 );
	GBuffer.SetRenderTexture2D ( Xenon::GPU::FrameBuffer :: kOutputAttachment_ColorBuffer, 1, NormalTexture, 0 );
	GBuffer.SetRenderTexture2D ( Xenon::GPU::FrameBuffer :: kOutputAttachment_ColorBuffer, 2, PositionTexture, 0 );
	
	std :: cout << "GL Error: " << glGetError () << std :: endl;
	
	std :: cout << "FrameBuffer Check: " << glCheckFramebufferStatus ( GL_FRAMEBUFFER ) << std :: endl;
	
	//GBuffer.SetRenderBuffer ( Xenon::GPU::FrameBuffer :: kOutputAttachment_DepthBuffer, 0, DepthBuffer );
	
	std :: cout << "GL Error: " << glGetError () << std :: endl;
	
	std :: cout << "FrameBuffer Check: " << glCheckFramebufferStatus ( GL_FRAMEBUFFER ) << std :: endl;
	
	glDrawBuffers ( 3, AttachmentList );
	
	std :: cout << "GL Error: " << glGetError () << std :: endl;
	
	std :: cout << "FrameBuffer Check: " << glCheckFramebufferStatus ( GL_FRAMEBUFFER ) << std :: endl;
	
	GBuffer.SetClearColor ( 0.0f, 0.0f, 0.0f, 0.0f );
	
	GBuffer.Clear ();
	
	if ( ! GeometryVShader.Compile ( true, false ) )
		std :: cout << "DeferredModelRenderer :: GeometryVShader failed to compile:" << std :: endl << GeometryVShader.GetCompilationLog () << std :: endl;
	
	if ( ! GeometryFShader.Compile ( true, false ) )
		std :: cout << "DeferredModelRenderer :: GeometryFShader failed to compile:" << std :: endl << GeometryFShader.GetCompilationLog () << std :: endl;
	
	/*
	GeometryFShader.Compile ( false, false );
	GeometryFShader.Compile ( false, false );
	*/
	
	GeometryProgram.AddShader ( GeometryVShader );
	GeometryProgram.AddShader ( GeometryFShader );
	
	if ( ! GeometryProgram.Link () )
		std :: cout << "DeferredModelRenderer :: GeometryProgram failed to compile: " << std :: endl << GeometryProgram.GetInfoLog () << std :: endl;
	
	GeometryProgram.Reference ();
	
	GeometryUniforms.SetProgram ( & GeometryProgram );
	GeometryUniforms.Link ();
	
	// Set up lighting pass
	
	LightingVAO.Bind ();
	
	if ( ! LightingVShader.Compile ( true, false ) )
		std :: cout << "DeferredModelRenderer :: LightingVShader failed to compile:" << std :: endl << LightingVShader.GetCompilationLog () << std :: endl;
	
	if ( ! LightingFShader.Compile ( true, false ) )
		std :: cout << "DeferredModelRenderer :: LightingFShader failed to compile:" << std :: endl << LightingFShader.GetCompilationLog () << std :: endl;
	
	/*
	LightingVShader.Compile ( false, false );
	LightingFShader.Compile ( false, false );
	*/
	
	LightingProgram.AddShader ( LightingVShader );
	LightingProgram.AddShader ( LightingFShader );
	
	if ( ! LightingProgram.Link () )
		std :: cout << "DeferredModelRenderer :: LightingProgram failed to link: " << std :: endl << LightingProgram.GetInfoLog () << std :: endl;
	
	LightingVAO.SetProgram ( & LightingProgram );
	
	LightingUniforms.SetProgram ( & LightingProgram );
	LightingUniforms.Link ();
	LightingUniforms.UpdateUniforms ();
	
	RenderQuad -> FlushData ();
	RenderQuad -> BuildVertexArray ( LightingVAO );
	
	AlbedoSpecularTexture.AssignToTextureUnit ( 0 );
	NormalTexture.AssignToTextureUnit ( 1 );
	PositionTexture.AssignToTextureUnit ( 2 );
	
}

void Red::Graphics::DeferredModelRenderer :: DestroyRender ()
{
	
	if ( ! GPUAllocated )
		return;
	
	GBuffer.GPUResourceFree ();
	
	AlbedoSpecularTexture.GPUResourceFree ();
	NormalTexture.GPUResourceFree ();
	PositionTexture.GPUResourceFree ();
	DepthBuffer.GPUResourceFree ();
	
	GeometryUniforms.SetProgram ( NULL );
	GeometryUniforms.ResetUniformStates ();
	
	GeometryProgram.GPUResourceFree ();
	GeometryVShader.GPUResourceFree ();
	GeometryFShader.GPUResourceFree ();
	
	LightingUniforms.SetProgram ( NULL );
	LightingUniforms.ResetUniformStates ();
	
	LightingProgram.GPUResourceFree ();
	LightingVShader.GPUResourceFree ();
	LightingFShader.GPUResourceFree ();
	
	LightingVAO.GPUResourceFree ();
	
	if ( RenderQuad != NULL )
		RenderQuad -> GPUResourceFree ();
	
	GPUAllocated = false;
	
}

void Red::Graphics::DeferredModelRenderer :: Render ()
{
	
	// TODO: Implement and test
	
	GPUContext -> MakeCurrent ();
	
	//std :: cout << "1. GL Error: " << glGetError () << std :: endl;
	
	GBuffer.Bind ( Xenon::GPU::FrameBuffer :: kFrameBufferBindingFlag_ReadDraw );
	GBuffer.Clear ();
	
	//std :: cout << "2. GL Error: " << glGetError () << std :: endl;
	
	GeometryProgram.Bind ();
	
	if ( ( ProjectionMatrixSource != NULL ) && ( ViewMatrixSource != NULL ) )
	{
		
		if ( ( ProjectionMatrixSource -> GetIteration () > LastProjectionIteration ) || ( ViewMatrixSource -> GetIteration () > LastViewIteration ) )
		{
			
			LastProjectionIteration = ProjectionMatrixSource -> GetIteration ();
			LastViewIteration = ViewMatrixSource -> GetIteration ();
			
			new ( & ViewProjectionMatrix ) Xenon::Math :: Matrix4x4 ( ProjectionMatrixSource -> GetFloatArray () );
			Xenon::Math::Matrix4x4 :: Append ( ViewProjectionMatrix, Xenon::Math :: Matrix4x4 ( ViewMatrixSource -> GetFloatArray () ) );
			
			ViewProjectionMatrixUniform.SetDirty ();
			
		}
		
	}
	
	GeometryUniforms.UpdateUniforms ();
	
	// For now, we'll just render each individual component to the output render target for debugging purposes.
	
	uint32_t DataSetLength = RenderDataSet.size ();
	
	for ( uint32_t I = 0; I < DataSetLength; I ++ )
	{
		
		PerModelRenderData * RenderData = RenderDataSet [ I ];
		
		if ( ! RenderData -> RenderModel -> Visible )
			continue;
		
		GPUAllocModelData ( RenderData );
		
		RenderData -> RenderModel -> Draw ();
		
	}
	
	// Now that all the items are rendered to the G-Buffers, we can do lighting rendering
	
	//std :: cout << "0. GL Error: " << glGetError () << std :: endl;
	
	GPUContext -> SetCullingEnabled ( false );
	
	//std :: cout << "1. GL Error: " << glGetError () << std :: endl;
	
	RenderTarget -> Bind ();
	
	//std :: cout << "2. GL Error: " << glGetError () << std :: endl;
	
	LightingVAO.Bind ();
	
	//std :: cout << "3. GL Error: " << glGetError () << std :: endl;
	
	LightingProgram.Bind ();
	
	//std :: cout << "4. GL Error: " << glGetError () << std :: endl;
	
	LightingDrawCall.Draw ();
	
	//std :: cout << "5. GL Error: " << glGetError () << std :: endl;
	
}

void Red::Graphics::DeferredModelRenderer :: GPUAllocModelData ( PerModelRenderData * Data )
{
	
	if ( Data -> GPUAllocated )
		return;
	
	Data -> RenderModel -> GPUAlloc ();
	
	Data -> Uniforms.SetProgram ( & GeometryProgram );
	Data -> VArray.SetProgram ( & GeometryProgram );
	
	Data -> RenderModel -> ApplyUniforms ( Data -> Uniforms );
	Data -> RenderModel -> ApplyVertexData ( Data -> VArray );
	
}

void Red::Graphics::DeferredModelRenderer :: GPUFreeModelData ( PerModelRenderData * Data )
{
	
	if ( ! Data -> GPUAllocated )
		return;
	
	Data -> Uniforms.SetProgram ( NULL );
	Data -> VArray.SetProgram ( NULL );
	
	Data -> Uniforms.ResetUniformStates ();
	Data -> VArray.GPUResourceFree ();
	
	Data -> RenderModel -> GPUFree ();
	
}

Red::Graphics::DeferredModelRenderer::PerModelRenderData :: PerModelRenderData ( Model * RenderModel ):
	RenderModel ( RenderModel ),
	Uniforms (),
	VArray (),
	GPUAllocated ( false )
{
	
	RenderModel -> Reference ();
	
}

Red::Graphics::DeferredModelRenderer::PerModelRenderData :: ~PerModelRenderData ()
{
	
	RenderModel -> Dereference ();
	
}

void Red::Graphics::DeferredModelRenderer :: AddModel ( Model * ToAdd )
{
	
	RenderDataSet.push_back ( new PerModelRenderData ( ToAdd ) );
	
}

void Red::Graphics::DeferredModelRenderer :: RemoveModel ( Model * ToRemove )
{
	
	
	
}
