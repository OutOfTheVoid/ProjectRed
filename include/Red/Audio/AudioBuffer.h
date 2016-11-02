#ifndef RED_AUDIO_AUDIOBUFFER_H
#define RED_AUDIO_AUDIOBUFFER_H

#include <stddef.h>
#include <atomic>

#include <Red/Audio/Audio.h>

#include <Red/Util/RefCounted.h>
#include <Red/Util/Function.h>

namespace Red
{
	
	namespace Audio
	{
		
		class AudioBuffer : public virtual Util :: IRefCounted
		{
		public:
			
			typedef enum
			{
				
				kResampleMode_Nearest,
				kResampleMode_Linear
				
			} ResampleMode;
			
			virtual ~AudioBuffer ();
			
			AudioBuffer ( AudioBufferType Type, uint32_t Channels, uint64_t SampleCount, Util :: IFunction1 <bool, AudioBuffer *> * OnUnReferenced = NULL );
			AudioBuffer ( void * Data, AudioBufferType Type, uint32_t Channels, uint64_t SampleCount, Util :: IFunction1 <void, void *> * OnFree = NULL, Util :: IFunction1 <bool, AudioBuffer *> * OnUnReferenced = NULL );
			
			static AudioBuffer * CopyReformated ( AudioBuffer & Source, AudioBufferType NewDataType, uint32_t NewChannelCount = 0 );
			static AudioBuffer * CopyReformatedResampled ( AudioBuffer & Source, ResampleMode Mode, AudioBufferType NewDataType, double SampleRatio, uint32_t NewChannelCount = 0 );
			
			void * GetRawBuffer ();
			
			AudioBufferType GetDataType ();
			uint32_t GetChannelCount ();
			
			uint64_t GetSampleCount ();
			
			void BlitBuffer ( AudioBuffer & Source, uint32_t SourceChannel, uint64_t SampleCount, uint64_t SourceStartSample = 0, uint64_t TargetStartSample = 0, uint32_t TargetChannel = 0xFFFFFFFF );
			void BlitBufferResampled ( AudioBuffer & Source, ResampleMode Mode, uint32_t Channel, uint64_t SampleCount, uint64_t SourceStartSample = 0, uint64_t TargetStartSample = 0, double SampleRatio = 1.0f, uint32_t TargetChannel = 0xFFFFFFFF );
			
			void AddBuffer ( AudioBuffer & Source, uint32_t SourceChannel, uint64_t SampleCount, uint64_t SourceStartSample = 0, uint64_t TargetStartSample = 0, uint32_t TargetChannel = 0xFFFFFFFF );
			void AddBufferResampled ( AudioBuffer & Source, ResampleMode Mode, uint32_t Channel, uint64_t SampleCount, uint64_t SourceStartSample = 0, uint64_t TargetStartSample = 0, uint32_t TargetChannel = 0xFFFFFFFF, double SampleRatio = 1.0f );
			
			void AddBufferScaled ( AudioBuffer & Source, float Scale, uint32_t SourceChannel, uint64_t SampleCount, uint64_t SourceStartSample = 0, uint64_t TargetStartSample = 0, uint32_t TargetChannel = 0xFFFFFFFF );
			void AddBufferResampledScaled ( AudioBuffer & Source, float Scale, ResampleMode Mode, uint32_t Channel, uint64_t SampleCount, uint64_t SourceStartSample = 0, uint64_t TargetStartSample = 0, uint32_t TargetChannel = 0xFFFFFFFF, double SampleRatio = 1.0f );
			
			void ClearBufferFloat ( uint32_t Channel, float Value = 0.0f, uint64_t StartSample = 0, uint64_t SampleCount = 0xFFFFFFFFFFFFFFFF );
			void ClearBufferInt ( uint32_t Channel, int64_t Value = 0, uint64_t StartSample = 0, uint64_t SampleCount = 0xFFFFFFFFFFFFFFFF );
			
			float ReadSampleFloat ( uint32_t Channel, uint64_t Sample );
			int64_t ReadSampleInt ( uint32_t Channel, uint64_t Sample );
			
			void Reference ();
			void Dereference ();
			
			static Util :: Function1 <void, void *> StdFreeWrapper;
			
		private:
			
			void * Data;
			
			AudioBufferType DataType;
			uint32_t ChannelCount;
			
			uint64_t SampleCount;
			
			Util :: IFunction1 <void, void *> * OnFree;
			Util :: IFunction1 <bool, AudioBuffer *> * OnUnReferenced;
			
			std::atomic <uint32_t> RefCount;
			
		};
		
	}
	
}

#endif
