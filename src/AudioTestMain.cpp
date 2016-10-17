#include <iostream>

#include <SDLX/Lib.h>
#include <SDLX/Window.h>

#include <Red/Util/Closure.h>

#include <SDLX/AudioDevice.h>

#include <Red/Audio/AudioBuffer.h>

#include <Red/Util/Endian.h>

#include <RAUX/WAVFile.h>

#include <math.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void WindowCloseEvent ( SDL_WindowEvent * Event, SDLX::Window * Win, void * Data );

void FillAudioData ( uint32_t & Counter, uint8_t * DataBuffer, int PacketLength );

Red::Audio :: AudioBuffer * FileBuffer = NULL;

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
	
	if ( Status == RAUX :: WAVFile :: kStatus_Success )
	{
		
		FileBuffer = TestWAV.LoadToBuffer ();
		
		if ( FileBuffer != NULL )
			std :: cout << "WAV Load success!" << std :: endl;
		
		FileBuffer -> Reference ();
		
	}
	
	/*================================*/
	
	SDLX :: AudioDevice * Device = SDLX::AudioDevice :: RequestAudioDevice ( NULL, 44100, SDLX::AudioDevice :: kBufferFormat_I16_LE, 2, 4096, false, false );
	
	if ( Device == NULL )
	{
		
		Win -> Disown ();
		
		SDLX::Lib :: DeInit ();
		
		return 0;
		
	}
		
	uint32_t * Counter = new uint32_t ();
	
	Red::Util :: Closure3_1 <void, uint32_t &, uint8_t *, int> FillDataClosure ( & FillAudioData, * Counter );
	
	Device -> Lock ();
	Device -> SetFillCallback ( & FillDataClosure );
	Device -> Unlock ();
	
	Device -> Start ();
	
	/*================================*/
	
	SDLX::Lib :: EventLoop ( & Status );
	
	//Device -> Lock ();
	Device -> Stop ();
	
	delete Counter;
	delete Device;
	 
	Win -> Disown ();
	
	SDLX::Lib :: DeInit ();
	
	return 0;

}

void FillAudioData ( uint32_t & Counter, uint8_t * DataBuffer, int PacketLength )
{
	
	(void) PacketLength;
	
	uint32_t TempData [ 4096 * 2 ];
	
	Red::Audio :: AudioBuffer ConversionBuffer ( reinterpret_cast <void *> ( TempData ), Red::Audio :: kAudioBufferType_UInt32_BigEndian, 2, 4096, NULL );
	
	Red::Audio :: AudioBuffer FillBuffer ( reinterpret_cast <void *> ( DataBuffer ), Red::Audio :: kAudioBufferType_Int16_LittleEndian, 2, 4096, NULL );
	FillBuffer.Reference ();
	
	if ( FileBuffer != NULL )
	{
		
		if ( FileBuffer -> GetSampleCount () > Counter + 4096 )
		{
			
			ConversionBuffer.BlitBuffer ( * FileBuffer, 0, 4096, Counter, 0 );
			ConversionBuffer.BlitBuffer ( * FileBuffer, 1, 4096, Counter, 0 );
			
			FillBuffer.BlitBuffer ( ConversionBuffer, 0, 4096, 0, 0 );
			FillBuffer.BlitBuffer ( ConversionBuffer, 1, 4096, 0, 0 );
			
			std :: cout << std :: endl << std :: endl;
			
		}
		
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
