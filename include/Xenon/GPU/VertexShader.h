#ifndef XENON_VERTEXSHADER_H
#define XENON_VERTEXSHADER_H

#include <Xenon/Xenon.h>
#include <Xenon/GPU/GPU.h>
#include <Xenon/GPU/IShader.h>
#include <Xenon/GPU/GLInclude.h>


namespace Xenon
{
	
	namespace GPU
	{
		
		class VertexShader : public IShader
		{
		public:
			
			VertexShader ( const GLchar * Source, const char * Name = "VertexShader_Undefined" );
			VertexShader ( const GLchar * Source, bool FreeOnCompile, const char * Name = "VertexShader_Undefined" );
			
			~VertexShader ();
			
			void GPUResourceAlloc ();
			void GPUResourceFree ();
			
			bool GPUResourceAllocated ();
			
			const std :: string & GetName ();
			
			bool Compile ( bool StoreCompilationLog = false, bool FreeSource = true );
			
			const std :: string & GetCompilationLog ();
			void FreeCompilationLog ();
			
		private:
			
			static const char * kErrorLog_GPUResourceFreedAfterShaderCodeFreed;
			
			GLuint GetSHandle ();
			
			std :: string ShaderCode;
			bool DiscardableSource;
			
			GLuint SHandle;
			
			bool Allocated;
			bool Compiled;
			
			std :: string CompileLog;
			
			const std :: string Name;
			
		};
		
	};
	
};

#endif
