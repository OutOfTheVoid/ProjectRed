#ifndef XENON_GEOMETRY_MESHATTRIBUTE_H
#define XENON_GEOMETRY_MESHATTRIBUTE_H

#include <Xenon/Xenon.h>

#include <Xenon/Geometry/Geometry.h>

#include <Xenon/GPU/GLInclude.h>
#include <Xenon/GPU/VertexArray.h>

#include <Red/Util/RefCounted.h>

#include <stdint.h>

namespace Xenon
{
	
	namespace Geometry
	{
		
		class MeshAttributeData;
		
		class MeshAttribute : public Red::Util :: RefCounted
		{
		public:
			
			enum NoInit
			{
				
				NO_INIT
				
			};
			
			MeshAttribute ( NoInit NO_INIT );
			MeshAttribute ( const std :: string & Name, GPU::VertexArray :: FPAttributeInputType FloatingType, bool Normalized, GLuint Size, GLuint Stride, GLvoid * Offset, MeshAttributeData * Data, GLuint InstanceDivisor = 0 );
			MeshAttribute ( const std :: string & Name, GPU::VertexArray :: IntegerAttributeInputType IntegerType, GLuint Size, GLuint Stride, GLvoid * Offset, MeshAttributeData * Data, GLuint InstanceDivisor = 0 );
			
			~MeshAttribute ();
			
			void ApplyToVertexArray ( GPU :: VertexArray & Array );
			
			MeshAttributeData * GetDataPointer ();
			
			GLvoid * GetDataOffset ();
			GLuint GetStride ();
			GLuint GetSize ();
			GLuint GetInstanceDivisor ();
			
			bool IsFloatingPoint ();
			
			GPU::VertexArray :: FPAttributeInputType GetFloatingType ();
			GPU::VertexArray :: IntegerAttributeInputType GetIntegerType ();
			
			const std :: string & GetName ();
			
		private:
			
			const std :: string Name;
			
			bool FloatingPointInput;
			
			union
			{
				
				GPU::VertexArray :: FPAttributeInputType FloatingType;
				GPU::VertexArray :: IntegerAttributeInputType IntegerType;
				
			};
			
			bool Normalized;
			
			GLuint Size;
			GLuint Stride;
			GLvoid * Offset;
			GLuint InstanceDivisor;
			
			MeshAttributeData * Data;
			
		};
		
	}
	
}

#endif
