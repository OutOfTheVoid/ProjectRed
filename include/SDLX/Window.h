#ifndef SDLX_WINDOW_H
#define SDLX_WINDOW_H

#include <SDL2/SDL.h>

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
		
		static Window * CreateWindow ( uint32_t * Status, std :: string Name, uint32_t Width, uint32_t Height, uint32_t Flags = kCreateFlag_HighDPI | kCreateFlag_Resizable | kCreateFlag_Shown | kCreateFlag_AcceleratedRender );
		
		~Window ();
		
		void AddEventHook ( uint8_t SDLWindowEventID, void ( * EventCallback ) ( SDL_WindowEvent * Event, Window * Origin, void * Data ), void * Data, int32_t Position = - 1 );
		void RemoveEventHook ( uint8_t SDLWindowEventID, void ( * EventCallback ) ( SDL_WindowEvent * Event, Window * Origin, void * Data ) );
		
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
		
		std :: map <uint8_t, std :: vector <CallbackPair>> EventMap;
		
	};

};

#endif
