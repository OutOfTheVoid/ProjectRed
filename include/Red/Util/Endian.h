#ifndef RED_UTIL_ENDIAN_H
#define RED_UTIL_ENDIAN_H

#include <stdint.h>

#ifdef __GNU_LIBRARY__
	#include <endian.h>
#endif

#ifdef __BYTE_ORDER__
	
	#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__ && __BYTE_ORDER__ != __ORDER_LITTLE_ENDIAN__
		
		#define RED_BIG_ENDIAN_DEFINITE

	#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

		#define RED_LITTLE_ENDIAN_DEFINITE

	#else
	
		#define RED_ENDIAN_INDEFINATE

	#endif

#endif

inline uint32_t LittleToHostEndian32 ( const uint32_t In )
{
	
#ifdef RED_LITTLE_ENDIAN_DEFINITE
	
	return In;
	
#else
	
	const uint8_t * Bytes = reinterpret_cast <const uint8_t *> ( & In );
	
	return ( Bytes [ 0 ] & 0xFF ) | ( ( Bytes [ 1 ] << 8 ) & 0xFF00 ) | ( Bytes [ 2 ] << 16 ) & 0xFF0000 ) | ( ( Bytes [ 3 ] << 24 ) & 0xFF000000 );
	
#endif
	
}

inline uint32_t BigToHostEndian32 ( const uint32_t In )
{
	
#ifdef RED_BIG_ENDIAN_DEFINITE
	
	return In;
	
#else
	
	const uint8_t * Bytes = reinterpret_cast <const uint8_t *> ( & In );
	
	return ( ( Bytes [ 0 ] << 24 ) & 0xFF000000 ) | ( ( Bytes [ 1 ] << 16 ) & 0xFF0000 ) | ( ( Bytes [ 2 ] << 8 ) & 0xFF00 ) | ( Bytes [ 3 ] & 0xFF );
#endif
	
}

inline uint16_t LittleToHostEndian16 ( const uint16_t In )
{
	
#ifdef RED_LITTLE_ENDIAN_DEFINITE
	
	return In;
	
#else
	
	const uint8_t * Bytes = reinterpret_cast <const uint8_t *> ( & In );
	
	return ( Bytes [ 0 ] << 0 ) | ( ( Bytes [ 1 ] << 8 ) & 0xFF00 );
	
#endif
	
}

inline uint16_t BigToHostEndian16 ( const uint16_t In )
{
	
#ifdef RED_BIG_ENDIAN_DEFINITE
	
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
	
#ifdef RED_LITTLE_ENDIAN_DEFINITE
	
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
	
#ifdef RED_BIG_ENDIAN_DEFINITE
	
	return In;
	
#else
	
	uint16_t Out;
	
	reinterpret_cast <uint8_t *> ( & Out ) [ 1 ] = In;
	reinterpret_cast <uint8_t *> ( & Out ) [ 0 ] = In >> 8;
	
	return Out;
	
#endif
	
}

inline uint32_t HostToLittleEndian32 ( const uint32_t In )
{
	
#ifdef RED_LITTLE_ENDIAN_DEFINITE
	
	return In;
	
#else
	
	uint32_t Out;
	
	reinterpret_cast <uint8_t *> ( & Out ) [ 0 ] = In;
	reinterpret_cast <uint8_t *> ( & Out ) [ 1 ] = In >> 8;
	reinterpret_cast <uint8_t *> ( & Out ) [ 2 ] = In >> 16;
	reinterpret_cast <uint8_t *> ( & Out ) [ 3 ] = In >> 24;
	
	return Out;
	
#endif
	
}

inline uint32_t HostToBigEndian32 ( const uint32_t In )
{
	
#ifdef RED_BIG_ENDIAN_DEFINITE
	
	return In;
	
#else
	
	uint32_t Out;
	
	reinterpret_cast <uint8_t *> ( & Out ) [ 0 ] = In >> 24;
	reinterpret_cast <uint8_t *> ( & Out ) [ 1 ] = In >> 16;
	reinterpret_cast <uint8_t *> ( & Out ) [ 2 ] = In >> 8;
	reinterpret_cast <uint8_t *> ( & Out ) [ 3 ] = In;
	
	return Out;
	
#endif
	
}

inline uint64_t BigToHostEndian64 ( const uint64_t In )
{
	
#ifdef RAUX_BIG_ENDIAN_DEFINITE
	
	return In;
	
#else
	
	const uint8_t * Bytes = reinterpret_cast <const uint8_t *> ( & In );
	
	return ( ( static_cast <uint64_t> ( Bytes [ 0 ] ) << 56 ) & 0xFF00000000000000 ) | ( ( static_cast <uint64_t> ( Bytes [ 1 ] ) << 48 ) & 0xFF000000000000 ) | ( ( static_cast <uint64_t> ( Bytes [ 2 ] ) << 40 ) & 0xFF0000000000 ) | ( ( static_cast <uint64_t> ( Bytes [ 3 ] ) << 32 ) & 0xFF00000000 ) | ( ( static_cast <uint64_t> ( Bytes [ 4 ] ) << 24 ) & 0xFF000000 ) | ( ( static_cast <uint64_t> ( Bytes [ 5 ] ) << 16 ) & 0xFF0000 ) | ( ( static_cast <uint64_t> ( Bytes [ 6 ] ) << 8 ) & 0xFF00 ) | ( static_cast <uint64_t> ( Bytes [ 7 ] ) & 0xFF );
#endif
	
}

inline float HostToLittleEndianFloat ( const float In )
{
	
	uint32_t Value = HostToLittleEndian32 ( * reinterpret_cast <const uint32_t *> ( & In ) );
	
	return * reinterpret_cast <const float *> ( & Value );
	
}

inline float HostToBigEndianFloat ( const float In )
{
	
	uint32_t Value = HostToBigEndian32 ( * reinterpret_cast <const uint32_t *> ( & In ) );
	
	return * reinterpret_cast <const float *> ( & Value );
	
}

#endif
