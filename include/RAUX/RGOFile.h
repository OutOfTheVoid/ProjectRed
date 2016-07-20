#ifndef RAUX_RGOFILE_H
#define RAUX_RGOFILE_H

#include <RAUX/RAUX.h>

#ifdef RAUX_XENON_INTERFACE

#include <RAUX/File.h>

namespace RAUX
{
	
	class RGOFile
	{
	public:
		
		RGOFile ( const std :: string & Name );
		~RGOFile ();
		
		bool Exists () const;
		
		
	private:
		
		File FileInstance;
		
	};
	
};

#endif

#endif
