#ifndef RED_AUDIO_ISTREAMSOURCE_H
#define RED_AUDIO_ISTREAMSOURCE_H

#include <Red/Audio/Audio.h>
#include <Red/Audio/AudioBuffer.h>

#include <stdint.h>

namespace Red
{
	
	namespace Audio
	{
		
		class IStreamSource
		{
		public:
			
			virtual inline ~IStreamSource () {};
			
			virtual void SetExpectedFillSize ( uint32_t FillSize ) = 0;
			
			virtual void FillAudioBuffer ( AudioBuffer * Buffer ) = 0;
			
		};
		
	}
	
}

#endif
