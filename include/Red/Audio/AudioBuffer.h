#ifndef RED_AUDIO_AUDIOBUFFER_H
#define RED_AUDIO_AUDIOBUFFER_H

#include <stddef.h>

#include <Red/Audio/Audio.h>

#include <Red/Util/RefCounted.h>
#include <Red/Util/Function.h>

namespace Red
{
	
	namespace Audio
	{
		
		class AudioBuffer : public Util :: RefCounted
		{
		public:
			
			~AudioBuffer ();
			
			AudioBuffer ( void * Data, AudioBufferType Type, uint32_t Channels, uint32_t SampleCount, Util :: IFunction1 <void, void *> * OnFree = NULL );
			
			static AudioBuffer * CopyReformated ( AudioBuffer & Source, AudioBufferType NewDataType, uint32_t NewChannelCount = 0 );
			static AudioBuffer * CopyReformatedResampled ( AudioBuffer & Source, AudioBufferType NewDataType, uint32_t NewChannelCount = 0, float SampleRatio = 1.0f );
			
			void * GetRawBuffer ();
			
			AudioBufferType GetDataType ();
			uint32_t GetChannelCount ();
			
			uint32_t GetSampleCount ();
			
			void BlitBuffer ( AudioBuffer & Source, uint32_t SourceChannel, uint32_t SampleCount, uint32_t SourceStartSample = 0, uint32_t TargetStartSample = 0, uint32_t TargetChannel = 0xFFFFFFFF );
			void BlitBufferResampled ( AudioBuffer & Source, uint32_t Channel, uint32_t SampleCount, uint32_t SourceStartSample = 0, uint32_t TargetStartSample = 0, float SampleRatio = 1.0f, uint32_t TargetChannel = 0xFFFFFFFF );
			
			void AddBuffer ( AudioBuffer & Source, uint32_t SourceChannel, uint32_t SampleCount, uint32_t SourceStartSample = 0, uint32_t TargetStartSample = 0, uint32_t TargetChannel = 0xFFFFFFFF );
			void AddBufferResampled ( AudioBuffer & Source, uint32_t Channel, uint32_t SampleCount, uint32_t SourceStartSample = 0, uint32_t TargetStartSample = 0, uint32_t TargetChannel = 0xFFFFFFFF, float SampleRatio = 1.0f );
			
			void ClearBufferFloat ( uint32_t Channel, float Value = 0.0f );
			void ClearBufferInt ( uint32_t Channel, int32_t Value = 0 );
			
			static Util :: Function1 <void, void *> StdFreeWrapper;
			
		private:
			
			void * Data;
			
			AudioBufferType DataType;
			uint32_t ChannelCount;
			
			uint32_t SampleCount;
			
			Util :: IFunction1 <void, void *> * OnFree;
			
		};
		
	}
	
}

#endif
