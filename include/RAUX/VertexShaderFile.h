#ifndef RAUX_VERTEXSHADERFILE_H
#define RAUX_VERTEXSHADERFILE_H

#include <RAUX/RAUX.h>
#include <RAUX/TextFile.h>

#ifdef RAUX_XENON_INTERFACE

#include <Xenon/GPU/VertexShader.h>

namespace RAUX
{
	
	class VertexShaderFile
	{
	public:
		
		static const uint32_t kStatus_Success = 0;
		static const uint32_t kStatus_Failure_Load = 1;
		
		VertexShaderFile ( const std :: string & Name );
		VertexShaderFile ( const std :: string & Name, const std :: string & ShaderName );
		~VertexShaderFile ();
		
		bool Exists () const;
		
		const std :: string & GetName () const;
		
		void Open ( uint32_t * Status );
		void Close ();
		
		Xenon::GPU :: VertexShader * LoadToShader ( uint32_t * Status );
		
	private:
		
		TextFile FileInstance;
		const std :: string ShaderName;
		
	};
	
}

#endif
#endif
