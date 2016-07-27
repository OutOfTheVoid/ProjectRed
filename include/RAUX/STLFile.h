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
		
		static const uint32_t kFlags_NormalizeNormals = 1;
		static const uint32_t kFlags_ReplaceNormalsConditional = 2;
		static const uint32_t kFlags_ReplaceNormalsForced = 4;
		static const uint32_t kFlags_CenterPositions = 8;
		static const uint32_t kFlags_NormalizePositions = 16;
		static const uint32_t kFlags_ForwardFace_CounterClockwise = 32;
		
#ifdef RAUX_XENON_INTERFACE
		
		static const uint32_t kMeshParameterFlags_Normals = 1;
		static const uint32_t kMeshParameterFlags_SeperateStaticAttributes = 2;
		static const uint32_t kMeshParameterFlags_InterleavedAttributes = 4;
		static const uint32_t kMeshParameterFlags_ReverseWindingOrder = 8;
		static const uint32_t kMeshParameterFlags_DynamicPositions = 16;
		static const uint32_t kMeshParameterFlags_DynamicNormals = 32;
		
		typedef Xenon::Math::Vec3 Vec3;
		
		#define STLFILE_VEC3_NOINIT Xenon::Math::Vec3 :: NO_INIT
		#define STLFILE_VEC3_NORMALIZE( v ) Xenon::Math::Vec3 :: Normalize ( v )
		#define STLFILE_VEC3_SUBTRACT( t, u, v ) Xenon::Math::Vec3 :: Subtract ( t, u, v )
		#define STLFILE_VEC3_ADD( t, s ) Xenon::Math::Vec3 :: Add ( t, s )
		#define STLFILE_VEC3_CROSS( t, u, v) Xenon::Math::Vec3 :: CrossProduct ( t, u, v )
		#define STLFILE_VEC3_MULTIPLYSCALAR( v, f ) Xenon::Math::Vec3 :: Multiply ( v, f )
		#define STLFILE_VEC3_LENGTH( v ) Xenon::Math::Vec3 :: Length ( v )
		#define STLFILE_VEC3_COPY( t, s ) Xenon::Math::Vec3 :: Copy ( t, s )
		
		typedef struct MeshParameters_Struct
		{
			
			inline MeshParameters_Struct ( uint32_t Flags, const std :: string & PositionAttributeName, const std :: string & NormalAttributeName ):
				Flags ( Flags ),
				PositionAttributeName ( PositionAttributeName ),
				NormalAttributeName ( NormalAttributeName )
			{
			};
			
			uint32_t Flags;
			
			std :: string PositionAttributeName;
			std :: string NormalAttributeName;
			
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
			
		}
		
		inline void Vec3_Subtract ( Vec3 & Target, const Vec3 & U, const Vec3 & V )
		{
			
			Target.X = U.X - V.X;
			Target.Y = U.Y - V.Y;
			Target.Z = U.Z - V.Z;
			
		}
		
		inline void Vec3_Add ( Vec3 & Target, const Vec3 & Source )
		{
			
			Target.X += Source.X;
			Target.Y += Source.Y;
			Target.Z += Source.Z;
			
		}
		
		inline void Vec3_CrossProduct ( Vec3 & Target, const Vec3 & U, const Vec3 & V )
		{
			
			Target.X = U.Y * V.Z - U.Z * V.Y;
			Target.Y = U.Z * V.X - U.X * V.Z;
			Target.Z = U.X * V.Y - U.Y * V.X;
			
		}
		
		inline void Vec3_MultiplyScalar ( Vec3 & Target, const float Scalar )
		{
			
			Target.X *= Scalar;
			Target.Y *= Scalar;
			Target.Z *= Scalar;
			
		}
		
		inline float Vec3_Length ( const Vec3 & Source )
		{
			
			return sqrt ( Source.X * Source.X + Source.Y * Source.Y + Source.Z * Source.Z );
			
		}
		
		inline void Vec3_Copy ( Vec3 & Target, const Vec3 & Source )
		{
			
			Target.X = Source.X;
			Target.Y = Source.Y;
			Target.Z = Source.Z;
			
		}
		
		#define STLFILE_VEC3_NOINIT 0.0f, 0.0f, 0.0f
		#define STLFILE_VEC3_NORMALIZE(v) Vec3_Normalize ( v )
		#define STLFILE_VEC3_SUBTRACT(t,u,v) Vec3_Subtract ( t, u, v )
		#define STLFILE_VEC3_ADD(t,s) Vec3_Add ( t, s )
		#define STLFILE_VEC3_CROSS(t,v,w) Vec3_CrossProduct ( t, v, w )
		#define STLFILE_VEC3_MULTIPLYSCALAR(v,f) Vec3_MultiplyScalar ( v, f )
		#define STLFILE_VEC3_LENGTH(v) Vec3_Length ( v )
		#define STLFILE_VEC3_COPY( t, s ) Vec3_Copy ( t, s )
		
#endif
		
		typedef struct Triangle_Struct
		{
			
			Vec3 Normal;
			Vec3 P1;
			Vec3 P2;
			Vec3 P3;
			
		} Triangle;
		
		StlFile ( const std :: string & Name );
		~StlFile ();
		
		bool Exists () const;
		
		void Load ( uint32_t * Status, uint32_t Flags );
		void CloseFile ();
		
		uint32_t GetTriangleCount () const;
		const Triangle * const GetTriangle ( uint32_t Index ) const;
		
#ifdef RAUX_XENON_INTERFACE
		
		Xenon::Geometry :: Mesh * CreateMesh ( const MeshParameters & Params ) const;
		
#endif
		
	private:
		
		File FileInstance;
		
		uint32_t TriangleCount;
		Triangle * TriangleList;
		
		uint32_t Flags;
		
	};
	
}

#endif
