#include <Red/Util/UID.h>

std :: atomic <uint64_t> Red::Util::UID :: CurrentTop ( 0 );

Red::Util::UID :: UID_t Red::Util::UID :: Generate ()
{
	
	return CurrentTop ++;
	
}
