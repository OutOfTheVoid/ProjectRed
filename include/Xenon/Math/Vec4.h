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
		
		class Vec4
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
			
			static void Copy ( const Vec4 & Source, Vec4 & Destination );
			
			static float DotProduct ( const Vec4 & A, const Vec4 & B );
			
			static void Multiply ( Vec4 & A, float B );
			static void Multiply ( const Vec4 & A, float B, Vec4 & Result );
			
			static void Add ( const Vec4 & A, const Vec4 & B, Vec4 & Result );
			static void Add ( Vec4 & A, const Vec4 & B );
			static void Subtract ( const Vec4 & A, const Vec4 & B, Vec4 & Result );
			static void Subtract ( Vec4 & A, const Vec4 & B );
			
			static void Normalize ( Vec4 & A );
			static void Normalize ( const Vec4 & A, Vec4 & Result );
			
			static float Length ( const Vec4 & A );
			static float LengthSquared ( const Vec4 & A );
			
			static float AngleBetween ( const Vec4 & A, const Vec4 & B );
			
			static void Interpolate ( Vec4 & A, const Vec4 & B, float Fraction );
			static void Interpolate ( const Vec4 & A, const Vec4 & B, float Fraction, Vec4 & Result );
			
#ifdef XENON_SSE
			
			union
			{
				
				struct
				{
					
					float X;
					float Y;
					float Z;
					float W;
					
				};
				
				__m128 SSEV;
				
			};
			
#else
			
			float X;
			float Y;
			float Z;
			float W;
			
#endif
			
		};
		
	};
	
};

#endif
