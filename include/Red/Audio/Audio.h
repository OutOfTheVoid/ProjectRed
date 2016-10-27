#ifndef RED_AUDIO_AUDIO_H
#define RED_AUDIO_AUDIO_H

#include <Red/Red.h>
#include <Red/Util/Endian.h>

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
			
			kAudioBufferType_Invalid
			
		} AudioBufferType;
		
		#ifndef RED_BIG_ENDIAN_DEFINITE
			static const AudioBufferType kAudioBufferType_Int16_Best = kAudioBufferType_Int16_LittleEndian;
		#else
			static const AudioBufferType kAudioBufferType_Int16_Best = kAudioBufferType_Int16_BigEndian;
		#endif
			
		#ifndef RED_BIG_ENDIAN_DEFINITE
			static const AudioBufferType kAudioBufferType_UInt16_Best = kAudioBufferType_UInt16_LittleEndian;
		#else
			static const AudioBufferType kAudioBufferType_UInt16_Best = kAudioBufferType_UInt16_BigEndian;
		#endif
			
		#ifndef RED_BIG_ENDIAN_DEFINITE
			static const AudioBufferType kAudioBufferType_Int32_Best = kAudioBufferType_Int32_LittleEndian;
		#else
			static const AudioBufferType kAudioBufferType_Int32_Best = kAudioBufferType_Int32_BigEndian;
		#endif
			
		#ifndef RED_BIG_ENDIAN_DEFINITE
			static const AudioBufferType kAudioBufferType_UInt32_Best = kAudioBufferType_UInt32_LittleEndian;
		#else
			static const AudioBufferType kAudioBufferType_UInt32_Best = kAudioBufferType_UInt32_BigEndian;
		#endif
			
		#ifndef RED_BIG_ENDIAN_DEFINITE
			static const AudioBufferType kAudioBufferType_Float32_Best = kAudioBufferType_Float32_LittleEndian;
		#else
			static const AudioBufferType kAudioBufferType_Float32_Best = kAudioBufferType_Float32_BigEndian;
		#endif
			
		static const AudioBufferType kAudioBufferType_PerferredQuality = kAudioBufferType_Float32_Best;
		
		static const AudioBufferType kAudioBufferType_PerferredPerformance = kAudioBufferType_Int32_Best;
		
	}
	
}

#endif
