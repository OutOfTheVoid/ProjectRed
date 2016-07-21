#include <Xenon/Math/Vec4.h>
#include <Xenon/Math/Vec3.h>

#include <math.h>
#include <string.h>

Xenon::Math::Vec4 :: Vec4 ( float X, float Y, float Z, float W ):
	X ( X ),
	Y ( Y ),
	Z ( Z ),
	W ( W )
{
}

Xenon::Math::Vec4 :: Vec4 ( Vec3 & XYZ, float W ):
	X ( XYZ.X ),
	Y ( XYZ.Y ),
	Z ( XYZ.Z ),
	W ( W )
{	
}

Xenon::Math::Vec4 :: Vec4 ( const Vec4 & CopyFrom )
{
	
	Copy ( * this, CopyFrom );
	
}

Xenon::Math::Vec4 :: Vec4 ( NoInit NO_INIT )
{
}

Xenon::Math::Vec4 :: ~Vec4 ()
{
}

void Xenon::Math::Vec4 :: Copy ( Vec4 & Target, const Vec4 & Source )
{
	
	memcpy ( & Target, & Source, sizeof ( Vec4 ) );
	
}

float Xenon::Math::Vec4 :: DotProduct ( const Vec4 & SourceA, const Vec4 & SourceB )
{
	
#ifdef XENON_SSE4_1
	
	__m128 TempSSEV = _mm_dp_ps ( reinterpret_cast <const __m128 &> ( SourceA ), reinterpret_cast <const __m128 &> ( SourceB ), 0xFF );
	Vec4 Temp = reinterpret_cast <const Vec4 &> ( TempSSEV );
	return Temp.X;
	
#else
	
	return SourceA.X * SourceB.X + SourceA.Y * SourceB.Y + SourceA.Z * SourceB.Z + SourceA.W * SourceB.W;
	
#endif
	
}

void Xenon::Math::Vec4 :: Multiply ( Vec4 & Target, float Scalar )
{
	
#ifdef XENON_SSE
	
	reinterpret_cast <__m128 &> ( Target ) = _mm_mul_ps ( reinterpret_cast <__m128 &> ( Target ), _mm_set1_ps ( Scalar ) );
	
#else
	
	Target.X *= Scalar;
	Target.Y *= Scalar;
	Target.Z *= Scalar;
	Target.W *= Scalar;
	
#endif
	
}

void Xenon::Math::Vec4 :: Multiply ( Vec4 & Target, const Vec4 & Source, float Scalar )
{
	
#ifdef XENON_SSE
	
	reinterpret_cast <__m128 &> ( Target ) = _mm_mul_ps ( reinterpret_cast <const __m128 &> ( Source ), _mm_set1_ps ( Scalar ) );
	
#else
	
	Target.X = Source.X * Scalar;
	Target.Y = Source.Y * Scalar;
	Target.Z = Source.Z * Scalar;
	Target.W = Source.W * Scalar;
	
#endif
	
}

void Xenon::Math::Vec4 :: Add ( Vec4 & Target, const Vec4 & SourceA, const Vec4 & SourceB )
{
	
#ifdef XENON_SSE
	
	reinterpret_cast <__m128 &> ( Target ) = _mm_add_ps ( reinterpret_cast <const __m128 &> ( SourceA ), reinterpret_cast <const __m128 &> ( SourceB ) );
	
#else
	
	Target.X = SourceA.X + SourceB.X;
	Target.Y = SourceA.Y + SourceB.Y;
	Target.Z = SourceA.Z + SourceB.Z;
	Target.W = SourceA.W + BSourceB.W;
	
#endif
	
}

void Xenon::Math::Vec4 :: Add ( Vec4 & A, const Vec4 & B )
{
	
#ifdef XENON_SSE
	
	reinterpret_cast <__m128 &> ( A ) = _mm_add_ps ( reinterpret_cast <const __m128 &> ( A ), reinterpret_cast <const __m128 &> ( B ) );
	
#else
	
	A.X += B.X;
	A.Y += B.Y;
	A.Z += B.Z;
	A.W += B.W;
	
#endif
	
}

void Xenon::Math::Vec4 :: Subtract ( Vec4 & Target, const Vec4 & SourceA, const Vec4 & SourceB )
{
	
#ifdef XENON_SSE
	
	reinterpret_cast <__m128 &> ( Target ) = _mm_sub_ps ( reinterpret_cast <const __m128 &> ( SourceA ), reinterpret_cast <const __m128 &> ( SourceB ) );
	
#else
	
	Target.X = SourceA.X - SourceB.X;
	Target.Y = SourceA.Y - SourceB.Y;
	Target.Z = SourceA.Z - SourceB.Z;
	Target.W = SourceA.W - SourceB.W;
	
#endif
	
}

void Xenon::Math::Vec4 :: Subtract ( Vec4 & Target, const Vec4 & Source )
{
	
#ifdef XENON_SSE
	
	reinterpret_cast <__m128 &> ( Target ) = _mm_sub_ps ( reinterpret_cast <__m128 &> ( Target ), reinterpret_cast <const __m128 &> ( Source ) );
	
#else
	
	Target.X -= Source.X;
	Target.Y -= Source.Y;
	Target.Z -= Source.Z;
	Target.W -= Source.W;
	
#endif
	
}

void Xenon::Math::Vec4 :: Normalize ( Vec4 & Target )
{
	
#ifdef XENON_SSE4_1
	
	reinterpret_cast <__m128 &> ( Target ) = _mm_div_ps ( reinterpret_cast <__m128 &> ( Target ), _mm_sqrt_ps ( _mm_dp_ps ( reinterpret_cast <__m128 &> ( Target ), reinterpret_cast <__m128 &> ( Target ), 0xFF ) ) );
	
#else
	
	Multiply ( Target, 1.0 / Length ( Target ) );
	
#endif
	
}

void Xenon::Math::Vec4 :: Normalize ( Vec4 & Target, const Vec4 & Source )
{
	
#ifdef XENON_SSE4_1
	
	reinterpret_cast <__m128 &> ( Target ) = _mm_div_ps ( reinterpret_cast <const __m128 &> ( Source ), _mm_sqrt_ps ( _mm_dp_ps ( reinterpret_cast <const __m128 &> ( Source ), reinterpret_cast <const __m128 &> ( Source ), 0xFF ) ) );
	
#else
	
	Multiply ( Source, 1.0 / Length ( Source ), Target );
	
#endif
	
}

float Xenon::Math::Vec4 :: Length ( const Vec4 & Target )
{
	
#ifdef XENON_SSE4_1
	
	__m128 TempSSEV = _mm_sqrt_ps ( _mm_dp_ps ( reinterpret_cast <const __m128 &> ( Target ), reinterpret_cast <const __m128 &> ( Target ), 0xFF ) );
	Vec4 Temp = reinterpret_cast <const Vec4 &> ( TempSSEV );
	return Temp.X;
	
#else
	
	return sqrt ( Target.X * Target.X + Target.Y * Target.Y + Target.Z * Target.Z + Target.W * Target.W );
	
#endif
	
}

float Xenon::Math::Vec4 :: LengthSquared ( const Vec4 & Source )
{
	
#ifdef XENON_SSE4_1
	
	__m128 TempSSEV = _mm_dp_ps ( reinterpret_cast <const __m128 &> ( Source ), reinterpret_cast <const __m128 &> ( Source ), 0xFF );
	Vec4 Temp ( reinterpret_cast <const Vec4 &> ( TempSSEV ) );
	return Temp.X;
	
#else
	
	return Source.X * Source.X + Source.Y * Source.Y + Source.Z * Source.Z + Source.W * Source.W;
	
#endif
	
}

float Xenon::Math::Vec4 :: AngleBetween ( const Vec4 & A, const Vec4 & B )
{
	
	return acos ( DotProduct ( A, B ) / sqrt ( LengthSquared ( A ) * LengthSquared ( B ) ) );
	
}

void Xenon::Math::Vec4 :: Interpolate ( Vec4 & Target, const Vec4 & Source, float Fraction )
{
	
#ifdef XENON_SSE
	
	float OppositeFraction = 1.0f - Fraction;
	
	reinterpret_cast <__m128 &> ( Target ) = _mm_add_ps ( _mm_mul_ps ( reinterpret_cast <__m128 &> ( Target ), _mm_set1_ps ( Fraction ) ), _mm_mul_ps ( reinterpret_cast <const __m128 &> ( Source ), _mm_set1_ps ( OppositeFraction ) ) );
	
#else
	
	Vec4 Temp;
	
	Multiply ( Target, Fraction );
	Multiply ( Source, 1.0f - Fraction, Temp );
	
	Add ( Target, Temp );
	
#endif
	
}

void Xenon::Math::Vec4 :: Interpolate ( Vec4 & Target, const Vec4 & SourceA, const Vec4 & SourceB, float Fraction )
{
	
	Vec4 Temp;
	
	Multiply ( Target, SourceA, Fraction );
	Multiply ( Temp, SourceB, 1.0f - Fraction );
	
	Add ( Target, Temp );
	
}

void Xenon::Math::Vec4 :: Project ( Vec4 & Target, const Vec4 & Direction )
{
	
	Multiply ( Target, Direction, DotProduct ( Target, Direction ) / LengthSquared ( Direction ) );
	
}

void Xenon::Math::Vec4 :: Project ( Vec4 & Target, const Vec4 & Projected, const Vec4 & Direction )
{
	
	Multiply ( Target, Direction, DotProduct ( Projected, Direction ) / LengthSquared ( Direction ) );
	
}
