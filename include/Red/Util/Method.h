#ifndef RED_UTIL_METHOD_H
#define RED_UTIL_METHOD_H

#include <Red/Util/Util.h>
#include <Red/Util/Function.h>

namespace Red
{
	
	namespace Util
	{
		
		template <typename Object, typename Return>
		class IMethod : public IFunction1 <Return, Object *>
		{
		public:	
			
			inline virtual ~IMethod () {};
			
			virtual Return Call ( Object * ) const = 0;
			virtual Return operator() ( Object * ) const = 0;
			
		};
		
		template <typename Object, typename Return, typename Arg1>
		class IMethod1 : public IFunction2 <Return, Object *, Arg1>
		{
		public:	
			
			inline virtual ~IMethod1 () {};
			
			virtual Return Call ( Object *, Arg1 ) const = 0;
			virtual Return operator() ( Object *, Arg1 ) const = 0;
			
		};
		
		template <typename Object, typename Return, typename Arg1, typename Arg2>
		class IMethod2 : public IFunction3 <Return, Object *, Arg1, Arg2>
		{
		public:	
			
			inline virtual ~IMethod2 () {};
			
			virtual Return Call ( Object *, Arg1, Arg2 ) const = 0;
			virtual Return operator() ( Object *, Arg1, Arg2 ) const = 0;
			
		};
		
		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class IMethod3 : public IFunction4 <Return, Object *, Arg1, Arg2, Arg3>
		{
		public:	
			
			inline virtual ~IMethod3 () {};
			
			virtual Return Call ( Object *, Arg1, Arg2, Arg3 ) const = 0;
			virtual Return operator() ( Object *, Arg1, Arg2, Arg3 ) const = 0;
			
		};
		
		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class IMethod4 : public IFunction5 <Return, Object *, Arg1, Arg2, Arg3, Arg4>
		{
		public:	
			
			inline virtual ~IMethod4 () {};
			
			virtual Return Call ( Object *, Arg1, Arg2, Arg3, Arg4 ) const = 0;
			virtual Return operator() ( Object *, Arg1, Arg2, Arg3, Arg4 ) const = 0;
			
		};
		
		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class IMethod5 : public IFunction6 <Return, Object *, Arg1, Arg2, Arg3, Arg4, Arg5>
		{
		public:	
			
			inline virtual ~IMethod5 () {};
			
			virtual Return Call ( Object *, Arg1, Arg2, Arg3, Arg4, Arg5 ) const = 0;
			virtual Return operator() ( Object *, Arg1, Arg2, Arg3, Arg4, Arg5 ) const = 0;
			
		};
		
		template <typename Object, typename Return>
		class Method : public virtual IMethod <Object, Return>
		{
		public:
			
			inline Method ( Return ( Object :: * MAddress ) ( void ) ):
				MAddress ( MAddress )
			{
			};
			
			inline Method ( const Method & CopyFrom ):
				MAddress ( CopyFrom.MAddress )
			{
			};
			
			inline ~Method ()
			{
			};
			
			inline Return Call ( Object * Target ) const
			{
				
				return Target ->* ( MAddress ) ();
				
			};
			
			inline Return operator() ( Object * Target ) const
			{
				
				return Call ( Target );
				
			};
			
		private:
			
			Return ( Object :: * MAddress ) ( void );
			
		};
		
		template <typename Object, typename Return>
		class Method <const Object, Return> : public virtual IMethod <const Object, Return>
		{
		public:
			
			inline Method ( Return ( Object :: * MAddress ) ( void ) ):
				MAddress ( MAddress )
			{
			};
			
			inline Method ( const Method & CopyFrom ):
				MAddress ( CopyFrom.MAddress )
			{
			};
			
			inline ~Method ()
			{
			};
			
			inline Return Call ( const Object * Target ) const
			{
				
				return Target ->* ( MAddress ) ();
				
			};
			
			inline Return operator() ( const Object * Target ) const
			{
				
				return Call ( Target );
				
			};
			
		private:
			
			Return ( Object :: * MAddress ) ( void ) const;
			
		};
		
		template <typename Object, typename Return, typename Arg1>
		class Method1 : public virtual IMethod1 <Object, Return, Arg1>
		{
		public:
			
			inline Method1 ( Return ( Object :: * MAddress ) ( Arg1 ) ):
				MAddress ( MAddress )
			{
			};
			
			inline Method1 ( const Method1 & CopyFrom ):
				MAddress ( CopyFrom.MAddress )
			{
			};
			
			inline ~Method1 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1 ) const
			{
				
				return Target ->* ( MAddress ) ( A1 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1 ) const
			{
				
				return Call ( Target, A1 );
				
			};
			
		private:
			
			Return ( Object :: * MAddress ) ( Arg1 );
			
		};
		
		template <typename Object, typename Return, typename Arg1>
		class Method1 <const Object, Return, Arg1> : public virtual IMethod1 <const Object, Return, Arg1>
		{
		public:
			
			inline Method1 ( Return ( Object :: * MAddress ) ( Arg1 ) ):
				MAddress ( MAddress )
			{
			};
			
			inline Method1 ( const Method1 & CopyFrom ):
				MAddress ( CopyFrom.MAddress )
			{
			};
			
			inline ~Method1 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1 ) const
			{
				
				return Target ->* ( MAddress ) ( A1 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1 ) const
			{
				
				return Call ( Target, A1 );
				
			};
			
		private:
			
			Return ( Object :: * MAddress ) ( Arg1 ) const;
			
		};
		
		template <typename Object, typename Return, typename Arg1, typename Arg2>
		class Method2 : public virtual IMethod2 <Object, Return, Arg1, Arg2>
		{
		public:
			
			inline Method2 ( Return ( Object :: * MAddress ) ( Arg1, Arg2 ) ):
				MAddress ( MAddress )
			{
			};
			
			inline Method2 ( const Method2 & CopyFrom ):
				MAddress ( CopyFrom.MAddress )
			{
			};
			
			inline ~Method2 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2 ) const
			{
				
				return Target ->* ( MAddress ) ( A1, A2 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2 ) const
			{
				
				return Call ( Target, A1, A2 );
				
			};
			
		private:
			
			Return ( Object :: * MAddress ) ( Arg1, Arg2 );
			
		};
		
		template <typename Object, typename Return, typename Arg1, typename Arg2>
		class Method2 <const Object, Return, Arg1, Arg2> : public virtual IMethod2 <const Object, Return, Arg1, Arg2>
		{
		public:
			
			inline Method2 ( Return ( Object :: * MAddress ) ( Arg1, Arg2 ) ):
				MAddress ( MAddress )
			{
			};
			
			inline Method2 ( const Method2 & CopyFrom ):
				MAddress ( CopyFrom.MAddress )
			{
			};
			
			inline ~Method2 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2 ) const
			{
				
				return Target ->* ( MAddress ) ( A1, A2 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2 ) const
			{
				
				return Call ( Target, A1, A2 );
				
			};
			
		private:
			
			Return ( Object :: * MAddress ) ( Arg1, Arg2 ) const;
			
		};
		
		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class Method3 : public virtual IMethod3 <Object, Return, Arg1, Arg2, Arg3>
		{
		public:
			
			inline Method3 ( Return ( Object :: * MAddress ) ( Arg1, Arg2, Arg3 ) ):
				MAddress ( MAddress )
			{
			};
			
			inline Method3 ( const Method3 & CopyFrom ):
				MAddress ( CopyFrom.MAddress )
			{
			};
			
			inline ~Method3 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				return Target ->* ( MAddress ) ( A1, A2, A3 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				return Call ( Target, A1, A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * MAddress ) ( Arg1, Arg2, Arg3 );
			
		};
		
		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class Method3 <const Object, Return, Arg1, Arg2, Arg3> : public virtual IMethod3 <Object, Return, Arg1, Arg2, Arg3>
		{
		public:
			
			inline Method3 ( Return ( Object :: * MAddress ) ( Arg1, Arg2, Arg3 ) const ):
				MAddress ( MAddress )
			{
			};
			
			inline Method3 ( const Method3 & CopyFrom ):
				MAddress ( CopyFrom.MAddress )
			{
			};
			
			inline ~Method3 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				return Target ->* ( MAddress ) ( A1, A2, A3 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				return Call ( Target, A1, A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * MAddress ) ( Arg1, Arg2, Arg3 ) const;
			
		};
		
		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class Method4 : public virtual IMethod4 <Object, Return, Arg1, Arg2, Arg3, Arg4>
		{
		public:
			
			inline Method4 ( Return ( Object :: * MAddress ) ( Arg1, Arg2, Arg3, Arg4 ) ):
				MAddress ( MAddress )
			{
			};
			
			inline Method4 ( const Method4 & CopyFrom ):
				MAddress ( CopyFrom.MAddress )
			{
			};
			
			inline ~Method4 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return Target ->* ( MAddress ) ( A1, A2, A3, A4 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return Call ( Target, A1, A2, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * MAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			
		};
		
		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class Method4 <const Object, Return, Arg1, Arg2, Arg3, Arg4> : public virtual IMethod4 <Object, Return, Arg1, Arg2, Arg3, Arg4>
		{
		public:
			
			inline Method4 ( Return ( Object :: * MAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const ):
				MAddress ( MAddress )
			{
			};
			
			inline Method4 ( const Method4 & CopyFrom ):
				MAddress ( CopyFrom.MAddress )
			{
			};
			
			inline ~Method4 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return Target ->* ( MAddress ) ( A1, A2, A3, A4 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return Call ( Target, A1, A2, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * MAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			
		};
		
		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Method5 : public virtual IMethod5 <Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>
		{
		public:
			
			inline Method5 ( Return ( Object :: * MAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) ):
				MAddress ( MAddress )
			{
			};
			
			inline Method5 ( const Method5 & CopyFrom ):
				MAddress ( CopyFrom.MAddress )
			{
			};
			
			inline ~Method5 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return Target ->* ( MAddress ) ( A1, A2, A3, A4, A5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return Call ( Target, A1, A2, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * MAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			
		};
		
		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Method5 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IMethod5 <Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>
		{
		public:
			
			inline Method5 ( Return ( Object :: * MAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const ):
				MAddress ( MAddress )
			{
			};
			
			inline Method5 ( const Method5 & CopyFrom ):
				MAddress ( CopyFrom.MAddress )
			{
			};
			
			inline ~Method5 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return Target ->* ( MAddress ) ( A1, A2, A3, A4, A5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return Call ( Target, A1, A2, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * MAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			
		};
		
	}
	
}

#endif