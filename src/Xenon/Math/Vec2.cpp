#include <Xenon/Math/Vec2.h>

#include <math.h>
#include <string.h>

const Xenon::Math :: Vec2 Xenon::Math::Vec2 :: UP ( 0.0f, 1.0f );
const Xenon::Math :: Vec2 Xenon::Math::Vec2 :: DOWN ( 0.0f, - 1.0f );
const Xenon::Math :: Vec2 Xenon::Math::Vec2 :: LEFT ( - 1.0f, 0.0f );
const Xenon::Math :: Vec2 Xenon::Math::Vec2 :: RIGHT ( 1.0f, 0.0f );

const Xenon::Math :: Vec2 Xenon::Math::Vec2 :: IDENTITY ( 1.0f, 1.0f );
const Xenon::Math :: Vec2 Xenon::Math::Vec2 :: ZERO ( 0.0f, 0.0f );

Xenon::Math::Vec2 :: Vec2 ( const float X, const float Y ):
	X ( X ),
	Y ( Y )
{
}

Xenon::Math::Vec2 :: Vec2 ( const Vec2 & CopyFrom )
{
	
	this -> X = X;
	this -> Y = Y;
	
}

Xenon::Math::Vec2 :: Vec2 ( NoInit NO_INIT )
{
}

Xenon::Math::Vec2 :: ~Vec2 ()
{
}

void Xenon::Math::Vec2 :: Copy ( Vec2 & Target, const Vec2 & Source )
{
	
	memcpy ( reinterpret_cast <void *> ( & Target ), reinterpret_cast <const void *> ( & Source ), sizeof ( Vec2 ) );
	
}

bool Xenon::Math::Vec2 :: Equal ( const Vec2 & A, const Vec2 & B )
{
	
	return ( A.X == B.X ) && ( A.Y == B.Y );
	
}

float Xenon::Math::Vec2 :: DotProduct ( const Vec2 & A, const Vec2 & B )
{
	
	return A.X * B.X + A.Y * B.Y;
	
}

void Xenon::Math::Vec2 :: Multiply ( Vec2 & Target, const float Scalar )
{
	
	Target.X *= Scalar;
	Target.Y *= Scalar;
	
}

void Xenon::Math::Vec2 :: Multiply ( Vec2 & Target, const Vec2 & Source, const float Scalar )
{
	
	Target.X = Source.X * Scalar;
	Target.Y = Source.Y * Scalar;
	
}

void Xenon::Math::Vec2 :: Scale ( Vec2 & Target, const Vec2 & B )
{
	
	Target.X *= B.X;
	Target.Y *= B.Y;
	
}

void Xenon::Math::Vec2 :: Scale ( Vec2 & Target, const Vec2 & Source, const Vec2 & B )
{
	
	Target.X = Source.X * B.X;
	Target.Y = Source.Y * B.Y;
	
}

void Xenon::Math::Vec2 :: Add ( Vec2 & Target, const Vec2 & B )
{
	
	Target.X += B.X;
	Target.Y += B.Y;
	
}

void Xenon::Math::Vec2 :: Add ( Vec2 & Target, const Vec2 & Source, const Vec2 & B )
{
	
	Target.X = Source.X + B.X;
	Target.Y = Source.Y + B.Y;
	
}

void Xenon::Math::Vec2 :: Subtract ( Vec2 & Target, const Vec2 & B )
{
	
	Target.X -= B.X;
	Target.Y -= B.Y;
	
}

void Xenon::Math::Vec2 :: Subtract ( Vec2 & Target, const Vec2 & Source, const Vec2 & B )
{
	
	Target.X = Source.X - B.X;
	Target.Y = Source.Y - B.Y;
	
}

void Xenon::Math::Vec2 :: Normalize ( Vec2 & Target )
{
	
	float Multiplier = 1.0f / Length ( Target );
	
	Target.X *= Multiplier;
	Target.Y *= Multiplier;
	
}

void Xenon::Math::Vec2 :: Normalize ( Vec2 & Target, const Vec2 & Source )
{
	
	float Multiplier = 1.0f / Length ( Source );
	
	Target.X = Source.X * Multiplier;
	Target.Y = Source.Y * Multiplier;
	
}

float Xenon::Math::Vec2 :: Length ( const Vec2 & Source )
{
	
	return sqrt ( Source.X * Source.X + Source.Y * Source.Y );
	
}

float Xenon::Math::Vec2 :: LengthSquared ( const Vec2 & Source )
{
	
	return Source.X * Source.X + Source.Y * Source.Y;
	
}

void Xenon::Math::Vec2 :: Absolute ( Vec2 & Target )
{
	
	Target.X = fabs ( Target.X );
	Target.Y = fabs ( Target.Y );
	
}

void Xenon::Math::Vec2 :: Absolute ( Vec2 & Target, const Vec2 & Source )
{
	
	Target.X = fabs ( Source.X );
	Target.Y = fabs ( Source.Y );
	
}

float Xenon::Math::Vec2 :: AngleBetween ( const Vec2 & A, const Vec2 & B )
{
	
	return acos ( DotProduct ( A, B ) / sqrt ( LengthSquared ( A ) * LengthSquared ( B ) ) );
	
}

void Xenon::Math::Vec2 :: Interpolate ( Vec2 & Target, const Vec2 & B, const float Fraction )
{
	
	Vec2 Temp;
	
	Multiply ( Target, Fraction );
	Multiply ( Temp, B, 1.0f - Fraction );
	Add ( Target, Temp );
	
}

void Xenon::Math::Vec2 :: Interpolate (  Vec2 & Target, const Vec2 & Source, const Vec2 & B, const float Fraction )
{
	
	Vec2 Temp;
	
	Multiply ( Target, Source, Fraction );
	Multiply ( Temp, B, 1 - Fraction );
	Add ( Target, Temp );
	
}

float Xenon::Math::Vec2 :: ScalarProjection ( const Vec2 & Source, const Vec2 & Direction )
{
	
	return DotProduct ( Source, Direction ) / Length ( Direction );
	
}

void Xenon::Math::Vec2 :: Project ( Vec2 & Target, const Vec2 & Direction )
{
	
	Multiply ( Target, Direction, DotProduct ( Target, Direction ) / LengthSquared ( Direction ) );
	
}

void Xenon::Math::Vec2 :: Project ( Vec2 & Target, const Vec2 & Projected, const Vec2 & Direction )
{
	
	Multiply ( Target, Direction, DotProduct ( Projected, Direction ) / LengthSquared ( Direction ) );
	
}
