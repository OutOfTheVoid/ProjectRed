#include <iostream>
#include <SDL2/SDL.h>

#include <SDLX/Lib.h>
#include <SDLX/Window.h>
#include <SDLX/GLContext.h>
#include <SDLX/Timer.h>
#include <SDLX/UserEvent.h>
#include <SDLX/Keyboard.h>
#include <SDLX/Mouse.h>

#include <Xenon/GPU/Context.h>

#include <Xenon/Math/Transform2D.h>
#include <Xenon/Math/Matrix3x3.h>

#include <RAUX/PNGFile.h>
#include <RAUX/VertexShaderFile.h>
#include <RAUX/FragmentShaderFile.h>

#include <Red/Graphics/Laminar/Renderer.h>
#include <Red/Graphics/Laminar/Raw2DTextureSource.h>

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
	
	inline RenderStruct_Struct ():
		Cont ( NULL ),
		Win ( NULL ),
		RTimer ( NULL ),
		TestSprite ( NULL ),
		Renderer ( NULL )
	{
	}
		
	
	Xenon::GPU :: Context * Cont;
	SDLX :: Window * Win;
	SDLX :: Timer * RTimer;
	
	Red::Graphics::Laminar :: Sprite * TestSprite;
	
	Red::Graphics::Laminar :: Renderer * Renderer;
	
	uint32_t Frame;
	
};

bool SetupScene ( RenderStruct & Data )
{
	
	uint32_t TestTexturePNGStatus = RAUX::PNGFile :: kStatus_Success;
	
	RAUX :: PNGFile TestTexturePNG ( "TestImage.png" );
	TestTexturePNG.Load ( & TestTexturePNGStatus );
	
	if ( ( TestTexturePNGStatus != RAUX::PNGFile :: kStatus_Success ) || ( TestTexturePNG.GetBitmapData () == NULL ) )
		return false;
	
	Xenon::GPU :: Texture2D * TestTexture = new Xenon::GPU :: Texture2D ();
	TestTexture -> TextureImage ( 0, TestTexturePNG.HasAlpha () ? Xenon::GPU::Texture2D :: kExternalFormat_RGBA : Xenon::GPU::Texture2D :: kExternalFormat_RGB, TestTexturePNG.GetWidth (), TestTexturePNG.GetHeight (), TestTexturePNG.HasAlpha () ? Xenon::GPU::Texture2D :: kExternalFormat_RGBA : Xenon::GPU::Texture2D :: kExternalFormat_RGB, Xenon::GPU::Texture2D :: kExternalLayout_UByte, TestTexturePNG.GetBitmapData () );
	
	Red::Graphics::Laminar :: Raw2DTextureSource * TestTextureSource = new Red::Graphics::Laminar :: Raw2DTextureSource ( TestTexture );
	
	Data.TestSprite = new Red::Graphics::Laminar :: Sprite ( TestTextureSource, Red::Graphics::Laminar :: RenderLayout ( Red::Graphics::Laminar :: kRenderMode_Mask, Xenon::Math::Vec2 ( 100, 100 ), Xenon::Math::Vec2 () ) );
	Data.TestSprite -> GetTransform ().SetScale ( Xenon::Math::Vec2 ( 0.5, 0.5 ) );
	
	std :: cout << "Texture Source: " << reinterpret_cast <void *> ( Data.TestSprite -> GetTextureSource () ) << std :: endl;
	std :: cout << "Texture Source: " << reinterpret_cast <void *> ( Data.TestSprite -> GetTextureSource () ) << std :: endl;
	
	Data.Renderer = new Red::Graphics::Laminar :: Renderer ( Data.Cont, WINDOW_WIDTH_0, WINDOW_HEIGHT_0 );
	
	Data.Renderer -> SetRenderTarget ( Data.Cont -> GetDefaultFrameBuffer () );
	
	Data.Renderer -> Begin ();
	
	Data.Renderer -> AddSprite ( Data.TestSprite, 0 );
	
	return true;
	
}

void DestroyScene ( RenderStruct & Data )
{
	
	if ( Data.TestSprite != NULL )
	{
		
		delete Data.TestSprite;
		Data.TestSprite = NULL;
		
	}
	
	if ( Data.Renderer != NULL )
	{
		
		Data.Renderer -> End ();
		
		delete Data.Renderer;
		Data.Renderer = NULL;
		
	}
	
}

void Render ( RenderStruct & Data )
{
	
	Data.Cont -> GetDefaultFrameBuffer () -> SetClearColor ( 0.0f, 1.0f, 1.0f );
	Data.Cont -> GetDefaultFrameBuffer () -> Clear ();
	
	Data.TestSprite -> GetTransform ().SetRotation ( static_cast <float> ( Data.Frame ) * 0.01f );
	
	Data.Renderer -> Render ();
	
	Data.Frame ++;
	
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

extern "C" int main ( int argc, const char * argv [] )
{
	
	( void ) argc;
	( void ) argv;
	
	uint32_t Status;
	
	SDLX::Lib :: Init ( & Status, SDLX::Lib :: kSDLFlag_Video );
	
	if ( Status != SDLX :: kStatus_Success )
		return - 1;
	
	SDLX::Window * Win = SDLX::Window :: Create ( & Status, "Test", WINDOW_WIDTH_0, WINDOW_HEIGHT_0, SDLX::Window :: kCreateFlag_Shown | SDLX::Window :: kCreateFlag_HighDPI | SDLX::Window :: kCreateFlag_OpenGL );
	
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
	
	Xenon::GPU :: Context * Cont = new Xenon::GPU :: Context ( GL );
	
	Cont -> Reference ();
	Cont -> MakeCurrent ();
	Cont -> GetDefaultFrameBuffer () -> SetClearColor ( 1.0f, 1.0f, 1.0f );
	Cont -> GetDefaultFrameBuffer () -> Clear ();
	
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
	DrawTimer -> Start ( 1000 / 30 );
	
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
			reinterpret_cast <KeyboardStruct *> ( Data ) -> RenderData -> Renderer -> Resize ( WINDOW_WIDTH_0, WINDOW_HEIGHT_0 );
			glViewport ( 0, 0, WINDOW_WIDTH_0, WINDOW_HEIGHT_0 );
			
		}
		else
		{
			
			reinterpret_cast <KeyboardStruct *> ( Data ) -> Resized = true;
			reinterpret_cast <KeyboardStruct *> ( Data ) -> RenderData -> Win -> Resize ( WINDOW_WIDTH_1, WINDOW_HEIGHT_1 );
			reinterpret_cast <KeyboardStruct *> ( Data ) -> RenderData -> Renderer -> Resize ( WINDOW_WIDTH_1, WINDOW_HEIGHT_1 );
			glViewport ( 0, 0, WINDOW_WIDTH_1, WINDOW_HEIGHT_1 );
			
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
	RData -> RTimer -> Start ( 1000 / 30 );
	
	if ( TimerLock )
		TimerLock -> Unlock ();
	
}
