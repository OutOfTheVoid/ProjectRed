#include <Red/Audio/RawBufferStreamSource.h>

Red::Audio::RawBufferStreamSource :: RawBufferStreamSource ( AudioBuffer * SourceData, uint32_t Channel, uint64_t Offset, uint64_t FinishOffset ):
	SourceData ( SourceData ),
	Channel ( Channel ),
	Offset ( Offset ),
	FinishOffset ( FinishOffset ),
	FinishedCallback ( NULL ),
	Lock ()
{
	
	if ( SourceData != NULL )
	{
		
		SourceData -> Reference ();
		
		if ( FinishOffset > SourceData -> GetSampleCount () )
			this -> FinishOffset = SourceData -> GetSampleCount ();
		
		if ( Offset > this -> FinishOffset )
			this -> Offset = this -> FinishOffset;
		
	}
	
}

void Red::Audio::RawBufferStreamSource :: ResetSource ( AudioBuffer * SourceData, uint32_t Channel, uint64_t Offset, uint64_t FinishOffset )
{
	
	Lock.Lock ();
	
	if ( this -> SourceData != SourceData )
	{
		
		if ( this -> SourceData != NULL )
			SourceData -> Dereference ();
		
		this -> SourceData = SourceData;
		
		if ( SourceData != NULL )
			SourceData -> Reference ();
		
	}
	
	if ( SourceData != NULL )
	{
	
		if ( FinishOffset > SourceData -> GetSampleCount () )
			FinishOffset = SourceData -> GetSampleCount ();
		
		if ( Offset > FinishOffset )
			Offset = FinishOffset;
		
	}
	
	this -> Offset = Offset;
	this -> FinishOffset = FinishOffset;
	
	this -> Channel = Channel;
	
	Lock.Unlock ();
	
}

Red::Audio::RawBufferStreamSource :: ~RawBufferStreamSource ()
{
	
	Lock.Lock ();
	
	if ( SourceData != NULL )
	{
		
		SourceData -> Dereference ();
		SourceData = NULL;
		
	}
	
	Lock.Unlock ();
	
}

void Red::Audio::RawBufferStreamSource :: SetFinishedCallback ( Util :: IFunction1 <bool, RawBufferStreamSource *> * Callback )
{
	
	Lock.Lock ();
	
	this -> FinishedCallback = Callback;
	
	Lock.Unlock ();
	
}

void Red::Audio::RawBufferStreamSource :: SetOffset ( uint64_t Offset )
{
	
	Lock.Lock ();
	
	this -> Offset = Offset;
	
	Lock.Unlock ();
	
}

void Red::Audio::RawBufferStreamSource :: SetFinishPoint ( uint64_t Finish )
{
	
	Lock.Lock ();
	
	FinishOffset = Finish;
	
	if ( SourceData != NULL )
	{
		
		if ( FinishOffset > SourceData -> GetSampleCount () )
			FinishOffset = SourceData -> GetSampleCount ();
		
	}
	
	Lock.Unlock ();
	
}

void Red::Audio::RawBufferStreamSource :: SetExpectedFillSize ( uint32_t FillSize )
{
	
	(void) FillSize;
	
}

Red::Audio::IStreamSource :: StreamFillCode Red::Audio::RawBufferStreamSource :: FillAudioBuffer ( AudioBuffer * Buffer, uint32_t TargetChannel )
{
	
	Lock.Lock ();
	
	if ( SourceData == NULL )
	{
		
		Lock.Unlock ();
		
		return kStreamFillCode_Failure_NoFill;
		
	}
	
	if ( Offset >= FinishOffset )
	{
		
		Lock.Unlock ();
		
		return kStreamFillCode_Success_Silence;
		
	}
	
	uint64_t FillSize = FinishOffset - Offset;
	uint64_t BufferSampleCount = Buffer -> GetSampleCount ();
	
	if ( BufferSampleCount < FillSize )
		FillSize = BufferSampleCount;
	
	Buffer -> BlitBuffer ( * SourceData, Channel, FillSize, Offset, 0, TargetChannel );
	
	if ( FillSize < BufferSampleCount )
		Buffer -> ClearBufferInt ( TargetChannel, 0, FillSize, BufferSampleCount - FillSize );
	
	Offset += FillSize;
	
	if ( Offset == FinishOffset )
	{
		
		Util :: IFunction1 <bool, RawBufferStreamSource *> * OnFinished = FinishedCallback;
		
		Lock.Unlock ();
		
		if ( OnFinished != NULL )
		{
			
			if ( ( FillSize < BufferSampleCount ) && ( * OnFinished ) ( this ) )
				FillAudioBuffer ( Buffer, TargetChannel );
			
		}
		
		return kStreamFillCode_Success_Normal;
		
	}
	
	Lock.Unlock ();
	
	return kStreamFillCode_Success_Normal;
	
}
