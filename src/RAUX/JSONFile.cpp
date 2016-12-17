#include <RAUX/JSONFile.h>

RAUX::JSONFile :: JSONFile ( const std :: string & Path, bool Writable, Red::Data::JSON::Decoder :: DecodeFlags DecFlags, Red::Data::JSON::Encoder :: EncodeFlags EncFlags, const std :: string & NewlineSequence ):
	FileInstance ( Path, Writable ),
	JSONBuffer ( "null" ),
	JSONDecoder ( DecFlags ),
	JSONEncoder ( EncFlags, 0, NewlineSequence )
{
}

RAUX::JSONFile :: ~JSONFile ()
{
}

bool RAUX::JSONFile :: Exists () const
{
	
	return FileInstance.Exists ();
	
}

const std :: string & RAUX::JSONFile :: GetName () const
{
	
	return FileInstance.GetName ();
	
}

// Load and close a file.
void RAUX::JSONFile :: Load ( bool ToDecode, uint32_t * Status )
{
	
	if ( ! FileInstance.Exists () )
	{
		
		* Status = kStatus_Failure_NonExistantFile;
		
		return;
		
	}
	
	if ( ! FileInstance.IsOpen () )
	{
		
		FileInstance.Open ( Status );
		
		if ( * Status != kStatus_Success )
		{
			
			* Status = kStatus_Failure_Load;
			
			return;
			
		}
		
	}
	
	if ( ToDecode )
	{
		
		FileInstance.LoadToString ( Status, JSONBuffer, 0 );
		
		if ( * Status != kStatus_Success )
		{
			
			* Status = kStatus_Failure_Load;
			
			return;
			
		}
		
	}
	
}

void RAUX::JSONFile :: Commit ( uint32_t * Status )
{
	
	if ( ! FileInstance.Exists () )
	{
		
		* Status = kStatus_Failure_NonExistantFile;
		
		return;
		
	}
	
	if ( ! FileInstance.IsOpen () )
	{
		
		FileInstance.Open ( Status );
		
		if ( * Status != kStatus_Success )
		{
			
			* Status = kStatus_Failure_Load;
			
			return;
			
		}
		
	}
	
	FileInstance.WriteFromString ( Status, JSONBuffer, 0, 0 );
	
	if ( * Status == File :: kStatus_Failure_Permissions )
	{
		
		* Status = kStatus_Failure_Permissions;
		
		return;
		
	}
	
	if ( * Status != File :: kStatus_Success )
	{
		
		* Status = kStatus_Failure_Unkown;
		
		return;
		
	}
	
}

void RAUX::JSONFile :: CloseFile ()
{
	
	FileInstance.Close ();
	
}

Red::Data::JSON :: IType * RAUX::JSONFile :: Decode ( uint32_t * Status )
{
	
	Red::Data::JSON :: IType * OutData = JSONDecoder.Decode ( JSONBuffer );
	
	if ( OutData == NULL )
	{
		
		* Status = kStatus_Failure_Decode;
		
		return NULL;
		
	}
	
	* Status = kStatus_Success;
	
	return OutData;
	
}

void RAUX::JSONFile :: Encode ( Red::Data::JSON :: IType * Data, uint32_t * Status )
{
	
	if ( ! JSONEncoder.Encode ( Data, JSONBuffer ) )
	{
		
		* Status = kStatus_Failure_Encode;
		
		return;
		
	}
	
	* Status = kStatus_Success;
	
}
