#include <SDLX/Timer.h>

SDLX::Timer :: Timer ( void ( * Callback ) ( Timer * Source, void * Data ), void * Data ):
	Callback ( Callback ),
	Data ( Data ),
	Valid ( false ),
	MLock ( Mutex :: Create () )
{
}

SDLX::Timer :: ~Timer ()
{
	
	if ( Valid )
		SDL_RemoveTimer ( ID );
	
}

void SDLX::Timer :: Start ( uint32_t Delay )
{
	
	Stop ();
	
	ID = SDL_AddTimer ( Delay, & TimerCallback, reinterpret_cast <void *> ( this ) );
	Valid = true;
	
}

void SDLX::Timer :: Stop ()
{
	
	if ( Valid )
	{
		
		SDL_RemoveTimer ( ID );
		
		Valid = false;
		
	}
	
}

SDLX::Mutex * SDLX::Timer :: GetMutex ()
{
	
	return MLock;
	
}

uint32_t SDLX::Timer :: TimerCallback ( uint32_t Interval, void * Parameter )
{
	
	return reinterpret_cast <Timer *> ( Parameter ) -> CallbackInternal ( Interval );
	
}

uint32_t SDLX::Timer :: CallbackInternal ( uint32_t Interval )
{
	
	Callback ( this, Data );
	
	return Interval;
	
}

void SDLX::Timer :: SetCallback ( void ( * Callback ) ( Timer * Source, void * Data ) )
{
	
	this -> Callback = Callback;
	
}

void SDLX::Timer :: SetData ( void * Data )
{
	
	this -> Data = Data;
	
}

