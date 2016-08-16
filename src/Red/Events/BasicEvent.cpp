#include <Red/Events/BasicEvent.h>

const std :: string Red::Events::BasicEvent :: kEvent_Update ( "BasicEvent:Update" );
const std :: string Red::Events::BasicEvent :: kEvent_Test ( "BasicEvent:Test" );

Red::Events::BasicEvent :: BasicEvent ( const std :: string & ID ):
	ID ( ID )
{
}

Red::Events::BasicEvent :: ~BasicEvent ()
{
}

const std :: string & Red::Events::BasicEvent :: GetID () const
{
	
	return ID;
	
}
