#ifndef RED_AUDIO_AUDIO_H
#define RED_AUDIO_AUDIO_H

#include <Red/Red.h>

namespace Red
{
	
	namespace Audio
	{
		
		typedef enum
		{
			
			kAudioBufferType_Int8,
			kAudioBufferType_UInt8,
			
			kAudioBufferType_Int16_LittleEndian,
			kAudioBufferType_Int16_BigEndian,
			kAudioBufferType_UInt16_LittleEndian,
			kAudioBufferType_UInt16_BigEndian,
			
			kAudioBufferType_Int32_LittleEndian,
			kAudioBufferType_Int32_BigEndian,
			kAudioBufferType_UInt32_LittleEndian,
			kAudioBufferType_UInt32_BigEndian,
			
			kAudioBufferType_Float32_LittleEndian,
			kAudioBufferType_Float32_BigEndian,
			
		} AudioBufferType;
		
	}
	
}

#endif
