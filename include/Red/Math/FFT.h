#ifndef RED_MATH_FFT_H
#define RED_MATH_FFT_H

#include <Red/Math/Math.h>

#include <complex>

namespace Red
{
	
	namespace Math
	{
		
		class FFT_1DReal_Float
		{
		public:
			
			FFT_1DReal_Float ();
			~FFT_1DReal_Float ();
			
			void Setup ( uint32_t ElementCount );
			void Destroy ();
			
			void Run ( const float * InputData, uint32_t Stride = 1 );
			
			uint32_t GetResultLength ();
			const std :: complex <float> * GetResult ();
			
			void GetResultMagnitude ( float * Output, uint32_t Stride = 1 );
			void GetResultReal ( float * Output, uint32_t Stride = 1 );
			
		private:
			
			uint32_t ElementCount;
			uint32_t ResultElementCount;
			
			uint32_t Level;
			
			std :: complex <float> ** RootsOfUnity;
			
			std :: complex <float> * Data;
			
		};
		
		class IFFT_1DReal_Float
		{
		public:
			
			IFFT_1DReal_Float ();
			~IFFT_1DReal_Float ();
			
			void Setup ( uint32_t ElementCount );
			void Destroy ();
			
			void Run ( const std :: complex <float> * InputData, uint32_t Stride );
			
			uint32_t GetResultLength ();
			const std :: complex <float> * GetResult ();
			
			void GetResultMagnitude ( float * Output, uint32_t Stride );
			void GetResultReal ( float * Output, uint32_t Stride );
			
		private:
			
			uint32_t ElementCount;
			uint32_t ResultElementCount;
			
			uint32_t Level;
			
			std :: complex <float> ** RootsOfUnity;
			
			std :: complex <float> * Data;
			
		};
		
	}
	
}

#endif
