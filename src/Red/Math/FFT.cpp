#include <Red/Math/FFT.h>
#include <cmath>

inline bool _IsPowerOfTwo ( uint32_t Num )
{
	
	return ( ( Num != 0 ) && ( ( Num & ( ~ Num + 1 ) ) == Num ) );
	
}

inline uint8_t _ReverseByteBits ( uint8_t In )
{
	
	return static_cast <uint8_t> ( ( ( static_cast <uint64_t> ( In ) * 0x80200802ULL ) & 0x0884422110ULL ) * 0x0101010101ULL >> 32 );
	
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

void Red::Math::FFT_1DReal_Float :: Run ( float * InputData, uint32_t Stride )
{
	
	uint32_t I;
	uint32_t J;
	uint32_t K;
	
	for ( I = 0; I < ElementCount; I ++ )
	{
		Data [ _ReverseBits ( I, Level ) ] = InputData [ I * Stride ];
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
	
	return ElementCount / 2;
	
}

const std :: complex <float> * Red::Math::FFT_1DReal_Float :: GetResult ()
{
	
	return Data;
	
}

void Red::Math::FFT_1DReal_Float :: GetResultMagnitude ( float * Output )
{
	
	for ( uint32_t I = 0; I < ElementCount / 2; I ++ )
		Output [ I ] = abs ( Data [ I ] );
	
}

