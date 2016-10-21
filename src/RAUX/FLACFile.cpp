#include <RAUX/FLACFile.h>
#include <Red/Util/Endian.h>

#include <iostream>

RAUX::FLACFile :: FLACFile ( const std :: string & Name, uint32_t Flags ):
	FileInstance ( Name, false ),
	Flags ( Flags ),
	FLACStreamInfo { 0, 0, 0, 0, 0, 0, 0, 0 },
	SeekTable ( NULL ),
	SeekTableSize ( 0 )
{
}

RAUX::FLACFile :: ~FLACFile ()
{
	
	if ( SeekTable != NULL )
		delete[] SeekTable;
	
	SeekTable = NULL;
	
}

bool RAUX::FLACFile :: Exists () const
{
	
	return FileInstance.Exists ();
	
}

const std :: string & RAUX::FLACFile :: GetName () const
{
	
	return FileInstance.GetName ();
	
}

void RAUX::FLACFile :: Load ( uint32_t * Status )
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
	
	
	
	// TODO: Implement
	
}

/* RETURN:
*
* 0: Parsed successfully. More to follow
* 1: Parsed successfully, Audio data follows
* 2: Ignored, future block type
* 3: Parse failed
*
*/
uint32_t RAUX::FLACFile :: ParseMetadataBlock ( uint32_t & Offset, uint32_t * Status )
{
	
	uint32_t Temp;
	
	uint32_t DummyStatus;
	
	FileInstance.Read ( reinterpret_cast <void *> ( & Temp ), 4, Offset, & DummyStatus );
	
	if ( DummyStatus != File :: kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return 3;
		
	}
	
	Offset += 4;
	
	Temp = BigToHostEndian32 ( Temp );
	
	bool LastMetadata = false;
	
	if ( ( Temp & 0x00000001 ) != 0 )
		LastMetadata = true;
	
	uint32_t BlockType = ( Temp >> 1 ) & 0x7F;
	uint32_t BlockLength = ( Temp >> 8 ) & 0xFFFFFF;
	
	switch ( BlockType )
	{
		
		case kBlockType_StreamInfo:
		{
			
			if ( ! ParseStreamInfoBlock ( Offset, BlockLength, Status ) )
				return 3;
				
		}
		break;
		
		case kBlockType_Padding:
		{
			
			if ( ! ParsePaddingBlock ( Offset, BlockLength, Status ) )
				return 3;
				
		}
		break;
		
		case kBlockType_Application:
		{
			
			if ( ! ParseApplicationBlock ( Offset, BlockLength, Status ) )
				return 3;
				
		}
		break;
		
		case kBlockType_SeekTable:
		{
			
			if ( ! ParseSeekTableBlock ( Offset, BlockLength, Status ) )
				return 3;
				
		}
		break;
		
		case kBlockType_VorbisComment:
		{
			
			if ( ! ParseVorbisCommentBlock ( Offset, BlockLength, Status ) )
				return 3;
				
		}
		break;
		
		case kBlockType_CueSheet:
		{
			
			if ( ! ParseCueSheetBlock ( Offset, BlockLength, Status ) )
				return 3;
				
		}
		break;
		
		case kBlockType_Picture:
		{
			
			if ( ! ParsePictureBlock ( Offset, BlockLength, Status ) )
				return 3;
				
		}
		break;
		
		case kBlockType_Invalid:
		{
			
			* Status = kStatus_Failure_Decode;
			
			return 3;
			
		}
		break;
		
		default:
		{
			
			Offset += BlockLength;
			
			return 2;
			
		}
		break;
		
	}
	
	return LastMetadata ? 1 : 0;
	
}

bool RAUX::FLACFile :: ParseStreamInfoBlock ( uint32_t & Offset, uint32_t Length, uint32_t * Status )
{
	
	uint16_t Temp16;
	uint32_t Temp32;
	uint64_t Temp64;
	
	uint32_t DummyStatus;
	
	FileInstance.Read ( reinterpret_cast <void *> ( & Temp16 ), 2, Offset, & DummyStatus );
	
	if ( DummyStatus != File :: kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return false;
		
	}
	
	FLACStreamInfo.MinBlockSize = static_cast <uint32_t> ( BigToHostEndian16 ( Temp16 ) );
	
	FileInstance.Read ( reinterpret_cast <void *> ( & Temp16 ), 2, Offset + 2, & DummyStatus );
	
	if ( DummyStatus != File :: kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return false;
		
	}
	
	FLACStreamInfo.MaxBlockSize = static_cast <uint32_t> ( BigToHostEndian16 ( Temp16 ) );
	
	Temp32 = 0;
	
	FileInstance.Read ( reinterpret_cast <void *> ( & Temp32 ), 3, Offset + 4, & DummyStatus );
	
	if ( DummyStatus != File :: kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return false;
		
	}
	
	FLACStreamInfo.MinFrameSize = static_cast <uint32_t> ( BigToHostEndian32 ( Temp32 << 8 ) );
	
	Temp32 = 0;
	
	FileInstance.Read ( reinterpret_cast <void *> ( & Temp32 ), 3, Offset + 7, & DummyStatus );
	
	if ( DummyStatus != File :: kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return false;
		
	}
	
	FLACStreamInfo.MaxFrameSize = static_cast <uint32_t> ( BigToHostEndian32 ( Temp32 << 8 ) );
	
	Temp64 = 0;
	
	FileInstance.Read ( reinterpret_cast <void *> ( & Temp64 ), 8, Offset + 10, & DummyStatus );
	
	if ( DummyStatus != File :: kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return false;
		
	}
	
	FLACStreamInfo.SampleRate = BigToHostEndian32 ( static_cast <uint32_t> ( ( Temp64 & 0xFFFFF ) << 12 ) );
	FLACStreamInfo.ChannelCount = BigToHostEndian32 ( static_cast <uint32_t> ( ( Temp64 & 0x700000 ) << 9 ) );
	FLACStreamInfo.BitsPerSample = BigToHostEndian32 ( static_cast <uint32_t> ( ( Temp64 & 0x0F800000 ) << 4 ) );
	FLACStreamInfo.SampleCount = BigToHostEndian64 ( Temp64 & 0xFFFFFFFFF0000000 );
	
	Offset += Length;
	
	return true;
	
}

bool RAUX::FLACFile :: ParsePaddingBlock ( uint32_t & Offset, uint32_t Length, uint32_t * Status )
{
	
	(void) Status;
	
	Offset += Length;
	
	return true;
	
}

bool RAUX::FLACFile :: ParseApplicationBlock ( uint32_t & Offset, uint32_t Length, uint32_t * Status )
{
	
	uint32_t Temp32;
	
	uint32_t DummyStatus;
	
	FileInstance.Read ( reinterpret_cast <void *> ( & Temp32 ), 4, Offset, & DummyStatus );
	
	if ( DummyStatus != File :: kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return false;
		
	}
	
	ApplicationID = BigToHostEndian32 ( Temp32 );
	
	Offset += Length;
	
	return true;
	
}

bool RAUX::FLACFile :: ParseSeekTableBlock ( uint32_t & Offset, uint32_t Length, uint32_t * Status )
{
	
	uint32_t DummyStatus;
	
	uint64_t Temp64;
	uint16_t Temp16;
	
	uint32_t SeekEntryCount = Length / 18;
	
	if ( ( SeekEntryCount != 0 ) && ( ( Flags & kLoadFlag_LoadSeekTable ) != 0 ) )
	{
		
		if ( SeekTable != NULL )
			delete[] SeekTable;
		
		SeekTable = new SeekEntry [ SeekEntryCount ];
		SeekTableSize = SeekEntryCount;
		
		for ( uint32_t I = 0; I < SeekEntryCount; I ++ )
		{
			
			FileInstance.Read ( reinterpret_cast <void *> ( & Temp64 ), 8, Offset + 18 * I, & DummyStatus );
			
			if ( DummyStatus != File :: kStatus_Success )
			{
				
				delete[] SeekTable;
				SeekTable = NULL;
				SeekTableSize = 0;
				
				* Status = kStatus_Failure_Load;
				
				return false;
				
			}
			
			SeekTable [ I ].FrameStartSample = BigToHostEndian64 ( Temp64 );
			
			FileInstance.Read ( reinterpret_cast <void *> ( & Temp64 ), 8, Offset + 8 + 18 * I, & DummyStatus );
			
			if ( DummyStatus != File :: kStatus_Success )
			{
				
				delete[] SeekTable;
				SeekTable = NULL;
				SeekTableSize = 0;
				
				* Status = kStatus_Failure_Load;
				
				return false;
				
			}
			
			SeekTable [ I ].FrameOffset = BigToHostEndian64 ( Temp64 );
			
			FileInstance.Read ( reinterpret_cast <void *> ( & Temp16 ), 2, Offset + 16 + 18 * I, & DummyStatus );
			
			if ( DummyStatus != File :: kStatus_Success )
			{
				
				delete[] SeekTable;
				SeekTable = NULL;
				SeekTableSize = 0;
				
				* Status = kStatus_Failure_Load;
				
				return false;
				
			}
			
			SeekTable [ I ].SampleCount = BigToHostEndian16 ( Temp16 );
			
		}
		
	}
	
	Offset += Length;
	
	return true;
	
}

bool RAUX::FLACFile :: ParseVorbisCommentBlock ( uint32_t & Offset, uint32_t Length, uint32_t * Status )
{
	
	(void) Status;
	
	// I'm not particularly interested in OGG Vorbis comments. Oops.
	Offset += Length;
	
	return false;
	
}

bool RAUX::FLACFile :: ParseCueSheetBlock ( uint32_t & Offset, uint32_t Length, uint32_t * Status )
{
	
	(void) Status;
	
	// This may prove usefull eventually, but for now it's not interesting.
	Offset += Length;
	
	return false;
	
}

bool RAUX::FLACFile :: ParsePictureBlock ( uint32_t & Offset, uint32_t Length, uint32_t * Status )
{
	
	(void) Status;
	
	// This may prove usefull eventually, but for now it's not interesting.
	// Eventually, integrate PNG support through PNGFile when raw binary parsing is supported.
	Offset += Length;
	
	return false;
	
}
