#include <SDLX/Mutex.h>

#include <stdexcept>

SDLX::Mutex :: Mutex ( SDL_mutex * MHandle ):
	MHandle ( MHandle )
{	
}

SDLX::Mutex * SDLX::Mutex :: Create ()
{
	
	SDL_mutex * TMHandle = SDL_CreateMutex ();
	
	if ( TMHandle == NULL )
		return NULL;
	
	return new Mutex ( TMHandle );
	
}

SDLX::Mutex :: ~Mutex ()
{
	
	SDL_DestroyMutex ( MHandle );
	
}

SDLX::Mutex :: MutexStatus SDLX::Mutex :: Lock ()
{
	
	if ( SDL_LockMutex ( MHandle ) == 0 )
		return kMutexStatus_Success;
	
	return kMutexStatus_Error;
	
}

SDLX::Mutex :: MutexStatus SDLX::Mutex :: TryLock ()
{
	
	return static_cast <MutexStatus> ( SDL_TryLockMutex ( MHandle ) );
	
}

SDLX::Mutex :: MutexStatus SDLX::Mutex :: Unlock ()
{
	
	if ( SDL_UnlockMutex ( MHandle ) == 0 )
		return kMutexStatus_Success;
	
	return kMutexStatus_Error;
	
}


