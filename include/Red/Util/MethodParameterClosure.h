#ifndef RED_UTIL_METHODPARAMETERCLOSURE_H
#define RED_UTIL_METHODPARAMETERCLOSURE_H

#include <Red/Util/Util.h>
#include <Red/Util/Method.h>

namespace Red
{
	
	namespace Util
	{
		
		template <typename Object, typename Return, typename Arg1>
		class MethodParameterClosure1_1 : public virtual IMethod <Object, Return>
		{
		public:
			
			inline MethodParameterClosure1_1 ( Return ( Object :: * FAddress ) ( Arg1 ), Arg1 Default1 ):
				FAddress ( FAddress ),
				Default1 ( Default1 )
			{
			};
			
			inline MethodParameterClosure1_1 ( const MethodParameterClosure1_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~MethodParameterClosure1_1 ()
			{
			};
			
			inline Return Call ( Object * Target ) const
			{
				
				return ( Target ->* FAddress ) ( Default1 );
				
			};
			
			inline Return operator() ( Object * Target ) const
			{
				
				Call ( Target );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1 );
			Arg1 Default1;
			
		};
		

		template <typename Object, typename Return, typename Arg1>
		class MethodParameterClosure1_1 <const Object, Return, Arg1>  : public virtual IMethod <const Object, Return>
		{
		public:
			
			inline MethodParameterClosure1_1 ( Return ( Object :: * FAddress ) ( Arg1 ) const, Arg1 Default1 ):
				FAddress ( FAddress ),
				Default1 ( Default1 )
			{
			};
			
			inline MethodParameterClosure1_1 ( const MethodParameterClosure1_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~MethodParameterClosure1_1 ()
			{
			};
			
			inline Return Call ( const Object * Target ) const
			{
				
				return ( Target ->* FAddress ) ( Default1 );
				
			};
			
			inline Return operator() ( const Object * Target ) const
			{
				
				Call ( Target );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1 ) const;
			Arg1 Default1;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2>
		class MethodParameterClosure2_1 : public virtual IMethod1 <Object, Return, Arg2>
		{
		public:
			
			inline MethodParameterClosure2_1 ( Return ( Object :: * FAddress ) ( Arg1, Arg2 ), Arg1 Default1 ):
				FAddress ( FAddress ),
				Default1 ( Default1 )
			{
			};
			
			inline MethodParameterClosure2_1 ( const MethodParameterClosure2_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~MethodParameterClosure2_1 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2 ) const
			{
				
				Call ( Target, A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2 );
			Arg1 Default1;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2>
		class MethodParameterClosure2_1 <const Object, Return, Arg1, Arg2>  : public virtual IMethod1 <const Object, Return, Arg2>
		{
		public:
			
			inline MethodParameterClosure2_1 ( Return ( Object :: * FAddress ) ( Arg1, Arg2 ) const, Arg1 Default1 ):
				FAddress ( FAddress ),
				Default1 ( Default1 )
			{
			};
			
			inline MethodParameterClosure2_1 ( const MethodParameterClosure2_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~MethodParameterClosure2_1 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2 ) const
			{
				
				Call ( Target, A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2 ) const;
			Arg1 Default1;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2>
		class MethodParameterClosure2_2 : public virtual IMethod1 <Object, Return, Arg1>
		{
		public:
			
			inline MethodParameterClosure2_2 ( Return ( Object :: * FAddress ) ( Arg1, Arg2 ), Arg2 Default2 ):
				FAddress ( FAddress ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodParameterClosure2_2 ( const MethodParameterClosure2_2 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodParameterClosure2_2 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1 ) const
			{
				
				Call ( Target, A1 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2 );
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2>
		class MethodParameterClosure2_2 <const Object, Return, Arg1, Arg2>  : public virtual IMethod1 <const Object, Return, Arg1>
		{
		public:
			
			inline MethodParameterClosure2_2 ( Return ( Object :: * FAddress ) ( Arg1, Arg2 ) const, Arg2 Default2 ):
				FAddress ( FAddress ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodParameterClosure2_2 ( const MethodParameterClosure2_2 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodParameterClosure2_2 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1 ) const
			{
				
				Call ( Target, A1 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2 ) const;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2>
		class MethodParameterClosure2_12 : public virtual IMethod <Object, Return>
		{
		public:
			
			inline MethodParameterClosure2_12 ( Return ( Object :: * FAddress ) ( Arg1, Arg2 ), Arg1 Default1, Arg2 Default2 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodParameterClosure2_12 ( const MethodParameterClosure2_12 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodParameterClosure2_12 ()
			{
			};
			
			inline Return Call ( Object * Target ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2 );
				
			};
			
			inline Return operator() ( Object * Target ) const
			{
				
				Call ( Target );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2 );
			Arg1 Default1;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2>
		class MethodParameterClosure2_12 <const Object, Return, Arg1, Arg2>  : public virtual IMethod <const Object, Return>
		{
		public:
			
			inline MethodParameterClosure2_12 ( Return ( Object :: * FAddress ) ( Arg1, Arg2 ) const, Arg1 Default1, Arg2 Default2 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodParameterClosure2_12 ( const MethodParameterClosure2_12 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodParameterClosure2_12 ()
			{
			};
			
			inline Return Call ( const Object * Target ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2 );
				
			};
			
			inline Return operator() ( const Object * Target ) const
			{
				
				Call ( Target );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2 ) const;
			Arg1 Default1;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodParameterClosure3_1 : public virtual IMethod2 <Object, Return, Arg2, Arg3>
		{
		public:
			
			inline MethodParameterClosure3_1 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ), Arg1 Default1 ):
				FAddress ( FAddress ),
				Default1 ( Default1 )
			{
			};
			
			inline MethodParameterClosure3_1 ( const MethodParameterClosure3_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~MethodParameterClosure3_1 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( Target, A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 );
			Arg1 Default1;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodParameterClosure3_1 <const Object, Return, Arg1, Arg2, Arg3>  : public virtual IMethod2 <const Object, Return, Arg2, Arg3>
		{
		public:
			
			inline MethodParameterClosure3_1 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ) const, Arg1 Default1 ):
				FAddress ( FAddress ),
				Default1 ( Default1 )
			{
			};
			
			inline MethodParameterClosure3_1 ( const MethodParameterClosure3_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~MethodParameterClosure3_1 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( Target, A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ) const;
			Arg1 Default1;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodParameterClosure3_2 : public virtual IMethod2 <Object, Return, Arg1, Arg3>
		{
		public:
			
			inline MethodParameterClosure3_2 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ), Arg2 Default2 ):
				FAddress ( FAddress ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodParameterClosure3_2 ( const MethodParameterClosure3_2 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodParameterClosure3_2 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg3 A3 ) const
			{
				
				Call ( Target, A1, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 );
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodParameterClosure3_2 <const Object, Return, Arg1, Arg2, Arg3>  : public virtual IMethod2 <const Object, Return, Arg1, Arg3>
		{
		public:
			
			inline MethodParameterClosure3_2 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ) const, Arg2 Default2 ):
				FAddress ( FAddress ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodParameterClosure3_2 ( const MethodParameterClosure3_2 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodParameterClosure3_2 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg3 A3 ) const
			{
				
				Call ( Target, A1, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ) const;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodParameterClosure3_3 : public virtual IMethod2 <Object, Return, Arg1, Arg2>
		{
		public:
			
			inline MethodParameterClosure3_3 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ), Arg3 Default3 ):
				FAddress ( FAddress ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure3_3 ( const MethodParameterClosure3_3 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure3_3 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2 ) const
			{
				
				Call ( Target, A1, A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 );
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodParameterClosure3_3 <const Object, Return, Arg1, Arg2, Arg3>  : public virtual IMethod2 <const Object, Return, Arg1, Arg2>
		{
		public:
			
			inline MethodParameterClosure3_3 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ) const, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure3_3 ( const MethodParameterClosure3_3 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure3_3 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2 ) const
			{
				
				Call ( Target, A1, A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ) const;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodParameterClosure3_12 : public virtual IMethod1 <Object, Return, Arg3>
		{
		public:
			
			inline MethodParameterClosure3_12 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ), Arg1 Default1, Arg2 Default2 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodParameterClosure3_12 ( const MethodParameterClosure3_12 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodParameterClosure3_12 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3 );
				
			};
			
			inline Return operator() ( Object * Target, Arg3 A3 ) const
			{
				
				Call ( Target, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 );
			Arg1 Default1;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodParameterClosure3_12 <const Object, Return, Arg1, Arg2, Arg3>  : public virtual IMethod1 <const Object, Return, Arg3>
		{
		public:
			
			inline MethodParameterClosure3_12 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ) const, Arg1 Default1, Arg2 Default2 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodParameterClosure3_12 ( const MethodParameterClosure3_12 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodParameterClosure3_12 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg3 A3 ) const
			{
				
				Call ( Target, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ) const;
			Arg1 Default1;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodParameterClosure3_13 : public virtual IMethod1 <Object, Return, Arg2>
		{
		public:
			
			inline MethodParameterClosure3_13 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ), Arg1 Default1, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure3_13 ( const MethodParameterClosure3_13 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure3_13 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2 ) const
			{
				
				Call ( Target, A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 );
			Arg1 Default1;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodParameterClosure3_13 <const Object, Return, Arg1, Arg2, Arg3>  : public virtual IMethod1 <const Object, Return, Arg2>
		{
		public:
			
			inline MethodParameterClosure3_13 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ) const, Arg1 Default1, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure3_13 ( const MethodParameterClosure3_13 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure3_13 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2 ) const
			{
				
				Call ( Target, A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ) const;
			Arg1 Default1;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodParameterClosure3_23 : public virtual IMethod1 <Object, Return, Arg1>
		{
		public:
			
			inline MethodParameterClosure3_23 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ), Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure3_23 ( const MethodParameterClosure3_23 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure3_23 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1 ) const
			{
				
				Call ( Target, A1 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 );
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodParameterClosure3_23 <const Object, Return, Arg1, Arg2, Arg3>  : public virtual IMethod1 <const Object, Return, Arg1>
		{
		public:
			
			inline MethodParameterClosure3_23 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ) const, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure3_23 ( const MethodParameterClosure3_23 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure3_23 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1 ) const
			{
				
				Call ( Target, A1 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ) const;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodParameterClosure3_123 : public virtual IMethod <Object, Return>
		{
		public:
			
			inline MethodParameterClosure3_123 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ), Arg1 Default1, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure3_123 ( const MethodParameterClosure3_123 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure3_123 ()
			{
			};
			
			inline Return Call ( Object * Target ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3 );
				
			};
			
			inline Return operator() ( Object * Target ) const
			{
				
				Call ( Target );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3>
		class MethodParameterClosure3_123 <const Object, Return, Arg1, Arg2, Arg3>  : public virtual IMethod <const Object, Return>
		{
		public:
			
			inline MethodParameterClosure3_123 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ) const, Arg1 Default1, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure3_123 ( const MethodParameterClosure3_123 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure3_123 ()
			{
			};
			
			inline Return Call ( const Object * Target ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3 );
				
			};
			
			inline Return operator() ( const Object * Target ) const
			{
				
				Call ( Target );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3 ) const;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_1 : public virtual IMethod3 <Object, Return, Arg2, Arg3, Arg4>
		{
		public:
			
			inline MethodParameterClosure4_1 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg1 Default1 ):
				FAddress ( FAddress ),
				Default1 ( Default1 )
			{
			};
			
			inline MethodParameterClosure4_1 ( const MethodParameterClosure4_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~MethodParameterClosure4_1 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( Target, A2, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg1 Default1;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_1 <const Object, Return, Arg1, Arg2, Arg3, Arg4>  : public virtual IMethod3 <const Object, Return, Arg2, Arg3, Arg4>
		{
		public:
			
			inline MethodParameterClosure4_1 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, Arg1 Default1 ):
				FAddress ( FAddress ),
				Default1 ( Default1 )
			{
			};
			
			inline MethodParameterClosure4_1 ( const MethodParameterClosure4_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~MethodParameterClosure4_1 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( Target, A2, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			Arg1 Default1;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_2 : public virtual IMethod3 <Object, Return, Arg1, Arg3, Arg4>
		{
		public:
			
			inline MethodParameterClosure4_2 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg2 Default2 ):
				FAddress ( FAddress ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodParameterClosure4_2 ( const MethodParameterClosure4_2 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodParameterClosure4_2 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( Target, A1, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_2 <const Object, Return, Arg1, Arg2, Arg3, Arg4>  : public virtual IMethod3 <const Object, Return, Arg1, Arg3, Arg4>
		{
		public:
			
			inline MethodParameterClosure4_2 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, Arg2 Default2 ):
				FAddress ( FAddress ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodParameterClosure4_2 ( const MethodParameterClosure4_2 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodParameterClosure4_2 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( Target, A1, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_3 : public virtual IMethod3 <Object, Return, Arg1, Arg2, Arg4>
		{
		public:
			
			inline MethodParameterClosure4_3 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg3 Default3 ):
				FAddress ( FAddress ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure4_3 ( const MethodParameterClosure4_3 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure4_3 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				Call ( Target, A1, A2, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_3 <const Object, Return, Arg1, Arg2, Arg3, Arg4>  : public virtual IMethod3 <const Object, Return, Arg1, Arg2, Arg4>
		{
		public:
			
			inline MethodParameterClosure4_3 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure4_3 ( const MethodParameterClosure4_3 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure4_3 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				Call ( Target, A1, A2, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_4 : public virtual IMethod3 <Object, Return, Arg1, Arg2, Arg3>
		{
		public:
			
			inline MethodParameterClosure4_4 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg4 Default4 ):
				FAddress ( FAddress ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure4_4 ( const MethodParameterClosure4_4 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure4_4 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( Target, A1, A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_4 <const Object, Return, Arg1, Arg2, Arg3, Arg4>  : public virtual IMethod3 <const Object, Return, Arg1, Arg2, Arg3>
		{
		public:
			
			inline MethodParameterClosure4_4 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure4_4 ( const MethodParameterClosure4_4 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure4_4 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( Target, A1, A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_12 : public virtual IMethod2 <Object, Return, Arg3, Arg4>
		{
		public:
			
			inline MethodParameterClosure4_12 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg1 Default1, Arg2 Default2 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodParameterClosure4_12 ( const MethodParameterClosure4_12 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodParameterClosure4_12 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4 );
				
			};
			
			inline Return operator() ( Object * Target, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( Target, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg1 Default1;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_12 <const Object, Return, Arg1, Arg2, Arg3, Arg4>  : public virtual IMethod2 <const Object, Return, Arg3, Arg4>
		{
		public:
			
			inline MethodParameterClosure4_12 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, Arg1 Default1, Arg2 Default2 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodParameterClosure4_12 ( const MethodParameterClosure4_12 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodParameterClosure4_12 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( Target, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			Arg1 Default1;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_13 : public virtual IMethod2 <Object, Return, Arg2, Arg4>
		{
		public:
			
			inline MethodParameterClosure4_13 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg1 Default1, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure4_13 ( const MethodParameterClosure4_13 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure4_13 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2, Arg4 A4 ) const
			{
				
				Call ( Target, A2, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg1 Default1;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_13 <const Object, Return, Arg1, Arg2, Arg3, Arg4>  : public virtual IMethod2 <const Object, Return, Arg2, Arg4>
		{
		public:
			
			inline MethodParameterClosure4_13 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, Arg1 Default1, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure4_13 ( const MethodParameterClosure4_13 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure4_13 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2, Arg4 A4 ) const
			{
				
				Call ( Target, A2, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			Arg1 Default1;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_14 : public virtual IMethod2 <Object, Return, Arg2, Arg3>
		{
		public:
			
			inline MethodParameterClosure4_14 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg1 Default1, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure4_14 ( const MethodParameterClosure4_14 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure4_14 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( Target, A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg1 Default1;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_14 <const Object, Return, Arg1, Arg2, Arg3, Arg4>  : public virtual IMethod2 <const Object, Return, Arg2, Arg3>
		{
		public:
			
			inline MethodParameterClosure4_14 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, Arg1 Default1, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure4_14 ( const MethodParameterClosure4_14 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure4_14 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( Target, A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			Arg1 Default1;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_23 : public virtual IMethod2 <Object, Return, Arg1, Arg4>
		{
		public:
			
			inline MethodParameterClosure4_23 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure4_23 ( const MethodParameterClosure4_23 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure4_23 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg4 A4 ) const
			{
				
				Call ( Target, A1, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_23 <const Object, Return, Arg1, Arg2, Arg3, Arg4>  : public virtual IMethod2 <const Object, Return, Arg1, Arg4>
		{
		public:
			
			inline MethodParameterClosure4_23 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure4_23 ( const MethodParameterClosure4_23 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure4_23 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg4 A4 ) const
			{
				
				Call ( Target, A1, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_24 : public virtual IMethod2 <Object, Return, Arg1, Arg3>
		{
		public:
			
			inline MethodParameterClosure4_24 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure4_24 ( const MethodParameterClosure4_24 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure4_24 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg3 A3 ) const
			{
				
				Call ( Target, A1, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_24 <const Object, Return, Arg1, Arg2, Arg3, Arg4>  : public virtual IMethod2 <const Object, Return, Arg1, Arg3>
		{
		public:
			
			inline MethodParameterClosure4_24 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure4_24 ( const MethodParameterClosure4_24 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure4_24 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg3 A3 ) const
			{
				
				Call ( Target, A1, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_34 : public virtual IMethod2 <Object, Return, Arg1, Arg2>
		{
		public:
			
			inline MethodParameterClosure4_34 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure4_34 ( const MethodParameterClosure4_34 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure4_34 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2 ) const
			{
				
				Call ( Target, A1, A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_34 <const Object, Return, Arg1, Arg2, Arg3, Arg4>  : public virtual IMethod2 <const Object, Return, Arg1, Arg2>
		{
		public:
			
			inline MethodParameterClosure4_34 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure4_34 ( const MethodParameterClosure4_34 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure4_34 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2 ) const
			{
				
				Call ( Target, A1, A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_123 : public virtual IMethod1 <Object, Return, Arg4>
		{
		public:
			
			inline MethodParameterClosure4_123 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg1 Default1, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure4_123 ( const MethodParameterClosure4_123 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure4_123 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4 );
				
			};
			
			inline Return operator() ( Object * Target, Arg4 A4 ) const
			{
				
				Call ( Target, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_123 <const Object, Return, Arg1, Arg2, Arg3, Arg4>  : public virtual IMethod1 <const Object, Return, Arg4>
		{
		public:
			
			inline MethodParameterClosure4_123 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, Arg1 Default1, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure4_123 ( const MethodParameterClosure4_123 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure4_123 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg4 A4 ) const
			{
				
				Call ( Target, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_124 : public virtual IMethod1 <Object, Return, Arg3>
		{
		public:
			
			inline MethodParameterClosure4_124 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg1 Default1, Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure4_124 ( const MethodParameterClosure4_124 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure4_124 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4 );
				
			};
			
			inline Return operator() ( Object * Target, Arg3 A3 ) const
			{
				
				Call ( Target, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_124 <const Object, Return, Arg1, Arg2, Arg3, Arg4>  : public virtual IMethod1 <const Object, Return, Arg3>
		{
		public:
			
			inline MethodParameterClosure4_124 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, Arg1 Default1, Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure4_124 ( const MethodParameterClosure4_124 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure4_124 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg3 A3 ) const
			{
				
				Call ( Target, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_134 : public virtual IMethod1 <Object, Return, Arg2>
		{
		public:
			
			inline MethodParameterClosure4_134 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg1 Default1, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure4_134 ( const MethodParameterClosure4_134 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure4_134 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2 ) const
			{
				
				Call ( Target, A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_134 <const Object, Return, Arg1, Arg2, Arg3, Arg4>  : public virtual IMethod1 <const Object, Return, Arg2>
		{
		public:
			
			inline MethodParameterClosure4_134 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, Arg1 Default1, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure4_134 ( const MethodParameterClosure4_134 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure4_134 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2 ) const
			{
				
				Call ( Target, A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_234 : public virtual IMethod1 <Object, Return, Arg1>
		{
		public:
			
			inline MethodParameterClosure4_234 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure4_234 ( const MethodParameterClosure4_234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure4_234 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1 ) const
			{
				
				Call ( Target, A1 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_234 <const Object, Return, Arg1, Arg2, Arg3, Arg4>  : public virtual IMethod1 <const Object, Return, Arg1>
		{
		public:
			
			inline MethodParameterClosure4_234 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure4_234 ( const MethodParameterClosure4_234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure4_234 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1 ) const
			{
				
				Call ( Target, A1 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_1234 : public virtual IMethod <Object, Return>
		{
		public:
			
			inline MethodParameterClosure4_1234 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure4_1234 ( const MethodParameterClosure4_1234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure4_1234 ()
			{
			};
			
			inline Return Call ( Object * Target ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4 );
				
			};
			
			inline Return operator() ( Object * Target ) const
			{
				
				Call ( Target );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class MethodParameterClosure4_1234 <const Object, Return, Arg1, Arg2, Arg3, Arg4>  : public virtual IMethod <const Object, Return>
		{
		public:
			
			inline MethodParameterClosure4_1234 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure4_1234 ( const MethodParameterClosure4_1234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure4_1234 ()
			{
			};
			
			inline Return Call ( const Object * Target ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4 );
				
			};
			
			inline Return operator() ( const Object * Target ) const
			{
				
				Call ( Target );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ) const;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_1 : public virtual IMethod4 <Object, Return, Arg2, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_1 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1 ):
				FAddress ( FAddress ),
				Default1 ( Default1 )
			{
			};
			
			inline MethodParameterClosure5_1 ( const MethodParameterClosure5_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~MethodParameterClosure5_1 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, A5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A2, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_1 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod4 <const Object, Return, Arg2, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_1 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg1 Default1 ):
				FAddress ( FAddress ),
				Default1 ( Default1 )
			{
			};
			
			inline MethodParameterClosure5_1 ( const MethodParameterClosure5_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~MethodParameterClosure5_1 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, A5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A2, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg1 Default1;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_2 : public virtual IMethod4 <Object, Return, Arg1, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_2 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg2 Default2 ):
				FAddress ( FAddress ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodParameterClosure5_2 ( const MethodParameterClosure5_2 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodParameterClosure5_2 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, A5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_2 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod4 <const Object, Return, Arg1, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_2 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg2 Default2 ):
				FAddress ( FAddress ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodParameterClosure5_2 ( const MethodParameterClosure5_2 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodParameterClosure5_2 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, A5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_3 : public virtual IMethod4 <Object, Return, Arg1, Arg2, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_3 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg3 Default3 ):
				FAddress ( FAddress ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure5_3 ( const MethodParameterClosure5_3 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure5_3 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, A5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A2, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_3 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod4 <const Object, Return, Arg1, Arg2, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_3 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure5_3 ( const MethodParameterClosure5_3 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure5_3 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, A5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A2, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_4 : public virtual IMethod4 <Object, Return, Arg1, Arg2, Arg3, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_4 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg4 Default4 ):
				FAddress ( FAddress ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure5_4 ( const MethodParameterClosure5_4 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure5_4 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, A5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A2, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_4 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod4 <const Object, Return, Arg1, Arg2, Arg3, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_4 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure5_4 ( const MethodParameterClosure5_4 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure5_4 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, A5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A2, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_5 : public virtual IMethod4 <Object, Return, Arg1, Arg2, Arg3, Arg4>
		{
		public:
			
			inline MethodParameterClosure5_5 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg5 Default5 ):
				FAddress ( FAddress ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_5 ( const MethodParameterClosure5_5 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_5 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, Default5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( Target, A1, A2, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_5 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod4 <const Object, Return, Arg1, Arg2, Arg3, Arg4>
		{
		public:
			
			inline MethodParameterClosure5_5 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_5 ( const MethodParameterClosure5_5 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_5 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, Default5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( Target, A1, A2, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_12 : public virtual IMethod3 <Object, Return, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_12 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg2 Default2 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodParameterClosure5_12 ( const MethodParameterClosure5_12 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodParameterClosure5_12 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, A5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_12 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod3 <const Object, Return, Arg3, Arg4, Arg5>
		{
			public:
			
			inline MethodParameterClosure5_12 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg1 Default1, Arg2 Default2 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodParameterClosure5_12 ( const MethodParameterClosure5_12 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodParameterClosure5_12 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, A5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg1 Default1;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_13 : public virtual IMethod3 <Object, Return, Arg2, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_13 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure5_13 ( const MethodParameterClosure5_13 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure5_13 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, A5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A2, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_13 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod3 <const Object, Return, Arg2, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_13 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg1 Default1, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure5_13 ( const MethodParameterClosure5_13 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure5_13 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, A5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A2, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg1 Default1;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_14 : public virtual IMethod3 <Object, Return, Arg2, Arg3, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_14 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure5_14 ( const MethodParameterClosure5_14 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure5_14 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, A5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( Target, A2, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_14 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod3 <const Object, Return, Arg2, Arg3, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_14 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg1 Default1, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure5_14 ( const MethodParameterClosure5_14 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure5_14 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, A5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( Target, A2, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg1 Default1;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_15 : public virtual IMethod3 <Object, Return, Arg2, Arg3, Arg4>
		{
		public:
			
			inline MethodParameterClosure5_15 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_15 ( const MethodParameterClosure5_15 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_15 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, Default5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( Target, A2, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_15 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod3 <const Object, Return, Arg2, Arg3, Arg4>
		{
		public:
			
			inline MethodParameterClosure5_15 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg1 Default1, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_15 ( const MethodParameterClosure5_15 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_15 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, Default5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( Target, A2, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg1 Default1;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_23 : public virtual IMethod3 <Object, Return, Arg1, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_23 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure5_23 ( const MethodParameterClosure5_23 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure5_23 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, A5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_23 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod3 <const Object, Return, Arg1, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_23 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure5_23 ( const MethodParameterClosure5_23 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure5_23 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, A5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_24 : public virtual IMethod3 <Object, Return, Arg1, Arg3, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_24 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure5_24 ( const MethodParameterClosure5_24 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure5_24 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, A5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_24 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod3 <const Object, Return, Arg1, Arg3, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_24 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure5_24 ( const MethodParameterClosure5_24 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure5_24 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, A5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_25 : public virtual IMethod3 <Object, Return, Arg1, Arg3, Arg4>
		{
		public:
			
			inline MethodParameterClosure5_25 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg2 Default2, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_25 ( const MethodParameterClosure5_25 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_25 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, Default5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( Target, A1, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg2 Default2;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_25 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod3 <const Object, Return, Arg1, Arg3, Arg4>
		{
		public:
			
			inline MethodParameterClosure5_25 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg2 Default2, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_25 ( const MethodParameterClosure5_25 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_25 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, Default5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( Target, A1, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg2 Default2;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_34 : public virtual IMethod3 <Object, Return, Arg1, Arg2, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_34 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure5_34 ( const MethodParameterClosure5_34 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure5_34 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, A5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A2, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_34 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod3 <const Object, Return, Arg1, Arg2, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_34 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure5_34 ( const MethodParameterClosure5_34 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure5_34 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, A5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A2, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_35 : public virtual IMethod3 <Object, Return, Arg1, Arg2, Arg4>
		{
		public:
			
			inline MethodParameterClosure5_35 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_35 ( const MethodParameterClosure5_35 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_35 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, Default5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				Call ( Target, A1, A2, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_35 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod3 <const Object, Return, Arg1, Arg2, Arg4>
		{
		public:
			
			inline MethodParameterClosure5_35 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_35 ( const MethodParameterClosure5_35 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_35 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, Default5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				Call ( Target, A1, A2, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_45 : public virtual IMethod3 <Object, Return, Arg1, Arg2, Arg3>
		{
		public:
			
			inline MethodParameterClosure5_45 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_45 ( const MethodParameterClosure5_45 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_45 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( Target, A1, A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_45 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod3 <const Object, Return, Arg1, Arg2, Arg3>
		{
		public:
			
			inline MethodParameterClosure5_45 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_45 ( const MethodParameterClosure5_45 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_45 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, Default5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( Target, A1, A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_123 : public virtual IMethod2 <Object, Return, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_123 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure5_123 ( const MethodParameterClosure5_123 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure5_123 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, A5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_123 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod2 <const Object, Return, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_123 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg1 Default1, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure5_123 ( const MethodParameterClosure5_123 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure5_123 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, A5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_124 : public virtual IMethod2 <Object, Return, Arg3, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_124 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure5_124 ( const MethodParameterClosure5_124 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure5_124 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, A5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( Target, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_124 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod2 <const Object, Return, Arg3, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_124 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg1 Default1, Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure5_124 ( const MethodParameterClosure5_124 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure5_124 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, A5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( Target, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_125 : public virtual IMethod2 <Object, Return, Arg3, Arg4>
		{
		public:
			
			inline MethodParameterClosure5_125 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg2 Default2, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_125 ( const MethodParameterClosure5_125 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_125 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, Default5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( Target, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg2 Default2;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_125 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod2 <const Object, Return, Arg3, Arg4>
		{
		public:
			
			inline MethodParameterClosure5_125 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg1 Default1, Arg2 Default2, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_125 ( const MethodParameterClosure5_125 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_125 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, Default5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( Target, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg1 Default1;
			Arg2 Default2;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_134 : public virtual IMethod2 <Object, Return, Arg2, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_134 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure5_134 ( const MethodParameterClosure5_134 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure5_134 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, A5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2, Arg5 A5 ) const
			{
				
				Call ( Target, A2, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_134 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod2 <const Object, Return, Arg2, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_134 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg1 Default1, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure5_134 ( const MethodParameterClosure5_134 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure5_134 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, A5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2, Arg5 A5 ) const
			{
				
				Call ( Target, A2, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_135 : public virtual IMethod2 <Object, Return, Arg2, Arg4>
		{
		public:
			
			inline MethodParameterClosure5_135 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_135 ( const MethodParameterClosure5_135 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_135 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, Default5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2, Arg4 A4 ) const
			{
				
				Call ( Target, A2, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_135 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod2 <const Object, Return, Arg2, Arg4>
		{
		public:
			
			inline MethodParameterClosure5_135 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg1 Default1, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_135 ( const MethodParameterClosure5_135 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_135 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, Default5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2, Arg4 A4 ) const
			{
				
				Call ( Target, A2, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg1 Default1;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_145 : public virtual IMethod2 <Object, Return, Arg2, Arg3>
		{
		public:
			
			inline MethodParameterClosure5_145 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_145 ( const MethodParameterClosure5_145 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_145 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( Target, A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_145 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod2 <const Object, Return, Arg2, Arg3>
		{
		public:
			
			inline MethodParameterClosure5_145 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg1 Default1, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_145 ( const MethodParameterClosure5_145 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_145 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, Default5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( Target, A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg1 Default1;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_234 : public virtual IMethod2 <Object, Return, Arg1, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_234 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure5_234 ( const MethodParameterClosure5_234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure5_234 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, A5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_234 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod2 <const Object, Return, Arg1, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_234 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure5_234 ( const MethodParameterClosure5_234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure5_234 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, A5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_235 : public virtual IMethod2 <Object, Return, Arg1, Arg4>
		{
		public:
			
			inline MethodParameterClosure5_235 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg2 Default2, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_235 ( const MethodParameterClosure5_235 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_235 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, Default5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg4 A4 ) const
			{
				
				Call ( Target, A1, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_235 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod2 <const Object, Return, Arg1, Arg4>
		{
		public:
			
			inline MethodParameterClosure5_235 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg2 Default2, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_235 ( const MethodParameterClosure5_235 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_235 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, Default5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg4 A4 ) const
			{
				
				Call ( Target, A1, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_245 : public virtual IMethod2 <Object, Return, Arg1, Arg3>
		{
		public:
			
			inline MethodParameterClosure5_245 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg2 Default2, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_245 ( const MethodParameterClosure5_245 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_245 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg3 A3 ) const
			{
				
				Call ( Target, A1, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_245 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod2 <const Object, Return, Arg1, Arg3>
		{
		public:
			
			inline MethodParameterClosure5_245 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg2 Default2, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_245 ( const MethodParameterClosure5_245 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_245 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, Default5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg3 A3 ) const
			{
				
				Call ( Target, A1, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_345 : public virtual IMethod2 <Object, Return, Arg1, Arg2>
		{
		public:
			
			inline MethodParameterClosure5_345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_345 ( const MethodParameterClosure5_345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_345 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2 ) const
			{
				
				Call ( Target, A1, A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_345 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod2 <const Object, Return, Arg1, Arg2>
		{
		public:
			
			inline MethodParameterClosure5_345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_345 ( const MethodParameterClosure5_345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_345 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, Default5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2 ) const
			{
				
				Call ( Target, A1, A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_1234 : public virtual IMethod1 <Object, Return, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_1234 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure5_1234 ( const MethodParameterClosure5_1234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure5_1234 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, A5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg5 A5 ) const
			{
				
				Call ( Target, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_1234 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod1 <const Object, Return, Arg5>
		{
		public:
			
			inline MethodParameterClosure5_1234 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure5_1234 ( const MethodParameterClosure5_1234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure5_1234 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, A5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg5 A5 ) const
			{
				
				Call ( Target, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_1235 : public virtual IMethod1 <Object, Return, Arg4>
		{
		public:
			
			inline MethodParameterClosure5_1235 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_1235 ( const MethodParameterClosure5_1235 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_1235 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, Default5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg4 A4 ) const
			{
				
				Call ( Target, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_1235 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod1 <const Object, Return, Arg4>
		{
		public:
			
			inline MethodParameterClosure5_1235 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_1235 ( const MethodParameterClosure5_1235 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_1235 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, Default5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg4 A4 ) const
			{
				
				Call ( Target, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_1245 : public virtual IMethod1 <Object, Return, Arg3>
		{
		public:
			
			inline MethodParameterClosure5_1245 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_1245 ( const MethodParameterClosure5_1245 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_1245 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg3 A3 ) const
			{
				
				Call ( Target, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_1245 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod1 <const Object, Return, Arg3>
		{
		public:
			
			inline MethodParameterClosure5_1245 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_1245 ( const MethodParameterClosure5_1245 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_1245 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, Default5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg3 A3 ) const
			{
				
				Call ( Target, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_1345 : public virtual IMethod1 <Object, Return, Arg2>
		{
		public:
			
			inline MethodParameterClosure5_1345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_1345 ( const MethodParameterClosure5_1345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_1345 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2 ) const
			{
				
				Call ( Target, A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_1345 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod1 <const Object, Return, Arg2>
		{
		public:
			
			inline MethodParameterClosure5_1345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_1345 ( const MethodParameterClosure5_1345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_1345 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, Default5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2 ) const
			{
				
				Call ( Target, A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_2345 : public virtual IMethod1 <Object, Return, Arg1>
		{
		public:
			
			inline MethodParameterClosure5_2345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_2345 ( const MethodParameterClosure5_2345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_2345 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1 ) const
			{
				
				Call ( Target, A1 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_2345 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod1 <const Object, Return, Arg1>
		{
		public:
			
			inline MethodParameterClosure5_2345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_2345 ( const MethodParameterClosure5_2345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_2345 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, Default5 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1 ) const
			{
				
				Call ( Target, A1 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_12345 : public virtual IMethod <Object, Return>
		{
		public:
			
			inline MethodParameterClosure5_12345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_12345 ( const MethodParameterClosure5_12345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_12345 ()
			{
			};
			
			inline Return Call ( Object * Target ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Object * Target ) const
			{
				
				Call ( Target );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class MethodParameterClosure5_12345 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>  : public virtual IMethod <const Object, Return>
		{
		public:
			
			inline MethodParameterClosure5_12345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure5_12345 ( const MethodParameterClosure5_12345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure5_12345 ()
			{
			};
			
			inline Return Call ( const Object * Target ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, Default5 );
				
			};
			
			inline Return operator() ( const Object * Target ) const
			{
				
				Call ( Target );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ) const;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_1 : public virtual IMethod5 <Object, Return, Arg2, Arg3, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_1 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1 ):
				FAddress ( FAddress ),
				Default1 ( Default1 )
			{
			};
			
			inline MethodParameterClosure6_1 ( const MethodParameterClosure6_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~MethodParameterClosure6_1 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A2, A3, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_1 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod5 <const Object, Return, Arg2, Arg3, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_1 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1 ):
				FAddress ( FAddress ),
				Default1 ( Default1 )
			{
			};
			
			inline MethodParameterClosure6_1 ( const MethodParameterClosure6_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~MethodParameterClosure6_1 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A2, A3, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_2 : public virtual IMethod5 <Object, Return, Arg1, Arg3, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_2 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2 ):
				FAddress ( FAddress ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodParameterClosure6_2 ( const MethodParameterClosure6_2 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodParameterClosure6_2 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A3, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_2 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod5 <const Object, Return, Arg1, Arg3, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_2 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg2 Default2 ):
				FAddress ( FAddress ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodParameterClosure6_2 ( const MethodParameterClosure6_2 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodParameterClosure6_2 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A3, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_3 : public virtual IMethod5 <Object, Return, Arg1, Arg2, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_3 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg3 Default3 ):
				FAddress ( FAddress ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure6_3 ( const MethodParameterClosure6_3 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure6_3 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A2, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_3 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod5 <const Object, Return, Arg1, Arg2, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_3 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure6_3 ( const MethodParameterClosure6_3 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure6_3 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
					
				Call ( Target, A1, A2, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_4 : public virtual IMethod5 <Object, Return, Arg1, Arg2, Arg3, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_4 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg4 Default4 ):
				FAddress ( FAddress ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure6_4 ( const MethodParameterClosure6_4 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure6_4 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A2, A3, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_4 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod5 <const Object, Return, Arg1, Arg2, Arg3, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_4 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure6_4 ( const MethodParameterClosure6_4 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure6_4 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A2, A3, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_5 : public virtual IMethod5 <Object, Return, Arg1, Arg2, Arg3, Arg4, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_5 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg5 Default5 ):
				FAddress ( FAddress ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_5 ( const MethodParameterClosure6_5 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_5 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A2, A3, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_5 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod5 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_5 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_5 ( const MethodParameterClosure6_5 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_5 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A2, A3, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_6 : public virtual IMethod5 <Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_6 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg6 Default6 ):
				FAddress ( FAddress ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_6 ( const MethodParameterClosure6_6 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_6 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A2, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_6 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod5 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_6 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_6 ( const MethodParameterClosure6_6 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_6 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A2, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_12 : public virtual IMethod4 <Object, Return, Arg3, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_12 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodParameterClosure6_12 ( const MethodParameterClosure6_12 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodParameterClosure6_12 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A3, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_12 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod4 <const Object, Return, Arg3, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_12 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg2 Default2 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 )
			{
			};
			
			inline MethodParameterClosure6_12 ( const MethodParameterClosure6_12 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~MethodParameterClosure6_12 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A3, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg2 Default2;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_13 : public virtual IMethod4 <Object, Return, Arg2, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_13 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure6_13 ( const MethodParameterClosure6_13 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure6_13 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A2, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_13 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod4 <const Object, Return, Arg2, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_13 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure6_13 ( const MethodParameterClosure6_13 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure6_13 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A2, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_14 : public virtual IMethod4 <Object, Return, Arg2, Arg3, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_14 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure6_14 ( const MethodParameterClosure6_14 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure6_14 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A2, A3, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_14 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod4 <const Object, Return, Arg2, Arg3, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_14 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure6_14 ( const MethodParameterClosure6_14 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure6_14 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A2, A3, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_15 : public virtual IMethod4 <Object, Return, Arg2, Arg3, Arg4, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_15 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_15 ( const MethodParameterClosure6_15 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_15 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( Target, A2, A3, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_15 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod4 <const Object, Return, Arg2, Arg3, Arg4, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_15 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_15 ( const MethodParameterClosure6_15 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_15 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( Target, A2, A3, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_16 : public virtual IMethod4 <Object, Return, Arg2, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_16 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_16 ( const MethodParameterClosure6_16 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_16 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A2, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_16 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod4 <const Object, Return, Arg2, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_16 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_16 ( const MethodParameterClosure6_16 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_16 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A2, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_23 : public virtual IMethod4 <Object, Return, Arg1, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_23 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure6_23 ( const MethodParameterClosure6_23 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure6_23 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_23 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod4 <const Object, Return, Arg1, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_23 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure6_23 ( const MethodParameterClosure6_23 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure6_23 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_24 : public virtual IMethod4 <Object, Return, Arg1, Arg3, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_24 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure6_24 ( const MethodParameterClosure6_24 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure6_24 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A3, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_24 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod4 <const Object, Return, Arg1, Arg3, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_24 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure6_24 ( const MethodParameterClosure6_24 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure6_24 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A3, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_25 : public virtual IMethod4 <Object, Return, Arg1, Arg3, Arg4, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_25 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_25 ( const MethodParameterClosure6_25 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_25 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A3, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_25 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod4 <const Object, Return, Arg1, Arg3, Arg4, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_25 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg2 Default2, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_25 ( const MethodParameterClosure6_25 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_25 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A3, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg2 Default2;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_26 : public virtual IMethod4 <Object, Return, Arg1, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_26 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_26 ( const MethodParameterClosure6_26 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_26 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_26 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod4 <const Object, Return, Arg1, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_26 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg2 Default2, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_26 ( const MethodParameterClosure6_26 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_26 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg2 Default2;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_34 : public virtual IMethod4 <Object, Return, Arg1, Arg2, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_34 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure6_34 ( const MethodParameterClosure6_34 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure6_34 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A2, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_34 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod4 <const Object, Return, Arg1, Arg2, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_34 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure6_34 ( const MethodParameterClosure6_34 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure6_34 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A2, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_35 : public virtual IMethod4 <Object, Return, Arg1, Arg2, Arg4, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_35 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_35 ( const MethodParameterClosure6_35 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_35 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A2, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_35 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod4 <const Object, Return, Arg1, Arg2, Arg4, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_35 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_35 ( const MethodParameterClosure6_35 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_35 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A2, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_36 : public virtual IMethod4 <Object, Return, Arg1, Arg2, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_36 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg3 Default3, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_36 ( const MethodParameterClosure6_36 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_36 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A2, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg3 Default3;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_36 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod4 <const Object, Return, Arg1, Arg2, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_36 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg3 Default3, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_36 ( const MethodParameterClosure6_36 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_36 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A2, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg3 Default3;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_45 : public virtual IMethod4 <Object, Return, Arg1, Arg2, Arg3, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_45 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_45 ( const MethodParameterClosure6_45 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_45 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A2, A3, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_45 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod4 <const Object, Return, Arg1, Arg2, Arg3, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_45 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_45 ( const MethodParameterClosure6_45 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_45 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A2, A3, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_46 : public virtual IMethod4 <Object, Return, Arg1, Arg2, Arg3, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_46 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_46 ( const MethodParameterClosure6_46 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_46 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A2, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_46 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod4 <const Object, Return, Arg1, Arg2, Arg3, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_46 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_46 ( const MethodParameterClosure6_46 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_46 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A2, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_56 : public virtual IMethod4 <Object, Return, Arg1, Arg2, Arg3, Arg4>
		{
		public:
			
			inline MethodParameterClosure6_56 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_56 ( const MethodParameterClosure6_56 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_56 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( Target, A1, A2, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_56 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod4 <const Object, Return, Arg1, Arg2, Arg3, Arg4>
		{
		public:
			
			inline MethodParameterClosure6_56 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_56 ( const MethodParameterClosure6_56 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_56 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( Target, A1, A2, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_123 : public virtual IMethod3 <Object, Return, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_123 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure6_123 ( const MethodParameterClosure6_123 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure6_123 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_123 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod3 <const Object, Return, Arg4, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_123 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline MethodParameterClosure6_123 ( const MethodParameterClosure6_123 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~MethodParameterClosure6_123 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_124 : public virtual IMethod3 <Object, Return, Arg3, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_124 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure6_124 ( const MethodParameterClosure6_124 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure6_124 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A3, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_124 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod3 <const Object, Return, Arg3, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_124 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure6_124 ( const MethodParameterClosure6_124 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure6_124 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A3, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_125 : public virtual IMethod3 <Object, Return, Arg3, Arg4, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_125 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_125 ( const MethodParameterClosure6_125 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_125 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( Target, A3, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_125 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod3 <const Object, Return, Arg3, Arg4, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_125 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg2 Default2, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_125 ( const MethodParameterClosure6_125 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_125 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( Target, A3, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg2 Default2;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_126 : public virtual IMethod3 <Object, Return, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_126 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_126 ( const MethodParameterClosure6_126 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_126 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_126 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod3 <const Object, Return, Arg3, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_126 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg2 Default2, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_126 ( const MethodParameterClosure6_126 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_126 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg2 Default2;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_134 : public virtual IMethod3 <Object, Return, Arg2, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_134 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure6_134 ( const MethodParameterClosure6_134 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure6_134 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A2, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_134 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod3 <const Object, Return, Arg2, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_134 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure6_134 ( const MethodParameterClosure6_134 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure6_134 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A2, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_135 : public virtual IMethod3 <Object, Return, Arg2, Arg4, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_135 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_135 ( const MethodParameterClosure6_135 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_135 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( Target, A2, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_135 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod3 <const Object, Return, Arg2, Arg4, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_135 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_135 ( const MethodParameterClosure6_135 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_135 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( Target, A2, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_136 : public virtual IMethod3 <Object, Return, Arg2, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_136 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg3 Default3, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_136 ( const MethodParameterClosure6_136 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_136 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A2, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg3 Default3;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_136 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod3 <const Object, Return, Arg2, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_136 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg3 Default3, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_136 ( const MethodParameterClosure6_136 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_136 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A2, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg3 Default3;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_145 : public virtual IMethod3 <Object, Return, Arg2, Arg3, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_145 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_145 ( const MethodParameterClosure6_145 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_145 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2, Arg3 A3, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2, Arg3 A3, Arg6 A6 ) const
			{
				
				Call ( Target, A2, A3, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_145 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod3 <const Object, Return, Arg2, Arg3, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_145 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_145 ( const MethodParameterClosure6_145 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_145 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2, Arg3 A3, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2, Arg3 A3, Arg6 A6 ) const
			{
				
				Call ( Target, A2, A3, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_146 : public virtual IMethod3 <Object, Return, Arg2, Arg3, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_146 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_146 ( const MethodParameterClosure6_146 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_146 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( Target, A2, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_146 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod3 <const Object, Return, Arg2, Arg3, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_146 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_146 ( const MethodParameterClosure6_146 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_146 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( Target, A2, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_156 : public virtual IMethod3 <Object, Return, Arg2, Arg3, Arg4>
		{
		public:
			
			inline MethodParameterClosure6_156 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_156 ( const MethodParameterClosure6_156 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_156 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( Target, A2, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_156 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod3 <const Object, Return, Arg2, Arg3, Arg4>
		{
		public:
			
			inline MethodParameterClosure6_156 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_156 ( const MethodParameterClosure6_156 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_156 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( Target, A2, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_234 : public virtual IMethod3 <Object, Return, Arg1, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_234 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure6_234 ( const MethodParameterClosure6_234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure6_234 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A5, A6 );
				
			};
				
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_234 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod3 <const Object, Return, Arg1, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_234 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure6_234 ( const MethodParameterClosure6_234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure6_234 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_235 : public virtual IMethod3 <Object, Return, Arg1, Arg4, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_235 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_235 ( const MethodParameterClosure6_235 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_235 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_235 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod3 <const Object, Return, Arg1, Arg4, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_235 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg2 Default2, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_235 ( const MethodParameterClosure6_235 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_235 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_236 : public virtual IMethod3 <Object, Return, Arg1, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_236 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg3 Default3, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_236 ( const MethodParameterClosure6_236 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_236 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg3 Default3;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_236 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod3 <const Object, Return, Arg1, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_236 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg2 Default2, Arg3 Default3, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_236 ( const MethodParameterClosure6_236 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_236 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg2 Default2;
			Arg3 Default3;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_245 : public virtual IMethod3 <Object, Return, Arg1, Arg3, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_245 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_245 ( const MethodParameterClosure6_245 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_245 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg3 A3, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg3 A3, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A3, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_245 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod3 <const Object, Return, Arg1, Arg3, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_245 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg2 Default2, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_245 ( const MethodParameterClosure6_245 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_245 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg3 A3, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg3 A3, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A3, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_246 : public virtual IMethod3 <Object, Return, Arg1, Arg3, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_246 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_246 ( const MethodParameterClosure6_246 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_246 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_246 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod3 <const Object, Return, Arg1, Arg3, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_246 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg2 Default2, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_246 ( const MethodParameterClosure6_246 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_246 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg2 Default2;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_256 : public virtual IMethod3 <Object, Return, Arg1, Arg3, Arg4>
		{
		public:
			
			inline MethodParameterClosure6_256 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_256 ( const MethodParameterClosure6_256 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_256 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( Target, A1, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_256 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod3 <const Object, Return, Arg1, Arg3, Arg4>
		{
		public:
			
			inline MethodParameterClosure6_256 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg2 Default2, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_256 ( const MethodParameterClosure6_256 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_256 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( Target, A1, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg2 Default2;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_345 : public virtual IMethod3 <Object, Return, Arg1, Arg2, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_345 ( const MethodParameterClosure6_345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_345 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A2, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_345 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod3 <const Object, Return, Arg1, Arg2, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_345 ( const MethodParameterClosure6_345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_345 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A2, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_346 : public virtual IMethod3 <Object, Return, Arg1, Arg2, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_346 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg3 Default3, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_346 ( const MethodParameterClosure6_346 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_346 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A2, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_346 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod3 <const Object, Return, Arg1, Arg2, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_346 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg3 Default3, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_346 ( const MethodParameterClosure6_346 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_346 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A2, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_356 : public virtual IMethod3 <Object, Return, Arg1, Arg2, Arg4>
		{
		public:
			
			inline MethodParameterClosure6_356 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg3 Default3, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_356 ( const MethodParameterClosure6_356 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_356 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				Call ( Target, A1, A2, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_356 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod3 <const Object, Return, Arg1, Arg2, Arg4>
		{
		public:
			
			inline MethodParameterClosure6_356 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg3 Default3, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_356 ( const MethodParameterClosure6_356 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_356 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				Call ( Target, A1, A2, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_456 : public virtual IMethod3 <Object, Return, Arg1, Arg2, Arg3>
		{
		public:
			
			inline MethodParameterClosure6_456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_456 ( const MethodParameterClosure6_456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_456 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( Target, A1, A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_456 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod3 <const Object, Return, Arg1, Arg2, Arg3>
		{
		public:
			
			inline MethodParameterClosure6_456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_456 ( const MethodParameterClosure6_456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_456 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, A3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( Target, A1, A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_1234 : public virtual IMethod2 <Object, Return, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_1234 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure6_1234 ( const MethodParameterClosure6_1234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure6_1234 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_1234 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod2 <const Object, Return, Arg5, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_1234 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline MethodParameterClosure6_1234 ( const MethodParameterClosure6_1234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~MethodParameterClosure6_1234 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg5 A5, Arg6 A6 ) const
			{
				
				Call ( Target, A5, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_1235 : public virtual IMethod2 <Object, Return, Arg4, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_1235 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_1235 ( const MethodParameterClosure6_1235 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_1235 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( Target, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_1235 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod2 <const Object, Return, Arg4, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_1235 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_1235 ( const MethodParameterClosure6_1235 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_1235 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg4 A4, Arg6 A6 ) const
			{
				
				Call ( Target, A4, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_1236 : public virtual IMethod2 <Object, Return, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_1236 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_1236 ( const MethodParameterClosure6_1236 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_1236 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_1236 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod2 <const Object, Return, Arg4, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_1236 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_1236 ( const MethodParameterClosure6_1236 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_1236 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg4 A4, Arg5 A5 ) const
			{
				
				Call ( Target, A4, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_1245 : public virtual IMethod2 <Object, Return, Arg3, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_1245 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_1245 ( const MethodParameterClosure6_1245 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_1245 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg3 A3, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg3 A3, Arg6 A6 ) const
			{
				
				Call ( Target, A3, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_1245 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod2 <const Object, Return, Arg3, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_1245 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_1245 ( const MethodParameterClosure6_1245 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_1245 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg3 A3, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg3 A3, Arg6 A6 ) const
			{
				
				Call ( Target, A3, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_1246 : public virtual IMethod2 <Object, Return, Arg3, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_1246 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_1246 ( const MethodParameterClosure6_1246 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_1246 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( Target, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_1246 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod2 <const Object, Return, Arg3, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_1246 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_1246 ( const MethodParameterClosure6_1246 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_1246 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg3 A3, Arg5 A5 ) const
			{
				
				Call ( Target, A3, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_1256 : public virtual IMethod2 <Object, Return, Arg3, Arg4>
		{
		public:
			
			inline MethodParameterClosure6_1256 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_1256 ( const MethodParameterClosure6_1256 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_1256 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( Target, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_1256 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod2 <const Object, Return, Arg3, Arg4>
		{
		public:
			
			inline MethodParameterClosure6_1256 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg2 Default2, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_1256 ( const MethodParameterClosure6_1256 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_1256 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg3 A3, Arg4 A4 ) const
			{
				
				Call ( Target, A3, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg2 Default2;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_1345 : public virtual IMethod2 <Object, Return, Arg2, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_1345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_1345 ( const MethodParameterClosure6_1345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_1345 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2, Arg6 A6 ) const
			{
				
				Call ( Target, A2, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_1345 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod2 <const Object, Return, Arg2, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_1345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_1345 ( const MethodParameterClosure6_1345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_1345 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2, Arg6 A6 ) const
			{
				
				Call ( Target, A2, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_1346 : public virtual IMethod2 <Object, Return, Arg2, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_1346 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_1346 ( const MethodParameterClosure6_1346 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_1346 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2, Arg5 A5 ) const
			{
				
				Call ( Target, A2, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_1346 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod2 <const Object, Return, Arg2, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_1346 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_1346 ( const MethodParameterClosure6_1346 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_1346 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2, Arg5 A5 ) const
			{
				
				Call ( Target, A2, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_1356 : public virtual IMethod2 <Object, Return, Arg2, Arg4>
		{
		public:
			
			inline MethodParameterClosure6_1356 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg3 Default3, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_1356 ( const MethodParameterClosure6_1356 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_1356 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2, Arg4 A4 ) const
			{
				
				Call ( Target, A2, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_1356 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod2 <const Object, Return, Arg2, Arg4>
		{
		public:
			
			inline MethodParameterClosure6_1356 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg3 Default3, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_1356 ( const MethodParameterClosure6_1356 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_1356 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2, Arg4 A4 ) const
			{
				
				Call ( Target, A2, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_1456 : public virtual IMethod2 <Object, Return, Arg2, Arg3>
		{
		public:
			
			inline MethodParameterClosure6_1456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_1456 ( const MethodParameterClosure6_1456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_1456 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( Target, A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_1456 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod2 <const Object, Return, Arg2, Arg3>
		{
		public:
			
			inline MethodParameterClosure6_1456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_1456 ( const MethodParameterClosure6_1456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_1456 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, A3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2, Arg3 A3 ) const
			{
				
				Call ( Target, A2, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_2345 : public virtual IMethod2 <Object, Return, Arg1, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_2345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_2345 ( const MethodParameterClosure6_2345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_2345 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_2345 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod2 <const Object, Return, Arg1, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_2345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_2345 ( const MethodParameterClosure6_2345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_2345 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg6 A6 ) const
			{
				
				Call ( Target, A1, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_2346 : public virtual IMethod2 <Object, Return, Arg1, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_2346 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_2346 ( const MethodParameterClosure6_2346 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_2346 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_2346 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod2 <const Object, Return, Arg1, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_2346 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_2346 ( const MethodParameterClosure6_2346 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_2346 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg5 A5 ) const
			{
				
				Call ( Target, A1, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_2356 : public virtual IMethod2 <Object, Return, Arg1, Arg4>
		{
		public:
			
			inline MethodParameterClosure6_2356 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg3 Default3, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_2356 ( const MethodParameterClosure6_2356 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_2356 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg4 A4 ) const
			{
				
				Call ( Target, A1, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_2356 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod2 <const Object, Return, Arg1, Arg4>
		{
		public:
			
			inline MethodParameterClosure6_2356 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg2 Default2, Arg3 Default3, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_2356 ( const MethodParameterClosure6_2356 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_2356 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg4 A4 ) const
			{
				
				Call ( Target, A1, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_2456 : public virtual IMethod2 <Object, Return, Arg1, Arg3>
		{
		public:
			
			inline MethodParameterClosure6_2456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_2456 ( const MethodParameterClosure6_2456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_2456 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg3 A3 ) const
			{
				
				Call ( Target, A1, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_2456 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod2 <const Object, Return, Arg1, Arg3>
		{
		public:
			
			inline MethodParameterClosure6_2456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg2 Default2, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_2456 ( const MethodParameterClosure6_2456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_2456 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, A3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg3 A3 ) const
			{
				
				Call ( Target, A1, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_3456 : public virtual IMethod2 <Object, Return, Arg1, Arg2>
		{
		public:
			
			inline MethodParameterClosure6_3456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_3456 ( const MethodParameterClosure6_3456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_3456 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1, Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1, Arg2 A2 ) const
			{
				
				Call ( Target, A1, A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_3456 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod2 <const Object, Return, Arg1, Arg2>
		{
		public:
			
			inline MethodParameterClosure6_3456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_3456 ( const MethodParameterClosure6_3456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_3456 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1, Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, A2, Default3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1, Arg2 A2 ) const
			{
				
				Call ( Target, A1, A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_12345 : public virtual IMethod1 <Object, Return, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_12345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_12345 ( const MethodParameterClosure6_12345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_12345 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg6 A6 ) const
			{
				
				Call ( Target, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_12345 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod1 <const Object, Return, Arg6>
		{
		public:
			
			inline MethodParameterClosure6_12345 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline MethodParameterClosure6_12345 ( const MethodParameterClosure6_12345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~MethodParameterClosure6_12345 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg6 A6 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg6 A6 ) const
			{
				
				Call ( Target, A6 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_12346 : public virtual IMethod1 <Object, Return, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_12346 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_12346 ( const MethodParameterClosure6_12346 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_12346 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg5 A5 ) const
			{
				
				Call ( Target, A5 );
				
			};
				
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_12346 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod1 <const Object, Return, Arg5>
		{
		public:
			
			inline MethodParameterClosure6_12346 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_12346 ( const MethodParameterClosure6_12346 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_12346 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg5 A5 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg5 A5 ) const
			{
				
				Call ( Target, A5 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_12356 : public virtual IMethod1 <Object, Return, Arg4>
		{
		public:
			
			inline MethodParameterClosure6_12356 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_12356 ( const MethodParameterClosure6_12356 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_12356 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg4 A4 ) const
			{
				
				Call ( Target, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_12356 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod1 <const Object, Return, Arg4>
		{
		public:
			
			inline MethodParameterClosure6_12356 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_12356 ( const MethodParameterClosure6_12356 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_12356 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg4 A4 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg4 A4 ) const
			{
				
				Call ( Target, A4 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_12456 : public virtual IMethod1 <Object, Return, Arg3>
		{
		public:
			
			inline MethodParameterClosure6_12456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_12456 ( const MethodParameterClosure6_12456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_12456 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg3 A3 ) const
			{
				
				Call ( Target, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_12456 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod1 <const Object, Return, Arg3>
		{
		public:
			
			inline MethodParameterClosure6_12456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_12456 ( const MethodParameterClosure6_12456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_12456 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg3 A3 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, A3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg3 A3 ) const
			{
				
				Call ( Target, A3 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_13456 : public virtual IMethod1 <Object, Return, Arg2>
		{
		public:
			
			inline MethodParameterClosure6_13456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_13456 ( const MethodParameterClosure6_13456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_13456 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg2 A2 ) const
			{
				
				Call ( Target, A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_13456 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod1 <const Object, Return, Arg2>
		{
		public:
			
			inline MethodParameterClosure6_13456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_13456 ( const MethodParameterClosure6_13456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_13456 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg2 A2 ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, A2, Default3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg2 A2 ) const
			{
				
				Call ( Target, A2 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_23456 : public virtual IMethod1 <Object, Return, Arg1>
		{
		public:
			
			inline MethodParameterClosure6_23456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_23456 ( const MethodParameterClosure6_23456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_23456 ()
			{
			};
			
			inline Return Call ( Object * Target, Arg1 A1 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target, Arg1 A1 ) const
			{
				
				Call ( Target, A1 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_23456 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod1 <const Object, Return, Arg1>
		{
		public:
			
			inline MethodParameterClosure6_23456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_23456 ( const MethodParameterClosure6_23456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_23456 ()
			{
			};
			
			inline Return Call ( const Object * Target, Arg1 A1 ) const
			{
				
				return ( Target ->* FAddress ) ( A1, Default2, Default3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target, Arg1 A1 ) const
			{
				
				Call ( Target, A1 );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_123456 : public virtual IMethod <Object, Return>
		{
		public:
			
			inline MethodParameterClosure6_123456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_123456 ( const MethodParameterClosure6_123456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_123456 ()
			{
			};
			
			inline Return Call ( Object * Target ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Object * Target ) const
			{
				
				Call ( Target );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Object, typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class MethodParameterClosure6_123456 <const Object, Return, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>  : public virtual IMethod <const Object, Return>
		{
		public:
			
			inline MethodParameterClosure6_123456 ( Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const, Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline MethodParameterClosure6_123456 ( const MethodParameterClosure6_123456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~MethodParameterClosure6_123456 ()
			{
			};
			
			inline Return Call ( const Object * Target ) const
			{
				
				return ( Target ->* FAddress ) ( Default1, Default2, Default3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( const Object * Target ) const
			{
				
				Call ( Target );
				
			};
			
		private:
			
			Return ( Object :: * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ) const;
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		
	}
	
}

#endif
