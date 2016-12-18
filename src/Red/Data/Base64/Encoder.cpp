#include <Red/Data/Base64/Encoder.h>

Red::Data::Base64::Encoder :: Encoder ( EncodeFlags Flags, char C62, char C63, char PadChar ):
	Flags ( Flags ),
	PadChar ( PadChar )
{
	
	for ( uint32_t I = 0; I < 26; I ++ )
	{
		
		Lookup [ I ] = static_cast <char> ( 'A' + I );
		Lookup [ I + 26 ] = static_cast <char> ( 'a' + I );
		
	}
	
	for ( uint32_t I = 0; I < 10; I ++ )
		Lookup [ I + 52 ] = static_cast <char> ( '0' + I );
	
	Lookup [ 62 ] = C62;
	Lookup [ 63 ] = C63;
	
}

Red::Data::Base64::Encoder :: ~Encoder ()
{
}

bool Red::Data::Base64::Encoder :: Encode ( const void * SourceData, uint32_t Size, std :: string & B64Out )
{
	
	uint32_t PadCount = Size % 3;
	uint32_t ModSize = ( Size / 3 );
	
	B64Out.clear ();
	
	for ( uint32_t I = 0; I < ModSize; I ++ )
	{
		
		char MiniString [ 5 ];
		
		uint32_t MiniSection = static_cast <uint32_t> ( reinterpret_cast <const uint8_t *> ( SourceData ) [ I * 3 + 2 ] ) | ( static_cast <uint32_t> ( reinterpret_cast <const uint8_t *> ( SourceData ) [ I * 3 + 1 ] ) << 8 ) | ( static_cast <uint32_t> ( reinterpret_cast <const uint8_t *> ( SourceData ) [ I * 3 + 0 ] ) << 16 );
		
		MiniString [ 0 ] = Lookup [ ( MiniSection >> 18 ) & 0x3F ];
		MiniString [ 1 ] = Lookup [ ( MiniSection >> 12 ) & 0x3F ];
		MiniString [ 2 ] = Lookup [ ( MiniSection >> 6 ) & 0x3F ];
		MiniString [ 3 ] = Lookup [ ( MiniSection >> 0 ) & 0x3F ];
		MiniString [ 4 ] = '\0';
		
		B64Out += reinterpret_cast <const char *> ( MiniString );
		
	}
	
	switch ( PadCount )
	{
		
		case 2:
		{
			
			char MiniString [ 4 ];
			uint32_t MiniSection = ( static_cast <uint32_t> ( reinterpret_cast <const uint8_t *> ( SourceData ) [ ModSize * 3 + 1 ] ) << 8 ) | ( static_cast <uint32_t> ( reinterpret_cast <const uint8_t *> ( SourceData ) [ ModSize * 3 + 0 ] ) << 16 );
			
			MiniString [ 0 ] = Lookup [ ( MiniSection >> 18 ) & 0x3F ];
			MiniString [ 1 ] = Lookup [ ( MiniSection >> 12 ) & 0x3F ];
			MiniString [ 2 ] = Lookup [ ( MiniSection >> 6 ) & 0x3F ];
			MiniString [ 3 ] = '\0';
			
			B64Out += reinterpret_cast <const char *> ( MiniString );
			B64Out += PadChar;
			
		}
		break;
		
		case 1:
		{
			
			char MiniString [ 3 ];
			uint32_t MiniSection = static_cast <uint32_t> ( reinterpret_cast <const uint8_t *> ( SourceData ) [ ModSize * 3 + 0 ] ) << 16;
			
			MiniString [ 0 ] = Lookup [ ( MiniSection >> 18 ) & 0x3F ];
			MiniString [ 1 ] = Lookup [ ( MiniSection >> 12 ) & 0x3F ];
			MiniString [ 2 ] = '\0';
			
			B64Out += reinterpret_cast <const char *> ( MiniString );
			B64Out += PadChar;
			B64Out += PadChar;
			
		}
		break;
		
		default:
			break;
		
	}
		
	return true;
	
}