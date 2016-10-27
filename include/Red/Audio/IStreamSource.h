#ifndef RED_AUDIO_ISTREAMSOURCE_H
#define RED_AUDIO_ISTREAMSOURCE_H

#include <Red/Audio/Audio.h>
#include <Red/Audio/AudioBuffer.h>

#include <Red/Util/IRefCounted.h>

#include <stdint.h>

namespace Red
{
	
	namespace Audio
	{
		
		class IStreamSource : public virtual Util :: IRefCounted
		{
		public:
			
			virtual inline ~IStreamSource () {};
			
			virtual void SetExpectedFillSize ( uint32_t FillSize ) = 0;
			
			virtual void FillAudioBuffer ( AudioBuffer * Buffer, uint32_t TargetChannel ) = 0;
			
		};
		
	}
	
}

#endif
