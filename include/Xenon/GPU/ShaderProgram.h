#ifndef XENON_SHADERPROGRAM_H
#define XENON_SHADERPROGRAM_H

#include <Xenon/Xenon.h>
#include <Xenon/GPU/GPU.h>
#include <Xenon/GPU/IShader.h>
#include <Xenon/GPU/IGPUResourceUser.h>

#include <Xenon/GPU/GLInclude.h>

#include <string>

namespace Xenon
{
	
	namespace GPU
	{
		
		class ShaderProgram : public IGPUResourceUser
		{
		public:
			
			ShaderProgram ( const std :: string Name = "Undefined" );
			~ShaderProgram ();
			
			void GPUResourceAlloc ();
			void GPUResourceFree ();
			
			bool GPUResourceAllocated ();
			
			void AddShader ( IShader & Shader );
			void RemoveShader ( IShader & Shader );
			
			void Link ();
			
			int64_t GetLinkIteration ();
			
			void Bind ();
			
			GLint GetAttributeLocation ( const GLchar * Location );
			GLint GetUniformLocation ( const GLchar * Attribute );
			
			const std :: string & GetName ();
			
		private:
			
			const std :: string Name;
			
			bool Allocated;
			bool Bound;
			
			GLuint SHandle;
			
			int64_t LinkIteration;
			
		};
		
	};
	
};

#endif
