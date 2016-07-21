#ifndef XENON_QUATERNION_H
#define XENON_QUATERNION_H

#include <Xenon/Xenon.h>
#include <Xenon/Math/Math.h>
#include <Xenon/Math/Vec4.h>
#include <Xenon/SSE.h>

namespace Xenon
{
	
	namespace Math
	{
		
		class Vec3;

		class alignas ( 16 ) Quaternion : public Vec4
		{
		public:
			
			static const Quaternion IDENTITY; // No rotation, <0, 0, 0, 1>
			
			enum NoInit
			{
				
				NO_INIT
				
			};
			
			Quaternion ( NoInit NO_INIT );
			Quaternion ( const Quaternion & Source );
			explicit Quaternion ( float X = 0.0, float Y = 0.0, float Z = 0.0, float W = 1.0 );
			~Quaternion ();
			
			static void Add ( Quaternion & Target, const Quaternion & Source );
			static void Add ( Quaternion & Target, const Quaternion & SourceA, const Quaternion & SourceB );
			static void Subtract ( Quaternion & Target, const Quaternion & Source );
			static void Subtract ( Quaternion & Target, const Quaternion & SourceA, const Quaternion & SourceB );
			
			static void Multiply ( Quaternion & Target, const float Scalar );
			static void Multiply ( Quaternion & Target, const Quaternion & Source, const float Scalar );
			
			static void Append ( Quaternion & Target, const Quaternion & Source );
			static void Append ( Quaternion & Result, const Quaternion & SourceA, const Quaternion & Source );
			static void Prepend ( Quaternion & Target, const Quaternion & Source );
			static void Prepend ( Quaternion & Result, const Quaternion & SourceA, const Quaternion & Source );
			
			static void Conjugate ( Quaternion & Target );
			static void Conjugate ( Quaternion & Target, const Quaternion & Source );
			
			static void InterpolateSLERP ( Quaternion & Target, const Quaternion & Interpoplated, const float Fraction );
			static void InterpolateSLERP ( Quaternion & Result, const Quaternion & SourceA, const Quaternion & SourceB, const float Fraction );
			
			static void FromYPR ( Quaternion & Target, const float Yaw, const float Pitch, const float Roll );
			static void FromAxisAngle ( Quaternion & Target, const Vec3 & Axis, const float Angle );
			static void FromBetweenVectors ( Quaternion & Target, const Vec3 & From, const Vec3 & To );
			
			static void Normalize ( Quaternion & Target );
			static void Normalize ( Quaternion & Target, const Quaternion & Source );
			
			static float Length ( const Quaternion & Source );
			
			static float Yaw ( const Quaternion & Source );
			static float Pitch ( const Quaternion & Source );
			static float Roll ( const Quaternion & Source );
			
			static void Axis ( Vec3 & Target, const Quaternion & Source );
			static float Angle ( const Quaternion & Source );
			
		};
		
	}

}

#endif
