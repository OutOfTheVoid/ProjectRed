#include <iostream>
#include <SDL2/SDL.h>

#include <SDLX/Lib.h>
#include <SDLX/Window.h>
#include <SDLX/Surface.h>
#include <SDLX/GLContext.h>
#include <SDLX/Timer.h>
#include <SDLX/UserEvent.h>
#include <SDLX/Keyboard.h>
#include <SDLX/Mouse.h>

#include <Xenon/GPU/GLInclude.h>
#include <Xenon/GPU/Context.h>
#include <Xenon/GPU/VertexShader.h>
#include <Xenon/GPU/FragmentShader.h>
#include <Xenon/GPU/ShaderProgram.h>
#include <Xenon/GPU/VertexBuffer.h>
#include <Xenon/GPU/IndexBuffer.h>
#include <Xenon/GPU/VertexArray.h>
#include <Xenon/GPU/Texture2D.h>
#include <Xenon/GPU/FrameBuffer.h>
#include <Xenon/GPU/UniformSet.h>

#include <Xenon/Math/Vec3.h>
#include <Xenon/Math/Matrix4x4.h>
#include <Xenon/Math/Matrix3x3.h>
#include <Xenon/Math/Quaternion.h>
#include <Xenon/Math/Transform3D.h>
#include <Xenon/Math/RawFloatUniformSource.h>
#include <Xenon/Math/RawMatrix4x4UniformSource.h>

#include <Xenon/Geometry/Mesh.h>
#include <Xenon/Geometry/Primitives.h>

#include <RAUX/ObjFile.h>
#include <RAUX/StlFile.h>

#include <math.h>

#include <string>

void WindowCloseEvent ( SDL_WindowEvent * Event, SDLX::Window * Win, void * Data );
void DrawEventPush ( SDLX :: Timer * Source, void * Data );
void DrawEvent ( SDL_UserEvent * Event );
void MouseMoveListener ( SDL_MouseMotionEvent * Event, void * Data );

void KeyListener ( int32_t ScanCode, int32_t KeyCode, bool Down, void * Data );

#define WINDOW_WIDTH_0 800
#define WINDOW_HEIGHT_0 600

#define WINDOW_WIDTH_1 2000
#define WINDOW_HEIGHT_1 1400

typedef struct
{
	
	Xenon::GPU :: Context * Cont; 
	SDLX :: Window * Win;
	SDLX :: Timer * RTimer;
	
	Xenon::Geometry :: Mesh * Cube;
	
	Xenon::GPU :: VertexArray * ColorArray;
	Xenon::GPU :: ShaderProgram * ColorProgram;
	Xenon::GPU :: UniformSet * ColorUniforms;
	
	Xenon::Math :: Transform3D * Transform;
	Xenon::Math :: Matrix4x4 * Projection;
	Xenon::Math :: RawMatrix4x4UniformSource * ProjectionSource;
	
	Xenon::Math :: Quaternion Rotation;
	
	int32_t X;
	int32_t Y;
	
	uint32_t Frame;
	
} RenderStruct;

typedef struct 
{
	
	uint32_t RenderEventID;
	
	RenderStruct * RenderData;
	
} UserEventPushStruct;

typedef struct 
{
	
	bool Resized;
	
	RenderStruct * RenderData;
	
	
} KeyboardStruct;

/*
* NOTE: This file is simply a test case for the engine. I've left it in the repository so people can see what I'm working on at the moment.
*/

int main ( int argc, const char * argv [] )
{
	
	( void ) argc;
	( void ) argv;
	
	uint32_t Status;
	
	/*
	RAUX :: ObjFile MyObj ( "Cube.obj", RAUX::ObjFile :: kFlags_StoreComments );
	MyObj.Load ( & Status );
	
	if ( Status != 0 )
		std :: cout << "Obj load failed: " << Status << std :: endl;
	
	for ( uint32_t I = 0; I < MyObj.GetGroupCount (); I ++ )
	{
		
		const RAUX::ObjFile :: Group * const ObjGroup = MyObj.GetGroup ( I );
		
		if ( ObjGroup != NULL )
		{
			
			std :: cout << "Group " << ObjGroup -> Name << ": " << ObjGroup -> FaceIndecies.size () << " faces: " << std :: endl;
			
			for ( uint32_t F = 0; F < ObjGroup -> FaceIndecies.size (); F ++ )
				std :: cout << "*	Face " << F << ": " << MyObj.GetFace ( ObjGroup -> FaceIndecies [ F ] ).VertexCount << " vertecies." << std :: endl;
				
			
		}
		
	}
	*/
	
	if ( Status != RAUX::StlFile :: kStatus_Success )
	{
		
		std :: cout << "Failed to load stl file" << std :: endl;
		
		return - 1;
		
	}
	
	SDLX::Lib :: Init ( & Status, SDLX::Lib :: kSDLFlag_Video );
	
	if ( Status != SDLX :: kStatus_Success )
		return - 1;
	
	SDLX::Window * Win = SDLX::Window :: CreateWindow ( & Status, "Test", WINDOW_WIDTH_0, WINDOW_HEIGHT_0, SDLX::Window :: kCreateFlag_Shown | SDLX::Window :: kCreateFlag_HighDPI | SDLX::Window :: kCreateFlag_OpenGL );
	
	SDLX::GLContext :: RequestGLContextVersion ( SDLX::GLContext :: kGLProfile_Core, 3, 2 );
	SDLX::GLContext :: RequestDepthBufferSize ( 24 );
	SDLX::GLContext :: RequestStencilBufferSize ( 8 );
	SDLX::GLContext :: RequestDoubleBuffering ( true );
	SDLX::GLContext :: RequestVSyncMode ( SDLX::GLContext :: kVSyncMode_Synced_LateSwapTearing );
	SDLX::GLContext :: RequestMSAA ( true, 4 );

	if ( Status != SDLX::Window :: kStatus_Success )
	{
		
		SDLX::Lib :: DeInit ();
		
		return - 2;
		
	}
	
	Win -> Own ();
	Win -> AddEventHook ( SDL_WINDOWEVENT_CLOSE, & WindowCloseEvent, NULL );
	
	SDLX :: GLContext * GL = Win -> GetOpenGLContext ();
	
	if ( GL == NULL )
	{
		
		Win -> Disown ();
		
		SDLX::Lib :: DeInit ();
		
	}
	
	SDLX::Mouse :: Lock ();
	
	Xenon::GPU :: Context * Cont = new Xenon::GPU :: Context ( GL );
	
	Cont -> MakeCurrent ();
	Cont -> GetDefaultFrameBuffer () -> SetClearColor ( 0.0f, 0.0f, 0.0f );
	
	Xenon::Geometry :: Mesh * TestMesh = NULL;
	
	/*Xenon::Geometry::Primitives :: CubeSpec CubeGenerationSpec;
	
	CubeGenerationSpec.WindOutwardFacesClockwise = true;
	CubeGenerationSpec.CompositionMode = Xenon::Geometry::Primitives :: kStaticAttributeCompositionMode_Interleaved;
	CubeGenerationSpec.Attributes = Xenon::Geometry::Primitives :: kAttributeFlags_Position | Xenon::Geometry::Primitives :: kAttributeFlags_Normal;
	
	Xenon::Geometry::Primitives :: SetupUnitCubeVertexPositionSpec ( CubeGenerationSpec.PositionSpec, "Position", true );
	//Xenon::Geometry::Primitives :: SetupRadialCubeVertexNormalSpec ( CubeGenerationSpec.NormalSpec, "Normal", true );
	Xenon::Geometry::Primitives :: SetupRealCubeFaceNormalSpec ( CubeGenerationSpec.NormalSpec, "Normal", true );
	bool Generated = Xenon::Geometry::Primitives :: GenerateCubeMesh ( & TestMesh, CubeGenerationSpec );
	
	if ( ! Generated )
	{
		
		std :: cout << "Failed to generate cube mesh" << std :: endl;
		
		delete Cont;
		
		Win -> Disown ();
		SDLX::Lib :: DeInit ();
		
		return - 1;
		
	}*/
	
	RAUX :: StlFile MySTL ( "Teapot.stl" );
	MySTL.Load ( & Status, RAUX::StlFile :: kFlags_ReplaceNormalsForced | RAUX::StlFile :: kFlags_ForwardFace_CounterClockwise | RAUX::StlFile :: kFlags_CenterPositions | RAUX::StlFile :: kFlags_NormalizePositions );
	
	RAUX::StlFile :: MeshParameters STLParams ( RAUX::StlFile :: kMeshParameterFlags_Normals | RAUX::StlFile :: kMeshParameterFlags_InterleavedAttributes, "Position", "Normal" );
	
	TestMesh = MySTL.CreateMesh ( STLParams );
	
	if ( TestMesh == NULL )
		std :: cout << "Failed to create mesh from STL data " << std :: endl;
	
	GLchar VShaderSource [] =
	"#version 150\n\n"
	
	"in vec3 Position;\n\n"
	
	"in vec3 Normal;\n\n"
	
	"uniform mat4 NormalTransform;\n\n"
	"uniform mat4 InverseNormalTransform;\n\n"
	"uniform mat4 ModelTransform;\n\n"
	"uniform mat4 ProjectionTransform;\n\n"
	
	"out vec3 FragmentNormal;\n\n"
	"out vec3 FragmentWorldPosition;\n\n"
	
	"void main ()\n"
	"{\n\n"
	
	"	float OffsetX = ( gl_InstanceID % 4 ) - 1.5;\n"
	"	float OffsetY = ( ( gl_InstanceID - ( gl_InstanceID % 4 ) ) / 4.0 ) - 1.0;\n\n"
	
	"	FragmentNormal = normalize ( vec3 ( InverseNormalTransform * vec4 ( Normal, 1.0 ) ) );\n\n"
	
	"	vec4 ModelPosition = ( ModelTransform * vec4 ( Position, 1.0 ) ) + vec4 ( OffsetX, OffsetY, 0.0f, 0.0f );\n"
	//"	ModelPosition += ModelPosition;\n\n"
	"	FragmentWorldPosition = ModelPosition.xyz;\n"
	"	gl_Position = ProjectionTransform * ModelPosition;\n\n"
	
	"}\n";
	
	Xenon::GPU :: VertexShader ColorVShader ( VShaderSource, "VertexShader_Color" );
	
	GLchar FShaderSource [] =
	"#version 150\n\n"
	
	"in vec3 FragmentNormal;\n\n"
	"in vec3 FragmentWorldPosition;\n\n"
	
	"out vec4 Color;\n\n"
	
	"void main ()\n"
	"{\n\n"
	
	"	vec3 LightPosition = vec3 ( 0.0, 0.0, 0.0 );\n"
	"	vec3 LightColor = vec3 ( 0.5, 0.5, 1.0 );\n"
	"	float DiffuseStrength = 1.0f;\n"
	"	float SpecularStrength = 0.5f;\n"
	"	float AmbiantStrength = 0.1f;\n\n"
	
	"	vec3 CameraPosition = vec3 ( 0.0, 0.0, 0.0 );\n\n"
	
	"	vec3 LightDirection = normalize ( LightPosition - FragmentWorldPosition );\n"
	"	vec3 ViewDirection = normalize ( CameraPosition - FragmentWorldPosition );\n"
	"	vec3 ReflectionDirection = reflect ( - LightDirection, FragmentNormal );\n\n"
	
	"	float SpecularCoefficient = pow ( max ( dot ( ViewDirection, ReflectionDirection ), 0.0 ), 16 );\n"
	"	float DiffuseCoefficient = max ( dot ( FragmentNormal, LightDirection ), 0.0 );\n\n"
	
	"	float LightStrength = DiffuseStrength * DiffuseCoefficient + SpecularStrength * SpecularCoefficient + AmbiantStrength;\n\n"
	"	LightStrength = LightStrength * 100.0;\n"
	"	LightStrength = ( LightStrength - mod ( LightStrength, 1.0 ) ) / 100.0;\n"
	
	"	Color = vec4 ( LightColor * LightStrength, 1.0 );\n\n"
	
	"}\n";
	
	Xenon::GPU :: FragmentShader ColorFShader ( FShaderSource, "FragmentShader_Color" );
	
	if ( ! ColorVShader.Compile ( true ) )
		std :: cout << "VertexShader_Color failed to compile: " << std :: endl << ColorVShader.GetCompilationLog () << std :: endl;
	
	if ( ! ColorFShader.Compile ( true ) )
		std :: cout << "FragmentShader_Color failed to compile: " << std :: endl << ColorFShader.GetCompilationLog () << std :: endl;
	
	Xenon::Math :: Matrix4x4 Projection ( Xenon::Math::Matrix4x4 :: NO_INIT );
	
	Xenon::Math::Matrix4x4 :: SetAsPerspectiveProjectionFieldOfView ( Projection, 0.1, 4.0, 60.0 / 180.0 * 3.1415926, 2048.0 / 1536.0 );
	Xenon::Math::RawMatrix4x4UniformSource PerspeciveProjectionUniformSource ( & Projection, true );
	
	Xenon::Math :: Transform3D Transform ( Xenon::Math :: Vec3 ( 0.0f, 0.0f, - 3.0f ), Xenon::Math :: Vec3 ( 0.5f, 0.5f, 0.5f ) );
	
	Xenon::GPU :: ShaderProgram ColorProgram ( "ShaderProgram_Color" );
	ColorProgram.AddShader ( ColorVShader );
	ColorProgram.AddShader ( ColorFShader );
	ColorProgram.Link ();
	
	Xenon::GPU :: VertexArray ColorVAO;
	TestMesh -> BuildVertexArray ( ColorVAO );
	ColorVAO.SetProgram ( & ColorProgram );
	ColorVAO.Build ();
	
	Xenon::GPU :: UniformSet ColorUniforms ( & ColorProgram );
	ColorUniforms.AddMatrix4x4Uniform ( "ModelTransform", & Transform.GetModelUniformSource () );
	ColorUniforms.AddMatrix4x4Uniform ( "NormalTransform", & Transform.GetNormalUniformSource () );
	ColorUniforms.AddMatrix4x4Uniform ( "InverseNormalTransform", & Transform.GetInverseNormalUniformSource () );
	ColorUniforms.AddMatrix4x4Uniform ( "ProjectionTransform", & PerspeciveProjectionUniformSource );
	ColorUniforms.Link ();
	
	RenderStruct RData;
	
	RData.Cont = Cont;
	RData.Win = Win;
	RData.Cube = TestMesh;
	RData.ColorProgram = & ColorProgram;
	RData.ColorArray = & ColorVAO;
	RData.ColorUniforms = & ColorUniforms;
	RData.Transform = & Transform;
	RData.Projection = & Projection;
	RData.ProjectionSource = & PerspeciveProjectionUniformSource;
	RData.Rotation = Xenon::Math::Quaternion :: IDENTITY;
	
	RData.Frame = 0;
	
	UserEventPushStruct UEData;
	
	uint32_t RenderEventID = SDLX::UserEvent :: GetNewEventID ( & Status );
	
	UEData.RenderEventID = RenderEventID;
	UEData.RenderData = & RData;
	
	SDLX :: Timer * DrawTimer = new SDLX :: Timer ( & DrawEventPush, reinterpret_cast <void *> ( & UEData ) );
	DrawTimer -> Start ( 1000 / 120 );
	
	RData.RTimer = DrawTimer;
	
	SDLX::UserEvent :: SetEventHook ( RenderEventID, & DrawEvent );
	
	KeyboardStruct KData;
	
	KData.RenderData = & RData;
	KData.Resized = false;
	
	SDLX::Keyboard :: AddKeyListener ( & KeyListener, reinterpret_cast <void *> ( & KData ) );
	SDLX::Mouse :: AddMotionListener ( & MouseMoveListener, reinterpret_cast <void *> ( & RData ) );
	
	SDLX::Lib :: EventLoop ( & Status );
	
	Win -> Disown ();
	SDLX::Lib :: DeInit ();
	
	delete TestMesh;
	
	return 0;
	
}

void MouseMoveListener ( SDL_MouseMotionEvent * Event, void * Data )
{
	
	Xenon::Math::Quaternion Delta ( Xenon::Math::Quaternion :: NO_INIT );
	
	Xenon::Math::Quaternion :: FromAxisAngle ( Delta, Xenon::Math::Vec3 :: UP, Event -> xrel / 100.0f );
	reinterpret_cast <RenderStruct *> ( Data ) -> Transform -> AppendRotation ( Delta );
	
	Xenon::Math::Quaternion :: FromAxisAngle ( Delta, Xenon::Math::Vec3 :: RIGHT, Event -> yrel / 100.0f );
	reinterpret_cast <RenderStruct *> ( Data ) -> Transform -> AppendRotation ( Delta );
	
}

void KeyListener ( int32_t ScanCode, int32_t KeyCode, bool Down, void * Data )
{
	
	(void) Data;
	(void) ScanCode;
	
	if ( KeyCode == SDLK_ESCAPE )
	{
		
		SDL_Event CloseEvent;
		
		CloseEvent.type = SDL_QUIT;
		
		SDLX::Lib :: PushEvent ( & CloseEvent );
		
	}
	
	if ( KeyCode == SDLK_r && Down )
	{
		
		if ( reinterpret_cast <KeyboardStruct *> ( Data ) -> Resized )	
		{
			
			reinterpret_cast <KeyboardStruct *> ( Data ) -> Resized = false;
			
			reinterpret_cast <KeyboardStruct *> ( Data ) -> RenderData -> Win -> Resize ( WINDOW_WIDTH_0, WINDOW_HEIGHT_0 );
			
			Xenon::Math::Matrix4x4 :: SetAsPerspectiveProjectionFieldOfView ( * reinterpret_cast <KeyboardStruct *> ( Data ) -> RenderData -> Projection, 0.1, 4.0, 60.0 / 180.0 * 3.1415926, static_cast <float> ( WINDOW_WIDTH_0 ) / static_cast <float> ( WINDOW_HEIGHT_0 ) );
			
		}
		else
		{
			
			reinterpret_cast <KeyboardStruct *> ( Data ) -> Resized = true;
			
			reinterpret_cast <KeyboardStruct *> ( Data ) -> RenderData -> Win -> Resize ( WINDOW_WIDTH_1, WINDOW_HEIGHT_1 );
			
			Xenon::Math::Matrix4x4 :: SetAsPerspectiveProjectionFieldOfView ( * reinterpret_cast <KeyboardStruct *> ( Data ) -> RenderData -> Projection, 0.1, 4.0, 60.0 / 180.0 * 3.1415926, static_cast <float> ( WINDOW_WIDTH_1 ) / static_cast <float> ( WINDOW_HEIGHT_1 ) );
			
		}
		
	}
	
	reinterpret_cast <KeyboardStruct *> ( Data ) -> RenderData -> ProjectionSource -> SetDirty ();
	
}

void WindowCloseEvent ( SDL_WindowEvent * Event, SDLX::Window * Win, void * Data )
{
	
	uint32_t Status;
	
	( void ) Event;
	( void ) Data;
	
	Win -> Close ( & Status );
	
}

void DrawEventPush ( SDLX :: Timer * Source, void * Data )
{
	
	if ( Data == NULL )
		return;
	
	SDLX::Mutex * TimerLock = Source -> GetMutex ();
	
	if ( TimerLock )
		TimerLock -> Lock ();
	Source -> Stop ();
	if ( TimerLock )
		TimerLock -> Unlock ();
	
	UserEventPushStruct * UEData = reinterpret_cast <UserEventPushStruct *> ( Data );
	
	SDLX::UserEvent :: PushEvent ( UEData -> RenderEventID, reinterpret_cast <void *> ( UEData -> RenderData ), NULL );
	
}

void DrawEvent ( SDL_UserEvent * Event )
{
	
	RenderStruct * RData = reinterpret_cast <RenderStruct *> ( Event -> data1 );
	
	if ( RData == NULL )
		return;
	
	RData -> Cont -> MakeCurrent ();
	RData -> Cont -> SetCullingEnabled ( true );
	RData -> Cont -> SetDepthTestEnabled ( true );
	RData -> Cont -> SetFrontFace ( Xenon::GPU::Context :: kFrontFace_Clockwise );
	
	RData -> Cont -> GetDefaultFrameBuffer () -> Clear ( Xenon::GPU::FrameBuffer :: kFrameBufferComponent_Color | Xenon::GPU::FrameBuffer :: kFrameBufferComponent_Depth );
	
	RData -> Cont -> SetCullingFace ( Xenon::GPU::Context :: kCullingFace_Back );
	
	RData -> ColorProgram -> Bind ();
	RData -> ColorArray -> Bind ();
	RData -> ColorUniforms -> UpdateUniforms ( false );
	
	glDrawElementsInstanced ( GL_TRIANGLES, RData -> Cube -> GetIndexCount (), RData -> Cube -> GetIndexType (), 0, 12 );
	
	RData -> Win -> GLSwap ();
	
	RData -> Frame ++;
	
	SDLX::Mutex * TimerLock = RData -> RTimer -> GetMutex ();
	
	if ( TimerLock )
		TimerLock -> Lock ();
	RData -> RTimer -> Stop ();
	if ( TimerLock )
		TimerLock -> Unlock ();
	
	RData -> RTimer -> Start ( 1000 / 120 );
	
}
