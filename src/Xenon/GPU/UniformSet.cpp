#include <Xenon/GPU/UniformSet.h>
#include <iostream>

Xenon::GPU::UniformSet :: UniformSet ( ShaderProgram * Program, uint32_t Matrix4x4Prealloc, uint32_t Matrix3x3Prealloc, uint32_t FloatVec4Prealloc, uint32_t FloatVec3Prealloc, uint32_t FloatVec2Prealloc, uint32_t FloatPrealloc ):
	Program ( Program ),
	FloatUniforms ( FloatPrealloc ),
	FloatVec2Uniforms ( FloatVec2Prealloc ),
	FloatVec3Uniforms ( FloatVec3Prealloc ),
	FloatVec4Uniforms ( FloatVec4Prealloc ),
	Matrix3x3Uniforms ( Matrix3x3Prealloc ),
	Matrix4x4Uniforms ( Matrix4x4Prealloc ),
	LastLinkIteration ( - 1 )
{
}

Xenon::GPU::UniformSet :: ~UniformSet ()
{
}

void Xenon::GPU::UniformSet :: AddFloatUniform ( const std :: string Name, const IFloatUniformSource * Source, bool LocateImmediately )
{
	
	FloatUniformTracker Tracker;
	
	Tracker.Name = Name;
	Tracker.Source = Source;
	Tracker.LastUploadedIteration = - 1;
	Tracker.UniformLocation = ( ( Program != NULL ) && LocateImmediately ) ? Program -> GetUniformLocation ( Name.c_str () ) : - 1;
	
	FloatUniforms.push_back ( Tracker );
	
}

void Xenon::GPU::UniformSet :: AddFloatVec2Uniform ( const std :: string Name, const IFloatVec2UniformSource * Source, bool LocateImmediately )
{
	
	FloatVec2UniformTracker Tracker;
	
	Tracker.Name = Name;
	Tracker.Source = Source;
	Tracker.LastUploadedIteration = - 1;
	Tracker.UniformLocation = ( ( Program != NULL ) && LocateImmediately ) ? Program -> GetUniformLocation ( Name.c_str () ) : - 1;
	
	FloatVec2Uniforms.push_back ( Tracker );
	
}

void Xenon::GPU::UniformSet :: AddFloatVec3Uniform ( const std :: string Name, const IFloatVec3UniformSource * Source, bool LocateImmediately )
{
	
	FloatVec3UniformTracker Tracker;
	
	Tracker.Name = Name;
	Tracker.Source = Source;
	Tracker.LastUploadedIteration = - 1;
	Tracker.UniformLocation = ( ( Program != NULL ) && LocateImmediately ) ? Program -> GetUniformLocation ( Name.c_str () ) : - 1;
	
	FloatVec3Uniforms.push_back ( Tracker );
	
}

void Xenon::GPU::UniformSet :: AddFloatVec4Uniform ( const std :: string Name, const IFloatVec4UniformSource * Source, bool LocateImmediately )
{
	
	FloatVec4UniformTracker Tracker;
	
	Tracker.Name = Name;
	Tracker.Source = Source;
	Tracker.LastUploadedIteration = - 1;
	Tracker.UniformLocation = ( ( Program != NULL ) && LocateImmediately ) ? Program -> GetUniformLocation ( Name.c_str () ) : - 1;
	
	FloatVec4Uniforms.push_back ( Tracker );
	
}

void Xenon::GPU::UniformSet :: AddMatrix3x3Uniform ( const std :: string Name, const IMatrix3x3UniformSource * Source, bool LocateImmediately )
{
	
	Matrix3x3UniformTracker Tracker;
	
	Tracker.Name = Name;
	Tracker.Source = Source;
	Tracker.LastUploadedIteration = - 1;
	Tracker.UniformLocation = ( ( Program != NULL ) && LocateImmediately ) ? Program -> GetUniformLocation ( Name.c_str () ) : - 1;
	
	Matrix3x3Uniforms.push_back ( Tracker );
	
}

void Xenon::GPU::UniformSet :: AddMatrix4x4Uniform ( const std :: string Name, const IMatrix4x4UniformSource * Source, bool LocateImmediately )
{
	
	Matrix4x4UniformTracker Tracker;
	
	Tracker.Name = Name;
	Tracker.Source = Source;
	Tracker.LastUploadedIteration = - 1;
	Tracker.UniformLocation = ( ( Program != NULL ) && LocateImmediately ) ? Program -> GetUniformLocation ( Name.c_str () ) : - 1;
	
	Matrix4x4Uniforms.push_back ( Tracker );
	
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
			
			glUniform2fv ( FloatVec2Uniforms [ I ].UniformLocation, 1, FloatVec2Uniforms [ I ].Source -> GetFloatVector () );
			
			FloatVec2Uniforms [ I ].LastUploadedIteration = CurrentIteration;
			
		}
		
	}
	
	for ( I = 0; I < FloatVec3Uniforms.size (); I ++ )
	{
		
		int64_t CurrentIteration = FloatVec3Uniforms [ I ].Source -> GetIteration ();
		
		if ( ( FloatVec3Uniforms [ I ].UniformLocation != - 1 ) && ( FloatVec3Uniforms [ I ].LastUploadedIteration < CurrentIteration ) )
		{
			
			glUniform3fv ( FloatVec3Uniforms [ I ].UniformLocation, 1, FloatVec3Uniforms [ I ].Source -> GetFloatVector () );
			
			FloatVec3Uniforms [ I ].LastUploadedIteration = CurrentIteration;
			
		}
		
	}
	
	for ( I = 0; I < FloatVec4Uniforms.size (); I ++ )
	{
		
		int64_t CurrentIteration = FloatVec4Uniforms [ I ].Source -> GetIteration ();
		
		if ( ( FloatVec4Uniforms [ I ].UniformLocation != - 1 ) && ( FloatVec4Uniforms [ I ].LastUploadedIteration < CurrentIteration ) )
		{
			
			glUniform4fv ( FloatVec4Uniforms [ I ].UniformLocation, 1, FloatVec4Uniforms [ I ].Source -> GetFloatVector () );
			
			FloatVec4Uniforms [ I ].LastUploadedIteration = CurrentIteration;
			
		}
		
	}
	
	for ( I = 0; I < Matrix3x3Uniforms.size (); I ++ )
	{
		
		int64_t CurrentIteration = Matrix3x3Uniforms [ I ].Source -> GetIteration ();
		
		if ( ( Matrix3x3Uniforms [ I ].UniformLocation != - 1 ) && ( Matrix3x3Uniforms [ I ].LastUploadedIteration < CurrentIteration ) )
		{
			
			glUniformMatrix3fv ( Matrix3x3Uniforms [ I ].UniformLocation, 1, Matrix3x3Uniforms [ I ].Source -> IsTransposed (), Matrix3x3Uniforms [ I ].Source -> GetFloatArray () );
			
			Matrix3x3Uniforms [ I ].LastUploadedIteration = CurrentIteration;
			
		}
		
	}
	
	for ( I = 0; I < Matrix4x4Uniforms.size (); I ++ )
	{
		
		int64_t CurrentIteration = Matrix4x4Uniforms [ I ].Source -> GetIteration ();
		
		if ( ( Matrix4x4Uniforms [ I ].UniformLocation != - 1 ) && ( Matrix4x4Uniforms [ I ].LastUploadedIteration < CurrentIteration ) )
		{
			
			glUniformMatrix4fv ( Matrix4x4Uniforms [ I ].UniformLocation, 1, Matrix4x4Uniforms [ I ].Source -> IsTransposed (), Matrix4x4Uniforms [ I ].Source -> GetFloatArray () );
			
			Matrix4x4Uniforms [ I ].LastUploadedIteration = CurrentIteration;
			
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
	
}

void Xenon::GPU::UniformSet :: SetProgram ( ShaderProgram * Program )
{
	
	if ( this -> Program != Program )
		ResetUniformStates ();
	
	this -> Program = Program;
	
}
