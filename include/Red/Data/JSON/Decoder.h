#ifndef RED_DATA_JSON_DECODER_H
#define RED_DATA_JSON_DECODER_H

#include <Red/Data/JSON/JSON.h>
#include <Red/Data/JSON/IType.h>

#include <string>
#include <vector>

namespace Red
{
	
	namespace Data
	{
		
		namespace JSON
		{
			
			class Boolean;
			class Number;
			class String;
			class Object;
			class Array;
			
			class Decoder
			{
			public:
				
				typedef uint32_t DecodeFlags;
				
				static const DecodeFlags kDecodeFlags_None = 0;
				static const DecodeFlags kDecodeFlags_KeepOnError = 1;
				static const DecodeFlags kDecodeFlags_AllowKeyOverwrite = 2;
				
				Decoder ( DecodeFlags Flags = kDecodeFlags_None );
				~Decoder ();
				
				IType * Decode ( const std :: string & StringData, uint32_t StartOffset = 0, uint32_t Length = 0xFFFFFFFF );
				
			private:
				
				typedef struct
				{
					
					const std :: string * Text;
					
					uint32_t TextSize;
					uint32_t TextOffset;
					
					IType * RootObject;
					
					std :: vector <IType *> * ObjectStack;
					
					bool Error;
					
				} DecodeInfo;
				
				void SkipWhitespace ( DecodeInfo & Info );
				void DecodeSubObject ( DecodeInfo & Info );
				
				void ReadbackString ( DecodeInfo & Info, std :: string & OutString );
				
				DecodeFlags Flags;
				
			};
			
		}
		
	}
	
}

#endif
