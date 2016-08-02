#include <Xenon/Math/Quaternion.h>
#include <Xenon/Math/Vec3.h>

#include <math.h>

const Xenon::Math :: Quaternion Xenon::Math::Quaternion :: IDENTITY ( 0.0f, 0.0f, 0.0f, 1.0f );

Xenon::Math::Quaternion :: Quaternion ( NoInit NO_INIT ):
	Vec4 ( Vec4 :: NO_INIT )
{
	
	(void) NO_INIT;
	
}

Xenon::Math::Quaternion :: Quaternion ( float X, float Y, float Z, float W ):
	Vec4 ( X, Y, Z, W )
{
}

Xenon::Math::Quaternion :: Quaternion ( const Quaternion & Source ):
	Vec4 ( Source )
{
}

Xenon::Math::Quaternion :: ~Quaternion ()
{
}

void Xenon::Math::Quaternion :: Add ( Quaternion & Target, const Quaternion & Source )
{
	
#ifdef XENON_SSE
	
	reinterpret_cast <__m128 &> ( Target ) = _mm_add_ps ( reinterpret_cast <__m128 &> ( Target ), reinterpret_cast <const __m128 &> ( Source ) );
	
#else
	
	Target.X += Source.X;
	Target.Y += Source.Y;
	Target.Z += Source.Z;
	Target.W += Source.W;
	
#endif
	
}

void Xenon::Math::Quaternion :: Add ( Quaternion & Target, const Quaternion & SourceA, const Quaternion & SourceB )
{
	
#ifdef XENON_SSE
	
	reinterpret_cast <__m128 &> ( Target ) = _mm_add_ps ( reinterpret_cast <const __m128 &> ( SourceA ), reinterpret_cast <const __m128 &> ( SourceB ) );
	
#else
	
	Target.X = SourceA.X + SourceB.X;
	Target.Y = SourceA.Y + SourceB.Y;
	Target.Z = SourceA.Z + SourceB.Z;
	Target.W = SourceA.W + SourceB.W;
	
#endif
	
}

void Xenon::Math::Quaternion :: Subtract ( Quaternion & Target, const Quaternion & Source )
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

void Xenon::Math::Quaternion :: Subtract ( Quaternion & Target, const Quaternion & SourceA, const Quaternion & SourceB )
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

void Xenon::Math::Quaternion :: Multiply ( Quaternion & A, const float Scalar )
{
	
#ifdef XENON_SSE
	
	reinterpret_cast <__m128 &> ( A ) = _mm_mul_ps ( reinterpret_cast <__m128 &> ( A ), _mm_set1_ps ( Scalar ) );
	
#else
	
	A.X *= Scalar;
	A.Y *= Scalar;
	A.Z *= Scalar;
	A.W *= Scalar;
	
#endif
	
}

void Xenon::Math::Quaternion :: Multiply ( Quaternion & Target, const Quaternion & Source, const float Scalar )
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

void Xenon::Math::Quaternion :: Prepend ( Quaternion & Target, const Quaternion & Source )
{
	
/*#ifdef XENON_SSE4_1
	
	
	
#else*/
	
	float X;
	float Y;
	float Z;
	float W;
	
	X =   Target.X * Source.W + Target.Y * Source.Z - Target.Z * Source.Y + Target.W * Source.X;
	Y = - Target.X * Source.Z + Target.Y * Source.W + Target.Z * Source.X + Target.W * Source.Y;
	Z =   Target.X * Source.Y - Target.Y * Source.X + Target.Z * Source.W + Target.W * Source.Z;
	W = - Target.X * Source.X - Target.Y * Source.Y - Target.Z * Source.Z + Target.W * Source.W;
	
	Target.X = X;
	Target.Y = Y;
	Target.Z = Z;
	Target.W = W;
	
//#endif
	
}

void Xenon::Math::Quaternion :: Prepend ( Quaternion & Target, const Quaternion & SourceA, const Quaternion & SourceB )
{
	
/*#ifdef XENON_SSE3
	
	__mm_add_ps ( __mm_mul_ps ( __mm_shuffle_ps ( A, A, __MM_SHUFFLE ( 3, 3, 3, 3 ) ), B ), __mm_mul_ps ( __mm_shuffle_ps ( A, A, __MM_SHUFFLE ( 0, 2, 1, 0 ) ), __mm_shuffle_ps ( B, B, __MM_SHUFFLE ( 0, 3, 3, 3 ) ) ) );
	
#else*/
	
	Target.X =   SourceA.X * SourceB.W + SourceA.Y * SourceB.Z - SourceA.Z * SourceB.Y + SourceA.W * SourceB.X;
	Target.Y = - SourceA.X * SourceB.Z + SourceA.Y * SourceB.W + SourceA.Z * SourceB.X + SourceA.W * SourceB.Y;
	Target.Z =   SourceA.X * SourceB.Y - SourceA.Y * SourceB.X + SourceA.Z * SourceB.W + SourceA.W * SourceB.Z;
	Target.W = - SourceA.X * SourceB.X - SourceA.Y * SourceB.Y - SourceA.Z * SourceB.Z + SourceA.W * SourceB.W;
	
//#endif
	
}

void Xenon::Math::Quaternion :: Append ( Quaternion & Target, const Quaternion & Source )
{
	
/*#ifdef XENON_SSE4_1
	
	
	
#else*/
	
	float X;
	float Y;
	float Z;
	float W;
	
	X =   Source.X * Target.W + Source.Y * Target.Z - Source.Z * Target.Y + Source.W * Target.X;
	Y = - Source.X * Target.Z + Source.Y * Target.W + Source.Z * Target.X + Source.W * Target.Y;
	Z =   Source.X * Target.Y - Source.Y * Target.X + Source.Z * Target.W + Source.W * Target.Z;
	W = - Source.X * Target.X - Source.Y * Target.Y - Source.Z * Target.Z + Source.W * Target.W;
	
	Target.X = X;
	Target.Y = Y;
	Target.Z = Z;
	Target.W = W;
	
//#endif
	
}

void Xenon::Math::Quaternion :: Append ( Quaternion & Target, const Quaternion & SourceA, const Quaternion & SourceB )
{
	
/*#ifdef XENON_SSE3
	
	__mm_add_ps ( __mm_mul_ps ( __mm_shuffle_ps ( A, A, __MM_SHUFFLE ( 3, 3, 3, 3 ) ), B ), __mm_mul_ps ( __mm_shuffle_ps ( A, A, __MM_SHUFFLE ( 0, 2, 1, 0 ) ), __mm_shuffle_ps ( B, B, __MM_SHUFFLE ( 0, 3, 3, 3 ) ) ) );
	
#else*/
	
	Target.X =   SourceB.X * SourceA.W + SourceB.Y * SourceA.Z - SourceB.Z * SourceA.Y + SourceB.W * SourceA.X;
	Target.Y = - SourceB.X * SourceA.Z + SourceB.Y * SourceA.W + SourceB.Z * SourceA.X + SourceB.W * SourceA.Y;
	Target.Z =   SourceB.X * SourceA.Y - SourceB.Y * SourceA.X + SourceB.Z * SourceA.W + SourceB.W * SourceA.Z;
	Target.W = - SourceB.X * SourceA.X - SourceB.Y * SourceA.Y - SourceB.Z * SourceA.Z + SourceB.W * SourceA.W;
	
//#endif
	
}

void Xenon::Math::Quaternion :: Conjugate ( Quaternion & A )
{
	
#ifdef XENON_SSE
	
	__m128 Sign = _mm_setr_ps ( - 1.0f, - 1.0f, - 1.0f, 1.0f );
	
	reinterpret_cast <__m128 &> ( A ) = _mm_mul_ps ( Sign, reinterpret_cast <__m128 &> ( A ) );
	
#else
	
	A.X = - A.X;
	A.Y = - A.Y;
	A.Z = - A.Z;
	
#endif
	
}

void Xenon::Math::Quaternion :: Conjugate ( Quaternion & Target, const Quaternion & Source )
{
	
#ifdef XENON_SSE
	
	__m128 Sign = _mm_setr_ps ( - 1.0f, - 1.0f, - 1.0f, 1.0f );
	
	reinterpret_cast <__m128 &> ( Target ) = _mm_mul_ps ( Sign, reinterpret_cast <const __m128 &> ( Source ) );
	
#else
	
	Target.X = - Source.X;
	Target.Y = - Source.X;
	Target.Z = - Source.X;
	Target.W = Source.W;
	
#endif
	
}

void Xenon::Math::Quaternion :: InterpolateSLERP ( Quaternion & A, const Quaternion & B, const float Fraction )
{
	
#ifdef XENON_SSE3
	
	Vec4 Temp;
	
	reinterpret_cast <__m128 &> ( Temp ) = _mm_mul_ps ( reinterpret_cast <const __m128 &> ( A ), reinterpret_cast <const __m128 &> ( B ) );
	reinterpret_cast <__m128 &> ( Temp ) = _mm_hadd_ps ( reinterpret_cast <__m128 &> ( Temp ), reinterpret_cast <__m128 &> ( Temp ) );
	reinterpret_cast <__m128 &> ( Temp ) = _mm_hadd_ps ( reinterpret_cast <__m128 &> ( Temp ), reinterpret_cast <__m128 &> ( Temp ) );

	Temp.X = acos ( Temp.X );
	
	Temp.Y = sin ( Temp.X );
	Temp.Z = sin ( Fraction * Temp.X ) / Temp.Y;
	Temp.W = sin ( ( 1 - Fraction ) * Temp.X ) / Temp.Y;
	
	reinterpret_cast <__m128 &> ( A ) = _mm_add_ps ( _mm_mul_ps ( reinterpret_cast <__m128 &> ( A ), _mm_shuffle_ps ( reinterpret_cast <__m128 &> ( Temp ), reinterpret_cast <__m128 &> ( Temp ), _MM_SHUFFLE ( 3, 3, 3, 3 ) ) ), _mm_mul_ps ( reinterpret_cast <const __m128 &> ( B ), _mm_shuffle_ps ( reinterpret_cast <__m128 &> ( Temp ), reinterpret_cast <__m128 &> ( Temp ), _MM_SHUFFLE ( 2, 2, 2, 2 ) ) ) );
	
#else
	
	float Theta = acos ( A.X * B.X + A.Y * B.Y + A.Z * B.Z + A.W * B.W );
	
	if ( Theta < 0.0 )
		Theta = - Theta;
	
	float ST = sin ( Theta );
	float SU = sin ( Fraction * Theta ) / ST;
	float SO = sin ( ( 1 - Fraction ) * Theta ) / ST;
	
	A.X = A.X * SO + B.X * SU;
	A.Y = A.Y * SO + B.Y * SU;
	A.Z = A.Z * SO + B.Z * SU;
	A.W = A.W * SO + B.W * SU;
	
#endif
	
}

void Xenon::Math::Quaternion :: InterpolateSLERP ( Quaternion & Target, const Quaternion & SourceA, const Quaternion & SourceB, const float Fraction )
{
	
#ifdef XENON_SSE3
	
	Vec4 Temp;
	
	reinterpret_cast <__m128 &> ( Temp ) = _mm_mul_ps ( reinterpret_cast <const __m128 &> ( SourceA ), reinterpret_cast <const __m128 &> ( SourceB ) );
	reinterpret_cast <__m128 &> ( Temp ) = _mm_hadd_ps ( reinterpret_cast <__m128 &> ( Temp ), reinterpret_cast <__m128 &> ( Temp ) );
	reinterpret_cast <__m128 &> ( Temp ) = _mm_hadd_ps ( reinterpret_cast <__m128 &> ( Temp ), reinterpret_cast <__m128 &> ( Temp ) );

	Temp.X = acos ( Temp.X );
	
	Temp.Y = sin ( Temp.X );
	Temp.Z = sin ( Fraction * Temp.X ) / Temp.Y;
	Temp.W = sin ( ( 1 - Fraction ) * Temp.X ) / Temp.Y;
	
	reinterpret_cast <__m128 &> ( Target ) = _mm_add_ps ( _mm_mul_ps ( reinterpret_cast <const __m128 &> ( SourceA ), _mm_shuffle_ps ( reinterpret_cast <__m128 &> ( Temp ), reinterpret_cast <__m128 &> ( Temp ), _MM_SHUFFLE ( 3, 3, 3, 3 ) ) ), _mm_mul_ps ( reinterpret_cast <const __m128 &> ( SourceB ), _mm_shuffle_ps ( reinterpret_cast <__m128 &> ( Temp ), reinterpret_cast <__m128 &> ( Temp ), _MM_SHUFFLE ( 2, 2, 2, 2 ) ) ) );
	
#else
	
	float Theta = acos ( SourceA.X * SourceB.X + SourceA.Y * SourceB.Y + SourceA.Z * SourceB.Z + SourceA.W * SourceB.W );
	
	if ( Theta < 0.0 )
		Theta = - Theta;
	
	float ST = sin ( Theta );
	float SU = sin ( Fraction * Theta ) / ST;
	float SO = sin ( ( 1 - Fraction ) * Theta ) / ST;
	
	Target.X = SourceA.X * SO + SourceB.X * SU;
	Target.Y = SourceA.Y * SO + SourceB.Y * SU;
	Target.Z = SourceA.Z * SO + SourceB.Z * SU;
	Target.W = SourceA.W * SO + SourceB.W * SU;
	
#endif
	
}

void Xenon::Math::Quaternion :: FromYPR ( Quaternion & Target, const float Yaw, const float Pitch, const float Roll )
{
	
	float YCos = cos ( Yaw / 2 );
	float YSin = sin ( Yaw / 2 );
	float PCos = cos ( Pitch / 2 );
	float PSin = sin ( Pitch / 2 );
	float RCos = cos ( Roll / 2 );
	float RSin = sin ( Roll / 2 );
	
	Target.W = RCos * PCos * YCos + RSin * PSin * YSin;
	Target.X = RSin * PCos * YCos - RCos * PSin * YSin;
	Target.Y = RCos * PSin * YCos + RSin * PCos * YSin;
	Target.Z = RCos * PCos * YSin - RSin * PSin * YCos;
	
	Normalize ( Target );
	
}

void Xenon::Math::Quaternion :: FromAxisAngle ( Quaternion & Target, const Vec3 & Axis, const float Angle )
{
	
	float RSin = sin ( Angle / 2 );
	
	Target.W = cos ( Angle / 2 );
	
	Target.X = Axis.X * RSin;
	Target.Y = Axis.Y * RSin;
	Target.Z = Axis.Z * RSin;
	
	Normalize ( Target );
	
}

void Xenon::Math::Quaternion :: FromBetweenVectors ( Quaternion & Target, const Vec3 & From, const Vec3 & To )
{
	
	Vec3 FromNormalized ( Vec3 :: NO_INIT );
	Vec3 ToNormalized ( Vec3 :: NO_INIT );
	Vec3 ToOpposite ( Vec3 :: NO_INIT );
	
	Vec3 :: Normalize ( FromNormalized, From );
	Vec3 :: Normalize ( ToNormalized, To );
	Vec3 :: Multiply ( ToOpposite, To, - 1.0 );
	
	if ( Vec3 :: Equal ( FromNormalized, ToOpposite ) )
	{
		
		Vec3 :: Orthogonal ( FromNormalized );
		
		Target.X = FromNormalized.X;
		Target.Y = FromNormalized.Y;
		Target.Z = FromNormalized.Z;
		Target.W = 0;
		
		return;
				
	}
	
	Vec3 Half ( Vec3 :: NO_INIT );
	Vec3 Cross ( Vec3 :: NO_INIT );
	
	Vec3 :: Add ( FromNormalized, ToNormalized, Half );
	Vec3 :: Normalize ( Half );
	
	Vec3 :: CrossProduct ( FromNormalized, Half );
	
	Target.W = Vec3 :: DotProduct ( FromNormalized, Half );
	
	Target.X = FromNormalized.X;
	Target.Y = FromNormalized.Y;
	Target.Z = FromNormalized.Z;
	
}

void Xenon::Math::Quaternion :: Normalize ( Quaternion & A )
{
	
	Multiply ( A, 1.0f / Length ( A ) );
	
}

void Xenon::Math::Quaternion :: Normalize ( Quaternion & Target, const Quaternion & Source )
{
	
	Multiply ( Target, Source, 1.0f / Length ( Source ) );
	
}

float Xenon::Math::Quaternion :: Length ( const Quaternion & Source )
{
	
	return sqrt ( Source.X * Source.X + Source.Y * Source.Y + Source.Z * Source.Z + Source.W * Source.W );
	
}

float Xenon::Math::Quaternion :: Yaw ( const Quaternion & A )
{
	
	return atan2 ( ( A.W * A.Z + A.X * A.Y ), 0.5 - ( A.Y * A.Y + A.Z * A.Z ) );
	
}

float Xenon::Math::Quaternion :: Pitch ( const Quaternion & A )
{
	
	return asin ( 2.0 * ( A.W * A.Y - A.X * A.Z ) );
	
}

float Xenon::Math::Quaternion :: Roll ( const Quaternion & A )
{
	
	return atan2 ( ( A.W * A.X + A.Y * A.Z ), 0.5 - ( A.X * A.X + A.Y * A.Y ) );
	
}

void Xenon::Math::Quaternion :: Axis ( Vec3 & Target, const Quaternion & Source )
{
	
	float Div = sqrt ( 1.0 - Source.W * Source.W );
	
	Target.X = Source.X / Div;
	Target.Y = Source.Y / Div;
	Target.Z = Source.Z / Div;
	
}

float Xenon::Math::Quaternion :: Angle ( const Quaternion & A )
{
	
	return 2.0 * acos ( A.W );
	
}
