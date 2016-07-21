#include <RAUX/TextFile.h>

RAUX::TextFile :: TextFile ( const std :: string & Name ):
FileInstance ( Name )
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

void RAUX::TextFile :: Open ( uint32_t * Status )
{
	
	if ( ! FileInstance.Exists () )
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

void RAUX::TextFile :: Close ()
{
	
	uint32_t DummyStatus;
	
	FileInstance.Close ( & DummyStatus );
	
}

void RAUX::TextFile :: LoadToString ( uint32_t * Status, std :: string & String, uint64_t Offset, uint64_t Length, bool TrimToFileEdge )
{
	
	if ( ! FileInstance.IsOpen () )
	{
		
		FileInstance.Open ( Status );
		
		if ( * Status != File :: kStatus_Success )
		{
			
			* Status = kStatus_Failure_Load;
			
			return;
			
		}
		
	}
	
	int64_t FileLength = FileInstance.GetLength ( Status );
	
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