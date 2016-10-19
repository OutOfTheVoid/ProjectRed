#ifndef RAUX_FLACFILE_H
#define RAUX_FLACFILE_H

#include <RAUX/RAUX.h>
#include <RAUX/File.h>

#include <stdint.h>

namespace RAUX
{
	
	class FLACFile
	{
	public:
		
		FLACFile ( const std :: string & Name );
		~FLACFile ();
		
		bool Exists () const;
		
		const std :: string & GetName () const;
		
		void Load ( uint32_t * Status );
		
		Red::Audio :: AudioBufferType GetFileDataType ();
		
		uint32_t GetSampleRate ();
		uint32_t GetChannelCount ();
		
		Red::Audio :: AudioBuffer * LoadToBuffer ();
		Red::Audio :: AudioBuffer * LoadToReformattedBuffer ( Red::Audio :: AudioBufferType NewType );
		
	private:
		
		
		
		File FileInstance;
		
	};
	
}

#endif
