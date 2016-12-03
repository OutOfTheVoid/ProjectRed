#include <Red/Util/Time.h>

#include <math.h>
#include <thread>

const Red::Util::Time :: Duration Red::Util::Time::Duration :: ZERO ( 0, 0 );

Red::Util::Time::Duration :: Duration ( uint64_t Seconds, uint64_t NanoSeconds ):
	Seconds ( std::chrono :: seconds ( Seconds ) ),
	NanoSeconds ( std::chrono::nanoseconds ( NanoSeconds ) )
{
}

Red::Util::Time::Duration :: Duration ( double Seconds ):
	Seconds ( std::chrono :: seconds ( static_cast <uint64_t> ( Seconds ) ) ),
	NanoSeconds ( std::chrono :: nanoseconds ( static_cast <uint64_t> ( ( Seconds - floor ( Seconds ) ) * 1000000000.0 ) ) )
{
}

Red::Util::Time::Duration :: Duration ( const Duration & CopyFrom ):
	Seconds ( CopyFrom.Seconds ),
	NanoSeconds ( CopyFrom.NanoSeconds )
{
}

Red::Util::Time::Duration :: ~Duration ()
{
}

int64_t Red::Util::Time::Duration :: GetNanoSeconds () const
{
	
	return static_cast <int64_t> ( NanoSeconds.count () );
	
}

int64_t Red::Util::Time::Duration :: GetTotalNanoSeconds () const
{
	
	return static_cast <int64_t> ( NanoSeconds.count () ) + static_cast <int64_t> ( Seconds.count () ) * 1000000000;
	
}

int64_t Red::Util::Time::Duration :: GetSeconds () const
{
	
	return static_cast <int64_t> ( Seconds.count () );
	
}

double Red::Util::Time::Duration :: GetFPSeconds () const
{
	
	return static_cast <double> ( Seconds.count () ) + static_cast <double> ( NanoSeconds.count () ) / 1000000000.0;
	
}

void Red::Util::Time :: BlockFor ( const Duration & TimeSpan )
{
	
	std::this_thread :: sleep_for ( TimeSpan.Seconds + TimeSpan.NanoSeconds );
	
}

bool operator< ( const Red::Util::Time :: Duration & Left, const Red::Util::Time :: Duration & Right )
{
	
	if ( Left.Seconds > Right.Seconds )
		return false;
	
	if ( Left.Seconds < Right.Seconds )
		return true;
	
	return ( Left.NanoSeconds < Right.NanoSeconds );
	
}

bool operator> ( const Red::Util::Time :: Duration & Left, const Red::Util::Time :: Duration & Right )
{
	
	if ( Left.Seconds < Right.Seconds )
		return false;
	
	if ( Left.Seconds > Right.Seconds )
		return true;
	
	return ( Left.NanoSeconds > Right.NanoSeconds );
	
}

bool operator<= ( const Red::Util::Time :: Duration & Left, const Red::Util::Time :: Duration & Right )
{
	
	if ( Left.Seconds > Right.Seconds )
		return false;
	
	if ( Left.Seconds < Right.Seconds )
		return true;
	
	return ( Left.NanoSeconds <= Right.NanoSeconds );
	
}

bool operator>= ( const Red::Util::Time :: Duration & Left, const Red::Util::Time :: Duration & Right )
{
	
	if ( Left.Seconds < Right.Seconds )
		return false;
	
	if ( Left.Seconds > Right.Seconds )
		return true;
	
	return ( Left.NanoSeconds >= Right.NanoSeconds );
	
}

bool operator== ( const Red::Util::Time :: Duration & Left, const Red::Util::Time :: Duration & Right )
{
	
	return ( Left.Seconds == Right.Seconds ) && ( Left.NanoSeconds == Right.NanoSeconds );
	
}

bool operator!= ( const Red::Util::Time :: Duration & Left, const Red::Util::Time :: Duration & Right )
{
	
	return ( Left.Seconds != Right.Seconds ) || ( Left.NanoSeconds != Right.NanoSeconds );
	
}

Red::Util::Time :: Duration Red::Util::Time::Duration :: operator+ ( const Red::Util::Time :: Duration & Right )
{
	
	int64_t Nanos = NanoSeconds.count () + Right.NanoSeconds.count ();
	
	return Red::Util::Time :: Duration ( Seconds.count () + Right.Seconds.count () + ( Nanos / 1000000000 ), Nanos % 1000000000 );
	
}

Red::Util::Time :: Duration & Red::Util::Time::Duration :: operator+= ( const Red::Util::Time :: Duration & Right )
{
	
	int64_t Nanos = NanoSeconds.count () + Right.NanoSeconds.count ();
	
	Seconds += Right.Seconds + std::chrono :: seconds ( Nanos / 1000000000 );
	NanoSeconds = std::chrono :: nanoseconds ( Nanos % 1000000000 );
	
	return * this;
	
}
