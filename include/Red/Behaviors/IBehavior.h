#ifndef RED_BEHAVIORS_IBEHAVIOR_H
#define RED_BEHAVIORS_IBEHAVIOR_H

#include <Red/Behaviors/Behaviors.h>

#include <Red/Util/IRefCounted.h>
#include <Red/Util/Time.h>

#include <stdint.h>

#include <string>

namespace Red
{
	
	namespace Behaviors
	{
		
		class BehaviorController;
		
		class IBehavior : public virtual Util::IRefCounted
		{
		public:
			
			virtual inline ~IBehavior () {};
			
			virtual const std :: string & GetBehaviorID () = 0;
			
			virtual void BeginUsage ( BehaviorController * ParentController ) = 0;
			virtual void BehaviorMappingChanged () = 0;
			virtual void EndUsage () = 0;
			
			virtual void Start () = 0;
			virtual void Stop () = 0;
			
			virtual void PreUpdatePeriodic ( const Red::Util::Time :: Duration & Delta ) = 0;
			virtual void UpdatePeriodic ( const Red::Util::Time :: Duration & Delta ) = 0;
			virtual void PostUpdatePeriodic ( const Red::Util::Time :: Duration & Delta ) = 0;
			
			virtual void UpdateSpecific () = 0;
			
			virtual uint32_t GetUpdateMode () = 0;
			
		};
		
	}
	
}

#endif
