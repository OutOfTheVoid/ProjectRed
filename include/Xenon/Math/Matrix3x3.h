#ifndef XENON_MATH_MATRIX3X3_H
#define XENON_MATH_MATRIX3X3_H

#include <Xenon/Xenon.h>
#include <Xenon/Math/Math.h>

#include <stdint.h>

namespace Xenon
{
	
	namespace Math
	{
		
		class Vec3;
		class Vec2;
		
		class Matrix3x3
		{
		public:
			
			enum NoInit
			{
				
				NO_INIT
				
			};
			
			Matrix3x3 ();
			explicit Matrix3x3 ( const float A, const float B, const float C, const float D, const float E, const float F, const float G, const float H, const float I );
			Matrix3x3 ( const Matrix3x3 & CopyFrom );
			Matrix3x3 ( NoInit NO_INIT );
			
			~Matrix3x3 ();
			
			static void Identity ( Matrix3x3 & Target );
			
			static void Copy ( Matrix3x3 & Target, const Matrix3x3 & Source );
			
			static void Transpose ( Matrix3x3 & Target );
			static void Transpose ( Matrix3x3 & Target, const Matrix3x3 & Source );
			
			static void Invert ( Matrix3x3 & Target );
			static void Invert ( Matrix3x3 & Target, const Matrix3x3 & Source );
			
			static bool Invertible ( const Matrix3x3 & Source, float PrecisionThreshold = 1.18e-38 ); // the default value is the minimum positive normal of an IEEE 754 32-bit float.
			
			static float Determinant ( const Matrix3x3 & Source );
			
			static float GetElement ( const Matrix3x3 & Source, uint32_t X, uint32_t Y );
			static float & GetElementMutable ( Matrix3x3 & Source, uint32_t X, uint32_t Y );
			
			static void MultiplyScalar ( Matrix3x3 & Target, const float Scalar );
			static void MultiplyScalar ( Matrix3x3 & Target, const Matrix3x3 & Source, const float Scalar );
			
			static void SetAsTranslation ( Matrix3x3 & Target, const Vec2 & Translation );
			static void SetAsTranslation ( Matrix3x3 & Target, const float X, const float Y );
			static void AppendTranslation ( Matrix3x3 & Target, const Vec2 & Translation );
			static void AppendTranslation ( Matrix3x3 & Target, const float X, const float Y );
			static void AppendTranslation ( Matrix3x3 & Target, const Matrix3x3 & Source, const Vec2 & Translation );
			static void AppendTranslation ( Matrix3x3 & Target, const Matrix3x3 & Source, const float X, const float Y );
			static void PrependTranslation ( Matrix3x3 & Target, const Vec2 & Translation );
			static void PrependTranslation ( Matrix3x3 & Target, const float X, const float Y );
			static void PrependTranslation ( Matrix3x3 & Target, const Matrix3x3 & Source, const Vec2 & Translation );
			static void PrependTranslation ( Matrix3x3 & Target, const Matrix3x3 & Source, const float X, const float Y );
			
			static void SetAsRotation ( Matrix3x3 & Target, const float Rotation );
			static void AppendRotation ( Matrix3x3 & Target, const float Rotation );
			static void AppendRotation ( Matrix3x3 & Target, const Matrix3x3 & Source, const float Rotation );
			static void PrependRotation ( Matrix3x3 & Target, const float Rotation );
			static void PrependRotation ( Matrix3x3 & Target, const Matrix3x3 & Source, const float Rotation );
			
			static void SetAsScale ( Matrix3x3 & Target, const Vec2 & Scale );
			static void SetAsScale ( Matrix3x3 & Target, const float X, const float Y );
			static void AppendScale ( Matrix3x3 & Target, const Vec2 & Scale );
			static void AppendScale ( Matrix3x3 & Target, const float X, const float Y );
			static void AppendScale ( Matrix3x3 & Target, const Matrix3x3 & Source, const Vec2 & Scale );
			static void AppendScale ( Matrix3x3 & Target, const Matrix3x3 & Source, const float X, const float Y );
			static void PrependScale ( Matrix3x3 & Target, const Vec2 & Scale );
			static void PrependScale ( Matrix3x3 & Target, const float X, const float Y );
			static void PrependScale ( Matrix3x3 & Target, const Matrix3x3 & Source, const Vec2 & Scale );
			static void PrependScale ( Matrix3x3 & Target, const Matrix3x3 & Source, const float X, const float Y );
			
			static void Append ( Matrix3x3 & Target, const Matrix3x3 & Pendant );
			static void Append ( Matrix3x3 & Target, const Matrix3x3 & Source, const Matrix3x3 & Pendant );
			static void Prepend ( Matrix3x3 & Target, const Matrix3x3 & Pendant );
			static void Prepend ( Matrix3x3 & Target, const Matrix3x3 & Source, const Matrix3x3 & Pendant );
			
		private:
			
			float Elements [ 3 ][ 3 ];
			
			static float DummyFloatRef;
			
		};
		
	}
	
}

#endif
