#include <RAUX/WAVFile.h>
#include <Red/Util/Endian.h>

#include <stdlib.h>

RAUX::WAVFile :: WAVFile ( const std :: string & Name ):
	FileInstance ( Name, false ),
	ChannelCount ( 0 ),
	SampleRate ( 0 ),
	BlockAlign ( 0 ),
	BitsPerSample ( 0 ),
	DataSize ( 0 ),
	DataOffset ( 0 )
{
}

RAUX::WAVFile :: ~WAVFile ()
{
}

bool RAUX::WAVFile :: Exists () const
{
	
	return FileInstance.Exists ();
	
}

const std :: string & RAUX::WAVFile :: GetName () const
{
	
	return FileInstance.GetName ();
	
}

void RAUX::WAVFile :: Close ( uint32_t * Status )
{

	uint32_t DummyStatus;
	
	FileInstance.Close ( & DummyStatus );
	
	if ( DummyStatus != kStatus_Success )
		* Status = kStatus_Failure_Load;
	else
		* Status = kStatus_Success;
	
}

void RAUX::WAVFile :: Load ( uint32_t * Status )
{
	
	uint32_t DummyStatus;
	
	if ( ! FileInstance.Exists () )
	{
		
		* Status = kStatus_Failure_NonExistantFile;
		
		return;
		
	}
	
	FileInstance.Open ( & DummyStatus );
	
	if ( DummyStatus != File :: kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return;
		
	}
	
	uint32_t Temp;
	
	FileInstance.Read ( reinterpret_cast <void *> ( & Temp ), 4, 0, & DummyStatus );
	
	if ( DummyStatus != kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return;
		
	}
	
	if ( BigToHostEndian32 ( Temp ) != kMagicNumber_Header )
	{
		
		* Status = kStatus_Failure_FileType;
		
		return;
		
	}
	
	FileInstance.Read ( reinterpret_cast <void *> ( & Temp ), 4, 4, & DummyStatus );
	
	if ( DummyStatus != kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return;
		
	}
	
	uint32_t FileSize = LittleToHostEndian32 ( Temp ) + 8;
	
	FileInstance.Read ( reinterpret_cast <void *> ( & Temp ), 4, 8, & DummyStatus );
	
	if ( DummyStatus != kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return;
		
	}
	
	if ( BigToHostEndian32 ( Temp ) != kMagicNumber_Format )
	{
		
		* Status = kStatus_Failure_FileType;
		
		return;
		
	}
	
	uint32_t Offset = 12;
	
	
	uint32_t SectionCount = 0;
	
	while ( Offset < FileSize )
	{
		
		SectionCount ++;
		
		ProcessChunk ( Offset, & DummyStatus );
		
		if ( DummyStatus != kStatus_Success )
		{
			
			* Status = kStatus_Failure_Decode;
			
			return;
			
		}
		
	}
	
	* Status = kStatus_Success;
	
}

void RAUX::WAVFile :: ProcessChunk ( uint32_t & Offset, uint32_t * Status )
{
	
	uint32_t Temp;
	uint32_t DummyStatus;
	
	FileInstance.Read ( reinterpret_cast <void *> ( & Temp ), 4, Offset, & DummyStatus );
	
	if ( DummyStatus != kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return;
		
	}
	
	switch ( BigToHostEndian32 ( Temp ) )
	{
		
		case kChunkID_Format:
			return ProcessFormatChunk ( Offset, Status );
			
		case kChunkID_Data:
			return ProcessDataChunk ( Offset, Status );
			
		default:
			return ProcessDummyChunk ( Offset, Status );
		
	}
	
}

void RAUX::WAVFile :: ProcessFormatChunk ( uint32_t & Offset, uint32_t * Status )
{
	
	uint32_t DummyStatus;
	uint32_t Temp;
	
	FileInstance.Read ( reinterpret_cast <void *> ( & Temp ), 4, Offset + 4, & DummyStatus );
	
	if ( DummyStatus != kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return;
		
	}
	
	uint32_t ChunkSize = LittleToHostEndian32 ( Temp );
	
	uint16_t Temp16;
	
	FileInstance.Read ( reinterpret_cast <void *> ( & Temp16 ), 2, Offset + 8, & DummyStatus );
	
	if ( DummyStatus != kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return;
		
	}
	
	if ( LittleToHostEndian16 ( Temp16 ) != 1 )
	{
		
		* Status = kStatus_Failure_FileType;
		
		return;
		
	}
	
	FileInstance.Read ( reinterpret_cast <void *> ( & Temp16 ), 2, Offset + 10, & DummyStatus );
	
	if ( DummyStatus != kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return;
		
	}
	
	ChannelCount = LittleToHostEndian16 ( Temp16 );
	
	FileInstance.Read ( reinterpret_cast <void *> ( & Temp ), 4, Offset + 12, & DummyStatus );
	
	if ( DummyStatus != kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return;
		
	}
	
	SampleRate = LittleToHostEndian32 ( Temp );
	
	FileInstance.Read ( reinterpret_cast <void *> ( & Temp16 ), 2, Offset + 20, & DummyStatus );
	
	if ( DummyStatus != kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return;
		
	}
	
	BlockAlign = LittleToHostEndian16 ( Temp16 );
	
	FileInstance.Read ( reinterpret_cast <void *> ( & Temp16 ), 2, Offset + 22, & DummyStatus );
	
	if ( DummyStatus != kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return;
		
	}
	
	BitsPerSample = LittleToHostEndian16 ( Temp16 );
	
	Offset += ChunkSize + 8;
	
}

void RAUX::WAVFile :: ProcessDataChunk ( uint32_t & Offset, uint32_t * Status )
{
	
	uint32_t DummyStatus;
	uint32_t Temp;
	
	FileInstance.Read ( reinterpret_cast <void *> ( & Temp ), 4, Offset + 4, & DummyStatus );
	
	if ( DummyStatus != kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return;
		
	}
	
	DataSize = LittleToHostEndian32 ( Temp );
	DataOffset = Offset + 8;
	Offset += DataSize + 8;
	
}

void RAUX::WAVFile :: ProcessDummyChunk ( uint32_t & Offset, uint32_t * Status )
{
	
	uint32_t DummyStatus;
	uint32_t Temp;
	
	FileInstance.Read ( reinterpret_cast <void *> ( & Temp ), 4, Offset + 4, & DummyStatus );
	
	if ( DummyStatus != kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return;
		
	}
	
	Offset += LittleToHostEndian32 ( Temp ) + 8;
	
}

uint32_t RAUX::WAVFile :: GetSampleRate ()
{
	
	return SampleRate;
	
}

uint32_t RAUX::WAVFile :: GetChannelCount ()
{
	
	return ChannelCount;
	
}

Red::Audio :: AudioBufferType RAUX::WAVFile :: GetFileDataType ()
{
	
	switch ( BitsPerSample )
	{
		
		case 8:
			return Red::Audio :: kAudioBufferType_UInt8;
			
		case 16:
			return Red::Audio :: kAudioBufferType_Int16_LittleEndian;
		
	}
	
	// Probably should have some invalid sentenial, but ideally this will never happen...
	return Red::Audio :: kAudioBufferType_UInt8;
	
}

Red::Audio :: AudioBuffer * RAUX::WAVFile :: LoadToBuffer ()
{
	
	uint32_t DummyStatus;
	
	if ( ( BitsPerSample == 0 ) || ( DataSize == 0 ) || ( DataOffset == 0 ) )
		return NULL;
	
	void * DataBuff = malloc ( DataSize );
	
	if ( DataBuff == NULL )
		return NULL;
	
	FileInstance.Read ( DataBuff, DataSize, DataOffset, & DummyStatus );
	
	if ( DummyStatus != File :: kStatus_Success )
	{
		
		free ( DataBuff );
		
		return NULL;
		
	}
	
	uint32_t SampleCount = ( DataSize / ChannelCount ) / ( BitsPerSample >> 3 );
	
	switch ( BitsPerSample )
	{
		
		case 8:
			return new Red::Audio :: AudioBuffer ( DataBuff, Red::Audio :: kAudioBufferType_UInt8, ChannelCount, SampleCount, & Red::Audio::AudioBuffer :: StdFreeWrapper );
		
		case 16:
			return new Red::Audio :: AudioBuffer ( DataBuff, Red::Audio :: kAudioBufferType_Int16_LittleEndian, ChannelCount, SampleCount, & Red::Audio::AudioBuffer :: StdFreeWrapper );
		
		default:
		{
			
			free ( DataBuff );
			
			return NULL;
			
		}
		
	}
	
	return NULL;
	
}

Red::Audio :: AudioBuffer * RAUX::WAVFile :: LoadToReformattedBuffer ( Red::Audio :: AudioBufferType NewType )
{
	
	Red::Audio :: AudioBuffer * TemporaryBuffer = LoadToBuffer ();
	
	if ( TemporaryBuffer != NULL )
	{
		
		Red::Audio :: AudioBuffer * NewBuffer = Red::Audio::AudioBuffer :: CopyReformated ( * TemporaryBuffer, NewType );
		
		delete TemporaryBuffer;
		return NewBuffer;
		
	}
	
	delete TemporaryBuffer;
	
	return NULL;
	
}
