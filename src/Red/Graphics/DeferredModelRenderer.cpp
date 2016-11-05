#include <Red/Graphics/DeferredModelRenderer.h>

#include <string>
#include <iostream>

#include <Xenon/Geometry/Primitives.h>

#include <Xenon/GPU/GLInclude.h>

const char * Red::Graphics::DeferredModelRenderer :: kModelAttributeName_Position = "Position";
const char * Red::Graphics::DeferredModelRenderer :: kModelAttributeName_Normal = "Normal";
const char * Red::Graphics::DeferredModelRenderer :: kModelAttributeName_Tangent = "Tangent";
const char * Red::Graphics::DeferredModelRenderer :: kModelAttributeName_Color = "Color";
const char * Red::Graphics::DeferredModelRenderer :: kModelAttributeName_TextureCoords = "TextureCoord";

const char * Red::Graphics::DeferredModelRenderer :: kModelAttributeName_InstancedTransform = "InstancedTransform";

const char * _DeferredModelRenderer_VShader_Geometry =
"#version 330 core\n"

"in vec3 Position;\n"
"in vec3 Normal;\n"
"in vec3 Tangent;\n"
"in vec3 Color;\n"
"in vec2 TextureCoord;\n"

"in mat4 InstancedTransform;\n"

"uniform mat4 ModelMatrix;\n"
"uniform mat4 ViewProjectionMatrix;\n"
"uniform mat4 NormalMatrix;\n"

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
"		WorldPosition = vec4 ( Position, 1.0 ) * InstancedTransform;\n"
"	else\n"
"		WorldPosition = vec4 ( Position, 1.0 ) * ModelMatrix;\n"

"	if ( DoNormalTexture )\n"
"	{\n"

"		FragTangent = normalize ( ( vec4 ( Tangent, 1.0 ) * NormalMatrix ).xyz );\n"
"		FragBinormal = normalize ( ( vec4 ( cross ( Tangent, Normal ), 1.0 ) * NormalMatrix ).xyz );\n"

"	}\n"

"	FragPosition = WorldPosition.xyz;\n"
"	FragNormal = normalize ( ( vec4 ( Normal, 1.0 ) * NormalMatrix ).xyz );\n"
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

"uniform vec3 ViewPosition;\n"

"uniform vec3 AmbientLight;\n"

"out vec4 OutColor;\n"

"void main ()\n"
"{\n"

"	vec4 AlbedoSpecular = texture ( AlbedoSpecularSampler, TexturePosition );\n"
"	vec3 Normal = texture ( NormalSampler, TexturePosition ).xyz;\n"
"	vec3 Position = texture ( PositionSampler, TexturePosition ).xyz;\n"

"	vec3 ViewDirection = normalize ( ViewPosition - Position );"

"	vec3 Accumulator = AlbedoSpecular.rgb * AmbientLight;\n"

	/* Various lighting calculations... */

"	OutColor = vec4 ( Accumulator, 1.0 );\n"


"}\n";

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
	ProjectionMatrix (),
	NormalMatrixUniform ( NULL, true ),
	ModelMatrixUniform ( NULL, true ),
	ViewProjectionMatrixUniform ( NULL, true ),
	LightingVAO (),
	LightingUniforms (),
	AlbedoSpecularSamplerUniform ( 0 ),
	NormalSamplerUniform ( 1 ),
	PositionSamplerUniform ( 2 ),
	LightingVShader ( _DeferredModelRenderer_VShader_Lighting, "DeferredModelRenderer :: LightingVShader" ),
	LightingFShader ( _DeferredModelRenderer_FShader_Lighting, "DeferredModelRenderer :: LightingFShader" ),
	LightingProgram ( "DeferredModelRenderer :: LightingProgram" ),
	RenderQuad ( NULL )
{
	
	Xenon::Geometry::Primitives :: Quad2DSpec RenderQuadSpec;
	RenderQuadSpec.WindOutwardFacesClockwise = true;
	RenderQuadSpec.Attributes = Xenon::Geometry::Primitives :: kAttributeFlags_Position;
	RenderQuadSpec.CompositionMode = Xenon::Geometry::Primitives :: kStaticAttributeCompositionMode_Interleaved;
	RenderQuadSpec.TexturePositionCount = 0;
	Xenon::Geometry::Primitives :: SetupNormalQuad2DPositionSpec ( RenderQuadSpec.PositionSpec, "Position", true );
	Xenon::Geometry::Primitives :: GenerateQuad2DMesh ( & RenderQuad, RenderQuadSpec );
	
	if ( RenderQuad != NULL )
		RenderQuad -> Reference ();
	
	NormalMatrixUniform.Reference ();
	ModelMatrixUniform.Reference ();
	ViewProjectionMatrixUniform.Reference ();
	
	GeometryUniforms.AddMatrix4x4Uniform ( "NormalMatrix", & NormalMatrixUniform, false );
	GeometryUniforms.AddMatrix4x4Uniform ( "ModelMatrix", & ModelMatrixUniform, false );
	GeometryUniforms.AddMatrix4x4Uniform ( "ViewProjectionMatrix", & ViewProjectionMatrixUniform, false );
	
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

void Red::Graphics::DeferredModelRenderer :: SetProjection ( Xenon::Math :: Matrix4x4 & ProjectionMatrix )
{
	
	Xenon::Math::Matrix4x4 :: Copy ( this -> ProjectionMatrix, ProjectionMatrix );
	
}

void Red::Graphics::DeferredModelRenderer :: SetupRender ( Xenon::GPU :: FrameBuffer * RenderTarget, Xenon::Math :: Vec2 Dimensions )
{
	
	if ( RenderQuad == NULL )
		return;
	
	if ( GPUContext == NULL )
		return;
	
	if ( RenderTarget == NULL )
		return;
	
	if ( GPUAllocated && ( this -> RenderTarget == RenderTarget ) )
	{
		
		GPUContext -> MakeCurrent ();
		
		AlbedoSpecularTexture.BlankTextureImage ( 0, Xenon::GPU::Texture2D :: kInternalFormat_RGBA, Dimensions.X, Dimensions.Y );
		NormalTexture.BlankTextureImage ( 0, Xenon::GPU::Texture2D :: kInternalFormat_RGB32f, Dimensions.X, Dimensions.Y );
		PositionTexture.BlankTextureImage ( 0, Xenon::GPU::Texture2D :: kInternalFormat_RGB32f, Dimensions.X, Dimensions.Y );
		
		return;
		
	}
	
	if ( this -> RenderTarget != NULL )
		this -> RenderTarget -> Dereference ();
	
	this -> RenderTarget = RenderTarget;
	
	if ( this -> RenderTarget != NULL )
		this -> RenderTarget -> Reference ();
	else
		return;
	
	if ( GPUAllocated )
	{
		
		GPUContext -> MakeCurrent ();
		
		LightingVAO.Bind ();
		
		RenderTarget -> Bind ();
		
		AlbedoSpecularTexture.BlankTextureImage ( 0, Xenon::GPU::Texture2D :: kInternalFormat_RGBA, Dimensions.X, Dimensions.Y );
		NormalTexture.BlankTextureImage ( 0, Xenon::GPU::Texture2D :: kInternalFormat_RGB32f, Dimensions.X, Dimensions.Y );
		PositionTexture.BlankTextureImage ( 0, Xenon::GPU::Texture2D :: kInternalFormat_RGB32f, Dimensions.X, Dimensions.Y );
		
		return;
		
	}
	
	GPUContext -> MakeCurrent ();
	
	// Set up geometry pass
	GBuffer.Bind ();
	
	AlbedoSpecularTexture.BlankTextureImage ( 0, Xenon::GPU::Texture2D :: kInternalFormat_RGBA, Dimensions.X, Dimensions.Y );
	NormalTexture.BlankTextureImage ( 0, Xenon::GPU::Texture2D :: kInternalFormat_RGB32f, Dimensions.X, Dimensions.Y );
	PositionTexture.BlankTextureImage ( 0, Xenon::GPU::Texture2D :: kInternalFormat_RGB32f, Dimensions.X, Dimensions.Y );
	
	DepthBuffer.AllocateStorage ( Xenon::GPU::Texture2D :: kInternalFormat_Depth, Dimensions.X, Dimensions.Y );
	
	GBuffer.SetRenderTexture2D ( Xenon::GPU::FrameBuffer :: kOutputAttachment_ColorBuffer, 0, AlbedoSpecularTexture );
	GBuffer.SetRenderTexture2D ( Xenon::GPU::FrameBuffer :: kOutputAttachment_ColorBuffer, 1, NormalTexture );
	GBuffer.SetRenderTexture2D ( Xenon::GPU::FrameBuffer :: kOutputAttachment_ColorBuffer, 2, PositionTexture );
	
	GBuffer.SetRenderBuffer ( Xenon::GPU::FrameBuffer :: kOutputAttachment_DepthBuffer, 0, DepthBuffer );
	
	glDrawBuffers ( 3, AttachmentList );
	
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
	GeometryProgram.Link ();
	GeometryProgram.Reference ();
	
	GeometryUniforms.SetProgram ( & GeometryProgram );
	GeometryUniforms.Link ();
	
	// Set up lighting pass
	
	LightingVAO.Bind ();
	RenderTarget -> Bind ();
	
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
	LightingProgram.Link ();
	LightingProgram.Reference ();
	LightingVAO.SetProgram ( & LightingProgram );
	
	LightingUniforms.SetProgram ( & LightingProgram );
	LightingUniforms.Link ();
	
	RenderQuad -> FlushData ();
	RenderQuad -> BuildVertexArray ( LightingVAO );
	
	
	AlbedoSpecularTexture.SetFiltering ( Xenon::GPU::Texture2D :: kMinimizingFilter_Nearest, Xenon::GPU::Texture2D :: kMagnificationFilter_Nearest );
	AlbedoSpecularTexture.AssignToTextureUnit ( 0 );
	
	NormalTexture.SetFiltering ( Xenon::GPU::Texture2D :: kMinimizingFilter_Nearest, Xenon::GPU::Texture2D :: kMagnificationFilter_Nearest );
	NormalTexture.AssignToTextureUnit ( 1 );
	
	PositionTexture.SetFiltering ( Xenon::GPU::Texture2D :: kMinimizingFilter_Nearest, Xenon::GPU::Texture2D :: kMagnificationFilter_Nearest );
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
	
	// TODO: Setup rendering chain
	
}

Red::Graphics::DeferredModelRenderer::PerModelRenderData :: PerModelRenderData ( Model * RenderModel, uint32_t Flags ):
	RenderModel ( RenderModel ),
	DoInstancedTransformUniform ( ( Flags & kRenderFlags_InstancedTransform ) != 0 ),
	DoNormalTextureUniform ( ( Flags & kRenderFlags_NormalTexture ) != 0 ),
	DoColorTextureUniform ( ( Flags & kRenderFlags_ColorTexture ) != 0 ),
	Uniforms (),
	AttributeArray (),
	GPUAllocated ( false )
{
}

Red::Graphics::DeferredModelRenderer::PerModelRenderData :: ~PerModelRenderData ()
{
	
	
	
}
