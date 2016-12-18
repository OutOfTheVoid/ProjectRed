#ifndef RED_DATA_BASE64_DECODER_H
#define RED_DATA_BASE64_DECODER_H

#include <Red/Data/Base64/Base64.h>

#include <string>
#include <stdint.h>

namespace Red
{
	
	namespace Data
	{
		
		namespace Base64
		{
			
			class Decoder
			{
			public:
				
				Decoder ( char C62 = '+', char C63 = '/', char PadChar = '=' );
				~Decoder ();
				
				bool Decode ( const std :: string & B64In, void ** MemoryOut, uint32_t * MemSizeOut );
				
			private:
				
				uint32_t Lookup [ 256 ];
				
				char PadChar;
				
			};
			
		}
		
	}
	
}

#endif
