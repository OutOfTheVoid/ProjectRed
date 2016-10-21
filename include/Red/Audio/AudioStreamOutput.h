#ifndef RED_AUDIO_AUDIOSTREAMOUTPUT_H
#define RED_AUDIO_AUDIOSTREAMOUTPUT_H

#include <Red/Audio/Audio.h>
#include <Red/Audio/AudioBuffer.h>
#include <Red/Audio/IStreamSource.h>

namespace Red
{
	
	namespace Audio
	{
		
		class AudioStreamOutput
		{
		public:
			
			AudioStreamOutput ( AudioBufferType IntermediaryBufferType =  );
			~AudioStreamOutput ();
			
		}
		
	}
	
}

#endif
