#ifndef RED_UTIL_SSE_H
#define RED_UTIL_SSE_H

#define SSE_ALLOW

#ifdef SSE_ALLOW

#ifdef __SSE__

	#include <xmmintrin.h>
	
	#define RED_SSE

#endif

#ifdef __SSE3__
	
	#include <pmmintrin.h>
	
	#define RED_SSE3
	
#endif

#ifdef __SSE4_1__
	
	#include <smmintrin.h>
	
	#define RED_SSE4_1
	
#endif

#endif

#endif