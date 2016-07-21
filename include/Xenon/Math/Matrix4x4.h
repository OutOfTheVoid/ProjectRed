#ifndef XENON_MATRIX4X4_H
#define XENON_MATRIX4X4_H

#include <Xenon/Xenon.h>
#include <Xenon/Math/Math.h>
#include <Xenon/Math/Vec4.h>
#include <Xenon/SSE.h>

#include <stddef.h>

namespace Xenon
{

	namespace Math
	{
		
		class Vec3;
		class Quaternion;
		
		class Matrix4x4
		{
		public:
			
			enum NoInit
			{
				
				NO_INIT
				
			};
			
			Matrix4x4 ();
			Matrix4x4 ( const float A, const float B, const float C, const float D, const float E, const float F, const float G, const float H, const float I, const float J, const float K, const float L, const float M, const float N, const float O, const float P );
			explicit Matrix4x4 ( const Vec4 & Row1, const Vec4 & Row2, const Vec4 & Row3, const Vec4 & Row4 );
			Matrix4x4 ( NoInit NO_INIT );
			Matrix4x4 ( const Matrix4x4 & CopyFrom );
			~Matrix4x4 ();
			
			static void Copy ( Matrix4x4 & Target, const Matrix4x4 & Source );
			
			static void Identity ( Matrix4x4 & Target );
			
			static void MultiplyScalar ( Matrix4x4 & Target, const float Scalar );
			static void MultiplyScalar ( Matrix4x4 & Target, const Matrix4x4 & Source, const float Scalar );
			
			// Projections
			static void SetAsPerspectiveProjection ( Matrix4x4 & Target, const float Near, const float Far, const float Left, const float Right, const float Top, const float Bottom );
			static void SetAsPerspectiveProjectionFieldOfView ( Matrix4x4 & Target, const float Near, const float Far, const float FieldOfView, const float AspectRatio );
			static void SetAsSymmetricPerspectiveProjection ( Matrix4x4 & Target, const float Near, const float Far, const float Width, const float Height );
			static void SetAsPerspectiveProjectionAngle ( Matrix4x4 & Target, const float Near, const float Far, const float LeftAngle, const float RightAngle, const float TopAngle, const float BottomAngle );
			static void SetAsSymmetricPerspectiveProjectionAngle ( Matrix4x4 & Target, const float Near, const float Far, const float AngleX, const float AngleY );
			
			// Translate
			static void SetAsTranslation ( Matrix4x4 & Target, const float X, const float Y, const float Z );
			static void SetAsTranslation ( Matrix4x4 & Target, const Vec3 & Translation );
			static void AppendTranslation ( Matrix4x4 & Target, const float X, const float Y, const float Z );
			static void AppendTranslation ( Matrix4x4 & Target, const Vec3 & Translation );
			static void AppendTranslation ( Matrix4x4 & Target, const Matrix4x4 & Source, const float X, const float Y, const float Z );
			static void AppendTranslation ( Matrix4x4 & Target, const Matrix4x4 & Source, const Vec3 & Translation );
			static void PrependTranslation ( Matrix4x4 & Target, const float X, const float Y, const float Z );
			static void PrependTranslation ( Matrix4x4 & Target, const Vec3 & Translation );
			static void PrependTranslation ( Matrix4x4 & Target, const Matrix4x4 & Source, const float X, const float Y, const float Z );
			static void PrependTranslation ( Matrix4x4 & Target, const Matrix4x4 & Source, const Vec3 & Translation );
			
			// Scale
			static void SetAsScale ( Matrix4x4 & Target, const float X, const float Y, const float Z );
			static void SetAsScale ( Matrix4x4 & Target, const Vec3 & Scale );
			static void AppendScale ( Matrix4x4 & Target, const float X, const float Y, const float Z );
			static void AppendScale ( Matrix4x4 & Target, const Vec3 & Scale );
			static void AppendScale ( Matrix4x4 & Target, const Matrix4x4 & Source, const float X, const float Y, const float Z );
			static void AppendScale ( Matrix4x4 & Target, const Matrix4x4 & Source, const Vec3 & Scale );
			static void PrependScale ( Matrix4x4 & Target, const float X, const float Y, const float Z );
			static void PrependScale ( Matrix4x4 & Target, const Vec3 & Scale );
			static void PrependScale ( Matrix4x4 & Target, const Matrix4x4 & Source, const float X, const float Y, const float Z );
			static void PrependScale ( Matrix4x4 & Target, const Matrix4x4 & Source, const Vec3 & Scale );
			
			// Rotation - Quaternion
			static void SetAsQuaternionRotation ( Matrix4x4 & Target, const Quaternion & Rotation );
			static void SetAsQuaternionRotation ( Matrix4x4 & Target, const float X, const float Y, const float Z, const float W );
			static void AppendQuaternionRotation ( Matrix4x4 & Target, const Quaternion & Rotation );
			static void AppendQuaternionRotation ( Matrix4x4 & Target, const float X, const float Y, const float Z, const float W );
			
			static float Determinant ( const Matrix4x4 & Target );
			
			static void Transpose ( Matrix4x4 & Target );
			static void Transpose ( Matrix4x4 & Target, const Matrix4x4 & Source );
			
			static void Invert ( Matrix4x4 & Target );
			static void Invert ( Matrix4x4 & Target, const Matrix4x4 & Source );
			
			static bool Invertible ( const Matrix4x4 & Source, float PrecisionThreshold = 1.18e-38 ); // the default value is the minimum positive normal of an IEEE 754 32-bit float.
			
			// multiply matrix
			static void Append ( Matrix4x4 & Target, const Matrix4x4 & Pendant );
			static void Append ( Matrix4x4 & Target, const Matrix4x4 & Source, const Matrix4x4 & Pendant );
			static void Prepend ( Matrix4x4 & Target, const Matrix4x4 & Pendant );
			static void Prepend ( Matrix4x4 & Target, const Matrix4x4 & Source, const Matrix4x4 & Pendant );
			
			typedef struct
			{
				
				float E0;
				float E1;
				float E2;
				float E3;
				
			} Row_t;
			
			alignas ( 16 ) Row_t Elements [ 4 ];
			
		};
		
	}

}

#endif
