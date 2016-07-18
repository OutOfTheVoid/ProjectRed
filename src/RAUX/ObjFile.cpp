#include <RAUX/ObjFile.h>

#include <iostream>
#include <stdexcept>

#define READBLOCK_SIZE 0x1000

RAUX::ObjFile :: ObjFile ( const std :: string & Name, uint32_t Flags ):
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
	Faces ()
{
	
	if ( ( ( Flags & kFlags_NoRAUXComment ) == 0 ) && ( ( Flags & kFlags_StoreComments ) != 0 ) )
		Comments.push_back ( std :: string ( "Loaded by RAUX" ) );
	
};

RAUX::ObjFile :: ~ObjFile ()
{
	
	CloseFile ();
	
};

bool RAUX::ObjFile :: Exists () const
{
	
	return FileInstance.Exists ();
	
};

RAUX::ObjFile::TexturePosition_Struct :: TexturePosition_Struct ():
	Position ( OBJFILE_VEC3_NOINIT ),
	Dimension ( 0 )
{
};

RAUX::ObjFile::Group_Struct :: Group_Struct ( const std :: string & Name ):
	Name ( Name ),
	FaceIndecies ()
{
};

RAUX::ObjFile::Group_Struct :: Group_Struct ( const Group_Struct & CopyFrom ):
	Name ( CopyFrom.Name ),
	FaceIndecies ( CopyFrom.FaceIndecies )
{
};

void RAUX::ObjFile :: Load ( uint32_t * Status )
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
	
	
	uint64_t LineStartIndex = 0;
	uint64_t Index = 0;
	
	bool EndOfReadBlock = false;
	
	while ( ! EndOfReadBlock )
	{
		
		if ( Index >= ReadBlock.size () )
			break;
		
		char Charachter = ReadBlock.at ( Index );
		LineStartIndex = Index;
		
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
	
	ResolveActiveGroups ();
	
	* Status = kStatus_Success;
	
	Validated = true;
	
};

bool RAUX::ObjFile :: ProcessTextLine ( const std :: string & Line )
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
		
		default:
			return ( ( Flags & kFlags_FailOnUnsupportedCommand ) == 0 );
		
	}
	
	return true;
	
};

bool RAUX::ObjFile :: ProcessVertexPosition ( const std :: string & Line, uint32_t Index )
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
	
};

bool RAUX::ObjFile :: ProcessVertexNormal ( const std :: string & Line, uint32_t Index )
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
	
	OBJFILE_VEC3_NORMALIZE ( Normal );
	
	VertexNormals.push_back ( Normal );
	
	return true;
	
};

bool RAUX::ObjFile :: ProcessVertexTexturePosition ( const std :: string & Line, uint32_t Index )
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
	
};

bool RAUX::ObjFile :: ProcessFace ( const std :: string & Line, uint32_t Index )
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
			VertexPositionIndex += VertexPositions.size ();
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
					VertexTexturePositionIndex += VertexTexturePositions.size ();
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
					VertexNormalIndex += VertexNormals.size ();
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
	
	Out.VertexIndexBase = Vertices.size ();
	Out.VertexCount = VertexAccumulator.size ();
	
	Faces.push_back ( Out );
	
	return true;
	
};

bool RAUX::ObjFile :: ProcessGroups ( const std :: string & Line, uint32_t Index )
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
	ActiveGroupFaceIndexBase = Faces.size ();
	
	for ( uint32_t I = 0; I < GroupNames.size (); I ++ )
	{
		
		int32_t ActiveIndex = - 1;
		
		for ( int32_t J = 0; J < Groups.size (); J ++ )
		{
			
			if ( Groups [ J ].Name == GroupNames [ I ] )
				ActiveGroupIndexes.push_back ( J );
			
		}
		
		if ( ActiveIndex == - 1 )
		{
			
			ActiveGroupIndexes.push_back ( Groups.size () );
			Groups.push_back ( GroupNames [ I ] );
			
		}
		
	}
	
	return true;
	
};

void RAUX::ObjFile :: ResolveActiveGroups ()
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
	
};

void RAUX::ObjFile :: CloseFile ()
{
	
	FileInstance.Close ();
	
};

bool RAUX::ObjFile :: Valid () const
{
	
	return Validated;
	
};

uint32_t RAUX::ObjFile :: GetCommentCount () const
{
	
	return Comments.size ();
	
};

const std :: string & RAUX::ObjFile :: GetComment ( uint32_t Index ) const
{
	
	if ( Index >= Comments.size () )
		return Comments [ 0 ];
	
	return Comments [ Index ];
	
};

uint32_t RAUX::ObjFile :: GetVertexPositionCount () const
{
	
	return VertexPositions.size ();
	
};

const RAUX::ObjFile :: Vec3 RAUX::ObjFile :: GetVertexPosition ( uint32_t Index ) const
{
	
	if ( Index >= VertexPositions.size () )
		return Vec3 ( 0.0f, 0.0f, 0.0f );
	
	return VertexPositions [ Index ];
	
};

uint32_t RAUX::ObjFile :: GetVertexNormalCount () const
{
	
	return VertexNormals.size ();
	
};

const RAUX::ObjFile :: Vec3 RAUX::ObjFile :: GetVertexNormal ( uint32_t Index ) const
{
	
	if ( Index >= VertexNormals.size () )
		return Vec3 ( 0.0f, 0.0f, 0.0f );
	
	return VertexNormals [ Index ];
	
};

uint32_t RAUX::ObjFile :: GetVertexTexturePositionCount () const
{
	
	return VertexPositions.size ();
	
};

const RAUX::ObjFile :: TexturePosition RAUX::ObjFile :: GetVertexTexturePosition ( uint32_t Index ) const
{
	
	if ( Index < VertexTexturePositions.size () )
		return VertexTexturePositions [ Index ];
	
	return TexturePosition ();
	
};

uint32_t RAUX::ObjFile :: GetGroupCount () const
{
	
	return Groups.size ();
	
};

const RAUX::ObjFile :: Group * const RAUX::ObjFile :: GetGroup ( uint32_t Index ) const
{
	
	if ( Index >= Groups.size () )
		return NULL;
	
	return & Groups [ Index ];
	
};

const RAUX::ObjFile :: Group * const RAUX::ObjFile :: GetGroup ( const std :: string & Name ) const
{
	
	for ( uint32_t I = 0; I < Groups.size (); I ++ )
	{
		
		if ( Groups [ I ].Name == Name )
			return & Groups [ I ];
		
	}
	
	return NULL;
	
};

#ifdef RAUX_XENON_MATH_INTERFACE

Xenon::Geometry :: Mesh * RAUX::ObjFile :: CreateMesh ( const MeshParameters & Parameters )
{
	
	return NULL;
	
};

#endif
