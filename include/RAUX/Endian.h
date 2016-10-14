#ifndef RAUX_ENDIAN_H
#define RAUX_ENDIAN_H

#include <stdint.h>

#ifdef __GNU_LIBRARY__
	#include <endian.h>
#endif

#ifdef __BYTE_ORDER__
	
	#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
		
		#define RAUX_BIG_ENDIAN_DEFINITE

	#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

		#define RAUX_LITTLE_ENDIAN_DEFINITE

	#else
	
		#define RAUX_ENDIAN_INDEFINATE

	#endif

#endif

inline uint32_t LittleToHostEndian32 ( const uint32_t In )
{
	
#ifdef RAUX_LITTLE_ENDIAN_DEFINITE
	
	return In;
	
#else
	
	const uint8_t * Bytes = reinterpret_cast <const uint8_t *> ( & In );
	
	return ( Bytes [ 0 ] << 0 ) | ( Bytes [ 1 ] << 8 ) | ( Bytes [ 2 ] << 16 ) | ( Bytes [ 3 ] << 24 );
	
#endif
	
}

inline uint32_t BigToHostEndian32 ( const uint32_t In )
{
	
#ifdef RAUX_BIG_ENDIAN_DEFINITE
	
	return In;
	
#else
	
	const uint8_t * Bytes = reinterpret_cast <const uint8_t *> ( & In );
	
	return ( Bytes [ 3 ] << 0 ) | ( Bytes [ 2 ] << 8 ) | ( Bytes [ 1 ] << 16 ) | ( Bytes [ 0 ] << 24 );
	
#endif
	
}

inline uint16_t LittleToHostEndian16 ( const uint16_t In )
{
	
#ifdef RAUX_LITTLE_ENDIAN_DEFINITE
	
	return In;
	
#else
	
	const uint8_t * Bytes = reinterpret_cast <const uint8_t *> ( & In );
	
	return ( Bytes [ 0 ] << 0 ) | ( Bytes [ 1 ] << 8 );
	
#endif
	
}

inline uint16_t BigToHostEndian16 ( const uint16_t In )
{
	
#ifdef RAUX_BIG_ENDIAN_DEFINITE
	
	return In;
	
#else
	
	const uint8_t * Bytes = reinterpret_cast <const uint8_t *> ( & In );
	
	return ( Bytes [ 1 ] << 0 ) | ( Bytes [ 0 ] << 8 );
	
#endif
	
}

// Assumes that a float is 32 bits.
inline float LittleToHostEndianFloat ( const float In )
{
	
	uint32_t Value = LittleToHostEndian32 ( * reinterpret_cast <const uint32_t *> ( & In ) );
	
	return * reinterpret_cast <const float *> ( & Value );
	
}

inline float BigToHostEndianFloat ( const float In )
{
	
	uint32_t Value = BigToHostEndian32 ( * reinterpret_cast <const uint32_t *> ( & In ) );
	
	return * reinterpret_cast <const float *> ( & Value );
	
}

inline uint16_t HostToLittleEndian16 ( const uint16_t In )
{
	
#ifdef RAUX_LITTLE_ENDIAN_DEFINITE
	
	return In;
	
#else
	
	uint16_t Out;
	
	reinterpret_cast <uint8_t *> ( & Out ) [ 0 ] = In;
	reinterpret_cast <uint8_t *> ( & Out ) [ 1 ] = In >> 8;
	
	return Out;
	
#endif
	
}

inline uint16_t HostToBigEndian16 ( const uint16_t In )
{
	
#ifdef RAUX_Big_ENDIAN_DEFINITE
	
	return In;
	
#else
	
	uint16_t Out;
	
	reinterpret_cast <uint8_t *> ( & Out ) [ 1 ] = In;
	reinterpret_cast <uint8_t *> ( & Out ) [ 0 ] = In >> 8;
	
	return Out;
	
#endif
	
}

#endif
