#ifndef RED_UTIL_METHODOBJECTCLOSURE_H
#define RED_UTIL_METHODOBJECTCLOSURE_H

#include <Red/Red.h>
#include <Red/Util/Util.h>

namespace Red
{
	
	namespace Util
	{
		
		template <typename Object, typename Return>
		class MethodObjectClosure : public virtual IFunction <Return>
		{
		public:
			
			inline MethodObjectClosure ( Return ( Object :: * MAddress ) (), Object * Target ):
				MAddress ( MAddress ),
				Target ( Target )
			{
			};
			
			inline MethodObjectClosure ( const MethodObjectClosure & CopyFrom ):
				MAddress ( CopyFrom.MAddress ),
				Target ( CopyFrom.Target )
			{	
			};
			
			inline Return Call () const
			{
				
				return ( Target ->* MAddress ) ();
				
			};
			
			inline Return operator() () const
			{
				
				return Call ();
				
			};
			
		private:
			
			Return ( Object :: * MAddress ) ();
			Object * Target;
			
		};
		
		template <typename Object, typename Return>
		class MethodObjectClosure <const Object, Return> : public virtual IFunction <Return>
		{
		public:
			
			inline MethodObjectClosure ( Return ( Object :: * MAddress ) () const, const Object * Target ):
				MAddress ( MAddress ),
				Target ( Target )
			{
			};
			
			inline MethodObjectClosure ( const MethodObjectClosure & CopyFrom ):
				MAddress ( CopyFrom.MAddress ),
				Target ( CopyFrom.Target )
			{	
			};
			
			inline Return Call () const
			{
				
				return ( Target ->* MAddress ) ();
				
			};
			
			inline Return operator() () const
			{
				
				return Call ();
				
			};
			
		private:
			
			Return ( Object :: * MAddress ) () const;
			const Object * Target;
			
		};
		
		template <typename Object, typename Return, typename Arg1>
		class MethodObjectClosure1 : public virtual IFunction1 <Return, Arg1>
		{
		public:
			
			inline MethodObjectClosure1 ( Return ( Object :: * MAddress ) ( Arg1 ), Object * Target ):
				MAddress ( MAddress ),
				Target ( Target )
			{
			};
			
			inline MethodObjectClosure1 ( const MethodObjectClosure1 & CopyFrom ):
				MAddress ( CopyFrom.MAddress ),
				Target ( CopyFrom.Target )
			{	
			};
			
			inline Return Call ( Arg1 A1 ) const
			{
				
				return ( Target ->* MAddress ) ( A1 );
				
			};
			
			inline Return operator() ( Arg1 A1 ) const
			{
				
				return Call ( A1 );
				
			};
			
		private:
			
			Return ( Object :: * MAddress ) ( Arg1 );
			Object * Target;
			
		};
		
		template <typename Object, typename Return, typename Arg1>
		class MethodObjectClosure1 <const Object, Return, Arg1> : public virtual IFunction1 <Return, Arg1>
		{
		public:
			
			inline MethodObjectClosure1 ( Return ( Object :: * MAddress ) ( Arg1 ) const, const Object * Target ):
				MAddress ( MAddress ),
				Target ( Target )
			{
			};
			
			inline MethodObjectClosure1 ( const MethodObjectClosure1 & CopyFrom ):
				MAddress ( CopyFrom.MAddress ),
				Target ( CopyFrom.Target )
			{	
			};
			
			inline Return Call ( Arg1 A1 ) const
			{
				
				return ( Target ->* MAddress ) ( A1 );
				
			};
			
			inline Return operator() ( Arg1 A1 ) const
			{
				
				return Call ( A1 );
				
			};
			
		private:
			
			Return ( Object :: * MAddress ) ( Arg1 ) const;
			const Object * Target;
			
		};
		
		template <typename Object, typename Return, typename Arg1, typename Arg2>
		class MethodObjectClosure2 : public virtual IFunction2 <Return, Arg1, Arg2>
		{
		public:
			
			inline MethodObjectClosure2 ( Return ( Object :: * MAddress ) ( Arg1, Arg2 ), Object * Target ):
				MAddress ( MAddress ),
				Target ( Target )
			{
			};
			
			inline MethodObjectClosure2 ( const MethodObjectClosure2 & CopyFrom ):
				MAddress ( CopyFrom.MAddress ),
				Target ( CopyFrom.Target )
			{	
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2 ) const
			{
				
				return ( Target ->* MAddress ) ( A1, A2 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2 ) const
			{
				
				return Call ( A1, A2 );
				
			};
			
		private:
			
			Return ( Object :: * MAddress ) ( Arg1, Arg2 );
			Object * Target;
			
		};
		
		template <typename Object, typename Return, typename Arg1, typename Arg2>
		class MethodObjectClosure2 <const Object, Return, Arg1, Arg2> : public virtual IFunction2 <Return, Arg1, Arg2>
		{
		public:
			
			inline MethodObjectClosure2 ( Return ( Object :: * MAddress ) ( Arg1, Arg2 ) const, const Object * Target ):
				MAddress ( MAddress ),
				Target ( Target )
			{
			};
			
			inline MethodObjectClosure2 ( const MethodObjectClosure2 & CopyFrom ):
				MAddress ( CopyFrom.MAddress ),
				Target ( CopyFrom.Target )
			{	
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2 ) const
			{
				
				return ( Target ->* MAddress ) ( A1, A2 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2 ) const
			{
				
				return Call ( A1, A2 );
				
			};
			
		private:
			
			Return ( Object :: * MAddress ) ( Arg1, Arg2 ) const;
			const Object * Target;
			
		};
		
		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodObjectClosure3 : public virtual IFunction3 <Return, Arg1, Arg2, Arg3>
		{
		public:
			
			inline MethodObjectClosure3 ( Return ( Object :: * MAddress ) ( Arg1, Arg2, Arg3 ), Object * Target ):
				MAddress ( MAddress ),
				Target ( Target )
			{
			};
			
			inline MethodObjectClosure3 ( const MethodObjectClosure3 & CopyFrom ):
				MAddress ( CopyFrom.MAddress ),
				Target ( CopyFrom.Target )
			{	
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* MAddress ) ( A1, A2, A3 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				return Call ( A1, A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * MAddress ) ( Arg1, Arg2, Arg3 );
			Object * Target;
			
		};
		
		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodObjectClosure3 <const Object, Return, Arg1, Arg2, Arg3> : public virtual IFunction3 <Return, Arg1, Arg2, Arg3>
		{
		public:
			
			inline MethodObjectClosure3 ( Return ( Object :: * MAddress ) ( Arg1, Arg2, Arg3 ) const, const Object * Target ):
				MAddress ( MAddress ),
				Target ( Target )
			{
			};
			
			inline MethodObjectClosure3 ( const MethodObjectClosure3 & CopyFrom ):
				MAddress ( CopyFrom.MAddress ),
				Target ( CopyFrom.Target )
			{	
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* MAddress ) ( A1, A2, A3 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				return Call ( A1, A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * MAddress ) ( Arg1, Arg2, Arg3 ) const;
			const Object * Target;
			
		};
		
		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectClosure4 : public virtual IFunction4 <Return, Arg1, Arg2, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectClosure4 ( Return ( Object :: * MAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Object * Target ):
				MAddress ( MAddress ),
				Target ( Target )
			{
			};
			
			inline MethodObjectClosure4 ( const MethodObjectClosure4 & CopyFrom ):
				MAddress ( CopyFrom.MAddress ),
				Target ( CopyFrom.Target )
			{	
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* MAddress ) ( A1, A2, A3, A4 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return Call ( A1, A2, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * MAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Object * Target;
			
		};
		
		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectClosure4 <const Object, Return, Arg1, Arg2, Arg3, Arg4> : public virtual IFunction4 <Return, Arg1, Arg2, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectClosure4 ( Return ( Object :: * MAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, const Object * Target ):
				MAddress ( MAddress ),
				Target ( Target )
			{
			};
			
			inline MethodObjectClosure4 ( const MethodObjectClosure4 & CopyFrom ):
				MAddress ( CopyFrom.MAddress ),
				Target ( CopyFrom.Target )
			{	
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* MAddress ) ( A1, A2, A3, A4 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return Call ( A1, A2, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * MAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			const Object * Target;
			
		};
		
		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectClosure5 : public virtual IFunction5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectClosure5 ( Return ( Object :: * MAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target ):
				MAddress ( MAddress ),
				Target ( Target )
			{
			};
			
			inline MethodObjectClosure5 ( const MethodObjectClosure5 & CopyFrom ):
				MAddress ( CopyFrom.MAddress ),
				Target ( CopyFrom.Target )
			{	
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* MAddress ) ( A1, A2, A3, A4, A5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return Call ( A1, A2, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * MAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			
		};
		
		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectClosure5 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectClosure5 ( Return ( Object :: * MAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target ):
				MAddress ( MAddress ),
				Target ( Target )
			{
			};
			
			inline MethodObjectClosure5 ( const MethodObjectClosure5 & CopyFrom ):
				MAddress ( CopyFrom.MAddress ),
				Target ( CopyFrom.Target )
			{	
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* MAddress ) ( A1, A2, A3, A4, A5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return Call ( A1, A2, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * MAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			
		};
		
	}
	
}

#endif
