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
#include <Red/Save/BinarySaveObject.h>

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
		BinSave ( new Red::Save :: BinarySaveObject ( "MyBin" ) ),
		IntValue ( 0 )
	{
		
		RootObj -> Reference ();
		IntSave -> Reference ();
		BinSave -> Reference ();
		
		BinSave -> SetData_AutoLock ( new Red::Util :: RCMem ( const_cast <void *> ( reinterpret_cast <const void *> ( "Hello world!" ) ), NULL ), 12 );
		
		RootObj -> AddChild ( IntSave );
		RootObj -> AddChild ( BinSave );
		
	};
	
	~TestSavable ()
	{
		
		RootObj -> Dereference ();
		IntSave -> Dereference ();
		BinSave -> Dereference ();
		
	}
	
	Red::Save :: ContainerSaveObject * GetRootSaveObject ()
	{
		
		return RootObj;
		
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
				
			default:
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
	Red::Save :: BinarySaveObject * BinSave;
	
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
	SaveFile.Open ( true );
	
	SaveData.SetIntValue ( 1000 );
	
	SaveFile.RunSave ();
	
	std :: cout << "IntVal: " << SaveData.GetIntValue () << std :: endl;
	
	SaveData.SetIntValue ( 400 );
	
	std :: cout << "IntVal: " << SaveData.GetIntValue () << std :: endl;
	
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
