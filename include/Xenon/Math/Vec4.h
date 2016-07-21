#ifndef XENON_VEC4_H
#define XENON_VEC4_H

#include <Xenon/Xenon.h>
#include <Xenon/Math/Math.h>
#include <Xenon/SSE.h>

namespace Xenon
{
	
	namespace Math
	{
		
		class Vec3;
		
		class alignas ( 16 ) Vec4
		{
		public:
			
			enum NoInit
			{
				
				NO_INIT
				
			};
			
			Vec4 ( float X = 0.0, float Y = 0.0, float Z = 0.0, float W = 0.0 );
			Vec4 ( Vec3 & XYZ, float W = 0.0 );
			Vec4 ( const Vec4 & CopyFrom );
#ifdef XENON_SSE
			Vec4 ( __m128 SSEV );
#endif
			Vec4 ( NoInit NO_INIT );
			~Vec4 ();
			
			static void Copy ( Vec4 & Target, const Vec4 & Source );
			
			static float DotProduct ( const Vec4 & SourceA, const Vec4 & SourceB );
			
			static void Multiply ( Vec4 & Target, float Scalar );
			static void Multiply ( Vec4 & Target, const Vec4 & Source, float Scalar );
			
			static void Add ( Vec4 & Target, const Vec4 & SourceA, const Vec4 & SourceB );
			static void Add ( Vec4 & Target, const Vec4 & Source );
			static void Subtract ( Vec4 & Target, const Vec4 & SourceA, const Vec4 & SourceB );
			static void Subtract ( Vec4 & Target, const Vec4 & Source );
			
			static void Normalize ( Vec4 & Target );
			static void Normalize ( Vec4 & Target, const Vec4 & Source );
			
			static float Length ( const Vec4 & Source );
			static float LengthSquared ( const Vec4 & Source );
			
			static float AngleBetween ( const Vec4 & SourceA, const Vec4 & SourceB );
			
			static void Interpolate ( Vec4 & Target, const Vec4 & Source, float Fraction );
			static void Interpolate ( Vec4 & Target, const Vec4 & SourceA, const Vec4 & SourceB, float Fraction );
			
			static void Project ( Vec4 & Target, const Vec4 & Direction );
			static void Project ( Vec4 & Target, const Vec4 & Projected, const Vec4 & Direction );
			
			float X;
			float Y;
			float Z;
			float W;
			
		};
		
	}
	
}

#endif
