#ifndef RAUX_ENDIAN_H
#define RAUX_ENDIAN_H

#include <stdint.h>

inline uint32_t LittleToHostEndian32 ( const uint32_t In )
{
	
	const uint8_t * Bytes = reinterpret_cast <const uint8_t *> ( & In );
	
	return ( Bytes [ 0 ] << 0 ) | ( Bytes [ 1 ] << 8 ) | ( Bytes [ 2 ] << 16 ) | ( Bytes [ 3 ] << 24 );
	
}

inline uint32_t BigToHostEndian32 ( const uint32_t In )
{
	
	const uint8_t * Bytes = reinterpret_cast <const uint8_t *> ( & In );
	
	return ( Bytes [ 3 ] << 0 ) | ( Bytes [ 2 ] << 8 ) | ( Bytes [ 1 ] << 16 ) | ( Bytes [ 0 ] << 24 );
	
}

inline uint16_t LittleToHostEndian16 ( const uint16_t In )
{
	
	const uint8_t * Bytes = reinterpret_cast <const uint8_t *> ( & In );
	
	return ( Bytes [ 0 ] << 0 ) | ( Bytes [ 1 ] << 8 );
	
}

inline uint16_t BigToHostEndian16 ( const uint16_t In )
{
	
	const uint8_t * Bytes = reinterpret_cast <const uint8_t *> ( & In );
	
	return ( Bytes [ 1 ] << 0 ) | ( Bytes [ 0 ] << 8 );
	
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

#endif
