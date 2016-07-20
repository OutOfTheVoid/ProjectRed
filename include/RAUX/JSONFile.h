#ifndef RAUX_JSONFILE_H
#define RAUX_JSONFILE_H

#include <RAUX/RAUX.h>
#include <RAUX/TextFile.h>

/*
* JSONFile: Represents a JSON file for reading or writing, maintaining a reference counted data graph for interaction.
*/

namespace RAUX
{
	
	class JsonFile
	{
	public:
		
		// Creates a new JSON file with the name < Name >.
		JsonFile ( const std :: string & Path );
		
		~JsonFile ();
		
		
	private:
		
		TextFile FileInstance;
		
	};
	
};

#endif
