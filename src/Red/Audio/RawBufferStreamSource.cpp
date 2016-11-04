#include <Red/Audio/RawBufferStreamSource.h>

Red::Audio::RawBufferStreamSource :: RawBufferStreamSource ( AudioBuffer * SourceData, uint32_t Channel, uint64_t Offset, uint64_t FinishOffset, uint64_t StartDelay, bool InitiallyPlaying ):
	SourceData ( SourceData ),
	Channel ( Channel ),
	Offset ( Offset ),
	FinishOffset ( FinishOffset ),
	StartDelay ( StartDelay ),
	DelayCounter ( 0 ),
	Playing ( InitiallyPlaying ),
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

void Red::Audio::RawBufferStreamSource :: ResetSource ( AudioBuffer * SourceData, uint32_t Channel, uint64_t Offset, uint64_t FinishOffset, uint64_t StartDelay, bool InitiallyPlaying )
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
	
	this -> StartDelay = StartDelay;
	this -> Playing = InitiallyPlaying;
	this -> DelayCounter = 0;
	
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

void Red::Audio::RawBufferStreamSource :: SetFinishedCallback ( Util :: IFunction1 <void, RawBufferStreamSource *> * Callback )
{
	
	Lock.Lock ();
	
	this -> FinishedCallback = Callback;
	
	Lock.Unlock ();
	
}

void Red::Audio::RawBufferStreamSource :: ResetDelayCounter ( uint64_t DelayCounter )
{
	
	Lock.Lock ();
	
	this -> DelayCounter = DelayCounter;
	
	Lock.Unlock ();
	
}

void Red::Audio::RawBufferStreamSource :: SetOffset ( uint64_t Offset )
{
	
	Lock.Lock ();
	
	this -> Offset = Offset;
	
	Lock.Unlock ();
	
}

void Red::Audio::RawBufferStreamSource :: SetPlaying ( bool Playing )
{
	
	Lock.Lock ();
	
	this -> Playing = Playing;
	
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
	
	if ( ! Playing )
	{
		
		Lock.Unlock ();
		
		return kStreamFillCode_Success_Silence;
		
	}
	
	if ( Offset >= FinishOffset )
	{
		
		Lock.Unlock ();
		
		return kStreamFillCode_Success_Silence;
		
	}
	
	uint64_t BufferSampleCount = Buffer -> GetSampleCount ();
	uint64_t DelayOffset = 0;
	
	if ( DelayCounter < StartDelay )
	{
		
		if ( DelayCounter + BufferSampleCount < StartDelay )
		{
			
			DelayCounter += BufferSampleCount;
			
			Lock.Unlock ();
			
			return kStreamFillCode_Success_Silence;
			
		}
		else
			DelayOffset = StartDelay - DelayCounter;
		
	}
	
	uint64_t FillSize = FinishOffset - Offset;
	
	if ( BufferSampleCount < FillSize )
		FillSize = BufferSampleCount;
	
	Buffer -> ClearBufferInt ( TargetChannel, 0, DelayOffset );
	Buffer -> BlitBuffer ( * SourceData, Channel, FillSize - DelayOffset, Offset, DelayOffset, TargetChannel );
	
	if ( FillSize < BufferSampleCount )
		Buffer -> ClearBufferInt ( TargetChannel, 0, FillSize, BufferSampleCount - FillSize - DelayOffset );
	
	Offset += FillSize - DelayOffset;
	
	if ( Offset >= FinishOffset )
	{
		
		Playing = false;
		
		Util :: IFunction1 <void, RawBufferStreamSource *> * OnFinished = FinishedCallback;
		
		Lock.Unlock ();
		
		if ( OnFinished != NULL )
		{
			
			( * OnFinished ) ( this );
			
			if ( Playing )
				FillAudioBuffer ( Buffer, TargetChannel );
			
		}
		
		return kStreamFillCode_Success_Normal;
		
	}
	
	Lock.Unlock ();
	
	return kStreamFillCode_Success_Normal;
	
}

bool Red::Audio::RawBufferStreamSource :: IsPlaying ()
{
	
	Lock.Lock ();
	
	bool Temp = Playing;
	
	Lock.Unlock ();
	
	return Temp;
	
}
