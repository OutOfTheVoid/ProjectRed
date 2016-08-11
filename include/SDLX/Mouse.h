#ifndef SDLX_MOUSE_H
#define SDLX_MOUSE_H

#include <SDLX/SDLX.h>
#include <SDLX/Mutex.h>

#include <vector>
#include <algorithm>

namespace SDLX
{
	
	class Lib;
	class Window;
	
	class Mouse
	{
	public:
		
		static void Lock ();
		static void Unlock ();
		
		static bool IsLocked ();
		
		static void AddMotionListener ( void ( * Listener ) ( SDL_MouseMotionEvent * Event, void * Data ), void * Data );
		static void RemoveMotionListener ( void ( * Listener ) ( SDL_MouseMotionEvent * Event, void * Data ) );
		
		static void AddButtonListener ( void ( * Listener ) ( SDL_MouseButtonEvent * Event, void * Data ), void * Data );
		static void RemoveButtonListener ( void ( * Listener ) ( SDL_MouseButtonEvent * Event, void * Data ) );
		
		static void InjectMouseMotionEvent ( int32_t X, int32_t Y, int32_t DX, int32_t DY, uint32_t TimeStamp = 0, Window * Source = NULL, uint32_t ButtonState = 0, bool Touch = false );
		static void InjectButtonEvent ( SDL_MouseButtonEvent * Event );
		
	private:
		
		friend class Lib;
		
		typedef struct
		{
			
			void ( * Listener ) ( SDL_MouseButtonEvent * Event, void * Data );
			void * Data;
			
		} ButtonListenerStruct;
		
		typedef struct
		{
			
			void ( * Listener ) ( SDL_MouseMotionEvent * Event, void * Data );
			void * Data;
			
		} MotionListenerStruct;
		
		static void Init ();
		static void DeInit ();
		
		static void ButtonEventInternal ( SDL_MouseButtonEvent * Event );
		static void MotionEventInternal ( SDL_MouseMotionEvent * Event );
		
		class ButtonListenerCompare : public std :: unary_function <ButtonListenerStruct, bool>
		{
		public:
			
			ButtonListenerCompare ( void ( * Listener ) ( SDL_MouseButtonEvent * Event, void * Data ) ):
				Listener ( Listener )
			{
			};
			
			bool operator() ( const ButtonListenerStruct & MatchTest )
			{
				
				return MatchTest.Listener == Listener;
				
			};
			
		private:
			
			void ( * Listener ) ( SDL_MouseButtonEvent * Event, void * Data );
			
		};
		
		class MotionListenerCompare : public std :: unary_function <MotionListenerStruct, bool>
		{
		public:
			
			MotionListenerCompare ( void ( * Listener ) ( SDL_MouseMotionEvent * Event, void * Data ) ):
				Listener ( Listener )
			{
			};
			
			bool operator() ( const MotionListenerStruct & MatchTest )
			{
				
				return MatchTest.Listener == Listener;
				
			};
			
		private:
			
			void ( * Listener ) ( SDL_MouseMotionEvent * Event, void * Data );
			
		};
		
		static std :: vector <MotionListenerStruct> MotionListeners;
		static Mutex * MotionListenerLock;
		
		static std :: vector <ButtonListenerStruct> ButtonListeners;
		static Mutex * ButtonListenerLock;
		
		static bool ButtonStates [ 32 ];
		
		static bool Locked;
		
	};
	
}

#endif
