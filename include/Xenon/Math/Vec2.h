#ifndef XENON_MATH_VEC2_H
#define XENON_MATH_VEC2_H

namespace Xenon
{
	
	namespace Math
	{
		
		class Vec2
		{
		public:
			
			const static Vec2 UP;
			const static Vec2 DOWN;
			const static Vec2 LEFT;
			const static Vec2 RIGHT;
			
			const static Vec2 IDENTITY;
			const static Vec2 ZERO;
			
			enum NoInit
			{
				
				NO_INIT
				
			};
			
			Vec2 ( const float X = 0.0f, const float Y = 0.0f );
			Vec2 ( const Vec2 & CopyFrom );
			Vec2 ( NoInit NO_INIT );
			
			~Vec2 ();
			
			static void Copy ( Vec2 & Target, const Vec2 & Source );
			
			static bool Equal ( const Vec2 & A, const Vec2 & B );
			
			static float DotProduct ( const Vec2 & A, const Vec2 & B );
			
			static void Multiply ( Vec2 & Target, const float Scalar );
			static void Multiply ( Vec2 & Target, const Vec2 & Source, const float Scalar );
			
			static void Scale ( Vec2 & Target, const Vec2 & B );
			static void Scale ( Vec2 & Target, const Vec2 & Source, const Vec2 & B );
			
			static void Add ( Vec2 & Target, const Vec2 & Source, const Vec2 & B );
			static void Add ( Vec2 & Target, const Vec2 & B );
			static void Subtract ( Vec2 & Target, const Vec2 & Source, const Vec2 & B );
			static void Subtract ( Vec2 & Target, const Vec2 & B );
			
			static void Normalize ( Vec2 & A );
			static void Normalize ( Vec2 & Result, const Vec2 & Source );
			
			static float Length ( const Vec2 & Source );
			static float LengthSquared ( const Vec2 & Source );
			
			static void Absolute ( Vec2 & Target );
			static void Absolute ( Vec2 & Target, const Vec2 & Source );
			
			static float AngleBetween ( const Vec2 & A, const Vec2 & B );
			
			static void Interpolate ( Vec2 & Target, const Vec2 & B, const float Fraction );
			static void Interpolate ( Vec2 & Target, const Vec2 & Source, const Vec2 & B, const float Fraction );
			
			static float ScalarProjection ( const Vec2 & Source, const Vec2 & Direction );
			
			static void Project ( Vec2 & Target, const Vec2 & Direction );
			static void Project ( Vec2 & Target, const Vec2 & Projected, const Vec2 & Direction );
			
			float X;
			float Y;
			
		};
		
	};
	
};

#endif
