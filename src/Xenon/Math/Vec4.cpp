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
	
	Copy ( * this, CopyFrom );
	
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

void Xenon::Math::Vec4 :: Copy ( Vec4 & Target, const Vec4 & Source )
{
	
	memcpy ( & Target, & Source, sizeof ( Vec4 ) );
	
};

float Xenon::Math::Vec4 :: DotProduct ( const Vec4 & SourceA, const Vec4 & SourceB )
{
	
#ifdef XENON_SSE4_1
	
	Vec4 Temp = _mm_dp_ps ( SourceA.SSEV, SourceB.SSEV, 0xFF );
	return Temp.X;
	
#else
	
	return SourceA.X * SourceB.X + SourceA.Y * SourceB.Y + SourceA.Z * SourceB.Z + SourceA.W * SourceB.W;
	
#endif
	
};

void Xenon::Math::Vec4 :: Multiply ( Vec4 & Target, float Scalar )
{
	
#ifdef XENON_SSE
	
	Target.SSEV = _mm_mul_ps ( Target.SSEV, _mm_set1_ps ( Scalar ) );
	
#else
	
	Target.X *= Scalar;
	Target.Y *= Scalar;
	Target.Z *= Scalar;
	Target.W *= Scalar;
	
#endif
	
};

void Xenon::Math::Vec4 :: Multiply ( Vec4 & Target, const Vec4 & Source, float Scalar )
{
	
#ifdef XENON_SSE
	
	Target.SSEV = _mm_mul_ps ( Source.SSEV, _mm_set1_ps ( Scalar ) );
	
#else
	
	Target.X = Source.X * Scalar;
	Target.Y = Source.Y * Scalar;
	Target.Z = Source.Z * Scalar;
	Target.W = Source.W * Scalar;
	
#endif
	
};

void Xenon::Math::Vec4 :: Add ( Vec4 & Target, const Vec4 & SourceA, const Vec4 & SourceB )
{
	
#ifdef XENON_SSE
	
	Target.SSEV = _mm_add_ps ( SourceA.SSEV, SourceB.SSEV );
	
#else
	
	Target.X = SourceA.X + SourceB.X;
	Target.Y = SourceA.Y + SourceB.Y;
	Target.Z = SourceA.Z + SourceB.Z;
	Target.W = SourceA.W + BSourceB.W;
	
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

void Xenon::Math::Vec4 :: Subtract ( Vec4 & Target, const Vec4 & SourceA, const Vec4 & SourceB )
{
	
#ifdef XENON_SSE
	
	Target.SSEV = _mm_sub_ps ( SourceA.SSEV, SourceB.SSEV );
	
#else
	
	Target.X = SourceA.X - SourceB.X;
	Target.Y = SourceA.Y - SourceB.Y;
	Target.Z = SourceA.Z - SourceB.Z;
	Target.W = SourceA.W - SourceB.W;
	
#endif
	
};

void Xenon::Math::Vec4 :: Subtract ( Vec4 & Target, const Vec4 & Source )
{
	
#ifdef XENON_SSE
	
	Target.SSEV = _mm_sub_ps ( Target.SSEV, Source.SSEV );
	
#else
	
	Target.X -= Source.X;
	Target.Y -= Source.Y;
	Target.Z -= Source.Z;
	Target.W -= Source.W;
	
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

void Xenon::Math::Vec4 :: Normalize ( Vec4 & Target, const Vec4 & Source )
{
	
#ifdef XENON_SSE4_1
	
	Target.SSEV = _mm_div_ps ( Source.SSEV, _mm_sqrt_ps ( _mm_dp_ps ( Source.SSEV, Source.SSEV, 0xFF ) ) );
	
#else
	
	Multiply ( Source, 1.0 / Length ( Source ), Target );
	
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

void Xenon::Math::Vec4 :: Interpolate ( Vec4 & Target, const Vec4 & Source, float Fraction )
{
	
#ifdef XENON_SSE
	
	float OppositeFraction = 1.0f - Fraction;
	
	Target.SSEV = _mm_add_ps ( _mm_mul_ps ( Target.SSEV, _mm_set1_ps ( Fraction ) ), _mm_mul_ps ( Source.SSEV, _mm_set1_ps ( OppositeFraction ) ) );
	
#else
	
	Vec4 Temp;
	
	Multiply ( Target, Fraction );
	Multiply ( Source, 1.0f - Fraction, Temp );
	
	Add ( Target, Temp );
	
#endif
	
};

void Xenon::Math::Vec4 :: Interpolate ( Vec4 & Target, const Vec4 & SourceA, const Vec4 & SourceB, float Fraction )
{
	
	Vec4 Temp;
	
	Multiply ( Target, SourceA, Fraction );
	Multiply ( Temp, SourceB, 1.0f - Fraction );
	
	Add ( Target, Temp );
	
};

void Xenon::Math::Vec4 :: Project ( Vec4 & Target, const Vec4 & Direction )
{
	
	Multiply ( Target, Direction, DotProduct ( Target, Direction ) / LengthSquared ( Direction ) );
	
};

void Xenon::Math::Vec4 :: Project ( Vec4 & Target, const Vec4 & Projected, const Vec4 & Direction )
{
	
	Multiply ( Target, Direction, DotProduct ( Projected, Direction ) / LengthSquared ( Direction ) );
	
};
