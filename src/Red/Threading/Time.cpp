#include <Red/Threading/Time.h>

#include <math.h>
#include <thread>

Red::Threading::Time::Duration :: Duration ( uint64_t Seconds, uint64_t NanoSeconds ):
	Seconds ( Seconds ),
	NanoSeconds ( NanoSeconds )
{
}

Red::Threading::Time::Duration :: Duration ( double Seconds ):
	Seconds ( static_cast <uint64_t> ( Seconds ) ),
	NanoSeconds ( static_cast <uint64_t> ( ( Seconds - floor ( Seconds ) ) * 1000000000.0 ) )
{
}

Red::Threading::Time::Duration :: ~Duration ()
{
}

int64_t Red::Threading::Time::Duration :: GetNanoSeconds ()
{
	
	return static_cast <int64_t> ( NanoSeconds.count () );
	
}

int64_t Red::Threading::Time::Duration :: GetSeconds ()
{
	
	return static_cast <int64_t> ( Seconds.count () );
	
}

double Red::Threading::Time::Duration :: GetFPSeconds ()
{
	
	return static_cast <double> ( Seconds.count () ) + static_cast <double> ( NanoSeconds.count () ) / 1000000000.0;
	
}

void Red::Threading::Time :: BlockFor ( const Duration & TimeSpan )
{
	
	std::this_thread :: sleep_for ( TimeSpan.Seconds + TimeSpan.NanoSeconds );
	
}
