#ifndef RED_THREADING_TIME_H
#define RED_THREADING_TIME_H

#include <Red/Util/Util.h>

#include <chrono>

namespace Red
{
	
	namespace Util
	{
		
		namespace Time
		{
			
			class Duration;
			
		}
		
	}
	
}

bool operator< ( const Red::Util::Time :: Duration & Left, const Red::Util::Time :: Duration & Right );
bool operator> ( const Red::Util::Time :: Duration & Left, const Red::Util::Time :: Duration & Right );
bool operator<= ( const Red::Util::Time :: Duration & Left, const Red::Util::Time :: Duration & Right );
bool operator>= ( const Red::Util::Time :: Duration & Left, const Red::Util::Time :: Duration & Right );
bool operator== ( const Red::Util::Time :: Duration & Left, const Red::Util::Time :: Duration & Right );
bool operator!= ( const Red::Util::Time :: Duration & Left, const Red::Util::Time :: Duration & Right );

namespace Red
{
	
	namespace Util
	{
		
		namespace Time
		{
			
			class Duration
			{
			public:
				
				static const Duration ZERO;
				
				explicit Duration ( uint64_t Seconds, uint64_t NanoSeconds );
				explicit Duration ( double Seconds );
				Duration ( const Duration & CopyFrom );
				~Duration ();
				
				int64_t GetNanoSeconds () const;
				int64_t GetSeconds () const;
				
				int64_t GetTotalNanoSeconds () const;
				
				double GetFPSeconds () const;
				
				Duration operator+ ( const Duration & Right );
				Duration & operator+= ( const Duration & Right );
				
			private:
				
				inline explicit operator int64_t () {};
				
				friend void BlockFor ( const Duration & TimeSpan );
				
				friend bool :: operator< ( const Duration & Left, const Duration & Right );
				friend bool :: operator> ( const Duration & Left, const Duration & Right );
				friend bool :: operator<= ( const Duration & Left, const Duration & Right );
				friend bool :: operator>= ( const Duration & Left, const Duration & Right );
				friend bool :: operator== ( const Duration & Left, const Duration & Right );
				friend bool :: operator!= ( const Duration & Left, const Duration & Right );
				
				std::chrono :: seconds Seconds;
				std::chrono :: nanoseconds NanoSeconds;
				
			};
			
			void BlockFor ( const Duration & TimeSpan );
			
			class TimeStamp
			{
			public:
				
				TimeStamp ();
				TimeStamp ( const TimeStamp & CopyFrom );
				//TimeStamp (  );
				
				~TimeStamp ();
				
				
				
				
			};
			
		}
		
	}
	
}

#endif
