#include <Red/Behaviors/DebugBehavior.h>
#include <Red/Behaviors/BehaviorController.h>

#include <iostream>

Red::Behaviors::DebugBehavior :: DebugBehavior ( const std :: string & ID, const std :: string & Message, uint32_t MessageFlags ):
	RefCounted (),
	ID ( ID ),
	Message ( Message ),
	MessageFlags ( MessageFlags )
{
}
	
Red::Behaviors::DebugBehavior :: ~DebugBehavior ()
{
}

const std :: string & Red::Behaviors::DebugBehavior :: GetBehaviorID ()
{
	
	return ID;
	
}

void Red::Behaviors::DebugBehavior :: BeginUsage ( BehaviorController * ParentController )
{
}

void Red::Behaviors::DebugBehavior :: EndUsage ()
{
}

void Red::Behaviors::DebugBehavior :: BehaviorMappingChanged ()
{
}

void Red::Behaviors::DebugBehavior :: Start ()
{
	
	if ( ( MessageFlags & kDebugMessageFlags_StartMessage ) != 0 )
	{
		
		if ( ( MessageFlags & kDebugMessageFlags_EnableMessagePrefixes ) != 0 )
			Log ( "DebugBehavior START: " + Message );
		else
			Log ( Message );
		
	}
	
}

void Red::Behaviors::DebugBehavior :: Stop ()
{
	
	if ( ( MessageFlags & kDebugMessageFlags_StopMessage ) != 0 )
	{
		
		if ( ( MessageFlags & kDebugMessageFlags_EnableMessagePrefixes ) != 0 )
			Log ( "DebugBehavior STOP: " + Message );
		else
			Log ( Message );
		
	}
	
}


void Red::Behaviors::DebugBehavior :: PreUpdatePeriodic ( const Red::Util::Time :: Duration & Delta )
{
	
	if ( ( MessageFlags & kDebugMessageFlags_PreUpdatePeriodicMessage ) != 0 )
	{
		
		if ( ( MessageFlags & kDebugMessageFlags_EnableMessagePrefixes ) != 0 )
		{
			
			if ( ( MessageFlags & kDebugMessageFlags_EnableMessageDeltaTimes ) != 0 )
				Log ( "DebugBehavior PRE-UPDATE (DT: " + std :: to_string ( Delta.GetFPSeconds () ) + " s):" + Message );
			else
				Log ( "DebugBehavior PRE-UPDATE: " + Message );
			
		}
		else
			Log ( Message );
		
	}
	
}

void Red::Behaviors::DebugBehavior :: UpdatePeriodic ( const Red::Util::Time :: Duration & Delta )
{
	
	if ( ( MessageFlags & kDebugMessageFlags_UpdatePeriodicMessage ) != 0 )
	{
		
		if ( ( MessageFlags & kDebugMessageFlags_EnableMessagePrefixes ) != 0 )
		{
			
			if ( ( MessageFlags & kDebugMessageFlags_EnableMessageDeltaTimes ) != 0 )
				Log ( "DebugBehavior UPDATE (DT: " + std :: to_string ( Delta.GetFPSeconds () ) + " s):" + Message );
			else
				Log ( "DebugBehavior UPDATE: " + Message );
			
		}
		else
			Log ( Message );
		
	}
	
}

void Red::Behaviors::DebugBehavior :: PostUpdatePeriodic ( const Red::Util::Time :: Duration & Delta )
{
	
	if ( ( MessageFlags & kDebugMessageFlags_PostUpdatePeriodicMessage ) != 0 )
	{
		
		if ( ( MessageFlags & kDebugMessageFlags_EnableMessagePrefixes ) != 0 )
		{
			
			if ( ( MessageFlags & kDebugMessageFlags_EnableMessageDeltaTimes ) != 0 )
				Log ( "DebugBehavior POST-UPDATE (DT: " + std :: to_string ( Delta.GetFPSeconds () ) + " s):" + Message );
			else
				Log ( "DebugBehavior POST-UPDATE: " + Message );
			
		}
		else
			Log ( Message );
		
	}
	
}

void Red::Behaviors::DebugBehavior :: UpdateSpecific ()
{
	
	if ( ( MessageFlags & kDebugMessageFlags_UpdateSpecificMessage ) != 0 )
	{
		
		if ( ( MessageFlags & kDebugMessageFlags_EnableMessagePrefixes ) != 0 )
			Log ( "DebugBehavior UPDATE-SPECIFIC: " + Message );
		else
			Log ( Message );
		
	}
	
}

uint32_t Red::Behaviors::DebugBehavior :: GetUpdateMode ()
{
	
	return ( ( ( MessageFlags & kDebugMessageFlags_PreUpdatePeriodicMessage ) != 0 ) ? BehaviorController :: kUpdateMode_PreUpdate : 0 ) | ( ( ( MessageFlags & kDebugMessageFlags_UpdatePeriodicMessage ) != 0 ) ? BehaviorController :: kUpdateMode_Update : 0 ) | ( ( ( MessageFlags & kDebugMessageFlags_PreUpdatePeriodicMessage ) != 0 ) ? BehaviorController :: kUpdateMode_PostUpdate : 0 ) | ( ( ( MessageFlags & kDebugMessageFlags_UpdateSpecificMessage ) != 0 ) ? BehaviorController :: kUpdateMode_SpecificUpdate : 0 );
	
}

void Red::Behaviors::DebugBehavior :: Log ( const std :: string & LMessage )
{
	
	std :: cout << LMessage << std :: endl;
	
}
