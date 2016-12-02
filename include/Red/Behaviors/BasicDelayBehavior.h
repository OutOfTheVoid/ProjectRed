#ifndef RED_BEHAVIORS_BASICDELAYBEHAVIOR_H
#define RED_BEHAVIORS_BASICDELAYBEHAVIOR_H

#include <Red/Behaviors/Behaviors.h>
#include <Red/Behaviors/IBehavior.h>

#include <Red/Util/RefCounted.h>
#include <Red/Util/Time.h>

#include <string>
#include <vector>

namespace Red
{
	
	namespace Behaviors
	{
		
		class BehaviorController;
		
		class BasicDelayBehavior : public Util :: RefCounted, public virtual IBehavior
		{
		public:
			
			static const std :: string kDefaultIDPrefix;
			
			BasicDelayBehavior ( const std :: string & ID, const Util::Time :: Duration & Delay );
			~BasicDelayBehavior ();
			
			void AddBehaviorIDToStop ( const std :: string & ID );
			void AddBehaviorIDToStart ( const std :: string & ID );
			
			const std :: string & GetBehaviorID ();
			
			void BeginUsage ( BehaviorController * ParentController );
			void BehaviorMappingChanged ();
			void EndUsage ();
			
			void Start ();
			void Stop ();
			
			void PreUpdatePeriodic ( const Red::Util::Time :: Duration & Delta );
			void UpdatePeriodic ( const Red::Util::Time :: Duration & Delta );
			void PostUpdatePeriodic ( const Red::Util::Time :: Duration & Delta );
			
			void UpdateSpecific ();
			
			uint32_t GetUpdateMode ();
			
		private:
			
			const std :: string ID;
			
			const Util::Time :: Duration Delay;
			Util::Time :: Duration Accumulated;
			
			typedef struct BehaviorTracker_Struct
			{
				
				BehaviorTracker_Struct ( const struct BehaviorTracker_Struct & CopyFrom );
				BehaviorTracker_Struct ( const std :: string & ID );
				
				std :: string ID;
				int32_t Index;
				
			} BehaviorTracker;
			
			std :: vector <BehaviorTracker> BehaviorsToStart;
			std :: vector <BehaviorTracker> BehaviorsToStop;
			
			BehaviorController * Controller;
			
			int32_t SelfIndex;
			
		};
		
	}
	
}


#endif
