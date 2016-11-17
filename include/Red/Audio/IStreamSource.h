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
			
			typedef uint32_t StreamFillCode;
			
			static const StreamFillCode kStreamFillCode_Success_Normal = 0;
			static const StreamFillCode kStreamFillCode_Success_Silence = 1;
			static const StreamFillCode kStreamFillCode_Success_DC = 2;
			static const StreamFillCode kStreamFillCode_Success_ControlParameter_Varying = 3;
			static const StreamFillCode kStreamFillCode_Success_ControlParameter_Constant = 4;
			
			static const StreamFillCode kStreamFillCode_ErrorFlag = 0x80000000;
			
			static const StreamFillCode kStreamFillCode_Failure_Silence = 0x7FFFFFFE | kStreamFillCode_ErrorFlag;
			static const StreamFillCode kStreamFillCode_Failure_NoFill = 0x7FFFFFFF | kStreamFillCode_ErrorFlag;
			
			virtual inline ~IStreamSource () {};
			
			virtual void SetExpectedFillSize ( uint64_t FillSize ) = 0;
			
			virtual StreamFillCode FillAudioBuffer ( AudioBuffer * Buffer, uint32_t TargetChannel ) = 0;
			
		};
		
	}
	
}

#endif
