#ifndef RED_TEXT_RENDERING_FREETYPE_LIBRARY_H
#define RED_TEXT_RENDERING_FREETYPE_LIBRARY_H

#include <Red/Text/Rendering/FreeType/FreeType.h>

#ifdef RED_OPT_TEXT_RENDERING_FREETYPE

#include <stdint.h>

#include <ft2build.h>
#include FT_FREETYPE_H

namespace Red
{
	
	namespace Text
	{
		
		namespace Rendering
		{
			
			namespace FreeType
			{
				
				class FontFace;
				
				class FTLibrary
				{
				public:
					
					static const uint32_t kStatus_Success = 0;
					static const uint32_t kStatus_Failure_LibInit = 1;
					
					static void LibInit ( uint32_t * Status );
					static void LibClose ();
					
				private:
					
					friend class FontFace;
					
					static FT_Library * GetLibrary ();
					
					static bool LibraryInitialized;
					static FT_Library LibraryHandle;
					
				};
				
			}
			
		}
		
	}
	
}

#endif

#endif
