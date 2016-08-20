#ifndef RED_UTIL_METHODOBJECTPARAMETERCLOSURE_H
#define RED_UTIL_METHODOBJECTPARAMETERCLOSURE_H

#include <Red/Red.h>
#include <Red/Util/Util.h>
#include <Red/Util/Function.h>

namespace Red
{
	
	namespace Util
	{
		
		template <typename Object, typename Return, typename Arg1>
		class MethodObjectParameterClosure1_1 : public virtual IFunction <Return>
		{
		public:
			
			inline MethodObjectParameterClosure1_1 ( Return ( Object :: * FAddress ) ( Arg1 ), Object * Target, Arg1 Default1 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 )
			{
			};
			
			inline MethodObjectParameterClosure1_1 ( const MethodObjectParameterClosure1_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~MethodObjectParameterClosure1_1 ()
			{
			};
			
			inline Return Call () const
			{
				
				return ( Target ->* FAddress ) ( Default1 );
				
			};
			
			inline Return operator() () const
			{
				
				Call ();
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1 );
			Object * Target;
			Arg1 Default1;
			
		};
		

		template <typename Object, typename Return, typename Arg1>
		class MethodObjectParameterClosure1_1 <const Object, Return, Arg1> : public virtual IFunction <Return>
		{
		public:
			
			inline MethodObjectParameterClosure1_1 ( Return ( Object :: * FAddress ) ( Arg1 ) const, const Object * Target, Arg1 Default1 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 )
			{
			};
			
			inline MethodObjectParameterClosure1_1 ( const MethodObjectParameterClosure1_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~MethodObjectParameterClosure1_1 ()
			{
			};
			
			inline Return Call () const
			{
				
				return ( Target ->* FAddress ) ( Default1 );
				
			};
			
			inline Return operator() () const
			{
				
				Call ();
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1 ) const;
			const Object * Target;
			Arg1 Default1;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2>
		class MethodObjectParameterClosure2_1 : public virtual IFunction1 <Return, Arg2>
		{
		public:
			
			inline MethodObjectParameterClosure2_1 ( Return ( Object :: * FAddress ) ( Arg1, Arg2 ), Object * Target, Arg1 Default1 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 )
			{
			};
			
			inline MethodObjectParameterClosure2_1 ( const MethodObjectParameterClosure2_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~MethodObjectParameterClosure2_1 ()
			{
			};
			
			inline Return Call ( Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2 );
				
			};
			
			inline Return operator() ( Arg2 A2 ) const
			{
				
				Call ( A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2 );
			Object * Target;
			Arg1 Default1;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2>
		class MethodObjectParameterClosure2_1 <const Object, Return, Arg1, Arg2> : public virtual IFunction1 <Return, Arg2>
		{
		public:
			
			inline MethodObjectParameterClosure2_1 ( Return ( Object :: * FAddress ) ( Arg1, Arg2 ) const, const Object * Target, Arg1 Default1 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 )
			{
			};
			
			inline MethodObjectParameterClosure2_1 ( const MethodObjectParameterClosure2_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~MethodObjectParameterClosure2_1 ()
			{
			};
			
			inline Return Call ( Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2 );
				
			};
			
			inline Return operator() ( Arg2 A2 ) const
			{
				
				Call ( A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2 ) const;
			const Object * Target;
			Arg1 Default1;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2>
		class MethodObjectParameterClosure2_2 : public virtual IFunction1 <Return, Arg1>
		{
		public:
			
			inline MethodObjectParameterClosure2_2 ( Return ( Object :: * FAddress ) ( Arg1, Arg2 ), Object * Target, Arg2 Default2 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodObjectParameterClosure2_2 ( const MethodObjectParameterClosure2_2 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodObjectParameterClosure2_2 ()
			{
			};
			
			inline Return Call ( Arg1 A1 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2 );
				
			};
			
			inline Return operator() ( Arg1 A1 ) const
			{
				
				Call ( A1 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2 );
			Object * Target;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2>
		class MethodObjectParameterClosure2_2 <const Object, Return, Arg1, Arg2> : public virtual IFunction1 <Return, Arg1>
		{
		public:
			
			inline MethodObjectParameterClosure2_2 ( Return ( Object :: * FAddress ) ( Arg1, Arg2 ) const, const Object * Target, Arg2 Default2 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodObjectParameterClosure2_2 ( const MethodObjectParameterClosure2_2 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodObjectParameterClosure2_2 ()
			{
			};
			
			inline Return Call ( Arg1 A1 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2 );
				
			};
			
			inline Return operator() ( Arg1 A1 ) const
			{
				
				Call ( A1 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2 ) const;
			const Object * Target;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2>
		class MethodObjectParameterClosure2_12 : public virtual IFunction <Return>
		{
		public:
			
			inline MethodObjectParameterClosure2_12 ( Return ( Object :: * FAddress ) ( Arg1, Arg2 ), Object * Target, Arg1 Default1, Arg2 Default2 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodObjectParameterClosure2_12 ( const MethodObjectParameterClosure2_12 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodObjectParameterClosure2_12 ()
			{
			};
			
			inline Return Call () const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2 );
				
			};
			
			inline Return operator() () const
			{
				
				Call ();
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2>
		class MethodObjectParameterClosure2_12 <const Object, Return, Arg1, Arg2> : public virtual IFunction <Return>
		{
		public:
			
			inline MethodObjectParameterClosure2_12 ( Return ( Object :: * FAddress ) ( Arg1, Arg2 ) const, const Object * Target, Arg1 Default1, Arg2 Default2 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodObjectParameterClosure2_12 ( const MethodObjectParameterClosure2_12 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodObjectParameterClosure2_12 ()
			{
			};
			
			inline Return Call () const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2 );
				
			};
			
			inline Return operator() () const
			{
				
				Call ();
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodObjectParameterClosure3_1 : public virtual IFunction2 <Return, Arg2, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure3_1 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ), Object * Target, Arg1 Default1 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 )
			{
			};
			
			inline MethodObjectParameterClosure3_1 ( const MethodObjectParameterClosure3_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~MethodObjectParameterClosure3_1 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 );
			Object * Target;
			Arg1 Default1;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodObjectParameterClosure3_1 <const Object, Return, Arg1, Arg2, Arg3> : public virtual IFunction2 <Return, Arg2, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure3_1 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ) const, const Object * Target, Arg1 Default1 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 )
			{
			};
			
			inline MethodObjectParameterClosure3_1 ( const MethodObjectParameterClosure3_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~MethodObjectParameterClosure3_1 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ) const;
			const Object * Target;
			Arg1 Default1;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodObjectParameterClosure3_2 : public virtual IFunction2 <Return, Arg1, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure3_2 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ), Object * Target, Arg2 Default2 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodObjectParameterClosure3_2 ( const MethodObjectParameterClosure3_2 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodObjectParameterClosure3_2 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3 ) const
			{
				
				Call ( A1, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 );
			Object * Target;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodObjectParameterClosure3_2 <const Object, Return, Arg1, Arg2, Arg3> : public virtual IFunction2 <Return, Arg1, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure3_2 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ) const, const Object * Target, Arg2 Default2 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodObjectParameterClosure3_2 ( const MethodObjectParameterClosure3_2 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodObjectParameterClosure3_2 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3 ) const
			{
				
				Call ( A1, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ) const;
			const Object * Target;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodObjectParameterClosure3_3 : public virtual IFunction2 <Return, Arg1, Arg2>
		{
		public:
			
			inline MethodObjectParameterClosure3_3 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ), Object * Target, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure3_3 ( const MethodObjectParameterClosure3_3 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure3_3 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2 ) const
			{
				
				Call ( A1, A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 );
			Object * Target;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodObjectParameterClosure3_3 <const Object, Return, Arg1, Arg2, Arg3> : public virtual IFunction2 <Return, Arg1, Arg2>
		{
		public:
			
			inline MethodObjectParameterClosure3_3 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ) const, const Object * Target, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure3_3 ( const MethodObjectParameterClosure3_3 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure3_3 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2 ) const
			{
				
				Call ( A1, A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ) const;
			const Object * Target;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodObjectParameterClosure3_12 : public virtual IFunction1 <Return, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure3_12 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ), Object * Target, Arg1 Default1, Arg2 Default2 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodObjectParameterClosure3_12 ( const MethodObjectParameterClosure3_12 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodObjectParameterClosure3_12 ()
			{
			};
			
			inline Return Call ( Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3 );
				
			};
			
			inline Return operator() ( Arg3 A3 ) const
			{
				
				Call ( A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodObjectParameterClosure3_12 <const Object, Return, Arg1, Arg2, Arg3> : public virtual IFunction1 <Return, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure3_12 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ) const, const Object * Target, Arg1 Default1, Arg2 Default2 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodObjectParameterClosure3_12 ( const MethodObjectParameterClosure3_12 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodObjectParameterClosure3_12 ()
			{
			};
			
			inline Return Call ( Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3 );
				
			};
			
			inline Return operator() ( Arg3 A3 ) const
			{
				
				Call ( A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodObjectParameterClosure3_13 : public virtual IFunction1 <Return, Arg2>
		{
		public:
			
			inline MethodObjectParameterClosure3_13 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ), Object * Target, Arg1 Default1, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure3_13 ( const MethodObjectParameterClosure3_13 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure3_13 ()
			{
			};
			
			inline Return Call ( Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3 );
				
			};
			
			inline Return operator() ( Arg2 A2 ) const
			{
				
				Call ( A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodObjectParameterClosure3_13 <const Object, Return, Arg1, Arg2, Arg3> : public virtual IFunction1 <Return, Arg2>
		{
		public:
			
			inline MethodObjectParameterClosure3_13 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ) const, const Object * Target, Arg1 Default1, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure3_13 ( const MethodObjectParameterClosure3_13 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure3_13 ()
			{
			};
			
			inline Return Call ( Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3 );
				
			};
			
			inline Return operator() ( Arg2 A2 ) const
			{
				
				Call ( A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodObjectParameterClosure3_23 : public virtual IFunction1 <Return, Arg1>
		{
		public:
			
			inline MethodObjectParameterClosure3_23 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ), Object * Target, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure3_23 ( const MethodObjectParameterClosure3_23 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure3_23 ()
			{
			};
			
			inline Return Call ( Arg1 A1 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3 );
				
			};
			
			inline Return operator() ( Arg1 A1 ) const
			{
				
				Call ( A1 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodObjectParameterClosure3_23 <const Object, Return, Arg1, Arg2, Arg3> : public virtual IFunction1 <Return, Arg1>
		{
		public:
			
			inline MethodObjectParameterClosure3_23 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ) const, const Object * Target, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure3_23 ( const MethodObjectParameterClosure3_23 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure3_23 ()
			{
			};
			
			inline Return Call ( Arg1 A1 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3 );
				
			};
			
			inline Return operator() ( Arg1 A1 ) const
			{
				
				Call ( A1 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodObjectParameterClosure3_123 : public virtual IFunction <Return>
		{
		public:
			
			inline MethodObjectParameterClosure3_123 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure3_123 ( const MethodObjectParameterClosure3_123 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure3_123 ()
			{
			};
			
			inline Return Call () const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3 );
				
			};
			
			inline Return operator() () const
			{
				
				Call ();
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodObjectParameterClosure3_123 <const Object, Return, Arg1, Arg2, Arg3> : public virtual IFunction <Return>
		{
		public:
			
			inline MethodObjectParameterClosure3_123 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure3_123 ( const MethodObjectParameterClosure3_123 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure3_123 ()
			{
			};
			
			inline Return Call () const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3 );
				
			};
			
			inline Return operator() () const
			{
				
				Call ();
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_1 : public virtual IFunction3 <Return, Arg2, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure4_1 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Object * Target, Arg1 Default1 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 )
			{
			};
			
			inline MethodObjectParameterClosure4_1 ( const MethodObjectParameterClosure4_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_1 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A2, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Object * Target;
			Arg1 Default1;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_1 <const Object, Return, Arg1, Arg2, Arg3, Arg4> : public virtual IFunction3 <Return, Arg2, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure4_1 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, const Object * Target, Arg1 Default1 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 )
			{
			};
			
			inline MethodObjectParameterClosure4_1 ( const MethodObjectParameterClosure4_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_1 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A2, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			const Object * Target;
			Arg1 Default1;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_2 : public virtual IFunction3 <Return, Arg1, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure4_2 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Object * Target, Arg2 Default2 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodObjectParameterClosure4_2 ( const MethodObjectParameterClosure4_2 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_2 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A1, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Object * Target;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_2 <const Object, Return, Arg1, Arg2, Arg3, Arg4> : public virtual IFunction3 <Return, Arg1, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure4_2 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, const Object * Target, Arg2 Default2 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodObjectParameterClosure4_2 ( const MethodObjectParameterClosure4_2 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_2 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A1, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			const Object * Target;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_3 : public virtual IFunction3 <Return, Arg1, Arg2, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure4_3 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Object * Target, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure4_3 ( const MethodObjectParameterClosure4_3 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_3 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				Call ( A1, A2, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Object * Target;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_3 <const Object, Return, Arg1, Arg2, Arg3, Arg4> : public virtual IFunction3 <Return, Arg1, Arg2, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure4_3 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, const Object * Target, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure4_3 ( const MethodObjectParameterClosure4_3 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_3 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				Call ( A1, A2, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			const Object * Target;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_4 : public virtual IFunction3 <Return, Arg1, Arg2, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure4_4 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Object * Target, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure4_4 ( const MethodObjectParameterClosure4_4 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_4 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( A1, A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Object * Target;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_4 <const Object, Return, Arg1, Arg2, Arg3, Arg4> : public virtual IFunction3 <Return, Arg1, Arg2, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure4_4 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, const Object * Target, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure4_4 ( const MethodObjectParameterClosure4_4 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_4 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( A1, A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			const Object * Target;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_12 : public virtual IFunction2 <Return, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure4_12 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Object * Target, Arg1 Default1, Arg2 Default2 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodObjectParameterClosure4_12 ( const MethodObjectParameterClosure4_12 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_12 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_12 <const Object, Return, Arg1, Arg2, Arg3, Arg4> : public virtual IFunction2 <Return, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure4_12 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, const Object * Target, Arg1 Default1, Arg2 Default2 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodObjectParameterClosure4_12 ( const MethodObjectParameterClosure4_12 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_12 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_13 : public virtual IFunction2 <Return, Arg2, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure4_13 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Object * Target, Arg1 Default1, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure4_13 ( const MethodObjectParameterClosure4_13 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_13 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4 ) const
			{
				
				Call ( A2, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_13 <const Object, Return, Arg1, Arg2, Arg3, Arg4> : public virtual IFunction2 <Return, Arg2, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure4_13 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, const Object * Target, Arg1 Default1, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure4_13 ( const MethodObjectParameterClosure4_13 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_13 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4 ) const
			{
				
				Call ( A2, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_14 : public virtual IFunction2 <Return, Arg2, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure4_14 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Object * Target, Arg1 Default1, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure4_14 ( const MethodObjectParameterClosure4_14 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_14 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_14 <const Object, Return, Arg1, Arg2, Arg3, Arg4> : public virtual IFunction2 <Return, Arg2, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure4_14 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, const Object * Target, Arg1 Default1, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure4_14 ( const MethodObjectParameterClosure4_14 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_14 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_23 : public virtual IFunction2 <Return, Arg1, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure4_23 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Object * Target, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure4_23 ( const MethodObjectParameterClosure4_23 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_23 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4 ) const
			{
				
				Call ( A1, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_23 <const Object, Return, Arg1, Arg2, Arg3, Arg4> : public virtual IFunction2 <Return, Arg1, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure4_23 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, const Object * Target, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure4_23 ( const MethodObjectParameterClosure4_23 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_23 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4 ) const
			{
				
				Call ( A1, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_24 : public virtual IFunction2 <Return, Arg1, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure4_24 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Object * Target, Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure4_24 ( const MethodObjectParameterClosure4_24 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_24 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3 ) const
			{
				
				Call ( A1, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_24 <const Object, Return, Arg1, Arg2, Arg3, Arg4> : public virtual IFunction2 <Return, Arg1, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure4_24 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, const Object * Target, Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure4_24 ( const MethodObjectParameterClosure4_24 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_24 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3 ) const
			{
				
				Call ( A1, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_34 : public virtual IFunction2 <Return, Arg1, Arg2>
		{
		public:
			
			inline MethodObjectParameterClosure4_34 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Object * Target, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure4_34 ( const MethodObjectParameterClosure4_34 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_34 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2 ) const
			{
				
				Call ( A1, A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_34 <const Object, Return, Arg1, Arg2, Arg3, Arg4> : public virtual IFunction2 <Return, Arg1, Arg2>
		{
		public:
			
			inline MethodObjectParameterClosure4_34 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, const Object * Target, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure4_34 ( const MethodObjectParameterClosure4_34 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_34 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2 ) const
			{
				
				Call ( A1, A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			const Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_123 : public virtual IFunction1 <Return, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure4_123 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure4_123 ( const MethodObjectParameterClosure4_123 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_123 ()
			{
			};
			
			inline Return Call ( Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4 );
				
			};
			
			inline Return operator() ( Arg4 A4 ) const
			{
				
				Call ( A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_123 <const Object, Return, Arg1, Arg2, Arg3, Arg4> : public virtual IFunction1 <Return, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure4_123 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure4_123 ( const MethodObjectParameterClosure4_123 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_123 ()
			{
			};
			
			inline Return Call ( Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4 );
				
			};
			
			inline Return operator() ( Arg4 A4 ) const
			{
				
				Call ( A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_124 : public virtual IFunction1 <Return, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure4_124 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure4_124 ( const MethodObjectParameterClosure4_124 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_124 ()
			{
			};
			
			inline Return Call ( Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4 );
				
			};
			
			inline Return operator() ( Arg3 A3 ) const
			{
				
				Call ( A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_124 <const Object, Return, Arg1, Arg2, Arg3, Arg4> : public virtual IFunction1 <Return, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure4_124 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure4_124 ( const MethodObjectParameterClosure4_124 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_124 ()
			{
			};
			
			inline Return Call ( Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4 );
				
			};
			
			inline Return operator() ( Arg3 A3 ) const
			{
				
				Call ( A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_134 : public virtual IFunction1 <Return, Arg2>
		{
		public:
			
			inline MethodObjectParameterClosure4_134 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure4_134 ( const MethodObjectParameterClosure4_134 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_134 ()
			{
			};
			
			inline Return Call ( Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4 );
				
			};
			
			inline Return operator() ( Arg2 A2 ) const
			{
				
				Call ( A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_134 <const Object, Return, Arg1, Arg2, Arg3, Arg4> : public virtual IFunction1 <Return, Arg2>
		{
		public:
			
			inline MethodObjectParameterClosure4_134 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, const Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure4_134 ( const MethodObjectParameterClosure4_134 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_134 ()
			{
			};
			
			inline Return Call ( Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4 );
				
			};
			
			inline Return operator() ( Arg2 A2 ) const
			{
				
				Call ( A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_234 : public virtual IFunction1 <Return, Arg1>
		{
		public:
			
			inline MethodObjectParameterClosure4_234 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure4_234 ( const MethodObjectParameterClosure4_234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_234 ()
			{
			};
			
			inline Return Call ( Arg1 A1 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4 );
				
			};
			
			inline Return operator() ( Arg1 A1 ) const
			{
				
				Call ( A1 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_234 <const Object, Return, Arg1, Arg2, Arg3, Arg4> : public virtual IFunction1 <Return, Arg1>
		{
		public:
			
			inline MethodObjectParameterClosure4_234 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, const Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure4_234 ( const MethodObjectParameterClosure4_234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_234 ()
			{
			};
			
			inline Return Call ( Arg1 A1 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4 );
				
			};
			
			inline Return operator() ( Arg1 A1 ) const
			{
				
				Call ( A1 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_1234 : public virtual IFunction <Return>
		{
		public:
			
			inline MethodObjectParameterClosure4_1234 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure4_1234 ( const MethodObjectParameterClosure4_1234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_1234 ()
			{
			};
			
			inline Return Call () const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4 );
				
			};
			
			inline Return operator() () const
			{
				
				Call ();
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodObjectParameterClosure4_1234 <const Object, Return, Arg1, Arg2, Arg3, Arg4> : public virtual IFunction <Return>
		{
		public:
			
			inline MethodObjectParameterClosure4_1234 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure4_1234 ( const MethodObjectParameterClosure4_1234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure4_1234 ()
			{
			};
			
			inline Return Call () const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4 );
				
			};
			
			inline Return operator() () const
			{
				
				Call ();
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_1 : public virtual IFunction4 <Return, Arg2, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_1 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg1 Default1 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 )
			{
			};
			
			inline MethodObjectParameterClosure5_1 ( const MethodObjectParameterClosure5_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_1 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, A5 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A2, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg1 Default1;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_1 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction4 <Return, Arg2, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_1 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg1 Default1 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 )
			{
			};
			
			inline MethodObjectParameterClosure5_1 ( const MethodObjectParameterClosure5_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_1 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, A5 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A2, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg1 Default1;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_2 : public virtual IFunction4 <Return, Arg1, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_2 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg2 Default2 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodObjectParameterClosure5_2 ( const MethodObjectParameterClosure5_2 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_2 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, A5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A1, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_2 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction4 <Return, Arg1, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_2 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg2 Default2 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodObjectParameterClosure5_2 ( const MethodObjectParameterClosure5_2 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_2 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, A5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A1, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_3 : public virtual IFunction4 <Return, Arg1, Arg2, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_3 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure5_3 ( const MethodObjectParameterClosure5_3 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_3 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, A5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A1, A2, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_3 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction4 <Return, Arg1, Arg2, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_3 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure5_3 ( const MethodObjectParameterClosure5_3 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_3 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, A5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A1, A2, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_4 : public virtual IFunction4 <Return, Arg1, Arg2, Arg3, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_4 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure5_4 ( const MethodObjectParameterClosure5_4 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_4 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, A5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( A1, A2, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg4 Default4;
				
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_4 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction4 <Return, Arg1, Arg2, Arg3, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_4 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure5_4 ( const MethodObjectParameterClosure5_4 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_4 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, A5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( A1, A2, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_5 : public virtual IFunction4 <Return, Arg1, Arg2, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure5_5 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_5 ( const MethodObjectParameterClosure5_5 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_5 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, Default5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A1, A2, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_5 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction4 <Return, Arg1, Arg2, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure5_5 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_5 ( const MethodObjectParameterClosure5_5 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_5 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, Default5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A1, A2, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_12 : public virtual IFunction3 <Return, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_12 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg1 Default1, Arg2 Default2 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodObjectParameterClosure5_12 ( const MethodObjectParameterClosure5_12 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_12 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, A5 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_12 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction3 <Return, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_12 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg1 Default1, Arg2 Default2 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodObjectParameterClosure5_12 ( const MethodObjectParameterClosure5_12 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_12 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, A5 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_13 : public virtual IFunction3 <Return, Arg2, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_13 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg1 Default1, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure5_13 ( const MethodObjectParameterClosure5_13 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_13 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, A5 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A2, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_13 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction3 <Return, Arg2, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_13 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg1 Default1, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure5_13 ( const MethodObjectParameterClosure5_13 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_13 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, A5 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A2, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_14 : public virtual IFunction3 <Return, Arg2, Arg3, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_14 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg1 Default1, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure5_14 ( const MethodObjectParameterClosure5_14 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_14 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, A5 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( A2, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_14 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction3 <Return, Arg2, Arg3, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_14 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg1 Default1, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure5_14 ( const MethodObjectParameterClosure5_14 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_14 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, A5 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( A2, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_15 : public virtual IFunction3 <Return, Arg2, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure5_15 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg1 Default1, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_15 ( const MethodObjectParameterClosure5_15 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_15 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, Default5 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A2, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg1 Default1;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_15 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction3 <Return, Arg2, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure5_15 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg1 Default1, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_15 ( const MethodObjectParameterClosure5_15 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_15 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, Default5 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A2, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_23 : public virtual IFunction3 <Return, Arg1, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_23 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure5_23 ( const MethodObjectParameterClosure5_23 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_23 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, A5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A1, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_23 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction3 <Return, Arg1, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_23 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure5_23 ( const MethodObjectParameterClosure5_23 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_23 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, A5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A1, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_24 : public virtual IFunction3 <Return, Arg1, Arg3, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_24 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure5_24 ( const MethodObjectParameterClosure5_24 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_24 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, A5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( A1, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_24 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction3 <Return, Arg1, Arg3, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_24 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure5_24 ( const MethodObjectParameterClosure5_24 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_24 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, A5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( A1, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_25 : public virtual IFunction3 <Return, Arg1, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure5_25 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg2 Default2, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_25 ( const MethodObjectParameterClosure5_25 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_25 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, Default5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A1, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg2 Default2;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_25 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction3 <Return, Arg1, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure5_25 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg2 Default2, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_25 ( const MethodObjectParameterClosure5_25 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_25 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, Default5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A1, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_34 : public virtual IFunction3 <Return, Arg1, Arg2, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_34 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure5_34 ( const MethodObjectParameterClosure5_34 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_34 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, A5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg5 A5 ) const
			{
				
				Call ( A1, A2, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_34 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction3 <Return, Arg1, Arg2, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_34 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure5_34 ( const MethodObjectParameterClosure5_34 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_34 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, A5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg5 A5 ) const
			{
				
				Call ( A1, A2, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_35 : public virtual IFunction3 <Return, Arg1, Arg2, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure5_35 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_35 ( const MethodObjectParameterClosure5_35 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_35 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, Default5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				Call ( A1, A2, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_35 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction3 <Return, Arg1, Arg2, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure5_35 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_35 ( const MethodObjectParameterClosure5_35 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_35 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, Default5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				Call ( A1, A2, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_45 : public virtual IFunction3 <Return, Arg1, Arg2, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure5_45 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_45 ( const MethodObjectParameterClosure5_45 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_45 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( A1, A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_45 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction3 <Return, Arg1, Arg2, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure5_45 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_45 ( const MethodObjectParameterClosure5_45 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_45 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( A1, A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_123 : public virtual IFunction2 <Return, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_123 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure5_123 ( const MethodObjectParameterClosure5_123 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_123 ()
			{
			};
			
			inline Return Call ( Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, A5 );
				
			};
			
			inline Return operator() ( Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_123 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction2 <Return, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_123 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure5_123 ( const MethodObjectParameterClosure5_123 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_123 ()
			{
			};
			
			inline Return Call ( Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, A5 );
				
			};
			
			inline Return operator() ( Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_124 : public virtual IFunction2 <Return, Arg3, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_124 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure5_124 ( const MethodObjectParameterClosure5_124 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_124 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, A5 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_124 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction2 <Return, Arg3, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_124 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure5_124 ( const MethodObjectParameterClosure5_124 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_124 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, A5 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_125 : public virtual IFunction2 <Return, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure5_125 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_125 ( const MethodObjectParameterClosure5_125 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_125 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, Default5 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_125 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction2 <Return, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure5_125 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_125 ( const MethodObjectParameterClosure5_125 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_125 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, Default5 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_134 : public virtual IFunction2 <Return, Arg2, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_134 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure5_134 ( const MethodObjectParameterClosure5_134 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_134 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, A5 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg5 A5 ) const
			{
				
				Call ( A2, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_134 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction2 <Return, Arg2, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_134 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure5_134 ( const MethodObjectParameterClosure5_134 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_134 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, A5 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg5 A5 ) const
			{
				
				Call ( A2, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_135 : public virtual IFunction2 <Return, Arg2, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure5_135 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg1 Default1, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_135 ( const MethodObjectParameterClosure5_135 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_135 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, Default5 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4 ) const
			{
				
				Call ( A2, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_135 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction2 <Return, Arg2, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure5_135 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg1 Default1, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_135 ( const MethodObjectParameterClosure5_135 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_135 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, Default5 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4 ) const
			{
				
				Call ( A2, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_145 : public virtual IFunction2 <Return, Arg2, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure5_145 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg1 Default1, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_145 ( const MethodObjectParameterClosure5_145 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_145 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_145 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction2 <Return, Arg2, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure5_145 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg1 Default1, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_145 ( const MethodObjectParameterClosure5_145 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_145 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_234 : public virtual IFunction2 <Return, Arg1, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_234 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure5_234 ( const MethodObjectParameterClosure5_234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_234 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, A5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg5 A5 ) const
			{
				
				Call ( A1, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_234 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction2 <Return, Arg1, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_234 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure5_234 ( const MethodObjectParameterClosure5_234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_234 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, A5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg5 A5 ) const
			{
				
				Call ( A1, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_235 : public virtual IFunction2 <Return, Arg1, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure5_235 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg2 Default2, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_235 ( const MethodObjectParameterClosure5_235 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_235 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, Default5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4 ) const
			{
				
				Call ( A1, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_235 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction2 <Return, Arg1, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure5_235 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg2 Default2, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_235 ( const MethodObjectParameterClosure5_235 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_235 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, Default5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4 ) const
			{
				
				Call ( A1, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_245 : public virtual IFunction2 <Return, Arg1, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure5_245 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg2 Default2, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_245 ( const MethodObjectParameterClosure5_245 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_245 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3 ) const
			{
				
				Call ( A1, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_245 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction2 <Return, Arg1, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure5_245 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg2 Default2, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_245 ( const MethodObjectParameterClosure5_245 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_245 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3 ) const
			{
				
				Call ( A1, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_345 : public virtual IFunction2 <Return, Arg1, Arg2>
		{
		public:
			
			inline MethodObjectParameterClosure5_345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_345 ( const MethodObjectParameterClosure5_345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_345 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2 ) const
			{
				
				Call ( A1, A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_345 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction2 <Return, Arg1, Arg2>
		{
		public:
			
			inline MethodObjectParameterClosure5_345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_345 ( const MethodObjectParameterClosure5_345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_345 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2 ) const
			{
				
				Call ( A1, A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_1234 : public virtual IFunction1 <Return, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_1234 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure5_1234 ( const MethodObjectParameterClosure5_1234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_1234 ()
			{
			};
			
			inline Return Call ( Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, A5 );
				
			};
			
			inline Return operator() ( Arg5 A5 ) const
			{
				
				Call ( A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_1234 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction1 <Return, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure5_1234 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure5_1234 ( const MethodObjectParameterClosure5_1234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_1234 ()
			{
			};
			
			inline Return Call ( Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, A5 );
				
			};
			
			inline Return operator() ( Arg5 A5 ) const
			{
				
				Call ( A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_1235 : public virtual IFunction1 <Return, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure5_1235 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_1235 ( const MethodObjectParameterClosure5_1235 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_1235 ()
			{
			};
			
			inline Return Call ( Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, Default5 );
				
			};
			
			inline Return operator() ( Arg4 A4 ) const
			{
				
				Call ( A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_1235 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction1 <Return, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure5_1235 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_1235 ( const MethodObjectParameterClosure5_1235 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_1235 ()
			{
			};
			
			inline Return Call ( Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, Default5 );
				
			};
			
			inline Return operator() ( Arg4 A4 ) const
			{
				
				Call ( A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_1245 : public virtual IFunction1 <Return, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure5_1245 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_1245 ( const MethodObjectParameterClosure5_1245 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_1245 ()
			{
			};
			
			inline Return Call ( Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Arg3 A3 ) const
			{
				
				Call ( A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_1245 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction1 <Return, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure5_1245 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_1245 ( const MethodObjectParameterClosure5_1245 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_1245 ()
			{
			};
			
			inline Return Call ( Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Arg3 A3 ) const
			{
				
				Call ( A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_1345 : public virtual IFunction1 <Return, Arg2>
		{
		public:
			
			inline MethodObjectParameterClosure5_1345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_1345 ( const MethodObjectParameterClosure5_1345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_1345 ()
			{
			};
			
			inline Return Call ( Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Arg2 A2 ) const
			{
				
				Call ( A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_1345 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction1 <Return, Arg2>
		{
		public:
			
			inline MethodObjectParameterClosure5_1345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_1345 ( const MethodObjectParameterClosure5_1345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_1345 ()
			{
			};
			
			inline Return Call ( Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Arg2 A2 ) const
			{
				
				Call ( A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_2345 : public virtual IFunction1 <Return, Arg1>
		{
		public:
			
			inline MethodObjectParameterClosure5_2345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_2345 ( const MethodObjectParameterClosure5_2345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_2345 ()
			{
			};
			
			inline Return Call ( Arg1 A1 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Arg1 A1 ) const
			{
				
				Call ( A1 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_2345 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction1 <Return, Arg1>
		{
		public:
			
			inline MethodObjectParameterClosure5_2345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_2345 ( const MethodObjectParameterClosure5_2345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_2345 ()
			{
			};
			
			inline Return Call ( Arg1 A1 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Arg1 A1 ) const
			{
				
				Call ( A1 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_12345 : public virtual IFunction <Return>
		{
		public:
			
			inline MethodObjectParameterClosure5_12345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
				inline MethodObjectParameterClosure5_12345 ( const MethodObjectParameterClosure5_12345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_12345 ()
			{
			};
			
			inline Return Call () const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, Default5 );
				
			};
			
			inline Return operator() () const
			{
				
				Call ();
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodObjectParameterClosure5_12345 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5> : public virtual IFunction <Return>
		{
		public:
			
			inline MethodObjectParameterClosure5_12345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure5_12345 ( const MethodObjectParameterClosure5_12345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure5_12345 ()
			{
			};
			
			inline Return Call () const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, Default5 );
				
			};
			
			inline Return operator() () const
			{
				
				Call ();
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_1 : public virtual IFunction5 <Return, Arg2, Arg3, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_1 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 )
			{
			};
			
			inline MethodObjectParameterClosure6_1 ( const MethodObjectParameterClosure6_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_1 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A2, A3, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_1 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction5 <Return, Arg2, Arg3, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_1 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 )
			{
			};
			
			inline MethodObjectParameterClosure6_1 ( const MethodObjectParameterClosure6_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_1 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A2, A3, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_2 : public virtual IFunction5 <Return, Arg1, Arg3, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_2 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg2 Default2 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodObjectParameterClosure6_2 ( const MethodObjectParameterClosure6_2 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_2 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A3, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_2 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction5 <Return, Arg1, Arg3, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_2 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg2 Default2 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodObjectParameterClosure6_2 ( const MethodObjectParameterClosure6_2 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_2 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A3, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_3 : public virtual IFunction5 <Return, Arg1, Arg2, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_3 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure6_3 ( const MethodObjectParameterClosure6_3 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_3 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_3 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction5 <Return, Arg1, Arg2, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_3 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure6_3 ( const MethodObjectParameterClosure6_3 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_3 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_4 : public virtual IFunction5 <Return, Arg1, Arg2, Arg3, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_4 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure6_4 ( const MethodObjectParameterClosure6_4 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_4 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A3, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_4 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction5 <Return, Arg1, Arg2, Arg3, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_4 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure6_4 ( const MethodObjectParameterClosure6_4 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_4 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A3, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_5 : public virtual IFunction5 <Return, Arg1, Arg2, Arg3, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_5 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_5 ( const MethodObjectParameterClosure6_5 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_5 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A3, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_5 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction5 <Return, Arg1, Arg2, Arg3, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_5 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_5 ( const MethodObjectParameterClosure6_5 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_5 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A3, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_6 : public virtual IFunction5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_6 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_6 ( const MethodObjectParameterClosure6_6 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_6 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A1, A2, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_6 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_6 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_6 ( const MethodObjectParameterClosure6_6 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_6 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A1, A2, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_12 : public virtual IFunction4 <Return, Arg3, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_12 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg2 Default2 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodObjectParameterClosure6_12 ( const MethodObjectParameterClosure6_12 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_12 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A3, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_12 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction4 <Return, Arg3, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_12 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg2 Default2 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodObjectParameterClosure6_12 ( const MethodObjectParameterClosure6_12 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_12 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A3, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_13 : public virtual IFunction4 <Return, Arg2, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_13 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure6_13 ( const MethodObjectParameterClosure6_13 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_13 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A2, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_13 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction4 <Return, Arg2, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_13 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure6_13 ( const MethodObjectParameterClosure6_13 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_13 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A2, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_14 : public virtual IFunction4 <Return, Arg2, Arg3, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_14 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure6_14 ( const MethodObjectParameterClosure6_14 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_14 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A2, A3, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_14 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction4 <Return, Arg2, Arg3, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_14 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure6_14 ( const MethodObjectParameterClosure6_14 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_14 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A2, A3, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_15 : public virtual IFunction4 <Return, Arg2, Arg3, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_15 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_15 ( const MethodObjectParameterClosure6_15 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_15 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A2, A3, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_15 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction4 <Return, Arg2, Arg3, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_15 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_15 ( const MethodObjectParameterClosure6_15 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_15 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A2, A3, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_16 : public virtual IFunction4 <Return, Arg2, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_16 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_16 ( const MethodObjectParameterClosure6_16 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_16 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A2, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_16 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction4 <Return, Arg2, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_16 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_16 ( const MethodObjectParameterClosure6_16 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_16 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A2, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_23 : public virtual IFunction4 <Return, Arg1, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_23 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure6_23 ( const MethodObjectParameterClosure6_23 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_23 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_23 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction4 <Return, Arg1, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_23 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure6_23 ( const MethodObjectParameterClosure6_23 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_23 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_24 : public virtual IFunction4 <Return, Arg1, Arg3, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_24 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure6_24 ( const MethodObjectParameterClosure6_24 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_24 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A3, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_24 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction4 <Return, Arg1, Arg3, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_24 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure6_24 ( const MethodObjectParameterClosure6_24 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_24 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A3, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_25 : public virtual IFunction4 <Return, Arg1, Arg3, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_25 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg2 Default2, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_25 ( const MethodObjectParameterClosure6_25 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_25 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A1, A3, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg2 Default2;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_25 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction4 <Return, Arg1, Arg3, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_25 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg2 Default2, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_25 ( const MethodObjectParameterClosure6_25 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_25 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A1, A3, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_26 : public virtual IFunction4 <Return, Arg1, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_26 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg2 Default2, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_26 ( const MethodObjectParameterClosure6_26 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_26 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A1, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg2 Default2;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_26 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction4 <Return, Arg1, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_26 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg2 Default2, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_26 ( const MethodObjectParameterClosure6_26 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_26 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A1, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_34 : public virtual IFunction4 <Return, Arg1, Arg2, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_34 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure6_34 ( const MethodObjectParameterClosure6_34 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_34 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_34 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction4 <Return, Arg1, Arg2, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_34 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure6_34 ( const MethodObjectParameterClosure6_34 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_34 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_35 : public virtual IFunction4 <Return, Arg1, Arg2, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_35 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_35 ( const MethodObjectParameterClosure6_35 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_35 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_35 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction4 <Return, Arg1, Arg2, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_35 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_35 ( const MethodObjectParameterClosure6_35 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_35 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_36 : public virtual IFunction4 <Return, Arg1, Arg2, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_36 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg3 Default3, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_36 ( const MethodObjectParameterClosure6_36 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_36 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A1, A2, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg3 Default3;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_36 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction4 <Return, Arg1, Arg2, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_36 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg3 Default3, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_36 ( const MethodObjectParameterClosure6_36 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_36 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A1, A2, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg3 Default3;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_45 : public virtual IFunction4 <Return, Arg1, Arg2, Arg3, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_45 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_45 ( const MethodObjectParameterClosure6_45 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_45 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A3, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_45 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction4 <Return, Arg1, Arg2, Arg3, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_45 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_45 ( const MethodObjectParameterClosure6_45 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_45 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A3, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_46 : public virtual IFunction4 <Return, Arg1, Arg2, Arg3, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_46 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_46 ( const MethodObjectParameterClosure6_46 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_46 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( A1, A2, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_46 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction4 <Return, Arg1, Arg2, Arg3, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_46 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_46 ( const MethodObjectParameterClosure6_46 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_46 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( A1, A2, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_56 : public virtual IFunction4 <Return, Arg1, Arg2, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure6_56 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_56 ( const MethodObjectParameterClosure6_56 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_56 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A1, A2, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_56 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction4 <Return, Arg1, Arg2, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure6_56 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_56 ( const MethodObjectParameterClosure6_56 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_56 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A1, A2, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_123 : public virtual IFunction3 <Return, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_123 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure6_123 ( const MethodObjectParameterClosure6_123 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_123 ()
			{
			};
			
			inline Return Call ( Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_123 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction3 <Return, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_123 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure6_123 ( const MethodObjectParameterClosure6_123 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_123 ()
			{
			};
			
			inline Return Call ( Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_124 : public virtual IFunction3 <Return, Arg3, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_124 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure6_124 ( const MethodObjectParameterClosure6_124 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_124 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A3, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_124 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction3 <Return, Arg3, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_124 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure6_124 ( const MethodObjectParameterClosure6_124 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_124 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A3, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_125 : public virtual IFunction3 <Return, Arg3, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_125 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_125 ( const MethodObjectParameterClosure6_125 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_125 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A3, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_125 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction3 <Return, Arg3, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_125 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_125 ( const MethodObjectParameterClosure6_125 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_125 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A3, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_126 : public virtual IFunction3 <Return, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_126 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_126 ( const MethodObjectParameterClosure6_126 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_126 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_126 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction3 <Return, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_126 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_126 ( const MethodObjectParameterClosure6_126 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_126 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_134 : public virtual IFunction3 <Return, Arg2, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_134 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure6_134 ( const MethodObjectParameterClosure6_134 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_134 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A2, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_134 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction3 <Return, Arg2, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_134 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure6_134 ( const MethodObjectParameterClosure6_134 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_134 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A2, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_135 : public virtual IFunction3 <Return, Arg2, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_135 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_135 ( const MethodObjectParameterClosure6_135 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_135 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4, Arg6 A6 ) const
			{
					
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A2, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_135 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction3 <Return, Arg2, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_135 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_135 ( const MethodObjectParameterClosure6_135 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_135 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A2, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_136 : public virtual IFunction3 <Return, Arg2, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_136 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg3 Default3, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_136 ( const MethodObjectParameterClosure6_136 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_136 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A2, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_136 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction3 <Return, Arg2, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_136 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg3 Default3, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_136 ( const MethodObjectParameterClosure6_136 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_136 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A2, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_145 : public virtual IFunction3 <Return, Arg2, Arg3, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_145 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_145 ( const MethodObjectParameterClosure6_145 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_145 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg6 A6 ) const
			{
				
				Call ( A2, A3, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_145 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction3 <Return, Arg2, Arg3, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_145 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_145 ( const MethodObjectParameterClosure6_145 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_145 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg6 A6 ) const
			{
				
				Call ( A2, A3, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_146 : public virtual IFunction3 <Return, Arg2, Arg3, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_146 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_146 ( const MethodObjectParameterClosure6_146 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_146 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( A2, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_146 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction3 <Return, Arg2, Arg3, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_146 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_146 ( const MethodObjectParameterClosure6_146 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_146 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( A2, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_156 : public virtual IFunction3 <Return, Arg2, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure6_156 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_156 ( const MethodObjectParameterClosure6_156 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_156 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A2, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_156 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction3 <Return, Arg2, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure6_156 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_156 ( const MethodObjectParameterClosure6_156 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_156 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A2, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_234 : public virtual IFunction3 <Return, Arg1, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_234 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure6_234 ( const MethodObjectParameterClosure6_234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_234 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_234 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction3 <Return, Arg1, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_234 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure6_234 ( const MethodObjectParameterClosure6_234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_234 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_235 : public virtual IFunction3 <Return, Arg1, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_235 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg2 Default2, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_235 ( const MethodObjectParameterClosure6_235 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_235 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A1, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_235 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction3 <Return, Arg1, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_235 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg2 Default2, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_235 ( const MethodObjectParameterClosure6_235 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_235 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A1, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_236 : public virtual IFunction3 <Return, Arg1, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_236 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg2 Default2, Arg3 Default3, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_236 ( const MethodObjectParameterClosure6_236 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_236 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A1, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_236 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction3 <Return, Arg1, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_236 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg2 Default2, Arg3 Default3, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_236 ( const MethodObjectParameterClosure6_236 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_236 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A1, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_245 : public virtual IFunction3 <Return, Arg1, Arg3, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_245 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg2 Default2, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_245 ( const MethodObjectParameterClosure6_245 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_245 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg6 A6 ) const
			{
				
				Call ( A1, A3, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_245 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction3 <Return, Arg1, Arg3, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_245 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg2 Default2, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_245 ( const MethodObjectParameterClosure6_245 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_245 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg6 A6 ) const
			{
				
				Call ( A1, A3, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_246 : public virtual IFunction3 <Return, Arg1, Arg3, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_246 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg2 Default2, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_246 ( const MethodObjectParameterClosure6_246 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_246 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( A1, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_246 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction3 <Return, Arg1, Arg3, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_246 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg2 Default2, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_246 ( const MethodObjectParameterClosure6_246 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_246 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( A1, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_256 : public virtual IFunction3 <Return, Arg1, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure6_256 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg2 Default2, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_256 ( const MethodObjectParameterClosure6_256 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_256 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A1, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg2 Default2;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_256 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction3 <Return, Arg1, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure6_256 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg2 Default2, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_256 ( const MethodObjectParameterClosure6_256 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_256 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A1, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_345 : public virtual IFunction3 <Return, Arg1, Arg2, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_345 ( const MethodObjectParameterClosure6_345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_345 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_345 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction3 <Return, Arg1, Arg2, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_345 ( const MethodObjectParameterClosure6_345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_345 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_346 : public virtual IFunction3 <Return, Arg1, Arg2, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_346 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg3 Default3, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_346 ( const MethodObjectParameterClosure6_346 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_346 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg5 A5 ) const
			{
				
				Call ( A1, A2, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_346 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction3 <Return, Arg1, Arg2, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_346 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg3 Default3, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_346 ( const MethodObjectParameterClosure6_346 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_346 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg5 A5 ) const
			{
				
				Call ( A1, A2, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_356 : public virtual IFunction3 <Return, Arg1, Arg2, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure6_356 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg3 Default3, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_356 ( const MethodObjectParameterClosure6_356 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_356 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				Call ( A1, A2, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_356 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction3 <Return, Arg1, Arg2, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure6_356 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg3 Default3, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_356 ( const MethodObjectParameterClosure6_356 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_356 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				Call ( A1, A2, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_456 : public virtual IFunction3 <Return, Arg1, Arg2, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure6_456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_456 ( const MethodObjectParameterClosure6_456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_456 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( A1, A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_456 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction3 <Return, Arg1, Arg2, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure6_456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_456 ( const MethodObjectParameterClosure6_456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_456 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( A1, A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_1234 : public virtual IFunction2 <Return, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_1234 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure6_1234 ( const MethodObjectParameterClosure6_1234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_1234 ()
			{
			};
			
			inline Return Call ( Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_1234 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction2 <Return, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_1234 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure6_1234 ( const MethodObjectParameterClosure6_1234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_1234 ()
			{
			};
			
			inline Return Call ( Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_1235 : public virtual IFunction2 <Return, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_1235 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_1235 ( const MethodObjectParameterClosure6_1235 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_1235 ()
			{
			};
			
			inline Return Call ( Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_1235 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction2 <Return, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_1235 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_1235 ( const MethodObjectParameterClosure6_1235 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_1235 ()
			{
			};
			
			inline Return Call ( Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_1236 : public virtual IFunction2 <Return, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_1236 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_1236 ( const MethodObjectParameterClosure6_1236 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_1236 ()
			{
			};
			
			inline Return Call ( Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_1236 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction2 <Return, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_1236 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_1236 ( const MethodObjectParameterClosure6_1236 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_1236 ()
			{
			};
			
			inline Return Call ( Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_1245 : public virtual IFunction2 <Return, Arg3, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_1245 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_1245 ( const MethodObjectParameterClosure6_1245 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_1245 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg6 A6 ) const
			{
				
				Call ( A3, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_1245 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction2 <Return, Arg3, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_1245 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_1245 ( const MethodObjectParameterClosure6_1245 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_1245 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg6 A6 ) const
			{
				
				Call ( A3, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_1246 : public virtual IFunction2 <Return, Arg3, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_1246 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_1246 ( const MethodObjectParameterClosure6_1246 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_1246 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_1246 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction2 <Return, Arg3, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_1246 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_1246 ( const MethodObjectParameterClosure6_1246 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_1246 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_1256 : public virtual IFunction2 <Return, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure6_1256 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_1256 ( const MethodObjectParameterClosure6_1256 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_1256 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_1256 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction2 <Return, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure6_1256 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_1256 ( const MethodObjectParameterClosure6_1256 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_1256 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_1345 : public virtual IFunction2 <Return, Arg2, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_1345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_1345 ( const MethodObjectParameterClosure6_1345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_1345 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg6 A6 ) const
			{
				
				Call ( A2, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_1345 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction2 <Return, Arg2, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_1345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_1345 ( const MethodObjectParameterClosure6_1345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_1345 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg6 A6 ) const
			{
				
				Call ( A2, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_1346 : public virtual IFunction2 <Return, Arg2, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_1346 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_1346 ( const MethodObjectParameterClosure6_1346 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_1346 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg5 A5 ) const
			{
				
				Call ( A2, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_1346 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction2 <Return, Arg2, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_1346 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_1346 ( const MethodObjectParameterClosure6_1346 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_1346 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg5 A5 ) const
			{
				
				Call ( A2, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_1356 : public virtual IFunction2 <Return, Arg2, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure6_1356 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg3 Default3, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_1356 ( const MethodObjectParameterClosure6_1356 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_1356 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4 ) const
			{
				
				Call ( A2, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_1356 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction2 <Return, Arg2, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure6_1356 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg3 Default3, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_1356 ( const MethodObjectParameterClosure6_1356 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_1356 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4 ) const
			{
				
				Call ( A2, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_1456 : public virtual IFunction2 <Return, Arg2, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure6_1456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_1456 ( const MethodObjectParameterClosure6_1456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_1456 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_1456 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction2 <Return, Arg2, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure6_1456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_1456 ( const MethodObjectParameterClosure6_1456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_1456 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_2345 : public virtual IFunction2 <Return, Arg1, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_2345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_2345 ( const MethodObjectParameterClosure6_2345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_2345 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg6 A6 ) const
			{
				
				Call ( A1, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_2345 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction2 <Return, Arg1, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_2345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_2345 ( const MethodObjectParameterClosure6_2345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_2345 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg6 A6 ) const
			{
				
				Call ( A1, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_2346 : public virtual IFunction2 <Return, Arg1, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_2346 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_2346 ( const MethodObjectParameterClosure6_2346 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_2346 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg5 A5 ) const
			{
				
				Call ( A1, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_2346 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction2 <Return, Arg1, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_2346 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_2346 ( const MethodObjectParameterClosure6_2346 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_2346 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg5 A5 ) const
			{
				
				Call ( A1, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_2356 : public virtual IFunction2 <Return, Arg1, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure6_2356 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg2 Default2, Arg3 Default3, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_2356 ( const MethodObjectParameterClosure6_2356 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_2356 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4 ) const
			{
				
				Call ( A1, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_2356 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction2 <Return, Arg1, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure6_2356 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg2 Default2, Arg3 Default3, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_2356 ( const MethodObjectParameterClosure6_2356 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_2356 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4 ) const
			{
				
				Call ( A1, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_2456 : public virtual IFunction2 <Return, Arg1, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure6_2456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg2 Default2, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_2456 ( const MethodObjectParameterClosure6_2456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_2456 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3 ) const
			{
				
				Call ( A1, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_2456 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction2 <Return, Arg1, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure6_2456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg2 Default2, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_2456 ( const MethodObjectParameterClosure6_2456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_2456 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3 ) const
			{
				
				Call ( A1, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_3456 : public virtual IFunction2 <Return, Arg1, Arg2>
		{
		public:
			
			inline MethodObjectParameterClosure6_3456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_3456 ( const MethodObjectParameterClosure6_3456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_3456 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2 ) const
			{
				
				Call ( A1, A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_3456 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction2 <Return, Arg1, Arg2>
		{
		public:
			
			inline MethodObjectParameterClosure6_3456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_3456 ( const MethodObjectParameterClosure6_3456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_3456 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2 ) const
			{
				
				Call ( A1, A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_12345 : public virtual IFunction1 <Return, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_12345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_12345 ( const MethodObjectParameterClosure6_12345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_12345 ()
			{
			};
			
			inline Return Call ( Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg6 A6 ) const
			{
				
				Call ( A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_12345 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction1 <Return, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure6_12345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure6_12345 ( const MethodObjectParameterClosure6_12345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_12345 ()
			{
			};
			
			inline Return Call ( Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg6 A6 ) const
			{
				
				Call ( A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_12346 : public virtual IFunction1 <Return, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_12346 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_12346 ( const MethodObjectParameterClosure6_12346 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_12346 ()
			{
			};
			
			inline Return Call ( Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg5 A5 ) const
			{
				
				Call ( A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_12346 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction1 <Return, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure6_12346 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_12346 ( const MethodObjectParameterClosure6_12346 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_12346 ()
			{
			};
			
			inline Return Call ( Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg5 A5 ) const
			{
				
				Call ( A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_12356 : public virtual IFunction1 <Return, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure6_12356 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_12356 ( const MethodObjectParameterClosure6_12356 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_12356 ()
			{
			};
			
			inline Return Call ( Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg4 A4 ) const
			{
				
				Call ( A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_12356 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction1 <Return, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure6_12356 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_12356 ( const MethodObjectParameterClosure6_12356 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_12356 ()
			{
			};
			
			inline Return Call ( Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg4 A4 ) const
			{
				
				Call ( A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_12456 : public virtual IFunction1 <Return, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure6_12456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_12456 ( const MethodObjectParameterClosure6_12456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_12456 ()
			{
			};
			
			inline Return Call ( Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg3 A3 ) const
			{
				
				Call ( A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_12456 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction1 <Return, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure6_12456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_12456 ( const MethodObjectParameterClosure6_12456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_12456 ()
			{
			};
			
			inline Return Call ( Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg3 A3 ) const
			{
				
				Call ( A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_13456 : public virtual IFunction1 <Return, Arg2>
		{
		public:
			
			inline MethodObjectParameterClosure6_13456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_13456 ( const MethodObjectParameterClosure6_13456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_13456 ()
			{
			};
			
			inline Return Call ( Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg2 A2 ) const
			{
				
				Call ( A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_13456 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction1 <Return, Arg2>
		{
		public:
			
			inline MethodObjectParameterClosure6_13456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_13456 ( const MethodObjectParameterClosure6_13456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_13456 ()
			{
			};
			
			inline Return Call ( Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg2 A2 ) const
			{
				
				Call ( A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_23456 : public virtual IFunction1 <Return, Arg1>
		{
		public:
			
			inline MethodObjectParameterClosure6_23456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_23456 ( const MethodObjectParameterClosure6_23456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_23456 ()
			{
			};
			
			inline Return Call ( Arg1 A1 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1 ) const
			{
				
				Call ( A1 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_23456 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction1 <Return, Arg1>
		{
		public:
			
			inline MethodObjectParameterClosure6_23456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_23456 ( const MethodObjectParameterClosure6_23456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_23456 ()
			{
			};
			
			inline Return Call ( Arg1 A1 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1 ) const
			{
				
				Call ( A1 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_123456 : public virtual IFunction <Return>
		{
		public:
			
			inline MethodObjectParameterClosure6_123456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_123456 ( const MethodObjectParameterClosure6_123456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_123456 ()
			{
			};
			
			inline Return Call () const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() () const
			{
				
				Call ();
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodObjectParameterClosure6_123456 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6> : public virtual IFunction <Return>
		{
		public:
			
			inline MethodObjectParameterClosure6_123456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure6_123456 ( const MethodObjectParameterClosure6_123456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure6_123456 ()
			{
			};
			
			inline Return Call () const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() () const
			{
				
				Call ();
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1 : public virtual IFunction6 <Return, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_1 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 )
			{
			};
			
			inline MethodObjectParameterClosure7_1 ( const MethodObjectParameterClosure7_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A2, A3, A4, A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction6 <Return, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_1 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 )
			{
			};
			
			inline MethodObjectParameterClosure7_1 ( const MethodObjectParameterClosure7_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A2, A3, A4, A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_2 : public virtual IFunction6 <Return, Arg1, Arg3, Arg4, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_2 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodObjectParameterClosure7_2 ( const MethodObjectParameterClosure7_2 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_2 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A3, A4, A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_2 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction6 <Return, Arg1, Arg3, Arg4, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_2 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodObjectParameterClosure7_2 ( const MethodObjectParameterClosure7_2 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_2 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A3, A4, A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_3 : public virtual IFunction6 <Return, Arg1, Arg2, Arg4, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_3 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure7_3 ( const MethodObjectParameterClosure7_3 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_3 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A4, A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_3 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction6 <Return, Arg1, Arg2, Arg4, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_3 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure7_3 ( const MethodObjectParameterClosure7_3 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_3 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A4, A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_4 : public virtual IFunction6 <Return, Arg1, Arg2, Arg3, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_4 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure7_4 ( const MethodObjectParameterClosure7_4 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_4 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A3, A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_4 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction6 <Return, Arg1, Arg2, Arg3, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_4 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure7_4 ( const MethodObjectParameterClosure7_4 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_4 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A3, A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_5 : public virtual IFunction6 <Return, Arg1, Arg2, Arg3, Arg4, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_5 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_5 ( const MethodObjectParameterClosure7_5 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_5 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A3, A4, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_5 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction6 <Return, Arg1, Arg2, Arg3, Arg4, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_5 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_5 ( const MethodObjectParameterClosure7_5 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_5 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A3, A4, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_6 : public virtual IFunction6 <Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_6 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_6 ( const MethodObjectParameterClosure7_6 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_6 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A3, A4, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_6 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction6 <Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_6 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_6 ( const MethodObjectParameterClosure7_6 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_6 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A3, A4, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_7 : public virtual IFunction6 <Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_7 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_7 ( const MethodObjectParameterClosure7_7 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_7 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A3, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_7 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction6 <Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_7 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_7 ( const MethodObjectParameterClosure7_7 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_7 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A3, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_12 : public virtual IFunction5 <Return, Arg3, Arg4, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_12 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodObjectParameterClosure7_12 ( const MethodObjectParameterClosure7_12 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_12 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A3, A4, A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_12 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction5 <Return, Arg3, Arg4, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_12 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodObjectParameterClosure7_12 ( const MethodObjectParameterClosure7_12 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_12 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A3, A4, A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_13 : public virtual IFunction5 <Return, Arg2, Arg4, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_13 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure7_13 ( const MethodObjectParameterClosure7_13 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_13 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A2, A4, A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_13 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction5 <Return, Arg2, Arg4, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_13 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure7_13 ( const MethodObjectParameterClosure7_13 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_13 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A2, A4, A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_14 : public virtual IFunction5 <Return, Arg2, Arg3, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_14 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure7_14 ( const MethodObjectParameterClosure7_14 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_14 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A2, A3, A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_14 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction5 <Return, Arg2, Arg3, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_14 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure7_14 ( const MethodObjectParameterClosure7_14 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_14 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A2, A3, A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_15 : public virtual IFunction5 <Return, Arg2, Arg3, Arg4, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_15 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_15 ( const MethodObjectParameterClosure7_15 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_15 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A2, A3, A4, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_15 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction5 <Return, Arg2, Arg3, Arg4, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_15 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_15 ( const MethodObjectParameterClosure7_15 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_15 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A2, A3, A4, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_16 : public virtual IFunction5 <Return, Arg2, Arg3, Arg4, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_16 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_16 ( const MethodObjectParameterClosure7_16 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_16 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A2, A3, A4, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_16 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction5 <Return, Arg2, Arg3, Arg4, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_16 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_16 ( const MethodObjectParameterClosure7_16 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_16 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A2, A3, A4, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_17 : public virtual IFunction5 <Return, Arg2, Arg3, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_17 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_17 ( const MethodObjectParameterClosure7_17 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_17 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A2, A3, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_17 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction5 <Return, Arg2, Arg3, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_17 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_17 ( const MethodObjectParameterClosure7_17 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_17 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A2, A3, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_23 : public virtual IFunction5 <Return, Arg1, Arg4, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_23 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure7_23 ( const MethodObjectParameterClosure7_23 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_23 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A4, A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_23 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction5 <Return, Arg1, Arg4, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_23 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure7_23 ( const MethodObjectParameterClosure7_23 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_23 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A4, A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_24 : public virtual IFunction5 <Return, Arg1, Arg3, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_24 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure7_24 ( const MethodObjectParameterClosure7_24 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_24 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A3, A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_24 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction5 <Return, Arg1, Arg3, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_24 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure7_24 ( const MethodObjectParameterClosure7_24 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_24 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A3, A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_25 : public virtual IFunction5 <Return, Arg1, Arg3, Arg4, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_25 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_25 ( const MethodObjectParameterClosure7_25 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_25 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A3, A4, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_25 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction5 <Return, Arg1, Arg3, Arg4, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_25 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_25 ( const MethodObjectParameterClosure7_25 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_25 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A3, A4, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_26 : public virtual IFunction5 <Return, Arg1, Arg3, Arg4, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_26 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_26 ( const MethodObjectParameterClosure7_26 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_26 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A1, A3, A4, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_26 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction5 <Return, Arg1, Arg3, Arg4, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_26 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_26 ( const MethodObjectParameterClosure7_26 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_26 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A1, A3, A4, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_27 : public virtual IFunction5 <Return, Arg1, Arg3, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_27 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_27 ( const MethodObjectParameterClosure7_27 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_27 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A3, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_27 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction5 <Return, Arg1, Arg3, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_27 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_27 ( const MethodObjectParameterClosure7_27 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_27 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A3, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_34 : public virtual IFunction5 <Return, Arg1, Arg2, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_34 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure7_34 ( const MethodObjectParameterClosure7_34 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_34 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_34 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction5 <Return, Arg1, Arg2, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_34 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure7_34 ( const MethodObjectParameterClosure7_34 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_34 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_35 : public virtual IFunction5 <Return, Arg1, Arg2, Arg4, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_35 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_35 ( const MethodObjectParameterClosure7_35 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_35 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A4, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_35 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction5 <Return, Arg1, Arg2, Arg4, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_35 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_35 ( const MethodObjectParameterClosure7_35 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_35 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A4, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_36 : public virtual IFunction5 <Return, Arg1, Arg2, Arg4, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_36 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg3 Default3, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_36 ( const MethodObjectParameterClosure7_36 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_36 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A4, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg3 Default3;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_36 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction5 <Return, Arg1, Arg2, Arg4, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_36 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg3 Default3, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_36 ( const MethodObjectParameterClosure7_36 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_36 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A4, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg3 Default3;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_37 : public virtual IFunction5 <Return, Arg1, Arg2, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_37 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg3 Default3, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_37 ( const MethodObjectParameterClosure7_37 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_37 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg3 Default3;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_37 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction5 <Return, Arg1, Arg2, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_37 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg3 Default3, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_37 ( const MethodObjectParameterClosure7_37 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_37 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg3 Default3;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_45 : public virtual IFunction5 <Return, Arg1, Arg2, Arg3, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_45 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_45 ( const MethodObjectParameterClosure7_45 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_45 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A3, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_45 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction5 <Return, Arg1, Arg2, Arg3, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_45 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_45 ( const MethodObjectParameterClosure7_45 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_45 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A3, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_46 : public virtual IFunction5 <Return, Arg1, Arg2, Arg3, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_46 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_46 ( const MethodObjectParameterClosure7_46 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_46 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A3, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_46 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction5 <Return, Arg1, Arg2, Arg3, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_46 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_46 ( const MethodObjectParameterClosure7_46 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_46 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A3, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_47 : public virtual IFunction5 <Return, Arg1, Arg2, Arg3, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_47 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg4 Default4, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_47 ( const MethodObjectParameterClosure7_47 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_47 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A3, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg4 Default4;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_47 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction5 <Return, Arg1, Arg2, Arg3, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_47 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg4 Default4, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_47 ( const MethodObjectParameterClosure7_47 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_47 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A3, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg4 Default4;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_56 : public virtual IFunction5 <Return, Arg1, Arg2, Arg3, Arg4, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_56 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_56 ( const MethodObjectParameterClosure7_56 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_56 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A3, A4, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_56 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction5 <Return, Arg1, Arg2, Arg3, Arg4, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_56 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_56 ( const MethodObjectParameterClosure7_56 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_56 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A3, A4, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_57 : public virtual IFunction5 <Return, Arg1, Arg2, Arg3, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_57 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_57 ( const MethodObjectParameterClosure7_57 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_57 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A3, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_57 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction5 <Return, Arg1, Arg2, Arg3, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_57 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_57 ( const MethodObjectParameterClosure7_57 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_57 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A3, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_67 : public virtual IFunction5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_67 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_67 ( const MethodObjectParameterClosure7_67 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_67 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A1, A2, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_67 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_67 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_67 ( const MethodObjectParameterClosure7_67 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_67 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A1, A2, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_123 : public virtual IFunction4 <Return, Arg4, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_123 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure7_123 ( const MethodObjectParameterClosure7_123 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_123 ()
			{
			};
			
			inline Return Call ( Arg4 A4, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg4 A4, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A4, A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_123 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg4, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_123 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodObjectParameterClosure7_123 ( const MethodObjectParameterClosure7_123 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_123 ()
			{
			};
			
			inline Return Call ( Arg4 A4, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg4 A4, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A4, A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_124 : public virtual IFunction4 <Return, Arg3, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_124 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure7_124 ( const MethodObjectParameterClosure7_124 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_124 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A3, A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_124 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg3, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_124 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure7_124 ( const MethodObjectParameterClosure7_124 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_124 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A3, A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_125 : public virtual IFunction4 <Return, Arg3, Arg4, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_125 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_125 ( const MethodObjectParameterClosure7_125 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_125 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A3, A4, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_125 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg3, Arg4, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_125 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_125 ( const MethodObjectParameterClosure7_125 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_125 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A3, A4, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_126 : public virtual IFunction4 <Return, Arg3, Arg4, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_126 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_126 ( const MethodObjectParameterClosure7_126 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_126 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A3, A4, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_126 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg3, Arg4, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_126 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_126 ( const MethodObjectParameterClosure7_126 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_126 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A3, A4, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_127 : public virtual IFunction4 <Return, Arg3, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_127 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_127 ( const MethodObjectParameterClosure7_127 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_127 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A3, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_127 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg3, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_127 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_127 ( const MethodObjectParameterClosure7_127 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_127 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A3, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_134 : public virtual IFunction4 <Return, Arg2, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_134 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure7_134 ( const MethodObjectParameterClosure7_134 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_134 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A2, A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_134 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg2, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_134 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure7_134 ( const MethodObjectParameterClosure7_134 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_134 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A2, A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_135 : public virtual IFunction4 <Return, Arg2, Arg4, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_135 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_135 ( const MethodObjectParameterClosure7_135 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_135 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A2, A4, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_135 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg2, Arg4, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_135 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_135 ( const MethodObjectParameterClosure7_135 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_135 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A2, A4, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_136 : public virtual IFunction4 <Return, Arg2, Arg4, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_136 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg3 Default3, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_136 ( const MethodObjectParameterClosure7_136 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_136 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A2, A4, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_136 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg2, Arg4, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_136 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg3 Default3, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_136 ( const MethodObjectParameterClosure7_136 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_136 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A2, A4, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_137 : public virtual IFunction4 <Return, Arg2, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_137 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg3 Default3, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_137 ( const MethodObjectParameterClosure7_137 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_137 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A2, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_137 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg2, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_137 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg3 Default3, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_137 ( const MethodObjectParameterClosure7_137 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_137 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A2, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_145 : public virtual IFunction4 <Return, Arg2, Arg3, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_145 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_145 ( const MethodObjectParameterClosure7_145 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_145 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A2, A3, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_145 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg2, Arg3, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_145 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_145 ( const MethodObjectParameterClosure7_145 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_145 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A2, A3, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_146 : public virtual IFunction4 <Return, Arg2, Arg3, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_146 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_146 ( const MethodObjectParameterClosure7_146 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_146 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A2, A3, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_146 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg2, Arg3, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_146 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_146 ( const MethodObjectParameterClosure7_146 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_146 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A2, A3, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_147 : public virtual IFunction4 <Return, Arg2, Arg3, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_147 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg4 Default4, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_147 ( const MethodObjectParameterClosure7_147 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_147 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A2, A3, A5, A6 );
				
			};
			
		private:
			
				Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_147 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg2, Arg3, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_147 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg4 Default4, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_147 ( const MethodObjectParameterClosure7_147 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_147 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A2, A3, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_156 : public virtual IFunction4 <Return, Arg2, Arg3, Arg4, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_156 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_156 ( const MethodObjectParameterClosure7_156 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_156 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4, Arg7 A7 ) const
			{
				
				Call ( A2, A3, A4, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_156 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg2, Arg3, Arg4, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_156 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_156 ( const MethodObjectParameterClosure7_156 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_156 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4, Arg7 A7 ) const
			{
				
				Call ( A2, A3, A4, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_157 : public virtual IFunction4 <Return, Arg2, Arg3, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_157 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_157 ( const MethodObjectParameterClosure7_157 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_157 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A2, A3, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_157 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg2, Arg3, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_157 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_157 ( const MethodObjectParameterClosure7_157 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_157 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A2, A3, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_167 : public virtual IFunction4 <Return, Arg2, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_167 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_167 ( const MethodObjectParameterClosure7_167 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_167 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A2, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_167 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg2, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_167 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_167 ( const MethodObjectParameterClosure7_167 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_167 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A2, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_234 : public virtual IFunction4 <Return, Arg1, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_234 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure7_234 ( const MethodObjectParameterClosure7_234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_234 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_234 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg1, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_234 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure7_234 ( const MethodObjectParameterClosure7_234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_234 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_235 : public virtual IFunction4 <Return, Arg1, Arg4, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_235 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_235 ( const MethodObjectParameterClosure7_235 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_235 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A4, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_235 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg1, Arg4, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_235 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_235 ( const MethodObjectParameterClosure7_235 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_235 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A4, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_236 : public virtual IFunction4 <Return, Arg1, Arg4, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_236 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg3 Default3, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_236 ( const MethodObjectParameterClosure7_236 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_236 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A1, A4, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_236 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg1, Arg4, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_236 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg3 Default3, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_236 ( const MethodObjectParameterClosure7_236 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_236 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A1, A4, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_237 : public virtual IFunction4 <Return, Arg1, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_237 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg3 Default3, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_237 ( const MethodObjectParameterClosure7_237 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_237 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_237 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg1, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_237 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg3 Default3, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_237 ( const MethodObjectParameterClosure7_237 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_237 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_245 : public virtual IFunction4 <Return, Arg1, Arg3, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_245 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_245 ( const MethodObjectParameterClosure7_245 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_245 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A3, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_245 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg1, Arg3, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_245 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_245 ( const MethodObjectParameterClosure7_245 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_245 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A3, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_246 : public virtual IFunction4 <Return, Arg1, Arg3, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_246 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_246 ( const MethodObjectParameterClosure7_246 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_246 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A1, A3, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_246 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg1, Arg3, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_246 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_246 ( const MethodObjectParameterClosure7_246 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_246 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A1, A3, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_247 : public virtual IFunction4 <Return, Arg1, Arg3, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_247 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg4 Default4, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_247 ( const MethodObjectParameterClosure7_247 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_247 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A3, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_247 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg1, Arg3, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_247 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg4 Default4, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_247 ( const MethodObjectParameterClosure7_247 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_247 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A3, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_256 : public virtual IFunction4 <Return, Arg1, Arg3, Arg4, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_256 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_256 ( const MethodObjectParameterClosure7_256 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_256 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4, Arg7 A7 ) const
			{
				
				Call ( A1, A3, A4, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_256 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg1, Arg3, Arg4, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_256 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_256 ( const MethodObjectParameterClosure7_256 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_256 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4, Arg7 A7 ) const
			{
				
				Call ( A1, A3, A4, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_257 : public virtual IFunction4 <Return, Arg1, Arg3, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_257 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_257 ( const MethodObjectParameterClosure7_257 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_257 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A1, A3, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_257 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg1, Arg3, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_257 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_257 ( const MethodObjectParameterClosure7_257 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_257 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A1, A3, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_267 : public virtual IFunction4 <Return, Arg1, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_267 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_267 ( const MethodObjectParameterClosure7_267 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_267 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A1, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_267 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg1, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_267 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_267 ( const MethodObjectParameterClosure7_267 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_267 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A1, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_345 : public virtual IFunction4 <Return, Arg1, Arg2, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_345 ( const MethodObjectParameterClosure7_345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_345 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_345 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg1, Arg2, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_345 ( const MethodObjectParameterClosure7_345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_345 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_346 : public virtual IFunction4 <Return, Arg1, Arg2, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_346 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg3 Default3, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_346 ( const MethodObjectParameterClosure7_346 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_346 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_346 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg1, Arg2, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_346 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg3 Default3, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_346 ( const MethodObjectParameterClosure7_346 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_346 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_347 : public virtual IFunction4 <Return, Arg1, Arg2, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_347 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg3 Default3, Arg4 Default4, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_347 ( const MethodObjectParameterClosure7_347 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_347 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_347 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg1, Arg2, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_347 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg3 Default3, Arg4 Default4, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_347 ( const MethodObjectParameterClosure7_347 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_347 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_356 : public virtual IFunction4 <Return, Arg1, Arg2, Arg4, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_356 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg3 Default3, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_356 ( const MethodObjectParameterClosure7_356 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_356 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A4, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_356 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg1, Arg2, Arg4, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_356 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg3 Default3, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_356 ( const MethodObjectParameterClosure7_356 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_356 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A4, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_357 : public virtual IFunction4 <Return, Arg1, Arg2, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_357 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg3 Default3, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_357 ( const MethodObjectParameterClosure7_357 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_357 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg3 Default3;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_357 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg1, Arg2, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_357 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg3 Default3, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_357 ( const MethodObjectParameterClosure7_357 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_357 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg3 Default3;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_367 : public virtual IFunction4 <Return, Arg1, Arg2, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_367 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg3 Default3, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_367 ( const MethodObjectParameterClosure7_367 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_367 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A1, A2, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg3 Default3;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_367 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg1, Arg2, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_367 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg3 Default3, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_367 ( const MethodObjectParameterClosure7_367 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_367 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A1, A2, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg3 Default3;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_456 : public virtual IFunction4 <Return, Arg1, Arg2, Arg3, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_456 ( const MethodObjectParameterClosure7_456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_456 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A3, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_456 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg1, Arg2, Arg3, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_456 ( const MethodObjectParameterClosure7_456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_456 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A3, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_457 : public virtual IFunction4 <Return, Arg1, Arg2, Arg3, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_457 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg4 Default4, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_457 ( const MethodObjectParameterClosure7_457 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_457 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A3, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg4 Default4;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_457 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg1, Arg2, Arg3, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_457 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg4 Default4, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_457 ( const MethodObjectParameterClosure7_457 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_457 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A3, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg4 Default4;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_467 : public virtual IFunction4 <Return, Arg1, Arg2, Arg3, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_467 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg4 Default4, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_467 ( const MethodObjectParameterClosure7_467 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_467 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( A1, A2, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg4 Default4;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_467 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg1, Arg2, Arg3, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_467 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg4 Default4, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_467 ( const MethodObjectParameterClosure7_467 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_467 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( A1, A2, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg4 Default4;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_567 : public virtual IFunction4 <Return, Arg1, Arg2, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure7_567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_567 ( const MethodObjectParameterClosure7_567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_567 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A1, A2, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_567 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction4 <Return, Arg1, Arg2, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure7_567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_567 ( const MethodObjectParameterClosure7_567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_567 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A1, A2, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1234 : public virtual IFunction3 <Return, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_1234 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure7_1234 ( const MethodObjectParameterClosure7_1234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1234 ()
			{
			};
			
			inline Return Call ( Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1234 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg5, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_1234 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodObjectParameterClosure7_1234 ( const MethodObjectParameterClosure7_1234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1234 ()
			{
			};
			
			inline Return Call ( Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, A5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg5 A5, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A5, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1235 : public virtual IFunction3 <Return, Arg4, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_1235 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_1235 ( const MethodObjectParameterClosure7_1235 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1235 ()
			{
			};
			
			inline Return Call ( Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
					return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A4, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1235 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg4, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_1235 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_1235 ( const MethodObjectParameterClosure7_1235 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1235 ()
			{
			};
			
			inline Return Call ( Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg4 A4, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A4, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1236 : public virtual IFunction3 <Return, Arg4, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_1236 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_1236 ( const MethodObjectParameterClosure7_1236 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1236 ()
			{
			};
			
			inline Return Call ( Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A4, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1236 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg4, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_1236 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_1236 ( const MethodObjectParameterClosure7_1236 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1236 ()
			{
			};
			
			inline Return Call ( Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg4 A4, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A4, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1237 : public virtual IFunction3 <Return, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_1237 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_1237 ( const MethodObjectParameterClosure7_1237 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1237 ()
			{
			};
			
			inline Return Call ( Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1237 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_1237 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_1237 ( const MethodObjectParameterClosure7_1237 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1237 ()
			{
			};
			
			inline Return Call ( Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1245 : public virtual IFunction3 <Return, Arg3, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_1245 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_1245 ( const MethodObjectParameterClosure7_1245 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1245 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A3, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1245 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg3, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_1245 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_1245 ( const MethodObjectParameterClosure7_1245 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1245 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A3, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1246 : public virtual IFunction3 <Return, Arg3, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_1246 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_1246 ( const MethodObjectParameterClosure7_1246 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1246 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A3, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1246 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg3, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_1246 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_1246 ( const MethodObjectParameterClosure7_1246 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1246 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A3, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1247 : public virtual IFunction3 <Return, Arg3, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_1247 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_1247 ( const MethodObjectParameterClosure7_1247 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1247 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A3, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1247 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg3, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_1247 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_1247 ( const MethodObjectParameterClosure7_1247 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1247 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A3, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1256 : public virtual IFunction3 <Return, Arg3, Arg4, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_1256 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_1256 ( const MethodObjectParameterClosure7_1256 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1256 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4, Arg7 A7 ) const
			{
				
				Call ( A3, A4, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1256 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg3, Arg4, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_1256 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_1256 ( const MethodObjectParameterClosure7_1256 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1256 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4, Arg7 A7 ) const
			{
				
				Call ( A3, A4, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1257 : public virtual IFunction3 <Return, Arg3, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_1257 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_1257 ( const MethodObjectParameterClosure7_1257 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1257 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A3, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1257 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg3, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_1257 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_1257 ( const MethodObjectParameterClosure7_1257 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1257 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A3, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1267 : public virtual IFunction3 <Return, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_1267 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_1267 ( const MethodObjectParameterClosure7_1267 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1267 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1267 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_1267 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_1267 ( const MethodObjectParameterClosure7_1267 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1267 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1345 : public virtual IFunction3 <Return, Arg2, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_1345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_1345 ( const MethodObjectParameterClosure7_1345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1345 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A2, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1345 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg2, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_1345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_1345 ( const MethodObjectParameterClosure7_1345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1345 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A2, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1346 : public virtual IFunction3 <Return, Arg2, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_1346 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_1346 ( const MethodObjectParameterClosure7_1346 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1346 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A2, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1346 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg2, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_1346 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_1346 ( const MethodObjectParameterClosure7_1346 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1346 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A2, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1347 : public virtual IFunction3 <Return, Arg2, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_1347 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_1347 ( const MethodObjectParameterClosure7_1347 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1347 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A2, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1347 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg2, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_1347 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_1347 ( const MethodObjectParameterClosure7_1347 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1347 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A2, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1356 : public virtual IFunction3 <Return, Arg2, Arg4, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_1356 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg3 Default3, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_1356 ( const MethodObjectParameterClosure7_1356 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1356 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4, Arg7 A7 ) const
			{
				
				Call ( A2, A4, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1356 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg2, Arg4, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_1356 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg3 Default3, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_1356 ( const MethodObjectParameterClosure7_1356 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1356 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4, Arg7 A7 ) const
			{
				
				Call ( A2, A4, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1357 : public virtual IFunction3 <Return, Arg2, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_1357 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg3 Default3, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_1357 ( const MethodObjectParameterClosure7_1357 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1357 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A2, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1357 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg2, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_1357 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg3 Default3, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_1357 ( const MethodObjectParameterClosure7_1357 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1357 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A2, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1367 : public virtual IFunction3 <Return, Arg2, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_1367 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg3 Default3, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_1367 ( const MethodObjectParameterClosure7_1367 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1367 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A2, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1367 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg2, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_1367 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg3 Default3, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_1367 ( const MethodObjectParameterClosure7_1367 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1367 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A2, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1456 : public virtual IFunction3 <Return, Arg2, Arg3, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_1456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_1456 ( const MethodObjectParameterClosure7_1456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1456 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg7 A7 ) const
			{
				
				Call ( A2, A3, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1456 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg2, Arg3, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_1456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_1456 ( const MethodObjectParameterClosure7_1456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1456 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg7 A7 ) const
			{
				
				Call ( A2, A3, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1457 : public virtual IFunction3 <Return, Arg2, Arg3, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_1457 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg4 Default4, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_1457 ( const MethodObjectParameterClosure7_1457 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1457 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg6 A6 ) const
			{
				
				Call ( A2, A3, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1457 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg2, Arg3, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_1457 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg4 Default4, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_1457 ( const MethodObjectParameterClosure7_1457 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1457 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg6 A6 ) const
			{
				
				Call ( A2, A3, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1467 : public virtual IFunction3 <Return, Arg2, Arg3, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_1467 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg4 Default4, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_1467 ( const MethodObjectParameterClosure7_1467 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1467 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( A2, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1467 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg2, Arg3, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_1467 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg4 Default4, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_1467 ( const MethodObjectParameterClosure7_1467 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1467 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( A2, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1567 : public virtual IFunction3 <Return, Arg2, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure7_1567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_1567 ( const MethodObjectParameterClosure7_1567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1567 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A2, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1567 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg2, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure7_1567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_1567 ( const MethodObjectParameterClosure7_1567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1567 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A2, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_2345 : public virtual IFunction3 <Return, Arg1, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_2345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_2345 ( const MethodObjectParameterClosure7_2345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_2345 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_2345 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg1, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_2345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_2345 ( const MethodObjectParameterClosure7_2345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_2345 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A1, A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_2346 : public virtual IFunction3 <Return, Arg1, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_2346 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_2346 ( const MethodObjectParameterClosure7_2346 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_2346 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A1, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_2346 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg1, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_2346 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_2346 ( const MethodObjectParameterClosure7_2346 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_2346 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A1, A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_2347 : public virtual IFunction3 <Return, Arg1, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_2347 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_2347 ( const MethodObjectParameterClosure7_2347 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_2347 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_2347 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg1, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_2347 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_2347 ( const MethodObjectParameterClosure7_2347 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_2347 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A1, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_2356 : public virtual IFunction3 <Return, Arg1, Arg4, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_2356 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg3 Default3, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_2356 ( const MethodObjectParameterClosure7_2356 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_2356 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4, Arg7 A7 ) const
			{
				
				Call ( A1, A4, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_2356 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg1, Arg4, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_2356 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg3 Default3, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_2356 ( const MethodObjectParameterClosure7_2356 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_2356 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4, Arg7 A7 ) const
			{
				
				Call ( A1, A4, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_2357 : public virtual IFunction3 <Return, Arg1, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_2357 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg3 Default3, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_2357 ( const MethodObjectParameterClosure7_2357 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_2357 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A1, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_2357 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg1, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_2357 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg3 Default3, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_2357 ( const MethodObjectParameterClosure7_2357 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_2357 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A1, A4, A6 );
					
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_2367 : public virtual IFunction3 <Return, Arg1, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_2367 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg3 Default3, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_2367 ( const MethodObjectParameterClosure7_2367 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_2367 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A1, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_2367 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg1, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_2367 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg3 Default3, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_2367 ( const MethodObjectParameterClosure7_2367 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_2367 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A1, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_2456 : public virtual IFunction3 <Return, Arg1, Arg3, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_2456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_2456 ( const MethodObjectParameterClosure7_2456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_2456 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg7 A7 ) const
			{
				
				Call ( A1, A3, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_2456 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg1, Arg3, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_2456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_2456 ( const MethodObjectParameterClosure7_2456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_2456 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg7 A7 ) const
			{
				
				Call ( A1, A3, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_2457 : public virtual IFunction3 <Return, Arg1, Arg3, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_2457 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg4 Default4, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_2457 ( const MethodObjectParameterClosure7_2457 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_2457 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg6 A6 ) const
			{
				
				Call ( A1, A3, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_2457 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg1, Arg3, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_2457 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg4 Default4, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_2457 ( const MethodObjectParameterClosure7_2457 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_2457 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg6 A6 ) const
			{
				
				Call ( A1, A3, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_2467 : public virtual IFunction3 <Return, Arg1, Arg3, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_2467 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg4 Default4, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_2467 ( const MethodObjectParameterClosure7_2467 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_2467 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( A1, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_2467 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg1, Arg3, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_2467 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg4 Default4, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_2467 ( const MethodObjectParameterClosure7_2467 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_2467 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( A1, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_2567 : public virtual IFunction3 <Return, Arg1, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure7_2567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_2567 ( const MethodObjectParameterClosure7_2567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_2567 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A1, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_2567 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg1, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure7_2567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_2567 ( const MethodObjectParameterClosure7_2567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_2567 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A1, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_3456 : public virtual IFunction3 <Return, Arg1, Arg2, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_3456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_3456 ( const MethodObjectParameterClosure7_3456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_3456 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_3456 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg1, Arg2, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_3456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_3456 ( const MethodObjectParameterClosure7_3456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_3456 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg7 A7 ) const
			{
				
				Call ( A1, A2, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_3457 : public virtual IFunction3 <Return, Arg1, Arg2, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_3457 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_3457 ( const MethodObjectParameterClosure7_3457 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_3457 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_3457 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg1, Arg2, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_3457 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_3457 ( const MethodObjectParameterClosure7_3457 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_3457 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg6 A6 ) const
			{
				
				Call ( A1, A2, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_3467 : public virtual IFunction3 <Return, Arg1, Arg2, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_3467 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg3 Default3, Arg4 Default4, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_3467 ( const MethodObjectParameterClosure7_3467 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_3467 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg5 A5 ) const
			{
				
				Call ( A1, A2, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_3467 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg1, Arg2, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_3467 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg3 Default3, Arg4 Default4, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_3467 ( const MethodObjectParameterClosure7_3467 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_3467 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg5 A5 ) const
			{
				
				Call ( A1, A2, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_3567 : public virtual IFunction3 <Return, Arg1, Arg2, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure7_3567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg3 Default3, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_3567 ( const MethodObjectParameterClosure7_3567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_3567 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				Call ( A1, A2, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_3567 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg1, Arg2, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure7_3567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg3 Default3, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_3567 ( const MethodObjectParameterClosure7_3567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_3567 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				Call ( A1, A2, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_4567 : public virtual IFunction3 <Return, Arg1, Arg2, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure7_4567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg4 Default4, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_4567 ( const MethodObjectParameterClosure7_4567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_4567 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( A1, A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_4567 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction3 <Return, Arg1, Arg2, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure7_4567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg4 Default4, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_4567 ( const MethodObjectParameterClosure7_4567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_4567 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( A1, A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_12345 : public virtual IFunction2 <Return, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_12345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_12345 ( const MethodObjectParameterClosure7_12345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_12345 ()
			{
			};
			
			inline Return Call ( Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_12345 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction2 <Return, Arg6, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_12345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodObjectParameterClosure7_12345 ( const MethodObjectParameterClosure7_12345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_12345 ()
			{
			};
			
			inline Return Call ( Arg6 A6, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, Default5, A6, A7 );
				
			};
			
			inline Return operator() ( Arg6 A6, Arg7 A7 ) const
			{
				
				Call ( A6, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_12346 : public virtual IFunction2 <Return, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_12346 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_12346 ( const MethodObjectParameterClosure7_12346 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_12346 ()
			{
			};
			
			inline Return Call ( Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_12346 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction2 <Return, Arg5, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_12346 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_12346 ( const MethodObjectParameterClosure7_12346 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_12346 ()
			{
			};
			
			inline Return Call ( Arg5 A5, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, A5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg5 A5, Arg7 A7 ) const
			{
				
				Call ( A5, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_12347 : public virtual IFunction2 <Return, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_12347 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_12347 ( const MethodObjectParameterClosure7_12347 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_12347 ()
			{
			};
			
			inline Return Call ( Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_12347 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction2 <Return, Arg5, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_12347 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_12347 ( const MethodObjectParameterClosure7_12347 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_12347 ()
			{
			};
			
			inline Return Call ( Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, A5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_12356 : public virtual IFunction2 <Return, Arg4, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_12356 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_12356 ( const MethodObjectParameterClosure7_12356 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_12356 ()
			{
			};
			
			inline Return Call ( Arg4 A4, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg4 A4, Arg7 A7 ) const
			{
				
				Call ( A4, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_12356 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction2 <Return, Arg4, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_12356 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_12356 ( const MethodObjectParameterClosure7_12356 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_12356 ()
			{
			};
			
			inline Return Call ( Arg4 A4, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg4 A4, Arg7 A7 ) const
			{
				
				Call ( A4, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_12357 : public virtual IFunction2 <Return, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_12357 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_12357 ( const MethodObjectParameterClosure7_12357 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_12357 ()
			{
			};
			
			inline Return Call ( Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_12357 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction2 <Return, Arg4, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_12357 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_12357 ( const MethodObjectParameterClosure7_12357 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_12357 ()
			{
			};
			
			inline Return Call ( Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_12367 : public virtual IFunction2 <Return, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_12367 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_12367 ( const MethodObjectParameterClosure7_12367 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_12367 ()
			{
			};
			
			inline Return Call ( Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_12367 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction2 <Return, Arg4, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_12367 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_12367 ( const MethodObjectParameterClosure7_12367 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_12367 ()
			{
			};
			
			inline Return Call ( Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_12456 : public virtual IFunction2 <Return, Arg3, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_12456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_12456 ( const MethodObjectParameterClosure7_12456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_12456 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg7 A7 ) const
			{
				
				Call ( A3, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_12456 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction2 <Return, Arg3, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_12456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_12456 ( const MethodObjectParameterClosure7_12456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_12456 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg7 A7 ) const
			{
				
				Call ( A3, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_12457 : public virtual IFunction2 <Return, Arg3, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_12457 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_12457 ( const MethodObjectParameterClosure7_12457 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_12457 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg6 A6 ) const
			{
				
				Call ( A3, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_12457 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction2 <Return, Arg3, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_12457 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_12457 ( const MethodObjectParameterClosure7_12457 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_12457 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg6 A6 ) const
			{
				
				Call ( A3, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_12467 : public virtual IFunction2 <Return, Arg3, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_12467 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_12467 ( const MethodObjectParameterClosure7_12467 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_12467 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_12467 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction2 <Return, Arg3, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_12467 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_12467 ( const MethodObjectParameterClosure7_12467 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_12467 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_12567 : public virtual IFunction2 <Return, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure7_12567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_12567 ( const MethodObjectParameterClosure7_12567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_12567 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_12567 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction2 <Return, Arg3, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure7_12567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_12567 ( const MethodObjectParameterClosure7_12567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_12567 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_13456 : public virtual IFunction2 <Return, Arg2, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_13456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_13456 ( const MethodObjectParameterClosure7_13456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_13456 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg7 A7 ) const
			{
				
				Call ( A2, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_13456 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction2 <Return, Arg2, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_13456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_13456 ( const MethodObjectParameterClosure7_13456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_13456 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg7 A7 ) const
			{
				
				Call ( A2, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_13457 : public virtual IFunction2 <Return, Arg2, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_13457 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_13457 ( const MethodObjectParameterClosure7_13457 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_13457 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg6 A6 ) const
			{
				
				Call ( A2, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_13457 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction2 <Return, Arg2, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_13457 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_13457 ( const MethodObjectParameterClosure7_13457 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_13457 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg6 A6 ) const
			{
				
				Call ( A2, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_13467 : public virtual IFunction2 <Return, Arg2, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_13467 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_13467 ( const MethodObjectParameterClosure7_13467 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_13467 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg5 A5 ) const
			{
				
				Call ( A2, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_13467 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction2 <Return, Arg2, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_13467 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_13467 ( const MethodObjectParameterClosure7_13467 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 ),
					Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_13467 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg5 A5 ) const
			{
				
				Call ( A2, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_13567 : public virtual IFunction2 <Return, Arg2, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure7_13567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg3 Default3, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_13567 ( const MethodObjectParameterClosure7_13567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_13567 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4 ) const
			{
				
				Call ( A2, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_13567 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction2 <Return, Arg2, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure7_13567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg3 Default3, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_13567 ( const MethodObjectParameterClosure7_13567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_13567 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4 ) const
			{
				
				Call ( A2, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_14567 : public virtual IFunction2 <Return, Arg2, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure7_14567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg4 Default4, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_14567 ( const MethodObjectParameterClosure7_14567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_14567 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_14567 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction2 <Return, Arg2, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure7_14567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg4 Default4, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_14567 ( const MethodObjectParameterClosure7_14567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_14567 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_23456 : public virtual IFunction2 <Return, Arg1, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_23456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_23456 ( const MethodObjectParameterClosure7_23456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_23456 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg7 A7 ) const
			{
				
				Call ( A1, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_23456 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction2 <Return, Arg1, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_23456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_23456 ( const MethodObjectParameterClosure7_23456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_23456 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg7 A7 ) const
			{
				
				Call ( A1, A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_23457 : public virtual IFunction2 <Return, Arg1, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_23457 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_23457 ( const MethodObjectParameterClosure7_23457 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_23457 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg6 A6 ) const
			{
				
				Call ( A1, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_23457 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction2 <Return, Arg1, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_23457 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_23457 ( const MethodObjectParameterClosure7_23457 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_23457 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg6 A6 ) const
			{
				
				Call ( A1, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_23467 : public virtual IFunction2 <Return, Arg1, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_23467 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_23467 ( const MethodObjectParameterClosure7_23467 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_23467 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg5 A5 ) const
			{
				
				Call ( A1, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_23467 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction2 <Return, Arg1, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_23467 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_23467 ( const MethodObjectParameterClosure7_23467 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_23467 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg5 A5 ) const
			{
				
				Call ( A1, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_23567 : public virtual IFunction2 <Return, Arg1, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure7_23567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg3 Default3, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_23567 ( const MethodObjectParameterClosure7_23567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_23567 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4 ) const
			{
				
				Call ( A1, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_23567 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction2 <Return, Arg1, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure7_23567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg3 Default3, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_23567 ( const MethodObjectParameterClosure7_23567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_23567 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4 ) const
			{
				
				Call ( A1, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_24567 : public virtual IFunction2 <Return, Arg1, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure7_24567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg4 Default4, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_24567 ( const MethodObjectParameterClosure7_24567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_24567 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3 ) const
			{
				
				Call ( A1, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_24567 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction2 <Return, Arg1, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure7_24567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg4 Default4, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_24567 ( const MethodObjectParameterClosure7_24567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_24567 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3 ) const
			{
				
				Call ( A1, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_34567 : public virtual IFunction2 <Return, Arg1, Arg2>
		{
		public:
			
			inline MethodObjectParameterClosure7_34567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_34567 ( const MethodObjectParameterClosure7_34567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_34567 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2 ) const
			{
				
				Call ( A1, A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_34567 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction2 <Return, Arg1, Arg2>
		{
		public:
			
			inline MethodObjectParameterClosure7_34567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_34567 ( const MethodObjectParameterClosure7_34567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_34567 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2 ) const
			{
				
				Call ( A1, A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_123456 : public virtual IFunction1 <Return, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_123456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_123456 ( const MethodObjectParameterClosure7_123456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_123456 ()
			{
			};
			
			inline Return Call ( Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg7 A7 ) const
			{
				
				Call ( A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_123456 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction1 <Return, Arg7>
		{
		public:
			
			inline MethodObjectParameterClosure7_123456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodObjectParameterClosure7_123456 ( const MethodObjectParameterClosure7_123456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_123456 ()
			{
			};
			
			inline Return Call ( Arg7 A7 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, Default5, Default6, A7 );
				
			};
			
			inline Return operator() ( Arg7 A7 ) const
			{
				
				Call ( A7 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_123457 : public virtual IFunction1 <Return, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_123457 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_123457 ( const MethodObjectParameterClosure7_123457 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_123457 ()
			{
			};
			
			inline Return Call ( Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg6 A6 ) const
			{
				
				Call ( A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_123457 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction1 <Return, Arg6>
		{
		public:
			
			inline MethodObjectParameterClosure7_123457 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_123457 ( const MethodObjectParameterClosure7_123457 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_123457 ()
			{
			};
			
			inline Return Call ( Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, Default5, A6, Default7 );
				
			};
			
			inline Return operator() ( Arg6 A6 ) const
			{
				
				Call ( A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_123467 : public virtual IFunction1 <Return, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_123467 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_123467 ( const MethodObjectParameterClosure7_123467 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_123467 ()
			{
			};
			
			inline Return Call ( Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg5 A5 ) const
			{
				
				Call ( A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_123467 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction1 <Return, Arg5>
		{
		public:
			
			inline MethodObjectParameterClosure7_123467 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_123467 ( const MethodObjectParameterClosure7_123467 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_123467 ()
			{
			};
			
			inline Return Call ( Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, A5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg5 A5 ) const
			{
				
				Call ( A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_123567 : public virtual IFunction1 <Return, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure7_123567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_123567 ( const MethodObjectParameterClosure7_123567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_123567 ()
			{
			};
			
			inline Return Call ( Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg4 A4 ) const
			{
				
				Call ( A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_123567 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction1 <Return, Arg4>
		{
		public:
			
			inline MethodObjectParameterClosure7_123567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_123567 ( const MethodObjectParameterClosure7_123567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_123567 ()
			{
			};
			
			inline Return Call ( Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg4 A4 ) const
			{
				
				Call ( A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_124567 : public virtual IFunction1 <Return, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure7_124567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_124567 ( const MethodObjectParameterClosure7_124567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_124567 ()
			{
			};
			
			inline Return Call ( Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg3 A3 ) const
			{
				
				Call ( A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_124567 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction1 <Return, Arg3>
		{
		public:
			
			inline MethodObjectParameterClosure7_124567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_124567 ( const MethodObjectParameterClosure7_124567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_124567 ()
			{
			};
			
			inline Return Call ( Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg3 A3 ) const
			{
				
				Call ( A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_134567 : public virtual IFunction1 <Return, Arg2>
		{
		public:
			
			inline MethodObjectParameterClosure7_134567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_134567 ( const MethodObjectParameterClosure7_134567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_134567 ()
			{
			};
			
			inline Return Call ( Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2 ) const
			{
				
				Call ( A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_134567 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction1 <Return, Arg2>
		{
		public:
			
			inline MethodObjectParameterClosure7_134567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_134567 ( const MethodObjectParameterClosure7_134567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_134567 ()
			{
			};
			
			inline Return Call ( Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg2 A2 ) const
			{
				
				Call ( A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_234567 : public virtual IFunction1 <Return, Arg1>
		{
		public:
			
			inline MethodObjectParameterClosure7_234567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_234567 ( const MethodObjectParameterClosure7_234567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_234567 ()
			{
			};
			
			inline Return Call ( Arg1 A1 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1 ) const
			{
				
				Call ( A1 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_234567 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction1 <Return, Arg1>
		{
		public:
			
			inline MethodObjectParameterClosure7_234567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_234567 ( const MethodObjectParameterClosure7_234567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_234567 ()
			{
			};
			
			inline Return Call ( Arg1 A1 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() ( Arg1 A1 ) const
			{
				
				Call ( A1 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1234567 : public virtual IFunction <Return>
		{
		public:
			
			inline MethodObjectParameterClosure7_1234567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ), Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_1234567 ( const MethodObjectParameterClosure7_1234567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1234567 ()
			{
			};
			
			inline Return Call () const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() () const
			{
				
				Call ();
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 );
			Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6, typename Arg7>
		class MethodObjectParameterClosure7_1234567 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7> : public virtual IFunction <Return>
		{
		public:
			
			inline MethodObjectParameterClosure7_1234567 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const, const Object * Target, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6, Arg7 Default7 ):
				FAddress ( FAddress ),
				Target ( Target ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 ),
				Default7 ( Default7 )
			{
			};
			
			inline MethodObjectParameterClosure7_1234567 ( const MethodObjectParameterClosure7_1234567 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Target ( CopyFrom.Target ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 ),
				Default7 ( CopyFrom.Default7 )
			{
			};
			
			inline ~MethodObjectParameterClosure7_1234567 ()
			{
			};
			
			inline Return Call () const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, Default5, Default6, Default7 );
				
			};
			
			inline Return operator() () const
			{
				
				Call ();
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7 ) const;
			const Object * Target;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			Arg7 Default7;
			
		};
		
	}
	
}

#endif
