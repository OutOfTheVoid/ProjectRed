#include <RAUX/WAVFile.h>
#include <RAUX/Endian.h>

#include <iostream>

RAUX::WAVFile :: WAVFile ( const std :: string & Name ):
	FileInstance ( Name, false )
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
	
	// TODO: Implement
	
}