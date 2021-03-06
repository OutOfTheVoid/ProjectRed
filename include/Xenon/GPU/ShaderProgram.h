#ifndef XENON_SHADERPROGRAM_H
#define XENON_SHADERPROGRAM_H

#include <Xenon/Xenon.h>
#include <Xenon/GPU/GPU.h>
#include <Xenon/GPU/IShader.h>
#include <Xenon/GPU/IGPUResourceUser.h>
#include <Xenon/GPU/GLInclude.h>

#include <Red/Util/RefCounted.h>

#include <string>

namespace Xenon
{
	
	namespace GPU
	{
		
		class ShaderProgram : public IGPUResourceUser, public Red::Util :: RefCounted
		{
		public:
			
			ShaderProgram ( const std :: string & Name = "Undefined" );
			~ShaderProgram ();
			
			void GPUResourceAlloc ();
			void GPUResourceFree ();
			
			bool GPUResourceAllocated ();
			
			void AddShader ( IShader & Shader );
			void RemoveShader ( IShader & Shader );
			
			bool Link ();
			
			int64_t GetLinkIteration ();
			
			void Bind ();
			
			GLint GetAttributeLocation ( const GLchar * Location );
			GLint GetUniformLocation ( const GLchar * Attribute );
			
			const std :: string & GetName ();
			
			const std :: string & GetInfoLog ();
			void FreeInfoLog ();
			
		private:
			
			const std :: string Name;
			
			bool Allocated;
			bool Bound;
			
			GLuint SHandle;
			
			int64_t LinkIteration;
			
			std :: string InfoLog;
			
		};
		
	}
	
}

#endif
