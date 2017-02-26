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

"uniform mat4 ModelMatrix;\n"
"uniform mat4 ViewProjectionMatrix;\n"

"in vec3 Position;\n"

"void main ()\n"
"{\n"

"	gl_Position = vec4 ( Position, 1.0 ) * ModelMatrix * ViewProjectionMatrix;\n"

"}"
;

const char * _DeferredModelRenderer_FShader_Geometry =
"#version 330 core\n"

"out vec4 OutColor;\n"

"void main ()\n"
"{\n"

"	OutColor = vec4 ( 1.0, 1.0, 0.0, 1.0 );\n"

"}";

const char * _DeferredModelRenderer_VShader_Lighting =
"#version 330 core\n"

"in vec2 Position;\n"

"out vec2 SamplePosition;\n"

"void main ()\n"
"{\n"

"	SamplePosition = ( Position + vec2 ( 1.0, 1.0 ) ) * vec2 ( 0.5, 0.5 );\n"

"	gl_Position = vec4 ( Position, 0.5, 1.0 );\n"

"}";

const char * _DeferredModelRenderer_FShader_Lighting =
"#version 330 core\n"

"in vec2 SamplePosition;\n"

"out vec4 OutColor;\n"

"void main ()\n"
"{\n"

"	OutColor = vec4 ( SamplePosition, 1.0, 1.0 );\n"

"}";

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
	RefCounted ( 0 ),
	GPUContext ( NULL ),
	RenderTarget ( NULL ),
	GPUAllocated ( false ),
	GeometryVShader ( _DeferredModelRenderer_VShader_Geometry, "DeferredModelRenderer :: GeometryVShader" ),
	GeometryFShader ( _DeferredModelRenderer_FShader_Geometry, "DeferredModelRenderer :: GeometryFShader" ),
	GeometryProgram ( "DeferredModelRenderer :: GeometryProgram" ),
	GeometryUniforms (),
	ViewProjectionMatrix (),
	ViewProjectionUniformSource ( & ViewProjectionMatrix, true ),
	ViewMatrixSource ( NULL ),
	ProjectionMatrixSource ( NULL ),
	AlbedoSpecularSamplerUniform ( 0 ),
	NormalSamplerUniform ( 1 ),
	PositionSamplerUniform ( 2 ),
	LightingDrawCall ( Xenon::GPU::IndexedDrawCall :: NO_INIT ),
	LightingVAO (),
	LightingUniforms (),
	LightingVShader ( _DeferredModelRenderer_VShader_Lighting, "DeferredModelRenderer :: LightingVShader" ),
	LightingFShader ( _DeferredModelRenderer_FShader_Lighting, "DeferredModelRenderer :: LightingFShader" ),
	LightingProgram ( "DeferredModelRenderer :: LightingProgram" ),
	RenderQuad ( NULL ),
	RenderDataSet ()
{
	
	Xenon::Geometry::Primitives :: Quad2DSpec RenderQuadSpec;
	
	RenderQuadSpec.WindOutwardFacesClockwise = false;
	RenderQuadSpec.Attributes = Xenon::Geometry::Primitives :: kAttributeFlags_Position;
	RenderQuadSpec.CompositionMode = Xenon::Geometry::Primitives :: kStaticAttributeCompositionMode_Interleaved;
	
	RenderQuadSpec.PositionSpec.Positions [ Xenon::Geometry::Primitives :: kQuad2DVertexIndex_XNeg_YNeg ] = Xenon::Math :: Vec2 ( - 1.0, - 1.0 );
	RenderQuadSpec.PositionSpec.Positions [ Xenon::Geometry::Primitives :: kQuad2DVertexIndex_XPos_YNeg ] = Xenon::Math :: Vec2 ( + 1.0, - 1.0 );
	RenderQuadSpec.PositionSpec.Positions [ Xenon::Geometry::Primitives :: kQuad2DVertexIndex_XNeg_YPos ] = Xenon::Math :: Vec2 ( - 1.0, + 1.0 );
	RenderQuadSpec.PositionSpec.Positions [ Xenon::Geometry::Primitives :: kQuad2DVertexIndex_XPos_YPos ] = Xenon::Math :: Vec2 ( + 1.0, + 1.0 );
	RenderQuadSpec.PositionSpec.AttributeName = "Position";
	RenderQuadSpec.PositionSpec.Static = true;
	
	Xenon::Geometry::Primitives :: GenerateQuad2DMesh ( & RenderQuad, RenderQuadSpec );
	
	if ( RenderQuad != NULL )
	{
		
		RenderQuad -> Reference ();
		RenderQuad -> ConfigureIndexedDrawCall ( LightingDrawCall );
		
	}
	
	GeometryProgram.Reference ();
	
	GeometryUniforms.Reference ();
	
	GeometryUniforms.AddMatrix4x4Uniform ( "ViewProjectionMatrix", & ViewProjectionUniformSource, false );
	
	AlbedoSpecularSamplerUniform.Reference ();
	NormalSamplerUniform.Reference ();
	PositionSamplerUniform.Reference ();
	
	LightingProgram.Reference ();
	
	LightingUniforms.Reference ();
	
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
	
	if ( this -> RenderTarget != RenderTarget )
	{
		
		if ( this -> RenderTarget != NULL )
			this -> RenderTarget -> Dereference ();
		
		this -> RenderTarget = RenderTarget;
		
		if ( this -> RenderTarget != NULL )
			this -> RenderTarget -> Reference ();
		
	}
	
	if ( this -> RenderTarget == NULL )
		return;
	
	
	
	if ( ! GeometryVShader.Compile ( true, false ) )
		std :: cout << "DeferredModelRenderer :: GeometryVShader failed to compile:" << std :: endl << GeometryVShader.GetCompilationLog () << std :: endl;
	
	if ( ! GeometryFShader.Compile ( true, false ) )
		std :: cout << "DeferredModelRenderer :: GeometryFShader failed to compile:" << std :: endl << GeometryFShader.GetCompilationLog () << std :: endl;
	
	GeometryProgram.AddShader ( GeometryVShader );
	GeometryProgram.AddShader ( GeometryFShader );
	
	if ( ! GeometryProgram.Link () )
		std :: cout << "DeferredModelRenderer :: GeometryProgram failed to compile: " << std :: endl << GeometryProgram.GetInfoLog () << std :: endl;
	
	GeometryUniforms.SetProgram ( & GeometryProgram );
	GeometryUniforms.Link ();
	GeometryUniforms.UpdateUniforms ();
	
	//================================================================//
	
	// Set up lighting pass
	
	LightingVAO.Bind ();
	
	if ( ! LightingVShader.Compile ( true, false ) )
		std :: cout << "DeferredModelRenderer :: LightingVShader failed to compile:" << std :: endl << LightingVShader.GetCompilationLog () << std :: endl;
	
	if ( ! LightingFShader.Compile ( true, false ) )
		std :: cout << "DeferredModelRenderer :: LightingFShader failed to compile:" << std :: endl << LightingFShader.GetCompilationLog () << std :: endl;
	
	LightingProgram.AddShader ( LightingVShader );
	LightingProgram.AddShader ( LightingFShader );
	
	if ( ! LightingProgram.Link () )
		std :: cout << "DeferredModelRenderer :: LightingProgram failed to link: " << std :: endl << LightingProgram.GetInfoLog () << std :: endl;
	
	LightingVAO.SetProgram ( & LightingProgram );
	
	LightingUniforms.SetProgram ( & LightingProgram );
	LightingUniforms.Link ();
	LightingUniforms.UpdateUniforms ();
	
	RenderQuad -> GPUResourceAlloc ();
	RenderQuad -> BuildVertexArray ( LightingVAO );
	RenderQuad -> FlushData ();
	
	LightingVAO.Build ();
	
}

void Red::Graphics::DeferredModelRenderer :: DestroyRender ()
{
	
	if ( ! GPUAllocated )
		return;
	
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
	
	if ( ( ViewMatrixSource != NULL ) && ( ProjectionMatrixSource != NULL ) )
	{
		
		Xenon::Math :: Matrix4x4 View ( ViewMatrixSource -> GetFloatArray () );
		Xenon::Math :: Matrix4x4 Projection ( ProjectionMatrixSource -> GetFloatArray () );
		
		Xenon::Math::Matrix4x4 :: Copy ( ViewProjectionMatrix, Projection );
		Xenon::Math::Matrix4x4 :: Append ( ViewProjectionMatrix, View );
		
		ViewProjectionUniformSource.SetDirty ();
		
	}
	
	GPUContext -> SetCullingEnabled ( false );
	GPUContext -> SetDepthTestEnabled ( false );
	GPUContext -> SetFrontFace ( Xenon::GPU::Context :: kFrontFace_CounterClockwise );
	GPUContext -> SetCullingFace ( Xenon::GPU::Context :: kCullingFace_Back );
	GPUContext -> BlendFunc ( Xenon::GPU::Context :: kBlendFactor_SourceAlpha, Xenon::GPU::Context :: kBlendFactor_OneMinusSourceAlpha, Xenon::GPU::Context :: kBlendFactor_One, Xenon::GPU::Context :: kBlendFactor_Zero );
	GPUContext -> BlendEquation ( Xenon::GPU::Context :: kBlendOperator_Add, Xenon::GPU::Context :: kBlendOperator_Add );
	
	RenderTarget -> Bind ();
	
	uint32_t ModelCount = RenderDataSet.size ();
	
	for ( uint32_t I = 0; I < ModelCount; I ++ )
	{
		
		std :: cout << "0 GL ERROR: " << glGetError () << std :: endl;
		
		PerModelRenderData * RenderData = RenderDataSet [ I ];
		
		GPUAllocModelData ( RenderData );
		
		std :: cout << "1 GL ERROR: " << glGetError () << std :: endl;
		
		RenderData -> VArray.Bind ();
		RenderData -> RenderModel -> FlushData ();
		
		std :: cout << "2 GL ERROR: " << glGetError () << std :: endl;
		
		GeometryProgram.Bind ();
		
		std :: cout << "3 GL ERROR: " << glGetError () << std :: endl;
		
		RenderData -> Uniforms.ResetUniformStates ();
		RenderData -> Uniforms.UpdateUniforms ();
		GeometryUniforms.UpdateUniforms ();
		
		std :: cout << "4 GL ERROR: " << glGetError () << std :: endl;
		
		RenderData -> RenderModel -> Draw ();
		
		std :: cout << "5 GL ERROR: " << glGetError () << std :: endl;
		
	}
	
	/*
	
	GPUContext -> SetCullingEnabled ( false );
	GPUContext -> SetDepthTestEnabled ( false );
	GPUContext -> SetFrontFace ( Xenon::GPU::Context :: kFrontFace_CounterClockwise );
	GPUContext -> SetCullingFace ( Xenon::GPU::Context :: kCullingFace_Back );
	GPUContext -> BlendFunc ( Xenon::GPU::Context :: kBlendFactor_SourceAlpha, Xenon::GPU::Context :: kBlendFactor_Zero, Xenon::GPU::Context :: kBlendFactor_One, Xenon::GPU::Context :: kBlendFactor_Zero );
	GPUContext -> BlendEquation ( Xenon::GPU::Context :: kBlendOperator_Add, Xenon::GPU::Context :: kBlendOperator_Add );
	
	RenderTarget -> Bind ();
	
	LightingVAO.Bind ();
	LightingProgram.Bind ();
	
	LightingUniforms.UpdateUniforms ();
	
	LightingDrawCall.Draw ();
	
	*/
	
}

void Red::Graphics::DeferredModelRenderer :: GPUAllocModelData ( PerModelRenderData * Data )
{
	
	if ( Data -> GPUAllocated )
		return;
	
	Data -> RenderModel -> GPUAlloc ();
	
	Data -> Uniforms.SetProgram ( & GeometryProgram );
	Data -> RenderModel -> ApplyUniforms ( Data -> Uniforms );
	Data -> Uniforms.Link ();
	
	Data -> VArray.GPUResourceAlloc ();
	Data -> VArray.SetProgram ( & GeometryProgram );
	Data -> RenderModel -> ApplyVertexData ( Data -> VArray );
	Data -> VArray.Build ();
	
	Data -> GPUAllocated = true;
	
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
	
	Data -> GPUAllocated = false;
	
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
