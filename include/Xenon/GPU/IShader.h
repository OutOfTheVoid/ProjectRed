#ifndef XENON_ISHADER_H
#define XENON_ISHADER_H

#include <Xenon/Xenon.h>
#include <Xenon/GPU/GPU.h>

#include <Xenon/GPU/GLInclude.h>

#include <string>

namespace Xenon
{
	
	namespace GPU
	{
		
		class ShaderProgram;
		
		class IShader
		{
		public:
			
			virtual const std :: string & GetName () = 0;
			
		private:
			
			friend class ShaderProgram;
			
			virtual GLuint GetSHandle () = 0;
			
		};
		
	}
	
}

#endif
