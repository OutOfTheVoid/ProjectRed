#ifndef RAUX_STLFILE_H
#define RAUX_STLFILE_H

#include <RAUX/RAUX.h>
#include <RAUX/File.h>

#ifdef RAUX_XENON_INTERFACE
	#include <Xenon/Math/Vec3.h>
	#include <Xenon/Geometry/Mesh.h>
#endif

#include <stdint.h>

#include <string>
#include <math.h>

namespace RAUX
{
	
	class StlFile
	{
	public:
		
		static const uint32_t kStatus_Success = 0;
		static const uint32_t kStatus_Failure_NonExistantFile = 1;
		static const uint32_t kStatus_Failure_Load = 2;
		static const uint32_t kStatus_Failure_MemoryAllocation = 3;
		static const uint32_t kStatus_Failure_InvalidFile = 4;
		
#ifdef RAUX_XENON_INTERFACE
		
		static const uint32_t kMeshParameterFlags_Normals = 1;
		
		typedef Xenon::Math::Vec3 Vec3;
		
		#define OBJFILE_VEC3_NOINIT Xenon::Math::Vec3 :: NO_INIT
		#define OBJFILE_VEC3_NORMALIZE(v) Xenon::Math::Vec3 :: Normalize ( v )
		
		typedef struct MeshParameters_Struct
		{
			
			
			
		} MeshParameters;
		
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
		
		StlFile ( const std :: string & Name );
		~StlFile ();
		
		bool Exists () const;
		
		void Load ( uint32_t * Status );
		void CloseFile ();
		
#ifdef RAUX_XENON_INTERFACE
		
		Xenon::Geometry :: Mesh * CreateMesh ( const MeshParameters & Params ) const;
		
#endif
		
	private:
		
		typedef struct Triangle_Struct
		{
			
			Vec3 Normal;
			Vec3 P1;
			Vec3 P2;
			Vec3 P3;
			
		} Triangle;
		
		File FileInstance;
		
		uint32_t TriangleCount;
		
		Triangle * TriangleList;
		
	};
	
}

#endif