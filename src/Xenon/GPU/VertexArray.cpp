#include <Xenon/GPU/VertexArray.h>
#include <Xenon/GPU/ShaderProgram.h>
#include <Xenon/GPU/VertexBuffer.h>
#include <Xenon/GPU/Context.h>

#include <iostream>

Xenon::GPU::VertexArray :: VertexArray ( uint32_t PreAllocFPAttributeCount, uint32_t PreAllocIntegerAttributeCount ):
	Allocated ( false ),
	AHandle ( 0 ),
	FPAttributes ( PreAllocFPAttributeCount ),
	IntegerAttributes ( PreAllocIntegerAttributeCount ),
	IBuffer ( NULL ),
	Program ( NULL )
{
}

Xenon::GPU::VertexArray :: ~VertexArray ()
{
	
	GPUResourceFree ();
	
}

void Xenon::GPU::VertexArray :: GPUResourceAlloc ()
{
	
	if ( Allocated )
		return;
	
	glGenVertexArrays ( 1, & AHandle );
	
	if ( AHandle != 0 )
		Allocated = true;
	
}

void Xenon::GPU::VertexArray :: GPUResourceFree ()
{
	
	if ( ! Allocated )
		return;
	
	glDeleteVertexArrays ( 1, & AHandle );
	
	Allocated = false;
	
}

bool Xenon::GPU::VertexArray :: GPUResourceAllocated ()
{
	
	return Allocated;
	
}

void Xenon::GPU::VertexArray :: SetProgram ( ShaderProgram * Program )
{
	
	uint32_t Count;
	uint32_t I;
	
	if ( Program != NULL )
	{
		
		Count = FPAttributes.size ();
		
		for ( I = 0; I < Count; I ++ )
			FPAttributes [ I ].AttributeLocation = Program -> GetAttributeLocation ( FPAttributes [ I ].Name.c_str () );
		
		Count = IntegerAttributes.size ();
		
		for ( I = 0; I < Count; I ++ )
			IntegerAttributes [ I ].AttributeLocation = Program -> GetAttributeLocation ( IntegerAttributes [ I ].Name.c_str () );
		
	}
	
	this -> Program = Program;
	
}

void Xenon::GPU::VertexArray :: AddFPAttribute ( const std :: string Name, GLint Size, FPAttributeInputType InputType, bool Normalized, GLsizei Stride, GLvoid * Offset, VertexBuffer * Data )
{
	
	FPAttributeStruct Attribute;
	
	Attribute.Name = Name;
	
	Attribute.InputType = InputType;
	Attribute.Size = Size;
	Attribute.Stride = Stride;
	Attribute.Offset = Offset;
	Attribute.Data = Data;
	Attribute.Normalized = Normalized;
	
	if ( Program != NULL )
		Attribute.AttributeLocation = Program -> GetAttributeLocation ( Name.c_str () );
	else
		Attribute.AttributeLocation = 0;
	
	FPAttributes.push_back ( Attribute );
	
}

void Xenon::GPU::VertexArray :: AddIntegerAttribute ( const std :: string Name, GLint Size, FPAttributeInputType InputType, GLsizei Stride, GLvoid * Offset, VertexBuffer * Data )
{
	
	IntegerAttributeStruct Attribute;
	
	Attribute.Name = Name;
	
	Attribute.InputType = InputType;
	Attribute.Size = Size;
	Attribute.Stride = Stride;
	Attribute.Offset = Offset;
	Attribute.Data = Data;
	
	if ( Program != NULL )
		Attribute.AttributeLocation = Program -> GetAttributeLocation ( Name.c_str () );
	else
		Attribute.AttributeLocation = 0;
	
	IntegerAttributes.push_back ( Attribute );
	
}

void Xenon::GPU::VertexArray :: SetIndexBuffer ( IndexBuffer * IBuffer )
{
	
	this -> IBuffer = IBuffer;
	
}

void Xenon::GPU::VertexArray :: Build ()
{
	
	uint32_t Count;
	uint32_t I;
	
	if ( Program == NULL )
		return;
	
	Bind ();
	
	if ( IBuffer != NULL )
		IBuffer -> Bind ();
	
	Count = FPAttributes.size ();
	
	for ( I = 0; I < Count; I ++ )
	{
		
		if ( FPAttributes [ I ].AttributeLocation != - 1 )
		{
			
			FPAttributes [ I ].Data -> Bind ();
			
			glVertexAttribPointer ( FPAttributes [ I ].AttributeLocation, FPAttributes [ I ].Size, FPAttributes [ I ].InputType, FPAttributes [ I ].Normalized, FPAttributes [ I ].Stride, FPAttributes [ I ].Offset );
			glEnableVertexAttribArray ( FPAttributes [ I ].AttributeLocation );
			
		}
		
	}
	
	Count = IntegerAttributes.size ();
	
	for ( I = 0; I < Count; I ++ )
	{
		
		if ( IntegerAttributes [ I ].AttributeLocation != - 1 )
		{
			
			IntegerAttributes [ I ].Data -> Bind ();
			
			glVertexAttribIPointer ( IntegerAttributes [ I ].AttributeLocation, IntegerAttributes [ I ].Size, IntegerAttributes [ I ].InputType, IntegerAttributes [ I ].Stride, IntegerAttributes [ I ].Offset );
			glEnableVertexAttribArray ( IntegerAttributes [ I ].AttributeLocation );
			
		}
		
	}
	
}

void Xenon::GPU::VertexArray :: Bind ()
{
	
	if ( Context :: CurrentBoundContext -> CurrentBoundVertexArray != this )
	{
		
		if ( ! Allocated )
		{
			
			GPUResourceAlloc ();
			
			if ( ! Allocated )
			{
				
				XENON_LOG_ERROR ( "Failed to allocate gl name for VertexArray\n" );
				
				return;
				
			}
			
		}
		
		glBindVertexArray ( AHandle );
		
		Context :: CurrentBoundContext -> CurrentBoundVertexArray = this;
		
	}
	
}

