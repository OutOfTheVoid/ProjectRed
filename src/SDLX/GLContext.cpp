#include <SDLX/GLContext.h>
#include <SDLX/Window.h>

SDLX::GLContext :: GLContext ( SDL_GLContext GLHandle, Window * ContextWindow ):
	GLHandle ( GLHandle ),
	ContextWindow ( ContextWindow )
{
}

SDLX::GLContext :: ~GLContext ()
{
	
	SDL_GL_DeleteContext ( GLHandle );
	
}

int32_t SDLX::GLContext :: MakeCurrent ()
{
	
	return SDL_GL_MakeCurrent ( ContextWindow -> WHandle, GLHandle );
	
}

void SDLX::GLContext :: SetWindow ( Window * ContextWindow )
{
	
	this -> ContextWindow = ContextWindow;
	
}

void SDLX::GLContext :: RequestGLContextVersion ( GLProfile Profile, uint32_t VMajor, uint32_t VMinor )
{
	
	SDL_GL_SetAttribute ( SDL_GL_CONTEXT_MAJOR_VERSION, VMajor );
	SDL_GL_SetAttribute ( SDL_GL_CONTEXT_MINOR_VERSION, VMinor );
	
	switch ( Profile )
	{
		
	case kGLProfile_Core:
	
		SDL_GL_SetAttribute ( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );
		
		break;
		
	case kGLProfile_Compatibility:
	
		SDL_GL_SetAttribute ( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY );
		
		break;
		
	case kGLProfile_ES:
	
		SDL_GL_SetAttribute ( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES );
		
		break;
		
	default:
		return;
		
	};
	
}

void SDLX::GLContext :: RequestDoubleBuffering ( bool DoubleBuffer )
{
	
	SDL_GL_SetAttribute ( SDL_GL_DOUBLEBUFFER, DoubleBuffer ? 1 : 0 );
	
}

void SDLX::GLContext :: RequestDepthBufferSize ( uint32_t BufferSize )
{
	
	SDL_GL_SetAttribute ( SDL_GL_DEPTH_SIZE, BufferSize );
	
}

void SDLX::GLContext :: RequestStencilBufferSize ( uint32_t BufferSize )
{
	
	SDL_GL_SetAttribute ( SDL_GL_STENCIL_SIZE, BufferSize );
	
}

SDLX::GLContext :: VSyncMode SDLX::GLContext :: RequestVSyncMode ( VSyncMode RequestedMode )
{
	
	int32_t Status = SDL_GL_SetSwapInterval ( RequestedMode );
	
	if ( Status == 0 )
		return RequestedMode;
	
	if ( RequestedMode == kVSyncMode_Synced_LateSwapTearing )
	{
		
		Status = SDL_GL_SetSwapInterval ( kVSyncMode_Synced );
		
		if ( Status == 0 )
			return kVSyncMode_Synced;
		
		return kVSyncMode_Unsynced;
		
	}
	
	if ( RequestedMode == kVSyncMode_Synced )
		return kVSyncMode_Unsynced;
	
	return kVSyncMode_Synced;
	
}

bool SDLX::GLContext :: RequestMSAA ( bool Enabled, uint32_t Level )
{
	
	if ( Enabled )
	{
		
		if ( ! SDL_GL_SetAttribute ( SDL_GL_MULTISAMPLEBUFFERS, 1 ) )
			return false;
		
		return SDL_GL_SetAttribute ( SDL_GL_MULTISAMPLESAMPLES, Level );
		
	}
	else
		return SDL_GL_SetAttribute ( SDL_GL_MULTISAMPLEBUFFERS, 0 );
	
}
