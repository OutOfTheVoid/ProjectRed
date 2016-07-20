#ifndef RAUX_OBJFILE_H
#define RAUX_OBJFILE_H

#include <RAUX/RAUX.h>
#include <RAUX/TextFile.h>
#include <RAUX/MTLFile.h>

#ifdef RAUX_XENON_INTERFACE
	#include <Xenon/Math/Vec3.h>
	#include <Xenon/Geometry/Mesh.h>
#endif

#include <string>
#include <vector>
#include <map>
#include <math.h>

/*
* ObjFile: Represents a wavefron 3D object file and parses it's contents into values and structures representing it's rendering properties and geometry.
* Optionally, has the ability to construct a Xenon mesh for rendering.
*/

namespace RAUX
{
	
	class ObjFile
	{
	public:
		
		static const uint32_t kStatus_Success = 0;
		static const uint32_t kStatus_Failure_NonExistantFile = 1;
		static const uint32_t kStatus_Failure_Load = 2;
		static const uint32_t kStatus_Failure_MemoryAllocation = 3;
		static const uint32_t kStatus_Failure_InvalidFile = 4;
		static const uint32_t kStatus_Failure_InvalidGroup = 5;
		
		static const uint32_t kFlags_StoreComments = 1;
		static const uint32_t kFlags_NoNormals = 2;
		static const uint32_t kFlags_NoTexturePositions = 4;
		static const uint32_t kFlags_NoGrouping = 8;
		static const uint32_t kFlags_FailOnUnsupportedCommand = 16;
		static const uint32_t kFlags_NoRAUXComment = 16;
		static const uint32_t kFlags_NoNormalNormalization = 32;
		
#ifdef RAUX_XENON_INTERFACE
		
		static const uint32_t kMeshParameterFlags_Normals = 1;
		static const uint32_t kMeshParameterFlags_TexturePositions = 2;
		static const uint32_t kMeshParameterFlags_GenerateMissingNormals = 4;
		static const uint32_t kMeshParameterFlags_ForceGenerateNormals = 8;
		static const uint32_t kMeshParameterFlags_GenerateTangents = 16;
		static const uint32_t kMeshParameterFlags_ForceFirstLineTangents = 32;
		
		typedef Xenon::Math::Vec3 Vec3;
		
		#define OBJFILE_VEC3_NOINIT Xenon::Math::Vec3 :: NO_INIT
		#define OBJFILE_VEC3_NORMALIZE(v) Xenon::Math::Vec3 :: Normalize ( v )
		
#else
		
		typedef struct Vec3_Struct
		{
			
			inline Vec3_Struct ( float X = 0.0f, float Y = 0.0f, float Z = 0.0f ):
				X ( X ),
				Y ( Y ),
				Z ( Z )
			{
			};
			
			float X;
			float Y;
			float Z;
			
		} Vec3;
		
		inline void Vec3_Normalize ( Vec3 & Target )
		{
			
			float Scale = 1.0f / sqrt ( Target.X * Target.X + Target.Y * Target.Y + Target.Z * Target.Z );
			
			Target.X *= Scale;
			Target.Y *= Scale;
			Target.Z *= Scale;
			
		};
		
		#define OBJFILE_VEC3_NOINIT 0.0f, 0.0f, 0.0f
		#define OBJFILE_VEC3_NORMALIZE(v) Vec3_Normalize ( v );
		
#endif
		
		// Tecture position struct, represents a texture position in 1D, 2D, or 3D in < Position > field as denoted by < Dimension >.
		typedef struct TexturePosition_Struct
		{
			
			TexturePosition_Struct ();
			
			Vec3 Position;
			uint32_t Dimension;
			
		} TexturePosition;
		
		// Face struct, represents a geometric face as an index < VertexIndexBase > into the vertex list, sequentially, with < VertexCount > verticies.
		typedef struct Face_Struct
		{
			
			uint32_t VertexIndexBase;
			uint32_t VertexCount;
			
		} Face;
		
		// Vertex struct, represents a vertex as indexes into the position list < VertexPositionIndex >, normal list < VertexNormalIndex >, and texture position list < VertexTexturePositionIndex >. These values are set to - 1 if a vertex does not have the relevant information.
		typedef struct Vertex_Struct
		{
			
			int32_t VertexPositionIndex;
			int32_t VertexNormalIndex;
			int32_t VertexTexturePositionIndex;
			
		} Vertex;
		
		// Group struct, represents a "group" as per the Wavefront OBJ spec, where the group name is < Name >, and where < FaceIndecies > contains the indecies into the face list of faces that belong to that group.
		typedef struct Group_Struct
		{
			
			Group_Struct ( const std :: string & Name );
			Group_Struct ( const Group_Struct & CopyFrom );
			
			const std :: string Name;
			
			std :: vector <uint32_t> FaceIndecies;
			
		} Group;
		
#ifdef RAUX_XENON_INTERFACE
		
		// Mesh parameter struct, represents parameters for mesh creation.
		typedef struct MeshParameters_Struct
		{
			
			// Pointer to an array of group indexes.
			const uint32_t * GroupIndexes;
			// Count of the number of groups to include in this mesh.
			const uint32_t GroupCount;
			
			// Names of various mesh attributes discoverable in an OBJ file.
			std :: string PositionAttributeName;
			std :: string NormalAttributeName;
			std :: string TexturePositionAttributeName;
			std :: string TangentAttributeName;
			
			// Flags for the mesh, see kMeshParameterFlags_* for more info.
			uint32_t Flags;
			
			// Whether or not to use an interleaved buffer strategy for the mesh attributes.
			bool InterleaveAttributes;
			// Whether or not to use static attributes in the mesh.
			bool StaticAttributes;
			
		} MeshParameters;
		
#endif
		
		ObjFile ( const std :: string & Path, uint32_t Flags = 0 );
		~ObjFile ();
		
		bool Exists () const;
		
		void Load ( uint32_t * Status );
		void CloseFile ();
		
		bool Valid () const;
		
		uint32_t GetCommentCount () const;
		const std :: string & GetComment ( uint32_t Index ) const;
		
		uint32_t GetVertexPositionCount () const;
		const Vec3 GetVertexPosition ( uint32_t Index ) const;
		
		uint32_t GetVertexNormalCount () const;
		const Vec3 GetVertexNormal ( uint32_t Index ) const;
		
		uint32_t GetVertexTexturePositionCount () const;
		const TexturePosition GetVertexTexturePosition ( uint32_t Index ) const;
		
		uint32_t GetGroupCount () const;
		const Group * const GetGroup ( uint32_t Index ) const;
		const Group * const GetGroup ( const std :: string & Name ) const;
		
		uint32_t GetVertexCount () const;
		const Vertex GetVertex ( uint32_t Index ) const;
		
		uint32_t GetFaceCount () const;
		const Face GetFace ( uint32_t Index ) const;
		
#ifdef RAUX_XENON_INTERFACE
		
		Xenon::Geometry :: Mesh * CreateMesh ( const MeshParameters & Parameters, uint32_t * Status );
		
#endif
		
	private:
		
		bool ProcessTextLine ( const std :: string & Line );
		
		bool ProcessVertexPosition ( const std :: string & Line, uint32_t Index );
		bool ProcessVertexNormal ( const std :: string & Line, uint32_t Index );
		bool ProcessVertexTexturePosition ( const std :: string & Line, uint32_t Index );
		bool ProcessFace ( const std :: string & Line, uint32_t Index );
		bool ProcessGroups ( const std :: string & Line, uint32_t Index );
		bool ProcessMaterial ( const std :: string & Line, uint32_t Index );
		bool ProcessMaterialLibrary ( const std :: string & Line, uint32_t Index );
		
		void ResolveActiveGroups ();
		
		TextFile FileInstance;
		
		uint32_t Flags;
		
		bool Validated;
		
		std :: vector <std :: string> Comments;
		
		std :: vector <Group> Groups;
		std :: vector <uint32_t> ActiveGroupIndexes;
		uint32_t ActiveGroupFaceIndexBase;
		
		std :: vector <Vec3> VertexPositions;
		std :: vector <Vec3> VertexNormals;
		std :: vector <TexturePosition> VertexTexturePositions;
		
		std :: vector <Vertex> Vertices;
		std :: vector <Face> Faces;
		
		std :: vector <std :: string> MaterialLibraryPrefixes;
		
		std :: vector <MtlFile> MaterialLibraries;
		std :: map <std :: string, MtlFile :: Material> Materials;
		
	};
	
};

#endif
