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
		
		// Absolute seek, seeks with reference to the beginning of the file.
		static const SeekMode kSeekMode_Absolute = SEEK_SET;
		// Relative seek, seeks with reference to the previous seek position.
		static const SeekMode kSeekMode_Relative = SEEK_CUR;
		// End seek, seeks with reference to the file end.
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
		
		// Creates a new File with the name < Name > and opens it as read-only unless < Writable > is specified.
		File ( const std :: string & Name, bool Writable = false );
		File ( const File & CopyFrom );
		~File ();
		
		// Whether or not the file exists.
		bool Exists () const;
		
		// Open and close a file, returning status in < Status >. If the file already exists and < Overwrite > is set to true, it will be overwritten.
		void Open ( uint32_t * Status, bool Overwrite = false );
		void Close ( uint32_t * Status );
		
		// Whether or not the file is open.
		bool IsOpen () const;
		
		// Whether the file is writable or not.
		bool IsWritable () const;
		
		// Set the current read/write position ( < Position > ) in the file for sequential mode operations. Status is returned through < Status >. < SeekMode > determines where the the Position is in reference to. See kSeekMode_* for more info.
		void Seek ( uint32_t * Status, int64_t Position, SeekMode Mode = kSeekMode_Absolute );
		
		// Set whether we want to be able to write to the file.
		void SetWritable ( uint32_t * Status, bool Writable = true );
		
		// Read and write to the file sequentially. < Buffer > is the read source or write sink. < Length > specifies how many bytes to read/write. Status returned in < Status>.
		int64_t ReadSequential ( void * Buffer, uint64_t Length, uint32_t * Status );
		int64_t WriteSequential ( void * Buffer, uint64_t Length, uint32_t * Status );
		
		// Read and write to the file with a specific starting offset: < Offset >. < Buffer > is the read source or write sink. < Length > specifies how many bytes to read/write. Status returned in < Status>.
		int64_t Write ( void * Buffer, uint64_t Length, int64_t Offset, uint32_t * Status );
		int64_t Read ( void * Buffer, uint64_t Length, int64_t Offset, uint32_t * Status );
		
		// Flush all read/write operations. Status returned in < Status >
		void Flush ( uint32_t * Status );
		
		// Get the length of the file. Status returned in < Status >
		int64_t GetLength ( uint32_t * Status ) const;
		
		// Get the raw FILE pointer. Returns NULL if no file pointer has been created. ( IE file not opened, or failed to open. )
		FILE * GetFilePointer () const;
		
		// Get the file name. Identical to the passed < Name > in the constructor File :: File ( const std :: string & Name, bool Writable ).
		const std :: string & GetName () const;
		
	private:
		
		// Name of the file.
		const std :: string Name;
		// Whether or not the file is writable.
		bool Writable;
		// Whether or not the file is open.
		bool Opened;
		// System file pointer.
		FILE * Handle;
		
	};
	
};

#endif
