#include <Xenon/Math/Matrix4x4.h>
#include <Xenon/Math/Vec3.h>
#include <Xenon/Math/Quaternion.h>

#include <string.h>
#include <stdlib.h>
#include <math.h>

#include <utility>

Xenon::Math::Matrix4x4 :: Matrix4x4 ():
#ifdef XENON_SSE

	Elements { _mm_setr_ps ( 1.0f, 0.0f, 0.0f, 0.0f ), _mm_setr_ps ( 0.0f, 1.0f, 0.0f, 0.0f ), _mm_setr_ps ( 0.0f, 0.0f, 1.0f, 0.0f ), _mm_setr_ps ( 0.0f, 0.0f, 0.0f, 1.0f ) }

#else
	
	Elements { { 1.0f, 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f, 0.0f, 1.0f } }

#endif
{
};

Xenon::Math::Matrix4x4 :: Matrix4x4 ( const float A, const float B, const float C, const float D, const float E, const float F, const float G, const float H, const float I, const float J, const float K, const float L, const float M, const float N, const float O, const float P ):
#ifdef XENON_SSE
	
	Elements { _mm_setr_ps ( A, B, C, D ), _mm_setr_ps ( E, F, G, H ), _mm_setr_ps ( I, J, K, L ), _mm_setr_ps ( M, N, O, P ) }
	
#else
	
	Elements { { A, B, C, D }, { E, F, G, H }, { I, J, K, L }, { M, N, O, P } }
	
#endif
{
};

Xenon::Math::Matrix4x4 :: Matrix4x4 ( const Vec4 & Row1, const Vec4 & Row2, const Vec4 & Row3, const Vec4 & Row4 ):
#ifdef XENON_SSE

	Elements { _mm_setr_ps ( Row1.X, Row1.Y, Row1.Z, Row1.W ), _mm_setr_ps ( Row2.X, Row2.Y, Row2.Z, Row2.W ), _mm_setr_ps ( Row3.X, Row3.Y, Row3.Z, Row3.W ), _mm_setr_ps ( Row4.X, Row4.Y, Row4.Z, Row4.W ) }

#else
	
	Elements { { Row1.X, Row1.Y, Row1.Z, Row1.W }, { Row2.X, Row2.Y, Row2.Z, Row2.W }, { Row3.X, Row3.Y, Row3.Z, Row3.W }, { Row4.X, Row4.Y, Row4.Z, Row4.W } }

#endif
{
};

Xenon::Math::Matrix4x4 :: Matrix4x4 ( NoInit NO_INIT )
{	
};

Xenon::Math::Matrix4x4 :: Matrix4x4 ( const Matrix4x4 & CopyFrom ):
	Elements ( CopyFrom.Elements )
{	
};

Xenon::Math::Matrix4x4 :: ~Matrix4x4 ()
{
};

void Xenon::Math::Matrix4x4 :: Identity ( Matrix4x4 & Source )
{
	
#ifdef XENON_SSE
	
	Source.Elements [ 0 ].SSEV = _mm_setr_ps ( 1.0f, 0.0f, 0.0f, 0.0f );
	Source.Elements [ 1 ].SSEV = _mm_setr_ps ( 0.0f, 1.0f, 0.0f, 0.0f );
	Source.Elements [ 2 ].SSEV = _mm_setr_ps ( 0.0f, 0.0f, 1.0f, 0.0f );
	Source.Elements [ 3 ].SSEV = _mm_setr_ps ( 0.0f, 0.0f, 0.0f, 1.0f );
	
#else
	
	Source.Elements [ 0 ].E0 = Source.Elements [ 1 ].E1 = Source.Elements [ 2 ].E2 = Source.Elements [ 3 ].E3 = 1.0f;
	Source.Elements [ 0 ].E1 = Source.Elements [ 0 ].E2 = Source.Elements [ 0 ].E3 = Source.Elements [ 1 ].E0 = Source.Elements [ 1 ].E2 = Source.Elements [ 1 ].E3 = Source.Elements [ 2 ].E0 = Source.Elements [ 2 ].E1 = Source.Elements [ 2 ].E3 = Source.Elements [ 3 ].E0 = Source.Elements [ 3 ].E1 = Source.Elements [ 3 ].E2 = 0.0f;
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: MultiplyScalar ( Matrix4x4 & Target, float Scalar )
{
	
#ifdef XENON_SSE
	
	const __m128 Multiplier = _mm_set1_ps ( Scalar );
	
	Target.Elements [ 0 ].SSEV = _mm_mul_ps ( Target.Elements [ 0 ].SSEV, Multiplier );
	Target.Elements [ 1 ].SSEV = _mm_mul_ps ( Target.Elements [ 1 ].SSEV, Multiplier );
	Target.Elements [ 2 ].SSEV = _mm_mul_ps ( Target.Elements [ 2 ].SSEV, Multiplier );
	Target.Elements [ 3 ].SSEV = _mm_mul_ps ( Target.Elements [ 3 ].SSEV, Multiplier );
	
#else
	
	Target.Elements [ 0 ].E0 * Scalar;
	Target.Elements [ 0 ].E1 * Scalar;
	Target.Elements [ 0 ].E2 * Scalar;
	Target.Elements [ 0 ].E3 * Scalar;
	
	Target.Elements [ 1 ].E0 * Scalar;
	Target.Elements [ 1 ].E1 * Scalar;
	Target.Elements [ 1 ].E2 * Scalar;
	Target.Elements [ 1 ].E3 * Scalar;
	
	Target.Elements [ 2 ].E0 * Scalar;
	Target.Elements [ 2 ].E1 * Scalar;
	Target.Elements [ 2 ].E2 * Scalar;
	Target.Elements [ 2 ].E3 * Scalar;
	
	Target.Elements [ 3 ].E0 * Scalar;
	Target.Elements [ 3 ].E1 * Scalar;
	Target.Elements [ 3 ].E2 * Scalar;
	Target.Elements [ 3 ].E3 * Scalar;
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: MultiplyScalar ( Matrix4x4 & Target, const Matrix4x4 & Source, float Scalar )
{
	
	#ifdef XENON_SSE
	
	const __m128 Multiplier = _mm_set1_ps ( Scalar );
	
	Target.Elements [ 0 ].SSEV = _mm_mul_ps ( Source.Elements [ 0 ].SSEV, Multiplier );
	Target.Elements [ 1 ].SSEV = _mm_mul_ps ( Source.Elements [ 1 ].SSEV, Multiplier );
	Target.Elements [ 2 ].SSEV = _mm_mul_ps ( Source.Elements [ 2 ].SSEV, Multiplier );
	Target.Elements [ 3 ].SSEV = _mm_mul_ps ( Source.Elements [ 3 ].SSEV, Multiplier );
	
#else
	
	Target.Elements [ 0 ].E0 = Source.Elements [ 0 ].E0 * Scalar;
	Target.Elements [ 0 ].E1 = Source.Elements [ 0 ].E1 * Scalar;
	Target.Elements [ 0 ].E2 = Source.Elements [ 0 ].E2 * Scalar;
	Target.Elements [ 0 ].E3 = Source.Elements [ 0 ].E3 * Scalar;
	
	Target.Elements [ 1 ].E0 = Source.Elements [ 1 ].E0 * Scalar;
	Target.Elements [ 1 ].E1 = Source.Elements [ 1 ].E1 * Scalar;
	Target.Elements [ 1 ].E2 = Source.Elements [ 1 ].E2 * Scalar;
	Target.Elements [ 1 ].E3 = Source.Elements [ 1 ].E3 * Scalar;
	
	Target.Elements [ 2 ].E0 = Source.Elements [ 2 ].E0 * Scalar;
	Target.Elements [ 2 ].E1 = Source.Elements [ 2 ].E1 * Scalar;
	Target.Elements [ 2 ].E2 = Source.Elements [ 2 ].E2 * Scalar;
	Target.Elements [ 2 ].E3 = Source.Elements [ 2 ].E3 * Scalar;

	Target.Elements [ 3 ].E0 = Source.Elements [ 3 ].E0 * Scalar;
	Target.Elements [ 3 ].E1 = Source.Elements [ 3 ].E1 * Scalar;
	Target.Elements [ 3 ].E2 = Source.Elements [ 3 ].E2 * Scalar;
	Target.Elements [ 3 ].E3 = Source.Elements [ 3 ].E3 * Scalar;
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: SetAsPerspectiveProjection ( Matrix4x4 & Target, float Near, float Far, float Left, float Right, float Top, float Bottom )
{
	
	float DiffX = Right - Left;
	float ProjX = Right + Left;
	
	float DiffY = Top - Bottom;
	float ProjY = Top + Bottom;
	
	float DiffZ = Far - Near;
	float ProjZ = Far + Near;
	float ScalZ = Far * Near;
	
#ifdef XENON_SSE
	
	Target.Elements [ 0 ].SSEV = _mm_setr_ps ( 2.0f * Near / DiffX, 0.0f, ProjX / DiffX, 0.0f );
	Target.Elements [ 1 ].SSEV = _mm_setr_ps ( 0.0f, 2.0f * Near / DiffY, ProjY / DiffY, 0.0f );
	Target.Elements [ 2 ].SSEV = _mm_setr_ps ( 0.0f, 0.0f, - ProjZ / DiffZ, - 2.0f * ScalZ / DiffZ );
	Target.Elements [ 3 ].SSEV = _mm_setr_ps ( 0.0f, 0.0f, - 1.0f, 0.0f );
	
#else
	
	Target.Elements [ 0 ].E0 = 2.0f * Near / DiffX;
	Target.Elements [ 0 ].E1 = 0.0f;
	Target.Elements [ 0 ].E2 = ProjX / DiffX;
	Target.Elements [ 0 ].E3 = 0.0f;
	
	Target.Elements [ 1 ].E0 = 0.0f;
	Target.Elements [ 1 ].E1 = 2.0f * Near / DiffY;
	Target.Elements [ 1 ].E2 = ProjY / DiffY;
	Target.Elements [ 1 ].E3 = 0.0f;
	
	Target.Elements [ 2 ].E0 = 0.0f;
	Target.Elements [ 2 ].E1 = 0.0f;
	Target.Elements [ 2 ].E2 = - ProjZ / DiffZ;
	Target.Elements [ 2 ].E3 = - 2.0f * ScalZ / DiffZ;
	
	Target.Elements [ 3 ].E0 = Target.Elements [ 3 ].E1 = 0.0f;
	Target.Elements [ 3 ].E2 = - 1.0f;
	Target.Elements [ 3 ].E3 = 0.0f;
	
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: SetAsPerspectiveProjectionFieldOfView ( Matrix4x4 & Target, const float Near, const float Far, const float FieldOfView, const float AspectRatio )
{
	
	float F = 1.0f / tan ( FieldOfView / 2.0f );
	float InvRange = 1.0f / ( Near - Far );
	
	#ifdef XENON_SSE
	
	Target.Elements [ 0 ].SSEV = _mm_setr_ps ( F / AspectRatio, 0.0f, 0.0f, 0.0f );
	Target.Elements [ 1 ].SSEV = _mm_setr_ps ( 0.0f, F, 0.0f, 0.0f );
	Target.Elements [ 2 ].SSEV = _mm_setr_ps ( 0.0f, 0.0f, ( Near + Far ) * InvRange, Near * Far * InvRange * 2.0f );
	Target.Elements [ 3 ].SSEV = _mm_setr_ps ( 0.0f, 0.0f, - 1.0f, 0.0f );
	
#else
	
	Target.Elements [ 0 ].E0 = F / AspectRatio;
	Target.Elements [ 0 ].E1 = Target.Elements [ 0 ].E2 = Target.Elements [ 0 ].E3 = 0.0f;
	
	Target.Elements [ 1 ].E0 = 0.0f;
	Target.Elements [ 1 ].E1 = F;
	Target.Elements [ 1 ].E2 = Target.Elements [ 1 ].E3 = 0.0f;
	
	Target.Elements [ 2 ].E0 = Target.Elements [ 2 ].E1 = 0.0f;
	Target.Elements [ 2 ].E2 = ( Near + Far ) * InvRange;
	Target.Elements [ 2 ].E3 = Near * Far * InvRange * 2.0f;
	
	Target.Elements [ 3 ].E0 = Target.Elements [ 3 ].E1 = 0.0f;
	Target.Elements [ 3 ].E2 = - 1.0f;
	Target.Elements [ 3 ].E3 = 0.0f;
	
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: SetAsSymmetricPerspectiveProjection ( Matrix4x4 & Target, const float Near, const float Far, const float Width, const float Height )
{
	
	SetAsPerspectiveProjection ( Target, Near, Far, - Width * 0.5f, Width * 0.5f, - Height * 0.5f, Height * 0.5f );
	
};

void Xenon::Math::Matrix4x4 :: SetAsPerspectiveProjectionAngle ( Matrix4x4 & Target, const float Near, const float Far, const float LeftAngle, const float RightAngle, const float TopAngle, const float BottomAngle )
{
	
	SetAsPerspectiveProjection ( Target, Near, Far, tan ( LeftAngle ) * Near, tan ( RightAngle ) * Near, - tan ( TopAngle ) * Near, - tan ( BottomAngle ) * Near );
	
};

void Xenon::Math::Matrix4x4 :: SetAsSymmetricPerspectiveProjectionAngle ( Matrix4x4 & Target, const float Near, const float Far, const float AngleX, const float AngleY )
{
	
	SetAsPerspectiveProjection ( Target, Near, Far, - AngleX * 0.5f, AngleX * 0.5f, AngleY * 0.5f, - AngleY * 0.5f );
	
};

void Xenon::Math::Matrix4x4 :: SetAsTranslation ( Matrix4x4 & Target, const float X, const float Y, const float Z )
{
	
#ifdef XENON_SSE
	
	Target.Elements [ 0 ].SSEV = _mm_setr_ps ( 1.0f, 0.0f, 0.0f, X );
	Target.Elements [ 1 ].SSEV = _mm_setr_ps ( 0.0f, 1.0f, 0.0f, Y );
	Target.Elements [ 2 ].SSEV = _mm_setr_ps ( 0.0f, 0.0f, 1.0f, Z );
	Target.Elements [ 3 ].SSEV = _mm_setr_ps ( 0.0f, 0.0f, 0.0f, 1.0f );
	
#else
	
	Target.Elements [ 0 ].E0 = Target.Elements [ 1 ].E1 = Target.Elements [ 2 ].E2 = Target.Elements [ 3 ].E3 = 1.0f;
	
	Target.Elements [ 0 ].E3 = X;
	Target.Elements [ 1 ].E3 = Y;
	Target.Elements [ 2 ].E3 = Z;
	
	Target.Elements [ 0 ].E1 = Target.Elements [ 0 ].E2 = Target.Elements [ 1 ].E0 = Target.Elements [ 1 ].E2 = Target.Elements [ 2 ].E0 = Target.Elements [ 2 ].E1 = Target.Elements [ 3 ].E0 = Target.Elements [ 3 ].E1 = Target.Elements [ 3 ].E2 = 0.0f;
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: SetAsTranslation ( Matrix4x4 & Source, const Vec3 & Translation )
{
	
#ifdef XENON_SSE
	
	Source.Elements [ 0 ].SSEV = _mm_setr_ps ( 1.0f, 0.0f, 0.0f, Translation.X );
	Source.Elements [ 1 ].SSEV = _mm_setr_ps ( 0.0f, 1.0f, 0.0f, Translation.Y );
	Source.Elements [ 2 ].SSEV = _mm_setr_ps ( 0.0f, 0.0f, 1.0f, Translation.Z );
	Source.Elements [ 3 ].SSEV = _mm_setr_ps ( 0.0f, 0.0f, 0.0f, 1.0f );
	
#else
	
	Source.Elements [ 0 ].E0 = Source.Elements [ 1 ].E1 = Source.Elements [ 2 ].E2 = Source.Elements [ 3 ].E3 = 1.0f;
	
	Source.Elements [ 0 ].E3 = Translation.X;
	Source.Elements [ 1 ].E3 = Translation.Y;
	Source.Elements [ 2 ].E3 = Translation.Z;
	
	Source.Elements [ 0 ].E1 = Source.Elements [ 0 ].E2 = Source.Elements [ 1 ].E0 = Source.Elements [ 1 ].E2 = Source.Elements [ 2 ].E0 = Source.Elements [ 2 ].E1 = Source.Elements [ 3 ].E0 = Source.Elements [ 3 ].E1 = Source.Elements [ 3 ].E2 = 0.0f;
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: AppendTranslation ( Matrix4x4 & Target, const float X, const float Y, const float Z )
{
	
#ifdef XENON_SSE
	
	Target.Elements [ 0 ].SSEV = _mm_add_ps ( Target.Elements [ 0 ].SSEV, _mm_mul_ps ( Target.Elements [ 3 ].SSEV, _mm_set1_ps ( X ) ) );
	Target.Elements [ 1 ].SSEV = _mm_add_ps ( Target.Elements [ 1 ].SSEV, _mm_mul_ps ( Target.Elements [ 3 ].SSEV, _mm_set1_ps ( Y ) ) );
	Target.Elements [ 2 ].SSEV = _mm_add_ps ( Target.Elements [ 2 ].SSEV, _mm_mul_ps ( Target.Elements [ 3 ].SSEV, _mm_set1_ps ( Z ) ) );
	
#else
	
	Target.Elements [ 0 ].E0 += Target.Elements [ 3 ].E0 * X;
	Target.Elements [ 0 ].E1 += Target.Elements [ 3 ].E1 * X;
	Target.Elements [ 0 ].E2 += Target.Elements [ 3 ].E2 * X;
	Target.Elements [ 0 ].E3 += Target.Elements [ 3 ].E3 * X;
	
	Target.Elements [ 1 ].E0 += Target.Elements [ 3 ].E0 * Y;
	Target.Elements [ 1 ].E1 += Target.Elements [ 3 ].E1 * Y;
	Target.Elements [ 1 ].E2 += Target.Elements [ 3 ].E2 * Y;
	Target.Elements [ 1 ].E3 += Target.Elements [ 3 ].E3 * Y;
	
	Target.Elements [ 2 ].E0 += Target.Elements [ 3 ].E0 * Z;
	Target.Elements [ 2 ].E1 += Target.Elements [ 3 ].E1 * Z;
	Target.Elements [ 2 ].E2 += Target.Elements [ 3 ].E2 * Z;
	Target.Elements [ 2 ].E3 += Target.Elements [ 3 ].E3 * Z;
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: AppendTranslation ( Matrix4x4 & Target, const Vec3 & Translation )
{
	
#ifdef XENON_SSE
	
	Target.Elements [ 0 ].SSEV = _mm_add_ps ( Target.Elements [ 0 ].SSEV, _mm_mul_ps ( Target.Elements [ 3 ].SSEV, _mm_set1_ps ( Translation.X ) ) );
	Target.Elements [ 1 ].SSEV = _mm_add_ps ( Target.Elements [ 1 ].SSEV, _mm_mul_ps ( Target.Elements [ 3 ].SSEV, _mm_set1_ps ( Translation.Y ) ) );
	Target.Elements [ 2 ].SSEV = _mm_add_ps ( Target.Elements [ 2 ].SSEV, _mm_mul_ps ( Target.Elements [ 3 ].SSEV, _mm_set1_ps ( Translation.Z ) ) );
	
#else
	
	Target.Elements [ 0 ].E0 += Target.Elements [ 3 ].E0 * Translation.X;
	Target.Elements [ 0 ].E1 += Target.Elements [ 3 ].E1 * Translation.X;
	Target.Elements [ 0 ].E2 += Target.Elements [ 3 ].E2 * Translation.X;
	Target.Elements [ 0 ].E3 += Target.Elements [ 3 ].E3 * Translation.X;
	
	Target.Elements [ 1 ].E0 += Target.Elements [ 3 ].E0 * Translation.Y;
	Target.Elements [ 1 ].E1 += Target.Elements [ 3 ].E1 * Translation.Y;
	Target.Elements [ 1 ].E2 += Target.Elements [ 3 ].E2 * Translation.Y;
	Target.Elements [ 1 ].E3 += Target.Elements [ 3 ].E3 * Translation.Y;
	
	Target.Elements [ 2 ].E0 += Target.Elements [ 3 ].E0 * Translation.Z;
	Target.Elements [ 2 ].E1 += Target.Elements [ 3 ].E1 * Translation.Z;
	Target.Elements [ 2 ].E2 += Target.Elements [ 3 ].E2 * Translation.Z;
	Target.Elements [ 2 ].E3 += Target.Elements [ 3 ].E3 * Translation.Z;
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: AppendTranslation ( Matrix4x4 & Target, const Matrix4x4 & Source, const float X, const float Y, const float Z )
{
	
#ifdef XENON_SSE
	
	Target.Elements [ 0 ].SSEV = _mm_add_ps ( Source.Elements [ 0 ].SSEV, _mm_mul_ps ( Source.Elements [ 3 ].SSEV, _mm_set1_ps ( X ) ) );
	Target.Elements [ 1 ].SSEV = _mm_add_ps ( Source.Elements [ 1 ].SSEV, _mm_mul_ps ( Source.Elements [ 3 ].SSEV, _mm_set1_ps ( Y ) ) );
	Target.Elements [ 2 ].SSEV = _mm_add_ps ( Source.Elements [ 2 ].SSEV, _mm_mul_ps ( Source.Elements [ 3 ].SSEV, _mm_set1_ps ( Z ) ) );
	Target.Elements [ 3 ].SSEV = Source.Elements [ 3 ].SSEV;
	
#else
	
	Target.Elements [ 0 ].E0 = Source.Elements [ 0 ].E0 + Source.Elements [ 3 ].E0 * X;
	Target.Elements [ 0 ].E1 = Source.Elements [ 0 ].E1 + Source.Elements [ 3 ].E1 * X;
	Target.Elements [ 0 ].E2 = Source.Elements [ 0 ].E2 + Source.Elements [ 3 ].E2 * X;
	Target.Elements [ 0 ].E3 = Source.Elements [ 0 ].E3 + Source.Elements [ 3 ].E3 * X;
	
	Target.Elements [ 1 ].E0 = Source.Elements [ 1 ].E0 + Source.Elements [ 3 ].E0 * Y;
	Target.Elements [ 1 ].E1 = Source.Elements [ 1 ].E1 + Source.Elements [ 3 ].E1 * Y;
	Target.Elements [ 1 ].E2 = Source.Elements [ 1 ].E2 + Source.Elements [ 3 ].E2 * Y;
	Target.Elements [ 1 ].E3 = Source.Elements [ 1 ].E3 + Source.Elements [ 3 ].E3 * Y;
	
	Target.Elements [ 2 ].E0 = Source.Elements [ 2 ].E0 + Source.Elements [ 3 ].E0 * Z;
	Target.Elements [ 2 ].E1 = Source.Elements [ 2 ].E1 + Source.Elements [ 3 ].E1 * Z;
	Target.Elements [ 2 ].E2 = Source.Elements [ 2 ].E2 + Source.Elements [ 3 ].E2 * Z;
	Target.Elements [ 2 ].E3 = Source.Elements [ 2 ].E3 + Source.Elements [ 3 ].E3 * Z;
	
	Target.Elements [ 3 ] = Source.Elements [ 3 ];
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: AppendTranslation ( Matrix4x4 & Target, const Matrix4x4 & Source, const Vec3 & Translation )
{
	
		
#ifdef XENON_SSE
	
	Target.Elements [ 0 ].SSEV = _mm_add_ps ( Source.Elements [ 0 ].SSEV, _mm_mul_ps ( Source.Elements [ 3 ].SSEV, _mm_set1_ps ( Translation.X ) ) );
	Target.Elements [ 1 ].SSEV = _mm_add_ps ( Source.Elements [ 1 ].SSEV, _mm_mul_ps ( Source.Elements [ 3 ].SSEV, _mm_set1_ps ( Translation.Y ) ) );
	Target.Elements [ 2 ].SSEV = _mm_add_ps ( Source.Elements [ 2 ].SSEV, _mm_mul_ps ( Source.Elements [ 3 ].SSEV, _mm_set1_ps ( Translation.Z ) ) );
	Target.Elements [ 3 ].SSEV = Source.Elements [ 3 ].SSEV;
	
#else
	
	Target.Elements [ 0 ].E0 = Source.Elements [ 0 ].E0 + Source.Elements [ 3 ].E0 * Translation.X;
	Target.Elements [ 0 ].E1 = Source.Elements [ 0 ].E1 + Source.Elements [ 3 ].E1 * Translation.X;
	Target.Elements [ 0 ].E2 = Source.Elements [ 0 ].E2 + Source.Elements [ 3 ].E2 * Translation.X;
	Target.Elements [ 0 ].E3 = Source.Elements [ 0 ].E3 + Source.Elements [ 3 ].E3 * Translation.X;
	
	Target.Elements [ 1 ].E0 = Source.Elements [ 1 ].E0 + Source.Elements [ 3 ].E0 * Translation.Y;
	Target.Elements [ 1 ].E1 = Source.Elements [ 1 ].E1 + Source.Elements [ 3 ].E1 * Translation.Y;
	Target.Elements [ 1 ].E2 = Source.Elements [ 1 ].E2 + Source.Elements [ 3 ].E2 * Translation.Y;
	Target.Elements [ 1 ].E3 = Source.Elements [ 1 ].E3 + Source.Elements [ 3 ].E3 * Translation.Y;
	
	Target.Elements [ 2 ].E0 = Source.Elements [ 2 ].E0 + Source.Elements [ 3 ].E0 * Translation.Z;
	Target.Elements [ 2 ].E1 = Source.Elements [ 2 ].E1 + Source.Elements [ 3 ].E1 * Translation.Z;
	Target.Elements [ 2 ].E2 = Source.Elements [ 2 ].E2 + Source.Elements [ 3 ].E2 * Translation.Z;
	Target.Elements [ 2 ].E3 = Source.Elements [ 2 ].E3 + Source.Elements [ 3 ].E3 * Translation.Z;
	
	Target.Elements [ 3 ] = Source.Elements [ 3 ];
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: PrependTranslation ( Matrix4x4 & Target, const float X, const float Y, const float Z )
{
	
#ifdef XENON_SSE3
	
	__m128 TranslationVect = _mm_setr_ps ( X, Y, Z, 0.0f );
	
	Row_t Temp;
	Temp.SSEV = _mm_hadd_ps ( _mm_hadd_ps ( _mm_mul_ps ( TranslationVect, Target.Elements [ 0 ].SSEV ), _mm_mul_ps ( TranslationVect, Target.Elements [ 1 ].SSEV ) ), _mm_hadd_ps ( _mm_mul_ps ( TranslationVect, Target.Elements [ 2 ].SSEV ), _mm_mul_ps ( TranslationVect, Target.Elements [ 3 ].SSEV ) ) );
	
	Target.Elements [ 0 ].E3 += Temp.E3;
	Target.Elements [ 1 ].E3 += Temp.E2;
	Target.Elements [ 2 ].E3 += Temp.E1;
	Target.Elements [ 3 ].E3 += Temp.E0;
	
#else
	
	Target.Elements [ 0 ].E3 += X * Target.Elements [ 0 ].E0 + Y * Target.Elements [ 0 ].E1 + Z * Target.Elements [ 0 ].E2;
	Target.Elements [ 1 ].E3 += X * Target.Elements [ 1 ].E0 + Y * Target.Elements [ 1 ].E1 + Z * Target.Elements [ 1 ].E2;
	Target.Elements [ 2 ].E3 += X * Target.Elements [ 2 ].E0 + Y * Target.Elements [ 2 ].E1 + Z * Target.Elements [ 2 ].E2;
	Target.Elements [ 3 ].E3 += X * Target.Elements [ 3 ].E0 + Y * Target.Elements [ 3 ].E1 + Z * Target.Elements [ 3 ].E2;
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: PrependTranslation ( Matrix4x4 & Target, const Vec3 & Translation )
{
	
#ifdef XENON_SSE3
	
	__m128 TranslationVect = _mm_setr_ps ( Translation.X, Translation.Y, Translation.Z, 0.0f );
	
	Row_t Temp;
	Temp.SSEV = _mm_hadd_ps ( _mm_hadd_ps ( _mm_mul_ps ( TranslationVect,Target.Elements [ 0 ].SSEV ), _mm_mul_ps ( TranslationVect,Target.Elements [ 1 ].SSEV ) ), _mm_hadd_ps ( _mm_mul_ps ( TranslationVect,Target.Elements [ 2 ].SSEV ), _mm_mul_ps ( TranslationVect,Target.Elements [ 3 ].SSEV ) ) );
	
	Target.Elements [ 0 ].E3 += Temp.E3;
	Target.Elements [ 1 ].E3 += Temp.E2;
	Target.Elements [ 2 ].E3 += Temp.E1;
	Target.Elements [ 3 ].E3 += Temp.E0;
	
#else
	
	Target.Elements [ 0 ].E3 += Translation.X * Target.Elements [ 0 ].E0 + Translation.Y * Target.Elements [ 0 ].E1 + Translation.Z * Target.Elements [ 0 ].E2;
	Target.Elements [ 1 ].E3 += Translation.X * Target.Elements [ 1 ].E0 + Translation.Y * Target.Elements [ 1 ].E1 + Translation.Z * Target.Elements [ 1 ].E2;
	Target.Elements [ 2 ].E3 += Translation.X * Target.Elements [ 2 ].E0 + Translation.Y * Target.Elements [ 2 ].E1 + Translation.Z * Target.Elements [ 2 ].E2;
	Target.Elements [ 3 ].E3 += Translation.X * Target.Elements [ 3 ].E0 + Translation.Y * Target.Elements [ 3 ].E1 + Translation.Z * Target.Elements [ 3 ].E2;
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: PrependTranslation ( Matrix4x4 & Target, const Matrix4x4 & Source, float X, float Y, float Z )
{
	
	Copy ( Target, Source );
	
#ifdef XENON_SSE3
	
	__m128 TranslationVect = _mm_setr_ps ( X, Y, Z, 0.0f );
	
	Row_t Temp;
	Temp.SSEV = _mm_hadd_ps ( _mm_hadd_ps ( _mm_mul_ps ( TranslationVect, Source.Elements [ 0 ].SSEV ), _mm_mul_ps ( TranslationVect, Source.Elements [ 1 ].SSEV ) ), _mm_hadd_ps ( _mm_mul_ps ( TranslationVect, Source.Elements [ 2 ].SSEV ), _mm_mul_ps ( TranslationVect, Source.Elements [ 3 ].SSEV ) ) );
	
	Target.Elements [ 0 ].E3 = Source.Elements [ 0 ].E3 + Temp.E3;
	Target.Elements [ 1 ].E3 = Source.Elements [ 1 ].E3 + Temp.E2;
	Target.Elements [ 2 ].E3 = Source.Elements [ 2 ].E3 + Temp.E1;
	Target.Elements [ 3 ].E3 = Source.Elements [ 3 ].E3 + Temp.E0;
	
#else
	
	Target.Elements [ 0 ].E3 = Source.Elements [ 0 ].E3 + X * Source.Elements [ 0 ].E0 + Y * Source.Elements [ 0 ].E1 + Z * Source.Elements [ 0 ].E2;
	Target.Elements [ 1 ].E3 = Source.Elements [ 1 ].E3 + X * Source.Elements [ 1 ].E0 + Y * Source.Elements [ 1 ].E1 + Z * Source.Elements [ 1 ].E2;
	Target.Elements [ 2 ].E3 = Source.Elements [ 2 ].E3 + X * Source.Elements [ 2 ].E0 + Y * Source.Elements [ 2 ].E1 + Z * Source.Elements [ 2 ].E2;
	Target.Elements [ 3 ].E3 = Source.Elements [ 3 ].E3 + X * Source.Elements [ 3 ].E0 + Y * Source.Elements [ 3 ].E1 + Z * Source.Elements [ 3 ].E2;
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: PrependTranslation ( Matrix4x4 & Target, const Matrix4x4 & Source, const Vec3 & Translation )
{
	
	Copy ( Target, Source );
	
#ifdef XENON_SSE3
	
	__m128 TranslationVect = _mm_setr_ps ( Translation.X, Translation.Y, Translation.Z, 0.0f );
	
	Row_t Temp;
	Temp.SSEV = _mm_hadd_ps ( _mm_hadd_ps ( _mm_mul_ps ( TranslationVect, Source.Elements [ 0 ].SSEV ), _mm_mul_ps ( TranslationVect, Source.Elements [ 1 ].SSEV ) ), _mm_hadd_ps ( _mm_mul_ps ( TranslationVect, Source.Elements [ 2 ].SSEV ), _mm_mul_ps ( TranslationVect, Source.Elements [ 3 ].SSEV ) ) );
	
	Target.Elements [ 0 ].E3 = Source.Elements [ 0 ].E3 + Temp.E3;
	Target.Elements [ 1 ].E3 = Source.Elements [ 1 ].E3 + Temp.E2;
	Target.Elements [ 2 ].E3 = Source.Elements [ 2 ].E3 + Temp.E1;
	Target.Elements [ 3 ].E3 = Source.Elements [ 3 ].E3 + Temp.E0;
	
#else
	
	Target.Elements [ 0 ].E3 = Source.Elements [ 0 ].E3 + Translation.X * Source.Elements [ 0 ].E0 + Translation.Y * Source.Elements [ 0 ].E1 + Translation.Z * Source.Elements [ 0 ].E2;
	Target.Elements [ 1 ].E3 = Source.Elements [ 1 ].E3 + Translation.X * Source.Elements [ 1 ].E0 + Translation.Y * Source.Elements [ 1 ].E1 + Translation.Z * Source.Elements [ 1 ].E2;
	Target.Elements [ 2 ].E3 = Source.Elements [ 2 ].E3 + Translation.X * Source.Elements [ 2 ].E0 + Translation.Y * Source.Elements [ 2 ].E1 + Translation.Z * Source.Elements [ 2 ].E2;
	Target.Elements [ 3 ].E3 = Source.Elements [ 3 ].E3 + Translation.X * Source.Elements [ 3 ].E0 + Translation.Y * Source.Elements [ 3 ].E1 + Translation.Z * Source.Elements [ 3 ].E2;
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: SetAsScale ( Matrix4x4 & Target, const float X, const float Y, const float Z )
{
	
#ifdef XENON_SSE
	
	Target.Elements [ 0 ].SSEV = _mm_setr_ps ( X, 0.0f, 0.0f, 0.0f );
	Target.Elements [ 1 ].SSEV = _mm_setr_ps ( 0.0f, Y, 0.0f, 0.0f );
	Target.Elements [ 2 ].SSEV = _mm_setr_ps ( 0.0f, 0.0f, Z, 0.0f );
	Target.Elements [ 3 ].SSEV = _mm_setr_ps ( 0.0f, 0.0f, 0.0f, 1.0f );
	
#else
	
	Target.Elements [ 0 ].E0 = X;
	Target.Elements [ 1 ].E1 = Y;
	Target.Elements [ 2 ].E2 = Z;
	Target.Elements [ 3 ].E3 = 1.0f;
	
	Target.Elements [ 0 ].E1 = Target.Elements [ 0 ].E2 = Target.Elements [ 0 ].E3 = Target.Elements [ 1 ].E0 = Target.Elements [ 1 ].E2 = Target.Elements [ 1 ].E3 = Target.Elements [ 2 ].E0 = Target.Elements [ 2 ].E1 = Target.Elements [ 2 ].E3 = Target.Elements [ 3 ].E0 = Target.Elements [ 3 ].E1 = Target.Elements [ 3 ].E2 = 0.0f;
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: SetAsScale ( Matrix4x4 & Target, const Vec3 & Scale )
{
	
#ifdef XENON_SSE
	
	Target.Elements [ 0 ].SSEV = _mm_setr_ps ( Scale.X, 0.0f, 0.0f, 0.0f );
	Target.Elements [ 1 ].SSEV = _mm_setr_ps ( 0.0f, Scale.Y, 0.0f, 0.0f );
	Target.Elements [ 2 ].SSEV = _mm_setr_ps ( 0.0f, 0.0f, Scale.Z, 0.0f );
	Target.Elements [ 3 ].SSEV = _mm_setr_ps ( 0.0f, 0.0f, 0.0f, 1.0f );
	
#else
	
	Target.Elements [ 3 ].E3 = 1.0f;
	
	Target.Elements [ 0 ].E0 = Scale.X;
	Target.Elements [ 1 ].E1 = Scale.Y;
	Target.Elements [ 2 ].E2 = Scale.Z;
	
	Target.Elements [ 0 ].E1 = Target.Elements [ 0 ].E2 = Target.Elements [ 0 ].E3 = Target.Elements [ 1 ].E0 = Target.Elements [ 1 ].E2 = Target.Elements [ 1 ].E3 = Target.Elements [ 2 ].E0 = Target.Elements [ 2 ].E1 = Target.Elements [ 2 ].E3 = Target.Elements [ 3 ].E1 = Target.Elements [ 3 ].E2 = Target.Elements [ 3 ].E3 = 0.0f;
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: AppendScale ( Matrix4x4 & Target, const float X, const float Y, const float Z )
{
	
#ifdef XENON_SSE
	
	Target.Elements [ 0 ].SSEV = _mm_mul_ps ( Target.Elements [ 0 ].SSEV, _mm_set1_ps ( X ) );
	Target.Elements [ 1 ].SSEV = _mm_mul_ps ( Target.Elements [ 1 ].SSEV, _mm_set1_ps ( Y ) );
	Target.Elements [ 2 ].SSEV = _mm_mul_ps ( Target.Elements [ 2 ].SSEV, _mm_set1_ps ( Z ) );
	
#else
	
	Target.Elements [ 0 ].E0 * X;
	Target.Elements [ 0 ].E1 * X;
	Target.Elements [ 0 ].E2 * X;
	Target.Elements [ 0 ].E3 * X;
	
	Target.Elements [ 1 ].E0 * Y;
	Target.Elements [ 1 ].E1 * Y;
	Target.Elements [ 1 ].E2 * Y;
	Target.Elements [ 1 ].E3 * Y;
	
	Target.Elements [ 2 ].E0 * Z;
	Target.Elements [ 2 ].E1 * Z;
	Target.Elements [ 2 ].E2 * Z;
	Target.Elements [ 2 ].E3 * Z;
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: AppendScale ( Matrix4x4 & Target, const Vec3 & Scale )
{
	
#ifdef XENON_SSE
	
	Target.Elements [ 0 ].SSEV = _mm_mul_ps ( Target.Elements [ 0 ].SSEV, _mm_set1_ps ( Scale.X ) );
	Target.Elements [ 1 ].SSEV = _mm_mul_ps ( Target.Elements [ 1 ].SSEV, _mm_set1_ps ( Scale.Y ) );
	Target.Elements [ 2 ].SSEV = _mm_mul_ps ( Target.Elements [ 2 ].SSEV, _mm_set1_ps ( Scale.Z ) );
	
#else
	
	Target.Elements [ 0 ].E0 * Scale.X;
	Target.Elements [ 0 ].E1 * Scale.X;
	Target.Elements [ 0 ].E2 * Scale.X;
	Target.Elements [ 0 ].E3 * Scale.X;
	
	Target.Elements [ 1 ].E0 * Scale.Y;
	Target.Elements [ 1 ].E1 * Scale.Y;
	Target.Elements [ 1 ].E2 * Scale.Y;
	Target.Elements [ 1 ].E3 * Scale.Y;
	
	Target.Elements [ 2 ].E0 * Scale.Z;
	Target.Elements [ 2 ].E1 * Scale.Z;
	Target.Elements [ 2 ].E2 * Scale.Z;
	Target.Elements [ 2 ].E3 * Scale.Z;
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: AppendScale ( Matrix4x4 & Target, const Matrix4x4 & Source, const float X, const float Y, const float Z )
{
	
#ifdef XENON_SSE
	
	Target.Elements [ 0 ].SSEV = _mm_mul_ps ( Source.Elements [ 0 ].SSEV, _mm_set1_ps ( X ) );
	Target.Elements [ 1 ].SSEV = _mm_mul_ps ( Source.Elements [ 1 ].SSEV, _mm_set1_ps ( Y ) );
	Target.Elements [ 2 ].SSEV = _mm_mul_ps ( Source.Elements [ 2 ].SSEV, _mm_set1_ps ( Z ) );
	
#else
	
	Target.Elements [ 0 ].E0 = Source.Elements [ 0 ].E0 * X;
	Target.Elements [ 0 ].E1 = Source.Elements [ 0 ].E1 * X;
	Target.Elements [ 0 ].E2 = Source.Elements [ 0 ].E2 * X;
	Target.Elements [ 0 ].E3 = Source.Elements [ 0 ].E3 * X;
	
	Target.Elements [ 1 ].E0 = Source.Elements [ 1 ].E0 * Y;
	Target.Elements [ 1 ].E1 = Source.Elements [ 1 ].E1 * Y;
	Target.Elements [ 1 ].E2 = Source.Elements [ 1 ].E2 * Y;
	Target.Elements [ 1 ].E3 = Source.Elements [ 1 ].E3 * Y;
	
	Target.Elements [ 2 ].E0 = Source.Elements [ 2 ].E0 * Z;
	Target.Elements [ 2 ].E1 = Source.Elements [ 2 ].E1 * Z;
	Target.Elements [ 2 ].E2 = Source.Elements [ 2 ].E2 * Z;
	Target.Elements [ 2 ].E3 = Source.Elements [ 2 ].E3 * Z;
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: AppendScale ( Matrix4x4 & Target, const Matrix4x4 & Source, const Vec3 & Scale )
{
	
#ifdef XENON_SSE
	
	Target.Elements [ 0 ].SSEV = _mm_mul_ps ( Source.Elements [ 0 ].SSEV, _mm_set1_ps ( Scale.X ) );
	Target.Elements [ 1 ].SSEV = _mm_mul_ps ( Source.Elements [ 1 ].SSEV, _mm_set1_ps ( Scale.Y ) );
	Target.Elements [ 2 ].SSEV = _mm_mul_ps ( Source.Elements [ 2 ].SSEV, _mm_set1_ps ( Scale.Z ) );
	
#else
	
	Target.Elements [ 0 ].E0 = Source.Elements [ 0 ].E0 * Scale.X;
	Target.Elements [ 0 ].E1 = Source.Elements [ 0 ].E1 * Scale.X;
	Target.Elements [ 0 ].E2 = Source.Elements [ 0 ].E2 * Scale.X;
	Target.Elements [ 0 ].E3 = Source.Elements [ 0 ].E3 * Scale.X;
	
	Target.Elements [ 1 ].E0 = Source.Elements [ 1 ].E0 * Scale.Y;
	Target.Elements [ 1 ].E1 = Source.Elements [ 1 ].E1 * Scale.Y;
	Target.Elements [ 1 ].E2 = Source.Elements [ 1 ].E2 * Scale.Y;
	Target.Elements [ 1 ].E3 = Source.Elements [ 1 ].E3 * Scale.Y;
	
	Target.Elements [ 2 ].E0 = Source.Elements [ 2 ].E0 * Scale.Z;
	Target.Elements [ 2 ].E1 = Source.Elements [ 2 ].E1 * Scale.Z;
	Target.Elements [ 2 ].E2 = Source.Elements [ 2 ].E2 * Scale.Z;
	Target.Elements [ 2 ].E3 = Source.Elements [ 2 ].E3 * Scale.Z;
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: PrependScale ( Matrix4x4 & Source, const float X, const float Y, const float Z )
{
	
#ifdef XENON_SSE
	
	__m128 ScaleVect = _mm_setr_ps ( X, Y, Z, 1.0f );
	
	Source.Elements [ 0 ].SSEV = _mm_mul_ps ( Source.Elements [ 0 ].SSEV, ScaleVect );
	Source.Elements [ 1 ].SSEV = _mm_mul_ps ( Source.Elements [ 1 ].SSEV, ScaleVect );
	Source.Elements [ 2 ].SSEV = _mm_mul_ps ( Source.Elements [ 2 ].SSEV, ScaleVect );
	Source.Elements [ 3 ].SSEV = _mm_mul_ps ( Source.Elements [ 3 ].SSEV, ScaleVect );
	
#else
	
	Source.Elements [ 0 ].E0 * X;
	Source.Elements [ 0 ].E1 * Y;
	Source.Elements [ 0 ].E2 * Z;
	
	Source.Elements [ 1 ].E0 * X;
	Source.Elements [ 1 ].E1 * Y;
	Source.Elements [ 1 ].E2 * Z;
	
	Source.Elements [ 2 ].E0 * X;
	Source.Elements [ 2 ].E1 * Y;
	Source.Elements [ 2 ].E2 * Z;
	
	Source.Elements [ 3 ].E0 * X;
	Source.Elements [ 3 ].E1 * Y;
	Source.Elements [ 3 ].E2 * Z;
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: PrependScale ( Matrix4x4 & Source, const Vec3 & Scale )
{
	
#ifdef XENON_SSE
	
	__m128 ScaleVect = _mm_setr_ps ( Scale.X, Scale.Y, Scale.Z, 1.0f );
	
	Source.Elements [ 0 ].SSEV = _mm_mul_ps ( Source.Elements [ 0 ].SSEV, ScaleVect );
	Source.Elements [ 1 ].SSEV = _mm_mul_ps ( Source.Elements [ 1 ].SSEV, ScaleVect );
	Source.Elements [ 2 ].SSEV = _mm_mul_ps ( Source.Elements [ 2 ].SSEV, ScaleVect );
	Source.Elements [ 3 ].SSEV = _mm_mul_ps ( Source.Elements [ 3 ].SSEV, ScaleVect );
	
#else
	
	Source.Elements [ 0 ].E0 * Scale.X;
	Source.Elements [ 0 ].E1 * Scale.Y;
	Source.Elements [ 0 ].E2 * Scale.Z;
	
	Source.Elements [ 1 ].E0 * Scale.X;
	Source.Elements [ 1 ].E1 * Scale.Y;
	Source.Elements [ 1 ].E2 * Scale.Z;
	
	Source.Elements [ 2 ].E0 * Scale.X;
	Source.Elements [ 2 ].E1 * Scale.Y;
	Source.Elements [ 2 ].E2 * Scale.Z;
	
	Source.Elements [ 3 ].E0 * Scale.X;
	Source.Elements [ 3 ].E1 * Scale.Y;
	Source.Elements [ 3 ].E2 * Scale.Z;
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: PrependScale ( Matrix4x4 & Target, const Matrix4x4 & Source, const float X, const float Y, const float Z )
{
	
#ifdef XENON_SSE
	
	__m128 ScaleVect = _mm_setr_ps ( X, Y, Z, 1.0f );
	
	Target.Elements [ 0 ].SSEV = _mm_mul_ps ( Source.Elements [ 0 ].SSEV, ScaleVect );
	Target.Elements [ 1 ].SSEV = _mm_mul_ps ( Source.Elements [ 1 ].SSEV, ScaleVect );
	Target.Elements [ 2 ].SSEV = _mm_mul_ps ( Source.Elements [ 2 ].SSEV, ScaleVect );
	Target.Elements [ 3 ].SSEV = _mm_mul_ps ( Source.Elements [ 3 ].SSEV, ScaleVect );
	
#else
	
	Target.Elements [ 0 ].E0 = Source.Elements [ 0 ].E0 * X;
	Target.Elements [ 0 ].E1 = Source.Elements [ 0 ].E1 * Y;
	Target.Elements [ 0 ].E2 = Source.Elements [ 0 ].E2 * Z;
	
	Target.Elements [ 1 ].E0 = Source.Elements [ 1 ].E0 * X;
	Target.Elements [ 1 ].E1 = Source.Elements [ 1 ].E1 * Y;
	Target.Elements [ 1 ].E2 = Source.Elements [ 1 ].E2 * Z;
	
	Target.Elements [ 2 ].E0 = Source.Elements [ 2 ].E0 * X;
	Target.Elements [ 2 ].E1 = Source.Elements [ 2 ].E1 * Y;
	Target.Elements [ 2 ].E2 = Source.Elements [ 2 ].E2 * Z;
	
	Target.Elements [ 3 ].E0 = Source.Elements [ 3 ].E0 * X;
	Target.Elements [ 3 ].E1 = Source.Elements [ 3 ].E1 * Y;
	Target.Elements [ 3 ].E2 = Source.Elements [ 3 ].E2 * Z;
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: PrependScale ( Matrix4x4 & Target, const Matrix4x4 & Source, const Vec3 & Scale )
{
	
#ifdef XENON_SSE
	
	__m128 ScaleVect = _mm_setr_ps ( Scale.X, Scale.Y, Scale.Z, 1.0f );
	
	Target.Elements [ 0 ].SSEV = _mm_mul_ps ( Source.Elements [ 0 ].SSEV, ScaleVect );
	Target.Elements [ 1 ].SSEV = _mm_mul_ps ( Source.Elements [ 1 ].SSEV, ScaleVect );
	Target.Elements [ 2 ].SSEV = _mm_mul_ps ( Source.Elements [ 2 ].SSEV, ScaleVect );
	Target.Elements [ 3 ].SSEV = _mm_mul_ps ( Source.Elements [ 3 ].SSEV, ScaleVect );
	
#else
	
	Target.Elements [ 0 ].E0 = Source.Elements [ 0 ].E0 * Scale.X;
	Target.Elements [ 0 ].E1 = Source.Elements [ 0 ].E1 * Scale.Y;
	Target.Elements [ 0 ].E2 = Source.Elements [ 0 ].E2 * Scale.Z;
	
	Target.Elements [ 1 ].E0 = Source.Elements [ 1 ].E0 * Scale.X;
	Target.Elements [ 1 ].E1 = Source.Elements [ 1 ].E1 * Scale.Y;
	Target.Elements [ 1 ].E2 = Source.Elements [ 1 ].E2 * Scale.Z;
	
	Target.Elements [ 2 ].E0 = Source.Elements [ 2 ].E0 * Scale.X;
	Target.Elements [ 2 ].E1 = Source.Elements [ 2 ].E1 * Scale.Y;
	Target.Elements [ 2 ].E2 = Source.Elements [ 2 ].E2 * Scale.Z;
	
	Target.Elements [ 3 ].E0 = Source.Elements [ 3 ].E0 * Scale.X;
	Target.Elements [ 3 ].E1 = Source.Elements [ 3 ].E1 * Scale.Y;
	Target.Elements [ 3 ].E2 = Source.Elements [ 3 ].E2 * Scale.Z;
	
#endif
	
};

#ifdef XENON_SSE

inline void RowMult ( __m128 & Result, const __m128 & Row, const __m128 B [] )
{
	
	Result = _mm_mul_ps ( _mm_shuffle_ps ( Row, Row, 0x00 ), B [ 0 ] );
	Result = _mm_add_ps ( Result, _mm_mul_ps ( _mm_shuffle_ps ( Row, Row, 0x55 ), B [ 1 ] ) );
	Result = _mm_add_ps ( Result, _mm_mul_ps ( _mm_shuffle_ps ( Row, Row, 0xAA ), B [ 2 ] ) );
	Result = _mm_add_ps ( Result, _mm_mul_ps ( _mm_shuffle_ps ( Row, Row, 0xFF ), B [ 3 ] ) );
	
};

#else

inline void RowMult ( float Result [], const float Row [], const float Matrix [] )
{
	
	Result [ 0 ] = Row [ 0 ] * Matrix [ 0 ] + Row [ 1 ] * Matrix [ 4 ] + Row [ 2 ] * Matrix [ 8 ] + Row [ 3 ] * Matrix [ 12 ];
	Result [ 1 ] = Row [ 0 ] * Matrix [ 1 ] + Row [ 1 ] * Matrix [ 5 ] + Row [ 2 ] * Matrix [ 9 ] + Row [ 3 ] * Matrix [ 13 ];
	Result [ 2 ] = Row [ 0 ] * Matrix [ 2 ] + Row [ 1 ] * Matrix [ 6 ] + Row [ 2 ] * Matrix [ 10 ] + Row [ 3 ] * Matrix [ 14 ];
	Result [ 3 ] = Row [ 0 ] * Matrix [ 3 ] + Row [ 1 ] * Matrix [ 7 ] + Row [ 2 ] * Matrix [ 11 ] + Row [ 3 ] * Matrix [ 15 ];
	
};

#endif

void Xenon::Math::Matrix4x4 :: Append ( Matrix4x4 & Target, const Matrix4x4 & Pendant )
{
	
#ifdef XENON_SSE
	
	__m128 Temp;
	
	RowMult ( Temp,Target.Elements [ 0 ].SSEV, reinterpret_cast <const __m128 *> ( Pendant.Elements ) );
	Target.Elements [ 0 ].SSEV = Temp;
	
	RowMult ( Temp,Target.Elements [ 1 ].SSEV, reinterpret_cast <const __m128 *> ( Pendant.Elements ) );
	Target.Elements [ 1 ].SSEV = Temp;
	
	RowMult ( Temp,Target.Elements [ 2 ].SSEV, reinterpret_cast <const __m128 *> ( Pendant.Elements ) );
	Target.Elements [ 2 ].SSEV = Temp;
	
	RowMult ( Temp,Target.Elements [ 3 ].SSEV, reinterpret_cast <const __m128 *> ( Pendant.Elements ) );
	Target.Elements [ 3 ].SSEV = Temp;
	
#else
	
	Row_t Temp;
	
	RowMult ( reinterpret_cast <float *> ( & Temp ), reinterpret_cast <const float *> ( &Target.Elements [ 0 ] ), reinterpret_cast <const float *> ( Pendant.Elements ) );
	Target.Elements [ 0 ] = Temp;
	
	RowMult ( reinterpret_cast <float *> ( & Temp ), reinterpret_cast <const float *> ( &Target.Elements [ 1 ] ), reinterpret_cast <const float *> ( Pendant.Elements ) );
	Target.Elements [ 1 ] = Temp;
	
	RowMult ( reinterpret_cast <float *> ( & Temp ), reinterpret_cast <const float *> ( &Target.Elements [ 2 ] ), reinterpret_cast <const float *> ( Pendant.Elements ) );
	Target.Elements [ 2 ] = Temp;
	
	RowMult ( reinterpret_cast <float *> ( & Temp ), reinterpret_cast <const float *> ( &Target.Elements [ 3 ] ), reinterpret_cast <const float *> ( Pendant.Elements ) );
	Target.Elements [ 3 ] = Temp;
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: Append ( Matrix4x4 & Target, const Matrix4x4 & Source, const Matrix4x4 & Pendant )
{
	
#ifdef XENON_SSE
	
	RowMult ( Target.Elements [ 0 ].SSEV, Source.Elements [ 0 ].SSEV, reinterpret_cast <const __m128 *> ( Pendant.Elements ) );
	RowMult ( Target.Elements [ 1 ].SSEV, Source.Elements [ 1 ].SSEV, reinterpret_cast <const __m128 *> ( Pendant.Elements ) );
	RowMult ( Target.Elements [ 2 ].SSEV, Source.Elements [ 2 ].SSEV, reinterpret_cast <const __m128 *> ( Pendant.Elements ) );
	RowMult ( Target.Elements [ 3 ].SSEV, Source.Elements [ 3 ].SSEV, reinterpret_cast <const __m128 *> ( Pendant.Elements ) );
	
#else
	
	RowMult ( reinterpret_cast <float *> ( & Target.Elements [ 0 ] ), reinterpret_cast <const float *> ( &Target.Elements [ 0 ] ), reinterpret_cast <const float *> ( Pendant.Elements ) );
	RowMult ( reinterpret_cast <float *> ( & Target.Elements [ 1 ] ), reinterpret_cast <const float *> ( &Target.Elements [ 1 ] ), reinterpret_cast <const float *> ( Pendant.Elements ) );
	RowMult ( reinterpret_cast <float *> ( & Target.Elements [ 2 ] ), reinterpret_cast <const float *> ( &Target.Elements [ 2 ] ), reinterpret_cast <const float *> ( Pendant.Elements ) );
	RowMult ( reinterpret_cast <float *> ( & Target.Elements [ 3 ] ), reinterpret_cast <const float *> ( &Target.Elements [ 3 ] ), reinterpret_cast <const float *> ( Pendant.Elements ) );
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: Prepend ( Matrix4x4 & Target, const Matrix4x4 & Pendant )
{
	
	Row_t Temp [ 4 ];
	
#ifdef XENON_SSE
	
	RowMult ( Temp [ 0 ].SSEV, Pendant.Elements [ 0 ].SSEV, reinterpret_cast <const __m128 *> ( Target.Elements ) );
	RowMult ( Temp [ 1 ].SSEV, Pendant.Elements [ 1 ].SSEV, reinterpret_cast <const __m128 *> ( Target.Elements ) );
	RowMult ( Temp [ 2 ].SSEV, Pendant.Elements [ 2 ].SSEV, reinterpret_cast <const __m128 *> ( Target.Elements ) );
	RowMult ( Temp [ 3 ].SSEV, Pendant.Elements [ 3 ].SSEV, reinterpret_cast <const __m128 *> ( Target.Elements ) );
	
	Target.Elements [ 0 ] = Temp [ 0 ];
	Target.Elements [ 1 ] = Temp [ 1 ];
	Target.Elements [ 2 ] = Temp [ 2 ];
	Target.Elements [ 3 ] = Temp [ 3 ];
	
#else
	
	RowMult ( reinterpret_cast <float *> ( & Temp [ 0 ] ), reinterpret_cast <const float *> ( & Pendant.Elements [ 0 ] ), reinterpret_cast <const float *> ( Target.Elements ) );
	RowMult ( reinterpret_cast <float *> ( & Temp [ 1 ] ), reinterpret_cast <const float *> ( & Pendant.Elements [ 1 ] ), reinterpret_cast <const float *> ( Target.Elements ) );
	RowMult ( reinterpret_cast <float *> ( & Temp [ 2 ] ), reinterpret_cast <const float *> ( & Pendant.Elements [ 2 ] ), reinterpret_cast <const float *> ( Target.Elements ) );
	RowMult ( reinterpret_cast <float *> ( & Temp [ 3 ] ), reinterpret_cast <const float *> ( & Pendant.Elements [ 3 ] ), reinterpret_cast <const float *> ( Target.Elements ) );
	
	Target.Elements [ 0 ] = Temp [ 0 ];
	Target.Elements [ 1 ] = Temp [ 1 ];
	Target.Elements [ 2 ] = Temp [ 2 ];
	Target.Elements [ 3 ] = Temp [ 3 ];
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: Prepend ( Matrix4x4 & Target, const Matrix4x4 & Source, const Matrix4x4 & Pendant )
{
	
	Row_t Temp [ 4 ];
	
#ifdef XENON_SSE
	
	RowMult ( Target.Elements [ 0 ].SSEV, Pendant.Elements [ 0 ].SSEV, reinterpret_cast <const __m128 *> ( Source.Elements ) );
	RowMult ( Target.Elements [ 1 ].SSEV, Pendant.Elements [ 1 ].SSEV, reinterpret_cast <const __m128 *> ( Source.Elements ) );
	RowMult ( Target.Elements [ 2 ].SSEV, Pendant.Elements [ 2 ].SSEV, reinterpret_cast <const __m128 *> ( Source.Elements ) );
	RowMult ( Target.Elements [ 3 ].SSEV, Pendant.Elements [ 3 ].SSEV, reinterpret_cast <const __m128 *> ( Source.Elements ) );
	
#else
	
	RowMult ( reinterpret_cast <float *> ( & Target.Elements [ 0 ] ), reinterpret_cast <const float *> ( & Pendant.Elements [ 0 ] ), reinterpret_cast <const float *> ( Source.Elements ) );
	RowMult ( reinterpret_cast <float *> ( & Target.Elements [ 1 ] ), reinterpret_cast <const float *> ( & Pendant.Elements [ 1 ] ), reinterpret_cast <const float *> ( Source.Elements ) );
	RowMult ( reinterpret_cast <float *> ( & Target.Elements [ 2 ] ), reinterpret_cast <const float *> ( & Pendant.Elements [ 2 ] ), reinterpret_cast <const float *> ( Source.Elements ) );
	RowMult ( reinterpret_cast <float *> ( & Target.Elements [ 3 ] ), reinterpret_cast <const float *> ( & Pendant.Elements [ 3 ] ), reinterpret_cast <const float *> ( Source.Elements ) );
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: SetAsQuaternionRotation ( Matrix4x4 & Target, const Quaternion & Rotation )
{
	
	float XX = 2.0 * Rotation.X * Rotation.X;
	float XY = 2.0 * Rotation.X * Rotation.Y;
	float XZ = 2.0 * Rotation.X * Rotation.Z;
	float XW = 2.0 * Rotation.X * Rotation.W;
	float YY = 2.0 * Rotation.Y * Rotation.Y;
	float YZ = 2.0 * Rotation.Y * Rotation.Z;
	float YW = 2.0 * Rotation.Y * Rotation.W;
	float ZZ = 2.0 * Rotation.Z * Rotation.Z;
	float ZW = 2.0 * Rotation.Z * Rotation.W;
	float WW = 2.0 * Rotation.W * Rotation.W;
	
#ifdef XENON_SSE
	
	Target.Elements [ 0 ].SSEV = _mm_setr_ps ( 1.0f - ( YY + ZZ ), XY - ZW, XZ + YW, 0.0f );
	Target.Elements [ 1 ].SSEV = _mm_setr_ps ( XY + ZW, 1.0f - ( XX + ZZ ), YZ - XW, 0.0f );
	Target.Elements [ 2 ].SSEV = _mm_setr_ps ( XZ - YW, YZ + XW, 1.0f - ( XX + YY ), 0.0f );
	Target.Elements [ 3 ].SSEV = _mm_setr_ps ( 0.0f, 0.0f, 0.0f, 1.0f );
	
#else
	
	Target.Elements [ 0 ].E0 = 1.0f - ( YY + ZZ );
	Target.Elements [ 0 ].E1 = XY - ZW;
	Target.Elements [ 0 ].E2 = XZ + YW;
	
	Target.Elements [ 1 ].E0 = XY + ZW;
	Target.Elements [ 1 ].E1 = 1.0f - ( XX + ZZ );
	Target.Elements [ 1 ].E2 = YZ - XW;
	
	Target.Elements [ 2 ].E0 = XZ - YW;
	Target.Elements [ 2 ].E1 = YZ + XW;
	Target.Elements [ 2 ].E2 = 1.0f - ( XX + YY );
	
	Target.Elements [ 0 ].E3 = Target.Elements [ 1 ].E3 = Target.Elements [ 2 ].E3 = Target.Elements [ 3 ].E0 = Target.Elements [ 3 ].E1 = Target.Elements [ 3 ].E2 = 0.0f;
	Target.Elements [ 3 ].E3 = 1.0f;
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: SetAsQuaternionRotation ( Matrix4x4 & Target, const float X, const float Y, const float Z, const float W )
{
	
	float XX = 2.0 * X * X;
	float XY = 2.0 * X * Y;
	float XZ = 2.0 * X * Z;
	float XW = 2.0 * X * W;
	float YY = 2.0 * Y * Y;
	float YZ = 2.0 * Y * Z;
	float YW = 2.0 * Y * W;
	float ZZ = 2.0 * Z * Z;
	float ZW = 2.0 * Z * W;
	float WW = 2.0 * W * W;
	
#ifdef XENON_SSE
	
	Target.Elements [ 0 ].SSEV = _mm_setr_ps ( 1.0f - ( YY + ZZ ), XY - ZW, XZ + YW, 0.0f );
	Target.Elements [ 1 ].SSEV = _mm_setr_ps ( XY + ZW, 1.0f - ( XX + ZZ ), YZ - XW, 0.0f );
	Target.Elements [ 2 ].SSEV = _mm_setr_ps ( XZ - YW, YZ + XW, 1.0f - ( XX + YY ), 0.0f );
	Target.Elements [ 3 ].SSEV = _mm_setr_ps ( 0.0f, 0.0f, 0.0f, 1.0f );
	
#else
	
	Target.Elements [ 0 ].E0 = 1.0f - ( YY + ZZ );
	Target.Elements [ 0 ].E1 = XY - ZW;
	Target.Elements [ 0 ].E2 = XZ + YW;
	
	Target.Elements [ 1 ].E0 = XY + ZW;
	Target.Elements [ 1 ].E1 = 1.0f - ( XX + ZZ );
	Target.Elements [ 1 ].E2 = YZ - XW;
	
	Target.Elements [ 2 ].E0 = XZ - YW;
	Target.Elements [ 2 ].E1 = YZ + XW;
	Target.Elements [ 2 ].E2 = 1.0f - ( XX + YY );
	
	Target.Elements [ 0 ].E3 = Target.Elements [ 1 ].E3 = Target.Elements [ 2 ].E3 = Target.Elements [ 3 ].E0 = Target.Elements [ 3 ].E1 = Target.Elements [ 3 ].E2 = 0.0f;
	Target.Elements [ 3 ].E3 = 1.0f;
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: AppendQuaternionRotation ( Matrix4x4 & Target, const Quaternion & Rotation )
{
	
	Matrix4x4 RotationMatrix ( NO_INIT );
	SetAsQuaternionRotation ( RotationMatrix, Rotation );
	
	Target.Append ( Target, RotationMatrix );
	
};

void Xenon::Math::Matrix4x4 :: AppendQuaternionRotation ( Matrix4x4 & Target, const float X, const float Y, const float Z, const float W )
{
	
	Matrix4x4 RotationMatrix ( NO_INIT );
	SetAsQuaternionRotation ( RotationMatrix, X, Y, Z, W );
	
	Target.Append ( Target, RotationMatrix );
	
};

float Xenon::Math::Matrix4x4 :: Determinant ( const Matrix4x4 & Source )
{
	
#ifdef XENON_SSE
	
	union
	{
		
		__m128 AddMul;
		float AddMulFP [ 4 ];
		
	};
	
	union
	{
		
		__m128 SubMul;
		float SubMulFP [ 4 ];
		
	};
	
	AddMul = _mm_mul_ps ( _mm_mul_ps ( Source.Elements [ 0 ].SSEV, _mm_shuffle_ps ( Source.Elements [ 1 ].SSEV,Source.Elements [ 1 ].SSEV, _MM_SHUFFLE ( 0, 3, 2, 1 ) ) ), _mm_mul_ps ( _mm_shuffle_ps ( Source.Elements [ 2 ].SSEV,Source.Elements [ 2 ].SSEV, _MM_SHUFFLE ( 1, 0, 3, 2 ) ), _mm_shuffle_ps ( Source.Elements [ 3 ].SSEV,Source.Elements [ 3 ].SSEV, _MM_SHUFFLE ( 2, 1, 0, 3 ) ) ) );
	SubMul = _mm_mul_ps ( _mm_shuffle_ps ( Source.Elements [ 0 ].SSEV,Source.Elements [ 0 ].SSEV, _MM_SHUFFLE ( 0, 1, 2, 3 ) ), _mm_shuffle_ps ( Source.Elements [ 1 ].SSEV,Source.Elements [ 1 ].SSEV, _MM_SHUFFLE ( 3, 0, 1, 2 ) ) ), _mm_mul_ps ( _mm_shuffle_ps ( Source.Elements [ 2 ].SSEV,Source.Elements [ 2 ].SSEV, _MM_SHUFFLE ( 2, 3, 0, 1 ) ), _mm_shuffle_ps ( Source.Elements [ 3 ].SSEV,Source.Elements [ 3 ].SSEV, _MM_SHUFFLE ( 1, 2, 3, 0 ) ) );
	
#ifdef XENON_SSE4_1
	
	AddMul = _mm_hadd_ps ( AddMul, AddMul );
	AddMul = _mm_hadd_ps ( AddMul, AddMul );
	
	SubMul = _mm_hadd_ps ( SubMul, SubMul );
	SubMul = _mm_hadd_ps ( SubMul, SubMul );
	
	return AddMulFP [ 0 ] - SubMulFP [ 0 ];
	
#else
	
	return ( AddMulFP [ 0 ] + AddMulFP [ 1 ] + AddMulFP [ 2 ] + AddMulFP [ 3 ] ) - ( SubMulFP [ 0 ] + SubMulFP [ 1 ] + SubMulFP [ 2 ] + SubMulFP [ 3 ] );
	
#endif
	
#else
	
	float Total = 0.0f;
	
	Total += Source.Elements [ 0 ].E0 * Source.Elements [ 1 ].E1 * Source.Elements [ 2 ].E2 * Source.Elements [ 3 ].E3;
	Total += Source.Elements [ 0 ].E1 * Source.Elements [ 1 ].E2 * Source.Elements [ 2 ].E3 * Source.Elements [ 3 ].E0;
	Total += Source.Elements [ 0 ].E2 * Source.Elements [ 1 ].E3 * Source.Elements [ 2 ].E0 * Source.Elements [ 3 ].E1;
	Total += Source.Elements [ 0 ].E3 * Source.Elements [ 1 ].E0 * Source.Elements [ 2 ].E1 * Source.Elements [ 3 ].E2;
	
	Total -= Source.Elements [ 0 ].E3 * Source.Elements [ 1 ].E2 * Source.Elements [ 2 ].E1 * Source.Elements [ 3 ].E0;
	Total -= Source.Elements [ 0 ].E2 * Source.Elements [ 1 ].E1 * Source.Elements [ 2 ].E0 * Source.Elements [ 3 ].E3;
	Total -= Source.Elements [ 0 ].E1 * Source.Elements [ 1 ].E0 * Source.Elements [ 2 ].E3 * Source.Elements [ 3 ].E2;
	Total -= Source.Elements [ 0 ].E0 * Source.Elements [ 1 ].E3 * Source.Elements [ 2 ].E2 * Source.Elements [ 3 ].E1;
	
	return Total;
	
#endif
	
};

void Xenon::Math::Matrix4x4 :: Transpose ( Matrix4x4 & Target )
{
	
	std :: swap ( Target.Elements [ 0 ].E1, Target.Elements [ 1 ].E0 );
	std :: swap ( Target.Elements [ 0 ].E2, Target.Elements [ 2 ].E0 );
	std :: swap ( Target.Elements [ 0 ].E3, Target.Elements [ 3 ].E0 );
	
	std :: swap ( Target.Elements [ 1 ].E2, Target.Elements [ 2 ].E1 );
	std :: swap ( Target.Elements [ 1 ].E3, Target.Elements [ 3 ].E1 );
	
	std :: swap ( Target.Elements [ 2 ].E3, Target.Elements [ 3 ].E2 );
	
};

void Xenon::Math::Matrix4x4 :: Transpose ( Matrix4x4 & Target, const Matrix4x4 & Source )
{
	
	Copy ( Target, Source );
	
	std :: swap ( Target.Elements [ 0 ].E1, Target.Elements [ 1 ].E0 );
	std :: swap ( Target.Elements [ 0 ].E2, Target.Elements [ 2 ].E0 );
	std :: swap ( Target.Elements [ 0 ].E3, Target.Elements [ 3 ].E0 );
	
	std :: swap ( Target.Elements [ 1 ].E2, Target.Elements [ 2 ].E1 );
	std :: swap ( Target.Elements [ 1 ].E3, Target.Elements [ 3 ].E1 );
	
	std :: swap ( Target.Elements [ 2 ].E3, Target.Elements [ 3 ].E2 );
	
};

void Xenon::Math::Matrix4x4 :: Copy ( Matrix4x4 & Target, const Matrix4x4 & Source )
{
	
	memcpy ( reinterpret_cast <void *> ( Target.Elements ), reinterpret_cast <const void *> ( Source.Elements ), sizeof ( Source.Elements ) );
	
};

void Xenon::Math::Matrix4x4 :: Invert ( Matrix4x4 & Target )
{
	
#ifdef XENON_SSE
	
	Transpose ( Target );
	
	__m128 V00 = _mm_shuffle_ps ( Target.Elements [ 2 ].SSEV, Target.Elements [ 2 ].SSEV, _MM_SHUFFLE ( 1, 1, 0, 0 ) );
	__m128 V10 = _mm_shuffle_ps ( Target.Elements [ 3 ].SSEV, Target.Elements [ 3 ].SSEV, _MM_SHUFFLE ( 3, 2, 3, 2 ) );
	__m128 V01 = _mm_shuffle_ps ( Target.Elements [ 0 ].SSEV, Target.Elements [ 0 ].SSEV, _MM_SHUFFLE ( 1, 1, 0, 0 ) );
	__m128 V11 = _mm_shuffle_ps ( Target.Elements [ 1 ].SSEV, Target.Elements [ 1 ].SSEV, _MM_SHUFFLE ( 3, 2, 3, 2 ) );
	__m128 V02 = _mm_shuffle_ps ( Target.Elements [ 2 ].SSEV, Target.Elements [ 0 ].SSEV, _MM_SHUFFLE ( 2, 0, 2, 0 ) );
	__m128 V12 = _mm_shuffle_ps ( Target.Elements [ 3 ].SSEV, Target.Elements [ 1 ].SSEV, _MM_SHUFFLE ( 3, 1, 3, 1 ) );
	
	__m128 D0 = _mm_mul_ps ( V00, V10 );
	__m128 D1 = _mm_mul_ps ( V01, V11 );
	__m128 D2 = _mm_mul_ps ( V02, V12 );
	
	V00 = _mm_shuffle_ps ( Target.Elements [ 2 ].SSEV, Target.Elements [ 2 ].SSEV, _MM_SHUFFLE ( 3, 2, 3, 2 ) );
	V10 = _mm_shuffle_ps ( Target.Elements [ 3 ].SSEV, Target.Elements [ 3 ].SSEV, _MM_SHUFFLE ( 1, 1, 0, 0 ) );
	V01 = _mm_shuffle_ps ( Target.Elements [ 0 ].SSEV, Target.Elements [ 0 ].SSEV, _MM_SHUFFLE ( 3, 2, 3, 2 ) );
	V11 = _mm_shuffle_ps ( Target.Elements [ 1 ].SSEV, Target.Elements [ 1 ].SSEV, _MM_SHUFFLE ( 1, 1, 0, 0 ) );
	V02 = _mm_shuffle_ps ( Target.Elements [ 2 ].SSEV, Target.Elements [ 0 ].SSEV, _MM_SHUFFLE ( 3, 1, 3, 1 ) );
	V12 = _mm_shuffle_ps ( Target.Elements [ 3 ].SSEV, Target.Elements [ 1 ].SSEV, _MM_SHUFFLE ( 2, 0, 2, 0 ) );
	
	V00 = _mm_mul_ps ( V00, V10 );
	V01 = _mm_mul_ps ( V01, V11 );
	V02 = _mm_mul_ps ( V02, V12 );
	D0 = _mm_sub_ps ( D0, V00 );
	D1 = _mm_sub_ps ( D1, V01 );
	D2 = _mm_sub_ps ( D2, V02 );
	V11 = _mm_shuffle_ps ( D0, D2, _MM_SHUFFLE ( 1, 1, 3, 1 ) );
	V00 = _mm_shuffle_ps ( Target.Elements [ 1 ].SSEV, Target.Elements [ 1 ].SSEV, _MM_SHUFFLE ( 1, 0, 2, 1 ) );
	V10 = _mm_shuffle_ps ( V11, D0, _MM_SHUFFLE ( 0, 3, 0, 2 ) );
	V01 = _mm_shuffle_ps ( Target.Elements [ 0 ].SSEV, Target.Elements [ 0 ].SSEV, _MM_SHUFFLE ( 0, 1, 0, 2 ) );
	V11 = _mm_shuffle_ps ( V11, D0, _MM_SHUFFLE ( 2, 1, 2, 1 ) );
	__m128 V13 = _mm_shuffle_ps ( D1, D2, _MM_SHUFFLE ( 3, 3, 3, 1 ) );
	V02 = _mm_shuffle_ps ( Target.Elements [ 3 ].SSEV, Target.Elements [ 3 ].SSEV, _MM_SHUFFLE ( 1, 0, 2, 1 ) );
	V12 = _mm_shuffle_ps ( V13, D1, _MM_SHUFFLE ( 0, 3, 0, 2 ) );
	__m128 V03 = _mm_shuffle_ps ( Target.Elements [ 2 ].SSEV, Target.Elements [ 2 ].SSEV, _MM_SHUFFLE ( 0, 1, 0, 2 ) );
	V13 = _mm_shuffle_ps ( V13, D1, _MM_SHUFFLE ( 2, 1, 2, 1 ) );
	
	__m128 C0 = _mm_mul_ps ( V00, V10 );
	__m128 C2 = _mm_mul_ps ( V01, V11 );
	__m128 C4 = _mm_mul_ps ( V02, V12 );
	__m128 C6 = _mm_mul_ps ( V03, V13 );
	
	V11 = _mm_shuffle_ps ( D0, D2, _MM_SHUFFLE ( 0, 0, 1, 0 ) );
	V00 = _mm_shuffle_ps ( Target.Elements [ 1 ].SSEV, Target.Elements [ 1 ].SSEV, _MM_SHUFFLE ( 2, 1, 3, 2 ) );
	V10 = _mm_shuffle_ps ( D0, V11, _MM_SHUFFLE ( 2, 1, 0, 3 ) );
	V01 = _mm_shuffle_ps ( Target.Elements [ 0 ].SSEV, Target.Elements [ 0 ].SSEV, _MM_SHUFFLE ( 1, 3, 2, 3 ) );
	V11 = _mm_shuffle_ps ( D0, V11, _MM_SHUFFLE ( 0, 2, 1, 2 ) );
	V13 = _mm_shuffle_ps ( D1, D2, _MM_SHUFFLE ( 2, 2, 1, 0 ) );
	V02 = _mm_shuffle_ps ( Target.Elements [ 3 ].SSEV, Target.Elements [ 3 ].SSEV, _MM_SHUFFLE ( 2, 1, 3, 2 ) );
	V12 = _mm_shuffle_ps ( D1, V13, _MM_SHUFFLE ( 2, 1, 0, 3 ) );
	V03 = _mm_shuffle_ps ( Target.Elements [ 2 ].SSEV, Target.Elements [ 2 ].SSEV, _MM_SHUFFLE ( 1, 3, 2, 3 ) );
	V13 = _mm_shuffle_ps ( D1, V13, _MM_SHUFFLE ( 0, 2, 1, 2 ) );
	
	V00 = _mm_mul_ps ( V00, V10 );
	V01 = _mm_mul_ps ( V01, V11 );
	V02 = _mm_mul_ps ( V02, V12 );
	V03 = _mm_mul_ps ( V03, V13 );
	C0 = _mm_sub_ps ( C0, V00 );
	C2 = _mm_sub_ps ( C2, V01 );
	C4 = _mm_sub_ps ( C4, V02 );
	C6 = _mm_sub_ps ( C6, V03 );
	
	V00 = _mm_shuffle_ps ( Target.Elements [ 1 ].SSEV, Target.Elements [ 1 ].SSEV, _MM_SHUFFLE ( 0, 3, 0, 3 ) );
	V10 = _mm_shuffle_ps ( D0, D2, _MM_SHUFFLE ( 1, 0, 2, 2 ) );
	V10 = _mm_shuffle_ps ( V10, V10, _MM_SHUFFLE ( 0, 2, 3, 0 ) );
	V01 = _mm_shuffle_ps ( Target.Elements [ 0 ].SSEV, Target.Elements [ 0 ].SSEV, _MM_SHUFFLE ( 2, 0, 3, 1 ) );
	V11 = _mm_shuffle_ps ( D0, D2, _MM_SHUFFLE ( 1, 0, 3, 0 ) );
	V11 = _mm_shuffle_ps ( V11, V11, _MM_SHUFFLE ( 2, 1, 0, 3 ) );
	V02 = _mm_shuffle_ps ( Target.Elements [ 3 ].SSEV, Target.Elements [ 3 ].SSEV, _MM_SHUFFLE ( 0, 3, 0, 3 ) );
	V12 = _mm_shuffle_ps ( D1, D2, _MM_SHUFFLE ( 3, 2, 2, 2 ) );
	V12 = _mm_shuffle_ps ( V12, V12, _MM_SHUFFLE ( 0, 2, 3, 0 ) );
	V03 = _mm_shuffle_ps ( Target.Elements [ 2 ].SSEV, Target.Elements [ 2 ].SSEV, _MM_SHUFFLE ( 2, 0, 3, 1 ) );
	V13 = _mm_shuffle_ps ( D1, D2, _MM_SHUFFLE ( 3, 2, 3, 0 ) );
	V13 = _mm_shuffle_ps ( V13, V13, _MM_SHUFFLE ( 2, 1, 0, 3 ) );
	
	V00 = _mm_mul_ps ( V00, V10 );
	V01 = _mm_mul_ps ( V01, V11 );
	V02 = _mm_mul_ps ( V02, V12 );
	V03 = _mm_mul_ps ( V03, V13 );
	
	__m128 C1 = _mm_sub_ps ( C0, V00 );
	C0 = _mm_add_ps ( C0, V00 );
	__m128 C3 = _mm_add_ps ( C2, V01 );
	C2 = _mm_sub_ps ( C2, V01 );
	__m128 C5 = _mm_sub_ps ( C4,V02 );
	C4 = _mm_add_ps ( C4,V02 );
	__m128 C7 = _mm_add_ps ( C6,V03 );
	C6 = _mm_sub_ps ( C6,V03 );
	
	C0 = _mm_shuffle_ps ( C0, C1, _MM_SHUFFLE ( 3, 1, 2, 0 ) );
	C2 = _mm_shuffle_ps ( C2, C3, _MM_SHUFFLE ( 3, 1, 2, 0 ) );
	C4 = _mm_shuffle_ps ( C4, C5, _MM_SHUFFLE ( 3, 1, 2, 0 ) );
	C6 = _mm_shuffle_ps ( C6, C7, _MM_SHUFFLE ( 3, 1, 2, 0 ) );
	C0 = _mm_shuffle_ps ( C0, C0, _MM_SHUFFLE ( 3, 1, 2, 0 ) );
	C2 = _mm_shuffle_ps ( C2, C2, _MM_SHUFFLE ( 3, 1, 2, 0 ) );
	C4 = _mm_shuffle_ps ( C4, C4, _MM_SHUFFLE ( 3, 1, 2, 0 ) );
	C6 = _mm_shuffle_ps ( C6, C6, _MM_SHUFFLE ( 3, 1, 2, 0 ) );
	
	__m128 vTemp = _mm_dp_ps ( C0, Target.Elements [ 0 ].SSEV, 0xFF );
	
	vTemp = _mm_div_ps ( _mm_set1_ps ( 1.0f ), vTemp );
	
	Target.Elements [ 0 ].SSEV = _mm_mul_ps ( C0, vTemp );
	Target.Elements [ 1 ].SSEV = _mm_mul_ps ( C2, vTemp );
	Target.Elements [ 2 ].SSEV = _mm_mul_ps ( C4, vTemp );
	Target.Elements [ 3 ].SSEV = _mm_mul_ps ( C6, vTemp );
	
#else
	
	Matrix4x4 Temp ( NO_INIT );
	
	Temp.Elements [ 0 ].E0 = + Target.Elements [ 1 ].E1 * Target.Elements [ 2 ].E2 * Target.Elements [ 3 ].E3 - Target.Elements [ 1 ].E1 * Target.Elements [ 2 ].E3 * Target.Elements [ 3 ].E2 - Target.Elements [ 2 ].E1 * Target.Elements [ 1 ].E2 * Target.Elements [ 3 ].E3 + Target.Elements [ 2 ].E1 * Target.Elements [ 1 ].E3 * Target.Elements [ 3 ].E2 + Target.Elements [ 3 ].E1 * Target.Elements [ 1 ].E2 * Target.Elements [ 2 ].E3 - Target.Elements [ 3 ].E1 * Target.Elements [ 1 ].E3 * Target.Elements [ 2 ].E2;
	Temp.Elements [ 1 ].E0 = - Target.Elements [ 1 ].E0 * Target.Elements [ 2 ].E2 * Target.Elements [ 3 ].E3 + Target.Elements [ 1 ].E0 * Target.Elements [ 2 ].E3 * Target.Elements [ 3 ].E2 + Target.Elements [ 2 ].E0 * Target.Elements [ 1 ].E2 * Target.Elements [ 3 ].E3 - Target.Elements [ 2 ].E0 * Target.Elements [ 1 ].E3 * Target.Elements [ 3 ].E2 - Target.Elements [ 3 ].E0 * Target.Elements [ 1 ].E2 * Target.Elements [ 2 ].E3 + Target.Elements [ 3 ].E0 * Target.Elements [ 1 ].E3 * Target.Elements [ 2 ].E2;
	Temp.Elements [ 2 ].E0 = + Target.Elements [ 1 ].E0 * Target.Elements [ 2 ].E1 * Target.Elements [ 3 ].E3 - Target.Elements [ 1 ].E0 * Target.Elements [ 2 ].E3 * Target.Elements [ 3 ].E1 - Target.Elements [ 2 ].E0 * Target.Elements [ 1 ].E1 * Target.Elements [ 3 ].E3 + Target.Elements [ 2 ].E0 * Target.Elements [ 1 ].E3 * Target.Elements [ 3 ].E1 + Target.Elements [ 3 ].E0 * Target.Elements [ 1 ].E1 * Target.Elements [ 2 ].E3 - Target.Elements [ 3 ].E0 * Target.Elements [ 1 ].E3 * Target.Elements [ 2 ].E1;
	Temp.Elements [ 3 ].E0 = - Target.Elements [ 1 ].E0 * Target.Elements [ 2 ].E1 * Target.Elements [ 3 ].E2 + Target.Elements [ 1 ].E0 * Target.Elements [ 2 ].E2 * Target.Elements [ 3 ].E1 + Target.Elements [ 2 ].E0 * Target.Elements [ 1 ].E1 * Target.Elements [ 3 ].E2 - Target.Elements [ 2 ].E0 * Target.Elements [ 1 ].E2 * Target.Elements [ 3 ].E1 - Target.Elements [ 3 ].E0 * Target.Elements [ 1 ].E1 * Target.Elements [ 2 ].E2 + Target.Elements [ 3 ].E0 * Target.Elements [ 1 ].E2 * Target.Elements [ 2 ].E1;
	Temp.Elements [ 0 ].E1 = - Target.Elements [ 0 ].E1 * Target.Elements [ 2 ].E2 * Target.Elements [ 3 ].E3 + Target.Elements [ 0 ].E1 * Target.Elements [ 2 ].E3 * Target.Elements [ 3 ].E2 + Target.Elements [ 2 ].E1 * Target.Elements [ 0 ].E2 * Target.Elements [ 3 ].E3 - Target.Elements [ 2 ].E1 * Target.Elements [ 0 ].E3 * Target.Elements [ 3 ].E2 - Target.Elements [ 3 ].E1 * Target.Elements [ 0 ].E2 * Target.Elements [ 2 ].E3 + Target.Elements [ 3 ].E1 * Target.Elements [ 0 ].E3 * Target.Elements [ 2 ].E2;
	Temp.Elements [ 1 ].E1 = + Target.Elements [ 0 ].E0 * Target.Elements [ 2 ].E2 * Target.Elements [ 3 ].E3 - Target.Elements [ 0 ].E0 * Target.Elements [ 2 ].E3 * Target.Elements [ 3 ].E2 - Target.Elements [ 2 ].E0 * Target.Elements [ 0 ].E2 * Target.Elements [ 3 ].E3 + Target.Elements [ 2 ].E0 * Target.Elements [ 0 ].E3 * Target.Elements [ 3 ].E2 + Target.Elements [ 3 ].E0 * Target.Elements [ 0 ].E2 * Target.Elements [ 2 ].E3 - Target.Elements [ 3 ].E0 * Target.Elements [ 0 ].E3 * Target.Elements [ 2 ].E2;
	Temp.Elements [ 2 ].E1 = - Target.Elements [ 0 ].E0 * Target.Elements [ 2 ].E1 * Target.Elements [ 3 ].E3 + Target.Elements [ 0 ].E0 * Target.Elements [ 2 ].E3 * Target.Elements [ 3 ].E1 + Target.Elements [ 2 ].E0 * Target.Elements [ 0 ].E1 * Target.Elements [ 3 ].E3 - Target.Elements [ 2 ].E0 * Target.Elements [ 0 ].E3 * Target.Elements [ 3 ].E1 - Target.Elements [ 3 ].E0 * Target.Elements [ 0 ].E1 * Target.Elements [ 2 ].E3 + Target.Elements [ 3 ].E0 * Target.Elements [ 0 ].E3 * Target.Elements [ 2 ].E1;
	Temp.Elements [ 3 ].E1 = + Target.Elements [ 0 ].E0 * Target.Elements [ 2 ].E1 * Target.Elements [ 3 ].E2 - Target.Elements [ 0 ].E0 * Target.Elements [ 2 ].E2 * Target.Elements [ 3 ].E1 - Target.Elements [ 2 ].E0 * Target.Elements [ 0 ].E1 * Target.Elements [ 3 ].E2 + Target.Elements [ 2 ].E0 * Target.Elements [ 0 ].E2 * Target.Elements [ 3 ].E1 + Target.Elements [ 3 ].E0 * Target.Elements [ 0 ].E1 * Target.Elements [ 2 ].E2 - Target.Elements [ 3 ].E0 * Target.Elements [ 0 ].E2 * Target.Elements [ 2 ].E1;
	Temp.Elements [ 0 ].E2 = + Target.Elements [ 0 ].E1 * Target.Elements [ 1 ].E2 * Target.Elements [ 3 ].E3 - Target.Elements [ 0 ].E1 * Target.Elements [ 1 ].E3 * Target.Elements [ 3 ].E2 - Target.Elements [ 1 ].E1 * Target.Elements [ 0 ].E2 * Target.Elements [ 3 ].E3 + Target.Elements [ 1 ].E1 * Target.Elements [ 0 ].E3 * Target.Elements [ 3 ].E2 + Target.Elements [ 3 ].E1 * Target.Elements [ 0 ].E2 * Target.Elements [ 1 ].E3 - Target.Elements [ 3 ].E1 * Target.Elements [ 0 ].E3 * Target.Elements [ 1 ].E2;
	Temp.Elements [ 1 ].E2 = - Target.Elements [ 0 ].E0 * Target.Elements [ 1 ].E2 * Target.Elements [ 3 ].E3 + Target.Elements [ 0 ].E0 * Target.Elements [ 1 ].E3 * Target.Elements [ 3 ].E2 + Target.Elements [ 1 ].E0 * Target.Elements [ 0 ].E2 * Target.Elements [ 3 ].E3 - Target.Elements [ 1 ].E0 * Target.Elements [ 0 ].E3 * Target.Elements [ 3 ].E2 - Target.Elements [ 3 ].E0 * Target.Elements [ 0 ].E2 * Target.Elements [ 1 ].E3 + Target.Elements [ 3 ].E0 * Target.Elements [ 0 ].E3 * Target.Elements [ 1 ].E2;
	Temp.Elements [ 2 ].E2 = + Target.Elements [ 0 ].E0 * Target.Elements [ 1 ].E1 * Target.Elements [ 3 ].E3 - Target.Elements [ 0 ].E0 * Target.Elements [ 1 ].E3 * Target.Elements [ 3 ].E1 - Target.Elements [ 1 ].E0 * Target.Elements [ 0 ].E1 * Target.Elements [ 3 ].E3 + Target.Elements [ 1 ].E0 * Target.Elements [ 0 ].E3 * Target.Elements [ 3 ].E1 + Target.Elements [ 3 ].E0 * Target.Elements [ 0 ].E1 * Target.Elements [ 1 ].E3 - Target.Elements [ 3 ].E0 * Target.Elements [ 0 ].E3 * Target.Elements [ 1 ].E1;
	Temp.Elements [ 3 ].E2 = - Target.Elements [ 0 ].E0 * Target.Elements [ 1 ].E1 * Target.Elements [ 3 ].E2 + Target.Elements [ 0 ].E0 * Target.Elements [ 1 ].E2 * Target.Elements [ 3 ].E1 + Target.Elements [ 1 ].E0 * Target.Elements [ 0 ].E1 * Target.Elements [ 3 ].E2 - Target.Elements [ 1 ].E0 * Target.Elements [ 0 ].E2 * Target.Elements [ 3 ].E1 - Target.Elements [ 3 ].E0 * Target.Elements [ 0 ].E1 * Target.Elements [ 1 ].E2 + Target.Elements [ 3 ].E0 * Target.Elements [ 0 ].E2 * Target.Elements [ 1 ].E1;
	Temp.Elements [ 0 ].E3 = - Target.Elements [ 0 ].E1 * Target.Elements [ 1 ].E2 * Target.Elements [ 2 ].E3 + Target.Elements [ 0 ].E1 * Target.Elements [ 1 ].E3 * Target.Elements [ 2 ].E2 + Target.Elements [ 1 ].E1 * Target.Elements [ 0 ].E2 * Target.Elements [ 2 ].E3 - Target.Elements [ 1 ].E1 * Target.Elements [ 0 ].E3 * Target.Elements [ 2 ].E2 - Target.Elements [ 2 ].E1 * Target.Elements [ 0 ].E2 * Target.Elements [ 1 ].E3 + Target.Elements [ 2 ].E1 * Target.Elements [ 0 ].E3 * Target.Elements [ 1 ].E2;
	Temp.Elements [ 1 ].E3 = + Target.Elements [ 0 ].E0 * Target.Elements [ 1 ].E2 * Target.Elements [ 2 ].E3 - Target.Elements [ 0 ].E0 * Target.Elements [ 1 ].E3 * Target.Elements [ 2 ].E2 - Target.Elements [ 1 ].E0 * Target.Elements [ 0 ].E2 * Target.Elements [ 2 ].E3 + Target.Elements [ 1 ].E0 * Target.Elements [ 0 ].E3 * Target.Elements [ 2 ].E2 + Target.Elements [ 2 ].E0 * Target.Elements [ 0 ].E2 * Target.Elements [ 1 ].E3 - Target.Elements [ 2 ].E0 * Target.Elements [ 0 ].E3 * Target.Elements [ 1 ].E2;
	Temp.Elements [ 2 ].E3 = - Target.Elements [ 0 ].E0 * Target.Elements [ 1 ].E1 * Target.Elements [ 2 ].E3 + Target.Elements [ 0 ].E0 * Target.Elements [ 1 ].E3 * Target.Elements [ 2 ].E1 + Target.Elements [ 1 ].E0 * Target.Elements [ 0 ].E1 * Target.Elements [ 2 ].E3 - Target.Elements [ 1 ].E0 * Target.Elements [ 0 ].E3 * Target.Elements [ 2 ].E1 - Target.Elements [ 2 ].E0 * Target.Elements [ 0 ].E1 * Target.Elements [ 1 ].E3 + Target.Elements [ 2 ].E0 * Target.Elements [ 0 ].E3 * Target.Elements [ 1 ].E1;
	Temp.Elements [ 3 ].E3 = + Target.Elements [ 0 ].E0 * Target.Elements [ 1 ].E1 * Target.Elements [ 2 ].E2 - Target.Elements [ 0 ].E0 * Target.Elements [ 1 ].E2 * Target.Elements [ 2 ].E1 - Target.Elements [ 1 ].E0 * Target.Elements [ 0 ].E1 * Target.Elements [ 2 ].E2 + Target.Elements [ 1 ].E0 * Target.Elements [ 0 ].E2 * Target.Elements [ 2 ].E1 + Target.Elements [ 2 ].E0 * Target.Elements [ 0 ].E1 * Target.Elements [ 1 ].E2 - Target.Elements [ 2 ].E0 * Target.Elements [ 0 ].E2 * Target.Elements [ 1 ].E1;   
	
	float Determinant = Target.Elements [ 0 ].E0 * Temp.Elements [ 0 ].E0 + Target.Elements [ 0 ].E1 * Temp.Elements [ 1 ].E0 + Target.Elements [ 0 ].E2 * Temp.Elements [ 2 ].E0 + Target.Elements [ 0 ].E3 * Temp.Elements [ 3 ].E0;
	
	if ( Determinant == 0.0f )
		return;
	
	Determinant = 1.0f / Determinant;
	
	Copy ( Target, Temp );
	MultiplyScalar ( Target, Determinant );
	
#endif
	
};

bool Xenon::Math::Matrix4x4 :: Invertible ( const Matrix4x4 & Source, float PrecisionThreshold )
{
	
	return fabs ( Determinant ( Source ) ) > PrecisionThreshold;
	
};

void Xenon::Math::Matrix4x4 :: Invert ( Matrix4x4 & Target, const Matrix4x4 & Source )
{
	
#ifdef XENON_SSE
	
	Matrix4x4 Temporary ( NO_INIT );
	
	Transpose ( Temporary, Source );
	
	__m128 V00 = _mm_shuffle_ps ( Temporary.Elements [ 2 ].SSEV, Temporary.Elements [ 2 ].SSEV, _MM_SHUFFLE ( 1, 1, 0, 0 ) );
	__m128 V10 = _mm_shuffle_ps ( Temporary.Elements [ 3 ].SSEV, Temporary.Elements [ 3 ].SSEV, _MM_SHUFFLE ( 3, 2, 3, 2 ) );
	__m128 V01 = _mm_shuffle_ps ( Temporary.Elements [ 0 ].SSEV, Temporary.Elements [ 0 ].SSEV, _MM_SHUFFLE ( 1, 1, 0, 0 ) );
	__m128 V11 = _mm_shuffle_ps ( Temporary.Elements [ 1 ].SSEV, Temporary.Elements [ 1 ].SSEV, _MM_SHUFFLE ( 3, 2, 3, 2 ) );
	__m128 V02 = _mm_shuffle_ps ( Temporary.Elements [ 2 ].SSEV, Temporary.Elements [ 0 ].SSEV, _MM_SHUFFLE ( 2, 0, 2, 0 ) );
	__m128 V12 = _mm_shuffle_ps ( Temporary.Elements [ 3 ].SSEV, Temporary.Elements [ 1 ].SSEV, _MM_SHUFFLE ( 3, 1, 3, 1 ) );
	
	__m128 D0 = _mm_mul_ps ( V00, V10 );
	__m128 D1 = _mm_mul_ps ( V01, V11 );
	__m128 D2 = _mm_mul_ps ( V02, V12 );
	
	V00 = _mm_shuffle_ps ( Temporary.Elements [ 2 ].SSEV, Temporary.Elements [ 2 ].SSEV, _MM_SHUFFLE ( 3, 2, 3, 2 ) );
	V10 = _mm_shuffle_ps ( Temporary.Elements [ 3 ].SSEV, Temporary.Elements [ 3 ].SSEV, _MM_SHUFFLE ( 1, 1, 0, 0 ) );
	V01 = _mm_shuffle_ps ( Temporary.Elements [ 0 ].SSEV, Temporary.Elements [ 0 ].SSEV, _MM_SHUFFLE ( 3, 2, 3, 2 ) );
	V11 = _mm_shuffle_ps ( Temporary.Elements [ 1 ].SSEV, Temporary.Elements [ 1 ].SSEV, _MM_SHUFFLE ( 1, 1, 0, 0 ) );
	V02 = _mm_shuffle_ps ( Temporary.Elements [ 2 ].SSEV, Temporary.Elements [ 0 ].SSEV, _MM_SHUFFLE ( 3, 1, 3, 1 ) );
	V12 = _mm_shuffle_ps ( Temporary.Elements [ 3 ].SSEV, Temporary.Elements [ 1 ].SSEV, _MM_SHUFFLE ( 2, 0, 2, 0 ) );
	
	V00 = _mm_mul_ps ( V00, V10 );
	V01 = _mm_mul_ps ( V01, V11 );
	V02 = _mm_mul_ps ( V02, V12 );
	D0 = _mm_sub_ps ( D0, V00 );
	D1 = _mm_sub_ps ( D1, V01 );
	D2 = _mm_sub_ps ( D2, V02 );
	V11 = _mm_shuffle_ps ( D0, D2, _MM_SHUFFLE ( 1, 1, 3, 1 ) );
	V00 = _mm_shuffle_ps ( Temporary.Elements [ 1 ].SSEV, Temporary.Elements [ 1 ].SSEV, _MM_SHUFFLE ( 1, 0, 2, 1 ) );
	V10 = _mm_shuffle_ps ( V11, D0, _MM_SHUFFLE ( 0, 3, 0, 2 ) );
	V01 = _mm_shuffle_ps ( Temporary.Elements [ 0 ].SSEV, Temporary.Elements [ 0 ].SSEV, _MM_SHUFFLE ( 0, 1, 0, 2 ) );
	V11 = _mm_shuffle_ps ( V11, D0, _MM_SHUFFLE ( 2, 1, 2, 1 ) );
	__m128 V13 = _mm_shuffle_ps ( D1, D2, _MM_SHUFFLE ( 3, 3, 3, 1 ) );
	V02 = _mm_shuffle_ps ( Temporary.Elements [ 3 ].SSEV, Temporary.Elements [ 3 ].SSEV, _MM_SHUFFLE ( 1, 0, 2, 1 ) );
	V12 = _mm_shuffle_ps ( V13, D1, _MM_SHUFFLE ( 0, 3, 0, 2 ) );
	__m128 V03 = _mm_shuffle_ps ( Temporary.Elements [ 2 ].SSEV, Temporary.Elements [ 2 ].SSEV, _MM_SHUFFLE ( 0, 1, 0, 2 ) );
	V13 = _mm_shuffle_ps ( V13, D1, _MM_SHUFFLE ( 2, 1, 2, 1 ) );
	
	__m128 C0 = _mm_mul_ps ( V00, V10 );
	__m128 C2 = _mm_mul_ps ( V01, V11 );
	__m128 C4 = _mm_mul_ps ( V02, V12 );
	__m128 C6 = _mm_mul_ps ( V03, V13 );
	
	V11 = _mm_shuffle_ps ( D0, D2, _MM_SHUFFLE ( 0, 0, 1, 0 ) );
	V00 = _mm_shuffle_ps ( Temporary.Elements [ 1 ].SSEV, Temporary.Elements [ 1 ].SSEV, _MM_SHUFFLE ( 2, 1, 3, 2 ) );
	V10 = _mm_shuffle_ps ( D0, V11, _MM_SHUFFLE ( 2, 1, 0, 3 ) );
	V01 = _mm_shuffle_ps ( Temporary.Elements [ 0 ].SSEV, Temporary.Elements [ 0 ].SSEV, _MM_SHUFFLE ( 1, 3, 2, 3 ) );
	V11 = _mm_shuffle_ps ( D0, V11, _MM_SHUFFLE ( 0, 2, 1, 2 ) );
	V13 = _mm_shuffle_ps ( D1, D2, _MM_SHUFFLE ( 2, 2, 1, 0 ) );
	V02 = _mm_shuffle_ps ( Temporary.Elements [ 3 ].SSEV, Temporary.Elements [ 3 ].SSEV, _MM_SHUFFLE ( 2, 1, 3, 2 ) );
	V12 = _mm_shuffle_ps ( D1, V13, _MM_SHUFFLE ( 2, 1, 0, 3 ) );
	V03 = _mm_shuffle_ps ( Temporary.Elements [ 2 ].SSEV, Temporary.Elements [ 2 ].SSEV, _MM_SHUFFLE ( 1, 3, 2, 3 ) );
	V13 = _mm_shuffle_ps ( D1, V13, _MM_SHUFFLE ( 0, 2, 1, 2 ) );
	
	V00 = _mm_mul_ps ( V00, V10 );
	V01 = _mm_mul_ps ( V01, V11 );
	V02 = _mm_mul_ps ( V02, V12 );
	V03 = _mm_mul_ps ( V03, V13 );
	C0 = _mm_sub_ps ( C0, V00 );
	C2 = _mm_sub_ps ( C2, V01 );
	C4 = _mm_sub_ps ( C4, V02 );
	C6 = _mm_sub_ps ( C6, V03 );
	
	V00 = _mm_shuffle_ps ( Temporary.Elements [ 1 ].SSEV, Temporary.Elements [ 1 ].SSEV, _MM_SHUFFLE ( 0, 3, 0, 3 ) );
	V10 = _mm_shuffle_ps ( D0, D2, _MM_SHUFFLE ( 1, 0, 2, 2 ) );
	V10 = _mm_shuffle_ps ( V10, V10, _MM_SHUFFLE ( 0, 2, 3, 0 ) );
	V01 = _mm_shuffle_ps ( Temporary.Elements [ 0 ].SSEV, Temporary.Elements [ 0 ].SSEV, _MM_SHUFFLE ( 2, 0, 3, 1 ) );
	V11 = _mm_shuffle_ps ( D0, D2, _MM_SHUFFLE ( 1, 0, 3, 0 ) );
	V11 = _mm_shuffle_ps ( V11, V11, _MM_SHUFFLE ( 2, 1, 0, 3 ) );
	V02 = _mm_shuffle_ps ( Temporary.Elements [ 3 ].SSEV, Temporary.Elements [ 3 ].SSEV, _MM_SHUFFLE ( 0, 3, 0, 3 ) );
	V12 = _mm_shuffle_ps ( D1, D2, _MM_SHUFFLE ( 3, 2, 2, 2 ) );
	V12 = _mm_shuffle_ps ( V12, V12, _MM_SHUFFLE ( 0, 2, 3, 0 ) );
	V03 = _mm_shuffle_ps ( Temporary.Elements [ 2 ].SSEV, Temporary.Elements [ 2 ].SSEV, _MM_SHUFFLE ( 2, 0, 3, 1 ) );
	V13 = _mm_shuffle_ps ( D1, D2, _MM_SHUFFLE ( 3, 2, 3, 0 ) );
	V13 = _mm_shuffle_ps ( V13, V13, _MM_SHUFFLE ( 2, 1, 0, 3 ) );
	
	V00 = _mm_mul_ps ( V00, V10 );
	V01 = _mm_mul_ps ( V01, V11 );
	V02 = _mm_mul_ps ( V02, V12 );
	V03 = _mm_mul_ps ( V03, V13 );
	
	__m128 C1 = _mm_sub_ps ( C0, V00 );
	C0 = _mm_add_ps ( C0, V00 );
	__m128 C3 = _mm_add_ps ( C2, V01 );
	C2 = _mm_sub_ps ( C2, V01 );
	__m128 C5 = _mm_sub_ps ( C4,V02 );
	C4 = _mm_add_ps ( C4,V02 );
	__m128 C7 = _mm_add_ps ( C6,V03 );
	C6 = _mm_sub_ps ( C6,V03 );
	
	C0 = _mm_shuffle_ps ( C0, C1, _MM_SHUFFLE ( 3, 1, 2, 0 ) );
	C2 = _mm_shuffle_ps ( C2, C3, _MM_SHUFFLE ( 3, 1, 2, 0 ) );
	C4 = _mm_shuffle_ps ( C4, C5, _MM_SHUFFLE ( 3, 1, 2, 0 ) );
	C6 = _mm_shuffle_ps ( C6, C7, _MM_SHUFFLE ( 3, 1, 2, 0 ) );
	C0 = _mm_shuffle_ps ( C0, C0, _MM_SHUFFLE ( 3, 1, 2, 0 ) );
	C2 = _mm_shuffle_ps ( C2, C2, _MM_SHUFFLE ( 3, 1, 2, 0 ) );
	C4 = _mm_shuffle_ps ( C4, C4, _MM_SHUFFLE ( 3, 1, 2, 0 ) );
	C6 = _mm_shuffle_ps ( C6, C6, _MM_SHUFFLE ( 3, 1, 2, 0 ) );
	
	__m128 vTemp = _mm_dp_ps ( C0, Temporary.Elements [ 0 ].SSEV, 0xFF );
	
	vTemp = _mm_div_ps ( _mm_set1_ps ( 1.0f ), vTemp );
	
	Target.Elements [ 0 ].SSEV = _mm_mul_ps ( C0, vTemp );
	Target.Elements [ 1 ].SSEV = _mm_mul_ps ( C2, vTemp );
	Target.Elements [ 2 ].SSEV = _mm_mul_ps ( C4, vTemp );
	Target.Elements [ 3 ].SSEV = _mm_mul_ps ( C6, vTemp );
	
#else
	
	// Thanks, glut
	
	Matrix4x4 Temp ( NO_INIT );
	
	Temp.Elements [ 0 ].E0 = + Source.Elements [ 1 ].E1 * Source.Elements [ 2 ].E2 * Source.Elements [ 3 ].E3 - Source.Elements [ 1 ].E1 * Source.Elements [ 2 ].E3 * Source.Elements [ 3 ].E2 - Source.Elements [ 2 ].E1 * Source.Elements [ 1 ].E2 * Source.Elements [ 3 ].E3 + Source.Elements [ 2 ].E1 * Source.Elements [ 1 ].E3 * Source.Elements [ 3 ].E2 + Source.Elements [ 3 ].E1 * Source.Elements [ 1 ].E2 * Source.Elements [ 2 ].E3 - Source.Elements [ 3 ].E1 * Source.Elements [ 1 ].E3 * Source.Elements [ 2 ].E2;
	Temp.Elements [ 1 ].E0 = - Source.Elements [ 1 ].E0 * Source.Elements [ 2 ].E2 * Source.Elements [ 3 ].E3 + Source.Elements [ 1 ].E0 * Source.Elements [ 2 ].E3 * Source.Elements [ 3 ].E2 + Source.Elements [ 2 ].E0 * Source.Elements [ 1 ].E2 * Source.Elements [ 3 ].E3 - Source.Elements [ 2 ].E0 * Source.Elements [ 1 ].E3 * Source.Elements [ 3 ].E2 - Source.Elements [ 3 ].E0 * Source.Elements [ 1 ].E2 * Source.Elements [ 2 ].E3 + Source.Elements [ 3 ].E0 * Source.Elements [ 1 ].E3 * Source.Elements [ 2 ].E2;
	Temp.Elements [ 2 ].E0 = + Source.Elements [ 1 ].E0 * Source.Elements [ 2 ].E1 * Source.Elements [ 3 ].E3 - Source.Elements [ 1 ].E0 * Source.Elements [ 2 ].E3 * Source.Elements [ 3 ].E1 - Source.Elements [ 2 ].E0 * Source.Elements [ 1 ].E1 * Source.Elements [ 3 ].E3 + Source.Elements [ 2 ].E0 * Source.Elements [ 1 ].E3 * Source.Elements [ 3 ].E1 + Source.Elements [ 3 ].E0 * Source.Elements [ 1 ].E1 * Source.Elements [ 2 ].E3 - Source.Elements [ 3 ].E0 * Source.Elements [ 1 ].E3 * Source.Elements [ 2 ].E1;
	Temp.Elements [ 3 ].E0 = - Source.Elements [ 1 ].E0 * Source.Elements [ 2 ].E1 * Source.Elements [ 3 ].E2 + Source.Elements [ 1 ].E0 * Source.Elements [ 2 ].E2 * Source.Elements [ 3 ].E1 + Source.Elements [ 2 ].E0 * Source.Elements [ 1 ].E1 * Source.Elements [ 3 ].E2 - Source.Elements [ 2 ].E0 * Source.Elements [ 1 ].E2 * Source.Elements [ 3 ].E1 - Source.Elements [ 3 ].E0 * Source.Elements [ 1 ].E1 * Source.Elements [ 2 ].E2 + Source.Elements [ 3 ].E0 * Source.Elements [ 1 ].E2 * Source.Elements [ 2 ].E1;
	Temp.Elements [ 0 ].E1 = - Source.Elements [ 0 ].E1 * Source.Elements [ 2 ].E2 * Source.Elements [ 3 ].E3 + Source.Elements [ 0 ].E1 * Source.Elements [ 2 ].E3 * Source.Elements [ 3 ].E2 + Source.Elements [ 2 ].E1 * Source.Elements [ 0 ].E2 * Source.Elements [ 3 ].E3 - Source.Elements [ 2 ].E1 * Source.Elements [ 0 ].E3 * Source.Elements [ 3 ].E2 - Source.Elements [ 3 ].E1 * Source.Elements [ 0 ].E2 * Source.Elements [ 2 ].E3 + Source.Elements [ 3 ].E1 * Source.Elements [ 0 ].E3 * Source.Elements [ 2 ].E2;
	Temp.Elements [ 1 ].E1 = + Source.Elements [ 0 ].E0 * Source.Elements [ 2 ].E2 * Source.Elements [ 3 ].E3 - Source.Elements [ 0 ].E0 * Source.Elements [ 2 ].E3 * Source.Elements [ 3 ].E2 - Source.Elements [ 2 ].E0 * Source.Elements [ 0 ].E2 * Source.Elements [ 3 ].E3 + Source.Elements [ 2 ].E0 * Source.Elements [ 0 ].E3 * Source.Elements [ 3 ].E2 + Source.Elements [ 3 ].E0 * Source.Elements [ 0 ].E2 * Source.Elements [ 2 ].E3 - Source.Elements [ 3 ].E0 * Source.Elements [ 0 ].E3 * Source.Elements [ 2 ].E2;
	Temp.Elements [ 2 ].E1 = - Source.Elements [ 0 ].E0 * Source.Elements [ 2 ].E1 * Source.Elements [ 3 ].E3 + Source.Elements [ 0 ].E0 * Source.Elements [ 2 ].E3 * Source.Elements [ 3 ].E1 + Source.Elements [ 2 ].E0 * Source.Elements [ 0 ].E1 * Source.Elements [ 3 ].E3 - Source.Elements [ 2 ].E0 * Source.Elements [ 0 ].E3 * Source.Elements [ 3 ].E1 - Source.Elements [ 3 ].E0 * Source.Elements [ 0 ].E1 * Source.Elements [ 2 ].E3 + Source.Elements [ 3 ].E0 * Source.Elements [ 0 ].E3 * Source.Elements [ 2 ].E1;
	Temp.Elements [ 3 ].E1 = + Source.Elements [ 0 ].E0 * Source.Elements [ 2 ].E1 * Source.Elements [ 3 ].E2 - Source.Elements [ 0 ].E0 * Source.Elements [ 2 ].E2 * Source.Elements [ 3 ].E1 - Source.Elements [ 2 ].E0 * Source.Elements [ 0 ].E1 * Source.Elements [ 3 ].E2 + Source.Elements [ 2 ].E0 * Source.Elements [ 0 ].E2 * Source.Elements [ 3 ].E1 + Source.Elements [ 3 ].E0 * Source.Elements [ 0 ].E1 * Source.Elements [ 2 ].E2 - Source.Elements [ 3 ].E0 * Source.Elements [ 0 ].E2 * Source.Elements [ 2 ].E1;
	Temp.Elements [ 0 ].E2 = + Source.Elements [ 0 ].E1 * Source.Elements [ 1 ].E2 * Source.Elements [ 3 ].E3 - Source.Elements [ 0 ].E1 * Source.Elements [ 1 ].E3 * Source.Elements [ 3 ].E2 - Source.Elements [ 1 ].E1 * Source.Elements [ 0 ].E2 * Source.Elements [ 3 ].E3 + Source.Elements [ 1 ].E1 * Source.Elements [ 0 ].E3 * Source.Elements [ 3 ].E2 + Source.Elements [ 3 ].E1 * Source.Elements [ 0 ].E2 * Source.Elements [ 1 ].E3 - Source.Elements [ 3 ].E1 * Source.Elements [ 0 ].E3 * Source.Elements [ 1 ].E2;
	Temp.Elements [ 1 ].E2 = - Source.Elements [ 0 ].E0 * Source.Elements [ 1 ].E2 * Source.Elements [ 3 ].E3 + Source.Elements [ 0 ].E0 * Source.Elements [ 1 ].E3 * Source.Elements [ 3 ].E2 + Source.Elements [ 1 ].E0 * Source.Elements [ 0 ].E2 * Source.Elements [ 3 ].E3 - Source.Elements [ 1 ].E0 * Source.Elements [ 0 ].E3 * Source.Elements [ 3 ].E2 - Source.Elements [ 3 ].E0 * Source.Elements [ 0 ].E2 * Source.Elements [ 1 ].E3 + Source.Elements [ 3 ].E0 * Source.Elements [ 0 ].E3 * Source.Elements [ 1 ].E2;
	Temp.Elements [ 2 ].E2 = + Source.Elements [ 0 ].E0 * Source.Elements [ 1 ].E1 * Source.Elements [ 3 ].E3 - Source.Elements [ 0 ].E0 * Source.Elements [ 1 ].E3 * Source.Elements [ 3 ].E1 - Source.Elements [ 1 ].E0 * Source.Elements [ 0 ].E1 * Source.Elements [ 3 ].E3 + Source.Elements [ 1 ].E0 * Source.Elements [ 0 ].E3 * Source.Elements [ 3 ].E1 + Source.Elements [ 3 ].E0 * Source.Elements [ 0 ].E1 * Source.Elements [ 1 ].E3 - Source.Elements [ 3 ].E0 * Source.Elements [ 0 ].E3 * Source.Elements [ 1 ].E1;
	Temp.Elements [ 3 ].E2 = - Source.Elements [ 0 ].E0 * Source.Elements [ 1 ].E1 * Source.Elements [ 3 ].E2 + Source.Elements [ 0 ].E0 * Source.Elements [ 1 ].E2 * Source.Elements [ 3 ].E1 + Source.Elements [ 1 ].E0 * Source.Elements [ 0 ].E1 * Source.Elements [ 3 ].E2 - Source.Elements [ 1 ].E0 * Source.Elements [ 0 ].E2 * Source.Elements [ 3 ].E1 - Source.Elements [ 3 ].E0 * Source.Elements [ 0 ].E1 * Source.Elements [ 1 ].E2 + Source.Elements [ 3 ].E0 * Source.Elements [ 0 ].E2 * Source.Elements [ 1 ].E1;
	Temp.Elements [ 0 ].E3 = - Source.Elements [ 0 ].E1 * Source.Elements [ 1 ].E2 * Source.Elements [ 2 ].E3 + Source.Elements [ 0 ].E1 * Source.Elements [ 1 ].E3 * Source.Elements [ 2 ].E2 + Source.Elements [ 1 ].E1 * Source.Elements [ 0 ].E2 * Source.Elements [ 2 ].E3 - Source.Elements [ 1 ].E1 * Source.Elements [ 0 ].E3 * Source.Elements [ 2 ].E2 - Source.Elements [ 2 ].E1 * Source.Elements [ 0 ].E2 * Source.Elements [ 1 ].E3 + Source.Elements [ 2 ].E1 * Source.Elements [ 0 ].E3 * Source.Elements [ 1 ].E2;
	Temp.Elements [ 1 ].E3 = + Source.Elements [ 0 ].E0 * Source.Elements [ 1 ].E2 * Source.Elements [ 2 ].E3 - Source.Elements [ 0 ].E0 * Source.Elements [ 1 ].E3 * Source.Elements [ 2 ].E2 - Source.Elements [ 1 ].E0 * Source.Elements [ 0 ].E2 * Source.Elements [ 2 ].E3 + Source.Elements [ 1 ].E0 * Source.Elements [ 0 ].E3 * Source.Elements [ 2 ].E2 + Source.Elements [ 2 ].E0 * Source.Elements [ 0 ].E2 * Source.Elements [ 1 ].E3 - Source.Elements [ 2 ].E0 * Source.Elements [ 0 ].E3 * Source.Elements [ 1 ].E2;
	Temp.Elements [ 2 ].E3 = - Source.Elements [ 0 ].E0 * Source.Elements [ 1 ].E1 * Source.Elements [ 2 ].E3 + Source.Elements [ 0 ].E0 * Source.Elements [ 1 ].E3 * Source.Elements [ 2 ].E1 + Source.Elements [ 1 ].E0 * Source.Elements [ 0 ].E1 * Source.Elements [ 2 ].E3 - Source.Elements [ 1 ].E0 * Source.Elements [ 0 ].E3 * Source.Elements [ 2 ].E1 - Source.Elements [ 2 ].E0 * Source.Elements [ 0 ].E1 * Source.Elements [ 1 ].E3 + Source.Elements [ 2 ].E0 * Source.Elements [ 0 ].E3 * Source.Elements [ 1 ].E1;
	Temp.Elements [ 3 ].E3 = + Source.Elements [ 0 ].E0 * Source.Elements [ 1 ].E1 * Source.Elements [ 2 ].E2 - Source.Elements [ 0 ].E0 * Source.Elements [ 1 ].E2 * Source.Elements [ 2 ].E1 - Source.Elements [ 1 ].E0 * Source.Elements [ 0 ].E1 * Source.Elements [ 2 ].E2 + Source.Elements [ 1 ].E0 * Source.Elements [ 0 ].E2 * Source.Elements [ 2 ].E1 + Source.Elements [ 2 ].E0 * Source.Elements [ 0 ].E1 * Source.Elements [ 1 ].E2 - Source.Elements [ 2 ].E0 * Source.Elements [ 0 ].E2 * Source.Elements [ 1 ].E1;   
	
	float Determinant = Source.Elements [ 0 ].E0 * Temp.Elements [ 0 ].E0 + Source.Elements [ 0 ].E1 * Temp.Elements [ 1 ].E0 + Source.Elements [ 0 ].E2 * Temp.Elements [ 2 ].E0 + Source.Elements [ 0 ].E3 * Temp.Elements [ 3 ].E0;
	
	if ( Determinant == 0.0f )
		return;
	
	Determinant = 1.0f / Determinant;
	
	Copy ( Target, Temp );
	MultiplyScalar ( Target, Determinant );
	
#endif
	
};
