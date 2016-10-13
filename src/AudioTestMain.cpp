#include <iostream>

#include <SDLX/Lib.h>
#include <SDLX/Window.h>

#include <Red/Util/Closure.h>

#include <SDLX/AudioDevice.h>

#include <math.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void WindowCloseEvent ( SDL_WindowEvent * Event, SDLX::Window * Win, void * Data );

void FillAudioData ( uint32_t & Counter, uint8_t * DataBuffer, int PacketLength );

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
	
	SDLX :: AudioDevice * Device = SDLX::AudioDevice :: RequestAudioDevice ( NULL, SDLX::AudioDevice :: kStandardFrequencey_48K, SDLX::AudioDevice :: kBufferFormat_F32_SE, 1, 4096, false, false );
	
	uint32_t * Counter = new uint32_t ();
	
	Red::Util :: Closure3_1 <void, uint32_t &, uint8_t *, int> FillDataClosure ( & FillAudioData, * Counter );
	
	if ( Device != NULL )
		std :: cout << "Got audio device!" << std :: endl;
	
	Device -> Lock ();
	Device -> SetFillCallback ( & FillDataClosure );
	Device -> Unlock ();
	
	Device -> Start ();
	
	/*================================*/
	
	SDLX::Lib :: EventLoop ( & Status );
	
	Device -> Stop ();
	
	delete Counter;
	delete Device;
	 
	Win -> Disown ();
	
	SDLX::Lib :: DeInit ();
	
	return 0;

}

void FillAudioData ( uint32_t & Counter, uint8_t * DataBuffer, int PacketLength )
{
	
	float * DataPointer = reinterpret_cast <float *> ( DataBuffer );
	
	std :: cout << "Counter: " << Counter << std :: endl;
	
	for ( uint32_t I = 0; I < 4096; I ++ )
	{
		
		double Seconds = static_cast <double> ( Counter + I ) / 48000.0;
		DataPointer [ I ] = sinf ( Seconds * 3.14159265 * 440.0 * powf ( 1.059463094359, ( Counter / 24000 ) ) );
		
	}
	
	Counter += 4096;
	
}

void WindowCloseEvent ( SDL_WindowEvent * Event, SDLX::Window * Win, void * Data )
{
	
	uint32_t Status;
	
	( void ) Event;
	( void ) Data;
	
	Win -> Close ( & Status );
	
}
