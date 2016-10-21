#ifndef RED_AUDIO_AUDIOOUTPUT_H
#define RED_AUDIO_AUDIOOUTPUT_H

#include <Red/Audio/Audio.h>
#include <Red/Audio/IAudioOutputDevice.h>

#include <Red/Util/Function.h>
#include <Red/Util/IRefCounted.h>

namespace Red
{
	
	namespace Audio
	{
		
		class IAudioOutputDevice : public virtual Util :: IRefCounted
		{
		public:
			
			virtual inline ~IAudioOutputDevice () {};
			
			virtual void SetFillCallback ( Util :: IFunction2 <void, uint8_t *, int> * FillFunction ) = 0;
			
			virtual void Lock () = 0;
			virtual void Unlock () = 0;
			
			virtual void Start () = 0;
			virtual void Stop () = 0;
			
			virtual uint32_t GetSampleFrequencey () = 0;
			virtual uint32_t GetSampleSize () = 0;
			virtual uint32_t GetChannelCount () = 0;
			
			virtual AudioBufferType GetSampleFormat () = 0;
			
		};
		
	}
	
}

#endif
