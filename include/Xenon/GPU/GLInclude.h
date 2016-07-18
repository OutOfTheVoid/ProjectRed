#ifndef XENON_GLINCLUDE_H
#define XENON_GLINCLUDE_H

#define GL3_PROTOTYPES

#if defined ( __APPLE__ )

	#include <OpenGL/gl3.h>
	
#else
	
	#ifdef _WIN32
	  
	  #include <windows.h>
	
	#endif
	
	#include <GL/glcorearb.h> // assert GL 3.2 core profile available...
	
#endif

#endif