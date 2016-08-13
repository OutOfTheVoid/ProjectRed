#ifndef RED_UTIL_FUNCTION_H
#define RED_UTIL_FUNCTION_H

#include <Red/Red.h>
#include <Red/Util/Util.h>

namespace Red
{
	
	namespace Util
	{
		
		template <typename Return>
		class IFunction
		{
		public:
			
			inline virtual ~IFunction () {};
			
			virtual Return Call () = 0;
			virtual Return operator() () = 0;
			
		};
		
		template <typename Return, typename Arg1>
		class IFunction1
		{
		public:
			
			inline virtual ~IFunction1 () {};
			
			virtual Return Call ( Arg1 ) = 0;
			virtual Return operator() ( Arg1 ) = 0;
			
		};
		
		template <typename Return, typename Arg1, typename Arg2>
		class IFunction2
		{
		public:
			
			inline virtual ~IFunction2 () {};
			
			virtual Return Call ( Arg1, Arg2 ) = 0;
			virtual Return operator() ( Arg1, Arg2 ) = 0;
			
		};
		
		template <typename Return, typename Arg1, typename Arg2, typename Arg3>
		class IFunction3
		{
		public:
			
			inline virtual ~IFunction3 () {};
			
			virtual Return Call ( Arg1, Arg2, Arg3 ) = 0;
			virtual Return operator() ( Arg1, Arg2, Arg3 ) = 0;
			
		};
		
		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class IFunction4
		{
		public:
			
			inline virtual ~IFunction4 () {};
			
			virtual Return Call ( Arg1, Arg2, Arg3, Arg4 ) = 0;
			virtual Return operator() ( Arg1, Arg2, Arg3, Arg4 ) = 0;
			
		};
		
		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class IFunction5
		{
		public:
			
			inline virtual ~IFunction5 () {};
			
			virtual Return Call ( Arg1, Arg2, Arg3, Arg4, Arg5 ) = 0;
			virtual Return operator() ( Arg1, Arg2, Arg3, Arg4, Arg5 ) = 0;
			
		};
		
		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class IFunction6
		{
		public:
			
			inline virtual ~IFunction6 () {};
			
			virtual Return Call ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) = 0;
			virtual Return operator() ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) = 0;
			
		};
		
		template <typename Return>
		class Function : public virtual IFunction <Return>
		{
		public:
			
			inline Function ( Return ( * FAddress ) ( void ) ):
				FAddress ( FAddress )
			{
			};
			
			inline Function ( const Function & CopyFrom ):
				FAddress ( CopyFrom.FAddress )
			{
			};
			
			inline ~Function ()
			{
			};
			
			inline Return Call ()
			{
				
				return ( * FAddress ) ();
				
			};
			
			inline Return operator() ()
			{
				
				return Call ();
				
			};
			
		private:
			
			Return ( * FAddress ) ( void );
			
		};
		
		template <typename Return, typename Arg1>
		class Function1 : public virtual IFunction1 <Return, Arg1>
		{
		public:
			
			inline Function1 ( Return ( * FAddress ) ( Arg1 ) ):
				FAddress ( FAddress )
			{
			};
			
			inline Function1 ( const Function1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress )
			{
			};
			
			inline ~Function1 ()
			{
			};
			
			inline Return Call ( Arg1 A1 )
			{
				
				return ( * FAddress ) ( A1 );
				
			};
			
			inline Return operator() ( Arg1 A1 )
			{
				
				return Call ( A1 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1 );
			
		};
		
		template <typename Return, typename Arg1, typename Arg2>
		class Function2 : public virtual IFunction2 <Return, Arg1, Arg2>
		{
		public:
			
			inline Function2 ( Return ( * FAddress ) ( Arg1, Arg2 ) ):
				FAddress ( FAddress )
			{
			};
			
			inline Function2 ( const Function2 & CopyFrom ):
				FAddress ( CopyFrom.FAddress )
			{
			};
			
			inline ~Function2 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2 )
			{
				
				return ( * FAddress ) ( A1, A2 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2 )
			{
				
				return Call ( A1, A2 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2 );
			
		};
		
		template <typename Return, typename Arg1, typename Arg2, typename Arg3>
		class Function3 : public virtual IFunction3 <Return, Arg1, Arg2, Arg3>
		{
		public:
			
			inline Function3 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3 ) ):
				FAddress ( FAddress )
			{
			};
			
			inline Function3 ( const Function3 & CopyFrom ):
				FAddress ( CopyFrom.FAddress )
			{
			};
			
			inline ~Function3 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3 )
			{
				
				return ( * FAddress ) ( A1, A2, A3 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3 )
			{
				
				return Call ( A1, A2, A3 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3 );
			
		};
		
		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class Function4 : public virtual IFunction4 <Return, Arg1, Arg2, Arg3, Arg4>
		{
		public:
			
			inline Function4 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) ):
				FAddress ( FAddress )
			{
			};
			
			inline Function4 ( const Function4 & CopyFrom ):
				FAddress ( CopyFrom.FAddress )
			{
			};
			
			inline ~Function4 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 )
			{
				
				return ( * FAddress ) ( A1, A2, A3, A4 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 )
			{
				
				return Call ( A1, A2, A3, A4 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			
		};
		
		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Function5 : public virtual IFunction5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5>
		{
		public:
			
			inline Function5 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) ):
				FAddress ( FAddress )
			{
			};
			
			inline Function5 ( const Function5 & CopyFrom ):
				FAddress ( CopyFrom.FAddress )
			{
			};
			
			inline ~Function5 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 )
			{
				
				return ( * FAddress ) ( A1, A2, A3, A4, A5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 )
			{
				
				return Call ( A1, A2, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			
		};
		
		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Function6 : public virtual IFunction6 <Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>
		{
		public:
			
			inline Function6 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) ):
				FAddress ( FAddress )
			{
			};
			
			inline Function6 ( const Function6 & CopyFrom ):
				FAddress ( CopyFrom.FAddress )
			{
			};
			
			inline ~Function6 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 )
			{
				
				return ( * FAddress ) ( A1, A2, A3, A4, A5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 )
			{
				
				return Call ( A1, A2, A3, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			
		};
		
	}
	
}

#endif
