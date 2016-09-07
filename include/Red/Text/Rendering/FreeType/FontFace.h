#ifndef RED_TEXT_RENDERING_FREETYPE_FONTFACE_H
#define RED_TEXT_RENDERING_FREETYPE_FONTFACE_H

#include <Red/Text/Rendering/FreeType/FreeType.h>

#ifdef RED_OPT_TEXT_RENDERING_FREETYPE

#include <ft2build.h>
#include FT_FREETYPE_H

#include <Red/Text/Rendering/IFontReference.h>

#include <Red/Util/RefCounted.h>
#include <Red/Util/RCMem.h>

#include <string>

namespace Red
{
	
	namespace Text
	{
		
		namespace Rendering
		{
			
			namespace FreeType
			{
				
				class FreeTypeFontRenderData;
				
				class FontFace : public Util :: RefCounted, public virtual IFontReference
				{
				public:
					
					typedef uint32_t StyleFlag;
					typedef uint32_t FaceFlag;
					typedef uint32_t LoadFlag;
					
					typedef FT_Pixel_Mode PixelMode;
					
					typedef FT_Render_Mode RenderMode;
					
					static const StyleFlag kStyleFlag_Italic = FT_STYLE_FLAG_ITALIC;
					static const StyleFlag kStyleFlag_Bold = FT_STYLE_FLAG_BOLD;
					
					static const FaceFlag kFaceFlag_Scalable = FT_FACE_FLAG_SCALABLE;
					static const FaceFlag kFaceFlag_FixedSizes = FT_FACE_FLAG_FIXED_SIZES;
					static const FaceFlag kFaceFlag_FixedWidth = FT_FACE_FLAG_FIXED_WIDTH;
					static const FaceFlag kFaceFlag_HorizontalMetrics = FT_FACE_FLAG_HORIZONTAL;
					static const FaceFlag kFaceFlag_VerticalMetrics = FT_FACE_FLAG_VERTICAL;
					static const FaceFlag kFaceFlag_Kerning = FT_FACE_FLAG_KERNING;
					
					static const LoadFlag kLoadFlag_Defaults = FT_LOAD_DEFAULT;
					static const LoadFlag kLoadFlag_NoScale = FT_LOAD_NO_SCALE;
					static const LoadFlag kLoadFlag_NoHinting = FT_LOAD_NO_HINTING;
					static const LoadFlag kLoadFlag_AvoidBitmaps = FT_LOAD_NO_BITMAP;
					static const LoadFlag kLoadFlag_AutoHint = FT_LOAD_FORCE_AUTOHINT;
					static const LoadFlag kLoadFlag_Pedantic = FT_LOAD_PEDANTIC;
					static const LoadFlag kLoadFlag_NoRecursion = FT_LOAD_NO_RECURSE;
					static const LoadFlag kLoadFlag_NoTransform = FT_LOAD_IGNORE_TRANSFORM;
					static const LoadFlag kLoadFlag_FontUnits = FT_LOAD_LINEAR_DESIGN;
					static const LoadFlag kLoadFlag_NoAutoHint = FT_LOAD_NO_AUTOHINT;
					static const LoadFlag kLoadFlag_LoadColor = FT_LOAD_COLOR;
					static const LoadFlag kLoadFlag_ComputeMetrics = FT_LOAD_COMPUTE_METRICS;
					
					static const PixelMode kPixelMode_Monochrome = FT_PIXEL_MODE_MONO;
					static const PixelMode kPixelMode_Gray = FT_PIXEL_MODE_GRAY;
					static const PixelMode kPixelMode_BGRA = FT_PIXEL_MODE_BGRA;
					
					static const RenderMode kRenderMode_Normal = FT_RENDER_MODE_NORMAL;
					static const RenderMode kRenderMode_Mono = FT_RENDER_MODE_MONO;
					
					typedef struct
					{
						
						uint32_t Rows;
						uint32_t Width;
						int32_t Pitch;
						
						uint32_t GrayCount;
						
						PixelMode PixMode;
						
					} BitmapMetrics;
					
					static FontFace * NewFromFile ( const std :: string & FileName, uint32_t FaceIndex, const std :: string & RefName );
					static FontFace * NewFromMemory ( Util :: RCMem * FileMemory, uint32_t FileSize, uint32_t FaceIndex, const std :: string & RefName );
					
					~FontFace ();
					
					uint32_t GetNumFaces () const;
					uint32_t GetFaceIndex () const;
					
					FaceFlag GetFaceFlags () const;
					StyleFlag GetStyleFlags () const;
					
					uint32_t GetNumGlyphs () const;
					
					const std :: string & GetFamilyName () const;
					const std :: string & GetStyleName () const;
					
					uint32_t GetFixedSizeCount () const;
					double GetFixedNominalWidth ( int32_t Index ) const;
					double GetFixedNominalHeight ( int32_t Index ) const;
					
					void SetPixelSize ( uint32_t PixelSize );
					uint32_t GetPixelSize () const;
					
					void SetRenderMode ( RenderMode RMode );
					
					uint32_t GlyphIndexFromChar ( char32_t Char ) const;
					
					bool LoadGlyph ( uint32_t Index, LoadFlag Flags );
					bool RenderGlyph ();
					
					void * GetBitmapPointer () const;
					void GetBitmapMetrics ( BitmapMetrics & Metrics ) const;
					
					void SetTransform ( double A, double B, double C, double D, double TX, double TY );
					void SetIdentityTransform ( double TX, double TY );
					
					const std :: string & GetName () const;
					
				private:
					
					friend class FreeTypeFontRenderData;
					
					FontFace ( const std :: string & RefName );
					
					FT_Face FHandle;
					bool Valid;
					
					uint32_t PixelSize;
					
					Util :: RCMem * MemFile;
					
					std :: string FamilyName;
					std :: string StyleName;
					
					RenderMode RMode;
					
					std :: string RefName;
					
					uint32_t LastLoaded;
					LoadFlag LastLoadFlags;
					
				};
				
			}
			
		}
		
	}
	
}

#endif

#endif
