#ifndef RED_DATA_JSON_ENCODER_H
#define RED_DATA_JSON_ENCODER_H

#include <Red/Data/JSON/JSON.h>
#include <Red/Data/JSON/IType.h>

#include <string>

namespace Red
{
	
	namespace Data
	{
		
		namespace JSON
		{
			
			class Encoder
			{
			public:
				
				typedef uint32_t EncodeFlags;
				
				static const EncodeFlags kEncodeFlags_None = 0;
				static const EncodeFlags kEncodeFlags_Pretty = 1;
				static const EncodeFlags kEncodeFlags_TrailingCommaLists = 2;
				static const EncodeFlags kEncodeFlags_SpaceIndentation = 4;
				static const EncodeFlags kEncodeFlags_NoObjectArrayNewlines = 8;
				static const EncodeFlags kEncodeFlags_AllArrayNewlines = 16;
				static const EncodeFlags kEncodeFlags_NoRecursiveObjectNewlines = 32;
				static const EncodeFlags kEncodeFlags_AllObjectNewlines = 64;
				static const EncodeFlags kEncodeFlags_MemberNameSeperator_PrefixSpace = 128;
				static const EncodeFlags kEncodeFlags_MemberNameSeperator_SuffixSpace = 256;
				static const EncodeFlags kEncodeFlags_ArrayObjectMemberSeperateLine = 512;
				
				static const EncodeFlags kEncodeFlags_PrettyPrint = kEncodeFlags_Pretty | kEncodeFlags_TrailingCommaLists | kEncodeFlags_MemberNameSeperator_SuffixSpace | kEncodeFlags_MemberNameSeperator_PrefixSpace | kEncodeFlags_AllObjectNewlines | kEncodeFlags_ArrayObjectMemberSeperateLine;
				static const EncodeFlags kEncodeFlags_Tight = kEncodeFlags_None;
				
				Encoder ( EncodeFlags Flags = kEncodeFlags_PrettyPrint, uint32_t IndentLevel = 1, const std :: string & NewlineSequence = "\n" );
				~Encoder ();
				
				bool Encode ( IType * RootObj, std :: string & OutString, uint32_t BaseIndent = 0 );
				
			private:
				
				const std :: string NewlineSequence;
				
				EncodeFlags Flags;
				
				uint32_t IndentSize;
				
			};
			
		}
		
	}
	
}

#endif
