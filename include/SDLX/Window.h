#ifndef SDLX_WINDOW_H
#define SDLX_WINDOW_H

#include <SDLX/SDLX.h>

#include <SDLX/SDLX.h>
#include <SDLX/RefCounted.h>
#include <SDLX/Mutex.h>

#include <string>
#include <vector>
#include <map>

namespace SDLX
{

	class Surface;
	class GLContext;
	class Renderer;
	class Mouse;

	class Window : public RefCounted
	{
	public:
		
		static const char * kDataName_WindowClassInstancePointer;
		
		static const uint32_t kStatus_Success = 0;
		static const uint32_t kStatus_SDLCreateWindowFailed = 1;
		static const uint32_t kStatus_AlreadyClosed = 2;
		static const uint32_t kStatus_AllocationError = 3;
		
		static const uint32_t kStatus_SDLEventWaitFailed = 2;
		
		static const uint32_t kCreateFlag_HighDPI = 1;
		static const uint32_t kCreateFlag_MultiThreaded = 2;
		static const uint32_t kCreateFlag_Resizable = 4;
		static const uint32_t kCreateFlag_OpenGL = 8;
		static const uint32_t kCreateFlag_Shown = 16;
		static const uint32_t kCreateFlag_AcceleratedRender = 32;
		static const uint32_t kCreateFlag_VSyncedRender = 32;
		
		static const uint32_t kFullscreenMode_Real = SDL_WINDOW_FULLSCREEN;
		static const uint32_t kFullscreenMode_Desktop = SDL_WINDOW_FULLSCREEN_DESKTOP;
		static const uint32_t kFullscreenMode_Windowed = 0;
		
		static const uint32_t kWindowEventID_Shown = SDL_WINDOWEVENT_SHOWN;
		static const uint32_t kWindowEventID_Hidden = SDL_WINDOWEVENT_HIDDEN;
		static const uint32_t kWindowEventID_Exposed = SDL_WINDOWEVENT_EXPOSED;
		static const uint32_t kWindowEventID_Moved = SDL_WINDOWEVENT_MOVED;
		static const uint32_t kWindowEventID_Resized = SDL_WINDOWEVENT_RESIZED;
		static const uint32_t kWindowEventID_SizeChanged = SDL_WINDOWEVENT_SIZE_CHANGED;
		static const uint32_t kWindowEventID_Minimized = SDL_WINDOWEVENT_MINIMIZED;
		static const uint32_t kWindowEventID_Maximized = SDL_WINDOWEVENT_MAXIMIZED;
		static const uint32_t kWindowEventID_Restored = SDL_WINDOWEVENT_RESTORED;
		static const uint32_t kWindowEventID_Enter = SDL_WINDOWEVENT_ENTER;
		static const uint32_t kWindowEventID_Leave = SDL_WINDOWEVENT_LEAVE;
		static const uint32_t kWindowEventID_FocusGained = SDL_WINDOWEVENT_FOCUS_GAINED;
		static const uint32_t kWindowEventID_FocusLost = SDL_WINDOWEVENT_FOCUS_LOST;
		static const uint32_t kWindowEventID_Closed = SDL_WINDOWEVENT_CLOSE;
#if SDL_VERSION_ATLEAST(2, 0, 5)
		static const uint32_t kWindowEventID_TakeFocus = SDL_WINDOWEVENT_TAKE_FOCUS;
		static const uint32_t kWindowEventID_HitTest = SDL_WINDOWEVENT_HIT_TEST;
#endif
		
		static Window * Create ( uint32_t * Status, const std :: string & Name, uint32_t Width, uint32_t Height, uint32_t Flags = kCreateFlag_HighDPI | kCreateFlag_Resizable | kCreateFlag_Shown | kCreateFlag_AcceleratedRender );
		
		~Window ();
		
		void AddEventHook ( uint32_t SDLWindowEventID, void ( * EventCallback ) ( SDL_WindowEvent * Event, Window * Origin, void * Data ), void * Data, int32_t Position = - 1 );
		void RemoveEventHook ( uint32_t SDLWindowEventID, void ( * EventCallback ) ( SDL_WindowEvent * Event, Window * Origin, void * Data ) );
		
		void Close ( uint32_t * Status );
		
		Surface * GetWindowSurface ();
		Renderer * GetRenderer ();
		GLContext * GetOpenGLContext ();
		
		void GLSwap ();
		
		Mutex * GetMutex ();
		
		void UpdateSurface ();
		
		void Resize ( uint32_t Width, uint32_t Height );
		void SetFullscreenMode ( uint32_t FullScreenMode );
		
		void Event ( SDL_WindowEvent * Event );
		
	private:
		
		typedef struct
		{
			
			void ( * EventCallback ) ( SDL_WindowEvent * Event, Window * Origin, void * Data );
			void * Data;
			
		} CallbackPair;
		
		friend class Surface;
		friend class GLContext;
		friend class Renderer;
		friend class Mouse;
		
		static bool EventMatch ( CallbackPair & A, CallbackPair & B );
		
		class EventMatchCompare : public std :: unary_function <CallbackPair, bool>
		{
		public:
			
			explicit EventMatchCompare ( void ( * EventCallback ) ( SDL_WindowEvent * Event, Window * Origin, void * Data ) ):
				EventCallback ( EventCallback )
			{
			};
			
			bool operator() ( const CallbackPair & MatchTest )
			{
				
				return MatchTest.EventCallback == EventCallback;
				
			};
			
		private:
			
			void ( * EventCallback ) ( SDL_WindowEvent * Event, Window * Origin, void * Data );
			
		};
		
		Window ( SDL_Window * WHandle, std :: string Name, uint32_t Flags );
		
		uint32_t Flags;
		
		SDL_Window * WHandle;
		SDL_Surface * SHandle;
		
		Surface * SurfaceInst;
		Renderer * RenderInst;
		GLContext * GLInst;
		
		Mutex * MLock;
		
		std :: string Name;
		
		bool Destroyed;
		
		std :: map <uint32_t, std :: vector <CallbackPair>> EventMap;
		
	};

}

#endif
