#include <Red/Audio/AudioBuffer.h>

#include <Red/Util/SSE.h>
#include <Red/Util/Endian.h>

#include <stddef.h>
#include <string.h>
#include <math.h>

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
	
	void * NewData = malloc ( GetSizeFromDataType ( NewDataType ) * Source.SampleCount );
	
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

Red::Audio :: AudioBuffer * Red::Audio::AudioBuffer :: CopyReformatedResampled ( AudioBuffer & Source, ResampleMode Mode, AudioBufferType NewDataType, uint32_t NewChannelCount, float SampleRatio )
{
	
	uint32_t NewSampleCount = static_cast <uint32_t> ( ceil ( static_cast <float> ( Source.SampleCount ) * SampleRatio ) );
	void * NewData = malloc ( GetSizeFromDataType ( NewDataType ) * NewSampleCount );
	
	if ( NewData == NULL )
		return NULL;
	
	AudioBuffer * NewBuffer = new AudioBuffer ( NewData, NewDataType, NewChannelCount, NewSampleCount, & StdFreeWrapper );
	
	uint32_t LeastTotalChannels = ( Source.ChannelCount < NewChannelCount ) ? Source.ChannelCount : NewChannelCount;
	
	uint32_t Channel;
	
	for ( Channel = 0; Channel < LeastTotalChannels; Channel ++ )
		NewBuffer -> BlitBufferResampled ( Source, Mode, Channel, NewSampleCount, 0, 0, SampleRatio );
	
	if ( ( NewDataType == kAudioBufferType_Float32_LittleEndian ) || ( NewDataType == kAudioBufferType_Float32_BigEndian ) )
		for ( ; Channel < NewChannelCount; Channel ++ )
			NewBuffer -> ClearBufferFloat ( Channel, 0.0f );
	else
		for ( ; Channel < NewChannelCount; Channel ++ )
			NewBuffer -> ClearBufferInt ( Channel, 0 );
	
	return NewBuffer;
	
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

inline int16_t _AB_Alias_U16ToI16 ( const uint16_t RValue )
{
	
	return * reinterpret_cast <const int16_t *> ( & RValue );
	
}

inline uint16_t _AB_Alias_I16ToU16 ( const int16_t RValue )
{
	
	return * reinterpret_cast <const uint16_t *> ( & RValue );
	
}

inline int32_t _AB_Alias_U32ToI32 ( const uint32_t RValue )
{
	
	return * reinterpret_cast <const int32_t *> ( & RValue );
	
}

inline uint32_t _AB_Alias_I32ToU32 ( const int32_t RValue )
{
	
	return * reinterpret_cast <const uint32_t *> ( & RValue );
	
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
		
		#define _BLITBUFFER_ABSOURCEDATA_INT8 static_cast <int32_t> ( reinterpret_cast <int8_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + I ) + SourceChannel ] )
		#define _BLITBUFFER_ABSOURCEDATA_UINT8 static_cast <uint32_t> ( reinterpret_cast <uint8_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + I ) + SourceChannel ] )
		#define _BLITBUFFER_ABSOURCEDATA_INT16_LE static_cast <int32_t> ( _AB_Alias_U16ToI16 ( LittleToHostEndian16 ( reinterpret_cast <uint16_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + I ) + SourceChannel ] ) ) )
		#define _BLITBUFFER_ABSOURCEDATA_INT16_BE static_cast <int32_t> ( _AB_Alias_U16ToI16 ( BigToHostEndian16 ( reinterpret_cast <uint16_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + I ) + SourceChannel ] ) ) )
		#define _BLITBUFFER_ABSOURCEDATA_UINT16_LE static_cast <uint32_t> ( LittleToHostEndian16 ( reinterpret_cast <uint16_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + I ) + SourceChannel ] ) )
		#define _BLITBUFFER_ABSOURCEDATA_UINT16_BE static_cast <uint32_t> ( BigToHostEndian16 ( reinterpret_cast <uint16_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + I ) + SourceChannel ] ) )
		#define _BLITBUFFER_ABSOURCEDATA_INT32_LE _AB_Alias_U32ToI32 ( LittleToHostEndian32 ( reinterpret_cast <uint32_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + I ) + SourceChannel ] ) )
		#define _BLITBUFFER_ABSOURCEDATA_INT32_BE _AB_Alias_U32ToI32 ( BigToHostEndian32 ( reinterpret_cast <uint32_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + I ) + SourceChannel ] ) )
		#define _BLITBUFFER_ABSOURCEDATA_UINT32_LE LittleToHostEndian32 ( reinterpret_cast <uint32_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + I ) + SourceChannel ] )
		#define _BLITBUFFER_ABSOURCEDATA_UINT32_BE BigToHostEndian32 ( reinterpret_cast <uint32_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + I ) + SourceChannel ] )
		#define _BLITBUFFER_ABSOURCEDATA_FLOAT32_LE LittleToHostEndianFloat ( reinterpret_cast <float *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + I ) + SourceChannel ] )
		#define _BLITBUFFER_ABSOURCEDATA_FLOAT32_BE BigToHostEndianFloat ( reinterpret_cast <float *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + I ) + SourceChannel ] )
		
		
		#define _BLITBUFFER_ABDESTDATA_INT8(x) reinterpret_cast <uint8_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = static_cast <int8_t> ( x )
		#define _BLITBUFFER_ABDESTDATA_UINT8(x) reinterpret_cast <uint8_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = static_cast <uint8_t> ( x )
		#define _BLITBUFFER_ABDESTDATA_INT16_LE(x) reinterpret_cast <int16_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = /*_AB_Alias_U16ToI16*/ ( /*HostToLittleEndian16*/ ( /*_AB_Alias_I16ToU16*/ ( static_cast <int16_t> ( static_cast <int32_t> ( x ) ) ) ) )
		#define _BLITBUFFER_ABDESTDATA_INT16_BE(x) reinterpret_cast <int16_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = _AB_Alias_U16ToI16 ( HostToBigEndian16 ( _AB_Alias_I16ToU16 ( static_cast <int16_t> ( x ) ) ) )
		#define _BLITBUFFER_ABDESTDATA_UINT16_LE(x) reinterpret_cast <uint16_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = HostToLittleEndian16 ( static_cast <uint16_t> ( x ) )
		#define _BLITBUFFER_ABDESTDATA_UINT16_BE(x) reinterpret_cast <uint16_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = HostToBigEndian16 ( static_cast <uint16_t> ( x ) )
		#define _BLITBUFFER_ABDESTDATA_INT32_LE(x) reinterpret_cast <int32_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = _AB_Alias_U32ToI32 ( HostToLittleEndian32 ( _AB_Alias_I32ToU32 ( static_cast <int32_t> ( x ) ) ) )
		#define _BLITBUFFER_ABDESTDATA_INT32_BE(x) reinterpret_cast <int32_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = _AB_Alias_U32ToI32 ( HostToBigEndian32 ( _AB_Alias_I32ToU32 ( static_cast <int32_t> ( x ) ) ) )
		#define _BLITBUFFER_ABDESTDATA_UINT32_LE(x) reinterpret_cast <uint32_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = HostToLittleEndian32 ( static_cast <uint32_t> ( x ) )
		#define _BLITBUFFER_ABDESTDATA_UINT32_BE(x) reinterpret_cast <uint32_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = HostToBigEndian32 ( static_cast <uint32_t> ( x ) )
		#define _BLITBUFFER_ABDESTDATA_FLOAT32_LE(x) reinterpret_cast <float *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = HostToLittleEndianFloat ( static_cast <float> ( x ) )
		#define _BLITBUFFER_ABDESTDATA_FLOAT32_BE(x) reinterpret_cast <float *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = HostToBigEndianFloat ( static_cast <float> ( x ) )
		
		switch ( DataType )
		{
			
			case kAudioBufferType_Int8:
			{
				
				switch ( Source.DataType )
				{
					
	
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT8 ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT8 ) - 0x80 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT8 ( _BLITBUFFER_ABSOURCEDATA_INT16_LE >> 8 ); // TODO: Fix clipping caused by down-conversion mapping to -128 to 128 by finding a way to map to -128 to 127
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT8 ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_INT16_BE ) / 0x100 );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT8 ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT16_LE >> 8 ) - 0x80 );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT8 ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT16_BE >> 8 ) - 0x80 );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT8 ( _BLITBUFFER_ABSOURCEDATA_INT32_LE / 0x1000000 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT8 ( _BLITBUFFER_ABSOURCEDATA_INT32_BE / 0x1000000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT8 ( ( _BLITBUFFER_ABSOURCEDATA_UINT32_LE >> 24 ) - 0x80 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT8 ( ( _BLITBUFFER_ABSOURCEDATA_UINT32_BE >> 24 ) - 0x80 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT8 ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_LE * 127.5 - 0.5 );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT8 ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_BE * 127.5 - 0.5 );
						
					}
					break;
					
					default:
						break;
					
				}
				
			}
			break;
			
			case kAudioBufferType_UInt8:
			{
				
				switch ( Source.DataType )
				{
					
	
					case kAudioBufferType_Int8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT8 ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_INT8 ) + 0x80 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT8 ( static_cast <uint32_t> ( _BLITBUFFER_ABSOURCEDATA_INT16_LE + 0x8000 ) >> 8 );
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT8 ( static_cast <uint32_t> ( _BLITBUFFER_ABSOURCEDATA_INT16_BE + 0x8000 ) >> 8 );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT8 ( _BLITBUFFER_ABSOURCEDATA_UINT16_LE >> 8 );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT8 ( _BLITBUFFER_ABSOURCEDATA_UINT16_BE >> 8 );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT8 ( ( static_cast <uint32_t> ( _BLITBUFFER_ABSOURCEDATA_INT32_LE ) + 0x80000000 ) >> 24 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT8 ( ( static_cast <uint32_t> ( _BLITBUFFER_ABSOURCEDATA_INT32_BE ) + 0x80000000 ) >> 24 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT8 ( _BLITBUFFER_ABSOURCEDATA_UINT32_LE >> 24 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT8 ( _BLITBUFFER_ABSOURCEDATA_UINT32_BE >> 24 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT8 ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_LE + 1.0 ) * 127.5 );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT8 ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_BE + 1.0 ) * 127.5 );
						
					}
					break;
					
					default:
						break;
					
				}
				
			}
			break;
			
			case kAudioBufferType_Int16_LittleEndian:
			{
				
				switch ( Source.DataType )
				{
					
	
					case kAudioBufferType_Int8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT16_LE ( _BLITBUFFER_ABSOURCEDATA_INT8 * 0x100 );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT8 << 8 ) - 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT16_LE ( _BLITBUFFER_ABSOURCEDATA_INT16_BE );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT16_LE ) - 0x8000 );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT16_BE ) - 0x8000 );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT16_LE ( _BLITBUFFER_ABSOURCEDATA_INT32_LE / 0x10000 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT16_LE ( _BLITBUFFER_ABSOURCEDATA_INT32_BE / 0x10000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT32_LE >> 16 ) - 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT32_BE >> 16 ) - 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT16_LE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_LE * 32767.5f ) - 0.5f );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT16_LE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_BE * 32767.5 ) - 0.5 );
						
					}
					break;
					
					default:
						break;
					
				}
				
			}
			break;
			
			case kAudioBufferType_Int16_BigEndian:
			{
				
				switch ( Source.DataType )
				{
					
	
					case kAudioBufferType_Int8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT16_BE ( _BLITBUFFER_ABSOURCEDATA_INT8 * 0x100 );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT8 << 8 ) - 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT16_BE ( _BLITBUFFER_ABSOURCEDATA_INT16_LE );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT16_LE ) - 0x8000 );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT16_BE ) - 0x8000 );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT16_BE ( _BLITBUFFER_ABSOURCEDATA_INT32_LE / 0x10000 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT16_BE ( _BLITBUFFER_ABSOURCEDATA_INT32_BE / 0x10000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT32_LE >> 16 ) - 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT32_BE >> 16 ) - 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT16_BE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_LE * 32767.5 ) - 0.5 );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT16_BE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_BE * 32767.5 ) - 0.5 );
						
					}
					break;
					
					default:
						break;
					
				}
				
			}
			break;
			
			case kAudioBufferType_UInt16_LittleEndian:
			{
				
				switch ( Source.DataType )
				{
					
	
					case kAudioBufferType_Int8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT16_LE ( static_cast <uint16_t> ( static_cast <int16_t> ( _BLITBUFFER_ABSOURCEDATA_INT8 ) + 0x80 ) << 8 );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT16_LE ( _BLITBUFFER_ABSOURCEDATA_UINT8 << 8 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT16_LE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_INT16_LE ) + 0x8000 );
							
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT16_LE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_INT16_BE ) + 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT16_LE ( _BLITBUFFER_ABSOURCEDATA_UINT16_BE );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT16_LE ( ( _BLITBUFFER_ABSOURCEDATA_INT32_LE / 0x10000 ) + 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT16_LE ( ( _BLITBUFFER_ABSOURCEDATA_INT32_BE / 0x10000 ) + 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT16_LE ( _BLITBUFFER_ABSOURCEDATA_UINT32_LE >> 16 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT16_LE ( _BLITBUFFER_ABSOURCEDATA_UINT32_BE >> 16 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT16_LE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_LE + 1.0 ) * 32767.5 );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT16_LE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_BE + 1.0 ) * 32767.5 );
						
					}
					break;
					
					default:
						break;
					
				}
				
			}
			break;
			
			case kAudioBufferType_UInt16_BigEndian:
			{
				
				switch ( Source.DataType )
				{
					
	
					case kAudioBufferType_Int8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT16_BE ( static_cast <uint16_t> ( static_cast <int16_t> ( _BLITBUFFER_ABSOURCEDATA_INT8 ) + 0x80 ) << 8 );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT16_BE ( _BLITBUFFER_ABSOURCEDATA_UINT8 << 8 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT16_BE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_INT16_LE ) + 0x8000 );
							
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT16_BE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_INT16_BE ) + 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT16_BE ( _BLITBUFFER_ABSOURCEDATA_UINT16_BE );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT16_BE ( ( _BLITBUFFER_ABSOURCEDATA_INT32_LE / 0x10000 ) + 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT16_BE ( ( _BLITBUFFER_ABSOURCEDATA_INT32_BE / 0x10000 ) + 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT16_BE ( _BLITBUFFER_ABSOURCEDATA_UINT32_LE >> 16 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT16_BE ( _BLITBUFFER_ABSOURCEDATA_UINT32_BE >> 16 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT16_BE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_LE + 1.0 ) * 32767.5 );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT16_BE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_BE + 1.0 ) * 32767.5 );
						
					}
					break;
					
					default:
						break;
					
				}
				
			}
			break;
			
			case kAudioBufferType_Int32_LittleEndian:
			{
				
				switch ( Source.DataType )
				{
					
	
					case kAudioBufferType_Int8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT32_LE ( _BLITBUFFER_ABSOURCEDATA_INT8 * 0x1000000 );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT32_LE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT8 << 24 ) - 0x800000 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT32_LE ( _BLITBUFFER_ABSOURCEDATA_INT16_LE * 0x10000 );
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT32_LE ( _BLITBUFFER_ABSOURCEDATA_INT16_BE * 0x10000 );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT32_LE ( ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT16_LE ) - 0x8000 ) * 0x10000 );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT32_LE ( ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT16_BE ) - 0x8000 ) * 0x10000 );
							
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT32_LE ( _BLITBUFFER_ABSOURCEDATA_INT32_BE );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT32_LE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT32_LE ) - 0x80000000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT32_LE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT32_BE ) - 0x80000000 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT32_LE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_BE * 2147483647.5 ) - 0.5 );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT32_LE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_BE * 2147483647.5 ) - 0.5 );
						
					}
					break;
					
					default:
						break;
					
				}
				
			}
			break;
			
			case kAudioBufferType_Int32_BigEndian:
			{
				
				switch ( Source.DataType )
				{
					
	
					case kAudioBufferType_Int8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT32_BE ( _BLITBUFFER_ABSOURCEDATA_INT8 * 0x1000000 );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT32_BE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT8 << 24 ) - 0x800000 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT32_BE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_INT16_LE ) * 0x1000 );
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT32_BE ( _BLITBUFFER_ABSOURCEDATA_INT16_BE * 0x10000 );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT32_BE ( ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT16_LE ) - 0x8000 ) * 0x10000 );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT32_BE ( ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT16_BE ) - 0x8000 ) * 0x10000 );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT32_BE ( _BLITBUFFER_ABSOURCEDATA_INT32_LE );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT32_BE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT32_LE ) - 0x80000000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT32_BE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT32_BE ) - 0x80000000 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT32_BE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_LE * 2147483647.5 ) - 0.5 );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_INT32_BE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_BE * 2147483647.5 ) - 0.5 );
						
					}
					break;
					
					default:
						break;
					
				}
				
			}
			break;
			
			case kAudioBufferType_UInt32_LittleEndian:
			{
				
				switch ( Source.DataType )
				{
					
	
					case kAudioBufferType_Int8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT32_LE ( static_cast <uint32_t> ( _BLITBUFFER_ABSOURCEDATA_INT8 + 0x80 ) << 24 );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT32_LE ( _BLITBUFFER_ABSOURCEDATA_UINT8 << 24 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT32_LE ( static_cast <uint32_t> ( _BLITBUFFER_ABSOURCEDATA_INT16_LE + 0x8000 ) << 16 );
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT32_LE ( static_cast <uint32_t> ( _BLITBUFFER_ABSOURCEDATA_INT16_BE + 0x8000 ) << 16 );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT32_LE ( _BLITBUFFER_ABSOURCEDATA_UINT16_LE << 16 );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT32_LE ( _BLITBUFFER_ABSOURCEDATA_UINT16_BE << 16 );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT32_LE ( _BLITBUFFER_ABSOURCEDATA_INT32_LE + 0x80000000 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT32_LE ( _BLITBUFFER_ABSOURCEDATA_INT32_BE + 0x80000000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT32_LE ( _BLITBUFFER_ABSOURCEDATA_UINT32_BE );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT32_LE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_LE + 1.0 ) * 2147483647.5 );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT32_LE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_BE + 1.0 ) * 2147483647.5 );
						
					}
					break;
					
					default:
						break;
					
				}
				
			}
			break;
			
			case kAudioBufferType_UInt32_BigEndian:
			{
				
				switch ( Source.DataType )
				{
					
	
					case kAudioBufferType_Int8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT32_BE ( static_cast <uint32_t> ( _BLITBUFFER_ABSOURCEDATA_INT8 + 0x80 ) << 24 );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT32_BE ( _BLITBUFFER_ABSOURCEDATA_UINT8 << 24 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT32_BE ( static_cast <uint32_t> ( _BLITBUFFER_ABSOURCEDATA_INT16_LE + 0x8000 ) << 16 );
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT32_BE ( static_cast <uint32_t> ( _BLITBUFFER_ABSOURCEDATA_INT16_BE + 0x8000 ) << 16 );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT32_BE ( _BLITBUFFER_ABSOURCEDATA_UINT16_LE << 16 );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT32_BE ( _BLITBUFFER_ABSOURCEDATA_UINT16_BE << 16 );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT32_BE ( _BLITBUFFER_ABSOURCEDATA_INT32_LE + 0x80000000 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT32_BE ( _BLITBUFFER_ABSOURCEDATA_INT32_BE + 0x80000000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT32_BE ( _BLITBUFFER_ABSOURCEDATA_UINT32_LE );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT32_BE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_LE + 1.0 ) * 2147483647.5f );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT32_BE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_BE + 1.0 ) * 2147483647.5f );
						
					}
					break;
					
					default:
						break;
					
				}
				
			}
			break;
			
			case kAudioBufferType_Float32_LittleEndian:
			{
				
				switch ( Source.DataType )
				{
					
	
					case kAudioBufferType_Int8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_FLOAT32_LE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_INT8 ) + 0.5f ) * 0.00784313725f );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_FLOAT32_LE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_INT8 ) - 127.5f ) * 0.00784313725f );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_FLOAT32_LE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_INT16_LE ) + 0.5f ) * 0.00003051804f );
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_FLOAT32_LE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_INT16_BE ) + 0.5f ) * 0.00003051804f );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_FLOAT32_LE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_UINT16_LE ) - 32767.5 ) * 0.00003051804f );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_FLOAT32_LE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_UINT16_BE ) - 32767.5 ) * 0.00003051804f );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ ) // The center shift here is pointless as a float32 has only 23 fraction bits
							_BLITBUFFER_ABDESTDATA_FLOAT32_LE ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_INT32_LE ) * 4.6566129e-10 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ ) // The center shift here is pointless as a float32 has only 23 fraction bits
							_BLITBUFFER_ABDESTDATA_FLOAT32_LE ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_INT32_BE ) * 4.6566129e-10 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ ) // The center shift here is pointless as a float32 has only 23 fraction bits
							_BLITBUFFER_ABDESTDATA_FLOAT32_LE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_UINT32_LE ) - 2147483647.5f ) * 4.6566129e-10 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_FLOAT32_LE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_UINT32_BE ) - 2147483647.5f ) * 4.6566129e-10 );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_FLOAT32_LE ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_BE );
						
					}
					break;
					
					default:
						break;
					
				}
				
			}
			break;
			
			case kAudioBufferType_Float32_BigEndian:
			{
				
				switch ( Source.DataType )
				{
					
	
					case kAudioBufferType_Int8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_FLOAT32_BE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_INT8 ) + 0.5f ) * 0.00784313725f );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_FLOAT32_BE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_INT8 ) - 127.5f ) * 0.00784313725f );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_FLOAT32_BE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_INT16_LE ) + 0.5f ) * 0.00003051804f );
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_FLOAT32_BE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_INT16_BE ) + 0.5f ) * 0.00003051804f );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_FLOAT32_BE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_UINT16_LE ) - 32767.5 ) * 0.00003051804f );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_FLOAT32_BE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_UINT16_BE ) - 32767.5 ) * 0.00003051804f );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ ) // The center shift here is pointless as a float32 has only 23 fraction bits
							_BLITBUFFER_ABDESTDATA_FLOAT32_BE ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_INT32_LE ) * 4.6566129e-10 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ ) // The center shift here is pointless as a float32 has only 23 fraction bits
							_BLITBUFFER_ABDESTDATA_FLOAT32_BE ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_INT32_BE ) * 4.6566129e-10 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ ) // The center shift here is pointless as a float32 has only 23 fraction bits
							_BLITBUFFER_ABDESTDATA_FLOAT32_BE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_UINT32_LE ) - 2147483647.5f ) * 4.6566129e-10 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_FLOAT32_BE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_UINT32_BE ) - 2147483647.5f ) * 4.6566129e-10 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_FLOAT32_BE ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_LE );
						
					}
					break;
					
					default:
						break;
					
				}
				
			}
			break;
			
			default:
				break;
			
		}
		
	}
	
}

void Red::Audio::AudioBuffer :: BlitBufferResampled ( AudioBuffer & Source, ResampleMode Mode, uint32_t Channel, uint32_t SampleCount, uint32_t SourceStartSample, uint32_t TargetStartSample, float SampleRatio, uint32_t TargetChannel )
{
	
	(void) Source;
	(void) Mode;
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

void Red::Audio::AudioBuffer :: AddBufferResampled ( AudioBuffer & Source, ResampleMode Mode, uint32_t SourceChannel, uint32_t SampleCount, uint32_t SourceStartSample, uint32_t TargetStartSample, uint32_t TargetChannel, float SampleRatio )
{
	
	(void) Source;
	(void) Mode;
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
	
	(void) Value;
	
	if ( Channel > ChannelCount )
		return;
	
	uint32_t I = 0;
	
	switch ( DataType )
	{
		
		case kAudioBufferType_Float32_LittleEndian:
		{
			
			float CValue = HostToLittleEndianFloat ( Value );
			
			for ( I = 0; I < SampleCount; I ++ )
				reinterpret_cast <float *> ( Data ) [ I * ChannelCount + Channel ] = CValue;
			
		}
		break;
		
		case kAudioBufferType_Float32_BigEndian:
		{
			
			float CValue = HostToBigEndianFloat ( Value );
			
			for ( I = 0; I < SampleCount; I ++ )
				reinterpret_cast <float *> ( Data ) [ I * ChannelCount + Channel ] = CValue;
			
		}
		break;
		
		case kAudioBufferType_Int8:
		case kAudioBufferType_UInt8:
		case kAudioBufferType_Int16_LittleEndian:
		case kAudioBufferType_Int16_BigEndian:
		case kAudioBufferType_UInt16_LittleEndian:
		case kAudioBufferType_UInt16_BigEndian:
		case kAudioBufferType_Int32_LittleEndian:
		case kAudioBufferType_Int32_BigEndian:
		case kAudioBufferType_UInt32_LittleEndian:
		case kAudioBufferType_UInt32_BigEndian:
			return ClearBufferInt ( Channel, static_cast <int64_t> ( Value ) );
			
		default:
			return;
		
	}
	
}

void Red::Audio::AudioBuffer :: ClearBufferInt ( uint32_t Channel, int64_t Value )
{
	
	if ( Channel >= ChannelCount )
		return;
	
	uint32_t I;
	
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
		break;
		
		case kAudioBufferType_UInt8:
		{
			
			if ( ChannelCount == 1 )
				memset ( reinterpret_cast <char *> ( Data ), static_cast <char> ( static_cast <uint8_t> ( Value ) ), SampleCount );
			else
				for ( I = 0; I < SampleCount; I ++ )
					reinterpret_cast <uint8_t *> ( Data ) [ I * ChannelCount + Channel ] = static_cast <uint8_t> ( Value );
			
		}
		break;
		
		case kAudioBufferType_Int16_LittleEndian:
		{
			
			uint16_t CValue = HostToLittleEndian16 ( _AB_Alias_I16ToU16 ( static_cast <int16_t> ( Value ) ) );
			
			for ( I = 0; I < SampleCount; I ++ )
				reinterpret_cast <uint16_t *> ( Data ) [ I * ChannelCount + Channel ] = CValue;
			
		}
		break;
		
		case kAudioBufferType_Int16_BigEndian:
		{
			
			uint16_t CValue = HostToBigEndian16 ( _AB_Alias_I16ToU16 ( static_cast <int16_t> ( Value ) ) );
			
			for ( I = 0; I < SampleCount; I ++ )
				reinterpret_cast <uint16_t *> ( Data ) [ I * ChannelCount + Channel ] = CValue;
			
		}
		break;
		
		case kAudioBufferType_UInt16_LittleEndian:
		{
			
			uint16_t CValue = HostToLittleEndian16 ( static_cast <uint16_t> ( Value ) );
			
			for ( I = 0; I < SampleCount; I ++ )
				reinterpret_cast <uint16_t *> ( Data ) [ I * ChannelCount + Channel ] = CValue;
			
		}
		break;
		
		case kAudioBufferType_UInt16_BigEndian:
		{
			
			uint16_t CValue = HostToBigEndian16 ( static_cast <uint16_t> ( Value ) );
			
			for ( I = 0; I < SampleCount; I ++ )
				reinterpret_cast <uint16_t *> ( Data ) [ I * ChannelCount + Channel ] = CValue;
			
		}
		break;
		
		case kAudioBufferType_Int32_LittleEndian:
		{
			
			uint32_t CValue = HostToLittleEndian32 ( _AB_Alias_I32ToU32 ( static_cast <int32_t> ( Value ) ) );
			
			for ( I = 0; I < SampleCount; I ++ )
				reinterpret_cast <uint32_t *> ( Data ) [ I * ChannelCount + Channel ] = CValue;
			
		}
		break;
		
		case kAudioBufferType_Int32_BigEndian:
		{
			
			uint32_t CValue = HostToBigEndian32 ( _AB_Alias_I32ToU32 ( static_cast <int32_t> ( Value ) ) );
			
			for ( I = 0; I < SampleCount; I ++ )
				reinterpret_cast <uint32_t *> ( Data ) [ I * ChannelCount + Channel ] = CValue;
			
		}
		break;
		
		case kAudioBufferType_UInt32_LittleEndian:
		{
			
			uint32_t CValue = HostToLittleEndian32 ( static_cast <uint32_t> ( Value ) );
			
			for ( I = 0; I < SampleCount; I ++ )
				reinterpret_cast <uint32_t *> ( Data ) [ I * ChannelCount + Channel ] = CValue;
			
		}
		break;
		
		case kAudioBufferType_UInt32_BigEndian:
		{
			
			uint32_t CValue = HostToBigEndian32 ( static_cast <uint32_t> ( Value ) );
			
			for ( I = 0; I < SampleCount; I ++ )
				reinterpret_cast <uint32_t *> ( Data ) [ I * ChannelCount + Channel ] = CValue;
			
		}
		break;
		
		case kAudioBufferType_Float32_LittleEndian:
		case kAudioBufferType_Float32_BigEndian:
			return ClearBufferFloat ( Channel, static_cast <float> ( Value ) );
		
		default:
			return;
		
	}
	
}