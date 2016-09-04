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
#include <Xenon/Math/ConstantIntUniformSource.h>

#include <Xenon/Geometry/Mesh.h>
#include <Xenon/Geometry/Primitives.h>

#include <RAUX/PNGFile.h>
#include <RAUX/VertexShaderFile.h>
#include <RAUX/FragmentShaderFile.h>

#include <Red/Util/Function.h>
#include <Red/Util/MethodObjectParameterClosure.h>

#include <Red/Events/IEventDispatcher.h>
#include <Red/Events/EventDispatcher.h>
#include <Red/Events/IEvent.h>
#include <Red/Events/BasicEvent.h>

#include <Red/Threading/Thread.h>
#include <Red/Threading/ThreadEvent.h>

#include <Red/Text/Rendering/FreeType/FTLibrary.h>
#include <Red/Text/Rendering/FreeType/FontFace.h>

#include <thread>
#include <chrono>

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

/*
* NOTE: This file is simply a test case for the engine. I've left it in the repository so people can see what I'm working on at the moment.
*/

struct RenderStruct_Struct
{
	
	Xenon::GPU :: Context * Cont;
	SDLX :: Window * Win;
	SDLX :: Timer * RTimer;
	
	Xenon::GPU :: Texture2D * FontTexture;
	Xenon::GPU :: ShaderProgram * Program;
	Xenon::GPU :: VertexArray * VArray;
	Xenon::GPU :: UniformSet * UniSet;
	
	Xenon::Geometry :: Mesh * TestMesh;
	
	uint32_t Frame;
	
};

bool SetupScene ( RenderStruct & Data )
{
	
	uint32_t Status;
	
	Data.FontTexture = new Xenon::GPU :: Texture2D ();
	Data.FontTexture -> Reference ();
	
	RAUX :: PNGFile MyTestTextureFile ( "RockTexture.png" );
	MyTestTextureFile.Load ( & Status );
	
	if ( ! MyTestTextureFile.Valid () )
		std :: cout << "PNG load failed!" << std :: endl;
	
	Data.FontTexture -> AssignToTextureUnit ( 0 );
	
	Red::Text::Rendering::FreeType :: FontFace * TestFontFace = Red::Text::Rendering::FreeType::FontFace :: NewFromFile ( "PTMono.ttf", 0 );
	
	if ( TestFontFace != NULL )
	{
		
		std :: cout << "Loaded font!" << std :: endl;
		
		TestFontFace -> SetPixelSize ( 2048 );
		
		uint32_t GlyphIndex = TestFontFace -> GlyphIndexFromChar ( U'Q' );
		std :: cout << "Glyph index for \'" << 'Q' << "\': " << GlyphIndex << std :: endl;
		
		if ( TestFontFace -> LoadGlyph ( GlyphIndex, Red::Text::Rendering::FreeType::FontFace :: kLoadFlag_Defaults ) )
			std :: cout << "Glyph loaded!" << std :: endl;
		
		TestFontFace -> RenderGlyph ();
		
		Red::Text::Rendering::FreeType::FontFace :: BitmapMetrics BMMetrics;
		TestFontFace -> GetBitmapMetrics ( & BMMetrics );
		
		Data.FontTexture -> TextureImage ( 0, Xenon::GPU::Texture2D :: kInternalFormat_RGBA, BMMetrics.Width, BMMetrics.Rows, Xenon::GPU::Texture2D :: kExternalLayout_UByte, Xenon::GPU::Texture2D :: kExternalFormat_R, TestFontFace -> GetBitmapPointer (), 1, BMMetrics.Pitch );
		Data.FontTexture -> SetFiltering ( Xenon::GPU::Texture2D :: kMinimizingFilter_Nearest, Xenon::GPU::Texture2D :: kMagnificationFilter_Nearest );
		Data.FontTexture -> SetWrapMode ( Xenon::GPU::Texture2D :: kWrapMode_Repeat );
		
		delete TestFontFace;
		
	}
	
	Xenon::Geometry::Primitives :: Quad2DSpec RenderQuadSpec;
	RenderQuadSpec.WindOutwardFacesClockwise = true;
	RenderQuadSpec.Attributes = Xenon::Geometry::Primitives :: kAttributeFlags_Position | Xenon::Geometry::Primitives :: kAttributeFlags_TexturePositions;
	RenderQuadSpec.CompositionMode = Xenon::Geometry::Primitives :: kStaticAttributeCompositionMode_Interleaved;
	RenderQuadSpec.TexturePositionCount = 0;
	Xenon::Geometry::Primitives :: SetupNormalQuad2DPositionSpec ( RenderQuadSpec.PositionSpec, "Position", true );
	
	Xenon::Geometry::Primitives :: Quad2DTexturePositionSpec TexPos;
	Xenon::Geometry::Primitives :: SetupNormalQuad2DTexturePositionSpec ( TexPos, "TexPosition", true );
	
	RenderQuadSpec.TexturePositionSpecs = & TexPos;
	RenderQuadSpec.TexturePositionCount = 1;
	
	Data.TestMesh = NULL;
	if ( ! Xenon::Geometry::Primitives :: GenerateQuad2DMesh ( & Data.TestMesh, RenderQuadSpec ) )
		std :: cout << "Failed to generate quad mesh!" << std :: endl;
	
	RAUX :: VertexShaderFile VShaderFile ( "Text2DVertex.glsl" );
	RAUX :: FragmentShaderFile FShaderFile ( "Text2DFragment.glsl" );
	
	Xenon::GPU :: VertexShader * VShader = VShaderFile.LoadToShader ( & Status );
	Xenon::GPU :: FragmentShader * FShader = FShaderFile.LoadToShader ( & Status );
	
	if ( ! VShader -> Compile ( true ) )
		std :: cout << "VShader failed to compile: " << std :: endl << VShader -> GetCompilationLog () << std :: endl;
		 
	if ( ! FShader -> Compile ( true ) )
		std :: cout << "FShader failed to compile: " << std :: endl << FShader -> GetCompilationLog () << std :: endl;
	
	Data.Program = new Xenon::GPU :: ShaderProgram ();
	
	Data.Program -> GPUResourceAlloc ();
	Data.Program -> AddShader ( * VShader );
	Data.Program -> AddShader ( * FShader );
	Data.Program -> Link ();
	
	Data.UniSet = new Xenon::GPU :: UniformSet ();
	
	Xenon::Math :: ConstantIntUniformSource * FontSamplerUniformSource = new Xenon::Math :: ConstantIntUniformSource ( 0 );
	Data.UniSet -> AddIntUniform ( "FontSampler", FontSamplerUniformSource );
	Data.UniSet -> SetProgram ( Data.Program );
	Data.UniSet -> Link ();
	
	delete VShader;
	delete FShader;
	
	Data.TestMesh -> FlushData ();
	Data.VArray = new Xenon::GPU :: VertexArray ();
	Data.TestMesh -> BuildVertexArray ( * Data.VArray );
	Data.VArray -> SetProgram ( Data.Program );
	Data.VArray -> Build ();
	Data.VArray -> Bind ();
	
	return true;
	
}

void DestroyScene ( RenderStruct & Data )
{
	
	Data.FontTexture -> Dereference ();
	
}

void Render ( RenderStruct & Data )
{
	
	Data.Cont -> GetDefaultFrameBuffer () -> Clear ();
	Data.Cont -> SetCullingEnabled ( false );
	Data.Cont -> SetDepthTestEnabled ( false );
	Data.Cont -> SetFrontFace ( Xenon::GPU::Context :: kFrontFace_Clockwise );
	Data.Cont -> SetCullingFace ( Xenon::GPU::Context :: kCullingFace_Back );
	
	Data.Program -> Bind ();
	
	Data.VArray -> Bind ();
	
	Data.UniSet -> UpdateUniforms ();
	
	glDrawElements ( Data.TestMesh -> GetDrawMode (), Data.TestMesh -> GetIndexCount (), Data.TestMesh -> GetIndexType (), 0 );
	
}

//===================================================//

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
	Cont -> GetDefaultFrameBuffer () -> SetClearColor ( 1.0f, 1.0f, 1.0f );
	
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
	
	RData -> Cont -> MakeCurrent ();
	
	Render ( * RData );
	
	RData -> Win -> GLSwap ();
	
	RData -> Frame ++;
	
	SDLX::Mutex * TimerLock = RData -> RTimer -> GetMutex ();
	
	if ( TimerLock )
		TimerLock -> Lock ();
	RData -> RTimer -> Stop ();
	RData -> RTimer -> Start ( 1000 / 120 );
	if ( TimerLock )
		TimerLock -> Unlock ();
	
}
