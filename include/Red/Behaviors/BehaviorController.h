#ifndef RED_BEHAVIORS_BEHAVIORCONTROLLER_H
#define RED_BEHAVIORS_BEHAVIORCONTROLLER_H

#include <Red/Behaviors/Behaviors.h>

#include <Red/Threading/Mutex.h>

#include <Red/Util/Time.h>
#include <Red/Util/RefCounted.h>

#include <stdint.h>

#include <vector>

namespace Red
{
	
	namespace Behaviors
	{
		
		class IBehavior;
		
		class BehaviorController : public Util :: RefCounted
		{
		public:
			
			static const uint32_t kUpdateMode_PreUpdate = 0x01;
			static const uint32_t kUpdateMode_Update = 0x02;
			static const uint32_t kUpdateMode_PostUpdate = 0x04;
			static const uint32_t kUpdateMode_SpecificUpdate = 0x08;
			
			BehaviorController ();
			~BehaviorController ();
			
			void LockState ();
			void UnlockState ();
			
			void AddBehavior ( IBehavior * ToAdd );
			void RemoveBehavior ( IBehavior * ToRemove );
			void RemoveBehavior ( int32_t Index );
			
			void UpdateBehaviorLinkage ();
			
			int32_t GetBehaviorIndex ( const std :: string & BehaviorID );
			
			void StartBehavior ( int32_t Index );
			void StopBehavior ( int32_t Index );
			
			bool GetBehaviorActive ( int32_t Index );
			
			void IssueUpdate ( const Red::Util::Time :: Duration & Delta );
			
			void IssueSpecificUpdate ();
			
			void StartBehaviorExternal ( const std :: string & BehaviorID );
			void StopBehaviorExternal ( const std :: string & BehaviorID );
			bool GetBehaviorActiveExternal ( const std :: string & BehaviorID );
			void AddBehaviorExternal ( IBehavior * ToAdd );
			void RemoveBehaviorExternal ( IBehavior * ToRemove );
			
		private:
			
			typedef struct
			{
				
				IBehavior * Behavior;
				
				bool Running;
				
			} BehaviorRecord;
			
			int32_t GetBehaviorIndex ( IBehavior * Behavior );
			
			bool BehaviorIndexesDirty;
			
			Threading :: Mutex Lock;
			
			std :: vector <BehaviorRecord> BehaviorList;
			
		};
		
	}
	
}

#endif
