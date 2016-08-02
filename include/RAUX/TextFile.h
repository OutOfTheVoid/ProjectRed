#ifndef RAUX_TEXTFILE_H
#define RAUX_TEXTFILE_H

#include <RAUX/RAUX.h>
#include <RAUX/File.h>

#include <string>

#define RAUX_STACKBUFFER_SIZE 0x1000

namespace RAUX
{
	
	class TextFile
	{
	public:
		
		static const uint32_t kStatus_Success = 0;
		
		static const uint32_t kStatus_Failure_NonExistantFile = 1;
		static const uint32_t kStatus_Failure_Load = 2;
		static const uint32_t kStatus_Failure_MemoryAllocation = 3;
		static const uint32_t kStatus_Failure_FileBounds = 4;
		
		TextFile ( const std :: string & Name );
		~TextFile ();
		
		bool Exists () const;
		
		const std :: string & GetName () const;
		
		void Open ( uint32_t * Status );
		void Close ();
		
		bool IsOpen () const;
		
		void LoadToString ( uint32_t * Status, std :: string & String, uint64_t Offset, uint64_t Length = 0xFFFFFFFFFFFFFFFF, bool TrimToFileEdge = true );
		
	private:
		
		File FileInstance;
		
	};
	
}

#endif
