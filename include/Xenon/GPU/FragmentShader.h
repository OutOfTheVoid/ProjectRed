#ifndef XENON_FRAGMENTSHADER_H
#define XENON_FRAGMENTSHADER_H

#include <Xenon/Xenon.h>
#include <Xenon/GPU/GPU.h>
#include <Xenon/GPU/IShader.h>
#include <Xenon/GPU/GLInclude.h>

#include <string>

namespace Xenon
{
	
	namespace GPU
	{
		
		class FragmentShader : public IShader
		{
		public:
			
			FragmentShader ( const std :: string Source, std :: string Name = "FragmentShader_Undefined" );
			
			~FragmentShader ();
			
			void GPUResourceAlloc ();
			void GPUResourceFree ();
			
			bool GPUResourceAllocated ();
			
			const std :: string & GetName ();
			
			bool Compile ( bool StoreCompilationLog = false, bool FreeSource = true );
			
			const std :: string & GetCompilationLog ();
			void FreeCompilationLog ();
			
		private:
			
			GLuint GetSHandle ();
			
			std :: string ShaderCode;
			bool DiscardableSource;
			
			GLuint SHandle;
			
			bool Allocated;
			bool Compiled;
			
			std :: string CompileLog;
			
			std :: string Name;
			
		};
		
	}
	
}

#endif