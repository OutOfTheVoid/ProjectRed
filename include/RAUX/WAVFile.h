#ifndef RAUX_WAVFILE_H
#define RAUX_WAVFILE_H

#include <RAUX/RAUX.h>
#include <RAUX/File.h>

#include <Red/Audio/Audio.h>
#include <Red/Audio/AudioBuffer.h>

#include <string>

namespace RAUX
{
	
	class WAVFile
	{
	public:
		
		static const uint32_t kStatus_Success = 0;
		
		static const uint32_t kStatus_Failure_NonExistantFile = 1;
		static const uint32_t kStatus_Failure_Load = 2;
		static const uint32_t kStatus_Failure_FileType = 3;
		static const uint32_t kStatus_Failure_Decode = 4;
		static const uint32_t kStatus_Failure_Memory = 5;
		
		
		WAVFile ( const std :: string & Name );
		~WAVFile ();
		
		bool Exists () const;
		
		const std :: string & GetName () const;
		
		void Load ( uint32_t * Status );
		
		Red::Audio :: AudioBufferType GetFileDataType ();
		
		uint32_t GetSampleRate ();
		uint32_t GetChannelCount ();
		
		Red::Audio :: AudioBuffer * LoadToBuffer ();
		Red::Audio :: AudioBuffer * LoadToReformattedBuffer ();
		
	private:
		
		void ProcessChunk ( uint32_t & Offset, uint32_t * Status );
		void ProcessFormatChunk ( uint32_t & Offset, uint32_t * Status );
		void ProcessDataChunk ( uint32_t & Offset, uint32_t * Status );
		void ProcessDummyChunk ( uint32_t & Offset, uint32_t * Status );
		
		static const uint32_t kMagicNumber_Header = 0x52494646;
		static const uint32_t kMagicNumber_Format = 0x57415645;
		
		static const uint32_t kChunkID_Format = 0x666d7420;
		static const uint32_t kChunkID_Data = 0x64617461;
		
		File FileInstance;
		
		uint32_t ChannelCount;
		uint32_t SampleRate;
		uint32_t BlockAlign;
		uint32_t BitsPerSample;
		
		uint32_t DataSize;
		uint32_t DataOffset;
		
	};
	
}

#endif
