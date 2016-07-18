#ifndef SDLX_SURFACE_H
#define SDLX_SURFACE_H

#include <SDLX/SDLX.h>
#include <SDLX/RefCounted.h>
#include <SDLX/Mutex.h>
#include <SDLX/Window.h>

namespace SDLX
{

	class Surface : public RefCounted
	{
	public:
		
		typedef SDL_BlendMode BlendMode;
		
		static const BlendMode kBlendMode_None = SDL_BLENDMODE_NONE;
		static const BlendMode kBlendMode_Blend = SDL_BLENDMODE_BLEND;
		static const BlendMode kBlendMode_Add = SDL_BLENDMODE_ADD;
		static const BlendMode kBlendMode_Modulate = SDL_BLENDMODE_MOD;
		
		static const uint32_t kNewFlags_None = 0;
		static const uint32_t kNewFlags_MultiThreaded = 1;
		
		static Surface * NewSurface ( uint32_t Width, uint32_t Height, uint32_t Flags = kNewFlags_None, uint32_t Depth = 32, uint32_t RedMask = 0xFF000000, uint32_t GreenMask = 0x00FF0000, uint32_t BlueMask = 0x0000FF00, uint32_t AlphaMask = 0x000000FF );
		static Surface * NewSurfaceFromLoadedBMP ( const char * FileName, uint32_t Flags = kNewFlags_None, const SDL_PixelFormat * Format = NULL );
		
		~Surface ();
		
		void SetClipRect ( int32_t X, int32_t Y, uint32_t Width, uint32_t Height );
		void GetClipRect ( int32_t & X, int32_t & Y, uint32_t & Width, uint32_t & Height );
		void ResetClipRect ();
		
		void BlitFull ( Surface * Source, int32_t X, int32_t Y );
		void BlitRect ( Surface * Source, int32_t X, int32_t Y, uint32_t Width, uint32_t Height );
		
		void Fill ( uint32_t Color );
		void FillRect ( uint32_t Color, int32_t X, int32_t Y, uint32_t Width, uint32_t Height );
		
		void Lock ();
		void Unlock ();
		
		Mutex & GetMutex ();
		
		void * GetPixelData ();
		
		const SDL_PixelFormat * GetPixelFormat ();
		
		SDL_Surface * GetSDLHandle ();
		
		uint32_t GetWidth ();
		uint32_t GetHeight ();
		
		void SetBlendMode ( BlendMode Mode );
		BlendMode GetBlendMode ();
		
	private:
		
		friend class Window;
		friend class Renderer;
		
		SDL_Surface * SHandle;
		
		Mutex * MLock;
		
		uint32_t Width;
		uint32_t Height;
		
		static Surface * FromWindowSurface ( SDL_Surface * SHandle, Window * Source );
		
		static void WindowResizeCallback ( SDL_WindowEvent * Event, Window * Origin, void * SurfacePtr );
		
		Surface ( SDL_Surface * SHandle, Mutex * MLock );
		
	};

};

#endif
