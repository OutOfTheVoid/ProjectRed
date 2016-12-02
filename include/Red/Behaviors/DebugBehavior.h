#ifndef RED_BEHAVIORS_DEBUGBEHAVIOR_H
#define RED_BEHAVIORS_DEBUGBEHAVIOR_H

#include <Red/Behaviors/Behaviors.h>
#include <Red/Behaviors/IBehavior.h>

#include <Red/Util/RefCounted.h>

#include <stdint.h>

namespace Red
{
	
	namespace Behaviors
	{
		
		class DebugBehavior : public Util :: RefCounted, public virtual IBehavior
		{
		public:
			
			static const uint32_t kDebugMessageFlags_EnableMessagePrefixes = 0x01;
			static const uint32_t kDebugMessageFlags_EnableMessageDeltaTimes = 0x02;
			
			static const uint32_t kDebugMessageFlags_StartMessage = 0x04;
			static const uint32_t kDebugMessageFlags_StopMessage = 0x08;
			static const uint32_t kDebugMessageFlags_PreUpdatePeriodicMessage = 0x10;
			static const uint32_t kDebugMessageFlags_UpdatePeriodicMessage = 0x20;
			static const uint32_t kDebugMessageFlags_PostUpdatePeriodicMessage = 0x40;
			static const uint32_t kDebugMessageFlags_UpdateSpecificMessage = 0x80;
			
			static const uint32_t kDebugMessageFlags_AllMessages = 0xFC;
			static const uint32_t kDebugMessageFlags_All = 0xFF;
			
			DebugBehavior ( const std :: string & ID, const std :: string & Message, uint32_t MessageFlags );
			~DebugBehavior ();
			
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
			
			void Log ( const std :: string & LMessage );
			
			const std :: string ID;
			const std :: string Message;
			
			uint32_t MessageFlags;
			
		};
		
	}
	
}

#endif
