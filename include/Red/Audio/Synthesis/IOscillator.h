#ifndef RED_AUDIO_IOSCILLATOR_H
#define RED_AUDIO_IOSCILLATOR_H

#include <Red/Audio/AudioBuffer.h>
#include <Red/Audio/Synthesis/Synthesis.h>

namespace Red
{
	
	namespace Audio
	{
		
		namespace Synthesis
		{
			
			class IOscillator
			{
			public:
				
				virtual ~IOscillator () {};
				
				virtual void FillBuffer ( AudioBuffer & Buffer, uint32_t Channel, double SamplePeriod, double SamplePhase ) = 0;
				
			};
			
		}
		
	}
	
}

#endif
