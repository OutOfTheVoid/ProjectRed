#include <RAUX/MtlFile.h>

#include <stdexcept>
#include <stdlib.h>

#define READBLOCK_SIZE 0x1000

std :: string RAUX::MtlFile :: NullComment ( "" );

//HELLO WORLD

RAUX::MtlFile :: MtlFile ( const std :: string & Name, uint32_t Flags ):
	Flags ( Flags ),
	FileInstance ( Name ),
	Materials (),
	Comments ()
{
	
	if ( ( ( Flags & kFlags_NoRAUXComment ) == 0 ) && ( ( Flags & kFlags_StoreComments ) != 0 ) )
		Comments.push_back ( std :: string ( "Loaded by RAUX" ) );
	
}

RAUX::MtlFile :: MtlFile ( const MtlFile & CopyFrom ):
	Flags ( CopyFrom.Flags ),
	FileInstance ( CopyFrom.FileInstance.GetName () ),
	Materials ( CopyFrom.Materials ),
	Comments ( CopyFrom.Comments )
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

RAUX::MtlFile::Material_Struct :: Material_Struct ( const std :: string & Name ):
	Name ( Name ),
	Ambiant ( 0.5f, 0.5f, 0.5f ),
	AmbiantIsCIEXYZ ( false ),
	AmbiantMapName ( "" ),
	Diffuse ( 1.0f, 1.0f, 1.0f ),
	DiffuseIsCIEXYZ ( false ),
	DiffuseMapName ( "" ),
	Specular ( 0.2f, 0.2f, 0.2f ),
	SpecularIsCIEXYZ ( false ),
	SpecularMapName ( "" ),
	Emission ( 0.0f, 0.0f, 0.0f ),
	EmissionIsCIEXYZ ( false ),
	EmissionMapName ( "" ),
	TransmissionFilter ( 0.0f, 0.0f, 0.0f ),
	TransmissionIsCIEXYZ ( false ),
	TransmissionMapName ( "" ),
	IlluminationModel ( 0 ),
	Dissolve ( 1.0 ),
	Halo ( false ),
	SpecularExponent ( 32.0f ),
	OpticalDensity ( 1.0f )
{	
}

RAUX::MtlFile::Material_Struct :: Material_Struct ( const Material_Struct & CopyFrom ):
	Name ( CopyFrom.Name ),
	Ambiant ( CopyFrom.Ambiant ),
	AmbiantIsCIEXYZ ( CopyFrom.AmbiantIsCIEXYZ ),
	AmbiantMapName ( CopyFrom.AmbiantMapName ),
	Diffuse ( CopyFrom.Diffuse ),
	DiffuseIsCIEXYZ ( CopyFrom.DiffuseIsCIEXYZ ),
	DiffuseMapName ( CopyFrom.DiffuseMapName ),
	Specular ( CopyFrom.Specular ),
	SpecularIsCIEXYZ ( CopyFrom.SpecularIsCIEXYZ ),
	SpecularMapName ( CopyFrom.SpecularMapName ),
	Emission ( CopyFrom.Emission ),
	EmissionIsCIEXYZ ( CopyFrom.EmissionIsCIEXYZ ),
	EmissionMapName ( CopyFrom.EmissionMapName ),
	TransmissionFilter ( CopyFrom.TransmissionFilter ),
	TransmissionIsCIEXYZ ( CopyFrom.TransmissionIsCIEXYZ ),
	TransmissionMapName ( CopyFrom.TransmissionMapName ),
	IlluminationModel ( CopyFrom.IlluminationModel ),
	Dissolve ( CopyFrom.Dissolve ),
	Halo ( CopyFrom.Halo ),
	SpecularExponent ( CopyFrom.SpecularExponent ),
	OpticalDensity ( CopyFrom.OpticalDensity )
{
}

void RAUX::MtlFile :: Load ( uint32_t * Status )
{
	
	if ( ! Exists () )
	{
		
		* Status = kStatus_Failure_NonExistantFile;
		
		return;
		
	}
	
	uint32_t SubStatus;
	
	FileInstance.Open ( & SubStatus );
	
	if ( SubStatus != TextFile :: kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return;
		
	}
	
	std :: string ReadBlock;
	
	FileInstance.LoadToString ( & SubStatus, ReadBlock, 0, READBLOCK_SIZE );
	
	if ( SubStatus != TextFile :: kStatus_Success )
	{
		
		* Status = kStatus_Failure_Load;
		
		return;
		
	}
	
	if ( ReadBlock.size () == 0 )
	{
		
		* Status = kStatus_Failure_InvalidFile;
		
		return;
		
	}
	
	std :: string Line;
	
	uint64_t Index = 0;
	
	bool EndOfReadBlock = false;
	
	while ( ! EndOfReadBlock )
	{
		
		if ( Index >= ReadBlock.size () )
			break;
		
		char Charachter = ReadBlock.at ( Index );
		
		while ( Charachter != '\n' )
		{
			
			Line.push_back ( Charachter );
			
			Index ++;
			
			if ( Index >= ReadBlock.size () )
			{
				
				EndOfReadBlock = true;
				break;
				
			}
			else
				Charachter = ReadBlock.at ( Index );
			
		}
		
		if ( ! ProcessTextLine ( Line ) )
		{
			
			* Status = kStatus_Failure_InvalidFile;
			
			return;
			
		}
		
		Line = "";
		
		Index ++;
		
	}
	
}

bool RAUX::MtlFile :: ProcessTextLine ( const std :: string & Line )
{
	
	uint32_t Index = 0;
	
	if ( Line.size () == 0 )
		return true;
	
	char Charachter = Line.at ( Index );
	
	while ( ( Charachter == ' ' ) || ( Charachter == '\t' ) )
	{
		
		Index ++;
		
		if ( Index + 1 >= Line.size () )
			return true;
		
		Charachter = Line.at ( Index );
		
	}
	
	switch ( Charachter )
	{
		
		case '#':
		{
			
			Index ++;
			
			while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
				Index ++;
			
			if ( Flags & kFlags_StoreComments )
				Comments.push_back ( Line.substr ( Index ) );
			
			break;
			
		}
		
		case 'n':
		{
			
			Index ++;
			
			if ( Index + 5 > Line.size () )
				return false;
			
			if ( Line.substr ( Index, 5 ) == "ewmtl" )
				return ProcessNewMaterial ( Line, Index + 5 );
			
			return false;
			
		}
		
		case 'K':
		{
			
			Index ++;
			
			if ( Index + 1 > Line.size () )
				return false;
			
			switch ( Line.at ( Index ) )
			{
				
				case 'a':
				{
					
					Index ++;
			
					if ( Index + 1 > Line.size () )
						return false;
					
					return ProcessAmbiant ( Line, Index );
					
				}
				
				case 'd':
				{
					
					Index ++;
			
					if ( Index + 1 > Line.size () )
						return false;
					
					return ProcessDiffuse ( Line, Index );
					
				}
				
				case 's':
				{
					
					Index ++;
			
					if ( Index + 1 > Line.size () )
						return false;
					
					return ProcessSpecular ( Line, Index );
					
				}
				
				case 'e':
				{
					
					Index ++;
			
					if ( Index + 1 > Line.size () )
						return false;
					
					return ProcessEmission ( Line, Index );
					
				}
				
				default:
					return ( ( Flags & kFlags_FailOnUnsupportedCommand ) == 0 );
				
			}
			
		}
		
		case 'i':
		{
			
			Index ++;
			
			if ( Index + 4 > Line.size () )
				return false;
			
			if ( Line.substr ( Index, 4 ) == "llum" )
				return ProcessIlluminationModel ( Line, Index + 4 );
			
			return false;
			
		}
		
		case 'd':
		{
			
			Index ++;
			
			if ( Index + 1 > Line.size () )
				return false;
			
			return ProcessDisolve ( Line, Index );
			
		}
		
		case 'N':
		{
			
			Index ++;
			
			if ( Index + 1 > Line.size () )
				return false;
			
			switch ( Line.at ( Index ) )
			{
				
				case 's':
				{
					
					Index ++;
					
					if ( Index + 1 > Line.size () )
						return false;
					
					return ProcessSpecularExponent ( Line, Index );
					
				}
				
				case 'i':
				{
					
					Index ++;
					
					if ( Index + 1 > Line.size () )
						return false;
					
					return ProcessOpticalDensity ( Line, Index );
					
				}
				
			}
			
		}
		
		default:
			return ( ( Flags & kFlags_FailOnUnsupportedCommand ) == 0 );
		
	};
	
	return true;
	
}

bool RAUX::MtlFile :: ProcessIlluminationModel ( const std :: string & Line, uint32_t Index )
{
	
	if ( Materials.size () == 0 )
		return false;
	
	while ( ( Index < Line.size () ) && ( ( Line.at ( Index ) == ' ' ) || ( Line.at ( Index ) == '\t' ) ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	uint32_t IntegerIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	std :: string IntegerString = Line.substr ( IntegerIndex, Index - IntegerIndex );
	
	uint32_t IlluminationModel = 0;
	
	try
	{
		IlluminationModel = stoi ( IntegerString, NULL, 10 );
	}
	catch ( std :: invalid_argument InvalArg )
	{
		return false;
	}
	
	Materials [ Materials.size () - 1 ].IlluminationModel = IlluminationModel;
	
	return true;
	
}

bool RAUX::MtlFile :: ProcessNewMaterial ( const std :: string & Line, uint32_t Index )
{
	
	while ( ( Index < Line.size () ) && ( ( Line.at ( Index ) == ' ' ) || ( Line.at ( Index ) == '\t' ) ) )
		Index ++;
	
	if ( Index + 1 >= Line.size () )
		return false;
	
	uint32_t NameIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	std :: string NameString = Line.substr ( NameIndex, Index - NameIndex );
	
	Materials.push_back ( NameString );
	
	return true;
	
}

bool RAUX::MtlFile :: ProcessAmbiant ( const std :: string & Line, uint32_t Index )
{
	
	if ( Materials.size () == 0 )
		return false;
	
	Vec3 Coefficients ( MTLFILE_VEC3_NOINIT );
	bool IsCIEXYZ = false;
	
	uint32_t StringIndex;
	
	Index ++;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	StringIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	std :: string FloatString = Line.substr ( StringIndex, Index - StringIndex );
	
	if ( FloatString == "xyz" )
	{
		
		IsCIEXYZ = true;
		
		Index ++;
		
		while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
			Index ++;
		
		if ( Index >= Line.size () )
			return false;
		
		StringIndex = Index;
		
		while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
			Index ++;
		
		if ( Index >= Line.size () )
			return false;
		
		FloatString = Line.substr ( StringIndex, Index - StringIndex );
		
	}
	
	Coefficients.X = strtof ( FloatString.c_str (), NULL );
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	StringIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	FloatString = Line.substr ( StringIndex, Index - StringIndex );
	Coefficients.Y = strtof ( FloatString.c_str (), NULL );
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	StringIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	FloatString = Line.substr ( StringIndex, Index - StringIndex );
	Coefficients.Z = strtof ( FloatString.c_str (), NULL );
	
	Materials [ Materials.size () - 1 ].Ambiant = Coefficients;
	Materials [ Materials.size () - 1 ].AmbiantIsCIEXYZ = IsCIEXYZ;
	
	return true;
	
}

bool RAUX::MtlFile :: ProcessDiffuse ( const std :: string & Line, uint32_t Index )
{
	
	if ( Materials.size () == 0 )
		return false;
	
	Vec3 Coefficients ( MTLFILE_VEC3_NOINIT );
	bool IsCIEXYZ = false;
	
	uint32_t StringIndex;
	
	Index ++;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	StringIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	std :: string FloatString = Line.substr ( StringIndex, Index - StringIndex );
	
	if ( FloatString == "xyz" )
	{
		
		IsCIEXYZ = true;
		
		Index ++;
		
		while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
			Index ++;
		
		if ( Index >= Line.size () )
			return false;
		
		StringIndex = Index;
		
		while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
			Index ++;
		
		if ( Index >= Line.size () )
			return false;
		
		FloatString = Line.substr ( StringIndex, Index - StringIndex );
		
	}
	
	Coefficients.X = strtof ( FloatString.c_str (), NULL );
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	StringIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	FloatString = Line.substr ( StringIndex, Index - StringIndex );
	Coefficients.Y = strtof ( FloatString.c_str (), NULL );
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	StringIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	FloatString = Line.substr ( StringIndex, Index - StringIndex );
	Coefficients.Z = strtof ( FloatString.c_str (), NULL );
	
	Materials [ Materials.size () - 1 ].Diffuse = Coefficients;
	Materials [ Materials.size () - 1 ].DiffuseIsCIEXYZ = IsCIEXYZ;
	
	return true;
	
}

bool RAUX::MtlFile :: ProcessSpecular ( const std :: string & Line, uint32_t Index )
{
	
	if ( Materials.size () == 0 )
		return false;
	
	Vec3 Coefficients ( MTLFILE_VEC3_NOINIT );
	bool IsCIEXYZ = false;
	
	uint32_t StringIndex;
	
	Index ++;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	StringIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	std :: string FloatString = Line.substr ( StringIndex, Index - StringIndex );
	
	if ( FloatString == "xyz" )
	{
		
		IsCIEXYZ = true;
		
		Index ++;
		
		while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
			Index ++;
		
		if ( Index >= Line.size () )
			return false;
		
		StringIndex = Index;
		
		while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
			Index ++;
		
		if ( Index >= Line.size () )
			return false;
		
		FloatString = Line.substr ( StringIndex, Index - StringIndex );
		
	}
	
	Coefficients.X = strtof ( FloatString.c_str (), NULL );
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	StringIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	FloatString = Line.substr ( StringIndex, Index - StringIndex );
	Coefficients.Y = strtof ( FloatString.c_str (), NULL );
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	StringIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	FloatString = Line.substr ( StringIndex, Index - StringIndex );
	Coefficients.Z = strtof ( FloatString.c_str (), NULL );
	
	Materials [ Materials.size () - 1 ].Specular = Coefficients;
	Materials [ Materials.size () - 1 ].SpecularIsCIEXYZ = IsCIEXYZ;
	
	return true;
	
}

bool RAUX::MtlFile :: ProcessEmission ( const std :: string & Line, uint32_t Index )
{
	
	if ( Materials.size () == 0 )
		return false;
	
	Vec3 Coefficients ( MTLFILE_VEC3_NOINIT );
	bool IsCIEXYZ = false;
	
	uint32_t StringIndex;
	
	Index ++;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	StringIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	std :: string FloatString = Line.substr ( StringIndex, Index - StringIndex );
	
	if ( FloatString == "xyz" )
	{
		
		IsCIEXYZ = true;
		
		Index ++;
		
		while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
			Index ++;
		
		if ( Index >= Line.size () )
			return false;
		
		StringIndex = Index;
		
		while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
			Index ++;
		
		if ( Index >= Line.size () )
			return false;
		
		FloatString = Line.substr ( StringIndex, Index - StringIndex );
		
	}
	
	Coefficients.X = strtof ( FloatString.c_str (), NULL );
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	StringIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	FloatString = Line.substr ( StringIndex, Index - StringIndex );
	Coefficients.Y = strtof ( FloatString.c_str (), NULL );
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	StringIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	FloatString = Line.substr ( StringIndex, Index - StringIndex );
	Coefficients.Z = strtof ( FloatString.c_str (), NULL );
	
	Materials [ Materials.size () - 1 ].Emission = Coefficients;
	Materials [ Materials.size () - 1 ].EmissionIsCIEXYZ = IsCIEXYZ;
	
	return true;
	
}

bool RAUX::MtlFile :: ProcessTransmissionFilter ( const std :: string & Line, uint32_t Index )
{
	
	if ( Materials.size () == 0 )
		return false;
	
	Vec3 Coefficients ( MTLFILE_VEC3_NOINIT );
	bool IsCIEXYZ = false;
	
	uint32_t StringIndex;
	
	Index ++;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	StringIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	std :: string FloatString = Line.substr ( StringIndex, Index - StringIndex );
	
	if ( FloatString == "xyz" )
	{
		
		IsCIEXYZ = true;
		
		Index ++;
		
		while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
			Index ++;
		
		if ( Index >= Line.size () )
			return false;
		
		StringIndex = Index;
		
		while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
			Index ++;
		
		if ( Index >= Line.size () )
			return false;
		
		FloatString = Line.substr ( StringIndex, Index - StringIndex );
		
	}
	
	Coefficients.X = strtof ( FloatString.c_str (), NULL );
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	StringIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	FloatString = Line.substr ( StringIndex, Index - StringIndex );
	Coefficients.Y = strtof ( FloatString.c_str (), NULL );
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	StringIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	FloatString = Line.substr ( StringIndex, Index - StringIndex );
	Coefficients.Z = strtof ( FloatString.c_str (), NULL );
	
	Materials [ Materials.size () - 1 ].TransmissionFilter = Coefficients;
	Materials [ Materials.size () - 1 ].TransmissionIsCIEXYZ = IsCIEXYZ;
	
	return true;
	
}

bool RAUX::MtlFile :: ProcessDisolve ( const std :: string & Line, uint32_t Index )
{
	
	if ( Materials.size () == 0 )
		return false;
	
	uint32_t StringIndex;
	
	Index ++;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	StringIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	std :: string FloatString = Line.substr ( StringIndex, Index - StringIndex );
	
	if ( FloatString == "-halo" )
	{
		
		Materials [ Materials.size () - 1 ].Halo = true;
		
		Index ++;
	
		while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
			Index ++;
		
		if ( Index >= Line.size () )
			return false;
		
		StringIndex = Index;
		
		while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
			Index ++;
		
		if ( Index >= Line.size () )
			return false;
		
		FloatString = Line.substr ( StringIndex, Index - StringIndex );
		
	}
	
	Materials [ Materials.size () - 1 ].Dissolve = strtof ( FloatString.c_str (), NULL );
	
	return true;
	
}

bool RAUX::MtlFile :: ProcessSpecularExponent ( const std :: string & Line, uint32_t Index )
{
	
	if ( Materials.size () == 0 )
		return false;
	
	uint32_t StringIndex;
	
	Index ++;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	StringIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	std :: string FloatString = Line.substr ( StringIndex, Index - StringIndex );
	
	Materials [ Materials.size () - 1 ].SpecularExponent = strtof ( FloatString.c_str (), NULL );
	
	return true;
	
}

bool RAUX::MtlFile :: ProcessOpticalDensity ( const std :: string & Line, uint32_t Index )
{
	
	if ( Materials.size () == 0 )
		return false;
	
	uint32_t StringIndex;
	
	Index ++;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	StringIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	std :: string FloatString = Line.substr ( StringIndex, Index - StringIndex );
	
	Materials [ Materials.size () - 1 ].OpticalDensity = strtof ( FloatString.c_str (), NULL );
	
	return true;
	
}

uint32_t RAUX::MtlFile :: GetCommentCount () const
{
	
	return static_cast <uint32_t> ( Comments.size () );
	
}

const std :: string & RAUX::MtlFile :: GetComment ( uint32_t Index ) const
{
	
	if ( Index >= Comments.size () )
		return NullComment;
	
	return Comments [ Index ];
	
}

uint32_t RAUX::MtlFile :: GetMaterialCount () const
{
	
	return static_cast <uint32_t> ( Materials.size () );
	
}

const std :: string & RAUX::MtlFile :: GetMaterialName ( uint32_t Index ) const
{
	
	if ( Index < Materials.size () )
		return Materials [ Index ].Name;
	
	return NullComment;
	
}

const RAUX::MtlFile :: Material * RAUX::MtlFile :: GetMaterial ( uint32_t Index ) const
{
	
	if ( Index < Materials.size () )
		return & Materials [ Index ];
	
	return NULL;
	
}

const RAUX::MtlFile :: Material * RAUX::MtlFile :: GetMaterial ( const std :: string & Name ) const
{
	
	for ( uint32_t I = 0; I < Materials.size (); I ++ )
	{
		
		if ( Materials [ I ].Name == Name )
			return & Materials [ I ];
		
	}
	
	return NULL;
	
}
