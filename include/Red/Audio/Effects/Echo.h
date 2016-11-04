#ifndef RED_AUDIO_EFFECTS_ECHO_H
#define RED_AUDIO_EFFECTS_ECHO_H

#include <Red/Audio/Effects/Effects.h>
#include <Red/Audio/IStreamSource.h>

#include <Red/Util/RefCounted.h>

#include <Red/Threading/Mutex.h>

#include <stdint.h>

namespace Red
{
	
	namespace Audio
	{
		
		namespace Effects
		{
			
			class Echo : public virtual IStreamSource, public Util :: RefCounted
			{
			public:
				
				Echo ( uint64_t MaxBackSampleCount, IStreamSource * Input, float PassLevel = 0.8f, float EchoLevel = 0.2f, float Feedback = 0.0f, float FeedForward = 1.0f );
				~Echo ();
				
				void SetExpectedFillSize ( uint32_t FillSize ) = 0;
				
				StreamFillCode FillAudioBuffer ( AudioBuffer * Buffer, uint32_t TargetChannel ) = 0;
				
				void SetInput ( IStreamSource * Source );
				void SetEchoDelay ( uint64_t SampleCount );
				
				void SetEnabled ( bool Enabled );
				
				void SetEchoDepth ( uint64_t EchoDepth );
				
				void SetCoefficients ( float PassLevel, float EchoLevel, float Feedback = 0.0f, float FeedForward = 1.0f );
				
			private:
				
				AudioBuffer * EchoBuffer;
				
				uint64_t EchoDepth;
				
				IStreamSource * Input;
				
				float PassLevel;
				float EchoLevel;
				float Feedback;
				float FeedForward;
				
				bool Enabled;
				
				Threading :: Mutex Lock;
				
			};
			
		}
		
	}
	
}

#endif
