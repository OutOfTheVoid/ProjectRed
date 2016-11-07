#ifndef XENON_XENON_H
#define XENON_XENON_H

/*
* Xenon: an object-oriented OpenGL 3.2+ wrapper library that makes use of C++11 to provide an efficient, easy to use interface to the GPU.
*/

#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>

// Leave defined for error messages.
#define XENON_DEBUG

// Leave defined to use gl3w to load OpenGL functions. ( needed for windows, mostly )
//#define XENON_GL3W_GL_LOADER

#define XENON_LOG_ERROR( ... ) ::Xenon::_Xenon_Log ( __FILE__, __LINE__, __VA_ARGS__ )

namespace Xenon
{

	void Init ();
	
	inline void _Xenon_Log ( const char * FileName, unsigned int LineNumber, const char * Format, ... )
	{
		
		va_list Args;
		
		printf ( "%s, %u: ", FileName, LineNumber );
		
		va_start ( Args, Format );
		vprintf ( Format, Args );
		va_end ( Args );
		
	}
	
}

#endif
