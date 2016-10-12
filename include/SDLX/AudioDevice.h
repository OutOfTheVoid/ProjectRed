#ifndef SDLX_AUDIODEVICE_H
#define SDLX_AUDIODEVICE_H

#include <SDLX/SDLX.h>

#include <stdint.h>

#include <SDL2/SDL.h>

namespace SDLX
{
	
	class AudioDevice
	{
	public:
		
		typedef SDL_AudioFormat BufferFormat;
		
		static uint32_t GetDeviceCount ( bool RequireRecording );
		static const char * GetDeviceName ( uint32_t DeviceIndex, bool RequireRecording );
		
		static AudioDevice * RequestAudioDevice ( const char * DeviceName, uint32_t Frequencey, BufferFormat Format, uint32_t ChannelCount, uint32_t SampleSize, bool FlexibleSource, bool RequireRecording );
		
		uint32_t GetSampleFrequencey ();
		BufferFormat GetFormat ();
		uint32_t GetChannelCount ();
		uint32_t GetSampleSize ();
		
		~AudioDevice ();
		
	private:
		
		AudioDevice ();
		
		inline void CallbackInternal ( uint8_t * Packet, int PacketLength );
		
		static void AudioCallback ( void * DeviceInstance, uint8_t * Packet, int PacketLength );
		
		SDL_AudioSpec Spec;
		SDL_AudioDeviceID Device;
		
	};
	
}

#endif
