#ifndef XENON_GPU_GEOMETRYSHADER_H
#define XENON_GPU_GEOMETRYSHADER_H

#include <Xenon/Xenon.h>

#include <Xenon/GPU/GPU.h>
#include <Xenon/GPU/IShader.h>

#include <string>

namespace Xenon
{
	
	namespace GPU
	{
		
		class GeometryShader : public IShader
		{
		public:
			
			GeometryShader ( const std :: string Source, const std :: string Name = "GeometryShader_Undefined" );
			
			~GeometryShader ();
			
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
			
			const std :: string Name;
			
		};
		
	}
	
}

#endif
