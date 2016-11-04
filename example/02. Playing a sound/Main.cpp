#include <SDLX/SDLX.h>
#include <SDLX/Lib.h>
#include <SDLX/Window.h>
#include <SDLX/AudioDevice.h>

#include <Red/Audio/AudioStreamOutput.h>
#include <Red/Audio/AudioBuffer.h>
#include <Red/Audio/RawBufferStreamSource.h>

#include <Red/Util/Time.h>

#include <RAUX/WAVFile.h>

#include <stdint.h>

#include <iostream>

// Forward declaration
void WindowCloseEvent ( SDL_WindowEvent * Event, SDLX :: Window * Origin, void * Data );

int main ( int argc, const char * argv [] )
{
	
	// Initialize SDLX for audio only
	uint32_t Status;
	SDLX::Lib :: Init ( & Status, SDLX::Lib :: kSDLFlag_Audio );
	
	if ( SDLX :: kStatus_Success )
		return 1;
	
	/*================================================================*/
	
	// Make sure there is an audio device to open.
	if ( SDLX::AudioDevice :: GetDeviceCount ( false ) == 0 )
	{
		
		SDLX::Lib :: DeInit ();
		
		return 2;
		
	}
	
	// Open an audio device. Get the name of the first audio device. We tell SDLX that we don't need to record with this device.
	const char * AudioDevName = SDLX::AudioDevice :: GetDeviceName ( 0, false );
	// Try and open that device with a specific format. In this case, with the sample frequency 44100 Hz, interpreted as little endian 16-bit integers, with two channels. The callback will sample in increments of 4096 samples.
	// We tell SDLX that we cannot handle any other format, so if necessary, it should handle conversion to an audio-driver supported format. We also specify that we don't need to be able to record with this device.
	SDLX::AudioDevice * MyAudioDevice = SDLX::AudioDevice :: RequestAudioDevice ( AudioDevName, SDLX::AudioDevice :: kStandardFrequencey_44K, SDLX::AudioDevice :: kBufferFormat_I16_LE, 2, 4096, false, false );
	
	// If the returned pointer is null, the device couldn't be opened. Fail gracefully.
	if ( MyAudioDevice == NULL )
	{
		
		SDLX::Lib :: DeInit ();
		
		return 3;
		
	}
	
	// Claim ownership of the audio device under reference counting.
	MyAudioDevice -> Reference ();
	// Create an AudioStreamOutput object to represent the device under the Red audio system.
	Red::Audio :: AudioStreamOutput MyAudioOutput ( MyAudioDevice, 2 );
	
	/*================================================================*/
	
	// Create a WAV file object for our file. In this case i'm using the song "Little Pistol" by Mother Mother.
	RAUX :: WAVFile MyWAV ( "LittlePistol.wav" );
	
	// Attempt to load the file
	MyWAV.Load ( & Status );
	
	// If there was some problem, fail gracefully.
	if ( Status != RAUX::WAVFile :: kStatus_Success )
	{
		
		MyAudioDevice -> Dereference ();
		MyAudioDevice = NULL;
		
		SDLX::Lib :: DeInit ();
		
		return 4;
		
	}
	
	// Load the WAV data into an audio buffer.
	Red::Audio :: AudioBuffer * WAVBuffer = MyWAV.LoadToBuffer ();
	
	// Close the wav file.
	MyWAV.Close ( & Status );
	
	// Check that our data was properly loaded.
	if ( WAVBuffer == NULL )
	{
		
		MyAudioDevice -> Dereference ();
		MyAudioDevice = NULL;
		
		SDLX::Lib :: DeInit ();
		
		return 5;
		
	}
	
	// Keep ownership of this buffer.
	WAVBuffer -> Reference ();
	
	// Create stream source objects for the left and right channels of our audio
	Red::Audio :: RawBufferStreamSource LeftChannelSource ( WAVBuffer, 0 );
	Red::Audio :: RawBufferStreamSource RightChannelSource ( WAVBuffer, 1 );
	
	// Keep references to them, because even while they are locals, we don't want something to dereference them and try to call delete on a stack-allocated object.
	LeftChannelSource.Reference ();
	RightChannelSource.Reference ();
	
	/*================================================================*/
	
	// We tell the audio output to source channel 0 and 1 data from the left and right buffer stream sources respectively
	MyAudioOutput.SetStreamSource ( 0, & LeftChannelSource );
	MyAudioOutput.SetStreamSource ( 1, & RightChannelSource );
	
	// Start the audio output. ( Begin playing our audio. )
	MyAudioOutput.Start ();
	
	// Sleep until our audio is done playing. Normally, we wouldn't just be blocking for this time, but this is just a demo.
	Red::Util::Time :: BlockFor ( Red::Util::Time :: Duration ( 390.0 ) );
	
	/*================================================================*/
	
	// Stop the audio output, since we have nothing left to play.
	MyAudioOutput.Stop ();
	
	// Clean up. Note that local objects shouldn't be dereferenced in this scope since they will automatically be deleted when this function returns.
	WAVBuffer -> Dereference ();
	
	MyAudioDevice -> Dereference ();
	MyAudioDevice = NULL;
	
	SDLX::Lib :: DeInit ();
	
}
