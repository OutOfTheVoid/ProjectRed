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

namespace RAUX
{
	
	class STLFile
	{
	public:
		
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
		
		STLFile ( const std :: string & Name );
		~STLFile ();
		
		bool Exists () const ();
		
		void Load ( uint32_t * Status );
		
#ifdef RAUX_XENON_INTERFACE
		
		Xenon::Geometry :: Mesh * CreateMesh ( const MeshParameters & Params ) const;
		
#endif
		
	private:
		
		File FileInstance;
		
	};
	
};

#endif
