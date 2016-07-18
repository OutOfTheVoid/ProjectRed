#include <Xenon/Math/Vec4.h>
#include <Xenon/Math/Vec3.h>

#include <math.h>
#include <string.h>

Xenon::Math::Vec4 :: Vec4 ( float X, float Y, float Z, float W ):
#ifdef XENON_SSE
	SSEV ( _mm_setr_ps ( X, Y, Z, W ) )
#else
	X ( X ),
	Y ( Y ),
	Z ( Z ),
	W ( W )
#endif
{
};

Xenon::Math::Vec4 :: Vec4 ( Vec3 & XYZ, float W ):
#ifdef XENON_SSE
	SSEV ( _mm_setr_ps ( XYZ.X, XYZ.Y, XYZ.Z, W ) )
#else
	X ( XYZ.X ),
	Y ( XYZ.Y ),
	Z ( XYZ.Z ),
	W ( W )
#endif
{	
};

Xenon::Math::Vec4 :: Vec4 ( const Vec4 & CopyFrom )
{
	
	Copy ( CopyFrom, * this );
	
}

#ifdef XENON_SSE
Xenon::Math::Vec4 :: Vec4 ( __m128 SSEV ):
	SSEV ( SSEV )
{
}
#endif

Xenon::Math::Vec4 :: Vec4 ( NoInit NO_INIT )
{
};

Xenon::Math::Vec4 :: ~Vec4 ()
{
};

void Xenon::Math::Vec4 :: Copy ( const Vec4 & Source, Vec4 & Destination )
{
	
	memcpy ( & Destination, & Source, sizeof ( Vec4 ) );
	
};

float Xenon::Math::Vec4 :: DotProduct ( const Vec4 & A, const Vec4 & B )
{
	
#ifdef XENON_SSE4_1
	
	Vec4 Temp = _mm_dp_ps ( A.SSEV, B.SSEV, 0xFF );
	return Temp.X;
	
#else
	
	return A.X * B.X + A.Y * B.Y + A.Z * B.Z + A.W * B.W;
	
#endif
	
};

void Xenon::Math::Vec4 :: Multiply ( Vec4 & A, float B )
{
	
#ifdef XENON_SSE
	
	A.SSEV = _mm_mul_ps ( A.SSEV, _mm_set1_ps ( B ) );
	
#else
	
	A.X *= B;
	A.Y *= B;
	A.Z *= B;
	A.W *= B;
	
#endif
	
};

void Xenon::Math::Vec4 :: Multiply ( const Vec4 & A, float B, Vec4 & Result )
{
	
#ifdef XENON_SSE
	
	Result.SSEV = _mm_mul_ps ( A.SSEV, _mm_set1_ps ( B ) );
	
#else
	
	Result.X = A.X * B;
	Result.Y = A.Y * B;
	Result.Z = A.Z * B;
	Result.W = A.W * B;
	
#endif
	
};

void Xenon::Math::Vec4 :: Add ( const Vec4 & A, const Vec4 & B, Vec4 & Result )
{
	
#ifdef XENON_SSE
	
	Result.SSEV = _mm_add_ps ( A.SSEV, B.SSEV );
	
#else
	
	Result.X = A.X + B.X;
	Result.Y = A.Y + B.Y;
	Result.Z = A.Z + B.Z;
	Result.W = A.W + B.W;
	
#endif
	
};

void Xenon::Math::Vec4 :: Add ( Vec4 & A, const Vec4 & B )
{
	
#ifdef XENON_SSE
	
	A.SSEV = _mm_add_ps ( A.SSEV, B.SSEV );
	
#else
	
	A.X += B.X;
	A.Y += B.Y;
	A.Z += B.Z;
	A.W += B.W;
	
#endif
	
};

void Xenon::Math::Vec4 :: Subtract ( const Vec4 & A, const Vec4 & B, Vec4 & Result )
{
	
#ifdef XENON_SSE
	
	Result.SSEV = _mm_sub_ps ( A.SSEV, B.SSEV );
	
#else
	
	Result.X = A.X - B.X;
	Result.Y = A.Y - B.Y;
	Result.Z = A.Z - B.Z;
	Result.W = A.W - B.W;
	
#endif
	
};

void Xenon::Math::Vec4 :: Subtract ( Vec4 & A, const Vec4 & B )
{
	
#ifdef XENON_SSE
	
	A.SSEV = _mm_sub_ps ( A.SSEV, B.SSEV );
	
#else
	
	A.X -= B.X;
	A.Y -= B.Y;
	A.Z -= B.Z;
	A.W -= B.W;
	
#endif
	
};

void Xenon::Math::Vec4 :: Normalize ( Vec4 & A )
{
	
#ifdef XENON_SSE4_1
	
	A.SSEV = _mm_div_ps ( A.SSEV, _mm_sqrt_ps ( _mm_dp_ps ( A.SSEV, A.SSEV, 0xFF ) ) );
	
#else
	
	Multiply ( A, 1.0 / Length ( A ) );
	
#endif
	
};

void Xenon::Math::Vec4 :: Normalize ( const Vec4 & A, Vec4 & Result )
{
	
#ifdef XENON_SSE4_1
	
	Result.SSEV = _mm_div_ps ( A.SSEV, _mm_sqrt_ps ( _mm_dp_ps ( A.SSEV, A.SSEV, 0xFF ) ) );
	
#else
	
	Multiply ( A, 1.0 / Length ( A ), Result );
	
#endif
	
};

float Xenon::Math::Vec4 :: Length ( const Vec4 & A )
{
	
#ifdef XENON_SSE4_1
	
	Vec4 Temp ( _mm_sqrt_ps ( _mm_dp_ps ( A.SSEV, A.SSEV, 0xFF ) ) );
	return Temp.X;
	
#else
	
	return sqrt ( A.X * A.X + A.Y * A.Y + A.Z * A.Z + A.W * A.W );
	
#endif
	
};

float Xenon::Math::Vec4 :: LengthSquared ( const Vec4 & A )
{
	
#ifdef XENON_SSE4_1
	
	Vec4 Temp ( _mm_dp_ps ( A.SSEV, A.SSEV, 0xFF ) );
	return Temp.X;
	
#else
	
	return A.X * A.X + A.Y * A.Y + A.Z * A.Z + A.W * A.W;
	
#endif
	
};

float Xenon::Math::Vec4 :: AngleBetween ( const Vec4 & A, const Vec4 & B )
{
	
#ifdef XENON_SSE4_1
	
	Vec4 Temp = _mm_div_ps ( _mm_dp_ps ( A.SSEV, B.SSEV, 0xFF ), _mm_sqrt_ps ( _mm_mul_ps ( _mm_dp_ps ( A.SSEV, A.SSEV, 0xFF ), _mm_dp_ps ( B.SSEV, B.SSEV, 0xFF ) ) ) );
	
#else
	
	return acos ( DotProduct ( A, B ) / sqrt ( LengthSquared ( A ) * LengthSquared ( B ) ) );
	
#endif
	
};

void Xenon::Math::Vec4 :: Interpolate ( Vec4 & A, const Vec4 & B, float Fraction )
{
	
#ifdef XENON_SSE
	
	float OppositeFraction = 1.0f - Fraction;
	
	A.SSEV = _mm_add_ps ( _mm_mul_ps ( A.SSEV, _mm_set1_ps ( Fraction ) ), _mm_mul_ps ( B.SSEV, _mm_set1_ps ( OppositeFraction ) ) );
	
#else
	
	Vec4 Temp;
	
	Multiply ( A, Fraction );
	Multiply ( B, 1.0f - Fraction, Temp );
	
	Add ( A, Temp );
	
#endif
	
};

void Xenon::Math::Vec4 :: Interpolate ( const Vec4 & A, const Vec4 & B, float Fraction, Vec4 & Result )
{
	
	Vec4 Temp;
	
	Multiply ( Result, Fraction );
	Multiply ( B, 1.0f - Fraction, Temp );
	
	Add ( Result, Temp );
	
};
