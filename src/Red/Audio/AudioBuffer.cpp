#include <Red/Audio/AudioBuffer.h>

#include <Red/Util/SSE.h>

#include <stddef.h>
#include <string.h>

#include <iostream>

Red::Util :: Function1 <void, void *> Red::Audio::AudioBuffer :: StdFreeWrapper ( & free );

inline size_t GetSizeFromDataType ( Red::Audio :: AudioBufferType Type )
{
	
	switch ( Type )
	{
		
		case Red::Audio :: kAudioBufferType_Int8:
		case Red::Audio :: kAudioBufferType_UInt8:
			return sizeof ( uint8_t );
			
		case Red::Audio :: kAudioBufferType_Int16_LittleEndian:
		case Red::Audio :: kAudioBufferType_Int16_BigEndian:
		case Red::Audio :: kAudioBufferType_UInt16_LittleEndian:
		case Red::Audio :: kAudioBufferType_UInt16_BigEndian:
			return sizeof ( uint16_t );
			
		case Red::Audio :: kAudioBufferType_Int32_LittleEndian:
		case Red::Audio :: kAudioBufferType_Int32_BigEndian:
		case Red::Audio :: kAudioBufferType_UInt32_LittleEndian:
		case Red::Audio :: kAudioBufferType_UInt32_BigEndian:
		case Red::Audio :: kAudioBufferType_Float32_LittleEndian:
		case Red::Audio :: kAudioBufferType_Float32_BigEndian:
			return sizeof ( uint32_t );
		
	}
	
	return 0;
	
}

Red::Audio::AudioBuffer :: AudioBuffer ( void * Data, AudioBufferType Type, uint32_t Channels, uint32_t SampleCount, Util :: IFunction1 <void, void *> * OnFree ):
	RefCounted (),
	Data ( Data ),
	DataType ( Type ),
	ChannelCount ( Channels ),
	SampleCount ( SampleCount ),
	OnFree ( OnFree )
{
}

Red::Audio::AudioBuffer :: ~AudioBuffer ()
{
	
	if ( OnFree != NULL )
		( * OnFree ) ( Data );
	
	Data = NULL;
	
}

Red::Audio :: AudioBuffer * Red::Audio::AudioBuffer :: CopyReformated ( AudioBuffer & Source, AudioBufferType NewDataType, uint32_t NewChannelCount )
{
	
	void * NewData = malloc ( GetSizeFromDataType ( NewDataType ) );
	
	if ( NewData == NULL )
		return NULL;
	
	AudioBuffer * NewBuffer = new AudioBuffer ( NewData, NewDataType, NewChannelCount, Source.SampleCount, & StdFreeWrapper );
	
	uint32_t LeastTotalChannels = ( Source.ChannelCount < NewChannelCount ) ? Source.ChannelCount : NewChannelCount;
	
	uint32_t Channel;
	
	for ( Channel = 0; Channel < LeastTotalChannels; Channel ++ )
		NewBuffer -> BlitBuffer ( Source, Channel, Source.SampleCount, 0, 0 );
	
	if ( ( NewDataType == kAudioBufferType_Float32_LittleEndian ) || ( NewDataType == kAudioBufferType_Float32_BigEndian ) )
		for ( ; Channel < NewChannelCount; Channel ++ )
			NewBuffer -> ClearBufferFloat ( Channel, 0.0f );
	else
		for ( ; Channel < NewChannelCount; Channel ++ )
			NewBuffer -> ClearBufferInt ( Channel, 0 );
	
	return NewBuffer;
	
}

Red::Audio :: AudioBuffer * Red::Audio::AudioBuffer :: CopyReformatedResampled ( AudioBuffer & Source, AudioBufferType NewDataType, uint32_t NewChannelCount, float SampleRatio )
{
	
	(void) Source;
	(void) NewDataType;
	(void) NewChannelCount;
	(void) SampleRatio;
	
	// TODO: Implement
	
	return NULL;
	
}

void * Red::Audio::AudioBuffer :: GetRawBuffer ()
{
	
	return Data;
	
}

Red::Audio :: AudioBufferType Red::Audio::AudioBuffer :: GetDataType ()
{
	
	return DataType;
	
}

uint32_t Red::Audio::AudioBuffer :: GetChannelCount ()
{
	
	return ChannelCount;
	
}

uint32_t Red::Audio::AudioBuffer :: GetSampleCount ()
{
	
	return SampleCount;
	
}

void Red::Audio::AudioBuffer :: BlitBuffer ( AudioBuffer & Source, uint32_t SourceChannel, uint32_t SampleCount, uint32_t SourceStartSample, uint32_t TargetStartSample, uint32_t TargetChannel )
{
	
	uint32_t I;
	
	if ( TargetChannel == 0xFFFFFFFF )
		TargetChannel = SourceChannel;
	
	if ( TargetChannel >= ChannelCount )
		return;
	
	if ( SourceChannel >= Source.ChannelCount )
		return;
	
	if ( DataType == Source.DataType )
	{
		
		size_t TypeSize = GetSizeFromDataType ( DataType );
		
		if ( ( Source.ChannelCount == 1 ) && ( ChannelCount == 1 ) )
			memcpy ( reinterpret_cast <void *> ( & ( reinterpret_cast <uint8_t *> ( Data ) [ TypeSize * TargetStartSample ] ) ), reinterpret_cast <const void *> ( & ( reinterpret_cast <uint8_t *> ( Source.Data ) [ TypeSize * SourceStartSample ] ) ), TypeSize * SampleCount );
		else
		{
			
			switch ( TypeSize )
			{
				
				case sizeof ( uint8_t ):
				{
					
					for ( I = 0; I < SampleCount; I ++ )
						reinterpret_cast <uint8_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = reinterpret_cast <uint8_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + I ) + SourceChannel ];
					
				}
				break;
				
				case sizeof ( uint16_t ):
				{
					
					for ( I = 0; I < SampleCount; I ++ )
						reinterpret_cast <uint16_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = reinterpret_cast <uint16_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + I ) + SourceChannel ];
					
				}
				break;
				
				case sizeof ( uint32_t ):
				{
					
					for ( I = 0; I < SampleCount; I ++ )
						reinterpret_cast <uint32_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = reinterpret_cast <uint32_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + I ) + SourceChannel ];
					
				}
				break;
				
				default:
					return;
				
			}
			
		}
		
	}
	else
	{
		
		// TODO: Implement buffer format conversion
		
	}
	
}

void Red::Audio::AudioBuffer :: BlitBufferResampled ( AudioBuffer & Source, uint32_t Channel, uint32_t SampleCount, uint32_t SourceStartSample, uint32_t TargetStartSample, float SampleRatio, uint32_t TargetChannel )
{
	
	(void) Source;
	(void) Channel;
	(void) SampleCount;
	(void) SourceStartSample;
	(void) TargetStartSample;
	(void) TargetChannel;
	(void) SampleRatio;
	
	// TODO: Implement
	
}

void Red::Audio::AudioBuffer :: AddBuffer ( AudioBuffer & Source, uint32_t SourceChannel, uint32_t SampleCount, uint32_t SourceStartSample, uint32_t TargetStartSample, uint32_t TargetChannel )
{
	
	(void) Source;
	(void) SourceChannel;
	(void) SampleCount;
	(void) SourceStartSample;
	(void) TargetStartSample;
	(void) TargetChannel;
	
	// TODO: Implement
	
}

void Red::Audio::AudioBuffer :: AddBufferResampled ( AudioBuffer & Source, uint32_t SourceChannel, uint32_t SampleCount, uint32_t SourceStartSample, uint32_t TargetStartSample, uint32_t TargetChannel, float SampleRatio )
{
	
	(void) Source;
	(void) SourceChannel;
	(void) SampleCount;
	(void) SourceStartSample;
	(void) TargetStartSample;
	(void) TargetChannel;
	(void) SampleRatio;
	
	// TODO: Implement
	
}

void Red::Audio::AudioBuffer :: ClearBufferFloat ( uint32_t Channel, float Value )
{
	
	(void) Channel;
	(void) Value;
	
	// TODO: Implement
	
}

void Red::Audio::AudioBuffer :: ClearBufferInt ( uint32_t Channel, int32_t Value )
{
	
	if ( Channel >= ChannelCount )
		return;
	
	uint32_t I;
	
	// TODO: Implement
	
	switch ( DataType )
	{
		
		case kAudioBufferType_Int8:
		{
			
			if ( ChannelCount == 1 )
				memset ( reinterpret_cast <char *> ( Data ), static_cast <char> ( static_cast <int8_t> ( Value ) ), SampleCount );
			else
				for ( I = 0; I < SampleCount; I ++ )
					reinterpret_cast <int8_t *> ( Data ) [ I * ChannelCount + Channel ] = static_cast <int8_t> ( Value );
			
		}
		
		case kAudioBufferType_UInt8:
		{
			
			if ( ChannelCount == 1 )
				memset ( reinterpret_cast <char *> ( Data ), static_cast <char> ( static_cast <uint8_t> ( Value ) ), SampleCount );
			else
				for ( I = 0; I < SampleCount; I ++ )
					reinterpret_cast <uint8_t *> ( Data ) [ I * ChannelCount + Channel ] = static_cast <uint8_t> ( Value );
			
		}
		
		/*
		
		case kAudioBufferType_Int16_LittleEndian:
		{
			
			uint16_t Value = 
			
			for ( I = 0; I < SampleCount; I ++ )
				reinterpret_cast <int8_t *> ( Data ) [ I * ChannelCount + Channel ] = static_cast <int8_t> ( Value );
			
		}
		
		case kAudioBufferType_UInt16_LittleEndian:
		{
			
			if ( ChannelCount == 1 )
				memset ( reinterpret_cast <char *> ( Data ), static_cast <char> ( static_cast <uint8_t> ( Value ) ), SampleCount );
			else
				for ( I = 0; I < SampleCount; I ++ )
					reinterpret_cast <uint8_t *> ( Data ) [ I * ChannelCount + Channel ] = static_cast <uint8_t> ( Value );
			
		}*/
		
		default:
			break;
		
	}
	
}