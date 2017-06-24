#include <Xenon/Math/Matrix3x3.h>
#include <Xenon/Math/Vec3.h>
#include <Xenon/Math/Vec2.h>

#include <math.h>
#include <string.h>

#include <utility>

float Xenon::Math::Matrix3x3 :: DummyFloatRef = 0.0f;

Xenon::Math::Matrix3x3 :: Matrix3x3 ():
	Elements { { 1.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f, 1.0f } }
{
}

Xenon::Math::Matrix3x3 :: Matrix3x3 ( const float A, const float B, const float C, const float D, const float E, const float F, const float G, const float H, const float I ):
	Elements { { A, B, C }, { D, E, F }, { G, H, I } }
{
}

Xenon::Math::Matrix3x3 :: Matrix3x3 ( const Matrix3x3 & CopyFrom ):
	Elements { { CopyFrom.Elements [ 0 ][ 0 ], CopyFrom.Elements [ 0 ][ 1 ], CopyFrom.Elements [ 0 ][ 2 ] }, { CopyFrom.Elements [ 1 ][ 0 ], CopyFrom.Elements [ 1 ][ 1 ], CopyFrom.Elements [ 1 ][ 2 ] }, { CopyFrom.Elements [ 2 ][ 0 ], CopyFrom.Elements [ 2 ][ 1 ], CopyFrom.Elements [ 2 ][ 2 ] } }
{
}

Xenon::Math::Matrix3x3 :: Matrix3x3 ( NoInit NO_INIT )
{
	
	(void) NO_INIT;
	
}

Xenon::Math::Matrix3x3 :: ~Matrix3x3 ()
{
}

float Xenon::Math::Matrix3x3 :: GetElement ( const Matrix3x3 & Source, uint32_t X, uint32_t Y )
{
	
	if ( X < 3 && Y < 3 )
		return Source.Elements [ Y ][ X ];
	
	return 0.0f;
	
}

float & Xenon::Math::Matrix3x3 :: GetElementMutable ( Matrix3x3 & Source, uint32_t X, uint32_t Y )
{
	
	if ( X < 3 && Y < 3 )
		return Source.Elements [ Y ][ X ];
	
	return DummyFloatRef;
	
}

void Xenon::Math::Matrix3x3 :: Identity ( Matrix3x3 & Target )
{
	
	Target.Elements [ 0 ][ 0 ] = 1.0f;
	Target.Elements [ 0 ][ 1 ] = 0.0f;
	Target.Elements [ 0 ][ 2 ] = 0.0f;
	Target.Elements [ 1 ][ 0 ] = 0.0f;
	Target.Elements [ 1 ][ 1 ] = 1.0f;
	Target.Elements [ 1 ][ 2 ] = 0.0f;
	Target.Elements [ 2 ][ 0 ] = 0.0f;
	Target.Elements [ 2 ][ 1 ] = 0.0f;
	Target.Elements [ 2 ][ 2 ] = 1.0f;
	
}

void Xenon::Math::Matrix3x3 :: Copy ( Matrix3x3 & Target, const Matrix3x3 & Source )
{
	
	memcpy ( reinterpret_cast <void *> ( & Target ), reinterpret_cast <const void *> ( & Source ), sizeof ( Matrix3x3 ) );
	
}

void Xenon::Math::Matrix3x3 :: Transpose ( Matrix3x3 & Target )
{
	
	std::swap ( Target.Elements [ 0 ][ 1 ], Target.Elements [ 1 ][ 0 ] );
	std::swap ( Target.Elements [ 0 ][ 2 ], Target.Elements [ 2 ][ 0 ] );
	std::swap ( Target.Elements [ 1 ][ 2 ], Target.Elements [ 2 ][ 1 ] );
	
}

void Xenon::Math::Matrix3x3 :: Transpose ( Matrix3x3 & Target, const Matrix3x3 & Source )
{
	
	Copy ( Target, Source );
	
	std::swap ( Target.Elements [ 0 ][ 1 ], Target.Elements [ 1 ][ 0 ] );
	std::swap ( Target.Elements [ 0 ][ 2 ], Target.Elements [ 2 ][ 0 ] );
	std::swap ( Target.Elements [ 1 ][ 2 ], Target.Elements [ 2 ][ 1 ] );
	
}

float Xenon::Math::Matrix3x3 :: Determinant ( const Matrix3x3 & Source )
{
	
	float Sum = + Source.Elements [ 0 ][ 0 ] * ( Source.Elements [ 1 ][ 1 ] * Source.Elements [ 2 ][ 2 ] - Source.Elements [ 1 ][ 2 ] * Source.Elements [ 2 ][ 1 ] )
				- Source.Elements [ 0 ][ 1 ] * ( Source.Elements [ 1 ][ 0 ] * Source.Elements [ 2 ][ 2 ] - Source.Elements [ 1 ][ 2 ] * Source.Elements [ 2 ][ 0 ] )
				+ Source.Elements [ 0 ][ 2 ] * ( Source.Elements [ 1 ][ 0 ] * Source.Elements [ 2 ][ 1 ] - Source.Elements [ 1 ][ 1 ] * Source.Elements [ 2 ][ 0 ] );
	
	return Sum;
	
}

bool Xenon::Math::Matrix3x3 :: Invertible ( const Matrix3x3 & Source, float PrecisionThreshold )
{
	
	return fabs ( Determinant ( Source ) ) > PrecisionThreshold;
	
}

void Xenon::Math::Matrix3x3 :: Invert ( Matrix3x3 & Target )
{
	
	Matrix3x3 Temp ( NO_INIT );
	
	float InverseDeterminate = 1.0f / Determinant ( Target );
	
	Temp.Elements [ 0 ][ 0 ] = Target.Elements [ 1 ][ 1 ] * Target.Elements [ 2 ][ 2 ] - Target.Elements [ 1 ][ 2 ] * Target.Elements [ 2 ][ 1 ];
	Temp.Elements [ 0 ][ 1 ] = Target.Elements [ 0 ][ 2 ] * Target.Elements [ 2 ][ 1 ] - Target.Elements [ 0 ][ 1 ] * Target.Elements [ 2 ][ 2 ];
	Temp.Elements [ 0 ][ 2 ] = Target.Elements [ 0 ][ 1 ] * Target.Elements [ 1 ][ 2 ] - Target.Elements [ 0 ][ 2 ] * Target.Elements [ 1 ][ 1 ];
	Temp.Elements [ 1 ][ 0 ] = Target.Elements [ 1 ][ 2 ] * Target.Elements [ 2 ][ 0 ] - Target.Elements [ 1 ][ 0 ] * Target.Elements [ 2 ][ 2 ];
	Temp.Elements [ 1 ][ 1 ] = Target.Elements [ 0 ][ 0 ] * Target.Elements [ 2 ][ 2 ] - Target.Elements [ 0 ][ 2 ] * Target.Elements [ 2 ][ 0 ];
	Temp.Elements [ 1 ][ 2 ] = Target.Elements [ 0 ][ 2 ] * Target.Elements [ 1 ][ 0 ] - Target.Elements [ 0 ][ 0 ] * Target.Elements [ 1 ][ 2 ];
	Temp.Elements [ 2 ][ 0 ] = Target.Elements [ 1 ][ 0 ] * Target.Elements [ 2 ][ 1 ] - Target.Elements [ 1 ][ 1 ] * Target.Elements [ 2 ][ 0 ];
	Temp.Elements [ 2 ][ 1 ] = Target.Elements [ 0 ][ 1 ] * Target.Elements [ 2 ][ 0 ] - Target.Elements [ 0 ][ 0 ] * Target.Elements [ 2 ][ 1 ];
	Temp.Elements [ 2 ][ 2 ] = Target.Elements [ 0 ][ 0 ] * Target.Elements [ 1 ][ 1 ] - Target.Elements [ 0 ][ 1 ] * Target.Elements [ 1 ][ 0 ];
	
	MultiplyScalar ( Target, Temp, InverseDeterminate );
	
}

void Xenon::Math::Matrix3x3 :: Invert ( Matrix3x3 & Target, const Matrix3x3 & Source )
{
	
	Matrix3x3 Temp ( NO_INIT );
	
	float InverseDeterminate = 1.0f / Determinant ( Target );
	
	Temp.Elements [ 0 ][ 0 ] = Source.Elements [ 1 ][ 1 ] * Source.Elements [ 2 ][ 2 ] - Source.Elements [ 1 ][ 2 ] * Source.Elements [ 2 ][ 1 ];
	Temp.Elements [ 0 ][ 1 ] = Source.Elements [ 0 ][ 2 ] * Source.Elements [ 2 ][ 1 ] - Source.Elements [ 0 ][ 1 ] * Source.Elements [ 2 ][ 2 ];
	Temp.Elements [ 0 ][ 2 ] = Source.Elements [ 0 ][ 1 ] * Source.Elements [ 1 ][ 2 ] - Source.Elements [ 0 ][ 2 ] * Source.Elements [ 1 ][ 1 ];
	Temp.Elements [ 1 ][ 0 ] = Source.Elements [ 1 ][ 2 ] * Source.Elements [ 2 ][ 0 ] - Source.Elements [ 1 ][ 0 ] * Source.Elements [ 2 ][ 2 ];
	Temp.Elements [ 1 ][ 1 ] = Source.Elements [ 0 ][ 0 ] * Source.Elements [ 2 ][ 2 ] - Source.Elements [ 0 ][ 2 ] * Source.Elements [ 2 ][ 0 ];
	Temp.Elements [ 1 ][ 2 ] = Source.Elements [ 0 ][ 2 ] * Source.Elements [ 1 ][ 0 ] - Source.Elements [ 0 ][ 0 ] * Source.Elements [ 1 ][ 2 ];
	Temp.Elements [ 2 ][ 0 ] = Source.Elements [ 1 ][ 0 ] * Source.Elements [ 2 ][ 1 ] - Source.Elements [ 1 ][ 1 ] * Source.Elements [ 2 ][ 0 ];
	Temp.Elements [ 2 ][ 1 ] = Source.Elements [ 0 ][ 1 ] * Source.Elements [ 2 ][ 0 ] - Source.Elements [ 0 ][ 0 ] * Source.Elements [ 2 ][ 1 ];
	Temp.Elements [ 2 ][ 2 ] = Source.Elements [ 0 ][ 0 ] * Source.Elements [ 1 ][ 1 ] - Source.Elements [ 0 ][ 1 ] * Source.Elements [ 1 ][ 0 ];
	
	MultiplyScalar ( Target, Temp, InverseDeterminate );
	
}
		
void Xenon::Math::Matrix3x3 :: MultiplyScalar ( Matrix3x3 & Target, const float Scalar )
{
	
	Target.Elements [ 0 ][ 0 ] *= Scalar;
	Target.Elements [ 0 ][ 1 ] *= Scalar;
	Target.Elements [ 0 ][ 2 ] *= Scalar;
	
	Target.Elements [ 1 ][ 0 ] *= Scalar;
	Target.Elements [ 1 ][ 1 ] *= Scalar;
	Target.Elements [ 1 ][ 2 ] *= Scalar;
	
	Target.Elements [ 2 ][ 0 ] *= Scalar;
	Target.Elements [ 2 ][ 1 ] *= Scalar;
	Target.Elements [ 2 ][ 2 ] *= Scalar;
	
}

void Xenon::Math::Matrix3x3 :: MultiplyScalar ( Matrix3x3 & Target, const Matrix3x3 & Source, const float Scalar )
{
	
	Target.Elements [ 0 ][ 0 ] = Source.Elements [ 0 ][ 0 ] * Scalar;
	Target.Elements [ 0 ][ 1 ] = Source.Elements [ 0 ][ 1 ] * Scalar;
	Target.Elements [ 0 ][ 2 ] = Source.Elements [ 0 ][ 2 ] * Scalar;
	
	Target.Elements [ 1 ][ 0 ] = Source.Elements [ 1 ][ 0 ] * Scalar;
	Target.Elements [ 1 ][ 1 ] = Source.Elements [ 1 ][ 1 ] * Scalar;
	Target.Elements [ 1 ][ 2 ] = Source.Elements [ 1 ][ 2 ] * Scalar;
	
	Target.Elements [ 2 ][ 0 ] = Source.Elements [ 2 ][ 0 ] * Scalar;
	Target.Elements [ 2 ][ 1 ] = Source.Elements [ 2 ][ 1 ] * Scalar;
	Target.Elements [ 2 ][ 2 ] = Source.Elements [ 2 ][ 2 ] * Scalar;
	
}

void Xenon::Math::Matrix3x3 :: SetAsTranslation ( Matrix3x3 & Target, const Vec2 & Translation )
{
	
	Target.Elements [ 0 ][ 0 ] = 1.0f;
	Target.Elements [ 0 ][ 1 ] = 0.0f;
	Target.Elements [ 0 ][ 2 ] = Translation.X;
	
	Target.Elements [ 1 ][ 0 ] = 0.0f;
	Target.Elements [ 1 ][ 1 ] = 1.0f;
	Target.Elements [ 1 ][ 2 ] = Translation.Y;
	
	Target.Elements [ 2 ][ 0 ] = 0.0f;
	Target.Elements [ 2 ][ 1 ] = 0.0f;
	Target.Elements [ 2 ][ 2 ] = 1.0f;
	
}

void Xenon::Math::Matrix3x3 :: SetAsTranslation ( Matrix3x3 & Target, const float X, const float Y )
{
	
	Target.Elements [ 0 ][ 0 ] = 1.0f;
	Target.Elements [ 0 ][ 1 ] = 0.0f;
	Target.Elements [ 0 ][ 2 ] = X;
	
	Target.Elements [ 1 ][ 0 ] = 0.0f;
	Target.Elements [ 1 ][ 1 ] = 1.0f;
	Target.Elements [ 1 ][ 2 ] = Y;
	
	Target.Elements [ 2 ][ 0 ] = 0.0f;
	Target.Elements [ 2 ][ 1 ] = 0.0f;
	Target.Elements [ 2 ][ 2 ] = 1.0f;
	
}

void Xenon::Math::Matrix3x3 :: AppendTranslation ( Matrix3x3 & Target, const Vec2 & Translation )
{
	
	Target.Elements [ 0 ][ 0 ] += Target.Elements [ 2 ][ 0 ] * Translation.X;
	Target.Elements [ 0 ][ 1 ] += Target.Elements [ 2 ][ 1 ] * Translation.X;
	Target.Elements [ 0 ][ 2 ] += Target.Elements [ 2 ][ 2 ] * Translation.X;
	
	Target.Elements [ 1 ][ 0 ] += Target.Elements [ 2 ][ 0 ] * Translation.Y;
	Target.Elements [ 1 ][ 1 ] += Target.Elements [ 2 ][ 1 ] * Translation.Y;
	Target.Elements [ 1 ][ 2 ] += Target.Elements [ 2 ][ 2 ] * Translation.Y;
	
}

void Xenon::Math::Matrix3x3 :: AppendTranslation ( Matrix3x3 & Target, const float X, const float Y )
{
	
	Target.Elements [ 0 ][ 0 ] += Target.Elements [ 2 ][ 0 ] * X;
	Target.Elements [ 0 ][ 1 ] += Target.Elements [ 2 ][ 1 ] * X;
	Target.Elements [ 0 ][ 2 ] += Target.Elements [ 2 ][ 2 ] * X;
	
	Target.Elements [ 1 ][ 0 ] += Target.Elements [ 2 ][ 0 ] * Y;
	Target.Elements [ 1 ][ 1 ] += Target.Elements [ 2 ][ 1 ] * Y;
	Target.Elements [ 1 ][ 2 ] += Target.Elements [ 2 ][ 2 ] * Y;
	
}

void Xenon::Math::Matrix3x3 :: AppendTranslation ( Matrix3x3 & Target, const Matrix3x3 & Source, const Vec2 & Translation )
{
	
	Target.Elements [ 0 ][ 0 ] += Source.Elements [ 2 ][ 0 ] * Translation.X + Source.Elements [ 0 ][ 0 ];
	Target.Elements [ 0 ][ 1 ] += Source.Elements [ 2 ][ 1 ] * Translation.X + Source.Elements [ 0 ][ 1 ];
	Target.Elements [ 0 ][ 2 ] += Source.Elements [ 2 ][ 2 ] * Translation.X + Source.Elements [ 0 ][ 2 ];
	
	Target.Elements [ 1 ][ 0 ] += Source.Elements [ 2 ][ 0 ] * Translation.Y + Source.Elements [ 1 ][ 0 ];
	Target.Elements [ 1 ][ 1 ] += Source.Elements [ 2 ][ 1 ] * Translation.Y + Source.Elements [ 1 ][ 1 ];
	Target.Elements [ 1 ][ 2 ] += Source.Elements [ 2 ][ 2 ] * Translation.Y + Source.Elements [ 1 ][ 2 ];
	
	Target.Elements [ 2 ][ 0 ] = Source.Elements [ 2 ][ 0 ];
	Target.Elements [ 2 ][ 1 ] = Source.Elements [ 2 ][ 1 ];
	Target.Elements [ 2 ][ 2 ] = Source.Elements [ 2 ][ 2 ];
	
}

void Xenon::Math::Matrix3x3 :: AppendTranslation ( Matrix3x3 & Target, const Matrix3x3 & Source, const float X, const float Y )
{
	
	Target.Elements [ 0 ][ 0 ] += Source.Elements [ 2 ][ 0 ] * X + Source.Elements [ 0 ][ 0 ];
	Target.Elements [ 0 ][ 1 ] += Source.Elements [ 2 ][ 1 ] * X + Source.Elements [ 0 ][ 1 ];
	Target.Elements [ 0 ][ 2 ] += Source.Elements [ 2 ][ 2 ] * X + Source.Elements [ 0 ][ 2 ];
	
	Target.Elements [ 1 ][ 0 ] += Source.Elements [ 2 ][ 0 ] * Y + Source.Elements [ 1 ][ 0 ];
	Target.Elements [ 1 ][ 1 ] += Source.Elements [ 2 ][ 1 ] * Y + Source.Elements [ 1 ][ 1 ];
	Target.Elements [ 1 ][ 2 ] += Source.Elements [ 2 ][ 2 ] * Y + Source.Elements [ 1 ][ 2 ];
	
	Target.Elements [ 2 ][ 0 ] = Source.Elements [ 2 ][ 0 ];
	Target.Elements [ 2 ][ 1 ] = Source.Elements [ 2 ][ 1 ];
	Target.Elements [ 2 ][ 2 ] = Source.Elements [ 2 ][ 2 ];
	
}
			

void Xenon::Math::Matrix3x3 :: PrependTranslation ( Matrix3x3 & Target, const Vec2 & Translation )
{
	
	Target.Elements [ 0 ][ 0 ] += Target.Elements [ 2 ][ 0 ] * Translation.X;
	Target.Elements [ 0 ][ 1 ] += Target.Elements [ 2 ][ 1 ] * Translation.X;
	Target.Elements [ 0 ][ 2 ] += Target.Elements [ 2 ][ 2 ] * Translation.X;
	
	Target.Elements [ 1 ][ 0 ] += Target.Elements [ 2 ][ 0 ] * Translation.Y;
	Target.Elements [ 1 ][ 1 ] += Target.Elements [ 2 ][ 1 ] * Translation.Y;
	Target.Elements [ 1 ][ 2 ] += Target.Elements [ 2 ][ 2 ] * Translation.Y;
	
}
			

void Xenon::Math::Matrix3x3 :: PrependTranslation ( Matrix3x3 & Target, const float X, const float Y )
{
	
	Target.Elements [ 0 ][ 0 ] += Target.Elements [ 2 ][ 0 ] * X;
	Target.Elements [ 0 ][ 1 ] += Target.Elements [ 2 ][ 1 ] * X;
	Target.Elements [ 0 ][ 2 ] += Target.Elements [ 2 ][ 2 ] * X;
	
	Target.Elements [ 1 ][ 0 ] += Target.Elements [ 2 ][ 0 ] * Y;
	Target.Elements [ 1 ][ 1 ] += Target.Elements [ 2 ][ 1 ] * Y;
	Target.Elements [ 1 ][ 2 ] += Target.Elements [ 2 ][ 2 ] * Y;
	
}

void Xenon::Math::Matrix3x3 :: PrependTranslation ( Matrix3x3 & Target, const Matrix3x3 & Source, const Vec2 & Translation )
{
	
	Target.Elements [ 0 ][ 0 ] = Source.Elements [ 0 ][ 0 ] + Source.Elements [ 2 ][ 0 ] * Translation.X;
	Target.Elements [ 0 ][ 1 ] = Source.Elements [ 0 ][ 1 ] + Source.Elements [ 2 ][ 1 ] * Translation.X;
	Target.Elements [ 0 ][ 2 ] = Source.Elements [ 0 ][ 2 ] + Source.Elements [ 2 ][ 2 ] * Translation.X;
	
	Target.Elements [ 1 ][ 0 ] = Source.Elements [ 1 ][ 0 ] + Source.Elements [ 2 ][ 0 ] * Translation.Y;
	Target.Elements [ 1 ][ 1 ] = Source.Elements [ 1 ][ 1 ] + Source.Elements [ 2 ][ 1 ] * Translation.Y;
	Target.Elements [ 1 ][ 2 ] = Source.Elements [ 1 ][ 2 ] + Source.Elements [ 2 ][ 2 ] * Translation.Y;
	
}

void Xenon::Math::Matrix3x3 :: PrependTranslation ( Matrix3x3 & Target, const Matrix3x3 & Source, const float X, const float Y )
{
	
	Target.Elements [ 0 ][ 0 ] = Source.Elements [ 0 ][ 0 ] + Source.Elements [ 2 ][ 0 ] * X;
	Target.Elements [ 0 ][ 1 ] = Source.Elements [ 0 ][ 1 ] + Source.Elements [ 2 ][ 1 ] * X;
	Target.Elements [ 0 ][ 2 ] = Source.Elements [ 0 ][ 2 ] + Source.Elements [ 2 ][ 2 ] * X;
	
	Target.Elements [ 1 ][ 0 ] = Source.Elements [ 1 ][ 0 ] + Source.Elements [ 2 ][ 0 ] * Y;
	Target.Elements [ 1 ][ 1 ] = Source.Elements [ 1 ][ 1 ] + Source.Elements [ 2 ][ 1 ] * Y;
	Target.Elements [ 1 ][ 2 ] = Source.Elements [ 1 ][ 2 ] + Source.Elements [ 2 ][ 2 ] * Y;
	
}

void Xenon::Math::Matrix3x3 :: SetAsRotation ( Matrix3x3 & Target, const float Rotation )
{
	
	float Cos = cos ( Rotation );
	float Sin = sin ( Rotation );
	
	Target.Elements [ 0 ][ 0 ] = Cos;
	Target.Elements [ 0 ][ 1 ] = - Sin;
	Target.Elements [ 0 ][ 2 ] = 0.0f;
	
	Target.Elements [ 1 ][ 0 ] = Sin;
	Target.Elements [ 1 ][ 1 ] = Cos;
	Target.Elements [ 1 ][ 2 ] = 0.0f;
	
	Target.Elements [ 2 ][ 0 ] = 0.0f;
	Target.Elements [ 2 ][ 1 ] = 0.0f;
	Target.Elements [ 2 ][ 2 ] = 1.0f;
	
}

void Xenon::Math::Matrix3x3 :: PrependRotation ( Matrix3x3 & Target, const float Rotation )
{
	
	float Cos = cos ( Rotation );
	float Sin = sin ( Rotation );
	
	float E00Temp = Target.Elements [ 0 ][ 0 ] * Cos + Target.Elements [ 1 ][ 0 ] * Sin;
	float E01Temp = Target.Elements [ 0 ][ 1 ] * Cos + Target.Elements [ 1 ][ 1 ] * Sin;
	float E02Temp = Target.Elements [ 0 ][ 2 ] * Cos + Target.Elements [ 1 ][ 2 ] * Sin;
	
	Target.Elements [ 1 ][ 0 ] = Target.Elements [ 1 ][ 0 ] * Cos - Target.Elements [ 0 ][ 0 ] * Sin;
	Target.Elements [ 1 ][ 1 ] = Target.Elements [ 1 ][ 1 ] * Cos - Target.Elements [ 0 ][ 1 ] * Sin;
	Target.Elements [ 1 ][ 2 ] = Target.Elements [ 1 ][ 2 ] * Cos - Target.Elements [ 0 ][ 2 ] * Sin;
	
	Target.Elements [ 0 ][ 0 ] = E00Temp;
	Target.Elements [ 0 ][ 1 ] = E01Temp;
	Target.Elements [ 0 ][ 2 ] = E02Temp;
	
}

void Xenon::Math::Matrix3x3 :: PrependRotation ( Matrix3x3 & Target, const Matrix3x3 & Source, const float Rotation )
{
	
	float Cos = cos ( Rotation );
	float Sin = sin ( Rotation );
	
	Target.Elements [ 0 ][ 0 ] = Source.Elements [ 0 ][ 0 ] * Cos + Source.Elements [ 1 ][ 0 ] * Sin;
	Target.Elements [ 0 ][ 1 ] = Source.Elements [ 0 ][ 1 ] * Cos + Source.Elements [ 1 ][ 1 ] * Sin;
	Target.Elements [ 0 ][ 2 ] = Source.Elements [ 0 ][ 2 ] * Cos + Source.Elements [ 1 ][ 2 ] * Sin;
	
	Target.Elements [ 1 ][ 0 ] = Source.Elements [ 1 ][ 0 ] * Cos - Source.Elements [ 0 ][ 0 ] * Sin;
	Target.Elements [ 1 ][ 1 ] = Source.Elements [ 1 ][ 1 ] * Cos - Source.Elements [ 0 ][ 1 ] * Sin;
	Target.Elements [ 1 ][ 2 ] = Source.Elements [ 1 ][ 2 ] * Cos - Source.Elements [ 0 ][ 2 ] * Sin;
	
	Target.Elements [ 2 ][ 0 ] = Source.Elements [ 2 ][ 0 ];
	Target.Elements [ 2 ][ 1 ] = Source.Elements [ 2 ][ 1 ];
	Target.Elements [ 2 ][ 2 ] = Source.Elements [ 2 ][ 2 ];
	
}

void Xenon::Math::Matrix3x3 :: AppendRotation ( Matrix3x3 & Target, const float Rotation )
{
	
	float Cos = cos ( Rotation );
	float Sin = sin ( Rotation );
	
	float Temp00 = Target.Elements [ 0 ][ 0 ];
	float Temp01 = Target.Elements [ 0 ][ 1 ];
	float Temp10 = Target.Elements [ 1 ][ 0 ];
	float Temp11 = Target.Elements [ 1 ][ 1 ];
	float Temp20 = Target.Elements [ 2 ][ 0 ];
	float Temp21 = Target.Elements [ 2 ][ 1 ];
	
	Target.Elements [ 0 ][ 0 ] = Temp00 * Cos - Temp01 * Sin;
	Target.Elements [ 0 ][ 1 ] = Temp01 * Cos + Temp00 * Sin;
	
	Target.Elements [ 1 ][ 0 ] = Temp10 * Cos - Temp11 * Sin;
	Target.Elements [ 1 ][ 1 ] = Temp11 * Cos + Temp10 * Sin;
	
	Target.Elements [ 2 ][ 0 ] = Temp20 * Cos - Temp21 * Sin;
	Target.Elements [ 2 ][ 1 ] = Temp21 * Cos + Temp20 * Sin;
	
}

void Xenon::Math::Matrix3x3 :: AppendRotation ( Matrix3x3 & Target, const Matrix3x3 & Source, const float Rotation )
{
	
	float Cos = cos ( Rotation );
	float Sin = sin ( Rotation );
	
	Target.Elements [ 0 ][ 0 ] = Source.Elements [ 0 ][ 0 ] * Cos - Source.Elements [ 0 ][ 1 ] * Sin;
	Target.Elements [ 0 ][ 1 ] = Source.Elements [ 0 ][ 1 ] * Cos + Source.Elements [ 0 ][ 0 ] * Sin;
	Target.Elements [ 0 ][ 2 ] = Source.Elements [ 0 ][ 2 ];
	
	Target.Elements [ 1 ][ 0 ] = Source.Elements [ 1 ][ 0 ] * Cos - Source.Elements [ 1 ][ 1 ] * Sin;
	Target.Elements [ 1 ][ 1 ] = Source.Elements [ 1 ][ 1 ] * Cos + Source.Elements [ 1 ][ 0 ] * Sin;
	Target.Elements [ 1 ][ 2 ] = Source.Elements [ 1 ][ 2 ];
	
	Target.Elements [ 2 ][ 0 ] = Source.Elements [ 1 ][ 0 ] * Cos - Source.Elements [ 1 ][ 1 ] * Sin;
	Target.Elements [ 2 ][ 1 ] = Source.Elements [ 1 ][ 1 ] * Cos + Source.Elements [ 1 ][ 0 ] * Sin;
	Target.Elements [ 2 ][ 2 ] = Source.Elements [ 2 ][ 2 ];
	
}

void Xenon::Math::Matrix3x3 :: SetAsScale ( Matrix3x3 & Target, const Vec2 & Scale )
{
	
	Target.Elements [ 0 ][ 0 ] = Scale.X;
	Target.Elements [ 0 ][ 1 ] = Target.Elements [ 0 ][ 2 ] = 0.0f;
	
	Target.Elements [ 1 ][ 1 ] = Scale.Y;
	Target.Elements [ 1 ][ 0 ] = Target.Elements [ 1 ][ 2 ] = 0.0f;
	
	Target.Elements [ 2 ][ 2 ] = 1.0f;
	Target.Elements [ 2 ][ 1 ] = Target.Elements [ 2 ][ 0 ] = 0.0f;
	
}

void Xenon::Math::Matrix3x3 :: SetAsScale ( Matrix3x3 & Target, const float X, const float Y )
{
	
	Target.Elements [ 0 ][ 0 ] = X;
	Target.Elements [ 0 ][ 1 ] = Target.Elements [ 0 ][ 2 ] = 0.0f;
	
	Target.Elements [ 1 ][ 1 ] = Y;
	Target.Elements [ 1 ][ 0 ] = Target.Elements [ 1 ][ 2 ] = 0.0f;
	
	Target.Elements [ 2 ][ 2 ] = 1.0f;
	Target.Elements [ 2 ][ 1 ] = Target.Elements [ 2 ][ 0 ] = 0.0f;
	
}

void Xenon::Math::Matrix3x3 :: AppendScale ( Matrix3x3 & Target, const Vec2 & Scale )
{
	
	Target.Elements [ 0 ][ 0 ] *= Scale.X;
	Target.Elements [ 1 ][ 0 ] *= Scale.X;
	Target.Elements [ 2 ][ 0 ] *= Scale.X;
	
	Target.Elements [ 0 ][ 1 ] *= Scale.Y;
	Target.Elements [ 1 ][ 1 ] *= Scale.Y;
	Target.Elements [ 2 ][ 1 ] *= Scale.Y;
	
}

void Xenon::Math::Matrix3x3 :: AppendScale ( Matrix3x3 & Target, const float X, const float Y )
{
	
	Target.Elements [ 0 ][ 0 ] *= X;
	Target.Elements [ 1 ][ 0 ] *= X;
	Target.Elements [ 2 ][ 0 ] *= X;
	
	Target.Elements [ 0 ][ 1 ] *= Y;
	Target.Elements [ 1 ][ 1 ] *= Y;
	Target.Elements [ 2 ][ 1 ] *= Y;
	
}

void Xenon::Math::Matrix3x3 :: AppendScale ( Matrix3x3 & Target, const Matrix3x3 & Source, const Vec2 & Scale )
{
	
	Target.Elements [ 0 ][ 0 ] = Source.Elements [ 0 ][ 0 ] * Scale.X;
	Target.Elements [ 1 ][ 0 ] = Source.Elements [ 1 ][ 0 ] * Scale.X;
	Target.Elements [ 2 ][ 0 ] = Source.Elements [ 2 ][ 0 ] * Scale.X;
	
	Target.Elements [ 0 ][ 1 ] = Source.Elements [ 0 ][ 1 ] * Scale.Y;
	Target.Elements [ 1 ][ 1 ] = Source.Elements [ 1 ][ 1 ] * Scale.Y;
	Target.Elements [ 2 ][ 1 ] = Source.Elements [ 2 ][ 1 ] * Scale.Y;
	
	Target.Elements [ 0 ][ 2 ] = Source.Elements [ 0 ][ 2 ];
	Target.Elements [ 1 ][ 2 ] = Source.Elements [ 1 ][ 2 ];
	Target.Elements [ 2 ][ 2 ] = Source.Elements [ 2 ][ 2 ];
	
}

void Xenon::Math::Matrix3x3 :: AppendScale ( Matrix3x3 & Target, const Matrix3x3 & Source, const float X, const float Y )
{
	
	Target.Elements [ 0 ][ 0 ] = Source.Elements [ 0 ][ 0 ] * X;
	Target.Elements [ 1 ][ 0 ] = Source.Elements [ 1 ][ 0 ] * X;
	Target.Elements [ 2 ][ 0 ] = Source.Elements [ 2 ][ 0 ] * X;
	
	Target.Elements [ 0 ][ 1 ] = Source.Elements [ 0 ][ 1 ] * Y;
	Target.Elements [ 1 ][ 1 ] = Source.Elements [ 1 ][ 1 ] * Y;
	Target.Elements [ 2 ][ 1 ] = Source.Elements [ 2 ][ 1 ] * Y;
	
	Target.Elements [ 0 ][ 2 ] = Source.Elements [ 0 ][ 2 ];
	Target.Elements [ 1 ][ 2 ] = Source.Elements [ 1 ][ 2 ];
	Target.Elements [ 2 ][ 2 ] = Source.Elements [ 2 ][ 2 ];
	
}

void Xenon::Math::Matrix3x3 :: PrependScale ( Matrix3x3 & Target, const Vec2 & Scale )
{
	
	Target.Elements [ 0 ][ 0 ] *= Scale.X;
	Target.Elements [ 0 ][ 1 ] *= Scale.X;
	Target.Elements [ 0 ][ 2 ] *= Scale.X;
	
	Target.Elements [ 1 ][ 0 ] *= Scale.Y;
	Target.Elements [ 1 ][ 1 ] *= Scale.Y;
	Target.Elements [ 1 ][ 2 ] *= Scale.Y;
	
}

void Xenon::Math::Matrix3x3 :: PrependScale ( Matrix3x3 & Target, const float X, const float Y )
{
	
	Target.Elements [ 0 ][ 0 ] *= X;
	Target.Elements [ 0 ][ 1 ] *= X;
	Target.Elements [ 0 ][ 2 ] *= X;
	
	Target.Elements [ 1 ][ 0 ] *= Y;
	Target.Elements [ 1 ][ 1 ] *= Y;
	Target.Elements [ 1 ][ 2 ] *= Y;
	
}

void Xenon::Math::Matrix3x3 :: PrependScale ( Matrix3x3 & Target, const Matrix3x3 & Source, const Vec2 & Scale )
{
	
	Target.Elements [ 0 ][ 0 ] = Source.Elements [ 0 ][ 0 ] * Scale.X;
	Target.Elements [ 0 ][ 1 ] = Source.Elements [ 0 ][ 1 ] * Scale.X;
	Target.Elements [ 0 ][ 2 ] = Source.Elements [ 0 ][ 2 ] * Scale.X;
	
	Target.Elements [ 1 ][ 0 ] = Source.Elements [ 1 ][ 0 ] * Scale.Y;
	Target.Elements [ 1 ][ 1 ] = Source.Elements [ 1 ][ 1 ] * Scale.Y;
	Target.Elements [ 1 ][ 2 ] = Source.Elements [ 1 ][ 2 ] * Scale.Y;
	
	Target.Elements [ 2 ][ 0 ] = Source.Elements [ 2 ][ 0 ];
	Target.Elements [ 2 ][ 1 ] = Source.Elements [ 2 ][ 1 ];
	Target.Elements [ 2 ][ 2 ] = Source.Elements [ 2 ][ 2 ];
	
}

void Xenon::Math::Matrix3x3 :: PrependScale ( Matrix3x3 & Target, const Matrix3x3 & Source, const float X, const float Y )
{
	
	Target.Elements [ 0 ][ 0 ] = Source.Elements [ 0 ][ 0 ] * X;
	Target.Elements [ 0 ][ 1 ] = Source.Elements [ 0 ][ 1 ] * X;
	Target.Elements [ 0 ][ 2 ] = Source.Elements [ 0 ][ 2 ] * X;
	
	Target.Elements [ 1 ][ 0 ] = Source.Elements [ 1 ][ 0 ] * Y;
	Target.Elements [ 1 ][ 1 ] = Source.Elements [ 1 ][ 1 ] * Y;
	Target.Elements [ 1 ][ 2 ] = Source.Elements [ 1 ][ 2 ] * Y;
	
	Target.Elements [ 2 ][ 0 ] = Source.Elements [ 2 ][ 0 ];
	Target.Elements [ 2 ][ 1 ] = Source.Elements [ 2 ][ 1 ];
	Target.Elements [ 2 ][ 2 ] = Source.Elements [ 2 ][ 2 ];
	
}

void Xenon::Math::Matrix3x3 :: Append ( Matrix3x3 & Target, const Matrix3x3 & Pendant )
{
	
	Matrix3x3 Temp ( NO_INIT );
	
	Temp.Elements [ 0 ][ 0 ] = Target.Elements [ 0 ][ 0 ] * Pendant.Elements [ 0 ][ 0 ] + Target.Elements [ 0 ][ 1 ] * Pendant.Elements [ 1 ][ 0 ] + Target.Elements [ 0 ][ 2 ] * Pendant.Elements [ 2 ][ 0 ];
	Temp.Elements [ 0 ][ 1 ] = Target.Elements [ 0 ][ 0 ] * Pendant.Elements [ 0 ][ 1 ] + Target.Elements [ 0 ][ 1 ] * Pendant.Elements [ 1 ][ 1 ] + Target.Elements [ 0 ][ 2 ] * Pendant.Elements [ 2 ][ 1 ];
	Temp.Elements [ 0 ][ 2 ] = Target.Elements [ 0 ][ 0 ] * Pendant.Elements [ 0 ][ 2 ] + Target.Elements [ 0 ][ 1 ] * Pendant.Elements [ 1 ][ 2 ] + Target.Elements [ 0 ][ 2 ] * Pendant.Elements [ 2 ][ 2 ];
	
	Temp.Elements [ 1 ][ 0 ] = Target.Elements [ 1 ][ 0 ] * Pendant.Elements [ 0 ][ 0 ] + Target.Elements [ 1 ][ 1 ] * Pendant.Elements [ 1 ][ 0 ] + Target.Elements [ 1 ][ 2 ] * Pendant.Elements [ 2 ][ 0 ];
	Temp.Elements [ 1 ][ 1 ] = Target.Elements [ 1 ][ 0 ] * Pendant.Elements [ 0 ][ 1 ] + Target.Elements [ 1 ][ 1 ] * Pendant.Elements [ 1 ][ 1 ] + Target.Elements [ 1 ][ 2 ] * Pendant.Elements [ 2 ][ 1 ];
	Temp.Elements [ 1 ][ 2 ] = Target.Elements [ 1 ][ 0 ] * Pendant.Elements [ 0 ][ 2 ] + Target.Elements [ 1 ][ 1 ] * Pendant.Elements [ 1 ][ 2 ] + Target.Elements [ 1 ][ 2 ] * Pendant.Elements [ 2 ][ 2 ];
	
	Temp.Elements [ 2 ][ 0 ] = Target.Elements [ 2 ][ 0 ] * Pendant.Elements [ 0 ][ 0 ] + Target.Elements [ 2 ][ 1 ] * Pendant.Elements [ 1 ][ 0 ] + Target.Elements [ 2 ][ 2 ] * Pendant.Elements [ 2 ][ 0 ];
	Temp.Elements [ 2 ][ 1 ] = Target.Elements [ 2 ][ 0 ] * Pendant.Elements [ 0 ][ 1 ] + Target.Elements [ 2 ][ 1 ] * Pendant.Elements [ 1 ][ 1 ] + Target.Elements [ 2 ][ 2 ] * Pendant.Elements [ 2 ][ 1 ];
	Temp.Elements [ 2 ][ 2 ] = Target.Elements [ 2 ][ 0 ] * Pendant.Elements [ 0 ][ 2 ] + Target.Elements [ 2 ][ 1 ] * Pendant.Elements [ 1 ][ 2 ] + Target.Elements [ 2 ][ 2 ] * Pendant.Elements [ 2 ][ 2 ];
	
	Copy ( Target, Temp );
	
}

void Xenon::Math::Matrix3x3 :: Append ( Matrix3x3 & Target, const Matrix3x3 & Source, const Matrix3x3 & Pendant )
{
	
	Target.Elements [ 0 ][ 0 ] = Source.Elements [ 0 ][ 0 ] * Pendant.Elements [ 0 ][ 0 ] + Source.Elements [ 0 ][ 1 ] * Pendant.Elements [ 1 ][ 0 ] + Source.Elements [ 0 ][ 2 ] * Pendant.Elements [ 2 ][ 0 ];
	Target.Elements [ 0 ][ 1 ] = Source.Elements [ 0 ][ 0 ] * Pendant.Elements [ 0 ][ 1 ] + Source.Elements [ 0 ][ 1 ] * Pendant.Elements [ 1 ][ 1 ] + Source.Elements [ 0 ][ 2 ] * Pendant.Elements [ 2 ][ 1 ];
	Target.Elements [ 0 ][ 2 ] = Source.Elements [ 0 ][ 0 ] * Pendant.Elements [ 0 ][ 2 ] + Source.Elements [ 0 ][ 1 ] * Pendant.Elements [ 1 ][ 2 ] + Source.Elements [ 0 ][ 2 ] * Pendant.Elements [ 2 ][ 2 ];
	
	Target.Elements [ 1 ][ 0 ] = Source.Elements [ 1 ][ 0 ] * Pendant.Elements [ 0 ][ 0 ] + Source.Elements [ 1 ][ 1 ] * Pendant.Elements [ 1 ][ 0 ] + Source.Elements [ 1 ][ 2 ] * Pendant.Elements [ 2 ][ 0 ];
	Target.Elements [ 1 ][ 1 ] = Source.Elements [ 1 ][ 0 ] * Pendant.Elements [ 0 ][ 1 ] + Source.Elements [ 1 ][ 1 ] * Pendant.Elements [ 1 ][ 1 ] + Source.Elements [ 1 ][ 2 ] * Pendant.Elements [ 2 ][ 1 ];
	Target.Elements [ 1 ][ 2 ] = Source.Elements [ 1 ][ 0 ] * Pendant.Elements [ 0 ][ 2 ] + Source.Elements [ 1 ][ 1 ] * Pendant.Elements [ 1 ][ 2 ] + Source.Elements [ 1 ][ 2 ] * Pendant.Elements [ 2 ][ 2 ];
	
	Target.Elements [ 2 ][ 0 ] = Source.Elements [ 2 ][ 0 ] * Pendant.Elements [ 0 ][ 0 ] + Source.Elements [ 2 ][ 1 ] * Pendant.Elements [ 1 ][ 0 ] + Source.Elements [ 2 ][ 2 ] * Pendant.Elements [ 2 ][ 0 ];
	Target.Elements [ 2 ][ 1 ] = Source.Elements [ 2 ][ 0 ] * Pendant.Elements [ 0 ][ 1 ] + Source.Elements [ 2 ][ 1 ] * Pendant.Elements [ 1 ][ 1 ] + Source.Elements [ 2 ][ 2 ] * Pendant.Elements [ 2 ][ 1 ];
	Target.Elements [ 2 ][ 2 ] = Source.Elements [ 2 ][ 0 ] * Pendant.Elements [ 0 ][ 2 ] + Source.Elements [ 2 ][ 1 ] * Pendant.Elements [ 1 ][ 2 ] + Source.Elements [ 2 ][ 2 ] * Pendant.Elements [ 2 ][ 2 ];
	
}

void Xenon::Math::Matrix3x3 :: Prepend ( Matrix3x3 & Target, const Matrix3x3 & Pendant )
{
	
	Matrix3x3 Temp ( NO_INIT );
	
	Temp.Elements [ 0 ][ 0 ] = Pendant.Elements [ 0 ][ 0 ] * Target.Elements [ 0 ][ 0 ] + Pendant.Elements [ 0 ][ 1 ] * Target.Elements [ 1 ][ 0 ] + Pendant.Elements [ 0 ][ 2 ] * Target.Elements [ 2 ][ 0 ];
	Temp.Elements [ 0 ][ 1 ] = Pendant.Elements [ 0 ][ 0 ] * Target.Elements [ 0 ][ 1 ] + Pendant.Elements [ 0 ][ 1 ] * Target.Elements [ 1 ][ 1 ] + Pendant.Elements [ 0 ][ 2 ] * Target.Elements [ 2 ][ 1 ];
	Temp.Elements [ 0 ][ 2 ] = Pendant.Elements [ 0 ][ 0 ] * Target.Elements [ 0 ][ 2 ] + Pendant.Elements [ 0 ][ 1 ] * Target.Elements [ 1 ][ 2 ] + Pendant.Elements [ 0 ][ 2 ] * Target.Elements [ 2 ][ 2 ];
	
	Temp.Elements [ 1 ][ 0 ] = Pendant.Elements [ 1 ][ 0 ] * Target.Elements [ 0 ][ 0 ] + Pendant.Elements [ 1 ][ 1 ] * Target.Elements [ 1 ][ 0 ] + Pendant.Elements [ 1 ][ 2 ] * Target.Elements [ 2 ][ 0 ];
	Temp.Elements [ 1 ][ 1 ] = Pendant.Elements [ 1 ][ 0 ] * Target.Elements [ 0 ][ 1 ] + Pendant.Elements [ 1 ][ 1 ] * Target.Elements [ 1 ][ 1 ] + Pendant.Elements [ 1 ][ 2 ] * Target.Elements [ 2 ][ 1 ];
	Temp.Elements [ 1 ][ 2 ] = Pendant.Elements [ 1 ][ 0 ] * Target.Elements [ 0 ][ 2 ] + Pendant.Elements [ 1 ][ 1 ] * Target.Elements [ 1 ][ 2 ] + Pendant.Elements [ 1 ][ 2 ] * Target.Elements [ 2 ][ 2 ];
	
	Temp.Elements [ 2 ][ 0 ] = Pendant.Elements [ 2 ][ 0 ] * Target.Elements [ 0 ][ 0 ] + Pendant.Elements [ 2 ][ 1 ] * Target.Elements [ 1 ][ 0 ] + Pendant.Elements [ 2 ][ 2 ] * Target.Elements [ 2 ][ 0 ];
	Temp.Elements [ 2 ][ 1 ] = Pendant.Elements [ 2 ][ 0 ] * Target.Elements [ 0 ][ 1 ] + Pendant.Elements [ 2 ][ 1 ] * Target.Elements [ 1 ][ 1 ] + Pendant.Elements [ 2 ][ 2 ] * Target.Elements [ 2 ][ 1 ];
	Temp.Elements [ 2 ][ 2 ] = Pendant.Elements [ 2 ][ 0 ] * Target.Elements [ 0 ][ 2 ] + Pendant.Elements [ 2 ][ 1 ] * Target.Elements [ 1 ][ 2 ] + Pendant.Elements [ 2 ][ 2 ] * Target.Elements [ 2 ][ 2 ];
	
	Copy ( Target, Temp );
	
}

void Xenon::Math::Matrix3x3 :: Prepend ( Matrix3x3 & Target, const Matrix3x3 & Source, const Matrix3x3 & Pendant )
{
	
	Target.Elements [ 0 ][ 0 ] = Pendant.Elements [ 0 ][ 0 ] * Source.Elements [ 0 ][ 0 ] + Pendant.Elements [ 0 ][ 1 ] * Source.Elements [ 1 ][ 0 ] + Pendant.Elements [ 0 ][ 2 ] * Source.Elements [ 2 ][ 0 ];
	Target.Elements [ 0 ][ 1 ] = Pendant.Elements [ 0 ][ 0 ] * Source.Elements [ 0 ][ 1 ] + Pendant.Elements [ 0 ][ 1 ] * Source.Elements [ 1 ][ 1 ] + Pendant.Elements [ 0 ][ 2 ] * Source.Elements [ 2 ][ 1 ];
	Target.Elements [ 0 ][ 2 ] = Pendant.Elements [ 0 ][ 0 ] * Source.Elements [ 0 ][ 2 ] + Pendant.Elements [ 0 ][ 1 ] * Source.Elements [ 1 ][ 2 ] + Pendant.Elements [ 0 ][ 2 ] * Source.Elements [ 2 ][ 2 ];
	
	Target.Elements [ 1 ][ 0 ] = Pendant.Elements [ 1 ][ 0 ] * Source.Elements [ 0 ][ 0 ] + Pendant.Elements [ 1 ][ 1 ] * Source.Elements [ 1 ][ 0 ] + Pendant.Elements [ 1 ][ 2 ] * Source.Elements [ 2 ][ 0 ];
	Target.Elements [ 1 ][ 1 ] = Pendant.Elements [ 1 ][ 0 ] * Source.Elements [ 0 ][ 1 ] + Pendant.Elements [ 1 ][ 1 ] * Source.Elements [ 1 ][ 1 ] + Pendant.Elements [ 1 ][ 2 ] * Source.Elements [ 2 ][ 1 ];
	Target.Elements [ 1 ][ 2 ] = Pendant.Elements [ 1 ][ 0 ] * Source.Elements [ 0 ][ 2 ] + Pendant.Elements [ 1 ][ 1 ] * Source.Elements [ 1 ][ 2 ] + Pendant.Elements [ 1 ][ 2 ] * Source.Elements [ 2 ][ 2 ];
	
	Target.Elements [ 2 ][ 0 ] = Pendant.Elements [ 2 ][ 0 ] * Source.Elements [ 0 ][ 0 ] + Pendant.Elements [ 2 ][ 1 ] * Source.Elements [ 1 ][ 0 ] + Pendant.Elements [ 2 ][ 2 ] * Source.Elements [ 2 ][ 0 ];
	Target.Elements [ 2 ][ 1 ] = Pendant.Elements [ 2 ][ 0 ] * Source.Elements [ 0 ][ 1 ] + Pendant.Elements [ 2 ][ 1 ] * Source.Elements [ 1 ][ 1 ] + Pendant.Elements [ 2 ][ 2 ] * Source.Elements [ 2 ][ 1 ];
	Target.Elements [ 2 ][ 2 ] = Pendant.Elements [ 2 ][ 0 ] * Source.Elements [ 0 ][ 2 ] + Pendant.Elements [ 2 ][ 1 ] * Source.Elements [ 1 ][ 2 ] + Pendant.Elements [ 2 ][ 2 ] * Source.Elements [ 2 ][ 2 ];
	
}
