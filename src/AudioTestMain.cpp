#include <iostream>

#include <SDLX/Lib.h>
#include <SDLX/Window.h>

#include <Red/Util/Closure.h>
#include <Red/Util/Function.h>

#include <SDLX/AudioDevice.h>

#include <Red/Audio/AudioBuffer.h>
#include <Red/Audio/AudioStreamOutput.h>
#include <Red/Audio/RawBufferStreamSource.h>

#include <Red/Audio/Effects/Echo.h>

#include <Red/Math/FFT.h>

#include <Red/Util/Endian.h>

#include <RAUX/WAVFile.h>

#include <math.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void WindowCloseEvent ( SDL_WindowEvent * Event, SDLX::Window * Win, void * Data );

void DoRepeateSource ( Red::Audio :: RawBufferStreamSource * Source );

int main ( int argc, char const * argv [] )
{
	
	( void ) argc;
	( void ) argv;
	
	uint32_t Status;
	
	SDLX::Lib :: Init ( & Status, SDLX::Lib :: kSDLFlag_Video | SDLX::Lib :: kSDLFlag_Audio );
	
	if ( Status != SDLX :: kStatus_Success )
		return - 1;
	
	SDLX::Window * Win = SDLX::Window :: Create ( & Status, "Test", WINDOW_WIDTH, WINDOW_HEIGHT, SDLX::Window :: kCreateFlag_Shown | SDLX::Window :: kCreateFlag_HighDPI );
	
	if ( Status != SDLX::Window :: kStatus_Success )
	{
		
		SDLX::Lib :: DeInit ();
		
		return - 2;
		
	}
	
	Win -> Own ();
	Win -> AddEventHook ( SDLX::Window :: kWindowEventID_Closed, & WindowCloseEvent, NULL );
	
	/*================================*/
	
	RAUX :: WAVFile TestWAV ( "VHSCollection_Lean.wav" );
	
	TestWAV.Load ( & Status );
	
	Red::Audio :: AudioBuffer * FileBuffer = NULL;
	
	if ( Status == RAUX :: WAVFile :: kStatus_Success )
	{
		
		FileBuffer = TestWAV.LoadToBuffer ();
		
		if ( FileBuffer != NULL )
		{
			
			std :: cout << "WAV Load success!" << std :: endl;
			
		}
		
		TestWAV.Close ( & Status );
		
	}
	else
		std :: cout << "WAV Load failure: " << Status << std :: endl;

	Red::Audio :: RawBufferStreamSource WAVSourceLeftChannel ( FileBuffer, 0 );
	Red::Audio :: RawBufferStreamSource WAVSourceRightChannel ( FileBuffer, 1 );
	
	Red::Util :: Function1 <void, Red::Audio :: RawBufferStreamSource *> RepeatePTR ( & DoRepeateSource );
	
	WAVSourceLeftChannel.Reference ();
	WAVSourceRightChannel.Reference ();
	
	WAVSourceLeftChannel.SetFinishedCallback ( & RepeatePTR );
	WAVSourceRightChannel.SetFinishedCallback ( & RepeatePTR );
	
	WAVSourceLeftChannel.SetOffset ( 0 );
	WAVSourceRightChannel.SetOffset ( 0 );
	
	Red::Audio::Effects :: Echo LeftChannelEcho ( 20000, & WAVSourceLeftChannel, 0.5f, 0.5f, 0.5f, 0.2f );
	Red::Audio::Effects :: Echo RightChannelEcho ( 20000, & WAVSourceRightChannel, 0.5f, 0.5f, 0.5f, 0.2f );
	
	LeftChannelEcho.Reference ();
	RightChannelEcho.Reference ();
	
	/*================================*/
	
	SDLX :: AudioDevice * Device = SDLX::AudioDevice :: RequestAudioDevice ( NULL, 44100, SDLX::AudioDevice :: kBufferFormat_I32_SE, 2, 4096, true, false );
	
	if ( Device == NULL )
	{
		
		Win -> Disown ();
		
		SDLX::Lib :: DeInit ();
		
		return 0;
		
	}
	
	Device -> Reference ();
	
	Red::Audio :: AudioStreamOutput AudioOutput ( Device );
	
	AudioOutput.SetStreamSource ( 0, & LeftChannelEcho );
	AudioOutput.SetStreamSource ( 1, & RightChannelEcho );
	
	AudioOutput.Start ();
	
	/*================================*/
	
	SDLX::Lib :: EventLoop ( & Status ); // GAME LOOP
	
	/*================================*/
	
	AudioOutput.Stop ();
	
	Device -> Stop ();
	Device -> Dereference ();
	 
	Win -> Disown ();
	
	SDLX::Lib :: DeInit ();
	
	return 0;

}

void DoRepeateSource ( Red::Audio :: RawBufferStreamSource * Source )
{
	
	Source -> SetOffset ( 0 );
	Source -> SetPlaying ( true );
	
	return;
	
}

void WindowCloseEvent ( SDL_WindowEvent * Event, SDLX::Window * Win, void * Data )
{
	
	uint32_t Status;
	
	( void ) Event;
	( void ) Data;
	
	Win -> Close ( & Status );
	
}
