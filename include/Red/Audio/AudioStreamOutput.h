#ifndef RED_AUDIO_AUDIOSTREAMOUTPUT_H
#define RED_AUDIO_AUDIOSTREAMOUTPUT_H

#include <Red/Audio/Audio.h>
#include <Red/Audio/AudioBuffer.h>
#include <Red/Audio/IStreamSource.h>
#include <Red/Audio/IAudioOutputDevice.h>

#include <Red/Util/MethodObjectClosure.h>

#include <Red/Threading/Mutex.h>

#include <stdint.h>

namespace Red
{
	
	namespace Audio
	{
		
		class AudioStreamOutput
		{
		public:
			
			AudioStreamOutput ( IAudioOutputDevice * OutputDevice = NULL, uint32_t MaxChannelCount = 8 );
			~AudioStreamOutput ();
			
			void SetOutputDevice ( IAudioOutputDevice * OutputDevice = NULL );
			void SetStreamSource ( uint32_t Channel, IStreamSource * Source = NULL );
			
			void Start ();
			void Stop ();
			
		private:
			
			void AudioCallback ( uint8_t * Data, int DataSize );
			
			Util :: MethodObjectClosure2 <AudioStreamOutput, void, uint8_t *, int> CallbackClosure;
			
			IStreamSource ** Sources;
			uint32_t ChannelCount;
			
			IAudioOutputDevice * OutputDevice;
			
			Threading :: Mutex Lock;
			
		};
		
	}
	
}

#endif
