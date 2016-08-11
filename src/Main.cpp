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
#include <Xenon/Math/RawMatrix3x3UniformSource.h>
#include <Xenon/Math/ConstantUIntUniformSource.h>

#include <Xenon/Geometry/Mesh.h>
#include <Xenon/Geometry/Primitives.h>

#include <RAUX/PNGFile.h>
#include <RAUX/VertexShaderFile.h>
#include <RAUX/FragmentShaderFile.h>

#include <math.h>

#include <string>

struct RenderStruct_Struct;

typedef struct RenderStruct_Struct RenderStruct;

void WindowCloseEvent ( SDL_WindowEvent * Event, SDLX::Window * Win, void * Data );
void DrawEventPush ( SDLX :: Timer * Source, void * Data );
void DrawEvent ( SDL_UserEvent * Event );
bool SetupScene ( RenderStruct & Data );
void DestroyScene ( RenderStruct & Data );
void Render ( RenderStruct & Data );
void MouseMoveListener ( SDL_MouseMotionEvent * Event, void * Data );

void KeyListener ( int32_t ScanCode, int32_t KeyCode, bool Down, void * Data );

#define WINDOW_WIDTH_0 800
#define WINDOW_HEIGHT_0 600

#define WINDOW_WIDTH_1 2000
#define WINDOW_HEIGHT_1 1400

struct RenderStruct_Struct
{
	
	Xenon::GPU :: Context * Cont; 
	SDLX :: Window * Win;
	SDLX :: Timer * RTimer;
	
	Xenon::Geometry :: Mesh * QuadMesh;
	Xenon::GPU :: ShaderProgram * QuadProgram;
	Xenon::GPU :: VertexArray * QuadVAO;
	Xenon::Math :: RawMatrix3x3UniformSource * QuadTransformSource;
	Xenon::Math :: ConstantUIntUniformSource * QuadTextureSamplerSource;
	Xenon::Math :: Matrix3x3 QuadTransform;
	Xenon::GPU :: UniformSet * QuadUniforms;
	Xenon::GPU :: Texture2D * QuadTexture;
	
	int32_t X;
	int32_t Y;
	
	uint32_t Frame;
	
};

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
	
	SDLX::Lib :: Init ( & Status, SDLX::Lib :: kSDLFlag_Video );
	
	if ( Status != SDLX :: kStatus_Success )
		return - 1;
	
	SDLX::Window * Win = SDLX::Window :: CreateWindow ( & Status, "Test", WINDOW_WIDTH_0, WINDOW_HEIGHT_0, SDLX::Window :: kCreateFlag_Shown | SDLX::Window :: kCreateFlag_HighDPI | SDLX::Window :: kCreateFlag_OpenGL );
	
	SDLX::GLContext :: RequestGLContextVersion ( SDLX::GLContext :: kGLProfile_Core, 3, 3 );
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
		
		return - 1;
		
	}
	
	SDLX::Mouse :: Lock ();
	
	Xenon::GPU :: Context * Cont = new Xenon::GPU :: Context ( GL );
	
	Cont -> Reference ();
	Cont -> MakeCurrent ();
	Cont -> GetDefaultFrameBuffer () -> SetClearColor ( 0.0f, 0.0f, 0.0f );
	
	RenderStruct RData;
	
	RData.Cont = Cont;
	RData.Win = Win;
	
	if ( ! SetupScene ( RData ) )
	{
		
		DestroyScene ( RData );
		
		Cont -> Dereference ();
		Win -> Disown ();
		
		SDLX::Lib :: DeInit ();
		
		return - 1;
		
	}
	
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
	
	DestroyScene ( RData );
	
	Cont -> Dereference ();
	Win -> Disown ();
	
	SDLX::Lib :: DeInit ();
	
	return 0;
	
}

void MouseMoveListener ( SDL_MouseMotionEvent * Event, void * Data )
{
	
	(void) Event;
	(void) Data;
	
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
			
		}
		else
		{
			
			reinterpret_cast <KeyboardStruct *> ( Data ) -> Resized = true;
			reinterpret_cast <KeyboardStruct *> ( Data ) -> RenderData -> Win -> Resize ( WINDOW_WIDTH_1, WINDOW_HEIGHT_1 );
			
		}
		
	}
	
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
	
	RData -> Cont -> GetDefaultFrameBuffer () -> Bind ();
	
	Render ( * RData );
	
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


bool SetupScene ( RenderStruct & Data )
{
	
	uint32_t Status;
	
	Xenon::Geometry::Primitives :: Quad2DSpec QuadSpec;
	Xenon::Geometry::Primitives :: Quad2DTexturePositionSpec TextureSpec;
	
	QuadSpec.WindOutwardFacesClockwise = true;
	QuadSpec.Attributes = Xenon::Geometry::Primitives :: kAttributeFlags_Position | Xenon::Geometry::Primitives :: kAttributeFlags_TexturePositions;
	QuadSpec.CompositionMode = Xenon::Geometry::Primitives :: kStaticAttributeCompositionMode_Interleaved;
	Xenon::Geometry::Primitives :: SetupNormalQuad2DPositionSpec ( QuadSpec.PositionSpec, "Position", true );
	Xenon::Geometry::Primitives :: SetupNormalQuad2DTexturePositionSpec ( TextureSpec, "TexturePosition", true );
	QuadSpec.TexturePositionCount = 1;
	QuadSpec.TexturePositionSpecs = & TextureSpec;
	
	Data.QuadMesh = NULL;
	if ( ! Xenon::Geometry::Primitives :: GenerateQuad2DMesh ( & Data.QuadMesh, QuadSpec ) )
	{
		
		std :: cout << "failed to generate quad mesh!" << std :: endl;
		return false;
		
	}
	
	Data.QuadMesh -> Reference ();
	
	RAUX :: VertexShaderFile VSFile ( "Quad2DVertex.glsl", "Quad2D_Vertex" );
	Xenon::GPU :: VertexShader * VShader = VSFile.LoadToShader ( & Status );
	
	if ( Status != RAUX::VertexShaderFile :: kStatus_Success )
	{
		
		std :: cout << "Vertex shader load failed: " << Status << std :: endl;
		
		Data.QuadMesh -> Dereference ();
		Data.QuadMesh = NULL;
		
		return false;
		
	}
	
	RAUX :: FragmentShaderFile FSFile ( "Quad2DFragment.glsl", "Quad2D_Fragment" );
	Xenon::GPU :: FragmentShader * FShader = FSFile.LoadToShader ( & Status );
	
	if ( Status != RAUX::FragmentShaderFile :: kStatus_Success )
	{
		
		VShader -> Dereference ();
		VShader = NULL;
		
		Data.QuadMesh -> Dereference ();
		Data.QuadMesh = NULL;
		
		return false;
		
	}
	
	if ( ! VShader -> Compile ( true ) )
	{
		
		std :: cout << VSFile.GetName () << ": " << VShader -> GetCompilationLog () << std :: endl;
		
		Data.QuadMesh -> Dereference ();
		Data.QuadMesh = NULL;
		
		return false;
		
	}
	
	if ( ! FShader -> Compile ( true ) )
	{
		
		std :: cout << "" << FSFile.GetName () << ": " << FShader -> GetCompilationLog () << std :: endl;
		
		Data.QuadMesh -> Dereference ();
		Data.QuadMesh = NULL;
		
		return false;
		
	}
	
	Data.QuadProgram = new Xenon::GPU :: ShaderProgram ( "Quad2D_Program" );
	Data.QuadProgram -> AddShader ( * VShader );
	Data.QuadProgram -> AddShader ( * FShader );
	Data.QuadProgram -> Reference ();
	Data.QuadProgram -> Link ();
	Data.QuadProgram -> Reference ();
	
	RAUX :: PNGFile TextureFile ( "RockTexture.png" );
	TextureFile.Load ( & Status );
	
	if ( ! TextureFile.Valid () )
	{
		
		Data.QuadProgram -> Dereference ();
		Data.QuadProgram = NULL;
		
		Data.QuadMesh -> Dereference ();
		Data.QuadMesh = NULL;
		
		return false;
		
	}
	
	Data.QuadTexture = new Xenon::GPU::Texture2D ();
	Data.QuadTexture -> TextureImage ( 0, Xenon::GPU::Texture2D :: kInternalFormat_RGBA, TextureFile.GetWidth (), TextureFile.GetHeight (), Xenon::GPU::Texture2D :: kExternalLayout_UByte, Xenon::GPU::Texture2D :: kExternalFormat_RGB, TextureFile.GetBitmapData (), 3 );
	Data.QuadTexture -> SetWrapMode ( Xenon::GPU::Texture2D :: kWrapMode_Repeat );
	Data.QuadTexture -> SetFiltering ( Xenon::GPU::Texture2D :: kMinimizingFilter_Linear, Xenon::GPU::Texture2D :: kMagnificationFilter_Linear );
	Data.QuadTexture -> GenerateMipMaps ();
	Data.QuadTexture -> AssignToTextureUnit ( 0 );
	Data.QuadTexture -> Reference ();
	
	Xenon::Math::Matrix3x3 :: Identity ( Data.QuadTransform );
	
	Data.QuadTransformSource = new Xenon::Math :: RawMatrix3x3UniformSource ( & Data.QuadTransform, true );
	Data.QuadTransformSource -> Reference ();
	
	Data.QuadTextureSamplerSource = new Xenon::Math :: ConstantUIntUniformSource ( 0 );
	Data.QuadTextureSamplerSource -> Reference ();
	
	Data.QuadUniforms = new Xenon::GPU :: UniformSet ( Data.QuadProgram );
	Data.QuadUniforms -> AddMatrix3x3Uniform ( "Transform", Data.QuadTransformSource );
	Data.QuadUniforms -> AddUIntUniform ( "TextureID", Data.QuadTextureSamplerSource );
	Data.QuadUniforms -> SetProgram ( Data.QuadProgram );
	Data.QuadUniforms -> Link ();
	Data.QuadUniforms -> Reference ();
	
	Data.QuadVAO = new Xenon::GPU :: VertexArray ();
	Data.QuadVAO -> SetProgram ( Data.QuadProgram );
	Data.QuadMesh -> BuildVertexArray ( * Data.QuadVAO );
	Data.QuadVAO -> Build ();
	Data.QuadVAO -> Reference ();
	
	return true;
	
}

void DestroyScene ( RenderStruct & Data )
{
	
	if ( Data.QuadMesh != NULL )
		Data.QuadMesh -> Dereference ();
	Data.QuadMesh = NULL;
	
	if ( Data.QuadProgram != NULL )
		Data.QuadProgram -> Dereference ();
	Data.QuadProgram = NULL;
	
	if ( Data.QuadTransformSource != NULL )
		Data.QuadTransformSource -> Dereference ();
	Data.QuadTransformSource = NULL;
	
	if ( Data.QuadUniforms != NULL )
		Data.QuadUniforms -> Dereference ();
	Data.QuadUniforms = NULL;
	
	if ( Data.QuadVAO != NULL )
		Data.QuadVAO -> Dereference ();
	Data.QuadVAO = NULL;
	
}

void Render ( RenderStruct & Data )
{
	
	Data.Cont -> GetDefaultFrameBuffer () -> Clear ();
	
	Data.QuadTexture -> Bind ();
	Data.QuadVAO -> Bind ();
	Data.QuadUniforms -> UpdateUniforms ();
	
	glDrawElements ( Data.QuadMesh -> GetDrawMode (), Data.QuadMesh -> GetIndexCount (), Data.QuadMesh -> GetIndexType (), NULL );
	
}
