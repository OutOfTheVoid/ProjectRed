#include <Xenon/GPU/UniformSet.h>
#include <iostream>

Xenon::GPU::UniformSet :: UniformSet ( ShaderProgram * Program ):
	RefCounted ( 0 ),
	Program ( Program ),
	LastLinkIteration ( - 1 ),
	FloatUniforms (),
	FloatVec2Uniforms (),
	FloatVec3Uniforms (),
	FloatVec4Uniforms (),
	Matrix3x3Uniforms (),
	Matrix4x4Uniforms (),
	UIntUniforms (),
	IntUniforms (),
	BoolUniforms ()
{
	
	if ( Program != NULL )
		Program -> Reference ();
	
}

Xenon::GPU::UniformSet :: ~UniformSet ()
{
	
	if ( Program != NULL )
	{
		
		Program -> Dereference ();
		
		Program = NULL;
		
	}
	
	uint32_t I;
	
	for ( I = 0; I < FloatUniforms.size (); I ++ )
		FloatUniforms [ I ].Source -> Dereference ();
	
	for ( I = 0; I < FloatVec2Uniforms.size (); I ++ )
		FloatVec2Uniforms [ I ].Source -> Dereference ();
	
	for ( I = 0; I < FloatVec3Uniforms.size (); I ++ )
		FloatVec3Uniforms [ I ].Source -> Dereference ();
	
	for ( I = 0; I < FloatVec4Uniforms.size (); I ++ )
		FloatVec4Uniforms [ I ].Source -> Dereference ();
	
	for ( I = 0; I < Matrix3x3Uniforms.size (); I ++ )
		Matrix3x3Uniforms [ I ].Source -> Dereference ();
	
	for ( I = 0; I < Matrix4x4Uniforms.size (); I ++ )
		Matrix4x4Uniforms [ I ].Source -> Dereference ();
	
	for ( I = 0; I < UIntUniforms.size (); I ++ )
		UIntUniforms [ I ].Source -> Dereference ();
	
	for ( I = 0; I < IntUniforms.size (); I ++ )
		IntUniforms [ I ].Source -> Dereference ();
	
}

void Xenon::GPU::UniformSet :: AddFloatUniform ( const std :: string & Name, IFloatUniformSource * Source, bool LocateImmediately )
{
	
	if ( Source == NULL )
		return;
	
	FloatUniformTracker Tracker;
	
	Tracker.Name = Name;
	Tracker.Source = Source;
	Tracker.LastUploadedIteration = - 1;
	Tracker.UniformLocation = ( ( Program != NULL ) && LocateImmediately ) ? Program -> GetUniformLocation ( Name.c_str () ) : - 1;
	
	Source -> Reference ();
	
	FloatUniforms.push_back ( Tracker );
	
}

void Xenon::GPU::UniformSet :: AddFloatVec2Uniform ( const std :: string & Name, IFloatVec2UniformSource * Source, bool LocateImmediately )
{
	
	if ( Source == NULL )
		return;
	
	FloatVec2UniformTracker Tracker;
	
	Tracker.Name = Name;
	Tracker.Source = Source;
	Tracker.LastUploadedIteration = - 1;
	Tracker.UniformLocation = ( ( Program != NULL ) && LocateImmediately ) ? Program -> GetUniformLocation ( Name.c_str () ) : - 1;
	
	Source -> Reference ();
	
	FloatVec2Uniforms.push_back ( Tracker );
	
}

void Xenon::GPU::UniformSet :: AddFloatVec3Uniform ( const std :: string & Name, IFloatVec3UniformSource * Source, bool LocateImmediately )
{
	
	if ( Source == NULL )
		return;
	
	FloatVec3UniformTracker Tracker;
	
	Tracker.Name = Name;
	Tracker.Source = Source;
	Tracker.LastUploadedIteration = - 1;
	Tracker.UniformLocation = ( ( Program != NULL ) && LocateImmediately ) ? Program -> GetUniformLocation ( Name.c_str () ) : - 1;
	
	Source -> Reference ();
	
	FloatVec3Uniforms.push_back ( Tracker );
	
}

void Xenon::GPU::UniformSet :: AddFloatVec4Uniform ( const std :: string & Name, IFloatVec4UniformSource * Source, bool LocateImmediately )
{
	
	if ( Source == NULL )
		return;
	
	FloatVec4UniformTracker Tracker;
	
	Tracker.Name = Name;
	Tracker.Source = Source;
	Tracker.LastUploadedIteration = - 1;
	Tracker.UniformLocation = ( ( Program != NULL ) && LocateImmediately ) ? Program -> GetUniformLocation ( Name.c_str () ) : - 1;
	
	Source -> Reference ();
	
	FloatVec4Uniforms.push_back ( Tracker );
	
}

void Xenon::GPU::UniformSet :: AddMatrix3x3Uniform ( const std :: string & Name, IMatrix3x3UniformSource * Source, bool LocateImmediately )
{
	
	if ( Source == NULL )
		return;
	
	Matrix3x3UniformTracker Tracker;
	
	Tracker.Name = Name;
	Tracker.Source = Source;
	Tracker.LastUploadedIteration = - 1;
	Tracker.UniformLocation = ( ( Program != NULL ) && LocateImmediately ) ? Program -> GetUniformLocation ( Name.c_str () ) : - 1;
	
	Source -> Reference ();
	
	Matrix3x3Uniforms.push_back ( Tracker );
	
}

void Xenon::GPU::UniformSet :: AddMatrix4x4Uniform ( const std :: string & Name, IMatrix4x4UniformSource * Source, bool LocateImmediately )
{
	
	if ( Source == NULL )
		return;
	
	Matrix4x4UniformTracker Tracker;
	
	Tracker.Name = Name;
	Tracker.Source = Source;
	Tracker.LastUploadedIteration = - 1;
	Tracker.UniformLocation = ( ( Program != NULL ) && LocateImmediately ) ? Program -> GetUniformLocation ( Name.c_str () ) : - 1;
	
	Source -> Reference ();
	
	Matrix4x4Uniforms.push_back ( Tracker );
	
}

void Xenon::GPU::UniformSet :: ChangeMatrix4x4Uniform ( const std :: string & Name, Xenon::GPU::IMatrix4x4UniformSource * Source, bool LocateImmediately )
{
	
	for ( uint32_t I = 0; I < Matrix4x4Uniforms.size (); I ++ )
	{
		
		Matrix4x4UniformTracker & Tracker = Matrix4x4Uniforms [ I ];
		
		if ( Tracker.Name == Name )
		{
			
			if ( Source != NULL )
			{
				
				Tracker.Source -> Dereference ();
				Tracker.Source = Source;
				Tracker.Source -> Reference ();
				
				Tracker.LastUploadedIteration = - 1;
				
				return;
				
			}
			else
			{
				
				Tracker.Source -> Dereference ();
				Tracker.Source = NULL;
				
				Matrix4x4Uniforms.erase ( Matrix4x4Uniforms.begin () + I );
				
				return;
				
			}
			
		}
		
	}
	
	if ( Source != NULL )
		AddMatrix4x4Uniform ( Name, Source, LocateImmediately );
	
}

void Xenon::GPU::UniformSet :: AddUIntUniform ( const std :: string & Name, IUIntUniformSource * Source, bool LocateImmediately )
{
	
	if ( Source == NULL )
		return;
	
	UIntUniformTracker Tracker;
	
	Tracker.Name = Name;
	Tracker.Source = Source;
	Tracker.LastUploadedIteration = - 1;
	Tracker.UniformLocation = ( ( Program != NULL ) && LocateImmediately ) ? Program -> GetUniformLocation ( Name.c_str () ) : - 1;
	
	Source -> Reference ();
	
	UIntUniforms.push_back ( Tracker );
	
}

void Xenon::GPU::UniformSet :: AddIntUniform ( const std :: string & Name, IIntUniformSource * Source, bool LocateImmediately )
{
	
	if ( Source == NULL )
		return;
	
	IntUniformTracker Tracker;
	
	Tracker.Name = Name;
	Tracker.Source = Source;
	Tracker.LastUploadedIteration = - 1;
	Tracker.UniformLocation = ( ( Program != NULL ) && LocateImmediately ) ? Program -> GetUniformLocation ( Name.c_str () ) : - 1;
	
	Source -> Reference ();
	
	IntUniforms.push_back ( Tracker );
	
}

void Xenon::GPU::UniformSet :: AddBoolUniform ( const std :: string & Name, IBoolUniformSource * Source, bool LocateImmediately )
{
	
	if ( Source == NULL )
		return;
	
	BoolUniformTracker Tracker;
	
	Tracker.Name = Name;
	Tracker.Source = Source;
	Tracker.LastUploadedIteration = - 1;
	Tracker.UniformLocation = ( ( Program != NULL ) && LocateImmediately ) ? Program -> GetUniformLocation ( Name.c_str () ) : - 1;
	
	Source -> Reference ();
	
	BoolUniforms.push_back ( Tracker );
	
}

void Xenon::GPU::UniformSet :: ResetUniformStates ()
{
	
	LastLinkIteration = - 1;
	
	uint32_t I = 0;
	
	for ( I = 0; I < FloatUniforms.size (); I ++ )
	{
		
		FloatUniforms [ I ].UniformLocation = - 1;
		FloatUniforms [ I ].LastUploadedIteration = - 1;
		
	}
	
	for ( I = 0; I < FloatVec2Uniforms.size (); I ++ )
	{
		
		FloatVec2Uniforms [ I ].UniformLocation = - 1;
		FloatVec2Uniforms [ I ].LastUploadedIteration = - 1;
		
	}
	
	for ( I = 0; I < FloatVec3Uniforms.size (); I ++ )
	{
		
		FloatVec3Uniforms [ I ].UniformLocation = - 1;
		FloatVec3Uniforms [ I ].LastUploadedIteration = - 1;
		
	}
	
	for ( I = 0; I < FloatVec4Uniforms.size (); I ++ )
	{
		
		FloatVec4Uniforms [ I ].UniformLocation = - 1;
		FloatVec4Uniforms [ I ].LastUploadedIteration = - 1;
		
	}
	
	for ( I = 0; I < Matrix3x3Uniforms.size (); I ++ )
	{
		
		Matrix3x3Uniforms [ I ].UniformLocation = - 1;
		Matrix3x3Uniforms [ I ].LastUploadedIteration = - 1;
		
	}
	
	for ( I = 0; I < Matrix4x4Uniforms.size (); I ++ )
	{
		
		Matrix4x4Uniforms [ I ].UniformLocation = - 1;
		Matrix4x4Uniforms [ I ].LastUploadedIteration = - 1;
		
	}
	
	for ( I = 0; I < UIntUniforms.size (); I ++ )
	{
		
		UIntUniforms [ I ].UniformLocation = - 1;
		UIntUniforms [ I ].LastUploadedIteration = - 1;
		
	}
	
	for ( I = 0; I < IntUniforms.size (); I ++ )
	{
		
		IntUniforms [ I ].UniformLocation = - 1;
		IntUniforms [ I ].LastUploadedIteration = - 1;
		
	}
	
	for ( I = 0; I < BoolUniforms.size (); I ++ )
	{
		
		BoolUniforms [ I ].UniformLocation = - 1;
		BoolUniforms [ I ].LastUploadedIteration = - 1;
		
	}
	
}

void Xenon::GPU::UniformSet :: UpdateUniforms ( bool Relink )
{
	
	if ( Program == NULL )
		return;
	
	Program -> Bind ();
	
	if ( Relink )
		Link ();
	
	uint32_t I = 0;
	
	for ( I = 0; I < FloatUniforms.size (); I ++ )
	{
		
		int64_t CurrentIteration = FloatUniforms [ I ].Source -> GetIteration ();
		
		if ( ( FloatUniforms [ I ].UniformLocation != - 1 ) && ( FloatUniforms [ I ].LastUploadedIteration < CurrentIteration ) )
		{
			
			float Value = FloatUniforms [ I ].Source -> GetValue ();
			glUniform1fv ( FloatUniforms [ I ].UniformLocation, 1, & Value );
			
			FloatUniforms [ I ].LastUploadedIteration = CurrentIteration;
			
		}
		
	}
	
	for ( I = 0; I < FloatVec2Uniforms.size (); I ++ )
	{
		
		int64_t CurrentIteration = FloatVec2Uniforms [ I ].Source -> GetIteration ();
		
		if ( ( FloatVec2Uniforms [ I ].UniformLocation != - 1 ) && ( FloatVec2Uniforms [ I ].LastUploadedIteration < CurrentIteration ) )
		{
			
			const GLfloat * Vector = FloatVec2Uniforms [ I ].Source -> GetFloatVector ();
			
			if ( Vector != NULL )
				glUniform2fv ( FloatVec2Uniforms [ I ].UniformLocation, 1, Vector );
			
			FloatVec2Uniforms [ I ].LastUploadedIteration = CurrentIteration;
			
		}
		
	}
	
	for ( I = 0; I < FloatVec3Uniforms.size (); I ++ )
	{
		
		int64_t CurrentIteration = FloatVec3Uniforms [ I ].Source -> GetIteration ();
		
		if ( ( FloatVec3Uniforms [ I ].UniformLocation != - 1 ) && ( FloatVec3Uniforms [ I ].LastUploadedIteration < CurrentIteration ) )
		{
			
			const GLfloat * Vector = FloatVec3Uniforms [ I ].Source -> GetFloatVector ();
			
			if ( Vector != NULL )
				glUniform3fv ( FloatVec3Uniforms [ I ].UniformLocation, 1, Vector );
			
			FloatVec3Uniforms [ I ].LastUploadedIteration = CurrentIteration;
			
		}
		
	}
	
	for ( I = 0; I < FloatVec4Uniforms.size (); I ++ )
	{
		
		int64_t CurrentIteration = FloatVec4Uniforms [ I ].Source -> GetIteration ();
		
		if ( ( FloatVec4Uniforms [ I ].UniformLocation != - 1 ) && ( FloatVec4Uniforms [ I ].LastUploadedIteration < CurrentIteration ) )
		{
			
			const GLfloat * Vector = FloatVec4Uniforms [ I ].Source -> GetFloatVector ();
			
			if ( Vector != NULL )
				glUniform4fv ( FloatVec4Uniforms [ I ].UniformLocation, 1, Vector );
			
			FloatVec4Uniforms [ I ].LastUploadedIteration = CurrentIteration;
			
		}
		
	}
	
	for ( I = 0; I < Matrix3x3Uniforms.size (); I ++ )
	{
		
		int64_t CurrentIteration = Matrix3x3Uniforms [ I ].Source -> GetIteration ();
		
		if ( ( Matrix3x3Uniforms [ I ].UniformLocation != - 1 ) && ( Matrix3x3Uniforms [ I ].LastUploadedIteration < CurrentIteration ) )
		{
			
			const GLfloat * Array = Matrix3x3Uniforms [ I ].Source -> GetFloatArray ();
			
			if ( Array != NULL )
				glUniformMatrix3fv ( Matrix3x3Uniforms [ I ].UniformLocation, 1, Matrix3x3Uniforms [ I ].Source -> IsTransposed (), Array );
			
			Matrix3x3Uniforms [ I ].LastUploadedIteration = CurrentIteration;
			
		}
		
	}
	
	for ( I = 0; I < Matrix4x4Uniforms.size (); I ++ )
	{
		
		int64_t CurrentIteration = Matrix4x4Uniforms [ I ].Source -> GetIteration ();
		
		if ( ( Matrix4x4Uniforms [ I ].UniformLocation != - 1 ) && ( Matrix4x4Uniforms [ I ].LastUploadedIteration < CurrentIteration ) )
		{
			
			const GLfloat * Array = Matrix4x4Uniforms [ I ].Source -> GetFloatArray ();
			
			if ( Array != NULL )
				glUniformMatrix4fv ( Matrix4x4Uniforms [ I ].UniformLocation, 1, Matrix4x4Uniforms [ I ].Source -> IsTransposed (), Array );
			
			Matrix4x4Uniforms [ I ].LastUploadedIteration = CurrentIteration;
			
		}
		
	}
	
	for ( I = 0; I < UIntUniforms.size (); I ++ )
	{
		
		int64_t CurrentIteration = UIntUniforms [ I ].Source -> GetIteration ();
		
		if ( ( UIntUniforms [ I ].UniformLocation != - 1 ) && ( UIntUniforms [ I ].LastUploadedIteration < CurrentIteration ) )
		{
			
			glUniform1ui ( UIntUniforms [ I ].UniformLocation, UIntUniforms [ I ].Source -> GetValue () );
			
			UIntUniforms [ I ].LastUploadedIteration = CurrentIteration;
			
		}
		
	}
	
	for ( I = 0; I < IntUniforms.size (); I ++ )
	{
		
		int64_t CurrentIteration = IntUniforms [ I ].Source -> GetIteration ();
		
		if ( ( IntUniforms [ I ].UniformLocation != - 1 ) && ( IntUniforms [ I ].LastUploadedIteration < CurrentIteration ) )
		{
			
			glUniform1i ( IntUniforms [ I ].UniformLocation, IntUniforms [ I ].Source -> GetValue () );
			
			IntUniforms [ I ].LastUploadedIteration = CurrentIteration;
			
		}
		
	}
	
	for ( I = 0; I < BoolUniforms.size (); I ++ )
	{
		
		int64_t CurrentIteration = BoolUniforms [ I ].Source -> GetIteration ();
		
		if ( ( BoolUniforms [ I ].UniformLocation != - 1 ) && ( BoolUniforms [ I ].LastUploadedIteration < CurrentIteration ) )
		{
			
			glUniform1i ( BoolUniforms [ I ].UniformLocation, BoolUniforms [ I ].Source -> GetValue () ? 1 : 0 );
			
			BoolUniforms [ I ].LastUploadedIteration = CurrentIteration;
			
		}
		
	}
	
}

void Xenon::GPU::UniformSet :: Link ()
{
	
	if ( Program == NULL )
		return;
	
	Program -> Bind ();
	
	int64_t CurrentLinkIteration = Program -> GetLinkIteration ();
	
	if ( LastLinkIteration < CurrentLinkIteration )
	{
		
		ResetUniformStates ();
		LastLinkIteration = CurrentLinkIteration;
		
	}
	
	uint32_t I = 0;
	
	for ( I = 0; I < FloatUniforms.size (); I ++ )
	{
		
		if ( FloatUniforms [ I ].UniformLocation == - 1 )
			FloatUniforms [ I ].UniformLocation = Program -> GetUniformLocation ( FloatUniforms [ I ].Name.c_str () );
		
	}
	
	for ( I = 0; I < FloatVec2Uniforms.size (); I ++ )
	{
		
		if ( FloatVec2Uniforms [ I ].UniformLocation == - 1 )
			FloatVec2Uniforms [ I ].UniformLocation = Program -> GetUniformLocation ( FloatVec2Uniforms [ I ].Name.c_str () );
		
	}
	
	for ( I = 0; I < FloatVec3Uniforms.size (); I ++ )
	{
		
		if ( FloatVec3Uniforms [ I ].UniformLocation == - 1 )
			FloatVec3Uniforms [ I ].UniformLocation = Program -> GetUniformLocation ( FloatVec3Uniforms [ I ].Name.c_str () );
		
	}
	
	for ( I = 0; I < FloatVec4Uniforms.size (); I ++ )
	{
		
		if ( FloatVec4Uniforms [ I ].UniformLocation == - 1 )
			FloatVec4Uniforms [ I ].UniformLocation = Program -> GetUniformLocation ( FloatVec4Uniforms [ I ].Name.c_str () );
		
	}
	
	for ( I = 0; I < Matrix3x3Uniforms.size (); I ++ )
	{
		
		if ( Matrix3x3Uniforms [ I ].UniformLocation == - 1 )
			Matrix3x3Uniforms [ I ].UniformLocation = Program -> GetUniformLocation ( Matrix3x3Uniforms [ I ].Name.c_str () );
		
	}
	
	for ( I = 0; I < Matrix4x4Uniforms.size (); I ++ )
	{
		
		if ( Matrix4x4Uniforms [ I ].UniformLocation == - 1 )
			Matrix4x4Uniforms [ I ].UniformLocation = Program -> GetUniformLocation ( Matrix4x4Uniforms [ I ].Name.c_str () );
		
	}
	
	for ( I = 0; I < UIntUniforms.size (); I ++ )
	{
		
		if ( UIntUniforms [ I ].UniformLocation == - 1 )
			UIntUniforms [ I ].UniformLocation = Program -> GetUniformLocation ( UIntUniforms [ I ].Name.c_str () );
		
	}
	
	for ( I = 0; I < IntUniforms.size (); I ++ )
	{
		
		if ( IntUniforms [ I ].UniformLocation == - 1 )
			IntUniforms [ I ].UniformLocation = Program -> GetUniformLocation ( IntUniforms [ I ].Name.c_str () );
		
	}
	
	for ( I = 0; I < BoolUniforms.size (); I ++ )
	{
		
		if ( BoolUniforms [ I ].UniformLocation == - 1 )
			BoolUniforms [ I ].UniformLocation = Program -> GetUniformLocation ( BoolUniforms [ I ].Name.c_str () );
		
	}
	
}

void Xenon::GPU::UniformSet :: SetProgram ( ShaderProgram * Program )
{
	
	if ( this -> Program != Program )
		ResetUniformStates ();
	
	if ( this -> Program != NULL )
		this -> Program -> Dereference ();
	this -> Program = Program;
	if ( this -> Program != NULL )
		this -> Program -> Reference ();
	
}
