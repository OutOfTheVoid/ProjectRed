#include <Xenon/Math/Transform2D.h>

Xenon::Math::Transform2D :: Transform2D ():
	Translation ( Vec2 :: ZERO ),
	Scale ( Vec2 :: IDENTITY ),
	Rotation ( 0.0f ),
	Dirty ( false ),
	Matrix (),
	MatrixSource ( * this ),
	Iteration ( 0 )
{
}

Xenon::Math::Transform2D :: Transform2D ( const Vec2 & Translation ):
	Translation ( Translation ),
	Scale ( Vec2 :: IDENTITY ),
	Rotation ( 0.0f ),
	Dirty ( true ),
	Matrix ( Matrix3x3 :: NO_INIT ),
	MatrixSource ( * this ),
	Iteration ( 0 )
{
}

Xenon::Math::Transform2D :: Transform2D ( const Vec2 & Translation, const Vec2 & Scale ):
	Translation ( Translation ),
	Scale ( Scale ),
	Rotation ( 0.0f ),
	Dirty ( true ),
	Matrix ( Matrix3x3 :: NO_INIT ),
	MatrixSource ( * this ),
	Iteration ( 0 )
{
}

Xenon::Math::Transform2D :: Transform2D ( const Vec2 & Translation, const Vec2 & Scale, const float Rotation ):
	Translation ( Translation ),
	Scale ( Scale ),
	Rotation ( Rotation ),
	Dirty ( true ),
	Matrix ( Matrix3x3 :: NO_INIT ),
	MatrixSource ( * this ),
	Iteration ( 0 )
{
}

Xenon::Math::Transform2D :: ~Transform2D ()
{
}

Xenon::Math::Transform2D::InternalMatrix3x3UniformSource :: InternalMatrix3x3UniformSource ( Transform2D & Source ):
	Source ( Source )
{
}

Xenon::Math::Transform2D::InternalMatrix3x3UniformSource :: ~InternalMatrix3x3UniformSource ()
{
}

const GLfloat * Xenon::Math::Transform2D::InternalMatrix3x3UniformSource :: GetFloatArray () const
{
	
	return reinterpret_cast <const GLfloat *> ( & Source.ReadMatrix () );
	
}

bool Xenon::Math::Transform2D::InternalMatrix3x3UniformSource :: IsTransposed () const
{
	
	return true;
	
}

int64_t Xenon::Math::Transform2D::InternalMatrix3x3UniformSource :: GetIteration () const 
{
	
	return Source.Iteration;
	
}

void Xenon::Math::Transform2D :: SetTranslation ( const Vec2 & Translation )
{
	
	Vec2 :: Copy ( this -> Translation, Translation );
	
	Dirty = true;
	Iteration ++;
	
}

void Xenon::Math::Transform2D :: SetScale ( const Vec2 & Scale )
{
	
	Vec2 :: Copy ( this -> Scale, Scale );
	
	Dirty = true;
	Iteration ++;
	
}

void Xenon::Math::Transform2D :: SetRotation ( float Rotation )
{
	
	this -> Rotation = Rotation;
	
	Dirty = true;
	Iteration ++;
	
}

const Xenon::Math :: Vec2 & Xenon::Math::Transform2D :: ReadTranslation ()
{
	
	return Translation;
	
}

const Xenon::Math :: Vec2 & Xenon::Math::Transform2D :: ReadScale ()
{
	
	return Scale;
	
}

float Xenon::Math::Transform2D :: ReadRotation ()
{
	
	return Rotation;
	
}

Xenon::Math :: Vec2 & Xenon::Math::Transform2D :: ReadTranslationMutable ()
{
	
	Dirty = true;
	Iteration ++;
	
	return Translation;
	
}

Xenon::Math :: Vec2 & Xenon::Math::Transform2D :: ReadScaleMutable ()
{
	
	Dirty = true;
	Iteration ++;
	
	return Scale;
	
}

float & Xenon::Math::Transform2D :: ReadRotationMutable ()
{
	
	Dirty = true;
	Iteration ++;
	
	return Rotation;
	
}

const Xenon::Math :: Matrix3x3 & Xenon::Math::Transform2D :: ReadMatrix ()
{
	
	if ( Dirty )
	{
		
		Matrix3x3 :: SetAsScale ( Matrix, Scale );
		Matrix3x3 :: AppendRotation ( Matrix, Rotation );
		Matrix3x3 :: AppendTranslation ( Matrix, Translation );
		
		Dirty = false;
		
	}
	
	return Matrix;
	
}

void Xenon::Math::Transform2D :: Flush ()
{
	
	if ( Dirty )
	{
		
		Matrix3x3 :: SetAsScale ( Matrix, Scale );
		Matrix3x3 :: AppendRotation ( Matrix, Rotation );
		Matrix3x3 :: AppendTranslation ( Matrix, Translation );
		
		Dirty = false;
		
	}
	
}

Xenon::GPU :: IMatrix3x3UniformSource & Xenon::Math::Transform2D :: GetTransformUniformSource ()
{
	
	return MatrixSource;
	
}
