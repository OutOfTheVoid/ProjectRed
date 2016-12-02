#include <Red/Behaviors/BehaviorController.h>
#include <Red/Behaviors/IBehavior.h>

Red::Behaviors::BehaviorController :: BehaviorController ():
	Lock (),
	BehaviorList (),
	BehaviorIndexesDirty ( true )
{
}

Red::Behaviors::BehaviorController :: ~BehaviorController ()
{
	
	LockState ();
	
}

void Red::Behaviors::BehaviorController :: LockState ()
{
	
	Lock.Lock ();
	
}

void Red::Behaviors::BehaviorController :: UnlockState ()
{
	
	Lock.Unlock ();
	
}

void Red::Behaviors::BehaviorController :: AddBehavior ( IBehavior * ToAdd )
{
	
	BehaviorRecord Record;
	
	Record.Behavior = ToAdd;
	Record.Running = false;
	
	ToAdd -> Reference ();
	ToAdd -> BeginUsage ( this );
	
	BehaviorList.push_back ( Record );
	
	BehaviorIndexesDirty = true;
	
}

void Red::Behaviors::BehaviorController :: RemoveBehavior ( IBehavior * ToRemove )
{
	
	int32_t Index = GetBehaviorIndex ( ToRemove );
	
	if ( Index >= 0 )
	{
		
		if ( BehaviorList [ Index ].Running )
			BehaviorList [ Index ].Behavior -> Stop ();
		
		BehaviorList [ Index ].Behavior -> EndUsage ();
		BehaviorList [ Index ].Behavior -> Dereference ();
		
		BehaviorList.erase ( BehaviorList.begin () + Index );
		
		BehaviorIndexesDirty = true;
		
	}
	
}

void Red::Behaviors::BehaviorController :: RemoveBehavior ( int32_t Index )
{
	
	if ( ( Index < BehaviorList.size () ) && ( Index >= 0 ) )
	{
		
		if ( BehaviorList [ Index ].Running )
			BehaviorList [ Index ].Behavior -> Stop ();
		
		BehaviorList [ Index ].Behavior -> EndUsage ();
		BehaviorList [ Index ].Behavior -> Dereference ();
		
		BehaviorList.erase ( BehaviorList.begin () + Index );
		
		BehaviorIndexesDirty = true;
		
	}
	
}

void Red::Behaviors::BehaviorController :: AddBehaviorExternal ( IBehavior * ToAdd )
{
	
	LockState ();
	
	BehaviorRecord Record;
	
	Record.Behavior = ToAdd;
	Record.Running = false;
	
	ToAdd -> Reference ();
	ToAdd -> BeginUsage ( this );
	
	BehaviorList.push_back ( Record );
	
	BehaviorIndexesDirty = true;
	
	UnlockState ();
	
}

void Red::Behaviors::BehaviorController :: RemoveBehaviorExternal ( IBehavior * ToRemove )
{
	
	LockState ();
	
	int32_t Index = GetBehaviorIndex ( ToRemove );
	
	if ( Index >= 0 )
	{
		
		if ( BehaviorList [ Index ].Running )
			BehaviorList [ Index ].Behavior -> Stop ();
		
		BehaviorList [ Index ].Behavior -> EndUsage ();
		BehaviorList [ Index ].Behavior -> Dereference ();
		
		BehaviorList.erase ( BehaviorList.begin () + Index );
		
		BehaviorIndexesDirty = true;
		
	}
	
	UnlockState ();
	
}

void Red::Behaviors::BehaviorController :: UpdateBehaviorLinkage ()
{
	
	if ( BehaviorIndexesDirty )
	{
		
		uint32_t Length = BehaviorList.size ();
		
		for ( uint32_t I = 0; I < Length; I ++ )
			BehaviorList [ I ].Behavior -> BehaviorMappingChanged ();
		
		BehaviorIndexesDirty = false;
		
	}
	
}

int32_t Red::Behaviors::BehaviorController :: GetBehaviorIndex ( const std :: string & BehaviorID )
{
	
	uint32_t Length = BehaviorList.size ();
	
	for ( uint32_t I = 0; I < Length; I ++ )
	{
		
		if ( BehaviorList [ I ].Behavior -> GetBehaviorID () == BehaviorID )
			return I;
		
	}
	
}

void Red::Behaviors::BehaviorController :: StartBehavior ( int32_t Index )
{
	
	if ( ( Index >= 0 ) && ( Index < BehaviorList.size () ) )
	{
		
		if ( BehaviorIndexesDirty )
			BehaviorList [ Index ].Behavior -> BehaviorMappingChanged ();
		
		if ( BehaviorList [ Index ].Running == false )
		{
			
			BehaviorList [ Index ].Running = true;
			BehaviorList [ Index ].Behavior -> Start ();
			
		}
		
	}
	
}

void Red::Behaviors::BehaviorController :: StopBehavior ( int32_t Index )
{
	
	if ( ( Index >= 0 ) && ( Index < BehaviorList.size () ) )
	{
		
		if ( BehaviorIndexesDirty )
			BehaviorList [ Index ].Behavior -> BehaviorMappingChanged ();
		
		if ( BehaviorList [ Index ].Running == false )
		{
			
			BehaviorList [ Index ].Running = false;
			BehaviorList [ Index ].Behavior -> Stop ();
			
		}
		
	}
	
}

bool Red::Behaviors::BehaviorController :: GetBehaviorActive ( int32_t Index )
{
	
	if ( ( Index >= 0 ) && ( Index < BehaviorList.size () ) )
	{
		
		return BehaviorList [ Index ].Running;
		
	}
	
}

void Red::Behaviors::BehaviorController :: IssueUpdate ( const Red::Util::Time :: Duration & Delta )
{
	
	Lock.Lock ();
	
	std :: vector <BehaviorRecord> TempList ( BehaviorList );
	
	uint32_t Length = TempList.size ();
	
	for ( uint32_t I = 0; I < Length; I ++ )
	{
		
		if ( BehaviorIndexesDirty )
			TempList [ I ].Behavior -> BehaviorMappingChanged ();
		
		if ( ( TempList [ I ].Running ) && ( ( TempList [ I ].Behavior -> GetUpdateMode () & kUpdateMode_PreUpdate ) != 0 ) )
			TempList [ I ].Behavior -> PreUpdatePeriodic ( Delta );
			
	}
	
	TempList.~vector ();
	new ( & TempList ) std :: vector <BehaviorRecord> ( BehaviorList );
	
	for ( uint32_t I = 0; I < Length; I ++ )
	{
		
		if ( BehaviorIndexesDirty )
			TempList [ I ].Behavior -> BehaviorMappingChanged ();
		
		if ( ( TempList [ I ].Running ) && ( ( TempList [ I ].Behavior -> GetUpdateMode () & kUpdateMode_Update ) != 0 ) )
			TempList [ I ].Behavior -> UpdatePeriodic ( Delta );
			
	}
	
	TempList.~vector ();
	new ( & TempList ) std :: vector <BehaviorRecord> ( BehaviorList );
	
	for ( uint32_t I = 0; I < Length; I ++ )
	{
		
		if ( BehaviorIndexesDirty )
			TempList [ I ].Behavior -> BehaviorMappingChanged ();
		
		if ( ( TempList [ I ].Running ) && ( ( TempList [ I ].Behavior -> GetUpdateMode () & kUpdateMode_PostUpdate ) != 0 ) )
			TempList [ I ].Behavior -> PostUpdatePeriodic ( Delta );
			
	}
	
	Lock.Unlock ();
	
}

void Red::Behaviors::BehaviorController :: IssueSpecificUpdate ()
{
	
	Lock.Lock ();
	
	std :: vector <BehaviorRecord> TempList ( BehaviorList );
	
	uint32_t Length = TempList.size ();
	
	for ( uint32_t I = 0; I < Length; I ++ )
	{
		
		if ( BehaviorIndexesDirty )
			TempList [ I ].Behavior -> BehaviorMappingChanged ();
		
		if ( ( TempList [ I ].Running ) && ( ( TempList [ I ].Behavior -> GetUpdateMode () & kUpdateMode_SpecificUpdate ) != 0 ) )
			TempList [ I ].Behavior -> UpdateSpecific ();
			
	}
	
	Lock.Unlock ();
	
}

int32_t Red::Behaviors::BehaviorController :: GetBehaviorIndex ( IBehavior * ToFind )
{
	
	if ( ToFind == NULL )
		return - 1;
	
	uint32_t Length = BehaviorList.size ();
	
	for ( uint32_t I = 0; I < Length; I ++ )
		if ( BehaviorList [ I ].Behavior -> GetBehaviorID () == ToFind -> GetBehaviorID () )
			return I;
		
	return - 1;
	
}

void Red::Behaviors::BehaviorController :: StartBehaviorExternal ( const std :: string & BehaviorID )
{
	
	LockState ();
	
	StartBehavior ( GetBehaviorIndex ( BehaviorID ) );
	
	UnlockState ();
	
}

void Red::Behaviors::BehaviorController :: StopBehaviorExternal ( const std :: string & BehaviorID )
{
	
	LockState ();
	
	StopBehavior ( GetBehaviorIndex ( BehaviorID ) );
	
	UnlockState ();
	
}

bool Red::Behaviors::BehaviorController :: GetBehaviorActiveExternal ( const std :: string & BehaviorID )
{
	
	bool Result;
	
	LockState ();
	
	Result = GetBehaviorActive ( GetBehaviorIndex ( BehaviorID ) );
	
	UnlockState ();
	
	return Result;
	
}
