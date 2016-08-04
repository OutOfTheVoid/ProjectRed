#ifndef RAUX_FRAGMENTSHADERFILE_H
#define RAUX_FRAGMENTSHADERFILE_H

#include <RAUX/RAUX.h>
#include <RAUX/TextFile.h>

#ifdef RAUX_XENON_INTERFACE

#include <Xenon/GPU/FragmentShader.h>

namespace RAUX
{
	
	class FragmentShaderFile
	{
	public:
		
		static const uint32_t kStatus_Success = 0;
		static const uint32_t kStatus_Failure_Load = 1;
		
		FragmentShaderFile ( const std :: string & Name );
		FragmentShaderFile ( const std :: string & Name, const std :: string & ShaderName );
		~FragmentShaderFile ();
		
		bool Exists () const;
		
		const std :: string & GetName () const;
		
		void Open ( uint32_t * Status );
		void Close ();
		
		Xenon::GPU :: FragmentShader * LoadToShader ( uint32_t * Status );
		
	private:
		
		TextFile FileInstance;
		const std :: string ShaderName;
		
	};
	
}

#endif
#endif
