#include <iostream>

#include <SDLX/Lib.h>
#include <SDLX/Window.h>

#include <Red/Util/Closure.h>
#include <Red/Util/Function.h>

#include <SDLX/AudioDevice.h>

#include <Red/Audio/AudioBuffer.h>
#include <Red/Audio/AudioStreamOutput.h>
#include <Red/Audio/RawBufferStreamSource.h>

#include <Red/Math/FFT.h>

#include <Red/Util/Endian.h>

#include <RAUX/WAVFile.h>

#include <math.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void WindowCloseEvent ( SDL_WindowEvent * Event, SDLX::Window * Win, void * Data );

void FillAudioData ( uint32_t & Counter, uint8_t * DataBuffer, int PacketLength );

bool DoRepeateSource ( Red::Audio :: RawBufferStreamSource * Source );

int main ( int argc, char const * argv [] )
{
	
	( void ) argc;
	( void ) argv;
	
	uint32_t Status;
	
	SDLX::Lib :: Init ( & Status, SDLX::Lib :: kSDLFlag_Video | SDLX::Lib :: kSDLFlag_Audio );
	
	if ( Status != SDLX :: kStatus_Success )
		return - 1;
	
	SDLX::Window * Win = SDLX::Window :: CreateWindow ( & Status, "Test", WINDOW_WIDTH, WINDOW_HEIGHT, SDLX::Window :: kCreateFlag_Shown | SDLX::Window :: kCreateFlag_HighDPI | SDLX::Window :: kCreateFlag_OpenGL );
	
	if ( Status != SDLX::Window :: kStatus_Success )
	{
		
		SDLX::Lib :: DeInit ();
		
		return - 2;
		
	}
	
	Win -> Own ();
	Win -> AddEventHook ( SDL_WINDOWEVENT_CLOSE, & WindowCloseEvent, NULL );
	
	/*================================*/
	
	RAUX :: WAVFile TestWAV ( "LittlePistol.wav" );
	
	TestWAV.Load ( & Status );
	
	Red::Audio :: AudioBuffer * FileBuffer = NULL;
	Red::Audio::AudioBuffer * ResampleBuffer = NULL;
	
	if ( Status == RAUX :: WAVFile :: kStatus_Success )
	{
		
		FileBuffer = TestWAV.LoadToBuffer ();
		
		if ( FileBuffer != NULL )
		{
			
			std :: cout << "WAV Load success!" << std :: endl;
			
			ResampleBuffer = Red::Audio::AudioBuffer :: CopyReformatedResampled ( * FileBuffer, Red::Audio::AudioBuffer :: kResampleMode_Linear, FileBuffer -> GetDataType (), 3.0 );
			
		}
		
		TestWAV.Close ( & Status );
		
	}
	else
		std :: cout << "WAV Load failure: " << Status << std :: endl;
		
	
	Red::Audio :: RawBufferStreamSource WAVSourceLeftChannel ( ResampleBuffer, 0 );
	Red::Audio :: RawBufferStreamSource WAVSourceRightChannel ( ResampleBuffer, 1 );
	
	Red::Util :: Function1 <bool, Red::Audio :: RawBufferStreamSource *> RepeatePTR ( & DoRepeateSource );
	
	WAVSourceLeftChannel.Reference ();
	WAVSourceRightChannel.Reference ();
	
	WAVSourceLeftChannel.SetFinishedCallback ( & RepeatePTR );
	WAVSourceRightChannel.SetFinishedCallback ( & RepeatePTR );
	
	/*================================*/
	
	SDLX :: AudioDevice * Device = SDLX::AudioDevice :: RequestAudioDevice ( NULL, 44100, SDLX::AudioDevice :: kBufferFormat_I16_LE, 2, 8192, false, false );
	
	if ( Device == NULL )
	{
		
		Win -> Disown ();
		
		SDLX::Lib :: DeInit ();
		
		return 0;
		
	}
	
	Device -> Reference ();
	
	Red::Audio :: AudioStreamOutput AudioOutput ( Device );
	
	AudioOutput.SetStreamSource ( 0, & WAVSourceLeftChannel );
	AudioOutput.SetStreamSource ( 1, & WAVSourceRightChannel );
	
	AudioOutput.Start ();
	
	/*================================*/
	
	SDLX::Lib :: EventLoop ( & Status ); // GAME LOOP
	
	/*================================*/
	
	Device -> Stop ();
	Device -> Dereference ();
	 
	Win -> Disown ();
	
	SDLX::Lib :: DeInit ();
	
	return 0;

}

bool DoRepeateSource ( Red::Audio :: RawBufferStreamSource * Source )
{
	
	Source -> SetOffset ( 0 );
	
	return true;
	
}

void WindowCloseEvent ( SDL_WindowEvent * Event, SDLX::Window * Win, void * Data )
{
	
	uint32_t Status;
	
	( void ) Event;
	( void ) Data;
	
	Win -> Close ( & Status );
	
}
