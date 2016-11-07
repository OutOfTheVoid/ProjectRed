#include <SDLX/AudioDevice.h>

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

SDLX :: AudioDevice * SDLX::AudioDevice :: RequestAudioDevice ( const char * DeviceName, uint32_t Frequency, BufferFormat Format, uint32_t ChannelCount, uint32_t SampleSize, bool FlexibleSource, bool RequireRecording )
{
	
	AudioDevice * NewDevice = new AudioDevice ();
	
	SDL_AudioSpec Requested;
	Requested.freq = Frequency;
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

SDLX::AudioDevice :: AudioDevice ():
	RefCounted (),
	FillFunction ( NULL ),
	Device ( 0 ),
	Spec ()
{
}

SDLX::AudioDevice :: ~AudioDevice ()
{
	
	Stop ();
	SDL_CloseAudioDevice ( Device );
	
	Device = 0;
	
}

uint32_t SDLX::AudioDevice :: GetSampleFrequency ()
{
	
	return Spec.freq;
	
}

SDLX::AudioDevice :: BufferFormat SDLX::AudioDevice :: GetFormat ()
{
	
	return Spec.format;
	
}

Red::Audio :: AudioBufferType SDLX::AudioDevice :: GetSampleFormat ()
{
	
	switch ( Spec.format )
	{
		
		case kBufferFormat_U8:
			return Red::Audio :: kAudioBufferType_UInt8;
			
		case kBufferFormat_I8:
			return Red::Audio :: kAudioBufferType_UInt8;
		
		case kBufferFormat_U16_LE:
			return Red::Audio :: kAudioBufferType_UInt16_LittleEndian;
			
		case kBufferFormat_U16_BE:
			return Red::Audio :: kAudioBufferType_UInt16_BigEndian;
			
		case kBufferFormat_I16_LE:
			return Red::Audio :: kAudioBufferType_Int16_LittleEndian;
			
		case kBufferFormat_I16_BE:
			return Red::Audio :: kAudioBufferType_Int16_BigEndian;
			
		case kBufferFormat_I32_LE:
			return Red::Audio :: kAudioBufferType_Int32_LittleEndian;
			
		case kBufferFormat_I32_BE:
			return Red::Audio :: kAudioBufferType_Int32_BigEndian;
			
		case kBufferFormat_F32_LE:
			return Red::Audio :: kAudioBufferType_Float32_LittleEndian;
			
		default:
			return Red::Audio :: kAudioBufferType_Float32_BigEndian;
		
	}
	
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
	
	if ( reinterpret_cast <AudioDevice *> ( DeviceInstance ) -> FillFunction != NULL ) 
		( * reinterpret_cast <AudioDevice *> ( DeviceInstance ) -> FillFunction ) ( Packet, PacketLength );
	
}

void SDLX::AudioDevice :: Lock ()
{
	
	SDL_LockAudioDevice ( Device );
	
}

void SDLX::AudioDevice :: Unlock ()
{
	
	SDL_UnlockAudioDevice ( Device );
	
}

void SDLX::AudioDevice :: Start ()
{
	
	SDL_PauseAudioDevice ( Device, 0 );
	
}

void SDLX::AudioDevice :: Stop ()
{
	
	SDL_PauseAudioDevice ( Device, 1 );
	
}

void SDLX::AudioDevice :: SetFillCallback ( Red::Util :: IFunction2 <void, uint8_t *, int> * FillFunction )
{
	
	this -> FillFunction = FillFunction;
	
}

const Red::Util::Time :: Duration SDLX::AudioDevice :: GetFillDuration ()
{
	
	return Red::Util::Time :: Duration ( 1.0 / static_cast <double> ( Spec.freq ) * static_cast <double> ( Spec.samples ) );
	
}
