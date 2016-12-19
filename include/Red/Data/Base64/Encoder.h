#ifndef RED_DATA_BASE64_ENCODE_H
#define RED_DATA_BASE64_ENCODE_H

#include <Red/Data/Base64/Base64.h>

#include <string>
#include <stdint.h>

namespace Red
{
	
	namespace Data
	{
		
		namespace Base64
		{
			
			class Encoder
			{
			public:
				
				typedef uint32_t EncodeFlags;
				
				static const EncodeFlags kEncodeFlags_None = 0;
				
				Encoder ( EncodeFlags Flags = kEncodeFlags_None, char C62 = '+', char C63 = '/', char PadChar = '=' );
				~Encoder ();
				
				bool Encode ( const void * SourceData, uint64_t Size, std :: string & B64Out );
				
			private:
				
				EncodeFlags Flags;
				
				char Lookup [ 64 ];
				
				char PadChar;
				
			};
			
		}
		
	}
	
}

#endif
