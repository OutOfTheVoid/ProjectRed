#include <Red/Audio/AudioBuffer.h>

#include <Red/Util/SSE.h>
#include <Red/Util/Endian.h>

#include <stddef.h>
#include <string.h>
#include <math.h>


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
			
		default:
			break;
		
	}
	
	return 0;
	
}

Red::Audio::AudioBuffer :: AudioBuffer ( void * Data, AudioBufferType Type, uint32_t Channels, uint64_t SampleCount, Util :: IFunction1 <void, void *> * OnFree, Util :: IFunction1 <bool, AudioBuffer *> * OnUnReferenced ):
	Data ( Data ),
	DataType ( Type ),
	ChannelCount ( Channels ),
	SampleCount ( SampleCount ),
	OnFree ( OnFree ),
	OnUnReferenced ( OnUnReferenced ),
	RefCount ( 0 )
{
}

Red::Audio::AudioBuffer :: AudioBuffer ( AudioBufferType Type, uint32_t Channels, uint64_t SampleCount, Util :: IFunction1 <bool, AudioBuffer *> * OnUnReferenced ):
	DataType ( Type ),
	ChannelCount ( Channels ),
	SampleCount ( SampleCount ),
	OnUnReferenced ( OnUnReferenced ),
	RefCount ( 0 )
{
	
	Data = malloc ( GetSizeFromDataType ( Type ) * Channels * SampleCount );
	OnFree = & StdFreeWrapper;
	
}

Red::Audio::AudioBuffer :: ~AudioBuffer ()
{
	
	if ( OnFree != NULL )
		( * OnFree ) ( Data );
	
	Data = NULL;
	
}

void Red::Audio::AudioBuffer :: Reference ()
{
	
	RefCount ++;
	
}

void Red::Audio::AudioBuffer :: Dereference ()
{
	
	RefCount --;
	
	if ( RefCount == 0 )
	{
		
		if ( OnUnReferenced == NULL )
			delete this;
		else if ( ( * OnUnReferenced ) ( this ) )
			delete this;
			
	}
	
}

Red::Audio :: AudioBuffer * Red::Audio::AudioBuffer :: CopyReformated ( AudioBuffer & Source, AudioBufferType NewDataType, uint32_t NewChannelCount )
{
	
	if ( NewDataType == kAudioBufferType_Invalid )
		return NULL;
	
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

Red::Audio :: AudioBuffer * Red::Audio::AudioBuffer :: CopyReformatedResampled ( AudioBuffer & Source, ResampleMode Mode, AudioBufferType NewDataType, float SampleRatio, uint32_t NewChannelCount )
{
	
	if ( NewDataType == kAudioBufferType_Invalid )
		return NULL;
	
	if ( NewChannelCount == 0 )
		NewChannelCount = Source.ChannelCount;
	
	uint32_t NewSampleCount = static_cast <uint32_t> ( ceil ( static_cast <float> ( Source.SampleCount ) * SampleRatio ) );
	void * NewData = malloc ( GetSizeFromDataType ( NewDataType ) * NewSampleCount * NewChannelCount );
	
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

uint64_t Red::Audio::AudioBuffer :: GetSampleCount ()
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

void Red::Audio::AudioBuffer :: BlitBuffer ( AudioBuffer & Source, uint32_t SourceChannel, uint64_t SampleCount, uint64_t SourceStartSample, uint64_t TargetStartSample, uint32_t TargetChannel )
{
	
	uint64_t I;
	
	if ( TargetChannel == 0xFFFFFFFF )
		TargetChannel = SourceChannel;
	
	if ( TargetChannel >= ChannelCount )
		return;
	
	if ( SourceChannel >= Source.ChannelCount )
		return;
	
	if ( DataType == kAudioBufferType_Invalid )
		return;
	
	if ( Source.DataType == kAudioBufferType_Invalid )
	{
		
		if ( ( DataType == kAudioBufferType_Float32_LittleEndian ) || ( DataType == kAudioBufferType_Float32_BigEndian ) )
			ClearBufferFloat ( TargetChannel, 0.0f );
		else
			ClearBufferInt ( TargetChannel, 0 );
			
		return;
		
	}
	
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
		#define _BLITBUFFER_ABDESTDATA_INT16_LE(x) reinterpret_cast <int16_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = _AB_Alias_U16ToI16 ( HostToLittleEndian16 ( _AB_Alias_I16ToU16 ( static_cast <int16_t> ( x ) ) ) )
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
							_BLITBUFFER_ABDESTDATA_INT8 ( _BLITBUFFER_ABSOURCEDATA_INT16_LE >> 8 );
						
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
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_BLITBUFFER_ABDESTDATA_UINT16_BE ( _BLITBUFFER_ABSOURCEDATA_UINT16_LE );
							
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

void Red::Audio::AudioBuffer :: BlitBufferResampled ( AudioBuffer & Source, ResampleMode Mode, uint32_t SourceChannel, uint64_t SampleCount, uint64_t SourceStartSample, uint64_t TargetStartSample, float SampleRatio, uint32_t TargetChannel )
{
	
	uint64_t I;
	
	if ( TargetChannel == 0xFFFFFFFF )
		TargetChannel = SourceChannel;
	
	if ( SampleRatio <= 0.0 )
		return;
	
	if ( TargetChannel >= ChannelCount )
		return;
	
	if ( SourceChannel >= Source.ChannelCount )
		return;
	
	if ( DataType == kAudioBufferType_Invalid )
		return;
	
	uint64_t TargetSampleCount = static_cast <uint64_t> ( static_cast <float> ( SampleCount ) * SampleRatio );
	
	if ( Source.DataType == kAudioBufferType_Invalid )
	{
		
		if ( ( DataType == kAudioBufferType_Float32_LittleEndian ) || ( DataType == kAudioBufferType_Float32_BigEndian ) )
			ClearBufferFloat ( TargetChannel, 0.0f, 0, TargetSampleCount );
		else
			ClearBufferInt ( TargetChannel, 0, 0, TargetSampleCount );
			
		return;
		
	}
	
	double RatioInverse = 1.0 / static_cast <double> ( SampleRatio );
	
	#define _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT8 static_cast <int32_t> ( reinterpret_cast <int8_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( static_cast <double> ( I ) * RatioInverse ) ) + SourceChannel ] )
	#define _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT8 static_cast <uint32_t> ( reinterpret_cast <uint8_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( static_cast <double> ( I ) * RatioInverse ) ) + SourceChannel ] )
	#define _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT16_LE static_cast <int32_t> ( _AB_Alias_U16ToI16 ( LittleToHostEndian16 ( reinterpret_cast <uint16_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( static_cast <double> ( I ) * RatioInverse ) ) + SourceChannel ] ) ) )
	#define _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT16_BE static_cast <int32_t> ( _AB_Alias_U16ToI16 ( BigToHostEndian16 ( reinterpret_cast <uint16_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + I ) + SourceChannel ] ) ) )
	#define _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT16_LE static_cast <uint32_t> ( LittleToHostEndian16 ( reinterpret_cast <uint16_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( static_cast <double> ( I ) * RatioInverse ) ) + SourceChannel ] ) )
	#define _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT16_BE static_cast <uint32_t> ( BigToHostEndian16 ( reinterpret_cast <uint16_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( static_cast <double> ( I ) * RatioInverse ) ) + SourceChannel ] ) )
	#define _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT32_LE _AB_Alias_U32ToI32 ( LittleToHostEndian32 ( reinterpret_cast <uint32_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( static_cast <double> ( I ) * RatioInverse ) ) + SourceChannel ] ) )
	#define _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT32_BE _AB_Alias_U32ToI32 ( BigToHostEndian32 ( reinterpret_cast <uint32_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( static_cast <double> ( I ) * RatioInverse ) ) + SourceChannel ] ) )
	#define _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT32_LE LittleToHostEndian32 ( reinterpret_cast <uint32_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( static_cast <double> ( I ) * RatioInverse ) ) + SourceChannel ] )
	#define _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT32_BE BigToHostEndian32 ( reinterpret_cast <uint32_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( static_cast <double> ( I ) * RatioInverse ) ) + SourceChannel ] )
	#define _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_FLOAT32_LE LittleToHostEndianFloat ( reinterpret_cast <float *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( static_cast <double> ( I ) * RatioInverse ) ) + SourceChannel ] )
	#define _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_FLOAT32_BE BigToHostEndianFloat ( reinterpret_cast <float *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( static_cast <double> ( I ) * RatioInverse ) ) + SourceChannel ] )
	
	#define _BLITBUFFERRESAMPLED_MIX_INT(A, B, Factor) static_cast <int32_t> ( static_cast <float> ( A ) * Factor + static_cast <float> ( B ) * ( 1.0f - Factor ) )
	#define _BLITBUFFERRESAMPLED_MIX_UINT(A, B, Factor) static_cast <uint32_t> ( static_cast <float> ( A ) * Factor + static_cast <float> ( B ) * ( 1.0f - Factor ) )
	#define _BLITBUFFERRESAMPLED_MIX_FLOAT(A, B, Factor) ( A * Factor + B * ( 1.0f - Factor ) )
	
	#define _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT8 _BLITBUFFERRESAMPLED_MIX_INT ( static_cast <int32_t> ( reinterpret_cast <int8_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( static_cast <double> ( I ) * RatioInverse ) ) + SourceChannel ] ), static_cast <int32_t> ( reinterpret_cast <int8_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( ceil ( static_cast <double> ( I ) * RatioInverse ) ) ) + SourceChannel ] ), ( ceil ( static_cast <double> ( I ) * RatioInverse ) - static_cast <double> ( I ) * RatioInverse ) )
	#define _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT8 _BLITBUFFERRESAMPLED_MIX_UINT ( static_cast <uint32_t> ( reinterpret_cast <uint8_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( static_cast <double> ( I ) * RatioInverse ) ) + SourceChannel ] ), static_cast <uint32_t> ( reinterpret_cast <uint8_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( ceil ( static_cast <double> ( I ) * RatioInverse ) ) ) + SourceChannel ] ), ( ceil ( static_cast <double> ( I ) * RatioInverse ) - static_cast <double> ( I ) * RatioInverse ) )
	#define _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT16_LE _BLITBUFFERRESAMPLED_MIX_INT ( static_cast <int32_t> ( _AB_Alias_U16ToI16 ( LittleToHostEndian16 ( reinterpret_cast <uint16_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( static_cast <double> ( I ) * RatioInverse ) ) + SourceChannel ] ) ) ), _AB_Alias_U16ToI16 ( LittleToHostEndian16 ( reinterpret_cast <uint16_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( ceil ( static_cast <double> ( I ) * RatioInverse ) ) ) + SourceChannel ] ) ), ( ceil ( static_cast <double> ( I ) * RatioInverse ) - static_cast <double> ( I ) * RatioInverse ) )
	#define _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT16_BE _BLITBUFFERRESAMPLED_MIX_INT ( static_cast <int32_t> ( _AB_Alias_U16ToI16 ( BigToHostEndian16 ( reinterpret_cast <uint16_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( static_cast <double> ( I ) * RatioInverse ) ) + SourceChannel ] ) ) ), static_cast <int32_t> ( _AB_Alias_U16ToI16 ( BigToHostEndian16 ( reinterpret_cast <uint16_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( ceil ( static_cast <double> ( I ) * RatioInverse ) ) ) + SourceChannel ] ) ) ), ( ceil ( static_cast <double> ( I ) * RatioInverse ) - static_cast <double> ( I ) * RatioInverse ) )
	#define _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT16_LE _BLITBUFFERRESAMPLED_MIX_UINT ( static_cast <uint32_t> ( LittleToHostEndian16 ( reinterpret_cast <uint16_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( static_cast <double> ( I ) * RatioInverse ) ) + SourceChannel ] ) ), static_cast <uint32_t> ( LittleToHostEndian16 ( reinterpret_cast <uint16_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( ceil ( static_cast <double> ( I ) * RatioInverse ) ) ) + SourceChannel ] ) ), ( ceil ( static_cast <double> ( I ) * RatioInverse ) - static_cast <double> ( I ) * RatioInverse ) )
	#define _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT16_BE _BLITBUFFERRESAMPLED_MIX_UINT ( static_cast <uint32_t> ( BigToHostEndian16 ( reinterpret_cast <uint16_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( static_cast <double> ( I ) * RatioInverse ) ) + SourceChannel ] ) ), static_cast <uint32_t> ( BigToHostEndian16 ( reinterpret_cast <uint16_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( ceil ( static_cast <double> ( I ) * RatioInverse ) ) ) + SourceChannel ] ) ), ( ceil ( static_cast <double> ( I ) * RatioInverse ) - static_cast <double> ( I ) * RatioInverse ) )
	#define _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT32_LE _BLITBUFFERRESAMPLED_MIX_INT ( _AB_Alias_U32ToI32 ( LittleToHostEndian32 ( reinterpret_cast <uint32_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( static_cast <double> ( I ) * RatioInverse ) ) + SourceChannel ] ) ), _AB_Alias_U32ToI32 ( LittleToHostEndian32 ( reinterpret_cast <uint32_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( ceil ( static_cast <double> ( I ) * RatioInverse ) ) ) + SourceChannel ] ) ), ( ceil ( static_cast <double> ( I ) * RatioInverse ) - static_cast <double> ( I ) * RatioInverse ) )
	#define _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT32_BE _BLITBUFFERRESAMPLED_MIX_INT ( _AB_Alias_U32ToI32 ( BigToHostEndian32 ( reinterpret_cast <uint32_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( static_cast <double> ( I ) * RatioInverse ) ) + SourceChannel ] ) ), _AB_Alias_U32ToI32 ( BigToHostEndian32 ( reinterpret_cast <uint32_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( ceil ( static_cast <double> ( I ) * RatioInverse ) ) ) + SourceChannel ] ) ), ( ceil ( static_cast <double> ( I ) * RatioInverse ) - static_cast <double> ( I ) * RatioInverse ) )
	#define _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT32_LE _BLITBUFFERRESAMPLED_MIX_UINT ( LittleToHostEndian32 ( reinterpret_cast <uint32_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( static_cast <double> ( I ) * RatioInverse ) ) + SourceChannel ] ), LittleToHostEndian32 ( reinterpret_cast <uint32_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( ceil ( static_cast <double> ( I ) * RatioInverse ) ) ) + SourceChannel ] ), ( ceil ( static_cast <double> ( I ) * RatioInverse ) - static_cast <double> ( I ) * RatioInverse ) )
	#define _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT32_BE _BLITBUFFERRESAMPLED_MIX_UINT ( BigToHostEndian32 ( reinterpret_cast <uint32_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( static_cast <double> ( I ) * RatioInverse ) ) + SourceChannel ] ), BigToHostEndian32 ( reinterpret_cast <uint32_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( ceil ( static_cast <double> ( I ) * RatioInverse ) ) ) + SourceChannel ] ), ( ceil ( static_cast <double> ( I ) * RatioInverse ) - static_cast <double> ( I ) * RatioInverse ) )
	#define _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_FLOAT32_LE _BLITBUFFERRESAMPLED_MIX_FLOAT ( LittleToHostEndianFloat ( reinterpret_cast <float *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( static_cast <double> ( I ) * RatioInverse ) ) + SourceChannel ] ), LittleToHostEndianFloat ( reinterpret_cast <float *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( ceil ( static_cast <double> ( I ) * RatioInverse ) ) ) + SourceChannel ] ), ( ceil ( static_cast <double> ( I ) * RatioInverse ) - static_cast <double> ( I ) * RatioInverse ) )
	#define _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_FLOAT32_BE _BLITBUFFERRESAMPLED_MIX_FLOAT ( BigToHostEndianFloat ( reinterpret_cast <float *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( static_cast <double> ( I ) * RatioInverse ) ) + SourceChannel ] ), BigToHostEndianFloat ( reinterpret_cast <float *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + static_cast <uint64_t> ( ceil ( static_cast <double> ( I ) * RatioInverse ) ) ) + SourceChannel ] ), ( ceil ( static_cast <double> ( I ) * RatioInverse ) - static_cast <double> ( I ) * RatioInverse ) )
	
	#define _BLITBUFFERRESAMPLED_ABDESTDATA_INT8(x) reinterpret_cast <uint8_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = static_cast <int8_t> ( x )
	#define _BLITBUFFERRESAMPLED_ABDESTDATA_UINT8(x) reinterpret_cast <uint8_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = static_cast <uint8_t> ( x )
	#define _BLITBUFFERRESAMPLED_ABDESTDATA_INT16_LE(x) reinterpret_cast <int16_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = _AB_Alias_U16ToI16 ( HostToLittleEndian16 ( _AB_Alias_I16ToU16 ( static_cast <int16_t> ( x ) ) ) )
	#define _BLITBUFFERRESAMPLED_ABDESTDATA_INT16_BE(x) reinterpret_cast <int16_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = _AB_Alias_U16ToI16 ( HostToBigEndian16 ( _AB_Alias_I16ToU16 ( static_cast <int16_t> ( x ) ) ) )
	#define _BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_LE(x) reinterpret_cast <uint16_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = HostToLittleEndian16 ( static_cast <uint16_t> ( x ) )
	#define _BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_BE(x) reinterpret_cast <uint16_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = HostToBigEndian16 ( static_cast <uint16_t> ( x ) )
	#define _BLITBUFFERRESAMPLED_ABDESTDATA_INT32_LE(x) reinterpret_cast <int32_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = _AB_Alias_U32ToI32 ( HostToLittleEndian32 ( _AB_Alias_I32ToU32 ( static_cast <int32_t> ( x ) ) ) )
	#define _BLITBUFFERRESAMPLED_ABDESTDATA_INT32_BE(x) reinterpret_cast <int32_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = _AB_Alias_U32ToI32 ( HostToBigEndian32 ( _AB_Alias_I32ToU32 ( static_cast <int32_t> ( x ) ) ) )
	#define _BLITBUFFERRESAMPLED_ABDESTDATA_UINT32_LE(x) reinterpret_cast <uint32_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = HostToLittleEndian32 ( static_cast <uint32_t> ( x ) )
	#define _BLITBUFFERRESAMPLED_ABDESTDATA_UINT32_BE(x) reinterpret_cast <uint32_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = HostToBigEndian32 ( static_cast <uint32_t> ( x ) )
	#define _BLITBUFFERRESAMPLED_ABDESTDATA_FLOAT32_LE(x) reinterpret_cast <float *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = HostToLittleEndianFloat ( static_cast <float> ( x ) )
	#define _BLITBUFFERRESAMPLED_ABDESTDATA_FLOAT32_BE(x) reinterpret_cast <float *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = HostToBigEndianFloat ( static_cast <float> ( x ) )	
	
	switch ( DataType )
	{
		
		case kAudioBufferType_Int8:
		{
			
			switch ( Mode )
			{
				
				case kResampleMode_Nearest:
				{
					
					switch ( Source.DataType )
					{
						
						case kAudioBufferType_Int8:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT8 ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT8 );
							
						}
						break;
						
						case kAudioBufferType_UInt8:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT8 ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT8 ) - 0x80 );
							
						}
						break;
						
						case kAudioBufferType_Int16_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT8 ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT16_LE >> 8 );
							
						}
						break;
						
						case kAudioBufferType_Int16_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT8 ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT16_BE >> 8 );
							
						}
						break;
						
						case kAudioBufferType_UInt16_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT8 ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT16_LE >> 8 ) - 128 );
							
						}
						break;
						
						case kAudioBufferType_UInt16_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT8 ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT16_LE >> 8 ) - 128 );
							
						}
						break;
						
						case kAudioBufferType_Int32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT8 ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT32_LE >> 24 );
							
						}
						break;
						
						case kAudioBufferType_Int32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT8 ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT32_BE >> 24 );
							
						}
						break;
						
						case kAudioBufferType_UInt32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT8 ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT32_LE >> 24 ) - 128 );
							
						}
						break;
						
						case kAudioBufferType_UInt32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT8 ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT32_LE >> 24 ) - 128 );
							
						}
						break;
						
						case kAudioBufferType_Float32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT8 ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_FLOAT32_LE * 127.5f - 0.5f ) );
							
							
						}
						break;
						
						case kAudioBufferType_Float32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT8 ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_FLOAT32_BE * 127.5f - 0.5f ) );
							
							
						}
						break;
						
						default:
							break;
						
					}
					
				}
				break;
				
				case kResampleMode_Linear:
				{
					
					switch ( Source.DataType )
					{
						
						case kAudioBufferType_Int8:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT8 ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT8 );
							
						}
						break;
						
						case kAudioBufferType_UInt8:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT8 ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT8 ) - 0x80 );
							
						}
						break;
						
						case kAudioBufferType_Int16_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT8 ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT16_LE >> 8 );
							
						}
						break;
						
						case kAudioBufferType_Int16_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT8 ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT16_BE >> 8 );
							
						}
						break;
						
						case kAudioBufferType_UInt16_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT8 ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT16_LE >> 8 ) - 128 );
							
						}
						break;
						
						case kAudioBufferType_UInt16_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT8 ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT16_LE >> 8 ) - 128 );
							
						}
						break;
						
						case kAudioBufferType_Int32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT8 ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT32_LE >> 24 );
							
						}
						break;
						
						case kAudioBufferType_Int32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT8 ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT32_BE >> 24 );
							
						}
						break;
						
						case kAudioBufferType_UInt32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT8 ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT32_LE >> 24 ) - 128 );
							
						}
						break;
						
						case kAudioBufferType_UInt32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT8 ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT32_LE >> 24 ) - 128 );
							
						}
						break;
						
						case kAudioBufferType_Float32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT8 ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_FLOAT32_LE * 127.5f - 0.5f ) );
							
							
						}
						break;
						
						case kAudioBufferType_Float32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT8 ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_FLOAT32_BE * 127.5f - 0.5f ) );
							
							
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
		break;
		
		case kAudioBufferType_UInt8:
		{
			
			switch ( Mode )
			{
				
				case kResampleMode_Nearest:
				{
					
					switch ( Source.DataType )
					{
						
						case kAudioBufferType_Int8:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT8 ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT8 + 128 );
							
						}
						break;
						
						case kAudioBufferType_UInt8:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT8 ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT8 );
							
						}
						break;
						
						case kAudioBufferType_Int16_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT8 ( ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT16_LE + 0x8000 ) >> 8 );
							
						}
						break;
						
						case kAudioBufferType_Int16_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT8 ( ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT16_BE + 0x8000 ) >> 8 );
							
						}
						break;
						
						case kAudioBufferType_UInt16_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT8 ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT16_LE >> 8 );
							
						}
						break;
						
						case kAudioBufferType_UInt16_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT8 ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT16_BE >> 8 );
							
						}
						break;
						
						case kAudioBufferType_Int32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT8 ( ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT32_LE >> 24 ) + 128 );
							
						}
						break;
						
						case kAudioBufferType_Int32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT8 ( ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT32_BE >> 24 ) + 128 );
							
						}
						break;
						
						case kAudioBufferType_UInt32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT8 ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT32_LE >> 24 );
							
						}
						break;
						
						case kAudioBufferType_UInt32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT8 ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT32_BE >> 24 );
							
						}
						break;
						
						case kAudioBufferType_Float32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT8 ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_FLOAT32_LE * 127.5f + 127.5f ) );
							
							
						}
						break;
						
						case kAudioBufferType_Float32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT8 ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_FLOAT32_BE * 127.5f + 127.5f ) );
							
							
						}
						break;
						
						default:
							break;
						
					}
					
				}
				break;
				
				case kResampleMode_Linear:
				{
					
					switch ( Source.DataType )
					{
						
						case kAudioBufferType_Int8:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT8 ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT8 + 128 );
							
						}
						break;
						
						case kAudioBufferType_UInt8:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT8 ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT8 );
							
						}
						break;
						
						case kAudioBufferType_Int16_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT8 ( ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT16_LE + 0x8000 ) >> 8 );
							
						}
						break;
						
						case kAudioBufferType_Int16_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT8 ( ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT16_BE + 0x8000 ) >> 8 );
							
						}
						break;
						
						case kAudioBufferType_UInt16_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT8 ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT16_LE >> 8 );
							
						}
						break;
						
						case kAudioBufferType_UInt16_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT8 ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT16_LE >> 8 );
							
						}
						break;
						
						case kAudioBufferType_Int32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT8 ( ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT32_LE >> 24 ) + 128 );
							
						}
						break;
						
						case kAudioBufferType_Int32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT8 ( ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT32_BE >> 24 ) + 128 );
							
						}
						break;
						
						case kAudioBufferType_UInt32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT8 ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT32_LE >> 24 );
							
						}
						break;
						
						case kAudioBufferType_UInt32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT8 ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT32_BE >> 24 );
							
						}
						break;
						
						case kAudioBufferType_Float32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT8 ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_FLOAT32_LE * 127.5f + 127.5f ) );
							
							
						}
						break;
						
						case kAudioBufferType_Float32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT8 ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_FLOAT32_BE * 127.5f + 127.5f ) );
							
							
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
		break;
		
		case kAudioBufferType_Int16_LittleEndian:
		{
			
			switch ( Mode )
			{
				
				case kResampleMode_Nearest:
				{
					
					switch ( Source.DataType )
					{
						
						case kAudioBufferType_Int8:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_LE ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT8 * 0x100 );
							
						}
						break;
						
						case kAudioBufferType_UInt8:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT8 << 8 ) - 0x8000 );
							
						}
						break;
						
						case kAudioBufferType_Int16_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_LE ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT16_LE );
							
						}
						break;
						
						case kAudioBufferType_Int16_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_LE ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT16_BE );
							
						}
						break;
						
						case kAudioBufferType_UInt16_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT16_LE ) - 0x7FFF );
							
						}
						break;
						
						case kAudioBufferType_UInt16_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT16_LE ) - 0x7FFF );
							
						}
						break;
						
						case kAudioBufferType_Int32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_LE ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT32_LE >> 16 );
							
						}
						break;
						
						case kAudioBufferType_Int32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_LE ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT32_BE >> 16 );
							
						}
						break;
						
						case kAudioBufferType_UInt32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT32_LE >> 16 ) - 0x7FFF );
							
						}
						break;
						
						case kAudioBufferType_UInt32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT32_BE >> 16 ) - 0x7FFF );
							
						}
						break;
						
						case kAudioBufferType_Float32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_FLOAT32_LE * 32767.5f - 0.5f ) );
							
							
						}
						break;
						
						case kAudioBufferType_Float32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_FLOAT32_BE * 32767.5f - 0.5f ) );
							
							
						}
						break;
						
						default:
							break;
						
					}
					
				}
				break;
				
				case kResampleMode_Linear:
				{
					
					switch ( Source.DataType )
					{
						
						case kAudioBufferType_Int8:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_LE ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT8 * 0x100 );
							
						}
						break;
						
						case kAudioBufferType_UInt8:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT8 << 8 ) - 0x8000 );
							
						}
						break;
						
						case kAudioBufferType_Int16_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_LE ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT16_LE );
							
						}
						break;
						
						case kAudioBufferType_Int16_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_LE ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT16_BE );
							
						}
						break;
						
						case kAudioBufferType_UInt16_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT16_LE ) - 0x8000 );
							
						}
						break;
						
						case kAudioBufferType_UInt16_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT16_LE ) - 0x8000 );
							
						}
						break;
						
						case kAudioBufferType_Int32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_LE ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT32_LE >> 16 );
							
						}
						break;
						
						case kAudioBufferType_Int32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_LE ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT32_BE >> 16 );
							
						}
						break;
						
						case kAudioBufferType_UInt32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT32_LE >> 16 ) - 0x8000 );
							
						}
						break;
						
						case kAudioBufferType_UInt32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT32_BE >> 16 ) - 0x8000 );
							
						}
						break;
						
						case kAudioBufferType_Float32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_FLOAT32_LE * 32767.5f - 0.5f ) );
							
							
						}
						break;
						
						case kAudioBufferType_Float32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_FLOAT32_BE * 32767.5f - 0.5f ) );
							
							
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
		break;
		
		case kAudioBufferType_Int16_BigEndian:
		{
			
			switch ( Mode )
			{
				
				case kResampleMode_Nearest:
				{
					
					switch ( Source.DataType )
					{
						
						case kAudioBufferType_Int8:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_BE ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT8 * 0x100 );
							
						}
						break;
						
						case kAudioBufferType_UInt8:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT8 << 8 ) - 0x8000 );
							
						}
						break;
						
						case kAudioBufferType_Int16_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_BE ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT16_LE );
							
						}
						break;
						
						case kAudioBufferType_Int16_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_BE ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT16_BE );
							
						}
						break;
						
						case kAudioBufferType_UInt16_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT16_LE ) - 0x7FFF );
							
						}
						break;
						
						case kAudioBufferType_UInt16_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT16_LE ) - 0x7FFF );
							
						}
						break;
						
						case kAudioBufferType_Int32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_BE ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT32_LE >> 16 );
							
						}
						break;
						
						case kAudioBufferType_Int32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_BE ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT32_BE >> 16 );
							
						}
						break;
						
						case kAudioBufferType_UInt32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT32_LE >> 16 ) - 0x7FFF );
							
						}
						break;
						
						case kAudioBufferType_UInt32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT32_BE >> 16 ) - 0x7FFF );
							
						}
						break;
						
						case kAudioBufferType_Float32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_FLOAT32_LE * 32767.5f - 0.5f ) );
							
							
						}
						break;
						
						case kAudioBufferType_Float32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_FLOAT32_BE * 32767.5f - 0.5f ) );
							
							
						}
						break;
						
						default:
							break;
						
					}
					
				}
				break;
				
				case kResampleMode_Linear:
				{
					
					switch ( Source.DataType )
					{
						
						case kAudioBufferType_Int8:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_BE ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT8 * 0x100 );
							
						}
						break;
						
						case kAudioBufferType_UInt8:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT8 << 8 ) - 0x8000 );
							
						}
						break;
						
						case kAudioBufferType_Int16_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_BE ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT16_LE );
							
						}
						break;
						
						case kAudioBufferType_Int16_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_BE ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT16_BE );
							
						}
						break;
						
						case kAudioBufferType_UInt16_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT16_LE ) - 0x8000 );
							
						}
						break;
						
						case kAudioBufferType_UInt16_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT16_LE ) - 0x8000 );
							
						}
						break;
						
						case kAudioBufferType_Int32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_BE ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT32_LE >> 16 );
							
						}
						break;
						
						case kAudioBufferType_Int32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_BE ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT32_BE >> 16 );
							
						}
						break;
						
						case kAudioBufferType_UInt32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT32_LE >> 16 ) - 0x8000 );
							
						}
						break;
						
						case kAudioBufferType_UInt32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT32_BE >> 16 ) - 0x8000 );
							
						}
						break;
						
						case kAudioBufferType_Float32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_FLOAT32_LE * 32767.5f - 0.5f ) );
							
							
						}
						break;
						
						case kAudioBufferType_Float32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_FLOAT32_BE * 32767.5f - 0.5f ) );
							
							
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
		break;
		
		case kAudioBufferType_UInt16_LittleEndian:
		{
			
			switch ( Mode )
			{
				
				case kResampleMode_Nearest:
				{
					
					switch ( Source.DataType )
					{
						
						case kAudioBufferType_Int8:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_LE ( static_cast <uint32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT8 + 128 ) << 8 );
							
						}
						break;
						
						case kAudioBufferType_UInt8:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_LE ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT8 << 8 );
							
						}
						break;
						
						case kAudioBufferType_Int16_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_LE ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT16_LE + 0x8000 );
							
						}
						break;
						
						case kAudioBufferType_Int16_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_LE ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT16_BE + 0x8000 );
							
						}
						break;
						
						case kAudioBufferType_UInt16_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_LE ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT16_LE );
							
						}
						break;
						
						case kAudioBufferType_UInt16_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_LE ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT16_BE );
							
						}
						break;
						
						case kAudioBufferType_Int32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_LE ( ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT32_LE >> 16 ) + 0x8000 );
							
						}
						break;
						
						case kAudioBufferType_Int32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_LE ( ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT32_BE >> 16 ) + 0x8000 );
							
						}
						break;
						
						case kAudioBufferType_UInt32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_LE ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT32_LE >> 16 );
							
						}
						break;
						
						case kAudioBufferType_UInt32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_LE ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT32_BE >> 16 );
							
						}
						break;
						
						case kAudioBufferType_Float32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_LE ( static_cast <uint32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_FLOAT32_LE * 32767.5f + 32767.5f ) );
							
							
						}
						break;
						
						case kAudioBufferType_Float32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_LE ( static_cast <uint32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_FLOAT32_BE * 32767.5f + 32767.5f ) );
							
							
						}
						break;
						
						default:
							break;
						
					}
					
				}
				break;
				
				case kResampleMode_Linear:
				{
					
					switch ( Source.DataType )
					{
						
						case kAudioBufferType_Int8:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_LE ( static_cast <uint32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT8 + 128 ) << 8 );
							
						}
						break;
						
						case kAudioBufferType_UInt8:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_LE ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT8 << 8 );
							
						}
						break;
						
						case kAudioBufferType_Int16_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_LE ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT16_LE + 0x8000 );
							
						}
						break;
						
						case kAudioBufferType_Int16_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_LE ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT16_BE + 0x8000 );
							
						}
						break;
						
						case kAudioBufferType_UInt16_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_LE ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT16_LE );
							
						}
						break;
						
						case kAudioBufferType_UInt16_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_LE ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT16_BE );
							
						}
						break;
						
						case kAudioBufferType_Int32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_LE ( ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT32_LE >> 16 ) + 0x8000 );
							
						}
						break;
						
						case kAudioBufferType_Int32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_LE ( ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT32_BE >> 16 ) + 0x8000 );
							
						}
						break;
						
						case kAudioBufferType_UInt32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_LE ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT32_LE >> 16 );
							
						}
						break;
						
						case kAudioBufferType_UInt32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_LE ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT32_BE >> 16 );
							
						}
						break;
						
						case kAudioBufferType_Float32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_LE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_FLOAT32_LE * 32767.5f + 32767.5f ) );
							
							
						}
						break;
						
						case kAudioBufferType_Float32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_LE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_FLOAT32_BE * 32767.5f + 32767.5f ) );
							
							
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
		break;
		
		case kAudioBufferType_UInt16_BigEndian:
		{
			
			switch ( Mode )
			{
				
				case kResampleMode_Nearest:
				{
					
					switch ( Source.DataType )
					{
						
						case kAudioBufferType_Int8:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_BE ( static_cast <uint32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT8 + 128 ) << 8 );
							
						}
						break;
						
						case kAudioBufferType_UInt8:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_BE ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT8 << 8 );
							
						}
						break;
						
						case kAudioBufferType_Int16_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_BE ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT16_LE + 0x8000 );
							
						}
						break;
						
						case kAudioBufferType_Int16_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_BE ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT16_BE + 0x8000 );
							
						}
						break;
						
						case kAudioBufferType_UInt16_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_BE ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT16_LE );
							
						}
						break;
						
						case kAudioBufferType_UInt16_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_BE ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT16_BE );
							
						}
						break;
						
						case kAudioBufferType_Int32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_BE ( ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT32_LE >> 16 ) + 0x8000 );
							
						}
						break;
						
						case kAudioBufferType_Int32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_BE ( ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_INT32_BE >> 16 ) + 0x8000 );
							
						}
						break;
						
						case kAudioBufferType_UInt32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_BE ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT32_LE >> 16 );
							
						}
						break;
						
						case kAudioBufferType_UInt32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_BE ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_UINT32_BE >> 16 );
							
						}
						break;
						
						case kAudioBufferType_Float32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_BE ( static_cast <uint32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_FLOAT32_LE * 32767.5f + 32767.5f ) );
							
						}
						break;
						
						case kAudioBufferType_Float32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_BE ( static_cast <uint32_t> ( _BLITBUFFERRESAMPLED_NEAREST_ABSOURCEDATA_FLOAT32_BE * 32767.5f + 32767.5f ) );
							
						}
						break;
						
						default:
							break;
						
					}
					
				}
				break;
				
				case kResampleMode_Linear:
				{
					
					switch ( Source.DataType )
					{
						
						case kAudioBufferType_Int8:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_BE ( static_cast <uint32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT8 + 128 ) << 8 );
							
						}
						break;
						
						case kAudioBufferType_UInt8:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_BE ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT8 << 8 );
							
						}
						break;
						
						case kAudioBufferType_Int16_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_BE ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT16_LE + 0x8000 );
							
						}
						break;
						
						case kAudioBufferType_Int16_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_BE ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT16_BE + 0x8000 );
							
						}
						break;
						
						case kAudioBufferType_UInt16_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_BE ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT16_LE );
							
						}
						break;
						
						case kAudioBufferType_UInt16_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_BE ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT16_BE );
							
						}
						break;
						
						case kAudioBufferType_Int32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_BE ( ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT32_LE >> 16 ) + 0x8000 );
							
						}
						break;
						
						case kAudioBufferType_Int32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_BE ( ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_INT32_BE >> 16 ) + 0x8000 );
							
						}
						break;
						
						case kAudioBufferType_UInt32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_BE ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT32_LE >> 16 );
							
						}
						break;
						
						case kAudioBufferType_UInt32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_BE ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_UINT32_BE >> 16 );
							
						}
						break;
						
						case kAudioBufferType_Float32_LittleEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_BE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_FLOAT32_LE * 32767.5f + 32767.5f ) );
							
						}
						break;
						
						case kAudioBufferType_Float32_BigEndian:
						{
							
							for ( I = 0; I < SampleCount; I ++ )
								_BLITBUFFERRESAMPLED_ABDESTDATA_UINT16_BE ( static_cast <int32_t> ( _BLITBUFFERRESAMPLED_LINEAR_ABSOURCEDATA_FLOAT32_BE * 32767.5f + 32767.5f ) );
							
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
		break;
		
		case kAudioBufferType_Int32_LittleEndian:
		{
			
			
			
		}
		break;
		
		case kAudioBufferType_Int32_BigEndian:
		{
			
			
			
		}
		break;
		
		case kAudioBufferType_UInt32_LittleEndian:
		{
			
			
			
		}
		break;
		
		case kAudioBufferType_UInt32_BigEndian:
		{
			
			
			
		}
		break;
		
		case kAudioBufferType_Float32_LittleEndian:
		{
			
			
			
		}
		break;
		
		case kAudioBufferType_Float32_BigEndian:
		{
			
			
			
		}
		break;
		
		default:
			break;
		
	}
	
	// TODO: Implement
	
}

void Red::Audio::AudioBuffer :: AddBuffer ( AudioBuffer & Source, uint32_t SourceChannel, uint64_t SampleCount, uint64_t SourceStartSample, uint64_t TargetStartSample, uint32_t TargetChannel )
{
	
	uint64_t I;
	
	if ( TargetChannel == 0xFFFFFFFF )
		TargetChannel = SourceChannel;
	
	if ( TargetChannel >= ChannelCount )
		return;
	
	if ( SourceChannel >= Source.ChannelCount )
		return;
	
	if ( DataType == kAudioBufferType_Invalid )
		return;
	
	if ( Source.DataType == kAudioBufferType_Invalid )
	{
		
		if ( ( DataType == kAudioBufferType_Float32_LittleEndian ) || ( DataType == kAudioBufferType_Float32_BigEndian ) )
			ClearBufferFloat ( TargetChannel, 0.0f );
		else
			ClearBufferInt ( TargetChannel, 0 );
			
		return;
		
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
		
		
		#define _ADDBUFFER_ABDESTDATA_INT8(x) reinterpret_cast <uint8_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] += static_cast <int8_t> ( x )
		#define _ADDBUFFER_ABDESTDATA_UINT8(x) reinterpret_cast <uint8_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] += static_cast <uint8_t> ( x )
		#define _ADDBUFFER_ABDESTDATA_INT16_LE(x) reinterpret_cast <int16_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = _AB_Alias_U16ToI16 ( HostToLittleEndian16 ( _AB_Alias_I16ToU16 ( static_cast <int16_t> ( static_cast <int32_t> ( x ) ) + _AB_Alias_U16ToI16 ( LittleToHostEndian16 ( _AB_Alias_I16ToU16 ( reinterpret_cast <int16_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] ) ) ) ) ) )
		#define _ADDBUFFER_ABDESTDATA_INT16_BE(x) reinterpret_cast <int16_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = _AB_Alias_U16ToI16 ( HostToBigEndian16 ( _AB_Alias_I16ToU16 ( static_cast <int16_t> ( x ) + _AB_Alias_U16ToI16 ( BigToHostEndian16 ( _AB_Alias_I16ToU16 ( reinterpret_cast <int16_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] ) ) ) ) ) )
		#define _ADDBUFFER_ABDESTDATA_UINT16_LE(x) reinterpret_cast <uint16_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = HostToLittleEndian16 ( static_cast <uint16_t> ( x ) + LittleToHostEndian16 ( reinterpret_cast <uint16_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] ) )
		#define _ADDBUFFER_ABDESTDATA_UINT16_BE(x) reinterpret_cast <uint16_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = HostToBigEndian16 ( static_cast <uint16_t> ( x ) + LittleToHostEndian16 ( reinterpret_cast <uint16_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] ) )
		#define _ADDBUFFER_ABDESTDATA_INT32_LE(x) reinterpret_cast <int32_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = _AB_Alias_U32ToI32 ( HostToLittleEndian32 ( _AB_Alias_I32ToU32 ( static_cast <int32_t> ( x ) + _AB_Alias_U32ToI32 ( LittleToHostEndian32 ( _AB_Alias_I32ToU32 ( reinterpret_cast <int32_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] ) ) ) ) ) )
		#define _ADDBUFFER_ABDESTDATA_INT32_BE(x) reinterpret_cast <int32_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = _AB_Alias_U32ToI32 ( HostToBigEndian32 ( _AB_Alias_I32ToU32 ( static_cast <int32_t> ( x ) + _AB_Alias_U32ToI32 ( BigToHostEndian32 ( _AB_Alias_I32ToU32 ( reinterpret_cast <int32_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] ) ) ) ) ) )
		#define _ADDBUFFER_ABDESTDATA_UINT32_LE(x) reinterpret_cast <uint32_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = HostToLittleEndian32 ( static_cast <uint32_t> ( x ) + LittleToHostEndian32 ( reinterpret_cast <int32_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] ) )
		#define _ADDBUFFER_ABDESTDATA_UINT32_BE(x) reinterpret_cast <uint32_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = HostToBigEndian32 ( static_cast <uint32_t> ( x ) + BigToHostEndian32 ( reinterpret_cast <int32_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] ) )
		#define _ADDBUFFER_ABDESTDATA_FLOAT32_LE(x) reinterpret_cast <float *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = HostToLittleEndianFloat ( static_cast <float> ( x ) + LittleToHostEndianFloat ( reinterpret_cast <float *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] ) )
		#define _ADDBUFFER_ABDESTDATA_FLOAT32_BE(x) reinterpret_cast <float *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = HostToBigEndianFloat ( static_cast <float> ( x ) + BigToHostEndianFloat ( reinterpret_cast <float *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] ) )
		
		switch ( DataType )
		{
			
			case kAudioBufferType_Int8:
			{
				
				switch ( Source.DataType )
				{
				
					case kAudioBufferType_Int8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT8 ( _BLITBUFFER_ABSOURCEDATA_INT8 );
						
					}
					break;
	
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT8 ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT8 ) - 0x80 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT8 ( _BLITBUFFER_ABSOURCEDATA_INT16_LE >> 8 ); // TODO: Fix clipping caused by down-conversion mapping to -128 to 128 by finding a way to map to -128 to 127
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT8 ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_INT16_BE ) / 0x100 );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT8 ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT16_LE >> 8 ) - 0x80 );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT8 ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT16_BE >> 8 ) - 0x80 );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT8 ( _BLITBUFFER_ABSOURCEDATA_INT32_LE / 0x1000000 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT8 ( _BLITBUFFER_ABSOURCEDATA_INT32_BE / 0x1000000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT8 ( ( _BLITBUFFER_ABSOURCEDATA_UINT32_LE >> 24 ) - 0x80 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT8 ( ( _BLITBUFFER_ABSOURCEDATA_UINT32_BE >> 24 ) - 0x80 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT8 ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_LE * 127.5 - 0.5 );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT8 ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_BE * 127.5 - 0.5 );
						
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
							_ADDBUFFER_ABDESTDATA_UINT8 ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_INT8 ) + 0x80 );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT8 ( _BLITBUFFER_ABSOURCEDATA_UINT8 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT8 ( static_cast <uint32_t> ( _BLITBUFFER_ABSOURCEDATA_INT16_LE + 0x8000 ) >> 8 );
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT8 ( static_cast <uint32_t> ( _BLITBUFFER_ABSOURCEDATA_INT16_BE + 0x8000 ) >> 8 );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT8 ( _BLITBUFFER_ABSOURCEDATA_UINT16_LE >> 8 );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT8 ( _BLITBUFFER_ABSOURCEDATA_UINT16_BE >> 8 );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT8 ( ( static_cast <uint32_t> ( _BLITBUFFER_ABSOURCEDATA_INT32_LE ) + 0x80000000 ) >> 24 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT8 ( ( static_cast <uint32_t> ( _BLITBUFFER_ABSOURCEDATA_INT32_BE ) + 0x80000000 ) >> 24 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT8 ( _BLITBUFFER_ABSOURCEDATA_UINT32_LE >> 24 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT8 ( _BLITBUFFER_ABSOURCEDATA_UINT32_BE >> 24 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT8 ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_LE + 1.0 ) * 127.5 );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT8 ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_BE + 1.0 ) * 127.5 );
						
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
							_ADDBUFFER_ABDESTDATA_INT16_LE ( _BLITBUFFER_ABSOURCEDATA_INT8 * 0x100 );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT8 << 8 ) - 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_LE ( _BLITBUFFER_ABSOURCEDATA_INT16_LE );
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_LE ( _BLITBUFFER_ABSOURCEDATA_INT16_BE );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT16_LE ) - 0x8000 );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT16_BE ) - 0x8000 );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_LE ( _BLITBUFFER_ABSOURCEDATA_INT32_LE / 0x10000 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_LE ( _BLITBUFFER_ABSOURCEDATA_INT32_BE / 0x10000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT32_LE >> 16 ) - 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT32_BE >> 16 ) - 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_LE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_LE * 32767.5f ) - 0.5f );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_LE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_BE * 32767.5 ) - 0.5 );
						
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
							_ADDBUFFER_ABDESTDATA_INT16_BE ( _BLITBUFFER_ABSOURCEDATA_INT8 * 0x100 );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT8 << 8 ) - 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_BE ( _BLITBUFFER_ABSOURCEDATA_INT16_LE );
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_BE ( _BLITBUFFER_ABSOURCEDATA_INT16_BE );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT16_LE ) - 0x8000 );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT16_BE ) - 0x8000 );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_BE ( _BLITBUFFER_ABSOURCEDATA_INT32_LE / 0x10000 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_BE ( _BLITBUFFER_ABSOURCEDATA_INT32_BE / 0x10000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT32_LE >> 16 ) - 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT32_BE >> 16 ) - 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_BE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_LE * 32767.5 ) - 0.5 );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_BE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_BE * 32767.5 ) - 0.5 );
						
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
							_ADDBUFFER_ABDESTDATA_UINT16_LE ( static_cast <uint16_t> ( static_cast <int16_t> ( _BLITBUFFER_ABSOURCEDATA_INT8 ) + 0x80 ) << 8 );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_LE ( _BLITBUFFER_ABSOURCEDATA_UINT8 << 8 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_LE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_INT16_LE ) + 0x8000 );
							
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_LE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_INT16_BE ) + 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_LE ( _BLITBUFFER_ABSOURCEDATA_UINT16_LE );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_LE ( _BLITBUFFER_ABSOURCEDATA_UINT16_BE );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_LE ( ( _BLITBUFFER_ABSOURCEDATA_INT32_LE / 0x10000 ) + 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_LE ( ( _BLITBUFFER_ABSOURCEDATA_INT32_BE / 0x10000 ) + 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_LE ( _BLITBUFFER_ABSOURCEDATA_UINT32_LE >> 16 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_LE ( _BLITBUFFER_ABSOURCEDATA_UINT32_BE >> 16 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_LE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_LE + 1.0 ) * 32767.5 );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_LE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_BE + 1.0 ) * 32767.5 );
						
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
							_ADDBUFFER_ABDESTDATA_UINT16_BE ( static_cast <uint16_t> ( static_cast <int16_t> ( _BLITBUFFER_ABSOURCEDATA_INT8 ) + 0x80 ) << 8 );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_BE ( _BLITBUFFER_ABSOURCEDATA_UINT8 << 8 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_BE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_INT16_LE ) + 0x8000 );
							
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_BE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_INT16_BE ) + 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_BE ( _BLITBUFFER_ABSOURCEDATA_UINT16_LE );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_BE ( _BLITBUFFER_ABSOURCEDATA_UINT16_BE );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_BE ( ( _BLITBUFFER_ABSOURCEDATA_INT32_LE / 0x10000 ) + 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_BE ( ( _BLITBUFFER_ABSOURCEDATA_INT32_BE / 0x10000 ) + 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_BE ( _BLITBUFFER_ABSOURCEDATA_UINT32_LE >> 16 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_BE ( _BLITBUFFER_ABSOURCEDATA_UINT32_BE >> 16 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_BE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_LE + 1.0 ) * 32767.5 );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_BE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_BE + 1.0 ) * 32767.5 );
						
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
							_ADDBUFFER_ABDESTDATA_INT32_LE ( _BLITBUFFER_ABSOURCEDATA_INT8 * 0x1000000 );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_LE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT8 << 24 ) - 0x800000 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_LE ( _BLITBUFFER_ABSOURCEDATA_INT16_LE * 0x10000 );
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_LE ( _BLITBUFFER_ABSOURCEDATA_INT16_BE * 0x10000 );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_LE ( ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT16_LE ) - 0x8000 ) * 0x10000 );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_LE ( ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT16_BE ) - 0x8000 ) * 0x10000 );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_LE ( _BLITBUFFER_ABSOURCEDATA_INT32_LE );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_LE ( _BLITBUFFER_ABSOURCEDATA_INT32_BE );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_LE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT32_LE ) - 0x80000000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_LE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT32_BE ) - 0x80000000 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_LE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_BE * 2147483647.5 ) - 0.5 );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_LE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_BE * 2147483647.5 ) - 0.5 );
						
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
							_ADDBUFFER_ABDESTDATA_INT32_BE ( _BLITBUFFER_ABSOURCEDATA_INT8 * 0x1000000 );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_BE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT8 << 24 ) - 0x800000 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_BE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_INT16_LE ) * 0x1000 );
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_BE ( _BLITBUFFER_ABSOURCEDATA_INT16_BE * 0x10000 );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_BE ( ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT16_LE ) - 0x8000 ) * 0x10000 );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_BE ( ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT16_BE ) - 0x8000 ) * 0x10000 );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_BE ( _BLITBUFFER_ABSOURCEDATA_INT32_LE );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_BE ( _BLITBUFFER_ABSOURCEDATA_INT32_BE );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_BE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT32_LE ) - 0x80000000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_BE ( static_cast <int32_t> ( _BLITBUFFER_ABSOURCEDATA_UINT32_BE ) - 0x80000000 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_BE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_LE * 2147483647.5 ) - 0.5 );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_BE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_BE * 2147483647.5 ) - 0.5 );
						
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
							_ADDBUFFER_ABDESTDATA_UINT32_LE ( static_cast <uint32_t> ( _BLITBUFFER_ABSOURCEDATA_INT8 + 0x80 ) << 24 );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_LE ( _BLITBUFFER_ABSOURCEDATA_UINT8 << 24 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_LE ( static_cast <uint32_t> ( _BLITBUFFER_ABSOURCEDATA_INT16_LE + 0x8000 ) << 16 );
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_LE ( static_cast <uint32_t> ( _BLITBUFFER_ABSOURCEDATA_INT16_BE + 0x8000 ) << 16 );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_LE ( _BLITBUFFER_ABSOURCEDATA_UINT16_LE << 16 );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_LE ( _BLITBUFFER_ABSOURCEDATA_UINT16_BE << 16 );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_LE ( _BLITBUFFER_ABSOURCEDATA_INT32_LE + 0x80000000 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_LE ( _BLITBUFFER_ABSOURCEDATA_INT32_BE + 0x80000000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_LE ( _BLITBUFFER_ABSOURCEDATA_UINT32_LE );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_LE ( _BLITBUFFER_ABSOURCEDATA_UINT32_BE );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_LE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_LE + 1.0 ) * 2147483647.5 );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_LE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_BE + 1.0 ) * 2147483647.5 );
						
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
							_ADDBUFFER_ABDESTDATA_UINT32_BE ( static_cast <uint32_t> ( _BLITBUFFER_ABSOURCEDATA_INT8 + 0x80 ) << 24 );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_BE ( _BLITBUFFER_ABSOURCEDATA_UINT8 << 24 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_BE ( static_cast <uint32_t> ( _BLITBUFFER_ABSOURCEDATA_INT16_LE + 0x8000 ) << 16 );
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_BE ( static_cast <uint32_t> ( _BLITBUFFER_ABSOURCEDATA_INT16_BE + 0x8000 ) << 16 );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_BE ( _BLITBUFFER_ABSOURCEDATA_UINT16_LE << 16 );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_BE ( _BLITBUFFER_ABSOURCEDATA_UINT16_BE << 16 );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_BE ( _BLITBUFFER_ABSOURCEDATA_INT32_LE + 0x80000000 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_BE ( _BLITBUFFER_ABSOURCEDATA_INT32_BE + 0x80000000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_BE ( _BLITBUFFER_ABSOURCEDATA_UINT32_LE );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_BE ( _BLITBUFFER_ABSOURCEDATA_UINT32_BE );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_BE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_LE + 1.0 ) * 2147483647.5f );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_BE ( ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_BE + 1.0 ) * 2147483647.5f );
						
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
							_ADDBUFFER_ABDESTDATA_FLOAT32_LE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_INT8 ) + 0.5f ) * 0.00784313725f );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_LE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_INT8 ) - 127.5f ) * 0.00784313725f );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_LE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_INT16_LE ) + 0.5f ) * 0.00003051804f );
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_LE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_INT16_BE ) + 0.5f ) * 0.00003051804f );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_LE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_UINT16_LE ) - 32767.5 ) * 0.00003051804f );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_LE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_UINT16_BE ) - 32767.5 ) * 0.00003051804f );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ ) // The center shift here is pointless as a float32 has only 23 fraction bits
							_ADDBUFFER_ABDESTDATA_FLOAT32_LE ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_INT32_LE ) * 4.6566129e-10 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ ) // The center shift here is pointless as a float32 has only 23 fraction bits
							_ADDBUFFER_ABDESTDATA_FLOAT32_LE ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_INT32_BE ) * 4.6566129e-10 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ ) // The center shift here is pointless as a float32 has only 23 fraction bits
							_ADDBUFFER_ABDESTDATA_FLOAT32_LE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_UINT32_LE ) - 2147483647.5f ) * 4.6566129e-10 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_LE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_UINT32_BE ) - 2147483647.5f ) * 4.6566129e-10 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_LE ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_LE );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_LE ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_BE );
						
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
							_ADDBUFFER_ABDESTDATA_FLOAT32_BE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_INT8 ) + 0.5f ) * 0.00784313725f );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_BE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_INT8 ) - 127.5f ) * 0.00784313725f );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_BE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_INT16_LE ) + 0.5f ) * 0.00003051804f );
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_BE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_INT16_BE ) + 0.5f ) * 0.00003051804f );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_BE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_UINT16_LE ) - 32767.5 ) * 0.00003051804f );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_BE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_UINT16_BE ) - 32767.5 ) * 0.00003051804f );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ ) // The center shift here is pointless as a float32 has only 23 fraction bits
							_ADDBUFFER_ABDESTDATA_FLOAT32_BE ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_INT32_LE ) * 4.6566129e-10 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ ) // The center shift here is pointless as a float32 has only 23 fraction bits
							_ADDBUFFER_ABDESTDATA_FLOAT32_BE ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_INT32_BE ) * 4.6566129e-10 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ ) // The center shift here is pointless as a float32 has only 23 fraction bits
							_ADDBUFFER_ABDESTDATA_FLOAT32_BE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_UINT32_LE ) - 2147483647.5f ) * 4.6566129e-10 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_BE ( ( static_cast <float> ( _BLITBUFFER_ABSOURCEDATA_UINT32_BE ) - 2147483647.5f ) * 4.6566129e-10 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_BE ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_LE );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_BE ( _BLITBUFFER_ABSOURCEDATA_FLOAT32_LE );
						
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

// TODO: Apply scale factors to source macros
void Red::Audio::AudioBuffer :: AddBufferScaled ( AudioBuffer & Source, float Scale, uint32_t SourceChannel, uint64_t SampleCount, uint64_t SourceStartSample, uint64_t TargetStartSample, uint32_t TargetChannel )
{
	
	uint64_t I;
	
	if ( TargetChannel == 0xFFFFFFFF )
		TargetChannel = SourceChannel;
	
	if ( TargetChannel >= ChannelCount )
		return;
	
	if ( SourceChannel >= Source.ChannelCount )
		return;
	
	union
	{
		
		int32_t ScaleI8;
		uint32_t ScaleU8;
		int32_t ScaleI16;
		uint32_t ScaleU16;
		int64_t ScaleI32;
		uint64_t ScaleU32;
		
	} ScaleFactors;
	
	//bool InvertUSign = Scale < 0.0f;
	
	switch ( Source.DataType )
	{
		
		case kAudioBufferType_Int8:
			ScaleFactors.ScaleI8 = static_cast <int32_t> ( Scale * 256.0f );
			break;
			
		case kAudioBufferType_UInt8:
			ScaleFactors.ScaleI8 = static_cast <uint32_t> ( Scale * 256.0f );
			break;
		
		case kAudioBufferType_Int16_LittleEndian:
		case kAudioBufferType_Int16_BigEndian:
			ScaleFactors.ScaleI16 = static_cast <int32_t> ( Scale * 65536.0f );
			break;
			
		case kAudioBufferType_UInt16_LittleEndian:
		case kAudioBufferType_UInt16_BigEndian:
			ScaleFactors.ScaleU16 = static_cast <uint32_t> ( Scale * 65536.0f );
			break;
			
		case kAudioBufferType_Int32_LittleEndian:
		case kAudioBufferType_Int32_BigEndian:
			ScaleFactors.ScaleI32 = static_cast <int64_t> ( Scale * 4294967296.0f );
			break;
			
		case kAudioBufferType_UInt32_LittleEndian:
		case kAudioBufferType_UInt32_BigEndian:
			ScaleFactors.ScaleU32 = static_cast <uint64_t> ( Scale * 4294967296.0f );
			break;
			
		default:
			break;
	
	}
	
	if ( DataType == kAudioBufferType_Invalid )
		return;
	
	if ( Source.DataType == kAudioBufferType_Invalid )
	{
		
		if ( ( DataType == kAudioBufferType_Float32_LittleEndian ) || ( DataType == kAudioBufferType_Float32_BigEndian ) )
			ClearBufferFloat ( TargetChannel, 0.0f );
		else
			ClearBufferInt ( TargetChannel, 0 );
			
		return;
		
	}
	else
	{
		
		#define _ADDBUFFERSCALED_ABSOURCEDATA_INT8 ( ( static_cast <int32_t> ( reinterpret_cast <int8_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + I ) + SourceChannel ] ) * ScaleFactors.ScaleI8 ) >> 8 )
		#define _ADDBUFFERSCALED_ABSOURCEDATA_UINT8 ( ( static_cast <uint32_t> ( reinterpret_cast <uint8_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + I ) + SourceChannel ] ) * ScaleFactors.ScaleU8 ) >> 8 )
		#define _ADDBUFFERSCALED_ABSOURCEDATA_INT16_LE ( ( static_cast <int32_t> ( _AB_Alias_U16ToI16 ( LittleToHostEndian16 ( reinterpret_cast <uint16_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + I ) + SourceChannel ] ) ) ) * ScaleFactors.ScaleI16 ) >> 16 )
		#define _ADDBUFFERSCALED_ABSOURCEDATA_INT16_BE ( ( static_cast <int32_t> ( _AB_Alias_U16ToI16 ( BigToHostEndian16 ( reinterpret_cast <uint16_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + I ) + SourceChannel ] ) ) ) * ScaleFactors.ScaleI16 ) >> 16 )
		#define _ADDBUFFERSCALED_ABSOURCEDATA_UINT16_LE ( ( static_cast <uint32_t> ( LittleToHostEndian16 ( reinterpret_cast <uint16_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + I ) + SourceChannel ] ) ) * ScaleFactors.ScaleU16 ) >> 16 )
		#define _ADDBUFFERSCALED_ABSOURCEDATA_UINT16_BE ( ( static_cast <uint32_t> ( BigToHostEndian16 ( reinterpret_cast <uint16_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + I ) + SourceChannel ] ) ) * ScaleFactors.ScaleU16 ) >> 16 )
		#define _ADDBUFFERSCALED_ABSOURCEDATA_INT32_LE static_cast <int32_t> ( ( static_cast <int64_t> ( _AB_Alias_U32ToI32 ( LittleToHostEndian32 ( reinterpret_cast <uint32_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + I ) + SourceChannel ] ) ) ) * ScaleFactors.ScaleI32 ) >> 32 )
		#define _ADDBUFFERSCALED_ABSOURCEDATA_INT32_BE static_cast <int32_t> ( ( static_cast <int64_t> ( _AB_Alias_U32ToI32 ( BigToHostEndian32 ( reinterpret_cast <uint32_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + I ) + SourceChannel ] ) ) ) * ScaleFactors.ScaleI32 ) >> 32 )
		#define _ADDBUFFERSCALED_ABSOURCEDATA_UINT32_LE static_cast <uint32_t> ( ( static_cast <uint64_t> ( LittleToHostEndian32 ( reinterpret_cast <uint32_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + I ) + SourceChannel ] ) ) * ScaleFactors.ScaleU32 ) >> 32 )
		#define _ADDBUFFERSCALED_ABSOURCEDATA_UINT32_BE static_cast <uint32_t> ( ( static_cast <uint64_t> ( BigToHostEndian32 ( reinterpret_cast <uint32_t *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + I ) + SourceChannel ] ) ) * ScaleFactors.ScaleU32 ) >> 32 )
		#define _ADDBUFFERSCALED_ABSOURCEDATA_FLOAT32_LE ( LittleToHostEndianFloat ( reinterpret_cast <float *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + I ) + SourceChannel ] ) * Scale )
		#define _ADDBUFFERSCALED_ABSOURCEDATA_FLOAT32_BE ( BigToHostEndianFloat ( reinterpret_cast <float *> ( Source.Data ) [ Source.ChannelCount * ( SourceStartSample + I ) + SourceChannel ] ) * Scale )
		
		
		#define _ADDBUFFER_ABDESTDATA_INT8(x) reinterpret_cast <uint8_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] += static_cast <int8_t> ( x )
		#define _ADDBUFFER_ABDESTDATA_UINT8(x) reinterpret_cast <uint8_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] += static_cast <uint8_t> ( x )
		#define _ADDBUFFER_ABDESTDATA_INT16_LE(x) reinterpret_cast <int16_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = _AB_Alias_U16ToI16 ( HostToLittleEndian16 ( _AB_Alias_I16ToU16 ( static_cast <int16_t> ( static_cast <int32_t> ( x ) ) + _AB_Alias_U16ToI16 ( LittleToHostEndian16 ( _AB_Alias_I16ToU16 ( reinterpret_cast <int16_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] ) ) ) ) ) )
		#define _ADDBUFFER_ABDESTDATA_INT16_BE(x) reinterpret_cast <int16_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = _AB_Alias_U16ToI16 ( HostToBigEndian16 ( _AB_Alias_I16ToU16 ( static_cast <int16_t> ( x ) + _AB_Alias_U16ToI16 ( BigToHostEndian16 ( _AB_Alias_I16ToU16 ( reinterpret_cast <int16_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] ) ) ) ) ) )
		#define _ADDBUFFER_ABDESTDATA_UINT16_LE(x) reinterpret_cast <uint16_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = HostToLittleEndian16 ( static_cast <uint16_t> ( x ) + LittleToHostEndian16 ( reinterpret_cast <uint16_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] ) )
		#define _ADDBUFFER_ABDESTDATA_UINT16_BE(x) reinterpret_cast <uint16_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = HostToBigEndian16 ( static_cast <uint16_t> ( x ) + LittleToHostEndian16 ( reinterpret_cast <uint16_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] ) )
		#define _ADDBUFFER_ABDESTDATA_INT32_LE(x) reinterpret_cast <int32_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = _AB_Alias_U32ToI32 ( HostToLittleEndian32 ( _AB_Alias_I32ToU32 ( static_cast <int32_t> ( x ) + _AB_Alias_U32ToI32 ( LittleToHostEndian32 ( _AB_Alias_I32ToU32 ( reinterpret_cast <int32_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] ) ) ) ) ) )
		#define _ADDBUFFER_ABDESTDATA_INT32_BE(x) reinterpret_cast <int32_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = _AB_Alias_U32ToI32 ( HostToBigEndian32 ( _AB_Alias_I32ToU32 ( static_cast <int32_t> ( x ) + _AB_Alias_U32ToI32 ( BigToHostEndian32 ( _AB_Alias_I32ToU32 ( reinterpret_cast <int32_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] ) ) ) ) ) )
		#define _ADDBUFFER_ABDESTDATA_UINT32_LE(x) reinterpret_cast <uint32_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = HostToLittleEndian32 ( static_cast <uint32_t> ( x ) + LittleToHostEndian32 ( reinterpret_cast <int32_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] ) )
		#define _ADDBUFFER_ABDESTDATA_UINT32_BE(x) reinterpret_cast <uint32_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = HostToBigEndian32 ( static_cast <uint32_t> ( x ) + BigToHostEndian32 ( reinterpret_cast <int32_t *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] ) )
		#define _ADDBUFFER_ABDESTDATA_FLOAT32_LE(x) reinterpret_cast <float *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = HostToLittleEndianFloat ( static_cast <float> ( x ) + LittleToHostEndianFloat ( reinterpret_cast <float *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] ) )
		#define _ADDBUFFER_ABDESTDATA_FLOAT32_BE(x) reinterpret_cast <float *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] = HostToBigEndianFloat ( static_cast <float> ( x ) + BigToHostEndianFloat ( reinterpret_cast <float *> ( Data ) [ ChannelCount * ( TargetStartSample + I ) + TargetChannel ] ) )
		
		switch ( DataType )
		{
			
			case kAudioBufferType_Int8:
			{
				
				switch ( Source.DataType )
				{
				
					case kAudioBufferType_Int8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT8 ( _ADDBUFFERSCALED_ABSOURCEDATA_INT8 );
						
					}
					break;
	
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT8 ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT8 ) - 0x80 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT8 ( _ADDBUFFERSCALED_ABSOURCEDATA_INT16_LE >> 8 ); // TODO: Fix clipping caused by down-conversion mapping to -128 to 128 by finding a way to map to -128 to 127
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT8 ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT16_BE ) / 0x100 );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT8 ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT16_LE >> 8 ) - 0x80 );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT8 ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT16_BE >> 8 ) - 0x80 );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT8 ( _ADDBUFFERSCALED_ABSOURCEDATA_INT32_LE / 0x1000000 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT8 ( _ADDBUFFERSCALED_ABSOURCEDATA_INT32_BE / 0x1000000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT8 ( ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT32_LE >> 24 ) - 0x80 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT8 ( ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT32_BE >> 24 ) - 0x80 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT8 ( _ADDBUFFERSCALED_ABSOURCEDATA_FLOAT32_LE * 127.5 - 0.5 );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT8 ( _ADDBUFFERSCALED_ABSOURCEDATA_FLOAT32_BE * 127.5 - 0.5 );
						
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
							_ADDBUFFER_ABDESTDATA_UINT8 ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT8 ) + 0x80 );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT8 ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT8 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT8 ( static_cast <uint32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT16_LE + 0x8000 ) >> 8 );
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT8 ( static_cast <uint32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT16_BE + 0x8000 ) >> 8 );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT8 ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT16_LE >> 8 );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT8 ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT16_BE >> 8 );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT8 ( ( static_cast <uint32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT32_LE ) + 0x80000000 ) >> 24 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT8 ( ( static_cast <uint32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT32_BE ) + 0x80000000 ) >> 24 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT8 ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT32_LE >> 24 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT8 ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT32_BE >> 24 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT8 ( ( _ADDBUFFERSCALED_ABSOURCEDATA_FLOAT32_LE + 1.0 ) * 127.5 );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT8 ( ( _ADDBUFFERSCALED_ABSOURCEDATA_FLOAT32_BE + 1.0 ) * 127.5 );
						
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
							_ADDBUFFER_ABDESTDATA_INT16_LE ( _ADDBUFFERSCALED_ABSOURCEDATA_INT8 * 0x100 );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT8 << 8 ) - 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_LE ( _ADDBUFFERSCALED_ABSOURCEDATA_INT16_LE );
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_LE ( _ADDBUFFERSCALED_ABSOURCEDATA_INT16_BE );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT16_LE ) - 0x8000 );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT16_BE ) - 0x8000 );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_LE ( _ADDBUFFERSCALED_ABSOURCEDATA_INT32_LE / 0x10000 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_LE ( _ADDBUFFERSCALED_ABSOURCEDATA_INT32_BE / 0x10000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT32_LE >> 16 ) - 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_LE ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT32_BE >> 16 ) - 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_LE ( ( _ADDBUFFERSCALED_ABSOURCEDATA_FLOAT32_LE * 32767.5f ) - 0.5f );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_LE ( ( _ADDBUFFERSCALED_ABSOURCEDATA_FLOAT32_BE * 32767.5 ) - 0.5 );
						
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
							_ADDBUFFER_ABDESTDATA_INT16_BE ( _ADDBUFFERSCALED_ABSOURCEDATA_INT8 * 0x100 );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT8 << 8 ) - 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_BE ( _ADDBUFFERSCALED_ABSOURCEDATA_INT16_LE );
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_BE ( _ADDBUFFERSCALED_ABSOURCEDATA_INT16_BE );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT16_LE ) - 0x8000 );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT16_BE ) - 0x8000 );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_BE ( _ADDBUFFERSCALED_ABSOURCEDATA_INT32_LE / 0x10000 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_BE ( _ADDBUFFERSCALED_ABSOURCEDATA_INT32_BE / 0x10000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT32_LE >> 16 ) - 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_BE ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT32_BE >> 16 ) - 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_BE ( ( _ADDBUFFERSCALED_ABSOURCEDATA_FLOAT32_LE * 32767.5 ) - 0.5 );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT16_BE ( ( _ADDBUFFERSCALED_ABSOURCEDATA_FLOAT32_BE * 32767.5 ) - 0.5 );
						
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
							_ADDBUFFER_ABDESTDATA_UINT16_LE ( static_cast <uint16_t> ( static_cast <int16_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT8 ) + 0x80 ) << 8 );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_LE ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT8 << 8 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_LE ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT16_LE ) + 0x8000 );
							
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_LE ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT16_BE ) + 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_LE ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT16_LE );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_LE ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT16_BE );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_LE ( ( _ADDBUFFERSCALED_ABSOURCEDATA_INT32_LE / 0x10000 ) + 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_LE ( ( _ADDBUFFERSCALED_ABSOURCEDATA_INT32_BE / 0x10000 ) + 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_LE ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT32_LE >> 16 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_LE ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT32_BE >> 16 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_LE ( ( _ADDBUFFERSCALED_ABSOURCEDATA_FLOAT32_LE + 1.0 ) * 32767.5 );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_LE ( ( _ADDBUFFERSCALED_ABSOURCEDATA_FLOAT32_BE + 1.0 ) * 32767.5 );
						
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
							_ADDBUFFER_ABDESTDATA_UINT16_BE ( static_cast <uint16_t> ( static_cast <int16_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT8 ) + 0x80 ) << 8 );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_BE ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT8 << 8 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_BE ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT16_LE ) + 0x8000 );
							
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_BE ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT16_BE ) + 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_BE ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT16_LE );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_BE ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT16_BE );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_BE ( ( _ADDBUFFERSCALED_ABSOURCEDATA_INT32_LE / 0x10000 ) + 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_BE ( ( _ADDBUFFERSCALED_ABSOURCEDATA_INT32_BE / 0x10000 ) + 0x8000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_BE ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT32_LE >> 16 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_BE ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT32_BE >> 16 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_BE ( ( _ADDBUFFERSCALED_ABSOURCEDATA_FLOAT32_LE + 1.0 ) * 32767.5 );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT16_BE ( ( _ADDBUFFERSCALED_ABSOURCEDATA_FLOAT32_BE + 1.0 ) * 32767.5 );
						
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
							_ADDBUFFER_ABDESTDATA_INT32_LE ( _ADDBUFFERSCALED_ABSOURCEDATA_INT8 * 0x1000000 );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_LE ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT8 << 24 ) - 0x800000 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_LE ( _ADDBUFFERSCALED_ABSOURCEDATA_INT16_LE * 0x10000 );
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_LE ( _ADDBUFFERSCALED_ABSOURCEDATA_INT16_BE * 0x10000 );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_LE ( ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT16_LE ) - 0x8000 ) * 0x10000 );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_LE ( ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT16_BE ) - 0x8000 ) * 0x10000 );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_LE ( _ADDBUFFERSCALED_ABSOURCEDATA_INT32_LE );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_LE ( _ADDBUFFERSCALED_ABSOURCEDATA_INT32_BE );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_LE ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT32_LE ) - 0x80000000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_LE ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT32_BE ) - 0x80000000 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_LE ( ( _ADDBUFFERSCALED_ABSOURCEDATA_FLOAT32_BE * 2147483647.5 ) - 0.5 );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_LE ( ( _ADDBUFFERSCALED_ABSOURCEDATA_FLOAT32_BE * 2147483647.5 ) - 0.5 );
						
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
							_ADDBUFFER_ABDESTDATA_INT32_BE ( _ADDBUFFERSCALED_ABSOURCEDATA_INT8 * 0x1000000 );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_BE ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT8 << 24 ) - 0x800000 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_BE ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT16_LE ) * 0x1000 );
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_BE ( _ADDBUFFERSCALED_ABSOURCEDATA_INT16_BE * 0x10000 );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_BE ( ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT16_LE ) - 0x8000 ) * 0x10000 );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_BE ( ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT16_BE ) - 0x8000 ) * 0x10000 );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_BE ( _ADDBUFFERSCALED_ABSOURCEDATA_INT32_LE );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_BE ( _ADDBUFFERSCALED_ABSOURCEDATA_INT32_BE );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_BE ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT32_LE ) - 0x80000000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_BE ( static_cast <int32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT32_BE ) - 0x80000000 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_BE ( ( _ADDBUFFERSCALED_ABSOURCEDATA_FLOAT32_LE * 2147483647.5 ) - 0.5 );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_INT32_BE ( ( _ADDBUFFERSCALED_ABSOURCEDATA_FLOAT32_BE * 2147483647.5 ) - 0.5 );
						
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
							_ADDBUFFER_ABDESTDATA_UINT32_LE ( static_cast <uint32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT8 + 0x80 ) << 24 );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_LE ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT8 << 24 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_LE ( static_cast <uint32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT16_LE + 0x8000 ) << 16 );
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_LE ( static_cast <uint32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT16_BE + 0x8000 ) << 16 );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_LE ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT16_LE << 16 );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_LE ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT16_BE << 16 );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_LE ( _ADDBUFFERSCALED_ABSOURCEDATA_INT32_LE + 0x80000000 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_LE ( _ADDBUFFERSCALED_ABSOURCEDATA_INT32_BE + 0x80000000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_LE ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT32_LE );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_LE ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT32_BE );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_LE ( ( _ADDBUFFERSCALED_ABSOURCEDATA_FLOAT32_LE + 1.0 ) * 2147483647.5 );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_LE ( ( _ADDBUFFERSCALED_ABSOURCEDATA_FLOAT32_BE + 1.0 ) * 2147483647.5 );
						
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
							_ADDBUFFER_ABDESTDATA_UINT32_BE ( static_cast <uint32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT8 + 0x80 ) << 24 );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_BE ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT8 << 24 );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_BE ( static_cast <uint32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT16_LE + 0x8000 ) << 16 );
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_BE ( static_cast <uint32_t> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT16_BE + 0x8000 ) << 16 );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_BE ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT16_LE << 16 );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_BE ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT16_BE << 16 );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_BE ( _ADDBUFFERSCALED_ABSOURCEDATA_INT32_LE + 0x80000000 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_BE ( _ADDBUFFERSCALED_ABSOURCEDATA_INT32_BE + 0x80000000 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_BE ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT32_LE );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_BE ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT32_BE );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_BE ( ( _ADDBUFFERSCALED_ABSOURCEDATA_FLOAT32_LE + 1.0 ) * 2147483647.5f );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_UINT32_BE ( ( _ADDBUFFERSCALED_ABSOURCEDATA_FLOAT32_BE + 1.0 ) * 2147483647.5f );
						
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
							_ADDBUFFER_ABDESTDATA_FLOAT32_LE ( ( static_cast <float> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT8 ) + 0.5f ) * 0.00784313725f );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_LE ( ( static_cast <float> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT8 ) - 127.5f ) * 0.00784313725f );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_LE ( ( static_cast <float> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT16_LE ) + 0.5f ) * 0.00003051804f );
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_LE ( ( static_cast <float> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT16_BE ) + 0.5f ) * 0.00003051804f );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_LE ( ( static_cast <float> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT16_LE ) - 32767.5 ) * 0.00003051804f );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_LE ( ( static_cast <float> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT16_BE ) - 32767.5 ) * 0.00003051804f );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ ) // The center shift here is pointless as a float32 has only 23 fraction bits
							_ADDBUFFER_ABDESTDATA_FLOAT32_LE ( static_cast <float> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT32_LE ) * 4.6566129e-10 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ ) // The center shift here is pointless as a float32 has only 23 fraction bits
							_ADDBUFFER_ABDESTDATA_FLOAT32_LE ( static_cast <float> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT32_BE ) * 4.6566129e-10 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ ) // The center shift here is pointless as a float32 has only 23 fraction bits
							_ADDBUFFER_ABDESTDATA_FLOAT32_LE ( ( static_cast <float> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT32_LE ) - 2147483647.5f ) * 4.6566129e-10 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_LE ( ( static_cast <float> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT32_BE ) - 2147483647.5f ) * 4.6566129e-10 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_LE ( _ADDBUFFERSCALED_ABSOURCEDATA_FLOAT32_LE );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_LE ( _ADDBUFFERSCALED_ABSOURCEDATA_FLOAT32_BE );
						
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
							_ADDBUFFER_ABDESTDATA_FLOAT32_BE ( ( static_cast <float> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT8 ) + 0.5f ) * 0.00784313725f );
						
					}
					break;
					
					case kAudioBufferType_UInt8:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_BE ( ( static_cast <float> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT8 ) - 127.5f ) * 0.00784313725f );
						
					}
					break;
					
					case kAudioBufferType_Int16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_BE ( ( static_cast <float> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT16_LE ) + 0.5f ) * 0.00003051804f );
						
					}
					break;
					
					case kAudioBufferType_Int16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_BE ( ( static_cast <float> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT16_BE ) + 0.5f ) * 0.00003051804f );
						
					}
					break;
					
					case kAudioBufferType_UInt16_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_BE ( ( static_cast <float> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT16_LE ) - 32767.5 ) * 0.00003051804f );
							
					}
					break;
					
					case kAudioBufferType_UInt16_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_BE ( ( static_cast <float> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT16_BE ) - 32767.5 ) * 0.00003051804f );
							
					}
					break;
					
					case kAudioBufferType_Int32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ ) // The center shift here is pointless as a float32 has only 23 fraction bits
							_ADDBUFFER_ABDESTDATA_FLOAT32_BE ( static_cast <float> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT32_LE ) * 4.6566129e-10 );
						
					}
					break;
					
					case kAudioBufferType_Int32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ ) // The center shift here is pointless as a float32 has only 23 fraction bits
							_ADDBUFFER_ABDESTDATA_FLOAT32_BE ( static_cast <float> ( _ADDBUFFERSCALED_ABSOURCEDATA_INT32_BE ) * 4.6566129e-10 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ ) // The center shift here is pointless as a float32 has only 23 fraction bits
							_ADDBUFFER_ABDESTDATA_FLOAT32_BE ( ( static_cast <float> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT32_LE ) - 2147483647.5f ) * 4.6566129e-10 );
						
					}
					break;
					
					case kAudioBufferType_UInt32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_BE ( ( static_cast <float> ( _ADDBUFFERSCALED_ABSOURCEDATA_UINT32_BE ) - 2147483647.5f ) * 4.6566129e-10 );
						
					}
					break;
					
					case kAudioBufferType_Float32_LittleEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_BE ( _ADDBUFFERSCALED_ABSOURCEDATA_FLOAT32_LE );
						
					}
					break;
					
					case kAudioBufferType_Float32_BigEndian:
					{
						
						for ( I = 0; I < SampleCount; I ++ )
							_ADDBUFFER_ABDESTDATA_FLOAT32_BE ( _ADDBUFFERSCALED_ABSOURCEDATA_FLOAT32_LE );
						
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

void Red::Audio::AudioBuffer :: AddBufferResampledScaled ( AudioBuffer & Source, float Scale, ResampleMode Mode, uint32_t Channel, uint64_t SampleCount, uint64_t SourceStartSample, uint64_t TargetStartSample, uint32_t TargetChannel, float SampleRatio )
{
	
	(void) Source;
	(void) Scale;
	(void) Mode;
	(void) Channel;
	(void) SampleCount;
	(void) SourceStartSample;
	(void) TargetStartSample;
	(void) TargetChannel;
	(void) SampleRatio;
	
}


void Red::Audio::AudioBuffer :: AddBufferResampled ( AudioBuffer & Source, ResampleMode Mode, uint32_t SourceChannel, uint64_t SampleCount, uint64_t SourceStartSample, uint64_t TargetStartSample, uint32_t TargetChannel, float SampleRatio )
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

void Red::Audio::AudioBuffer :: ClearBufferFloat ( uint32_t Channel, float Value, uint64_t StartSample, uint64_t SampleCount )
{
	
	(void) Value;
	
	if ( Channel > ChannelCount )
		return;
	
	if ( SampleCount > this -> SampleCount )
		SampleCount = this -> SampleCount;
	
	uint64_t I = 0;
	
	switch ( DataType )
	{
		
		case kAudioBufferType_Float32_LittleEndian:
		{
			
			float CValue = HostToLittleEndianFloat ( Value );
			
			for ( I = StartSample; I < SampleCount; I ++ )
				reinterpret_cast <float *> ( Data ) [ I * ChannelCount + Channel ] = CValue;
			
		}
		break;
		
		case kAudioBufferType_Float32_BigEndian:
		{
			
			float CValue = HostToBigEndianFloat ( Value );
			
			for ( I = StartSample; I < SampleCount; I ++ )
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
			return ClearBufferInt ( Channel, static_cast <int64_t> ( Value ), StartSample, SampleCount );
			
		default:
			return;
		
	}
	
}

void Red::Audio::AudioBuffer :: ClearBufferInt ( uint32_t Channel, int64_t Value, uint64_t StartSample, uint64_t SampleCount )
{
	
	if ( Channel >= ChannelCount )
		return;
	
	uint64_t I;
	
	if ( SampleCount > this -> SampleCount )
		SampleCount = this -> SampleCount;
	
	switch ( DataType )
	{
		
		case kAudioBufferType_Int8:
		{
			
			if ( ChannelCount == 1 )
				memset ( reinterpret_cast <char *> ( Data ), static_cast <char> ( static_cast <int8_t> ( Value ) ), SampleCount );
			else
				for ( I = StartSample; I < SampleCount; I ++ )
					reinterpret_cast <int8_t *> ( Data ) [ I * ChannelCount + Channel ] = static_cast <int8_t> ( Value );
			
		}
		break;
		
		case kAudioBufferType_UInt8:
		{
			
			if ( ChannelCount == 1 )
				memset ( reinterpret_cast <char *> ( Data ), static_cast <char> ( static_cast <uint8_t> ( Value ) ), SampleCount );
			else
				for ( I = StartSample; I < SampleCount; I ++ )
					reinterpret_cast <uint8_t *> ( Data ) [ I * ChannelCount + Channel ] = static_cast <uint8_t> ( Value );
			
		}
		break;
		
		case kAudioBufferType_Int16_LittleEndian:
		{
			
			uint16_t CValue = HostToLittleEndian16 ( _AB_Alias_I16ToU16 ( static_cast <int16_t> ( Value ) ) );
			
			for ( I = StartSample; I < SampleCount; I ++ )
				reinterpret_cast <uint16_t *> ( Data ) [ I * ChannelCount + Channel ] = CValue;
			
		}
		break;
		
		case kAudioBufferType_Int16_BigEndian:
		{
			
			uint16_t CValue = HostToBigEndian16 ( _AB_Alias_I16ToU16 ( static_cast <int16_t> ( Value ) ) );
			
			for ( I = StartSample; I < SampleCount; I ++ )
				reinterpret_cast <uint16_t *> ( Data ) [ I * ChannelCount + Channel ] = CValue;
			
		}
		break;
		
		case kAudioBufferType_UInt16_LittleEndian:
		{
			
			uint16_t CValue = HostToLittleEndian16 ( static_cast <uint16_t> ( Value ) );
			
			for ( I = StartSample; I < SampleCount; I ++ )
				reinterpret_cast <uint16_t *> ( Data ) [ I * ChannelCount + Channel ] = CValue;
			
		}
		break;
		
		case kAudioBufferType_UInt16_BigEndian:
		{
			
			uint16_t CValue = HostToBigEndian16 ( static_cast <uint16_t> ( Value ) );
			
			for ( I = StartSample; I < SampleCount; I ++ )
				reinterpret_cast <uint16_t *> ( Data ) [ I * ChannelCount + Channel ] = CValue;
			
		}
		break;
		
		case kAudioBufferType_Int32_LittleEndian:
		{
			
			uint32_t CValue = HostToLittleEndian32 ( _AB_Alias_I32ToU32 ( static_cast <int32_t> ( Value ) ) );
			
			for ( I = StartSample; I < SampleCount; I ++ )
				reinterpret_cast <uint32_t *> ( Data ) [ I * ChannelCount + Channel ] = CValue;
			
		}
		break;
		
		case kAudioBufferType_Int32_BigEndian:
		{
			
			uint32_t CValue = HostToBigEndian32 ( _AB_Alias_I32ToU32 ( static_cast <int32_t> ( Value ) ) );
			
			for ( I = StartSample; I < SampleCount; I ++ )
				reinterpret_cast <uint32_t *> ( Data ) [ I * ChannelCount + Channel ] = CValue;
			
		}
		break;
		
		case kAudioBufferType_UInt32_LittleEndian:
		{
			
			uint32_t CValue = HostToLittleEndian32 ( static_cast <uint32_t> ( Value ) );
			
			for ( I = StartSample; I < SampleCount; I ++ )
				reinterpret_cast <uint32_t *> ( Data ) [ I * ChannelCount + Channel ] = CValue;
			
		}
		break;
		
		case kAudioBufferType_UInt32_BigEndian:
		{
			
			uint32_t CValue = HostToBigEndian32 ( static_cast <uint32_t> ( Value ) );
			
			for ( I = StartSample; I < SampleCount; I ++ )
				reinterpret_cast <uint32_t *> ( Data ) [ I * ChannelCount + Channel ] = CValue;
			
		}
		break;
		
		case kAudioBufferType_Float32_LittleEndian:
		case kAudioBufferType_Float32_BigEndian:
			return ClearBufferFloat ( Channel, static_cast <float> ( Value ), StartSample, SampleCount );
		
		default:
			return;
		
	}
	
}
