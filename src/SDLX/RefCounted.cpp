#include <SDLX/RefCounted.h>

SDLX::RefCounted :: RefCounted ():
	RefCount ( 0 )
{
}

SDLX::RefCounted :: RefCounted ( uint32_t InitialCount ):
	RefCount ( InitialCount )
{
}

SDLX::RefCounted :: ~RefCounted ()
{
}
	
void SDLX::RefCounted :: Own ()
{
	
	RefCount ++;
	
}

void SDLX::RefCounted :: Disown ()
{
	
	RefCount --;
	
	if ( RefCount == 0 )
		Delete ();
	
}

void SDLX::RefCounted :: Delete ()
{
	
	delete this;
	
}
