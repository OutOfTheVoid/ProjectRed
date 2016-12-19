#include <RAUX/TextFile.h>

#include <stdlib.h>
#include <string.h>

#include <iostream>

RAUX::TextFile :: TextFile ( const std :: string & Name, bool Writeable ):
	FileInstance ( Name, Writeable )
{
}

RAUX::TextFile :: ~TextFile ()
{
	
	Close ();
	
}

bool RAUX::TextFile :: Exists () const
{
	
	return FileInstance.Exists ();
	
}

const std :: string & RAUX::TextFile :: GetName () const
{
	
	return FileInstance.GetName ();
	
}

void RAUX::TextFile :: Open ( uint32_t * Status, bool Create )
{
	
	if ( ( ! FileInstance.Exists () ) && ( ! Create ) )
	{
		
		* Status = kStatus_Failure_NonExistantFile;
		
		return;
		
	}
	
	FileInstance.Open ( Status );
	
	if ( * Status != File :: kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return;
		
	}
	
	* Status = kStatus_Success;
	
}

bool RAUX::TextFile :: IsOpen () const
{
	
	return FileInstance.IsOpen ();
	
}

void RAUX::TextFile :: Close ()
{
	
	uint32_t DummyStatus;
	
	FileInstance.Close ( & DummyStatus );
	
}

void RAUX::TextFile :: SetWritable ( uint32_t * Status, bool Writeable, bool Overwrite )
{
	
	if ( ( ! FileInstance.Exists () ) && ( ! Writeable ) )
	{
		
		* Status = kStatus_Failure_NonExistantFile;
		
		return;
		
	}
	
	FileInstance.SetWritable ( Status, Writeable, Overwrite );
	
	if ( * Status != File :: kStatus_Success )
		* Status = kStatus_Failure_Permissions;
	else 
		* Status = kStatus_Success;
	
}

void RAUX::TextFile :: LoadToString ( uint32_t * Status, std :: string & String, uint64_t Offset, uint64_t Length, bool TrimToFileEdge )
{
	
	if ( ! FileInstance.Exists () )
	{
		
		* Status = kStatus_Failure_NonExistantFile;
		
		return;
		
	}
	
	if ( ! FileInstance.IsOpen () )
	{
		
		FileInstance.Open ( Status );
		
		if ( * Status != File :: kStatus_Success )
		{
			
			* Status = kStatus_Failure_Load;
			
			return;
			
		}
		
	}
	else
		FileInstance.Flush ( Status );
	
	uint64_t FileLength = FileInstance.GetLength ( Status );
	
	if ( * Status != File :: kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return;
		
	}
	
	if ( Offset + Length > FileLength )
	{
		
		if ( ( Offset > FileLength ) || ( ! TrimToFileEdge ) )
		{
			
			* Status = kStatus_Failure_FileBounds;
			
			return;
			
		}
		
		Length = FileLength - Offset;
		
	}
	
	if ( Length > RAUX_STACKBUFFER_SIZE )
	{
		
		void * ReadBuffer = malloc ( static_cast <size_t> ( Length ) );
		
		if ( ReadBuffer == NULL )
		{
			
			* Status = kStatus_Failure_MemoryAllocation;
			
			return;
			
		}
		
		FileInstance.Read ( ReadBuffer, Length, Offset, Status );
		
		if ( * Status != File :: kStatus_Success )
		{
			
			free ( ReadBuffer );
			
			* Status = kStatus_Failure_Load;
			
			return;
			
		}
		
		String.assign ( reinterpret_cast <char *> ( ReadBuffer ), Length );
		
		free ( ReadBuffer );
		
		* Status = kStatus_Success;
		
		return;
		
	}
	
	char ReadBuffer [ RAUX_STACKBUFFER_SIZE ];
	
	FileInstance.Read ( reinterpret_cast <void *> ( ReadBuffer ), Length, Offset, Status );
	
	if ( * Status != File :: kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return;
		
	}
	
	String.assign ( reinterpret_cast <char *> ( ReadBuffer ), Length );
	
	* Status = kStatus_Success;
	
}

void RAUX::TextFile :: WriteFromString ( uint32_t * Status, const std :: string & String, uint64_t StringOffset, uint64_t FileOffset, uint64_t Length, bool FillFileGap, char FillChar )
{
	
	if ( StringOffset >= String.size () )
	{
		 
		* Status = kStatus_Failure_StringBounds;
		
		return;
		
	}
	
	if ( StringOffset + Length >= String.size () )
		Length = String.size () - StringOffset;
	
	if ( ! FileInstance.Exists () )
	{
		
		* Status = kStatus_Failure_NonExistantFile;
		
		return;
		
	}
	
	if ( ! FileInstance.IsOpen () )
	{
		
		FileInstance.Open ( Status );
		
		if ( * Status != File :: kStatus_Success )
		{
			
			* Status = kStatus_Failure_Load;
			
			return;
			
		}
		
	}
	
	uint64_t FileLength = FileInstance.GetLength ( Status );
	
	if ( * Status != File :: kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return;
		
	}
	
	if ( FillFileGap )
	{
		
		if ( FileLength < FileOffset )
		{
			
			uint64_t GapSize = FileOffset - FileLength;
			
			uint64_t FillOffset = FileLength;
			uint64_t FillSize = ( GapSize >= 0x1000 ) ? 0x1000 : GapSize;
			
			void * FillBuffer = malloc ( static_cast <size_t> ( 0x1000 ) );
			
			if ( FillBuffer == NULL )
			{
				
				* Status = kStatus_Failure_MemoryAllocation;
				
				return;
				
			}
			
			memset ( FillBuffer, FillChar, static_cast <size_t> ( FillSize ) );
			
			while ( FillOffset < FileOffset )
			{
				
				if ( FillOffset + FillSize > FileOffset )
					FillSize = FileOffset - FillOffset;
				
				FileInstance.Write ( FillBuffer, FillSize, FillOffset, Status );
				
				if ( * Status == File :: kStatus_Failure_Permissions )
				{
					
					* Status = kStatus_Failure_Permissions;
					
					return;
					
				}
				
				if ( * Status != File :: kStatus_Success )
				{
					
					* Status = kStatus_Failure_Write;
					
					return;
					
				}
				
				FillOffset += FillSize;
				
			}
			
			FileLength = FileOffset;
			
			free ( FillBuffer );
			
		}
		
	}
	else
	{
		
		if ( FileOffset > FileLength )
			FileOffset = FileLength;
		
	}
	
	FileInstance.Write ( reinterpret_cast <const void *> ( & String.c_str () [ StringOffset ] ), Length, FileOffset, Status );
	
	if ( * Status == File :: kStatus_Failure_Permissions )
	{
		
		* Status = kStatus_Failure_Permissions;
		
		return;
		
	}
	
	if ( * Status != File :: kStatus_Success )
	{
		
		* Status = kStatus_Failure_Write;
		
		return;
		
	}
	
	* Status = kStatus_Success;
	
}
