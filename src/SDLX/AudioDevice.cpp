#include <SDLX/AudioDevice.h>

void __SDLX_AudioDevice_AudioCallback ( void * DeviceInstance, uint8_t * Packet, int PacketLength );

uint32_t SDLX::AudioDevice :: GetDeviceCount ( bool RequireRecording )
{
	
	int Count = SDL_GetNumAudioDevices ( RequireRecording ? 1 : 0 );
	
	if ( Count > 0 )
		return Count;
	
	return 0;
	
}

const char * SDLX::AudioDevice :: GetDeviceName ( uint32_t DeviceIndex, bool RequireRecording )
{
	
	return SDL_GetAudioDeviceName ( DeviceIndex, RequireRecording ? 1 : 0 );
	
}

SDLX :: AudioDevice * SDLX::AudioDevice :: RequestAudioDevice ( const char * DeviceName, uint32_t Frequencey, BufferFormat Format, uint32_t ChannelCount, uint32_t SampleSize, bool FlexibleSource, bool RequireRecording )
{
	
	AudioDevice * NewDevice = new AudioDevice ();
	
	SDL_AudioSpec Requested;
	Requested.freq = Frequencey;
	Requested.format = Format;
	Requested.channels = ChannelCount;
	Requested.samples = SampleSize;
	Requested.userdata = reinterpret_cast <void *> ( NewDevice );
	Requested.callback = & AudioCallback;
	
	NewDevice -> Device = SDL_OpenAudioDevice ( DeviceName, RequireRecording ? 1 : 0, & Requested, & NewDevice -> Spec, FlexibleSource ? SDL_AUDIO_ALLOW_ANY_CHANGE : 0 );
	
	if ( NewDevice -> Device > 0 )
		return NewDevice;
	
	delete NewDevice;
	return NULL;
	
}

SDLX::AudioDevice :: AudioDevice ()
{
	
	
	
}

SDLX::AudioDevice :: ~AudioDevice ()
{
}

uint32_t SDLX::AudioDevice :: GetSampleFrequencey ()
{
	
	return Spec.freq;
	
}

SDLX::AudioDevice :: BufferFormat SDLX::AudioDevice :: GetFormat ()
{
	
	return Spec.format;
	
}

uint32_t SDLX::AudioDevice :: GetChannelCount ()
{
	
	return Spec.channels;
	
}

uint32_t SDLX::AudioDevice ::  GetSampleSize ()
{
	
	return Spec.samples;
	
}

inline void SDLX::AudioDevice :: CallbackInternal ( uint8_t * Packet, int PacketLength )
{
	
	(void) Packet;
	(void) PacketLength;
	
}

void SDLX::AudioDevice :: AudioCallback ( void * DeviceInstance, uint8_t * Packet, int PacketLength )
{
	
	reinterpret_cast <AudioDevice *> ( DeviceInstance ) -> CallbackInternal ( Packet, PacketLength );
	
}