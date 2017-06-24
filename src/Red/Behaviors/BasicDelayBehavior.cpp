#include <Red/Behaviors/BasicDelayBehavior.h>
#include <Red/Behaviors/BehaviorController.h>

Red::Behaviors::BasicDelayBehavior :: BasicDelayBehavior ( const std :: string & ID, const Util::Time :: Duration & Delay ):
	ID ( ID ),
	Delay ( Delay ),
	Accumulated ( Util::Time::Duration :: ZERO ),
	BehaviorsToStart (),
	BehaviorsToStop (),
	Controller ( NULL ),
	SelfIndex ( - 1 )
{	
}

Red::Behaviors::BasicDelayBehavior::BehaviorTracker_Struct :: BehaviorTracker_Struct ( const struct BehaviorTracker_Struct & CopyFrom ):
	ID ( CopyFrom.ID ),
	Index ( CopyFrom.Index )
{
}

Red::Behaviors::BasicDelayBehavior::BehaviorTracker_Struct :: BehaviorTracker_Struct ( const std :: string & ID ):
	ID ( ID ),
	Index ( - 1 )
{
}

Red::Behaviors::BasicDelayBehavior :: ~BasicDelayBehavior ()
{
}

const std :: string & Red::Behaviors::BasicDelayBehavior :: GetBehaviorID ()
{
	
	return ID;
	
}

void Red::Behaviors::BasicDelayBehavior :: AddBehaviorIDToStop ( const std :: string & ID )
{
	
	BehaviorsToStop.push_back ( BehaviorTracker ( ID ) );
	
}

void Red::Behaviors::BasicDelayBehavior :: AddBehaviorIDToStart ( const std :: string & ID )
{
	
	BehaviorsToStart.push_back ( BehaviorTracker ( ID ) );
	
}

void Red::Behaviors::BasicDelayBehavior :: BeginUsage ( BehaviorController * ParentController )
{
	
	this -> Controller = ParentController;
	
}

void Red::Behaviors::BasicDelayBehavior :: BehaviorMappingChanged ()
{
	
	for ( uint32_t I = 0; I < BehaviorsToStart.size (); I ++ )
		BehaviorsToStart [ I ].Index = Controller -> GetBehaviorIndex ( BehaviorsToStart [ I ].ID );
	
	for ( uint32_t I = 0; I < BehaviorsToStop.size (); I ++ )
		BehaviorsToStop [ I ].Index = Controller -> GetBehaviorIndex ( BehaviorsToStop [ I ].ID );
	
	SelfIndex = Controller -> GetBehaviorIndex ( ID );
	
}

void Red::Behaviors::BasicDelayBehavior :: EndUsage ()
{
}

void Red::Behaviors::BasicDelayBehavior :: Start ()
{
	
	Accumulated = Util::Time::Duration :: ZERO;
	
}

void Red::Behaviors::BasicDelayBehavior :: Stop ()
{
}

void Red::Behaviors::BasicDelayBehavior :: PreUpdatePeriodic ( const Red::Util::Time :: Duration & Delta )
{
	
	(void) Delta;
	
}

void Red::Behaviors::BasicDelayBehavior :: UpdatePeriodic ( const Red::Util::Time :: Duration & Delta )
{
	
	(void) Delta;
	
}

void Red::Behaviors::BasicDelayBehavior :: PostUpdatePeriodic ( const Red::Util::Time :: Duration & Delta )
{
	
	uint32_t I;
	
	Accumulated += Delta;
	
	if ( Accumulated >= Delay )
	{
		
		for ( I = 0; I < BehaviorsToStop.size (); I ++ )
			Controller -> StopBehavior ( BehaviorsToStop [ I ].Index );
		
		for ( I = 0; I < BehaviorsToStart.size (); I ++ )
			Controller -> StartBehavior ( BehaviorsToStart [ I ].Index );
		
		Controller -> StopBehavior ( SelfIndex );
		
	}
	
}

void Red::Behaviors::BasicDelayBehavior :: UpdateSpecific ()
{
}

uint32_t Red::Behaviors::BasicDelayBehavior :: GetUpdateMode ()
{
	
	return BehaviorController :: kUpdateMode_PostUpdate;
	
}
