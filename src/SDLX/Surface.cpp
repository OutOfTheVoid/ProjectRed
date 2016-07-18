#include <SDLX/Surface.h>
#include <iostream>

SDLX::Surface :: Surface ( SDL_Surface * SHandle, Mutex * MLock ):
	SHandle ( SHandle ),
	MLock ( MLock )
{
};

SDLX::Surface :: ~Surface ()
{
	
	if ( RefCount == 0 )
		SDL_FreeSurface ( SHandle );
	
};

SDLX::Surface * SDLX::Surface :: FromWindowSurface ( SDL_Surface * SHandle, Window * Source )
{
	
	Mutex * MLock = NULL;
	
	if ( Source -> GetMutex () != NULL )
	{
		
		MLock = Mutex :: Create ();
		
		if ( MLock == NULL )
			return NULL;
		
	}
	
	Surface * New = new Surface ( SHandle, MLock );
	
	New -> Own ();
	
	Source -> AddEventHook ( SDL_WINDOWEVENT_RESIZED, & WindowResizeCallback, reinterpret_cast <void *> ( New ), 0 );
	Source -> AddEventHook ( SDL_WINDOWEVENT_SIZE_CHANGED, & WindowResizeCallback, reinterpret_cast <void *> ( New ), 0 );
	
	SDL_Rect InitialSize;
	
	SDL_GetClipRect ( SHandle, & InitialSize );
	
	New -> Width = InitialSize.w;
	New -> Height = InitialSize.h;
	
	return New;
	
};

void SDLX::Surface :: WindowResizeCallback ( SDL_WindowEvent * Event, Window * Origin, void * SurfacePtr )
{
	
	reinterpret_cast <Surface *> ( SurfacePtr ) -> SHandle = SDL_GetWindowSurface ( Origin -> WHandle );
	
	reinterpret_cast <Surface *> ( SurfacePtr ) -> Width = Event -> data1;
	reinterpret_cast <Surface *> ( SurfacePtr ) -> Height = Event -> data2;
	
};

SDLX::Surface * SDLX::Surface :: NewSurface ( uint32_t Width, uint32_t Height, uint32_t Flags, uint32_t Depth, uint32_t RedMask, uint32_t GreenMask, uint32_t BlueMask, uint32_t AlphaMask )
{
	
	Mutex * MLock = NULL;
	
	if ( Flags & kNewFlags_MultiThreaded )
	{
		
		MLock = Mutex :: Create ();
		
		if ( MLock == NULL )
			return NULL;
		
	}
	
	SDL_Surface * SHandle = SDL_CreateRGBSurface ( 0, Width, Height, Depth, RedMask, GreenMask, BlueMask, AlphaMask );
	
	if ( SHandle == NULL )
	{
		
		delete MLock;
		
		return NULL;
		
	}
	
	return new Surface ( SHandle, MLock );
	
};

SDLX::Surface * SDLX::Surface :: NewSurfaceFromLoadedBMP ( const char * FileName, uint32_t Flags, const SDL_PixelFormat * Format )
{
	
	Mutex * MLock = NULL;
	
	if ( Flags & kNewFlags_MultiThreaded )
	{
		
		MLock = Mutex :: Create ();
		
		if ( MLock == NULL )
			return NULL;
		
	}
	
	SDL_Surface * SHandle = SDL_LoadBMP ( FileName );
	
	if ( SHandle == NULL )
		return NULL;
	
	if ( Format != NULL )
	{
		
		SDL_Surface * NewSHandle = SDL_ConvertSurface ( SHandle, Format, 0 );
		
		if ( NewSHandle == NULL )
			return NULL;
		
		if ( NewSHandle != SHandle )
		{
			
			SDL_FreeSurface ( SHandle );
			
			SHandle = NewSHandle;
			
		}
		
	}
	
	Surface * New = new Surface ( SHandle, MLock );
	
	SDL_Rect ImageSize;
	
	SDL_GetClipRect ( SHandle, & ImageSize );
	
	New -> Width = ImageSize.w;
	New -> Height = ImageSize.h;
	
	return New;
	
};

void SDLX::Surface :: SetClipRect ( int32_t X, int32_t Y, uint32_t Width, uint32_t Height )
{
	
	const SDL_Rect NewClipRect { x : static_cast <int> ( X ), y : static_cast <int> ( Y ), w : static_cast <int> ( Width ), h : static_cast <int> ( Height ) };
	
	SDL_SetClipRect ( SHandle, & NewClipRect );
	
};

void SDLX::Surface :: GetClipRect ( int32_t & X, int32_t & Y, uint32_t & Width, uint32_t & Height )
{
	
	SDL_Rect Temp;
	
	SDL_GetClipRect ( SHandle, & Temp );
	
	X = static_cast <int32_t> ( Temp.x );
	Y = static_cast <int32_t> ( Temp.y );
	Width = static_cast <int32_t> ( Temp.w );
	Height = static_cast <int32_t> ( Temp.h );
	
};

void SDLX::Surface :: ResetClipRect ()
{
	
	const SDL_Rect NewClipRect { x : 0, y : 0, w : static_cast <int> ( GetWidth () ), h : static_cast <int> ( GetHeight () ) };
	
	SDL_SetClipRect ( SHandle, & NewClipRect );
	
};


void SDLX::Surface :: SetBlendMode ( BlendMode Mode )
{
	
	SDL_SetSurfaceBlendMode ( SHandle, static_cast <SDL_BlendMode> ( Mode ) );
	
};

SDLX::Surface :: BlendMode SDLX::Surface :: GetBlendMode ()
{
	
	BlendMode Mode;
	
	SDL_GetSurfaceBlendMode ( SHandle, reinterpret_cast <SDL_BlendMode *> ( & Mode ) );
	
	return Mode;
	
};

void SDLX::Surface :: BlitFull ( Surface * Source, int32_t X, int32_t Y )
{
	
	SDL_Rect DestRect { x : static_cast <int> ( X ), y : static_cast <int> ( Y ), w : static_cast <int> ( Source -> GetWidth () ), h : static_cast <int> ( Source -> GetHeight () ) };
	
	SDL_BlitSurface ( Source -> SHandle, NULL, SHandle, & DestRect );
	
};

void SDLX::Surface :: BlitRect ( Surface * Source, int32_t X, int32_t Y, uint32_t Width, uint32_t Height )
{
	
	SDL_Rect DestRect { x : static_cast <int> ( X ), y : static_cast <int> ( Y ), w : static_cast <int> ( Width ), h : static_cast <int> ( Height ) };
	SDL_Rect SourceRect { x : 0, y : 0, w : static_cast <int> ( Width ), h : static_cast <int> ( Height ) };
	
	SDL_BlitSurface ( Source -> SHandle, & SourceRect, SHandle, & DestRect );
	
};

void SDLX::Surface :: Fill ( uint32_t Color )
{
	
	SDL_Rect DestRect { x : 0, y : 0, w : static_cast <int> ( GetWidth () ), h : static_cast <int> ( GetHeight () ) };
	
	SDL_FillRect ( SHandle, & DestRect, Color );
	
};

void SDLX::Surface :: FillRect ( uint32_t Color, int32_t X, int32_t Y, uint32_t Width, uint32_t Height )
{
	
	SDL_Rect DestRect { x : static_cast <int> ( X ), y : static_cast <int> ( Y ), w : static_cast <int> ( Width ), h : static_cast <int> ( Height ) };
	
	SDL_FillRect ( SHandle, & DestRect, Color );
	
};

void SDLX::Surface :: Lock ()
{
	
	SDL_LockSurface ( SHandle );
	
};

void SDLX::Surface :: Unlock ()
{
	
	SDL_UnlockSurface ( SHandle );
	
};

SDL_Surface * SDLX::Surface :: GetSDLHandle ()
{
	
	return SHandle;
	
};

void * SDLX::Surface :: GetPixelData ()
{
	
	return SHandle -> pixels;
	
};

const SDL_PixelFormat * SDLX::Surface :: GetPixelFormat ()
{
	
	return SHandle -> format;
	
};

uint32_t SDLX::Surface :: GetWidth ()
{
	
	return static_cast <uint32_t> ( SHandle -> w );
	
};

uint32_t SDLX::Surface :: GetHeight ()
{
	
	return static_cast <uint32_t> ( SHandle -> h );
	
};
