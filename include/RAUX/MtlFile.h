#ifndef RAUX_MTLFILE_H
#define RAUX_MTLFILE_H

#include <RAUX/RAUX.h>
#include <RAUX/TextFile.h>

#ifdef RAUX_XENON_INTERFACE
	#include <Xenon/Math/Vec3.h>
#endif

#include <math.h>

#include <vector>

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
		
		static const uint32_t kFlags_StoreComments = 1;
		static const uint32_t kFlags_FailOnUnsupportedCommand = 2;
		static const uint32_t kFlags_NoRAUXComment = 4;
		
#ifdef RAUX_XENON_INTERFACE
		
		typedef Xenon::Math::Vec3 Vec3;
		
		#define MTLFILE_VEC3_NOINIT Xenon::Math::Vec3 :: NO_INIT
		#define MTLFILE_VEC3_NORMALIZE(v) Xenon::Math::Vec3 :: Normalize ( v )
		
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
		
		#define MTLFILE_VEC3_NOINIT 0.0f, 0.0f, 0.0f
		#define MTLFILE_VEC3_NORMALIZE(v) Vec3_Normalize ( v );
		
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
		
		typedef struct Material_Struct
		{
			
			Material_Struct ( const std :: string & Name );
			Material_Struct ( const Material_Struct & CopyFrom );
			
			std :: string Name;
			
			Vec3 Ambiant;
			bool AmbiantIsCIEXYZ;
			std :: string AmbiantMapName;
			
			Vec3 Diffuse;
			bool DiffuseIsCIEXYZ;
			std :: string DiffuseMapName;
			
			Vec3 Specular;
			bool SpecularIsCIEXYZ;
			std :: string SpecularMapName;
			
			Vec3 Emission;
			bool EmissionIsCIEXYZ;
			std :: string EmissionMapName;
			
			Vec3 TransmissionFilter;
			bool TransmissionIsCIEXYZ;
			std :: string TransmissionMapName;
			
			uint32_t IlluminationModel;
			
			float Dissolve;
			bool Halo;
			
			float SpecularExponent;
			
			float OpticalDensity;
			
		} Material;
		
		// Constructs an MTLFile object, using the file name < Name >.
		MtlFile ( const std :: string & Name, uint32_t Flags );
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
		
		// Returns the number of comments recorded.
		uint32_t GetCommentCount () const;
		// Gets a comment by index, or "" if the index is out of range.
		const std :: string & GetComment ( uint32_t Index ) const;
		
	private:
		
		bool ProcessTextLine ( const std :: string & Line );
		
		bool ProcessIlluminationModel ( const std :: string & Line, uint32_t Index );
		bool ProcessNewMaterial ( const std :: string & Line, uint32_t Index );
		
		bool ProcessAmbiant ( const std :: string & Line, uint32_t Index );
		bool ProcessDiffuse ( const std :: string & Line, uint32_t Index );
		bool ProcessSpecular ( const std :: string & Line, uint32_t Index );
		bool ProcessEmission ( const std :: string & Line, uint32_t Index );
		bool ProcessTransmissionFilter ( const std :: string & Line, uint32_t Index );
		
		bool ProcessDisolve ( const std :: string & Line, uint32_t Index );
		
		bool ProcessSpecularExponent ( const std :: string & Line, uint32_t Index );
		bool ProcessOpticalDensity ( const std :: string & Line, uint32_t Index );
		
		uint32_t Flags;
		
		// The actual file
		TextFile FileInstance;
		
		std :: vector <Material> Materials;
		
		std :: vector <std :: string> Comments;
		
		static std :: string NullComment;
		
	};
	
}

#endif
