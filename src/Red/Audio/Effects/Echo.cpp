#include <Red/Audio/Effects/Echo.h>

Red::Audio::Effects::Echo :: Echo ( uint64_t MaxBackSampleCount, IStreamSource * Input, float PassLevel, float EchoLevel, float Feedback, float FeedForward ):
	EchoBuffer ( NULL ),
	EchoDepth ( EchoLevel ),
	Input ( Input ),
	PassLevel ( PassLevel ),
	EchoLevel ( EchoLevel ),
	Feedback ( Feedback ),
	FeedForward ( FeedForward ),
	Enabled ( true ),
	Lock ()
{
	
	if ( Input != NULL )
		Input -> Reference ();
	else
		Enabled = false;
	
	EchoBuffer = new AudioBuffer ( Red::Audio :: kAudioBufferType_PerferredQuality, 1, MaxBackSampleCount );
	
}

Red::Audio::Effects::Echo :: ~Echo ()
{
	
	Lock.Lock ();
	
	if ( Input != NULL )
	{
		
		Input -> Dereference ();
		Input = NULL;
		
	}
	
	if ( EchoBuffer != NULL )
	{
		
		EchoBuffer -> Dereference ();
		EchoBuffer = NULL;
		
	}
	
}

void Red::Audio::Effects::Echo :: SetExpectedFillSize ( uint32_t FillSize )
{
	
	(void) FillSize;
	
}

Red::Audio::IStreamSource :: StreamFillCode Red::Audio::Effects::Echo :: FillAudioBuffer ( AudioBuffer * Buffer, uint32_t TargetChannel )
{
	
	Lock.Lock ();
	
	if ( Input == NULL )
	{
		
		Lock.Unlock ();
		
		return kStreamFillCode_Failure_NoFill;
		
	}
	
	if ( Enabled == false )
		return Input -> FillAudioBuffer ( Buffer, TargetChannel );
	
	//StreamFillCode SourceFillCode = Input -> FillAudioBuffer ( Buffer, TargetChannel );
	//Buffer -> ScaleBufferByConstant ( PassLevel, TargetChannel );
	
	uint64_t FillOffset = 0;
	//uint64_t EchoOffset = 0;
	
	AudioBuffer SubBuffer ( AudioBuffer :: NO_INIT );
	
	while ( FillOffset < Buffer -> GetSampleCount () )
	{
		
		uint64_t SubSampleSize = ( EchoDepth < Buffer -> GetSampleCount () - FillOffset ) ? EchoDepth : Buffer -> GetSampleCount () - FillOffset;
		
		AudioBuffer :: CreateChildWindow ( Buffer, FillOffset, SubSampleSize, & SubBuffer );
		
		SubBuffer.Reference ();
		
		StreamFillCode SourceFillCode = Input -> FillAudioBuffer ( & SubBuffer, TargetChannel );
		
		switch ( SourceFillCode )
		{
			
			case kStreamFillCode_Success_Normal:
			case kStreamFillCode_Success_ControlParameter_Varying:
			{
				
				
				
			}
			break;
			
			case kStreamFillCode_Success_Silence:
			{
			
			
			
			}
			break;
			
			default:
				break;
		
		}
		
	}
	
	return kStreamFillCode_Success_Normal;
	
}

void Red::Audio::Effects::Echo :: SetInput ( IStreamSource * Source )
{
	
	(void) Source;
	
}

void Red::Audio::Effects::Echo :: SetEchoDelay ( uint64_t SampleCount )
{
	
	(void) SampleCount;
	
}

void Red::Audio::Effects::Echo :: SetEnabled ( bool Enabled )
{
	
	(void) Enabled;
	
}

void Red::Audio::Effects::Echo :: SetCoefficients ( float PassLevel, float EchoLevel, float Feedback, float FeedForward )
{
	
	(void) PassLevel;
	(void) EchoLevel;
	(void) Feedback;
	(void) FeedForward;
	
}
