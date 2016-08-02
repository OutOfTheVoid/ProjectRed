#ifndef XENON_VERTEXARRAY_H
#define XENON_VERTEXARRAY_H

#include <Xenon/Xenon.h>

#include <Xenon/GPU/GPU.h>
#include <Xenon/GPU/IGPUResourceUser.h>
#include <Xenon/GPU/GLInclude.h>
#include <Xenon/GPU/IndexBuffer.h>
#include <Xenon/Util/RefCounted.h>

#include <string>
#include <vector>

namespace Xenon
{
	
	namespace GPU
	{
		
		class ShaderProgram;
		class VertexBuffer;
		
		class VertexArray : public IGPUResourceUser, public Util :: RefCounted
		{
		public:
			
			typedef GLenum FPAttributeInputType;
			typedef GLenum IntegerAttributeInputType;
			
			static const FPAttributeInputType kFPAttributeInputType_Byte = GL_BYTE;
			static const FPAttributeInputType kFPAttributeInputType_UByte = GL_UNSIGNED_BYTE;
			static const FPAttributeInputType kFPAttributeInputType_Short = GL_SHORT;
			static const FPAttributeInputType kFPAttributeInputType_UShort = GL_UNSIGNED_SHORT;
			static const FPAttributeInputType kFPAttributeInputType_Int = GL_INT;
			static const FPAttributeInputType kFPAttributeInputType_UInt = GL_UNSIGNED_INT;
			static const FPAttributeInputType kFPAttributeInputType_HalfFloat = GL_HALF_FLOAT;
			static const FPAttributeInputType kFPAttributeInputType_Float = GL_FLOAT;
			static const FPAttributeInputType kFPAttributeInputType_Double = GL_DOUBLE;
			static const FPAttributeInputType kFPAttributeInputType_Int_2_10_10_10 = GL_INT_2_10_10_10_REV;
			static const FPAttributeInputType kFPAttributeInputType_UInt_2_10_10_10 = GL_UNSIGNED_INT_2_10_10_10_REV;
			static const FPAttributeInputType kFPAttributeInputType_UInt_10F_11F_11F = GL_UNSIGNED_INT_10F_11F_11F_REV;
			
			static const IntegerAttributeInputType kIntegerAttributeInputType_Byte = GL_BYTE;
			static const IntegerAttributeInputType kIntegerAttributeInputType_UByte = GL_UNSIGNED_BYTE;
			static const IntegerAttributeInputType kIntegerAttributeInputType_Short = GL_SHORT;
			static const IntegerAttributeInputType kIntegerAttributeInputType_UShort = GL_UNSIGNED_SHORT;
			static const IntegerAttributeInputType kIntegerAttributeInputType_Int = GL_INT;
			static const IntegerAttributeInputType kIntegerAttributeInputType_UInt = GL_UNSIGNED_INT;
			
			VertexArray ( uint32_t PreAllocFPAttributeCount = 4, uint32_t PreAllocIntegerAttributeCount = 0 );
			~VertexArray ();
			
			void GPUResourceAlloc ();
			void GPUResourceFree ();
			
			bool GPUResourceAllocated ();
			
			void SetProgram ( ShaderProgram * Program );
			
			void AddFPAttribute ( const std :: string Name, GLint Size, FPAttributeInputType InputType, bool Normalized, GLsizei Stride, GLvoid * Offset, VertexBuffer * Data );
			void AddIntegerAttribute ( const std :: string Name, GLint Size, IntegerAttributeInputType InputType, GLsizei Stride, GLvoid * Offset, VertexBuffer * Data );
			
			void SetIndexBuffer ( IndexBuffer * IBuffer );
			
			void Build ();
			
			void Bind ();
			
		private:
			
			friend class IndexBuffer;
			
			typedef struct
			{
				
				std :: string Name;
				
				bool Normalized;
				
				FPAttributeInputType InputType;
				
				GLint Size;
				GLsizei Stride;
				GLvoid * Offset;
				
				VertexBuffer * Data;
				
				GLint AttributeLocation;
				
			} FPAttributeStruct;
			
			typedef struct
			{
				
				std :: string Name;
				
				IntegerAttributeInputType InputType;
				
				GLint Size;
				GLsizei Stride;
				GLvoid * Offset;
				
				VertexBuffer * Data;
				
				GLint AttributeLocation;
				
			} IntegerAttributeStruct;
			
			bool Allocated;
			
			GLuint AHandle;
			
			std :: vector <FPAttributeStruct> FPAttributes;
			std :: vector <IntegerAttributeStruct> IntegerAttributes;
			
			IndexBuffer * IBuffer;
			
			ShaderProgram * Program;
			
		};
		
	}
	
}

#endif
