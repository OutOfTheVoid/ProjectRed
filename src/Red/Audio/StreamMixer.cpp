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
	
	StreamsLock.LockWrite ();
	
	for ( uint32_t I = 0; I < StreamCount; I ++ )
	{
		
		if ( Streams [ I ].Source == NULL )
		{
			
			Streams [ I ].Source = Source;
			Streams [ I ].Scale = InitialScaleFactor;
			Streams [ I ].Muted = InitiallyMuted;
			
			StreamsLock.UnlockWrite ();
			
			Source -> Reference ();
			Source -> SetExpectedFillSize ( FillSize );
			
			return I;
			
		}
		
	}
	
	StreamsLock.UnlockWrite ();
	
	return kStream_Invalid;
	
}

uint32_t Red::Audio::StreamMixer :: GetFirstStreamBySource ( IStreamSource * Source )
{
	
	StreamsLock.LockRead ();
	
	for ( uint32_t I = 0; I < StreamCount; I ++ )
	{
		
		if ( Streams [ I ].Source == Source )
		{
			
			StreamsLock.UnlockRead ();
			
			return I;
			
		}
		
	}
	
	StreamsLock.UnlockRead ();
	
	return kStream_Invalid;
	
}

void Red::Audio::StreamMixer :: RemoveStream ( uint32_t Index )
{
	
	if ( Index >= StreamCount )
		return;
	
	IStreamSource * ToDereference = NULL;
	
	StreamsLock.LockWrite ();
	
	if ( Streams [ Index ].Source != NULL )
	{
		
		ToDereference = Streams [ Index ].Source;
		Streams [ Index ].Source = NULL;
		
	}
	
	StreamsLock.UnlockWrite ();
	
	if ( ToDereference != NULL )
		ToDereference -> Dereference ();
	
}

void Red::Audio::StreamMixer :: SetStreamScale ( uint32_t Index, float ScaleFactor )
{
	
	if ( Index >= StreamCount )
		return;
	
	StreamsLock.LockRead ();
	
	Streams [ Index ].Scale = ScaleFactor;
	
	StreamsLock.UnlockRead ();
	
}

void Red::Audio::StreamMixer :: SetStreamMuted ( uint32_t Index, bool Muted )
{
	
	if ( Index >= StreamCount )
		return;
	
	StreamsLock.LockRead ();
	
	Streams [ Index ].Muted = Muted;
	
	StreamsLock.UnlockRead ();
	
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
	
	StreamsLock.LockRead ();
	
	for ( uint32_t I = 0; I < StreamCount; I ++ )
	{
		
		if ( Streams [ I ].Source != NULL )
			Streams [ I ].Source -> SetExpectedFillSize ( FillSize );
		
	}
	
	StreamsLock.UnlockRead ();
	
}

void Red::Audio::StreamMixer :: FillAudioBuffer ( AudioBuffer * Buffer, uint32_t TargetChannel )
{
	
	Buffer -> ClearBufferInt ( TargetChannel );
	
	StreamsLock.LockRead ();
	
	for ( uint32_t I = 0; I < StreamCount; I ++ )
	{
		
		if ( ( Streams [ I ].Source != NULL ) && ( ! Streams [ I ].Muted ) )
		{
			
			Streams [ I ].Source -> FillAudioBuffer ( IntermediaryBuffer, 0 );
			
			if ( Streams [ I ].Scale == 1.0f )
				Buffer -> AddBuffer ( * IntermediaryBuffer, 0, Buffer -> GetSampleCount (), 0, 0, TargetChannel );
			else
				Buffer -> AddBufferScaled ( * IntermediaryBuffer, Streams [ I ].Scale, 0, Buffer -> GetSampleCount (), 0, 0, TargetChannel );
			
		}
		
	}
	
	StreamsLock.UnlockRead ();
	
}
