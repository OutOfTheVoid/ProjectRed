#include <Red/Data/Base64/Decoder.h>

#include <iostream>

Red::Data::Base64::Decoder :: Decoder ( char C62, char C63, char PadChar ):
	PadChar ( PadChar )
{
	
	for ( uint32_t I = 0; I < 256; I ++ )
		Lookup [ I ] = 0;
	
	for ( uint32_t I = 0; I < 26; I ++ )
	{
	
		Lookup [ static_cast <uint32_t> ( 'A' ) + I ] = I;
		Lookup [ static_cast <uint32_t> ( 'a' ) + I ] = I + 26;
		
	}
	
	for ( uint32_t I = 0; I < 10; I ++ )
		Lookup [ static_cast <uint32_t> ( '0' ) + I ] = 52 + I;
	
	Lookup [ static_cast <uint32_t> ( C62 ) ] = 62;
	Lookup [ static_cast <uint32_t> ( C63 ) ] = 63;
	
}

Red::Data::Base64::Decoder :: ~Decoder ()
{
}

bool Red::Data::Base64::Decoder :: Decode ( const std :: string & B64In, void ** MemoryOut, uint64_t * MemSizeOut )
{
	
	if ( ( B64In.size () % 4 ) != 0 )
	{
		
		* MemoryOut = NULL;
		* MemSizeOut = 0;
		
		return false;
		
	}
	
	uint64_t PadCount = 0;
	
	if ( B64In.at ( B64In.size () - 1 ) == PadChar )
		PadCount ++;
	
	if ( B64In.at ( B64In.size () - 2 ) == PadChar )
		PadCount ++;
	
	uint64_t MemSize = ( ( B64In.size () / 4 ) * 3 ) - PadCount;
	uint64_t RunCount = MemSize / 3;
	
	if ( PadCount == 1 )
		PadCount = 2;
	else if ( PadCount == 2 )
		PadCount = 1;
	
	std :: cout << "PadCount: " << PadCount << std :: endl;
	
	* MemoryOut = malloc ( MemSize );
	
	if ( * MemoryOut == NULL )
	{
		
		* MemSizeOut = 0;
		
		return false;
		
	}
	
	* MemSizeOut = MemSize;
	
	std :: cout << "MemSize: " << MemSize << std :: endl;
	
	for ( uint64_t I = 0; I < RunCount; I ++ )
	{
		
		uint32_t MiniSection = ( Lookup [ B64In.at ( ( I * 4 ) + 3 ) ] << 0 ) | ( Lookup [ B64In.at ( ( I * 4 ) + 2 ) ] << 6 ) | ( Lookup [ B64In.at ( ( I * 4 ) + 1 ) ] << 12 ) | ( Lookup [ B64In.at ( ( I * 4 ) + 0 ) ] << 18 );
		
		reinterpret_cast <uint8_t *> ( * MemoryOut ) [ 3 * I + 0 ] = ( MiniSection >> 16 ) & 0xFF;
		reinterpret_cast <uint8_t *> ( * MemoryOut ) [ 3 * I + 1 ] = ( MiniSection >> 8 ) & 0xFF;
		reinterpret_cast <uint8_t *> ( * MemoryOut ) [ 3 * I + 2 ] = ( MiniSection >> 0 ) & 0xFF;
		
	}
	
	switch ( PadCount )
	{
		
		case 2:
		{
			
			uint32_t MiniSection = ( Lookup [ B64In.at ( RunCount * 4 + 2 ) ] << 6 ) | ( Lookup [ B64In.at ( RunCount * 4 + 1 ) ] << 12 ) | ( Lookup [ B64In.at ( RunCount * 4 + 0 ) ] << 18 );
			
			reinterpret_cast <uint8_t *> ( * MemoryOut ) [ 3 * RunCount + 0 ] = ( MiniSection >> 16 ) & 0xFF;
			reinterpret_cast <uint8_t *> ( * MemoryOut ) [ 3 * RunCount + 1 ] = ( MiniSection >> 8 ) & 0xFF;
			
		}
		break;
		
		case 1:
		{
			
			uint32_t MiniSection = ( Lookup [ B64In.at ( RunCount * 4 + 1 ) ] << 12 ) | ( Lookup [ B64In.at ( RunCount * 4 + 0 ) ] << 18 );
			
			reinterpret_cast <uint8_t *> ( * MemoryOut ) [ 3 * RunCount + 0 ] = ( MiniSection >> 16 ) & 0xFF;
			
		}
		break;
		
	}
	
	return true;
	
}
