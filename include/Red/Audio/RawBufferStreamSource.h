#ifndef RED_AUDIO_RAWBUFFERSTREAMSOURCE_H
#define RED_AUDIO_RAWBUFFERSTREAMSOURCE_H

#include <Red/Audio/Audio.h>
#include <Red/Audio/AudioBuffer.h>
#include <Red/Audio/IStreamSource.h>

#include <Red/Util/Function.h>
#include <Red/Util/RefCounted.h>

#include <Red/Threading/Mutex.h>

#include <stdint.h>

namespace Red
{
	
	namespace Audio
	{
		
		class RawBufferStreamSource : public virtual IStreamSource, public Util :: RefCounted
		{
		public:
			
			RawBufferStreamSource ( AudioBuffer * SourceData, uint32_t Channel = 0, uint64_t Offset = 0, uint64_t FinishPoint = 0xFFFFFFFFFFFFFFFFULL, uint64_t StartDelay = 0, bool InitiallyPlaying = true );
			~RawBufferStreamSource ();
			
			void ResetDelayCounter ( uint64_t DelayCounter = 0 );
			void SetStartDelay ( uint64_t StartDelay );
			void SetFinishedCallback ( Util :: IFunction1 <void, RawBufferStreamSource *> * Callback = NULL );
			void SetOffset ( uint64_t Offset );
			void SetFinishPoint ( uint64_t Finish );
			
			void SetPlaying ( bool Playing );
			
			bool IsPlaying ();
			
			void ResetSource ( AudioBuffer * SourceData, uint32_t Channel = 0, uint64_t Offset = 0, uint64_t FinishPoint = 0xFFFFFFFFFFFFFFFFULL, uint64_t StartDelay = 0, bool InitiallyPlaying = true );
			
			// IStreamSource
			void SetExpectedFillSize ( uint64_t FillSize );
			
			StreamFillCode FillAudioBuffer ( AudioBuffer * Buffer, uint32_t TargetChannel );
			
		private:
			
			AudioBuffer * SourceData;
			
			uint32_t Channel;
			
			uint64_t Offset;
			uint64_t FinishOffset;
			
			uint64_t StartDelay;
			uint64_t DelayCounter;
			
			bool Playing;
			
			Util :: IFunction1 <void, RawBufferStreamSource *> * FinishedCallback;
			
			Threading :: Mutex Lock;
			
		};
		
	}
	
}

#endif
