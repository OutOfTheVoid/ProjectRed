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
				
				Echo ( uint64_t Depth, IStreamSource * Input, float PassLevel = 0.8f, float EchoLevel = 0.2f, float Feedback = 0.0f, float FeedForward = 1.0f, uint64_t MaxBackSampleCount = 0 );
				~Echo ();
				
				void SetExpectedFillSize ( uint64_t FillSize );
				StreamFillCode FillAudioBuffer ( AudioBuffer * Buffer, uint32_t TargetChannel );
				
				void SetInput ( IStreamSource * Source );
				void SetEchoDelay ( uint64_t SampleCount );
				
				void SetEnabled ( bool Enabled );
				
				void SetEchoDepth ( uint64_t EchoDepth );
				
				void SetCoefficients ( float PassLevel, float EchoLevel, float Feedback = 0.0f, float FeedForward = 1.0f );
				
			private:
				
				AudioBuffer * EchoBuffer;
				
				uint64_t EchoDepth;
				uint64_t EchoOffset;
				
				IStreamSource * Input;
				
				uint64_t ExpectedFillSize;
				
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
