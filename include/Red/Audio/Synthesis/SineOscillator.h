#ifndef RED_AUDIO_SYNTHESIS_H
#define RED_AUDIO_SYNTHESIS_H

#include <Red/Audio/Synthesis/Synthesis.h>
#include <Red/Audio/Synthesis/IOscillator.h>
#include <Red/Audio/AudioBuffer.h>

#include <math.h>

namespace Red
{
	
	namespace Audio
	{
		
		namespace Synthesis
		{
			
			class SineOscillator
			{
			public:
				
				SineOscillator ();
				~SineOscillator ();
				
				void FillBuffer ( AudioBuffer & Buffer, uint32_t Channel, double SamplePeriod, double SamplePhase );
				
			}
			
		}
		
	}
	
}

#endif
