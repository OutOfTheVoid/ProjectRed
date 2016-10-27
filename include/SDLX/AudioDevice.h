#ifndef SDLX_AUDIODEVICE_H
#define SDLX_AUDIODEVICE_H

#include <SDLX/SDLX.h>

#include <stdint.h>

#include <SDL2/SDL.h>

#include <Red/Util/Function.h>
#include <Red/Util/RefCounted.h>

#include <Red/Audio/Audio.h>
#include <Red/Audio/IAudioOutputDevice.h>

namespace SDLX
{
	
	class AudioDevice : public Red::Util :: RefCounted, public virtual Red::Audio :: IAudioOutputDevice
	{
	public:
		
		static const uint32_t kStandardFrequencey_11K = 11025;
		static const uint32_t kStandardFrequencey_22K = 22050;
		static const uint32_t kStandardFrequencey_44K = 44100;
		static const uint32_t kStandardFrequencey_48K = 48000;
		static const uint32_t kStandardFrequencey_96K = 96000;
		
		typedef SDL_AudioFormat BufferFormat;
		
		static const BufferFormat kBufferFormat_U8 = AUDIO_U8;
		static const BufferFormat kBufferFormat_I8 = AUDIO_S8;
		
		static const BufferFormat kBufferFormat_U16_LE = AUDIO_U16LSB;
		static const BufferFormat kBufferFormat_U16_BE = AUDIO_U16MSB;
		static const BufferFormat kBufferFormat_U16_SE = AUDIO_U16SYS;
		static const BufferFormat kBufferFormat_I16_LE = AUDIO_S16LSB;
		static const BufferFormat kBufferFormat_I16_BE = AUDIO_S16MSB;
		static const BufferFormat kBufferFormat_I16_SE = AUDIO_S16SYS;
		
		static const BufferFormat kBufferFormat_I32_LE = AUDIO_S32LSB;
		static const BufferFormat kBufferFormat_I32_BE = AUDIO_S32MSB;
		static const BufferFormat kBufferFormat_I32_SE = AUDIO_S32SYS;
		static const BufferFormat kBufferFormat_F32_LE = AUDIO_F32LSB;
		static const BufferFormat kBufferFormat_F32_BE = AUDIO_F32MSB;
		static const BufferFormat kBufferFormat_F32_SE = AUDIO_F32SYS;
		
		static uint32_t GetDeviceCount ( bool RequireRecording );
		static const char * GetDeviceName ( uint32_t DeviceIndex, bool RequireRecording );
		
		static AudioDevice * RequestAudioDevice ( const char * DeviceName, uint32_t Frequencey, BufferFormat Format, uint32_t ChannelCount, uint32_t SampleSize, bool FlexibleSource, bool RequireRecording );
		
		uint32_t GetSampleFrequencey ();
		uint32_t GetSampleSize ();
		
		uint32_t GetChannelCount ();
		
		BufferFormat GetFormat ();
		Red::Audio :: AudioBufferType GetSampleFormat ();
		
		~AudioDevice ();
		
		void Lock ();
		void Unlock ();
		
		void Start ();
		void Stop ();
		
		void SetFillCallback ( Red::Util :: IFunction2 <void, uint8_t *, int> * FillFunction );
		
		const Red::Util::Time :: Duration GetFillDuration ();
		
	private:
		
		AudioDevice ();
		
		inline void CallbackInternal ( uint8_t * Packet, int PacketLength );
		
		static void AudioCallback ( void * DeviceInstance, uint8_t * Packet, int PacketLength );
		
		Red::Util :: IFunction2 <void, uint8_t *, int> * FillFunction;
		
		SDL_AudioDeviceID Device;
		SDL_AudioSpec Spec;
		
	};
	
}

#endif
