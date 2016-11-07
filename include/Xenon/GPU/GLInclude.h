#ifndef XENON_GLINCLUDE_H
#define XENON_GLINCLUDE_H

#define GL3_PROTOTYPES

#if defined ( __APPLE__ )

	#include <OpenGL/gl3.h>
	
#else
	
	#ifdef _WIN32
	  
	#include <windows.h>
	
	#define GL_GLEXT_PROTOTYPES
	#include <gl/glcorearb.h>
	
	#else
	
	#undef GL_GLEXT_PROTOTYPES
	
	#include <GL/gl.h>
	
	#endif

#endif

#endif