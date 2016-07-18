#ifndef RAUX_OBJFILE_H
#define RAUX_OBJFILE_H

#include <RAUX/RAUX.h>
#include <RAUX/TextFile.h>

#ifdef RAUX_XENON_MATH_INTERFACE
	#include <Xenon/Math/Vec3.h>
	#include <Xenon/Geometry/Mesh.h>
#endif

#include <string>
#include <vector>
#include <math.h>

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
		
		static const uint32_t kFlags_StoreComments = 1;
		static const uint32_t kFlags_NoNormals = 2;
		static const uint32_t kFlags_NoTexturePositions = 4;
		static const uint32_t kFlags_NoGrouping = 8;
		static const uint32_t kFlags_FailOnUnsupportedCommand = 16;
		static const uint32_t kFlags_NoRAUXComment = 16;
		
#ifdef RAUX_XENON_MATH_INTERFACE
		
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
		
		typedef struct TexturePosition_Struct
		{
			
			TexturePosition_Struct ();
			
			Vec3 Position;
			uint32_t Dimension;
			
		} TexturePosition;
		
		typedef struct Face_Struct
		{
			
			uint32_t VertexIndexBase;
			uint32_t VertexCount;
			
		} Face;
		
		typedef struct Vertex_Struct
		{
			
			int32_t VertexPositionIndex;
			int32_t VertexNormalIndex;
			int32_t VertexTexturePositionIndex;
			
		} Vertex;
		
		typedef struct Group_Struct
		{
			
			Group_Struct ( const std :: string & Name );
			Group_Struct ( const Group_Struct & CopyFrom );
			
			const std :: string Name;
			
			std :: vector <uint32_t> FaceIndecies;
			
		} Group;
		
#ifdef RAUX_XENON_MATH_INTERFACE
		
		typedef struct MeshParameters_Struct
		{
			
			std :: string PositionAttributeName;
			std :: string NormalAttributeName;
			std :: string TexturePositionAttributeName;
			
			bool InterleaveAttributes;
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
		
#ifdef RAUX_XENON_MATH_INTERFACE
		
		Xenon::Geometry :: Mesh * CreateMesh ( const MeshParameters & Parameters );
		
#endif
		
	private:
		
		bool ProcessTextLine ( const std :: string & Line );
		
		bool ProcessVertexPosition ( const std :: string & Line, uint32_t Index );
		bool ProcessVertexNormal ( const std :: string & Line, uint32_t Index );
		bool ProcessVertexTexturePosition ( const std :: string & Line, uint32_t Index );
		bool ProcessFace ( const std :: string & Line, uint32_t Index );
		bool ProcessGroups ( const std :: string & Line, uint32_t Index );
		
		void ResolveActiveGroups ();
		
		TextFile FileInstance;
		
		uint32_t Flags;
		
		bool Validated;
		
		std :: vector <std :: string> Comments;
		
		std :: vector <Group> Groups;
		std :: vector <uint32_t> ActiveGroupIndexes;
		uint32_t ActiveGroupFaceIndexBase;
		
		std :: vector <Xenon::Math::Vec3> VertexPositions;
		std :: vector <Xenon::Math::Vec3> VertexNormals;
		std :: vector <TexturePosition> VertexTexturePositions;
		
		std :: vector <Vertex> Vertices;
		std :: vector <Face> Faces;
		
	};
	
};

#endif
