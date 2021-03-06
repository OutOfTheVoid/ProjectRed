#include <RAUX/OBJFile.h>

#include <iostream>
#include <stdexcept>

#ifdef RAUX_XENON_MATH_INTERFACE
	
	#include <Red/Util/RCMem.h>

	#include <Xenon/Geometry/MeshAttribute.h>
	#include <Xenon/Geometry/MeshAttributeData.h>

	#include <Xenon/GPU/GLInclude.h>

#endif

#define READBLOCK_SIZE 0x1000

std :: string RAUX::OBJFile :: NullComment ( "" );

RAUX::OBJFile :: OBJFile ( const std :: string & Name, uint32_t Flags ):
	FileInstance ( Name ),
	Flags ( Flags ),
	Validated ( false ),
	Comments (),
	Groups (),
	ActiveGroupIndexes (),
	ActiveGroupFaceIndexBase ( 0 ),
	VertexPositions (),
	VertexNormals (),
	VertexTexturePositions (),
	Vertices (),
	Faces (),
	MaterialLibraryPrefixes (),
	MaterialLibraries (),
	ActiveMaterials (),
	CurrentMaterial ( - 1 )
{
	
	if ( ( ( Flags & kFlags_NoRAUXComment ) == 0 ) && ( ( Flags & kFlags_StoreComments ) != 0 ) )
		Comments.push_back ( std :: string ( "Loaded by RAUX" ) );
	
}

RAUX::OBJFile :: ~OBJFile ()
{
	
	CloseFile ();
	
}

bool RAUX::OBJFile :: Exists () const
{
	
	return FileInstance.Exists ();
	
}

RAUX::OBJFile::TexturePosition_Struct :: TexturePosition_Struct ():
	Position ( OBJFILE_VEC3_NOINIT ),
	Dimension ( 0 )
{
}

RAUX::OBJFile::Group_Struct :: Group_Struct ( const std :: string & Name ):
	Name ( Name ),
	FaceIndecies ()
{
}

RAUX::OBJFile::Group_Struct :: Group_Struct ( const Group_Struct & CopyFrom ):
	Name ( CopyFrom.Name ),
	FaceIndecies ( CopyFrom.FaceIndecies )
{
}

void RAUX::OBJFile :: Load ( uint32_t * Status )
{
	
	if ( Validated )
	{
		
		* Status = kStatus_Success;
		
		return;
		
	}
	
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
			
			std :: cout << "Failed line: \"" << Line << "\"" << std :: endl;
			
			* Status = kStatus_Failure_InvalidFile;
			
			return;
			
		}
		
		Line = "";
		
		Index ++;
		
	}
	
	ResolveActiveGroups ();
	
	* Status = kStatus_Success;
	
	Validated = true;
	
}

bool RAUX::OBJFile :: ProcessTextLine ( const std :: string & Line )
{
	
	uint32_t Index = 0;
	
	if ( Line.size () == 0 )
		return true;
	
	char Charachter = Line.at ( Index );
	
	while ( ( Charachter == ' ' ) || ( Charachter == '\t' ) )
	{
		
		Index ++;
		
		if ( Index >= Line.size () )
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
		
		case 'v':
		{
			
			Index ++;
			
			if ( Index > Line.size () )
				return false;
			
			Charachter = Line.at ( Index );
			
			switch ( Charachter )
			{
				
				case ' ':
					return ProcessVertexPosition ( Line, Index );
				
				case 'n':
					return ( Flags & kFlags_NoNormals ) ? true : ProcessVertexNormal ( Line, Index );
				
				case 't':
					return ( Flags & kFlags_NoTexturePositions ) ? true : ProcessVertexTexturePosition ( Line, Index );
				
			}
			
			return false;
			
		}
		
		case 'g':
			return ( Flags & kFlags_NoGrouping ) ? true : ProcessGroups ( Line, Index );
		
		case 'f':
			return ProcessFace ( Line, Index );
			
		case 'm':
		{
			
			Index ++;
			
			if ( Index + 5 > Line.size () )
				return false;
			
			if ( Line.substr ( Index, 5 ) == "tllib" )
				return ProcessMaterialLibrary ( Line, Index + 5 );
			
			return false;
			
		}
		
		case 'u':
		{
			
			Index ++;
			
			if ( Index + 5 > Line.size () )
				return false;
			
			if ( Line.substr ( Index, 5 ) == "semtl" )
				return ProcessMaterial ( Line, Index + 5 );
			
			return false;
			
		}
		
		default:
			return ( ( Flags & kFlags_FailOnUnsupportedCommand ) == 0 );
		
	}
	
	return true;
	
}

bool RAUX::OBJFile :: ProcessVertexPosition ( const std :: string & Line, uint32_t Index )
{
	
	Vec3 Position ( OBJFILE_VEC3_NOINIT );
	
	uint32_t FloatIndex;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	FloatIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	std :: string FloatString = Line.substr ( FloatIndex, Index - FloatIndex );
	Position.X = strtof ( FloatString.c_str (), NULL );
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	FloatIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	FloatString = Line.substr ( FloatIndex, Index - FloatIndex );
	Position.Y = strtof ( FloatString.c_str (), NULL );
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	FloatIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	FloatString = Line.substr ( FloatIndex, Index - FloatIndex );
	Position.Z = strtof ( FloatString.c_str (), NULL );
	
	VertexPositions.push_back ( Position );
	
	return true;
	
}

bool RAUX::OBJFile :: ProcessVertexNormal ( const std :: string & Line, uint32_t Index )
{
	
	Vec3 Normal ( OBJFILE_VEC3_NOINIT );
	
	uint32_t FloatIndex;
	
	Index ++;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	FloatIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	std :: string FloatString = Line.substr ( FloatIndex, Index - FloatIndex );
	Normal.X = strtof ( FloatString.c_str (), NULL );
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	FloatIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	FloatString = Line.substr ( FloatIndex, Index - FloatIndex );
	Normal.Y = strtof ( FloatString.c_str (), NULL );
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	FloatIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	FloatString = Line.substr ( FloatIndex, Index - FloatIndex );
	Normal.Z = strtof ( FloatString.c_str (), NULL );
	
	if ( ( Flags & kFlags_NoNormalNormalization ) == 0 )
		OBJFILE_VEC3_NORMALIZE ( Normal );
	
	VertexNormals.push_back ( Normal );
	
	return true;
	
}

bool RAUX::OBJFile :: ProcessVertexTexturePosition ( const std :: string & Line, uint32_t Index )
{
	
	TexturePosition TexPosition;
	
	uint32_t FloatIndex;
	
	Index ++;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	FloatIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	std :: string FloatString = Line.substr ( FloatIndex, Index - FloatIndex );
	TexPosition.Position.X = strtof ( FloatString.c_str (), NULL );
	
	TexPosition.Dimension = 1;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
		Index ++;
	
	if ( Index < Line.size () )
	{
		
		FloatIndex = Index;
		
		FloatString = Line.substr ( FloatIndex, Index - FloatIndex );
		TexPosition.Position.Y = strtof ( FloatString.c_str (), NULL );
		
		TexPosition.Dimension = 2;
		
		while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
			Index ++;
		
		if ( Index < Line.size () )
		{
			
			FloatIndex = Index;
			
			while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
				Index ++;
			
			FloatString = Line.substr ( FloatIndex, Index - FloatIndex );
			TexPosition.Position.Z = strtof ( FloatString.c_str (), NULL );
			
			TexPosition.Dimension = 2;
			
		}
		else
			TexPosition.Position.Z = TexPosition.Position.Y;
		
	}
	else
	{
		
		TexPosition.Position.Y = TexPosition.Position.X;
		TexPosition.Position.Z = TexPosition.Position.X;
		
	}
	
	VertexTexturePositions.push_back ( TexPosition );
	
	return true;
	
}

bool RAUX::OBJFile :: ProcessFace ( const std :: string & Line, uint32_t Index )
{
	
	uint32_t IntegerIndex;
	std :: string IntegerString;
	
	std :: vector <Vertex> VertexAccumulator;
	
	Vertex Vert;
	
	Index ++;
	
	while ( true )
	{
		
		while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
			Index ++;
		
		if ( Index >= Line.size () )
			break;
		
		Vert.VertexPositionIndex = - 1;
		Vert.VertexNormalIndex = - 1;
		Vert.VertexTexturePositionIndex = - 1;
		
		IntegerIndex = Index;
		
		while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) && ( Line.at ( Index ) != '/' ) )
			Index ++;
		
		IntegerString = Line.substr ( IntegerIndex, Index - IntegerIndex );
		int32_t VertexPositionIndex;
		
		try
		{
			VertexPositionIndex = stoi ( IntegerString, NULL, 10 );
		}
		catch ( std :: invalid_argument InvalArg )
		{
			return false;
		}
		
		if ( VertexPositionIndex < 0 )
			VertexPositionIndex += static_cast <int32_t> ( VertexPositions.size () );
		else
			VertexPositionIndex --;
		
		Vert.VertexPositionIndex = VertexPositionIndex;
		
		if ( Index >= Line.size () )
			break;
		
		if ( Line.at ( Index ) == '/' )
		{
			
			Index ++;
			
			if ( Index >= Line.size () )
				return false;
			
			if ( Line.at ( Index ) != '/' )
			{
				
				IntegerIndex = Index;
				
				while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
					Index ++;
				
				IntegerString = Line.substr ( IntegerIndex, Index - IntegerIndex );
				int32_t VertexTexturePositionIndex;
				
				try
				{
					VertexTexturePositionIndex = stoi ( IntegerString, NULL, 10 );
				}
				catch ( std :: invalid_argument InvalArg )
				{
					return false;
				}
				
				if ( VertexTexturePositionIndex < 0 )
					VertexTexturePositionIndex += static_cast <int32_t> ( VertexTexturePositions.size () );
				else
					VertexTexturePositionIndex --;
				
				Vert.VertexTexturePositionIndex = VertexTexturePositionIndex;
				
			}
			
			if ( ( Index < Line.size () ) && ( Line.at ( Index ) == '/' ) )
			{
				
				Index ++;
				
				if ( Index >= Line.size () )
					break;
				
				IntegerIndex = Index;
				
				while ( ( Index < Line.size () ) && ( Line.at ( Index ) != '/' ) && ( Line.at ( Index ) != ' ' ) )
					Index ++;
				
				IntegerString = Line.substr ( IntegerIndex, Index - IntegerIndex );
				int32_t VertexNormalIndex;
				
				try
				{
					VertexNormalIndex = stoi ( IntegerString, NULL, 10 );
				}
				catch ( std :: invalid_argument InvalArg )
				{
					return false;
				}
				
				if ( VertexNormalIndex < 0 )
					VertexNormalIndex += static_cast <int32_t> ( VertexNormals.size () );
				else
					VertexNormalIndex --;
				
				Vert.VertexNormalIndex = VertexNormalIndex;
				
			}
			
		}
		
		VertexAccumulator.push_back ( Vert );
		
	}
	
	if ( VertexAccumulator.size () < 3 )
		return false;
	
	Face Out;
	
	Out.VertexIndexBase = static_cast <uint32_t> ( Vertices.size () );
	Out.VertexCount = static_cast <uint32_t> ( VertexAccumulator.size () );
	Out.MaterialIndex = static_cast <uint32_t> ( ActiveMaterials.size () - 1 );
	
	Faces.push_back ( Out );
	Vertices.insert ( Vertices.end (), VertexAccumulator.begin (), VertexAccumulator.end () );
	
	return true;
	
}

bool RAUX::OBJFile :: ProcessGroups ( const std :: string & Line, uint32_t Index )
{
	
	std :: vector <std :: string> GroupNames;
	
	Index ++;
	
	while ( Index < Line.size () )
	{
		
		while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
			Index ++;
		
		uint32_t NameIndex = Index;
		
		while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
			Index ++;
		
		if ( Index - NameIndex == 0 )
			break;
		
		std :: string GroupString = Line.substr ( NameIndex, Index - NameIndex );
		
		GroupNames.push_back ( GroupString );
		
	}
	
	if ( GroupNames.size () == 0 )
		return false;
	
	ResolveActiveGroups ();
	
	ActiveGroupIndexes.clear ();
	ActiveGroupFaceIndexBase = static_cast <uint32_t> ( Faces.size () );
	
	for ( uint32_t I = 0; I < GroupNames.size (); I ++ )
	{
		
		int32_t ActiveIndex = - 1;
		
		for ( uint32_t J = 0; J < Groups.size (); J ++ )
		{
			
			if ( Groups [ J ].Name == GroupNames [ I ] )
				ActiveGroupIndexes.push_back ( J );
			
		}
		
		if ( ActiveIndex == - 1 )
		{
			
			ActiveGroupIndexes.push_back ( static_cast <uint32_t> ( Groups.size () ) );
			Groups.push_back ( GroupNames [ I ] );
			
		}
		
	}
	
	return true;
	
}

bool RAUX::OBJFile :: ProcessMaterial ( const std :: string & Line, uint32_t Index )
{
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	uint32_t NameIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	std :: string MaterialName = Line.substr ( NameIndex, Index - NameIndex );
	
	std :: cout << "Using Material: \"" << MaterialName << "\"" << std :: endl;
	
	CurrentMaterial = - 1;
	
	for ( uint32_t I = 0; I < ActiveMaterials.size (); I ++ )
	{
		
		if ( MaterialName == ActiveMaterials [ I ].Name )
			CurrentMaterial = I;
		
	}
	
	if ( CurrentMaterial == - 1 )
	{
		
		for ( uint32_t I = 0; I < MaterialLibraries.size (); I ++ )
		{
			
			const MTLFile :: Material * PendingMaterial = MaterialLibraries [ I ].GetMaterial ( MaterialName );
			
			if ( PendingMaterial != NULL )
			{
				
				CurrentMaterial = static_cast <uint32_t> ( ActiveMaterials.size () );
				ActiveMaterials.push_back ( * PendingMaterial );
				
				break;
				
			}
			
		}
		
	}
	
	return ( CurrentMaterial != - 1 );
	
}

bool RAUX::OBJFile :: ProcessMaterialLibrary ( const std :: string & Line, uint32_t Index )
{
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) == ' ' ) )
		Index ++;
	
	if ( Index >= Line.size () )
		return false;
	
	uint32_t NameIndex = Index;
	
	while ( ( Index < Line.size () ) && ( Line.at ( Index ) != ' ' ) )
		Index ++;
	
	std :: string LibraryName = Line.substr ( NameIndex, Index - NameIndex );
	std :: string PrefixedName = LibraryName;
	
	MTLFile LibraryFile ( LibraryName, ( ( ( Flags & kFlags_StoreComments ) != 0 ) ? MTLFile :: kFlags_StoreComments : 0 ) | ( ( ( Flags & kFlags_FailOnUnsupportedCommand ) != 0 ) ? MTLFile :: kFlags_FailOnUnsupportedCommand : 0 ) );
	
	uint32_t PrefixIndex = 0;
		
	while ( ( ! LibraryFile.Exists () ) && ( PrefixIndex < MaterialLibraryPrefixes.size () ) )
	{
		
		PrefixedName = MaterialLibraryPrefixes [ Index ];
		PrefixedName.append ( LibraryName );
		
		LibraryFile = MTLFile ( PrefixedName, ( ( ( Flags & kFlags_StoreComments ) != 0 ) ? MTLFile :: kFlags_StoreComments : 0 ) | ( ( ( Flags & kFlags_FailOnUnsupportedCommand ) != 0 ) ? MTLFile :: kFlags_FailOnUnsupportedCommand : 0 ) );
		
	}
	
	if ( LibraryFile.Exists () )
	{
		
		std :: cout << "Found material library: \"" << PrefixedName << "\"" << std :: endl;
		
		MaterialLibraries.push_back ( LibraryFile );
		
		MTLFile & InPlaceLibrary = MaterialLibraries [ MaterialLibraries.size () - 1 ];
		
		uint32_t LoadStatus;
		InPlaceLibrary.Load ( & LoadStatus );
		
		if ( ( Flags & kFlags_StoreComments ) != 0 )
		{
			
			for ( uint32_t I = 0; I < InPlaceLibrary.GetCommentCount (); I ++ )
				Comments.push_back ( PrefixedName + ": " + InPlaceLibrary.GetComment ( I ) );
			
		}
		
		return true;
		
	}
	
	return false;
	
}

void RAUX::OBJFile :: ResolveActiveGroups ()
{
	
	if ( ( ActiveGroupIndexes.size () == 0 ) && ( Faces.size () - ActiveGroupFaceIndexBase > 0 ) )
	{
		
		if ( Groups.size () == 0 )
			Groups.push_back ( std :: string ( "_raux_objgroup_default" ) );
		
		ActiveGroupIndexes.push_back ( 0 );
		
	}
	
	for ( uint32_t I = 0; I < ActiveGroupIndexes.size (); I ++ )
	{
		
		Group & CurrentResolveGroup = Groups [ ActiveGroupIndexes [ I ] ];
		
		for ( uint32_t F = ActiveGroupFaceIndexBase; F < Faces.size (); F ++ )
			CurrentResolveGroup.FaceIndecies.push_back ( F );
		
	}
	
}

void RAUX::OBJFile :: CloseFile ()
{
	
	FileInstance.Close ();
	
}

bool RAUX::OBJFile :: Valid () const
{
	
	return Validated;
	
}

uint32_t RAUX::OBJFile :: GetCommentCount () const
{
	
	return static_cast <uint32_t> ( Comments.size () );
	
}

const std :: string & RAUX::OBJFile :: GetComment ( uint32_t Index ) const
{
	
	if ( Index >= Comments.size () )
		return NullComment;
	
	return Comments [ Index ];
	
}

uint32_t RAUX::OBJFile :: GetVertexPositionCount () const
{
	
	return static_cast <uint32_t> ( VertexPositions.size () );
	
}

const RAUX::OBJFile :: Vec3 RAUX::OBJFile :: GetVertexPosition ( uint32_t Index ) const
{
	
	if ( Index >= VertexPositions.size () )
		return Vec3 ( 0.0f, 0.0f, 0.0f );
	
	return VertexPositions [ Index ];
	
}

uint32_t RAUX::OBJFile :: GetVertexNormalCount () const
{
	
	return static_cast <uint32_t> ( VertexNormals.size () );
	
}

const RAUX::OBJFile :: Vec3 RAUX::OBJFile :: GetVertexNormal ( uint32_t Index ) const
{
	
	if ( Index >= VertexNormals.size () )
		return Vec3 ( 0.0f, 0.0f, 0.0f );
	
	return VertexNormals [ Index ];
	
}

uint32_t RAUX::OBJFile :: GetVertexTexturePositionCount () const
{
	
	return static_cast <uint32_t> ( VertexPositions.size () );
	
}

const RAUX::OBJFile :: TexturePosition RAUX::OBJFile :: GetVertexTexturePosition ( uint32_t Index ) const
{
	
	if ( Index < VertexTexturePositions.size () )
		return VertexTexturePositions [ Index ];
	
	return TexturePosition ();
	
}

uint32_t RAUX::OBJFile :: GetGroupCount () const
{
	
	return static_cast <uint32_t> ( Groups.size () );
	
}

const RAUX::OBJFile :: Group * RAUX::OBJFile :: GetGroup ( uint32_t Index ) const
{
	
	if ( Index >= Groups.size () )
		return NULL;
	
	return & Groups [ Index ];
	
}

const RAUX::OBJFile :: Group * RAUX::OBJFile :: GetGroup ( const std :: string & Name ) const
{
	
	for ( uint32_t I = 0; I < Groups.size (); I ++ )
	{
		
		if ( Groups [ I ].Name == Name )
			return & Groups [ I ];
		
	}
	
	return NULL;
	
}

uint32_t RAUX::OBJFile :: GetFaceCount () const
{
	
	return static_cast <uint32_t> ( Faces.size () );
	
}

const RAUX::OBJFile :: Face RAUX::OBJFile :: GetFace ( uint32_t Index ) const
{
	
	if ( Index > Faces.size () )
	{
		
		Face Return;
		
		Return.VertexIndexBase = 0;
		Return.VertexCount = 0;
		
		return Return;
		
	}
	
	return Faces [ Index ];
	
}

#ifdef RAUX_XENON_INTERFACE

Xenon::Geometry :: Mesh * RAUX::OBJFile :: CreateMesh ( const MeshParameters & Parameters, uint32_t * Status )
{
	
	uint32_t IndexCount = 0;
	uint32_t TriCount = 0;
	
	uint32_t I;
	
	for ( I = 0; I < Parameters.GroupCount; I ++ )
	{
		
		const Group * FGroup = GetGroup ( Parameters.GroupIndexes [ I ] );
		
		if ( FGroup == NULL )
		{
			
			* Status = kStatus_Failure_InvalidGroup;
			
			return NULL;
			
		}
		
		TriCount += static_cast <uint32_t> ( FGroup -> FaceIndecies.size () );
		
	}
	
	IndexCount = TriCount * 3;
	
	if ( ! IndexCount )
		return NULL;
	
	Red::Util :: RCMem * IndexMemory = new Red::Util :: RCMem ( sizeof ( GLuint ) * IndexCount );
	GLuint * Indexies = reinterpret_cast <GLuint *> ( IndexMemory -> GetData () );
	
	if ( Parameters.WindCounterClockwise )
	{
		
		for ( I = 0; I < TriCount; I ++ )
		{
			
			Indexies [ I * 3 ] = I * 3;
			Indexies [ I * 3 + 1 ] = I * 3 + 1;
			Indexies [ I * 3 + 2 ] = I * 3 + 2;
			
		}
		
	}
	else
	{
		
		for ( I = 0; I < TriCount; I ++ )
		{
			
			Indexies [ I * 3 ] = I * 3 + 2;
			Indexies [ I * 3 + 1 ] = I * 3 + 1;
			Indexies [ I * 3 + 2 ] = I * 3;
			
		}
		
	}
	
	return NULL;
	
}

#endif
