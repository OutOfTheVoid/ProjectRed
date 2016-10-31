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
			
			RawBufferStreamSource ( AudioBuffer * SourceData, uint32_t Channel = 0, uint64_t Offset = 0, uint64_t FinishPoint = 0xFFFFFFFFFFFFFFFFULL );
			~RawBufferStreamSource ();
			
			void SetFinishedCallback ( Util :: IFunction1 <bool, RawBufferStreamSource *> * Callback = NULL );
			void SetOffset ( uint64_t Offset );
			void SetFinishPoint ( uint64_t Finish );
			
			void SetExpectedFillSize ( uint32_t FillSize );
			
			void ResetSource ( AudioBuffer * SourceData, uint32_t Channel = 0, uint64_t Offset = 0, uint64_t FinishPoint = 0xFFFFFFFFFFFFFFFFULL );
			
			StreamFillCode FillAudioBuffer ( AudioBuffer * Buffer, uint32_t TargetChannel );
			
		private:
			
			AudioBuffer * SourceData;
			
			uint32_t Channel;
			
			uint64_t Offset;
			uint64_t FinishOffset;
			
			Util :: IFunction1 <bool, RawBufferStreamSource *> * FinishedCallback;
			
			Threading :: Mutex Lock;
			
		};
		
	}
	
}

#endif
