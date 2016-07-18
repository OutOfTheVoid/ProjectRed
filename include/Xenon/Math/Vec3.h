#ifndef XENON_VEC3_H
#define XENON_VEC3_H

#include <Xenon/Xenon.h>
#include <Xenon/Math/Math.h>

namespace Xenon
{
	
	namespace Math
	{

		class Quaternion;
		class Vec2;

		class Vec3
		{
		public:
			
			enum NoInit
			{
				
				NO_INIT
				
			};
			
			const static Vec3 RIGHT;	// + X
			const static Vec3 LEFT;		// - X
			const static Vec3 UP;		// + Y
			const static Vec3 DOWN;		// - Y
			const static Vec3 FORWARD;	// + Z
			const static Vec3 BACKWARD;	// - Z
			
			const static Vec3 IDENTITY; // <1, 1, 1>
			const static Vec3 ZERO; // <0, 0, 0>
			
			explicit Vec3 ( const float X = 0.0, const float Y = 0.0, const float Z = 0.0 );
			Vec3 ( const Vec3 & CopyFrom );
			explicit Vec3 ( const Vec2 & Lower, const float Z );
			inline explicit Vec3 ( NoInit NO_INIT ) {};
			~Vec3 ();
			
			static void Set ( Vec3 & Target, const float X, const float Y, const float Z );
			
			static void Copy (  Vec3 & Target, const Vec3 & Source );
			
			static bool Equal ( const Vec3 & A, const Vec3 & B );
			
			static float DotProduct ( const Vec3 & A, const Vec3 & B );
			
			static void CrossProduct ( Vec3 & Target, const Vec3 & Source, const Vec3 & B );
			static void CrossProduct ( Vec3 & A, const Vec3 & B );
			
			static void Multiply ( Vec3 & Target, const float B );
			static void Multiply ( Vec3 & Target, const Vec3 & Source, const float B );
			
			static void Scale ( Vec3 & Target, const Vec3 & B );
			static void Scale ( Vec3 & Target, const Vec3 & Source, const Vec3 & B );
			
			static void Add ( Vec3 & Target, const Vec3 & B );
			static void Add ( Vec3 & Target, const Vec3 & Source, const Vec3 & B );
			
			static void Subtract ( Vec3 & Target, const Vec3 & B );
			static void Subtract ( Vec3 & Target, const Vec3 & Source, const Vec3 & B );
			
			static void Normalize ( Vec3 & Target );
			static void Normalize ( Vec3 & Target, const Vec3 & Source );
			
			static float Length ( const Vec3 & Source );
			static float LengthSquared ( const Vec3 & Source );
			
			static void Absolute ( Vec3 & Target );
			static void Absolute ( Vec3 & Target, const Vec3 & Source );
			
			static float AngleBetween ( const Vec3 & A, const Vec3 & B );
			
			static void Interpolate ( Vec3 & Target, const Vec3 & B, const float Fraction );
			static void Interpolate ( Vec3 & Target, const Vec3 & Source, const Vec3 & B, const float Fraction );
			
			static void Rotate ( Vec3 & Target, const Quaternion & Rotation );
			static void Rotate ( Vec3 & Target, const Vec3 & Source, const Quaternion & Rotation );
			
			static void Orthogonal ( Vec3 & Target );
			static void Orthogonal ( Vec3 & Target, const Vec3 & Source );
			
			float X;
			float Y;
			float Z;
			
		};
		
	};

};

#endif