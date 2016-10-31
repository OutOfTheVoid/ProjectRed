#include <Red/Audio/StreamMixer.h>

Red::Audio::StreamMixer :: StreamMixer ( AudioBufferType IntermediaryBufferType, uint32_t MaxStreamCount ):
	Streams ( new Stream [ MaxStreamCount ] ),
	StreamCount ( MaxStreamCount ),
	StreamsLock (),
	FillSize ( 0 ),
	IntermediaryBuffer ( NULL ),
	IntermediaryBufferType ( IntermediaryBufferType )
{
	
	for ( uint32_t I = 0; I < MaxStreamCount; I ++ )
	{
		
		Streams [ I ].Source = NULL;
		Streams [ I ].Scale = 0.0f;
		Streams [ I ].Muted = false;
		
	}
	
}

Red::Audio::StreamMixer :: ~StreamMixer ()
{
	
	for ( uint32_t I = 0; I < StreamCount; I ++ )
	{
		
		if ( Streams [ I ].Source != NULL )
		{
			
			Streams [ I ].Source -> Dereference ();
			Streams [ I ].Source = NULL;
			
		}
		
	}
	
	delete[] Streams;
	
}

uint32_t Red::Audio::StreamMixer :: AddStream ( IStreamSource * Source, float InitialScaleFactor, bool InitiallyMuted )
{
	
	StreamsLock.Lock ();
	
	for ( uint32_t I = 0; I < StreamCount; I ++ )
	{
		
		if ( Streams [ I ].Source == NULL )
		{
			
			Streams [ I ].Source = Source;
			Streams [ I ].Scale = InitialScaleFactor;
			Streams [ I ].Muted = InitiallyMuted;
			
			StreamsLock.Unlock ();
			
			Source -> Reference ();
			Source -> SetExpectedFillSize ( FillSize );
			
			return I;
			
		}
		
	}
	
	StreamsLock.Unlock ();
	
	return kStream_Invalid;
	
}

uint32_t Red::Audio::StreamMixer :: GetFirstStreamBySource ( IStreamSource * Source )
{
	
	StreamsLock.Lock ();
	
	for ( uint32_t I = 0; I < StreamCount; I ++ )
	{
		
		if ( Streams [ I ].Source == Source )
		{
			
			StreamsLock.Unlock ();
			
			return I;
			
		}
		
	}
	
	StreamsLock.Unlock ();
	
	return kStream_Invalid;
	
}

void Red::Audio::StreamMixer :: RemoveStream ( uint32_t Index )
{
	
	if ( Index >= StreamCount )
		return;
	
	IStreamSource * ToDereference = NULL;
	
	StreamsLock.Lock ();
	
	if ( Streams [ Index ].Source != NULL )
	{
		
		ToDereference = Streams [ Index ].Source;
		Streams [ Index ].Source = NULL;
		
	}
	
	StreamsLock.Unlock ();
	
	if ( ToDereference != NULL )
		ToDereference -> Dereference ();
	
}

void Red::Audio::StreamMixer :: SetStreamScale ( uint32_t Index, float ScaleFactor )
{
	
	if ( Index >= StreamCount )
		return;
	
	StreamsLock.Lock ();
	
	Streams [ Index ].Scale = ScaleFactor;
	
	StreamsLock.Unlock ();
	
}

void Red::Audio::StreamMixer :: SetStreamMuted ( uint32_t Index, bool Muted )
{
	
	if ( Index >= StreamCount )
		return;
	
	StreamsLock.Lock ();
	
	Streams [ Index ].Muted = Muted;
	
	StreamsLock.Unlock ();
	
}

			// IStreamSource
void Red::Audio::StreamMixer :: SetExpectedFillSize ( uint32_t FillSize )
{
	
	this -> FillSize = FillSize;
	
	if ( IntermediaryBuffer != NULL )
	{
		
		if ( IntermediaryBuffer -> GetSampleCount () != FillSize )
		{
			
			delete IntermediaryBuffer;
			
			IntermediaryBuffer = new AudioBuffer ( IntermediaryBufferType, 1, FillSize );
			
		}
		
	}
	else
		IntermediaryBuffer = new AudioBuffer ( IntermediaryBufferType, 1, FillSize );
	
	StreamsLock.Lock ();
	
	for ( uint32_t I = 0; I < StreamCount; I ++ )
	{
		
		if ( Streams [ I ].Source != NULL )
			Streams [ I ].Source -> SetExpectedFillSize ( FillSize );
		
	}
	
	StreamsLock.Unlock ();
	
}

Red::Audio::IStreamSource :: StreamFillCode Red::Audio::StreamMixer :: FillAudioBuffer ( AudioBuffer * Buffer, uint32_t TargetChannel )
{
	
	Buffer -> ClearBufferInt ( TargetChannel );
	
	StreamsLock.Lock ();
	
	uint32_t AudioCount = 0;
	
	for ( uint32_t I = 0; I < StreamCount; I ++ )
	{
		
		if ( ( Streams [ I ].Source != NULL ) && ( ! Streams [ I ].Muted ) )
		{
		
			StreamFillCode FillCode = Streams [ I ].Source -> FillAudioBuffer ( IntermediaryBuffer, 0 );
			
			if ( ( ( FillCode & kStreamFillCode_ErrorFlag ) == 0 ) && ( FillCode != kStreamFillCode_Success_Silence ) )
			{
				
				AudioCount ++;
				
				if ( Streams [ I ].Scale == 1.0f )
					Buffer -> AddBuffer ( * IntermediaryBuffer, 0, Buffer -> GetSampleCount (), 0, 0, TargetChannel );
				else
					Buffer -> AddBufferScaled ( * IntermediaryBuffer, Streams [ I ].Scale, 0, Buffer -> GetSampleCount (), 0, 0, TargetChannel );
				
			}
			
		}
		
	}
	
	StreamsLock.Unlock ();
	
	return ( AudioCount > 0 ) ? kStreamFillCode_Success_Normal : kStreamFillCode_Success_Silence;
	
}
