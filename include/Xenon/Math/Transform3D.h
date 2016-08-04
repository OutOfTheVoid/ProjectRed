#ifndef XENON_MATH_TRANSFORM3D_H
#define XENON_MATH_TRANSFORM3D_H

#include <Xenon/Xenon.h>
#include <Xenon/Math/Math.h>
#include <Xenon/Math/Quaternion.h>
#include <Xenon/Math/Vec3.h>
#include <Xenon/Math/Matrix4x4.h>
#include <Xenon/GPU/GLInclude.h>
#include <Xenon/GPU/IMatrix4x4UniformSource.h>
#include <Xenon/Util/RefCounted.h>

namespace Xenon
{
	
	namespace Math
	{
		
		class Transform3D : public Util :: RefCounted
		{
		public:
			
			Transform3D ();
			Transform3D ( const Vec3 & Translation );
			Transform3D ( const Vec3 & Translation, const Vec3 & Scale );
			Transform3D ( const Vec3 & Translation, const Vec3 & Scale, const Quaternion & Rotation );
			
			~Transform3D ();
			
			void SetTranslation ( const Vec3 & Translation );
			void SetScale ( const Vec3 & Scale );
			void SetRotation ( const Quaternion & Rotation );
			
			void AppendTranslation ( const Vec3 & Translation );
			void AppendScale ( const Vec3 & Scale );
			void AppendRotation ( const Quaternion & Rotation );
			
			void FlushMatricies ( bool Model = true, bool Normal = true, bool InverseNormal = false );
			
			const Vec3 & ReadTranslation ();
			const Vec3 & ReadScale ();
			const Quaternion & ReadRotation ();
			
			Vec3 & ReadTranslationMutable ();
			Vec3 & ReadScaleMutable ();
			Quaternion & ReadRotationMutable ();
			
			const Matrix4x4 & ReadNormalMatrix ();
			const Matrix4x4 & ReadInverseNormalMatrix ();
			const Matrix4x4 & ReadModelMatrix ();
			
			GPU :: IMatrix4x4UniformSource & GetNormalUniformSource ();
			GPU :: IMatrix4x4UniformSource & GetInverseNormalUniformSource ();
			GPU :: IMatrix4x4UniformSource & GetModelUniformSource ();
			
		private:
			
			class InternalMatrix4x4UniformSource : public GPU :: IMatrix4x4UniformSource
			{
			public:
				
				InternalMatrix4x4UniformSource ( Transform3D * Source, const Matrix4x4 & ( Transform3D :: * ReadFunction ) (), int64_t * IterationPTR );
				~InternalMatrix4x4UniformSource ();
				
				const GLfloat * GetFloatArray () const;
				bool IsTransposed () const;
				
				void Reference ();
				void Dereference ();
				
				int64_t GetIteration () const;
				
			private:
				
				Transform3D * Source;
				const Matrix4x4 & ( Transform3D :: * ReadFunction ) ();
				int64_t * IterationPTR;
				
			};
			
			Vec3 Translation;
			Vec3 Scale;
			Quaternion Rotation;
			
			bool NormalDirty;
			Matrix4x4 NormalMatrix;
			InternalMatrix4x4UniformSource NormalMatrixSource;
			int64_t NormalIteration;
			
			bool InverseNormalDirty;
			Matrix4x4 InverseNormalMatrix;
			InternalMatrix4x4UniformSource InverseNormalMatrixSource;
			int64_t InverseNormalIteration;
			
			bool ModelDirty;
			Matrix4x4 ModelMatrix;
			InternalMatrix4x4UniformSource ModelMatrixSource;
			int64_t ModelIteration;
			
		};
		
	}
	
}

#endif
