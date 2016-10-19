#ifndef RAUX_FLACFILE_H
#define RAUX_FLACFILE_H

#include <RAUX/RAUX.h>
#include <RAUX/File.h>

#include <Red/Audio/Audio.h>
#include <Red/Audio/AudioBuffer.h>

#include <stdint.h>

namespace RAUX
{
	
	class FLACFile
	{
	public:
		
		static const uint32_t kStatus_Failure_NonExistantFile = 1;
		static const uint32_t kStatus_Failure_Load = 2;
		static const uint32_t kStatus_Failure_FileType = 3;
		static const uint32_t kStatus_Failure_Decode = 4;
		static const uint32_t kStatus_Failure_Memory = 5;
		
		static const uint32_t kLoadFlag_LoadSeekTable = 1;
		
		FLACFile ( const std :: string & Name, uint32_t Flags = 0 );
		~FLACFile ();
		
		bool Exists () const;
		
		const std :: string & GetName () const;
		
		void Load ( uint32_t * Status );
		
		Red::Audio :: AudioBufferType GetFileDataType ();
		
		uint32_t GetSampleRate ();
		uint32_t GetChannelCount ();
		
		Red::Audio :: AudioBuffer * LoadToBuffer ();
		Red::Audio :: AudioBuffer * LoadToReformattedBuffer ( Red::Audio :: AudioBufferType NewType );
		
	private:
		
		static const uint32_t kBlockType_StreamInfo = 0;
		static const uint32_t kBlockType_Padding = 1;
		static const uint32_t kBlockType_Application = 2;
		static const uint32_t kBlockType_SeekTable = 3;
		static const uint32_t kBlockType_VorbisComment = 4;
		static const uint32_t kBlockType_CueSheet = 5;
		static const uint32_t kBlockType_Picture = 6;
		
		static const uint32_t kBlockType_Invalid = 127;
		
		typedef struct
		{
			
			uint32_t MinBlockSize;
			uint32_t MaxBlockSize;
			
			uint32_t MinFrameSize;
			uint32_t MaxFrameSize;
			
			uint32_t SampleRate;
			
			uint32_t ChannelCount;
			
			uint32_t BitsPerSample;
			
			uint64_t SampleCount;
			
			// MD5 Sum would go here. (Not supported because MD5 is another dependancy and not really useful anyway)
			
		} StreamInfo;
		
		typedef struct
		{
			
			uint64_t FrameOffset;
			uint64_t FrameStartSample;
			
			uint32_t SampleCount;
			
		} SeekEntry;
		
		uint32_t ParseMetadataBlock ( uint32_t & Offset, uint32_t * Status );
		
		bool ParseStreamInfoBlock ( uint32_t & Offset, uint32_t Length, uint32_t * Status );
		bool ParsePaddingBlock ( uint32_t & Offset, uint32_t Length, uint32_t * Status );
		bool ParseApplicationBlock ( uint32_t & Offset, uint32_t Length, uint32_t * Status );
		bool ParseSeekTableBlock ( uint32_t & Offset, uint32_t Length, uint32_t * Status );
		bool ParseVorbisCommentBlock ( uint32_t & Offset, uint32_t Length, uint32_t * Status );
		bool ParseCueSheetBlock ( uint32_t & Offset, uint32_t Length, uint32_t * Status );
		bool ParsePictureBlock ( uint32_t & Offset, uint32_t Length, uint32_t * Status );
		
		bool ParseFrame ( uint32_t & Offset, uint32_t * Status );
		
		File FileInstance;
		
		uint32_t Flags;
		
		StreamInfo FLACStreamInfo;
		
		uint32_t ApplicationID;
		
		SeekEntry * SeekTable;
		uint32_t SeekTableSize;
		
	};
	
}

#endif
