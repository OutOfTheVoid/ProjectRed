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
			
			AudioStreamOutput ( IAudioOutputDevice * OutputDevice = NULL, uint32_t MaxChannelCount = 8, AudioBufferType IntermediaryBufferType = kAudioBufferType_PerferredQuality );
			~AudioStreamOutput ();
			
			void SetOutputDevice ( IAudioOutputDevice * OutputDevice = NULL );
			void SetStreamSource ( uint32_t Channel, IStreamSource * Source = NULL );
			
			void Start ();
			void Stop ();
			
		private:
			
			void AudioCallback ( uint8_t * Data, int DataSize );
			
			IStreamSource ** Sources;
			uint32_t ChannelCount;
			
		};
		
	}
	
}

#endif
