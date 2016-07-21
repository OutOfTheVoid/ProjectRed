#ifndef RAUX_MTLFILE_H
#define RAUX_MTLFILE_H

#include <RAUX/RAUX.h>
#include <RAUX/TextFile.h>

#ifdef RAUX_XENON_INTERFACE
	#include <Xenon/Math/Vec3.h>
#endif

#include <math.h>

/*
* MtlFile: Represents a model library file used by the ObjFile class for loading 3D object materials.
*/

namespace RAUX
{
	
	class MtlFile
	{
	public:
		
		static const uint32_t kStatus_Success = 0;
		static const uint32_t kStatus_Failure_NonExistantFile = 1;
		static const uint32_t kStatus_Failure_Load = 2;
		static const uint32_t kStatus_Failure_MemoryAllocation = 3;
		static const uint32_t kStatus_Failure_InvalidFile = 4;
		
#ifdef RAUX_XENON_INTERFACE
		
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
		
		static const uint32_t kIlluminationModel_Color = 0;
		static const uint32_t kIlluminationModel_CAmbiant = 1;
		static const uint32_t kIlluminationModel_CAHighlight = 2;
		static const uint32_t kIlluminationModel_CAHReflect = 3;
		static const uint32_t kIlluminationModel_CAHRTransparency = 4;
		static const uint32_t kIlluminationModel_CAHRTFresnel = 5;
		static const uint32_t kIlluminationModel_CAHRTFRefraction = 6;
		static const uint32_t kIlluminationModel_CAHReflect_NoRayTrace = 7;
		static const uint32_t kIlluminationModel_CAHRTransparency_NoRayTrace = 8;
		static const uint32_t kIlluminationModel_CastInvisibleSurfaceShadows = 9;
		
		// MTLFile :: Material: A structure representing a parsed material from the file.
		
		typedef struct
		{
			
			Vec3 Reflectivity;
			bool ReflectivityIsCIEXYZ;
			
			Vec3 Diffuse;
			bool DiffuseIsCIEXYZ;
			
			Vec3 Specular;
			bool SpecularIsCIEXYZ;
			
			Vec3 TransmissionFilter;
			
			uint32_t IlluminationModel;
			
			float Dissolve;
			bool Halo;
			
			float SpecularExponent;
			
			float OpticalDensity;
			
		} Material;
		
		// Constructs an MTLFile object, using the file name < Name >.
		MtlFile ( const std :: string & Name );
		MtlFile ( const MtlFile & CopyFrom );
		~MtlFile ();
		
		// Whether or not this file exists.
		bool Exists () const;
		
		// = operator.
		void operator= ( const RAUX::MtlFile & );
		
		// Loads and parses the contents of the .mtl file. Returns status in < Status >.
		void Load ( uint32_t * Status );
		
		// Returns the number of successfully loaded materials.
		uint32_t GetMaterialCount () const;
		// Returns a reference to the name of a material at < Index >, or a reference to < "" > if < Index > is out of bounds.
		const std :: string & GetMaterialName ( uint32_t Index ) const;
		
		// Returns a pointer to a material structure at < Index >, or returns NULL if < Index > is out of bounds.
		const Material * const GetMaterial ( uint32_t Index ) const;
		// Returns a pointer to a material structure specified by the name < Name >, or returns NULL if a material by that name doesn't exist.
		const Material * const GetMaterial ( const std :: string & Name ) const;
		
	private:
		
		// The actual file
		TextFile FileInstance;
		
	};
	
}

#endif
