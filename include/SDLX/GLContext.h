#ifndef SDLX_GLCONTEXT_H
#define SDLX_GLCONTEXT_H

#include <SDLX/SDLX.h>
#include <SDL2/SDL.h>

#ifdef SDLX_XENON_GL_INTERFACE
	#include <Xenon/GPU/IGLContext.h>
#endif

// GLContext: Represents an SDL OpenGL context managed by the Xenon library.

namespace SDLX
{
	
	class Window;

#ifdef SDLX_XENON_GL_INTERFACE
	class GLContext : public Xenon::GPU :: IGLContext
#else
	class GLContext
#endif
	{
	public:
		
		typedef uint32_t GLProfile;
		
		static const GLProfile kGLProfile_Core = 0;
		static const GLProfile kGLProfile_Compatibility = 1;
		static const GLProfile kGLProfile_ES = 2;
		
		typedef int32_t VSyncMode;
		
		static const VSyncMode kVSyncMode_Synced_LateSwapTearing = - 1;
		static const VSyncMode kVSyncMode_Synced = 1;
		static const VSyncMode kVSyncMode_Unsynced = 0;
		
		static void RequestGLContextVersion ( GLProfile Profile, uint32_t VMajor, uint32_t VMinor );
		
		static void RequestDoubleBuffering ( bool DoubleBuffer );
		
		static void RequestDepthBufferSize ( uint32_t BufferSize );
		static void RequestStencilBufferSize ( uint32_t BufferSize );
		
		static VSyncMode RequestVSyncMode ( VSyncMode RequestedMode );
		
		static bool RequestMSAA ( bool Enabled, uint32_t Level = 4 );
		
		int32_t MakeCurrent ();
		void SetWindow ( Window * ContextWindow );
		
	private:
		
		friend class Window;
		
		GLContext ( SDL_GLContext GLHandle, Window * ContextWindow );
		~GLContext ();
		
		SDL_GLContext GLHandle;
		Window * ContextWindow;
		
	};

}

#endif
