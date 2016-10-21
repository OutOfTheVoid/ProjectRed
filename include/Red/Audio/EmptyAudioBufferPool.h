#ifndef RED_AUDIO_AUDIOBUFFERPOOL_H
#define RED_AUDIO_AUDIOBUFFERPOOL_H

#include <Red/Audio/Audio.h>
#include <Red/Audio/AudioBuffer.h>

#include <Red/Util/RefCounted.h>
#include <Red/Util/MethodObjectClosure.h>

#include <Red/Threading/Mutex.h>

#include <vector>

namespace Red
{
	
	namespace Audio
	{
		
		class EmptyAudioBufferPool : public Util :: RefCounted
		{
		public:
			
			EmptyAudioBufferPool ( uint32_t InitialPool = 16, uint32_t MaxFree = 0 );
			~EmptyAudioBufferPool ();
			
			AudioBuffer * New ( void * Data, AudioBufferType Type, uint32_t Channels, uint32_t SampleCount, Util :: IFunction1 <void, void *> * OnFree = NULL );
			
			void DestroyPool ();
			
			void SetFreeCap ( uint32_t MaxFree = 0 );
			void PreallocateTo ( uint32_t ExpectedCount );
			
		private:
			
			bool OnUnReferenceAudioBuffer ( AudioBuffer * Buffer );
			
			uint32_t MaxFree;
			
			std :: vector <AudioBuffer *> Pool;
			Threading :: Mutex PoolLock;
			
			Util::MethodObjectClosure1 <EmptyAudioBufferPool, bool, AudioBuffer *> OnUnReferenceAudioBufferClosure;
			
		};
		
	}
	
}

#endif
