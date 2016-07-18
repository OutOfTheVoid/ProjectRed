#ifndef RAUX_FILE_H
#define RAUX_FILE_H

#include <RAUX/RAUX.h>

#include <stdint.h>
#include <stdio.h>

#include <string>

// File: Represents a system file and it's read/write/seek operations. Tracks the status of an open file and whether it exists or not.

namespace RAUX
{
	
	class File
	{
	public:
		
		typedef int SeekMode;
		
		static const SeekMode kSeekMode_Absolute = SEEK_SET;
		static const SeekMode kSeekMode_Relative = SEEK_CUR;
		static const SeekMode kSeekMode_FromEnd = SEEK_END;
		
		static const uint32_t kStatus_Success = 0;
		
		static const uint32_t kStatus_Failure_Unknown = 1;
		
		static const uint32_t kStatus_Failure_FileModeIncompatible = 2;
		static const uint32_t kStatus_Failure_OutOfMemory = 3;
		static const uint32_t kStatus_Failure_Permissions = 4;
		static const uint32_t kStatus_Failure_InvalidParam = 5;
		static const uint32_t kStatis_Failure_FileIsDirectory = 6;
		static const uint32_t kStatus_Failure_FileNotOpen = 7;
		static const uint32_t kStatus_Failure_FileAlreadyOpen = 8;
		static const uint32_t kStatus_Failure_IOError = 9;
		
		File ( const std :: string & Name, bool Writable = false );
		~File ();
		
		// Whether or not the file exists.
		bool Exists () const;
		
		// Open and close a file.
		void Open ( uint32_t * Status, bool Overwrite = false );
		void Close ( uint32_t * Status );
		
		// Whether or not the file is open.
		bool IsOpen () const;
		
		// Whether the file is writable or not.
		bool IsWritable () const;
		
		// Set the current read/write position in the file for sequential mode operations.
		void Seek ( uint32_t * Status, int64_t Position, SeekMode Mode = kSeekMode_Absolute );
		
		// Set whether we want to be able to write to the file.
		void SetWritable ( uint32_t * Status, bool Writable = true );
		
		// Read and write to the file sequentially.
		int64_t ReadSequential ( void * Buffer, uint64_t Length, uint32_t * Status );
		int64_t WriteSequential ( void * Buffer, uint64_t Length, uint32_t * Status );
		
		// Read and write to the file with a specific starting offset.
		int64_t Write ( void * Buffer, uint64_t Length, int64_t Offset, uint32_t * Status );
		int64_t Read ( void * Buffer, uint64_t Length, int64_t Offset, uint32_t * Status );
		
		// Flush all read/write operations.
		void Flush ( uint32_t * Status );
		
		// Get the length of the file.
		int64_t GetLength ( uint32_t * Status ) const;
		
		// Get the raw FILE pointer.
		FILE * GetFilePointer () const;
		
		// Get the file name.
		const std :: string & GetName () const;
		
	private:
		
		const std :: string Name;
		bool Writable;
		
		bool Opened;
		
		FILE * Handle;
		
	};
	
};

#endif
