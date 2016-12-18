#include <iostream>

#include <SDLX/Lib.h>
#include <SDLX/Window.h>

#include <Red/Util/Closure.h>
#include <Red/Util/Function.h>
#include <Red/Util/Time.h>
#include <Red/Util/RefCounted.h>

#include <Red/Behaviors/BehaviorController.h>
#include <Red/Behaviors/DebugBehavior.h>

#include <Red/Save/JSONSaveFile.h>
#include <Red/Save/ISavable.h>
#include <Red/Save/ContainerSaveObject.h>
#include <Red/Save/Int32SaveObject.h>

#include <RAUX/JSONFile.h>

#include <Red/Data/Base64/Encoder.h>
#include <Red/Data/Base64/Decoder.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void WindowCloseEvent ( SDL_WindowEvent * Event, SDLX::Window * Win, void * Data );

class TestSavable : public virtual Red::Save :: ISavable, public Red::Util :: RefCounted
{
public:
	
	TestSavable ():
		RefCounted ( 0 ),
		RootObj ( new Red::Save :: ContainerSaveObject ( "Root" ) ),
		IntSave ( new Red::Save :: Int32SaveObject ( "MyInt" ) ),
		IntValue ( 0 )
	{
		
		RootObj -> Reference ();
		IntSave -> Reference ();
		RootObj -> AddChild ( IntSave );
		
	};
	
	~TestSavable ()
	{
		
		RootObj -> Dereference ();
		IntSave -> Dereference ();
		
	}
	
	Red::Save :: ISaveObject * GetRootSaveObject ()
	{
		
		return dynamic_cast <Red::Save :: ISaveObject *> ( RootObj );
		
	};
	
	void NotifySaveAction ( SaveAction Action )
	{
		
		switch ( Action )
		{
			
			case Red::Save::ISavable :: kSaveAction_Restore_Success:
				IntValue = IntSave -> GetState ();
				break;
				
			case Red::Save::ISavable :: kSaveAction_Save_Prepare:
				IntSave -> SetState ( IntValue );
				break;
			
		}
		
	};
	
	void SetIntValue ( int32_t Value )
	{
		
		IntValue = Value;
		
	};
	
	int32_t GetIntValue ()
	{
		
		return IntValue;
		
	}
	
private:
	
	Red::Save :: ContainerSaveObject * RootObj;
	Red::Save :: Int32SaveObject * IntSave;
	
	int32_t IntValue;
	
};

int main ( int argc, char const * argv [] )
{
	
	( void ) argc;
	( void ) argv;
	
	uint32_t Status;
	
	SDLX::Lib :: Init ( & Status, SDLX::Lib :: kSDLFlag_Video );
	
	if ( Status != SDLX :: kStatus_Success )
		return - 1;
	
	SDLX::Window * Win = SDLX::Window :: Create ( & Status, "Test", WINDOW_WIDTH, WINDOW_HEIGHT, SDLX::Window :: kCreateFlag_Shown | SDLX::Window :: kCreateFlag_HighDPI );
	
	if ( Status != SDLX::Window :: kStatus_Success )
	{
		
		SDLX::Lib :: DeInit ();
		
		return - 2;
		
	}
	
	Win -> Own ();
	Win -> AddEventHook ( SDLX::Window :: kWindowEventID_Closed, & WindowCloseEvent, NULL );
	
	TestSavable SaveData;
	SaveData.Reference ();
	
	Red::Save :: JSONSaveFile SaveFile ( "TestSave.json" );
	SaveFile.SetSaveObject ( & SaveData );
	SaveFile.Open ( false );
	
	SaveData.SetIntValue ( 1000 );
	
	SaveFile.RunSave ();
	
	Red::Data::Base64 :: Encoder B64Encoder;
	Red::Data::Base64 :: Decoder B64Decoder;
	
	const char * TestData = "Hello World!";
	std :: string B64Out;
	
	std :: cout << "B64 Original: " << TestData << std :: endl;
	
	B64Encoder.Encode ( reinterpret_cast <const void *> ( TestData ), 12, B64Out );
	
	std :: cout << "B64 Encode: " << B64Out << std :: endl;
	
	void * MemOut = NULL;
	uint32_t CharCount;
	
	if ( B64Decoder.Decode ( B64Out, & MemOut, & CharCount ) )
	{
		
		std :: string B64OutString ( reinterpret_cast <const char *> ( MemOut ), CharCount );
		
		std :: cout << "B64 Decode: " << B64OutString << std :: endl;
		
	}
	
	/*================================*/
	
	SDLX::Lib :: EventLoop ( & Status ); // GAME LOOP
	
	/*================================*/
	 
	Win -> Disown ();
	
	SDLX::Lib :: DeInit ();
	
	return 0;

}

void WindowCloseEvent ( SDL_WindowEvent * Event, SDLX::Window * Win, void * Data )
{
	
	uint32_t Status;
	
	( void ) Event;
	( void ) Data;
	
	Win -> Close ( & Status );
	
}
