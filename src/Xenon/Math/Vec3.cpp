#include <Xenon/Math/Vec3.h>
#include <Xenon/Math/Vec2.h>
#include <Xenon/Math/Quaternion.h>

#include <string.h>
#include <math.h>

const Xenon::Math :: Vec3 Xenon::Math::Vec3 :: FORWARD ( 0, 0, 1 );
const Xenon::Math :: Vec3 Xenon::Math::Vec3 :: BACKWARD ( 0, 0, - 1 );
const Xenon::Math :: Vec3 Xenon::Math::Vec3 :: DOWN ( 0, - 1, 0 );
const Xenon::Math :: Vec3 Xenon::Math::Vec3 :: UP ( 0, 1, 0 );
const Xenon::Math :: Vec3 Xenon::Math::Vec3 :: RIGHT ( 1, 0, 0 );
const Xenon::Math :: Vec3 Xenon::Math::Vec3 :: LEFT ( - 1, 0, 0 );
const Xenon::Math :: Vec3 Xenon::Math::Vec3 :: IDENTITY ( 1, 1, 1 );
const Xenon::Math :: Vec3 Xenon::Math::Vec3 :: ZERO ( 0, 0, 0 );

Xenon::Math::Vec3 :: Vec3 ( const float X, const float Y, const float Z ):
	X ( X ),
	Y ( Y ),
	Z ( Z )
{
};

Xenon::Math::Vec3 :: Vec3 ( const Vec3 & CopyFrom )
{
	
	Copy ( * this, CopyFrom );
	
};

Xenon::Math::Vec3 :: Vec3 ( const Vec2 & Lower, const float Z ):
	X ( Lower.X ),
	Y ( Lower.Y ),
	Z ( Z )
{
};

Xenon::Math::Vec3 :: ~Vec3 ()
{
};

void Xenon::Math::Vec3 :: Set ( Vec3 & Target, const float X, const float Y, const float Z )
{
	
	Target.X = X;
	Target.Y = Y;
	Target.Z = Z;
	
};

void Xenon::Math::Vec3 :: Copy ( Vec3 & Target, const Vec3 & Source )
{
	
	memcpy ( & Target, & Source, sizeof ( Vec3 ) );
	
};

bool Xenon::Math::Vec3 :: Equal ( const Vec3 & Source, const Vec3 & B )
{
	
	return ( ( Source.X == B.X ) && ( Source.Y == B.Y ) && ( Source.Z == B.Z ) );
	
};

float Xenon::Math::Vec3 :: DotProduct ( const Vec3 & Source, const Vec3 & B )
{
	
	return Source.X * B.X + Source.Y * B.Y + Source.Z * B.Z;
	
};

void Xenon::Math::Vec3 :: CrossProduct ( Vec3 & Target, const Vec3 & Source, const Vec3 & B )
{
	
	Target.X = Source.Y * B.Z - Source.Z * B.Y;
	Target.Y = Source.Z * B.X - Source.X * B.Z;
	Target.Z = Source.X * B.Y - Source.Y * B.X;
	
};

void Xenon::Math::Vec3 :: CrossProduct ( Vec3 & Target, const Vec3 & B )
{
	
	float X = Target.Y * B.Z - Target.Z * B.Y;
	float Y = Target.Z * B.X - Target.X * B.Z;
	Target.Z = Target.X * B.Y - Target.Y * B.X;
	Target.X = X;
	Target.Y = Y;
	
};

void Xenon::Math::Vec3 :: Multiply ( Vec3 & Target, const float B )
{
	
	Target.X *= B;
	Target.Y *= B;
	Target.Z *= B;
	
};

void Xenon::Math::Vec3 :: Multiply ( Vec3 & Target, const Vec3 & Source, const float B )
{
	
	Target.X = Source.X * B;
	Target.Y = Source.Y * B;
	Target.Z = Source.Z * B;
	
};

void Xenon::Math::Vec3 :: Scale ( Vec3 & Target, const Vec3 & B )
{
	
	Target.X *= B.X;
	Target.Y *= B.Y;
	Target.Z *= B.Z;
	
};

void Xenon::Math::Vec3 :: Scale ( Vec3 & Target, const Vec3 & Source, const Vec3 & B )
{
	
	Target.X = Source.X * B.X;
	Target.Z = Source.Y * B.Y;
	Target.Y = Source.Z * B.Z;
	
};

void Xenon::Math::Vec3 :: Add ( Vec3 & Target, const Vec3 & Source, const Vec3 & B )
{
	
	Target.X = Source.X + B.X;
	Target.Y = Source.Y + B.Y;
	Target.Z = Source.Z + B.Z;
	
};

void Xenon::Math::Vec3 :: Add ( Vec3 & Target, const Vec3 & B )
{
	
	Target.X += B.X;
	Target.Y += B.Y;
	Target.Z += B.Z;
	
};

void Xenon::Math::Vec3 :: Subtract ( Vec3 & Target, const Vec3 & Source, const Vec3 & B )
{
	
	Target.X = Source.X - B.X;
	Target.Y = Source.Y - B.Y;
	Target.Z = Source.Z - B.Z;
	
};

void Xenon::Math::Vec3 :: Subtract ( Vec3 & Target, const Vec3 & B )
{
	
	Target.X -= B.X;
	Target.Y -= B.Y;
	Target.Z -= B.Z;
	
};

void Xenon::Math::Vec3 :: Normalize ( Vec3 & Target )
{
	
	Multiply ( Target, 1 / Length ( Target ) );
	
};

void Xenon::Math::Vec3 :: Normalize ( Vec3 & Target, const Vec3 & Source )
{
	
	Multiply ( Target, Source, 1.0f / Length ( Source ) );
	
};

float Xenon::Math::Vec3 :: Length ( const Vec3 & Source )
{
	
	return sqrt ( Source.X * Source.X + Source.Y * Source.Y + Source.Z * Source.Z );
	
};

float Xenon::Math::Vec3 :: LengthSquared ( const Vec3 & Source )
{
	
	return Source.X * Source.X + Source.Y * Source.Y + Source.Z * Source.Z;
	
};

void Xenon::Math::Vec3 :: Absolute ( Vec3 & Target )
{
	
	Target.X = fabs ( Target.X );
	Target.Y = fabs ( Target.Y );
	Target.Z = fabs ( Target.Z );
	
};

void Xenon::Math::Vec3 :: Absolute ( Vec3 & Target, const Vec3 & Source )
{
	
	Target.X = fabs ( Source.X );
	Target.Y = fabs ( Source.Y );
	Target.Z = fabs ( Source.Z );
	
};

float Xenon::Math::Vec3 :: AngleBetween ( const Vec3 & Source, const Vec3 & B )
{
	
	return acos ( DotProduct ( Source, B ) / sqrt ( LengthSquared ( Source ) * LengthSquared ( B ) ) );
	
};

void Xenon::Math::Vec3 :: Interpolate ( Vec3 & Target, const Vec3 & B, const float Fraction )
{
	
	Vec3 Temp;
	
	Multiply ( Target, Fraction );
	Multiply ( Temp, B, 1.0f - Fraction );
	Add ( Target, Temp );
	
};

void Xenon::Math::Vec3 :: Interpolate ( Vec3 & Target, const Vec3 & Source, const Vec3 & B, const float Fraction )
{
	
	Vec3 Temp;
	
	Multiply ( Target, Source, Fraction );
	Multiply ( Temp, B, 1 - Fraction );
	Add ( Target, Temp );
	
};

void Xenon::Math::Vec3 :: Rotate ( Vec3 & Target, const Quaternion & Rotation )
{
	
	Vec3 Dir ( Rotation.X, Rotation.Y, Rotation.Z );
	Vec3 Temp ( NO_INIT );
	Vec3 Temp2 ( NO_INIT );
	
	Multiply ( Temp, Dir, 2.0f * DotProduct ( Target, Dir ) );
	Multiply ( Temp2, Target, Rotation.W * Rotation.W - LengthSquared ( Dir ) );
	Add ( Temp, Temp2 );
	
	CrossProduct ( Temp2, Target, Dir );
	Multiply ( Temp2, 2.0f * Rotation.W );
	Add ( Target, Temp, Temp2 );
	
};

void Xenon::Math::Vec3 :: Rotate ( Vec3 & Target, const Vec3 & Source, const Quaternion & Rotation )
{
	
	Vec3 Dir ( Rotation.X, Rotation.Y, Rotation.Z );
	Vec3 ACross;
	Vec3 BCross;
	Vec3 Temp;
	
	CrossProduct ( Temp, Source, ACross );
	Multiply ( ACross, 2.0 );
	CrossProduct ( ACross, Dir, BCross );
	
	Target.X = Temp.X * Rotation.W + BCross.X;
	Target.Y = Temp.Y * Rotation.W + BCross.Y;
	Target.Z = Temp.Z * Rotation.W + BCross.Z;
	
};

void Xenon::Math::Vec3 :: Orthogonal ( Vec3 & Target )
{
	
	Vec3 Abs ( NO_INIT );
	
	Absolute ( Abs, Target );
	
	CrossProduct ( Target, ( Abs.X < Abs.Y ) ? ( ( Abs.X < Abs.Y ) ? RIGHT : FORWARD ) : ( ( Abs.X < Abs.Y ) ? UP : FORWARD ) );
	
};

void Xenon::Math::Vec3 :: Orthogonal ( Vec3 & Target, const Vec3 & Source )
{
	
	Vec3 Abs ( NO_INIT );
	
	Absolute ( Abs, Source );
	
	CrossProduct ( Target, ( Abs.X < Abs.Y ) ? ( ( Abs.X < Abs.Y ) ? RIGHT : FORWARD ) : ( ( Abs.X < Abs.Y ) ? UP : FORWARD ), Source );
	
};