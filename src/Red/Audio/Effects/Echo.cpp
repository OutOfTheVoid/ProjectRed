#include <Red/Audio/Effects/Echo.h>

#include <iostream>

Red::Audio::Effects::Echo :: Echo ( uint64_t Depth, IStreamSource * Input, float PassLevel, float EchoLevel, float Feedback, float FeedForward, uint64_t MaxBackSampleCount ):
	EchoBuffer ( NULL ),
	EchoDepth ( Depth ),
	EchoOffset ( 0 ),
	Input ( Input ),
	ExpectedFillSize ( 0 ),
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
	
	if ( EchoDepth > MaxBackSampleCount )
		MaxBackSampleCount = EchoDepth;
	
	EchoBuffer = new AudioBuffer ( Red::Audio :: kAudioBufferType_PerferredQuality, 1, MaxBackSampleCount * 2 );
	
	EchoBuffer -> ClearBufferFloat ( 0, EchoBuffer -> GetCenterValueFloat () );
	
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

void Red::Audio::Effects::Echo :: SetExpectedFillSize ( uint64_t FillSize )
{
	
	Lock.Lock ();
	
	this -> ExpectedFillSize = FillSize;
	
	if ( Input != NULL )
	{
		
		Lock.Unlock ();
		
		Input -> SetExpectedFillSize ( FillSize );
		
	}
	else
		Lock.Unlock ();
	
}

Red::Audio::IStreamSource :: StreamFillCode Red::Audio::Effects::Echo :: FillAudioBuffer ( AudioBuffer * Buffer, uint32_t TargetChannel )
{
	
	Lock.Lock ();
	
	IStreamSource :: StreamFillCode FillCode;
	
	if ( Input == NULL )
	{
		
		Lock.Unlock ();
		
		return kStreamFillCode_Failure_NoFill;
		
	}
	
	if ( Enabled == false )
	{
		
		FillCode = Input -> FillAudioBuffer ( Buffer, TargetChannel );
		
		Lock.Unlock ();
		
		return FillCode;
		
	}
	
	FillCode = Input -> FillAudioBuffer ( Buffer, TargetChannel );
	
	bool Silent = false;
	
	switch ( FillCode )
	{
		
		case kStreamFillCode_Success_Normal:
		case kStreamFillCode_Success_ControlParameter_Varying:
			break;
			
		case kStreamFillCode_Success_DC:
		case kStreamFillCode_Success_ControlParameter_Constant:
		{
			
			float Parameter = Buffer -> ReadSampleFloat ( TargetChannel, 0 );
			
			Buffer -> ClearBufferFloat ( TargetChannel, Parameter );
			
			Silent = ( Parameter == 0.0f ) || ( Parameter == - 0.0f );
			
		}
		break;
		
		case kStreamFillCode_Success_Silence:
		{
			
			Silent = true;
			
			Buffer -> ClearBufferFloat ( TargetChannel, Buffer -> GetCenterValueFloat () );
			
		}
		break;
		
		case kStreamFillCode_Failure_NoFill:
		case kStreamFillCode_Failure_Silence:
		default:
		{
			
			Buffer -> ClearBufferFloat ( TargetChannel, Buffer -> GetCenterValueFloat () );
			EchoBuffer -> ClearBufferFloat ( 0, EchoBuffer -> GetCenterValueFloat (), Buffer -> GetSampleCount (), EchoOffset + EchoDepth );
			
			Enabled = false;
			
			Lock.Unlock ();
			
			return FillCode;
			
		}
		
	}
	
	uint64_t EffectOffset = 0;
	uint64_t FillSize = Buffer -> GetSampleCount ();
	uint64_t EchoBuffSize = EchoBuffer -> GetSampleCount ();
	
	uint64_t EchoOffsetNext = ( EchoOffset + EchoDepth ) % EchoBuffSize;
	
	while ( EffectOffset < FillSize )
	{
	
		uint64_t PassSize = ( ( FillSize - EffectOffset ) < EchoDepth ) ? ( FillSize - EffectOffset ) : EchoDepth;
		
		bool EchoReadWraps = ( EchoOffset + PassSize ) > EchoBuffSize;
		bool EchoWriteWraps = ( EchoOffsetNext + PassSize ) > EchoBuffSize;
		
		if ( ( FeedForward != 0.0f ) && ( ! Silent ) )
		{
			
			EchoBuffer -> AddBufferScaled ( * Buffer, FeedForward, TargetChannel, PassSize, EffectOffset, EchoOffsetNext, 0 );
			if ( EchoWriteWraps )
				EchoBuffer -> AddBufferScaled ( * Buffer, FeedForward, TargetChannel, PassSize - ( EchoBuffSize - EchoOffsetNext ), EffectOffset + ( EchoBuffSize - EchoOffsetNext ), 0, 0 );
			
		}
		
		if ( PassLevel != 1.0f )
			Buffer -> ScaleBufferByConstant ( PassLevel, TargetChannel, PassSize, EffectOffset );
		
		if ( EchoLevel != 0.0f )
		{
			
			Buffer -> AddBufferScaled ( * EchoBuffer, EchoLevel, 0, PassSize, EchoOffset, EffectOffset, TargetChannel );
			if ( EchoReadWraps )
				Buffer -> AddBufferScaled ( * EchoBuffer, EchoLevel, 0, PassSize - ( EchoBuffSize - EchoOffset ), 0, EffectOffset + ( EchoBuffSize - EchoOffset ), TargetChannel );
			
		}
		
		if ( Feedback != 0.0f )
		{
			
			EchoBuffer -> AddBufferScaled ( * Buffer, Feedback, TargetChannel, PassSize, EffectOffset, EchoOffsetNext, 0 );
			if ( EchoWriteWraps )
				EchoBuffer -> AddBufferScaled ( * Buffer, Feedback, TargetChannel, PassSize - ( EchoBuffSize - EchoOffsetNext ), EffectOffset + ( EchoBuffSize - EchoOffsetNext ), 0, 0 );
			
		}
		
		EchoBuffer -> ClearBufferFloat ( 0, EchoBuffer -> GetCenterValueFloat (), EchoOffset, PassSize );
		if ( EchoReadWraps )
			EchoBuffer -> ClearBufferFloat ( 0, EchoBuffer -> GetCenterValueFloat (), 0, PassSize - ( EchoBuffSize - EchoOffset ) );
		
		EffectOffset += PassSize;
		EchoOffset += PassSize;
		EchoOffset %= EchoBuffSize;
		EchoOffsetNext = ( EchoOffset + EchoDepth ) % EchoBuffSize;
		
	}
	
	Lock.Unlock ();
	
	return kStreamFillCode_Success_Normal;
	
}

void Red::Audio::Effects::Echo :: SetInput ( IStreamSource * Input )
{
	
	Lock.Lock ();
	
	if ( this -> Input == Input )
	{
		
		Lock.Unlock ();
		
		return;
		
	}
	
	if ( this -> Input != NULL )
		this -> Input -> Dereference ();
	
	this -> Input = Input;
	
	if ( Input != NULL )
		Input -> Reference ();
	
	Lock.Unlock ();
	
}

void Red::Audio::Effects::Echo :: SetEchoDelay ( uint64_t SampleCount )
{
	
	Lock.Lock ();
	
	if ( SampleCount > MaxBackSampleCount )
	{
		
		MaxBackSampleCount = SampleCount;
		
		delete EchoBuffer;
		
		EchoBuffer = new AudioBuffer ( Red::Audio :: kAudioBufferType_PerferredQuality, 1, MaxBackSampleCount * 2 );
		EchoBuffer -> ClearBufferFloat ( 0, EchoBuffer -> GetCenterValueFloat () );
		
	}
	
	Lock.Unlock ();
	
}

void Red::Audio::Effects::Echo :: SetEnabled ( bool Enabled )
{
	
	Lock.Lock ();
	
	if ( ( ! this -> Enabled ) && Enabled )
		EchoBuffer -> ClearBufferFloat ( 0, EchoBuffer -> GetCenterValueFloat () );
	
	this -> Enabled = Enabled;
	
	Lock.Unlock ();
	
}

void Red::Audio::Effects::Echo :: SetCoefficients ( float PassLevel, float EchoLevel, float Feedback, float FeedForward )
{
	
	Lock.Lock ();
	
	this -> PassLevel = PassLevel;
	this -> EchoLevel = EchoLevel;
	this -> Feedback = Feedback;
	this -> FeedForward = FeedForward;
	
	Lock.Unlock ();
	
}
