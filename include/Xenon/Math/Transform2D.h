#ifndef XENON_MATH_TRANSFORM2D_H
#define XENON_MATH_TRANSFORM2D_H

#include <Xenon/Xenon.h>
#include <Xenon/Math/Math.h>
#include <Xenon/Math/Vec2.h>
#include <Xenon/Math/Matrix3x3.h>
#include <Xenon/GPU/GLInclude.h>
#include <Xenon/GPU/IMatrix3x3UniformSource.h>

#include <Red/Util/RefCounted.h>

namespace Xenon
{
	
	namespace Math
	{
		
		class Transform2D : public Red::Util :: RefCounted
		{
		public:
			
			Transform2D ();
			Transform2D ( const Vec2 & Translation );
			Transform2D ( const Vec2 & Translation, const Vec2 & Scale );
			Transform2D ( const Vec2 & Translation, const Vec2 & Scale, const float Rotation );
			
			~Transform2D ();
			
			void SetTranslation ( const Vec2 & Translation );
			void SetScale ( const Vec2 & Scale );
			void SetRotation ( float Rotation );
			
			const Vec2 & ReadTranslation ();
			const Vec2 & ReadScale ();
			float ReadRotation ();
			
			Vec2 & ReadTranslationMutable ();
			Vec2 & ReadScaleMutable ();
			float & ReadRotationMutable ();
			
			void Flush ();
			
			const Matrix3x3 & ReadMatrix ();
			
			GPU :: IMatrix3x3UniformSource & GetTransformUniformSource ();
			
		private:
			
			class InternalMatrix3x3UniformSource : public GPU :: IMatrix3x3UniformSource
			{
			public:
				
				InternalMatrix3x3UniformSource ( Transform2D & Source );
				~InternalMatrix3x3UniformSource ();
				
				void Reference ();
				void Dereference ();
				
				const GLfloat * GetFloatArray () const;
				
				bool IsTransposed () const;
				
				int64_t GetIteration () const;
				
			private:
				
				Transform2D & Source;
				
			};
			
			Vec2 Translation;
			Vec2 Scale;
			float Rotation;
			
			bool Dirty;
			Matrix3x3 Matrix;
			InternalMatrix3x3UniformSource MatrixSource;
			int64_t Iteration;
			
		};
		
	}
	
}

#endif
