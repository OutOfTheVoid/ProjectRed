#include <Red/Math/FFT.h>
#include <math.h>

// Why wouldn't windows math.h deifne M_PI?????
#ifndef M_PI
	#define M_PI 3.14159265358979323846264338327950288
#endif

inline bool _IsPowerOfTwo ( uint32_t Num )
{
	
	return ( ( Num != 0 ) && ( ( Num & ( ~ Num + 1 ) ) == Num ) );
	
}

inline uint8_t _ReverseByteBits ( uint8_t In )
{
	
	return static_cast <uint8_t> ( ( ( In * 0x0802LU & 0x22110LU ) | ( In * 0x8020LU & 0x88440LU ) ) * 0x10101LU >> 16 );
	
}

inline uint32_t _ReverseBits ( uint32_t Number, uint32_t BitCount )
{

	uint32_t ByteReversed = ( ( _ReverseByteBits ( Number ) << 24 ) | ( _ReverseByteBits ( Number >> 8 ) << 16 ) | ( _ReverseByteBits ( Number >> 16 ) << 8 ) | _ReverseByteBits ( Number >> 24 ) );
	return ( ByteReversed >> ( 32 - BitCount ) );
	
}

Red::Math::FFT_1DReal_Float :: FFT_1DReal_Float ():
	ElementCount ( 0 ),
	ResultElementCount ( 0 ),
	Level ( 0 ),
	RootsOfUnity ( NULL ),
	Data ( NULL )
{
}

Red::Math::FFT_1DReal_Float :: ~FFT_1DReal_Float ()
{
	
	if ( ElementCount != 0 )
		Destroy ();
	
}

void Red::Math::FFT_1DReal_Float :: Setup ( uint32_t ElementCount )
{
	
	if ( ElementCount != 0 )
		Destroy ();
	
	if ( ! _IsPowerOfTwo ( ElementCount ) )
		return;
	
	this -> ElementCount = ElementCount;
	
	Level = static_cast <uint32_t> ( std :: log2 ( ElementCount ) );
	
	RootsOfUnity = new std :: complex <float> * [ Level ];
	
	uint32_t L = 0;
	
	for ( uint32_t I = 2; I <= ElementCount; I <<= 1 )
	{
		
		RootsOfUnity [ L ] = new std :: complex <float> [ I / 2 ];
		
		for ( uint32_t J = 0; J < I / 2; J ++ )
			RootsOfUnity [ L ][ J ] = std :: polar ( 1.0, - 2.0 * M_PI * static_cast <double> ( J ) / static_cast <double> ( I ) );
		
		L ++;
		
	}
	
	Data = new std :: complex <float> [ ElementCount ];
	
}

void Red::Math::FFT_1DReal_Float :: Destroy ()
{
	
	for ( uint32_t I = 0; I < Level; I ++ )
		delete [] RootsOfUnity [ I ];
	
	delete [] RootsOfUnity;
	RootsOfUnity = NULL;
	
	delete [] Data;
	Data = NULL;
	
	ElementCount = 0;
	ResultElementCount = 0;
	
}

void Red::Math::FFT_1DReal_Float :: Run ( const float * InputData, bool Reverse, uint32_t Stride )
{
	
	uint32_t I;
	uint32_t J;
	uint32_t K;
	
	if ( Reverse )
	{
		
		for ( I = 0; I < ElementCount; I ++ )
			Data [ _ReverseBits ( I, Level ) ] = std :: complex <float> ( InputData [ I * Stride ], 0.0 );
		
	}
	else
	{
		
		for ( I = 0; I < ElementCount; I ++ )
			Data [ I ] = InputData [ I * Stride ];
		
	}
	
	uint32_t L = 0;
	
	for ( I = 2; I <= ElementCount; I <<= 1 )
	{
		
		for ( J = 0; J < ( I >> 1 ); J ++ )
		{
			
			for ( K = 0; K < ( ElementCount / I ); K ++ )
			{
				
				const uint32_t Index1 = K * I + J;
				const uint32_t Index2 = Index1 + ( I >> 1 );
				const std :: complex <float> Temp = RootsOfUnity [ L ][ J ] * Data [ Index2 ];
				Data [ Index2 ] = Data [ Index1 ] - Temp;
				Data [ Index1 ] = Data [ Index2 ] + Temp;
				
			}
			
		}
		
		L ++;
		
	}
	
}

uint32_t Red::Math::FFT_1DReal_Float :: GetResultLength ()
{
	
	return ElementCount;
	
}

const std :: complex <float> * Red::Math::FFT_1DReal_Float :: GetResult ()
{
	
	return Data;
	
}

void Red::Math::FFT_1DReal_Float :: GetResultMagnitude ( float * Output, uint32_t Stride )
{
	
	for ( uint32_t I = 0; I < ElementCount; I ++ )
		Output [ I * Stride ] = abs ( Data [ I ] );
	
}

void Red::Math::FFT_1DReal_Float :: GetResultMagnitudeBitReversed ( float * Output, uint32_t Stride )
{
	
	for ( uint32_t I = 0; I < ElementCount; I ++ )
		Output [ _ReverseBits ( I, Level ) * Stride ] = std :: abs ( Data [ I ] );
	
}

void Red::Math::FFT_1DReal_Float :: GetResultReal ( float * Output, uint32_t Stride )
{
	
	for ( uint32_t I = 0; I < ElementCount; I ++ )
		Output [ I * Stride ] = Data [ I ].real ();
	
}

void Red::Math::FFT_1DReal_Float :: GetResultRealBitReversed ( float * Output, uint32_t Stride )
{
	
	for ( uint32_t I = 0; I < ElementCount; I ++ )
		Output [ I * Stride ] = Data [ _ReverseBits ( I, Level ) ].real ();
	
}

void Red::Math::FFT_1DReal_Float :: GetResultBitReversed ( std :: complex <float> * Output, uint32_t Stride )
{
	
	for ( uint32_t I = 0; I < ElementCount; I ++ )
		Output [ _ReverseBits ( I, Level ) * Stride ] = Data [ I ];
	
}

Red::Math::IFFT_1DReal_Float :: IFFT_1DReal_Float ():
	ElementCount ( 0 ),
	ResultElementCount ( 0 ),
	Level ( 0 ),
	RootsOfUnity ( NULL ),
	Data ( NULL )
{
}

Red::Math::IFFT_1DReal_Float :: ~IFFT_1DReal_Float ()
{
	
	if ( ElementCount != 0 )
		Destroy ();
	
}

void Red::Math::IFFT_1DReal_Float :: Setup ( uint32_t ElementCount )
{
	
	if ( ElementCount != 0 )
		Destroy ();
	
	if ( ! _IsPowerOfTwo ( ElementCount ) )
		return;
	
	this -> ElementCount = ElementCount;
	
	Level = static_cast <uint32_t> ( std :: log2 ( ElementCount ) );
	
	RootsOfUnity = new std :: complex <float> * [ Level ];
	
	uint32_t L = 0;
	
	for ( uint32_t I = 2; I <= ElementCount; I <<= 1 )
	{
		
		RootsOfUnity [ L ] = new std :: complex <float> [ I / 2 ];
		
		for ( uint32_t J = 0; J < I / 2; J ++ )
			RootsOfUnity [ L ][ J ] = std :: polar ( 1.0, - 2.0 * M_PI * static_cast <double> ( J ) / static_cast <double> ( I ) );
		
		L ++;
		
	}
	
	Data = new std :: complex <float> [ ElementCount ];
	
}

void Red::Math::IFFT_1DReal_Float :: Destroy ()
{
	
	for ( uint32_t I = 0; I < Level; I ++ )
		delete [] RootsOfUnity [ I ];
	
	delete [] RootsOfUnity;
	RootsOfUnity = NULL;
	
	delete [] Data;
	Data = NULL;
	
	ElementCount = 0;
	ResultElementCount = 0;
	
}

void Red::Math::IFFT_1DReal_Float :: Run ( const std :: complex <float> * InputData, bool UnReverse, uint32_t Stride )
{
	
	uint32_t I;
	uint32_t J;
	uint32_t K;
	
	if ( UnReverse )
	{
		
		for ( I = 0; I < ElementCount; I ++ )
			Data [ _ReverseBits ( I, Level ) ] = std :: conj ( InputData [ I * Stride ] );
		
	}
	else
	{
		
		for ( I = 0; I < ElementCount; I ++ )
			Data [ I ] = std :: conj ( InputData [ I * Stride ] );
		
	}
	
	uint32_t L = 0;
	
	for ( I = 2; I <= ElementCount; I <<= 1 )
	{
		
		for ( J = 0; J < ( I >> 1 ); J ++ )
		{
			
			for ( K = 0; K < ( ElementCount / I ); K ++ )
			{
				
				const uint32_t Index1 = K * I + J;
				const uint32_t Index2 = Index1 + ( I >> 1 );
				const std :: complex <float> Temp = RootsOfUnity [ L ][ J ] * Data [ Index2 ];
				Data [ Index2 ] = Data [ Index1 ] - Temp;
				Data [ Index1 ] = Data [ Index2 ] + Temp;
				
			}
			
		}
		
		L ++;
		
	}
	
	std :: complex <float> Divisor ( static_cast <float> ( ElementCount ) );
	
	for ( I = 0; I < ElementCount; I ++ )
		Data [ I ] = std :: conj ( Data [ I ] );
	
}

uint32_t Red::Math::IFFT_1DReal_Float :: GetResultLength ()
{
	
	return ElementCount;
	
}

const std :: complex <float> * Red::Math::IFFT_1DReal_Float :: GetResult ()
{
	
	return Data;
	
}

void Red::Math::IFFT_1DReal_Float :: GetResultMagnitude ( float * Output, uint32_t Stride )
{
	
	for ( uint32_t I = 0; I < ElementCount; I ++ )
		Output [ I * Stride ] = abs ( Data [ I ] );
	
}

void Red::Math::IFFT_1DReal_Float :: GetResultReal ( float * Output, uint32_t Stride )
{
	
	for ( uint32_t I = 0; I < ElementCount; I ++ )
		Output [ I * Stride ] = Data [ I ].real ();
	
}
