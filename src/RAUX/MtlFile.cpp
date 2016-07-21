#include <RAUX/MtlFile.h>

RAUX::MtlFile :: MtlFile ( const std :: string & Name ):
	FileInstance ( Name )
{
}

RAUX::MtlFile :: MtlFile ( const MtlFile & CopyFrom ):
	FileInstance ( CopyFrom.FileInstance.GetName () )
{
}

void RAUX::MtlFile :: operator= ( const RAUX::MtlFile & CopyFrom )
{
	
	this -> ~MtlFile ();
	new ( this ) MtlFile ( CopyFrom );
	
}

RAUX::MtlFile :: ~MtlFile ()
{
}

bool RAUX::MtlFile :: Exists () const
{
	
	return FileInstance.Exists ();
	
}

void RAUX::MtlFile :: Load ( uint32_t * Status )
{
	
	// TODO: Load material library.
	
	* Status = kStatus_Success;
	
}
