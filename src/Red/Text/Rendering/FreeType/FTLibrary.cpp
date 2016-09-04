#include <Red/Text/Rendering/FreeType/FTLibrary.h>

#ifdef RED_OPT_TEXT_RENDERING_FREETYPE

bool Red::Text::Rendering::FreeType::FTLibrary :: LibraryInitialized = false;
FT_Library Red::Text::Rendering::FreeType::FTLibrary :: LibraryHandle;

void Red::Text::Rendering::FreeType::FTLibrary :: LibInit ( uint32_t * Status )
{
	
	if ( LibraryInitialized )
	{
		
		* Status = kStatus_Success;
		
		return;
		
	}
	
	if ( FT_Init_FreeType ( & LibraryHandle ) == 0 )
	{
		
		* Status = kStatus_Success;
		
		LibraryInitialized = true;
		
		return;
		
	}
	
	* Status = kStatus_Failure_LibInit;
	
}

void Red::Text::Rendering::FreeType::FTLibrary :: LibClose ()
{
	
	if ( ! LibraryInitialized )
		return;
	
	FT_Done_FreeType ( LibraryHandle );
	
	LibraryInitialized = false;
	
}

FT_Library * Red::Text::Rendering::FreeType::FTLibrary :: GetLibrary ()
{
	
	uint32_t Status;
	
	LibInit ( & Status );
	
	if ( Status == kStatus_Success )
		return & LibraryHandle;
	
	return NULL;
	
}

#endif
