#include <Xenon/Math/Transform3D.h>

Xenon::Math::Transform3D :: Transform3D ():
	RefCounted ( 0 ),
	Translation ( Vec3 :: ZERO ),
	Scale ( Vec3 :: IDENTITY ),
	Rotation ( Quaternion :: IDENTITY ),
	NormalDirty ( false ),
	NormalMatrix (),
	NormalMatrixSource ( this, & Xenon::Math::Transform3D :: ReadNormalMatrix, & NormalIteration ),
	NormalIteration ( 0 ),
	InverseNormalDirty ( false ),
	InverseNormalMatrix (),
	InverseNormalMatrixSource ( this, & Xenon::Math::Transform3D :: ReadInverseNormalMatrix, & InverseNormalIteration ),
	InverseNormalIteration ( 0 ),
	ModelDirty ( false ),
	ModelMatrix (),
	ModelMatrixSource ( this, & Xenon::Math::Transform3D :: ReadModelMatrix, & ModelIteration ),
	ModelIteration ( 0 )
{
}

Xenon::Math::Transform3D :: Transform3D ( const Vec3 & Translation ):
	RefCounted ( 0 ),
	Translation ( Translation ),
	Scale ( Vec3 :: IDENTITY ),
	Rotation ( Quaternion :: IDENTITY ),
	NormalDirty ( false ),
	NormalMatrix (),
	NormalMatrixSource ( this, & Xenon::Math::Transform3D :: ReadNormalMatrix, & NormalIteration ),
	NormalIteration ( 0 ),
	InverseNormalDirty ( false ),
	InverseNormalMatrix (),
	InverseNormalMatrixSource ( this, & Xenon::Math::Transform3D :: ReadInverseNormalMatrix, & InverseNormalIteration ),
	InverseNormalIteration ( 0 ),
	ModelDirty ( true ),
	ModelMatrix ( Matrix4x4 :: NO_INIT ),
	ModelMatrixSource ( this, & Xenon::Math::Transform3D :: ReadModelMatrix, & ModelIteration ),
	ModelIteration ( 0 )
{	
}

Xenon::Math::Transform3D :: Transform3D ( const Vec3 & Translation, const Vec3 & Scale ):
	RefCounted ( 0 ),
	Translation ( Translation ),
	Scale ( Scale ),
	Rotation ( Quaternion :: IDENTITY ),
	NormalDirty ( true ),
	NormalMatrix (),
	NormalMatrixSource ( this, & Xenon::Math::Transform3D :: ReadNormalMatrix, & NormalIteration ),
	NormalIteration ( 0 ),
	InverseNormalDirty ( true ),
	InverseNormalMatrix (),
	InverseNormalMatrixSource ( this, & Xenon::Math::Transform3D :: ReadInverseNormalMatrix, & InverseNormalIteration ),
	InverseNormalIteration ( 0 ),
	ModelDirty ( true ),
	ModelMatrix ( Matrix4x4 :: NO_INIT ),
	ModelMatrixSource ( this, & Xenon::Math::Transform3D :: ReadModelMatrix, & ModelIteration ),
	ModelIteration ( 0 )
{	
}

Xenon::Math::Transform3D :: Transform3D ( const Vec3 & Translation, const Vec3 & Scale, const Quaternion & Rotation ):
	RefCounted ( 0 ),
	Translation ( Translation ),
	Scale ( Scale ),
	Rotation ( Rotation ),
	NormalDirty ( true ),
	NormalMatrix (),
	NormalMatrixSource ( this, & Xenon::Math::Transform3D :: ReadNormalMatrix, & NormalIteration ),
	NormalIteration ( 0 ),
	InverseNormalDirty ( true ),
	InverseNormalMatrix (),
	InverseNormalMatrixSource ( this, & Xenon::Math::Transform3D :: ReadInverseNormalMatrix, & InverseNormalIteration ),
	InverseNormalIteration ( 0 ),
	ModelDirty ( true ),
	ModelMatrix ( Matrix4x4 :: NO_INIT ),
	ModelMatrixSource ( this, & Xenon::Math::Transform3D :: ReadModelMatrix, & ModelIteration ),
	ModelIteration ( 0 )
{
}

Xenon::Math::Transform3D :: ~Transform3D ()
{
}

Xenon::Math::Transform3D::InternalMatrix4x4UniformSource :: InternalMatrix4x4UniformSource ( Transform3D * Source, const Matrix4x4 & ( Transform3D :: * ReadFunction ) (), int64_t * IterationPTR ):
	Source ( Source ),
	ReadFunction ( ReadFunction ),
	IterationPTR ( IterationPTR )
{
}

Xenon::Math::Transform3D::InternalMatrix4x4UniformSource :: ~InternalMatrix4x4UniformSource ()
{
}
				
const GLfloat * Xenon::Math::Transform3D::InternalMatrix4x4UniformSource :: GetFloatArray () const
{
	
	return reinterpret_cast <const GLfloat *> ( & ( Source ->* ReadFunction ) () );
	
}

bool Xenon::Math::Transform3D::InternalMatrix4x4UniformSource :: IsTransposed () const
{
	
	return true;
	
}

int64_t Xenon::Math::Transform3D::InternalMatrix4x4UniformSource :: GetIteration () const
{
	
	return * IterationPTR;
	
}

void Xenon::Math::Transform3D::InternalMatrix4x4UniformSource :: Reference ()
{
	
	Source -> Reference ();
	
}

void Xenon::Math::Transform3D::InternalMatrix4x4UniformSource :: Dereference ()
{
	
	Source -> Dereference ();
	
}

void Xenon::Math::Transform3D :: SetTranslation ( const Vec3 & Translation )
{
	
	Vec3 :: Copy ( this -> Translation, Translation );
	
	ModelDirty = true;
	
}

void Xenon::Math::Transform3D :: SetScale ( const Vec3 & Scale )
{
	
	Vec3 :: Copy ( this -> Scale, Scale );
	
	ModelDirty = true;
	ModelIteration ++;
	
	NormalDirty = true;
	NormalIteration ++;
	
	InverseNormalDirty = true;
	InverseNormalIteration ++;
	
}

void Xenon::Math::Transform3D :: SetRotation ( const Quaternion & Rotation )
{
	
	Quaternion :: Copy ( this -> Rotation, Rotation );
	
	ModelDirty = true;
	ModelIteration ++;
	
	NormalDirty = true;
	NormalIteration ++;
	
	InverseNormalDirty = true;
	InverseNormalIteration ++;
	
}

void Xenon::Math::Transform3D :: AppendTranslation ( const Vec3 & Translation )
{
	
	Vec3 :: Add ( this -> Translation, Translation );
	
	ModelDirty = true;
	ModelIteration ++;
	
}

void Xenon::Math::Transform3D :: AppendScale ( const Vec3 & Scale )
{
	
	Vec3 :: Scale ( this -> Scale, Scale );
	
	ModelDirty = true;
	ModelIteration ++;
	
	NormalDirty = true;
	NormalIteration ++;
	
	InverseNormalDirty = true;
	InverseNormalIteration ++;
	
}

void Xenon::Math::Transform3D :: AppendRotation ( const Quaternion & Rotation )
{
	
	Quaternion :: Append ( this -> Rotation, Rotation );
	Quaternion :: Normalize ( this -> Rotation );
	
	ModelDirty = true;
	ModelIteration ++;
	
	NormalDirty = true;
	NormalIteration ++;
	
	InverseNormalDirty = true;
	InverseNormalIteration ++;
	
}

const Xenon::Math :: Vec3 & Xenon::Math::Transform3D :: ReadTranslation ()
{
	
	return Translation;
	
}

const Xenon::Math :: Vec3 & Xenon::Math::Transform3D :: ReadScale ()
{
	
	return Scale;
	
}

const Xenon::Math :: Quaternion & Xenon::Math::Transform3D :: ReadRotation ()
{
	
	return Rotation;
	
}
			
Xenon::Math :: Vec3 & Xenon::Math::Transform3D :: ReadTranslationMutable ()
{
	
	ModelDirty = true;
	ModelIteration ++;
	
	return Translation;
	
}

Xenon::Math :: Vec3 & Xenon::Math::Transform3D :: ReadScaleMutable ()
{
	
	ModelDirty = true;
	ModelIteration ++;
	
	NormalDirty = true;
	NormalIteration ++;
	
	InverseNormalDirty = true;
	InverseNormalIteration ++;
	
	return Scale;
	
}

Xenon::Math :: Quaternion & Xenon::Math::Transform3D :: ReadRotationMutable ()
{
	
	ModelDirty = true;
	ModelIteration ++;
	
	NormalDirty = true;
	NormalIteration ++;
	
	InverseNormalDirty = true;
	InverseNormalIteration ++;
	
	return Rotation;
	
}

const Xenon::Math :: Matrix4x4 & Xenon::Math::Transform3D :: ReadNormalMatrix ()
{
	
	if ( NormalDirty )
	{
		
		Matrix4x4 :: SetAsQuaternionRotation ( NormalMatrix, Rotation );
		Matrix4x4 :: PrependScale ( NormalMatrix, Scale );
		
		Matrix4x4 :: Invert ( NormalMatrix );
		
		NormalDirty = false;
		
	};
	
	return NormalMatrix;
	
}

const Xenon::Math :: Matrix4x4 & Xenon::Math::Transform3D :: ReadModelMatrix ()
{
	
	if ( ModelDirty )
	{
		
		Matrix4x4 :: SetAsQuaternionRotation ( ModelMatrix, Rotation );
		Matrix4x4 :: PrependScale ( ModelMatrix, Scale );
		Matrix4x4 :: AppendTranslation ( ModelMatrix, Translation );
		
		ModelDirty = false;
		
	}
	
	return ModelMatrix;
	
}

const Xenon::Math :: Matrix4x4 & Xenon::Math::Transform3D :: ReadInverseNormalMatrix ()
{
	
	if ( InverseNormalDirty )
	{
		
		Matrix4x4 :: Invert ( InverseNormalMatrix, ReadNormalMatrix () );
		
		InverseNormalDirty = false;
		
	}
	
	return InverseNormalMatrix;
	
}

Xenon::GPU :: IMatrix4x4UniformSource & Xenon::Math::Transform3D :: GetNormalUniformSource ()
{
	
	return NormalMatrixSource;
	
}

Xenon::GPU :: IMatrix4x4UniformSource & Xenon::Math::Transform3D :: GetInverseNormalUniformSource ()
{
	
	return InverseNormalMatrixSource;
	
}

Xenon::GPU :: IMatrix4x4UniformSource & Xenon::Math::Transform3D :: GetModelUniformSource ()
{
	
	return ModelMatrixSource;
	
}

void Xenon::Math::Transform3D :: FlushMatricies ( bool Model, bool Normal, bool InverseNormal )
{
	
	if ( NormalDirty && Normal )
	{
		
		Matrix4x4 :: SetAsQuaternionRotation ( NormalMatrix, Rotation );
		Matrix4x4 :: PrependScale ( NormalMatrix, Scale );
		
		Matrix4x4 :: Invert ( NormalMatrix );
		
		NormalDirty = false;
		
	}
	
	if ( ModelDirty && Model )
	{
		
		Matrix4x4 :: SetAsQuaternionRotation ( ModelMatrix, Rotation );
		Matrix4x4 :: PrependScale ( ModelMatrix, Scale );
		Matrix4x4 :: AppendTranslation ( ModelMatrix, Translation );
		
		ModelDirty = false;
		
	}
	
	if ( InverseNormalDirty && InverseNormal )
	{
		
		Matrix4x4 :: Invert ( InverseNormalMatrix, NormalMatrix );
		
		InverseNormalDirty = false;
		
	}
	
}
