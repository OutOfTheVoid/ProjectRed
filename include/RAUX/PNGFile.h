#ifndef RAUX_PNG_H
#define RAUX_PNG_H

#include <RAUX/RAUX.h>
#include <RAUX/File.h>
#include <stdint.h>

// PNGFile: Represents a PNG type file, offering the ability to read the data to a raw bitmap. Implemented using libpng.

namespace RAUX
{
	
	class PNGFile
	{
	public:
		
		static const uint32_t kStatus_Success = 0;
		
		static const uint32_t kStatus_Failure_NonExistantFile = 1;
		static const uint32_t kStatus_Failure_Init = 2;
		static const uint32_t kStatus_Failure_Load = 3;
		static const uint32_t kStatus_Failure_FileType = 4;
		static const uint32_t kStatus_Failure_Decode = 5;
		static const uint32_t kStatus_Failure_Memory = 6;
		
		PNGFile ( const std :: string & Path );
		~PNGFile ();
		
		// Whether or not the file exists.
		bool Exists () const;
		
		// Load and close a file.
		void Load ( uint32_t * Status );
		void CloseFile ();
		
		// Whether or not the file was a valid PNG.
		bool Valid () const;
		
		// Get the raw bitmap pointer.
		const void * GetBitmapData () const;
		
		// Test if the file has an alpha channel or not.
		bool HasAlpha () const;
		
		// Get the image dimensions.
		uint32_t GetWidth () const;
		uint32_t GetHeight () const;
		
	private:
		
		File FileInstance;
		
		void * Data;
		
		uint32_t Width;
		uint32_t Height;
		
		bool Alpha;
		
	};
	
};

#endif
