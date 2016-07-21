#ifndef SDLX_KEYBOARD_H
#define SDLX_KEYBOARD_H

#include <SDLX/SDLX.h>
#include <SDLX/Mutex.h>

#include <SDL2/SDL.h>

#include <vector>
#include <algorithm>

// Keyboard: Represents the machine keyboard.

namespace SDLX
{
	
	class Keyboard
	{
	public:

		
		static bool GetKeyState ( int32_t Key );
		static bool GetScanState ( int32_t ScanCode );
		
		static void AddKeyListener ( void ( * Listener ) ( int32_t ScanCode, int32_t KeyCode, bool Down, void * Data ), void * Data );
		static void RemoveKeyListener ( void ( * Listener ) ( int32_t ScanCode, int32_t KeyCode, bool Down, void * Data ) );
		
		static const char * GetKeyName ( int32_t Key );
		static const char * GetScanName ( int32_t ScanCode );
		
	private:
		
		static void Init ();
		
		friend class Lib;
		
		typedef struct
		{
			
			void ( * Listener ) ( int32_t ScanCode, int32_t KeyCode, bool Down, void * Data );
			void * Data;
			
		} ListenerStruct;
		
		class ListenerCompare : public std :: unary_function <ListenerStruct, bool>
		{
		public:
			
			ListenerCompare ( void ( * Listener ) ( int32_t ScanCode, int32_t KeyCode, bool Down, void * Data ) ):
				Listener ( Listener )
			{
			};
			
			bool operator() ( const ListenerStruct & MatchTest )
			{
				
				return MatchTest.Listener == Listener;
				
			};
			
		private:
			
			void ( * Listener ) ( int32_t ScanCode, int32_t KeyCode, bool Down, void * Data );
			
		};
		
		static const uint8_t * KeyArray;
		static int32_t KeyCount;
		
		static void EventInternal ( SDL_KeyboardEvent * Event );
		
		static std :: vector <ListenerStruct> Listeners;
		static Mutex * ListenerLock;
		
	};
	
}

#endif
