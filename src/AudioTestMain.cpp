#include <iostream>

#include <SDLX/Lib.h>
#include <SDLX/Window.h>

#include <Red/Util/Closure.h>

#include <SDLX/AudioDevice.h>

#include <Red/Audio/AudioBuffer.h>

#include <Red/Math/FFT.h>

#include <Red/Util/Endian.h>

#include <RAUX/WAVFile.h>

#include <math.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void WindowCloseEvent ( SDL_WindowEvent * Event, SDLX::Window * Win, void * Data );

void FillAudioData ( uint32_t & Counter, uint8_t * DataBuffer, int PacketLength );

Red::Audio :: AudioBuffer * FileBuffer = NULL;

Red::Math :: FFT_1DReal_Float TestFFT;
Red::Math :: IFFT_1DReal_Float TestIFFT;

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
	
	SDLX :: AudioDevice * Device = SDLX::AudioDevice :: RequestAudioDevice ( NULL, 44100, SDLX::AudioDevice :: kBufferFormat_I16_LE, 2, 8192, false, false );
	
	if ( Device == NULL )
	{
		
		Win -> Disown ();
		
		SDLX::Lib :: DeInit ();
		
		return 0;
		
	}
	
	TestFFT.Setup ( 8192 );
	TestIFFT.Setup( 8192 );
		
	uint32_t * Counter = new uint32_t ();
	
	Red::Util :: Closure3_1 <void, uint32_t &, uint8_t *, int> FillDataClosure ( & FillAudioData, * Counter );
	
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
	
	(void) PacketLength;
	
	float TempData [ 8192 * 2 ];
	
	Red::Audio :: AudioBuffer ConversionBuffer ( reinterpret_cast <void *> ( TempData ), Red::Audio :: kAudioBufferType_Float32_LittleEndian, 2, 8192, NULL );
	
	Red::Audio :: AudioBuffer FillBuffer ( reinterpret_cast <void *> ( DataBuffer ), Red::Audio :: kAudioBufferType_Int16_LittleEndian, 2, 8192, NULL );
	FillBuffer.Reference ();
	
	if ( FileBuffer != NULL )
	{
		
		if ( FileBuffer -> GetSampleCount () > Counter + 8192 )
		{
			
			ConversionBuffer.ClearBufferFloat ( 0, 0.0f );
			
			ConversionBuffer.AddBufferScaled ( * FileBuffer, 0.5f, 0, 8192, Counter, 0, 0 );
			ConversionBuffer.AddBufferScaled ( * FileBuffer, 0.5f, 1, 8192, Counter, 0, 0 );
			
			float FFTBuff [ 8192 ];
			
			TestFFT.Run ( reinterpret_cast <float *> ( ConversionBuffer.GetRawBuffer () ), 2 );
			TestIFFT.Run ( TestFFT.GetResult (), 1 );
			TestIFFT.GetResultReal ( FFTBuff, 1 );
			
			Red::Audio :: AudioBuffer FFTAudioBuffer ( reinterpret_cast <void *> ( FFTBuff ), Red::Audio :: kAudioBufferType_Float32_LittleEndian, 1, 8192, NULL );
			
			FillBuffer.BlitBuffer ( FFTAudioBuffer, 0, 8192, 0, 0 );
			FillBuffer.BlitBuffer ( FFTAudioBuffer, 0, 8192, 0, 0, 1 );
			
		}
		
	}
	
	Counter += 8192;
	
}

void WindowCloseEvent ( SDL_WindowEvent * Event, SDLX::Window * Win, void * Data )
{
	
	uint32_t Status;
	
	( void ) Event;
	( void ) Data;
	
	Win -> Close ( & Status );
	
}
