#ifndef RED_AUDIO_STREAMMIXER_H
#define RED_AUDIO_STREAMMIXER_H

#include <stdint.h>

#include <Red/Audio/IStreamSource.h>
#include <Red/Audio/AudioBuffer.h>
#include <Red/Audio/Audio.h>

#include <Red/Util/RefCounted.h>

#include <Red/Threading/Mutex.h>

namespace Red
{
	
	namespace Audio
	{
		
		class StreamMixer : public IStreamSource, public Util :: RefCounted
		{
		public:
			
			static const uint32_t kStream_Invalid = 0xFFFFFFFF;
			
			StreamMixer ( AudioBufferType IntermediaryBufferType, uint32_t MaxChannelCount = 8 );
			~StreamMixer ();
			
			uint32_t AddStream ( IStreamSource * Source, float InitialScaleFactor, bool InitiallyMuted = false );
			uint32_t GetFirstStreamBySource ( IStreamSource * Source );
			void RemoveStream ( uint32_t Index );
			
			void SetStreamScale ( uint32_t Index, float ScaleFactor );
			
			void SetStreamMuted ( uint32_t Index, bool Muted );
			
			// IStreamSource
			void SetExpectedFillSize ( uint32_t FillSize );
			StreamFillCode FillAudioBuffer ( AudioBuffer * Buffer, uint32_t TargetChannel );
			
		private:
			
			typedef struct
			{
				
				IStreamSource * Source;
				
				std :: atomic <float> Scale;
				std :: atomic <bool> Muted;
				
			} Stream;
			
			Stream * Streams;
			uint32_t StreamCount;
			Threading :: Mutex StreamsLock;
			
			uint32_t FillSize;
			
			AudioBuffer * IntermediaryBuffer;
			
			AudioBufferType IntermediaryBufferType;
			
		};
		
	}
	
}

#endif
