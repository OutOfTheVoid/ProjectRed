#ifndef RAUX_JSONFILE_H
#define RAUX_JSONFILE_H

#include <RAUX/RAUX.h>
#include <RAUX/TextFile.h>

#include <Red/Data/JSON/IType.h>
#include <Red/Data/JSON/Encoder.h>
#include <Red/Data/JSON/Decoder.h>

/*
* JSONFile: Represents a JSON file for reading or writing, maintaining a reference counted data graph for interaction.
*/

namespace RAUX
{
	
	class JSONFile
	{
	public:
		
		static const uint32_t kStatus_Success = 0;
		
		static const uint32_t kStatus_Failure_Unkown = 1;
		static const uint32_t kStatus_Failure_Permissions = 2;
		static const uint32_t kStatus_Failure_NonExistantFile = 3;
		static const uint32_t kStatus_Failure_Load = 4;
		static const uint32_t kStatus_Failure_Decode = 5;
		static const uint32_t kStatus_Failure_Encode = 6;
		
		// Creates a new JSON file with the name < Name >.
		JSONFile ( const std :: string & Path, bool Writable = false, Red::Data::JSON::Decoder :: DecodeFlags DecFlags = Red::Data::JSON::Decoder :: kDecodeFlags_AllowKeyOverwrite, Red::Data::JSON::Encoder :: EncodeFlags EncFlags = Red::Data::JSON::Encoder :: kEncodeFlags_PrettyPrint, const std :: string & NewlineSequence = "\n" );
		~JSONFile ();
		
		bool Exists () const;
		
		const std :: string & GetName () const;
		
		// Load and close a file.
		void Load ( bool ToDecode, uint32_t * Status );
		void Commit ( uint32_t * Status );
		void CloseFile ();
		
		Red::Data::JSON :: IType * Decode ( uint32_t * Status );
		void Encode ( Red::Data::JSON :: IType * Data, uint32_t * Status );
		
	private:
		
		TextFile FileInstance;
		
		std :: string JSONBuffer;
		
		Red::Data::JSON :: Decoder JSONDecoder;
		Red::Data::JSON :: Encoder JSONEncoder;
		
	};
	
};

#endif
