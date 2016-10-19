#ifndef RED_AUDIO_MATH_H
#define RED_AUDIO_MATH_H

#include <math.h>

#include <stdint.h>

inline float DecibelsToScaleF ( float Decibels )
{
	
	return powf ( 10.0f, 0.05f * Decibels );
	
}

inline float ScaleToDecibelsF ( float Scale )
{
	
	return 20.0f * log10f ( Scale );
	
}

inline double DecibelsToScaleF ( double Decibels )
{
	
	return pow ( 10.0f, 0.05f * Decibels );
	
}

inline double ScaleToDecibelsF ( double Scale )
{
	
	return 20.0f * log10 ( Scale );
	
}

#endif
