#include <iostream>

#include <SDLX/Lib.h>
#include <SDLX/Window.h>

#include <Red/Util/Closure.h>
#include <Red/Util/Function.h>
#include <Red/Util/Time.h>

#include <Red/Behaviors/BehaviorController.h>
#include <Red/Behaviors/DebugBehavior.h>

#include <Red/Data/JSON/Decoder.h>
#include <Red/Data/JSON/IType.h>
#include <Red/Data/JSON/Object.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void WindowCloseEvent ( SDL_WindowEvent * Event, SDLX::Window * Win, void * Data );

const char * TestJSON =
"{\n"
"    \"MyBoolValue\" : false,\n"
"    \"MyStringValue\" : \"Hello world!\",\n"
"    \"MyNumberValue\" : -6.7,\n"
"    \"MyNullValue\" : null,\n"
"    \"MyArrayValue\" : [ 1, 2, 3, 4 ],\n"
"    \"MyObjectValue\" : { \"MyStringValueSub\" : \"!!!\"\n }\n"
"}";

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
	
	Red::Data::JSON :: Decoder JSONDecoder ( Red::Data::JSON::Decoder :: kDecodeFlags_AllowKeyOverwrite );
	
	Red::Data::JSON :: IType * JSONRoot = JSONDecoder.Decode ( std :: string ( TestJSON ) );
	
	if ( JSONRoot != NULL )
	{
		
		std :: cout << "JSON parsed!" << std :: endl;
		
		std :: cout << "Root object type: " << static_cast <uint32_t> ( JSONRoot -> GetType () ) << std :: endl;
		
		Red::Data::JSON :: Object * RootObj = dynamic_cast <Red::Data::JSON :: Object *> ( JSONRoot );
		
		for ( uint32_t I = 0; I < RootObj -> GetKeyCount (); I ++ )
		{
			
			std :: string Key;
			
			RootObj -> GetKeyByIndex ( I, Key );
			
			std :: cout << "root object key: \"" << Key << "\"" << std :: endl;
			
		}
		
		delete JSONRoot;
		
	}
	
	/*================================*/
	
	Red::Behaviors :: BehaviorController BehaviorControl;
	
	Red::Behaviors :: DebugBehavior Debug ( "debug", "Hello, world!", Red::Behaviors::DebugBehavior :: kDebugMessageFlags_All );
	Debug.Reference ();
	
	BehaviorControl.AddBehaviorExternal ( & Debug );
	
	BehaviorControl.StartBehaviorExternal ( "debug" );
	BehaviorControl.IssueUpdate ( Red::Util::Time :: Duration ( 0.0 ) );
	BehaviorControl.IssueSpecificUpdate ();
	BehaviorControl.StopBehaviorExternal ( "debug" );
	BehaviorControl.RemoveBehaviorExternal ( & Debug );
	
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
