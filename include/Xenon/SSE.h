#ifndef XENON_SSE_H
#define XENON_SSE_H

#define SSE_ALLOW

#ifdef SSE_ALLOW

#ifdef __SSE__

	#include <xmmintrin.h>
	
	#define XENON_SSE

#endif

#ifdef __SSE3__
	
	#include <pmmintrin.h>
	
	#define XENON_SSE3
	
#endif

#ifdef __SSE4_1__
	
	#include <smmintrin.h>
	
	#define XENON_SSE4_1
	
#endif

#endif

#endif