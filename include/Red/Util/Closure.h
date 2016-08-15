#ifndef RED_UTIL_METHOD_H
#define RED_UTIL_METHOD_H

#include <Red/Red.h>
#include <Red/Util/Util.h>
#include <Red/Util/Function.h>

namespace Red
{
	
	namespace Util
	{
		
		template <typename Return, typename Arg1>
		class Closure1_1 : public virtual IFunction <Return>
		{
		public:
			
			inline Closure1_1 ( Return ( * FAddress ) ( Arg1 ), Arg1 Default1 ):
				FAddress ( FAddress ),
				Default1 ( Default1 )
			{
			};
			
			inline Closure1_1 ( const Closure1_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 )
			{	
			};
			
			inline ~Closure1_1 ()
			{
			};
			
			inline Return Call () const
			{
				
				return ( * FAddress ) ( Default1 );
				
			}
			
			inline Return operator() () const
			{
				
				return Call ();
					
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1 );
			Arg1 Default1;
			
		};
		
		template <typename Return, typename Arg1, typename Arg2>
		class Closure2_1 : public virtual IFunction1 <Return, Arg2>
		{
		public:
			
			inline Closure2_1 ( Return ( * FAddress ) ( Arg1, Arg2 ), Arg1 Default1 ):
				FAddress ( FAddress ),
				Default1 ( Default1 )
			{
			};
			
			inline Closure2_1 ( const Closure2_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 )
			{	
			};
			
			inline ~Closure2_1 ()
			{
			};
			
			inline Return Call ( Arg2 A2 ) const
			{
				
				return ( * FAddress ) ( Default1, A2 );
				
			}
			
			inline Return operator() ( Arg2 A2 ) const
			{
				
				return Call ( A2 );
					
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2 );
			Arg1 Default1;
			
		};
		
		template <typename Return, typename Arg1, typename Arg2>
		class Closure2_2 : public virtual IFunction1 <Return, Arg1>
		{
		public:
			
			inline Closure2_2 ( Return ( * FAddress ) ( Arg1, Arg2 ), Arg2 Default2 ):
				FAddress ( FAddress ),
				Default2 ( Default2 )
			{
			};
			
			inline Closure2_2 ( const Closure2_2 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 )
			{	
			};
			
			inline ~Closure2_2 ()
			{
			};
			
			inline Return Call ( Arg1 A1 ) const
			{
				
				return ( * FAddress ) ( A1, Default2 );
				
			}
			
			inline Return operator() ( Arg2 A1 ) const
			{
				
				return Call ( A1 );
					
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2 );
			Arg2 Default2;
			
		};
		
		template <typename Return, typename Arg1, typename Arg2>
		class Closure2_12 : public virtual IFunction <Return>
		{
		public:
			
			inline Closure2_12 ( Return ( * FAddress ) ( Arg1, Arg2 ), Arg1 Default1, Arg2 Default2 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 )
			{
			};
			
			inline Closure2_12 ( const Closure2_12 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 )
			{	
			};
			
			inline ~Closure2_12 ()
			{
			};
			
			inline Return Call () const
			{
				
				return ( * FAddress ) ( Default1, Default2 );
				
			}
			
			inline Return operator() () const
			{
				
				return Call ();
					
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2 );
			Arg1 Default1;
			Arg2 Default2;
			
		};
		
		template <typename Return, typename Arg1, typename Arg2, typename Arg3>
		class Closure3_1 : public virtual IFunction2 <Return, Arg2, Arg3>
		{
		public:
			
			inline Closure3_1 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3 ), Arg1 Default1 ):
				FAddress ( FAddress ),
				Default1 ( Default1 )
			{
			};
			
			inline Closure3_1 ( const Closure3_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~Closure3_1 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, A3 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3 ) const
			{
				
				return Call ( A2, A3 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3 );
			Arg1 Default1;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3>
		class Closure3_2 : public virtual IFunction2 <Return, Arg1, Arg3>
		{
		public:
			
			inline Closure3_2 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3 ), Arg2 Default2 ):
				FAddress ( FAddress ),
				Default2 ( Default2 )
			{
			};
			
			inline Closure3_2 ( const Closure3_2 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~Closure3_2 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, A3 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3 ) const
			{
				
				return Call ( A1, A3 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3 );
			Arg2 Default2;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3>
		class Closure3_3 : public virtual IFunction2 <Return, Arg1, Arg2>
		{
		public:
			
			inline Closure3_3 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3 ), Arg3 Default3 ):
				FAddress ( FAddress ),
				Default3 ( Default3 )
			{
			};
			
			inline Closure3_3 ( const Closure3_3 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~Closure3_3 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2 ) const
			{
				
				return ( * FAddress ) ( A1, A2, Default3 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2 ) const
			{
				
				return Call ( A1, A2 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3 );
			Arg3 Default3;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3>
		class Closure3_12 : public virtual IFunction1 <Return, Arg3>
		{
		public:
			
			inline Closure3_12 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3 ), Arg1 Default1, Arg2 Default2 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 )
			{
			};
			
			inline Closure3_12 ( const Closure3_12 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~Closure3_12 ()
			{
			};
			
			inline Return Call ( Arg3 A3 ) const
			{
				
				return ( * FAddress ) ( Default1, Default2, A3 );
				
			};
			
			inline Return operator() ( Arg3 A3 ) const
			{
				
				return Call ( A3 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3 );
			Arg1 Default1;
			Arg2 Default2;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3>
		class Closure3_13 : public virtual IFunction1 <Return, Arg2>
		{
		public:
			
			inline Closure3_13 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3 ), Arg1 Default1, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 )
			{
			};
			
			inline Closure3_13 ( const Closure3_13 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~Closure3_13 ()
			{
			};
			
			inline Return Call ( Arg2 A2 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, Default3 );
				
			};
			
			inline Return operator() ( Arg2 A2 ) const
			{
				
				return Call ( A2 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3 );
			Arg1 Default1;
			Arg3 Default3;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3>
		class Closure3_23 : public virtual IFunction1 <Return, Arg1>
		{
		public:
			
			inline Closure3_23 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3 ), Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline Closure3_23 ( const Closure3_23 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~Closure3_23 ()
			{
			};
			
			inline Return Call ( Arg1 A1 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, Default3 );
				
			};
			
			inline Return operator() ( Arg1 A1 ) const
			{
				
				return Call ( A1 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3 );
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3>
		class Closure3_123 : public virtual IFunction <Return>
		{
		public:
			
			inline Closure3_123 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3 ), Arg1 Default1, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline Closure3_123 ( const Closure3_123 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~Closure3_123 ()
			{
			};
			
			inline Return Call () const
			{
				
				return ( * FAddress ) ( Default1, Default2, Default3 );
				
			};
			
			inline Return operator() () const
			{
				
				return Call ();
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class Closure4_1 : public virtual IFunction3 <Return, Arg2, Arg3, Arg4>
		{
		public:
			
			inline Closure4_1 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg1 Default1 ):
				FAddress ( FAddress ),
				Default1 ( Default1 )
			{
			};
			
			inline Closure4_1 ( const Closure4_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~Closure4_1 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, A3, A4 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return Call ( A2, A3, A4 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg1 Default1;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class Closure4_2 : public virtual IFunction3 <Return, Arg1, Arg3, Arg4>
		{
		public:
			
			inline Closure4_2 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg2 Default2 ):
				FAddress ( FAddress ),
				Default2 ( Default2 )
			{
			};
			
			inline Closure4_2 ( const Closure4_2 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~Closure4_2 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, A3, A4 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				return Call ( A1, A3, A4 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg2 Default2;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class Closure4_3 : public virtual IFunction3 <Return, Arg1, Arg2, Arg4>
		{
		public:
			
			inline Closure4_3 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg3 Default3 ):
				FAddress ( FAddress ),
				Default3 ( Default3 )
			{
			};
			
			inline Closure4_3 ( const Closure4_3 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~Closure4_3 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				return ( * FAddress ) ( A1, A2, Default3, A4 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				return Call ( A1, A2, A4 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg3 Default3;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class Closure4_4 : public virtual IFunction3 <Return, Arg1, Arg2, Arg3>
		{
		public:
			
			inline Closure4_4 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg4 Default4 ):
				FAddress ( FAddress ),
				Default4 ( Default4 )
			{
			};
			
			inline Closure4_4 ( const Closure4_4 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~Closure4_4 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				return ( * FAddress ) ( A1, A2, A3, Default4 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				return Call ( A1, A2, A3 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg4 Default4;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class Closure4_12 : public virtual IFunction2 <Return, Arg3, Arg4>
		{
		public:
			
			inline Closure4_12 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg1 Default1, Arg2 Default2 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 )
			{
			};
			
			inline Closure4_12 ( const Closure4_12 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~Closure4_12 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4 ) const
			{
				
				return ( * FAddress ) ( Default1, Default2, A3, A4 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4 ) const
			{
				
				return Call ( A3, A4 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg1 Default1;
			Arg2 Default2;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class Closure4_13 : public virtual IFunction2 <Return, Arg2, Arg4>
		{
		public:
			
			inline Closure4_13 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg1 Default1, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 )
			{
			};
			
			inline Closure4_13 ( const Closure4_13 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~Closure4_13 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, Default3, A4 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4 ) const
			{
				
				return Call ( A2, A4 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg1 Default1;
			Arg3 Default3;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class Closure4_14 : public virtual IFunction2 <Return, Arg2, Arg3>
		{
		public:
			
			inline Closure4_14 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg1 Default1, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default4 ( Default4 )
			{
			};
			
			inline Closure4_14 ( const Closure4_14 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~Closure4_14 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, A3, Default4 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3 ) const
			{
				
				return Call ( A2, A3 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg1 Default1;
			Arg4 Default4;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class Closure4_23 : public virtual IFunction2 <Return, Arg1, Arg4>
		{
		public:
			
			inline Closure4_23 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline Closure4_23 ( const Closure4_23 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~Closure4_23 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, Default3, A4 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4 ) const
			{
				
				return Call ( A1, A4 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class Closure4_24 : public virtual IFunction2 <Return, Arg1, Arg3>
		{
		public:
			
			inline Closure4_24 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline Closure4_24 ( const Closure4_24 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~Closure4_24 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, A3, Default4 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3 ) const
			{
				
				return Call ( A1, A3 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class Closure4_34 : public virtual IFunction2 <Return, Arg1, Arg2>
		{
		public:
			
			inline Closure4_34 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline Closure4_34 ( const Closure4_34 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~Closure4_34 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2 ) const
			{
				
				return ( * FAddress ) ( A1, A2, Default3, Default4 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2 ) const
			{
				
				return Call ( A1, A2 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class Closure4_123 : public virtual IFunction1 <Return, Arg4>
		{
		public:
			
			inline Closure4_123 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg1 Default1, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline Closure4_123 ( const Closure4_123 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~Closure4_123 ()
			{
			};
			
			inline Return Call ( Arg4 A4 ) const
			{
				
				return ( * FAddress ) ( Default1, Default2, Default3, A4 );
				
			};
			
			inline Return operator() ( Arg4 A4 ) const
			{
				
				return Call ( A4 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class Closure4_124 : public virtual IFunction1 <Return, Arg3>
		{
		public:
			
			inline Closure4_124 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg1 Default1, Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline Closure4_124 ( const Closure4_124 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~Closure4_124 ()
			{
			};
			
			inline Return Call ( Arg3 A3 ) const
			{
				
				return ( * FAddress ) ( Default1, Default2, A3, Default4 );
				
			};
			
			inline Return operator() ( Arg3 A3 ) const
			{
				
				return Call ( A3 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class Closure4_134 : public virtual IFunction1 <Return, Arg2>
		{
		public:
			
			inline Closure4_134 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg1 Default1, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline Closure4_134 ( const Closure4_134 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~Closure4_134 ()
			{
			};
			
			inline Return Call ( Arg2 A2 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, Default3, Default4 );
				
			};
			
			inline Return operator() ( Arg2 A2 ) const
			{
				
				return Call ( A2 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class Closure4_234 : public virtual IFunction1 <Return, Arg1>
		{
		public:
			
			inline Closure4_234 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline Closure4_234 ( const Closure4_234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~Closure4_234 ()
			{
			};
			
			inline Return Call ( Arg1 A1 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, Default3, Default4 );
				
			};
			
			inline Return operator() ( Arg1 A1 ) const
			{
				
				return Call ( A1 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class Closure4_1234 : public virtual IFunction <Return>
		{
		public:
			
			inline Closure4_1234 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 ), Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline Closure4_1234 ( const Closure4_1234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~Closure4_1234 ()
			{
			};
			
			inline Return Call () const
			{
				
				return ( * FAddress ) ( Default1, Default2, Default3, Default4 );
				
			};
			
			inline Return operator() () const
			{
				
				return Call ();
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_1 : public virtual IFunction4 <Return, Arg2, Arg3, Arg4, Arg5>
		{
		public:
			
			inline Closure5_1 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1 ):
				FAddress ( FAddress ),
				Default1 ( Default1 )
			{
			};
			
			inline Closure5_1 ( const Closure5_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~Closure5_1 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, A3, A4, A5 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return Call ( A2, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_2 : public virtual IFunction4 <Return, Arg1, Arg3, Arg4, Arg5>
		{
		public:
			
			inline Closure5_2 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg2 Default2 ):
				FAddress ( FAddress ),
				Default2 ( Default2 )
			{
			};
			
			inline Closure5_2 ( const Closure5_2 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~Closure5_2 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, A3, A4, A5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return Call ( A1, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg2 Default2;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_3 : public virtual IFunction4 <Return, Arg1, Arg2, Arg4, Arg5>
		{
		public:
			
			inline Closure5_3 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg3 Default3 ):
				FAddress ( FAddress ),
				Default3 ( Default3 )
			{
			};
			
			inline Closure5_3 ( const Closure5_3 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~Closure5_3 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( A1, A2, Default3, A4, A5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				return Call ( A1, A2, A4, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg3 Default3;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_4 : public virtual IFunction4 <Return, Arg1, Arg2, Arg3, Arg5>
		{
		public:
			
			inline Closure5_4 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg4 Default4 ):
				FAddress ( FAddress ),
				Default4 ( Default4 )
			{
			};
			
			inline Closure5_4 ( const Closure5_4 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~Closure5_4 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( A1, A2, A3, Default4, A5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				return Call ( A1, A2, A3, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg4 Default4;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_5 : public virtual IFunction4 <Return, Arg1, Arg2, Arg3, Arg4>
		{
		public:
			
			inline Closure5_5 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg5 Default5 ):
				FAddress ( FAddress ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure5_5 ( const Closure5_5 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure5_5 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( * FAddress ) ( A1, A2, A3, A4, Default5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return Call ( A1, A2, A3, A4 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_12 : public virtual IFunction3 <Return, Arg3, Arg4, Arg5>
		{
		public:
			
			inline Closure5_12 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg2 Default2 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 )
			{
			};
			
			inline Closure5_12 ( const Closure5_12 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~Closure5_12 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( Default1, Default2, A3, A4, A5 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return Call ( A3, A4, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg2 Default2;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_13 : public virtual IFunction3 <Return, Arg2, Arg4, Arg5>
		{
		public:
			
			inline Closure5_13 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 )
			{
			};
			
			inline Closure5_13 ( const Closure5_13 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~Closure5_13 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, Default3, A4, A5 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				return Call ( A2, A4, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg3 Default3;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_14 : public virtual IFunction3 <Return, Arg2, Arg3, Arg5>
		{
		public:
			
			inline Closure5_14 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default4 ( Default4 )
			{
			};
			
			inline Closure5_14 ( const Closure5_14 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~Closure5_14 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, A3, Default4, A5 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				return Call ( A2, A3, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg4 Default4;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_15 : public virtual IFunction3 <Return, Arg2, Arg3, Arg4>
		{
		public:
			
			inline Closure5_15 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure5_15 ( const Closure5_15 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure5_15 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, A3, A4, Default5 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return Call ( A2, A3, A4 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_23 : public virtual IFunction3 <Return, Arg1, Arg4, Arg5>
		{
		public:
			
			inline Closure5_23 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline Closure5_23 ( const Closure5_23 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~Closure5_23 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, Default3, A4, A5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4, Arg5 A5 ) const
			{
				
				return Call ( A1, A4, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_24 : public virtual IFunction3 <Return, Arg1, Arg3, Arg5>
		{
		public:
			
			inline Closure5_24 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline Closure5_24 ( const Closure5_24 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~Closure5_24 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, A3, Default4, A5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg5 A5 ) const
			{
				
				return Call ( A1, A3, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_25 : public virtual IFunction3 <Return, Arg1, Arg3, Arg4>
		{
		public:
			
			inline Closure5_25 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg2 Default2, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure5_25 ( const Closure5_25 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure5_25 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, A3, A4, Default5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				return Call ( A1, A3, A4 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg2 Default2;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_34 : public virtual IFunction3 <Return, Arg1, Arg2, Arg5>
		{
		public:
			
			inline Closure5_34 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline Closure5_34 ( const Closure5_34 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~Closure5_34 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( A1, A2, Default3, Default4, A5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg5 A5 ) const
			{
				
				return Call ( A1, A2, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_35 : public virtual IFunction3 <Return, Arg1, Arg2, Arg4>
		{
		public:
			
			inline Closure5_35 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure5_35 ( const Closure5_35 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure5_35 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				return ( * FAddress ) ( A1, A2, Default3, A4, Default5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				return Call ( A1, A2, A4 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_45 : public virtual IFunction3 <Return, Arg1, Arg2, Arg3>
		{
		public:
			
			inline Closure5_45 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure5_45 ( const Closure5_45 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure5_45 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				return ( * FAddress ) ( A1, A2, A3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				return Call ( A1, A2, A3 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_123 : public virtual IFunction2 <Return, Arg4, Arg5>
		{
		public:
			
			inline Closure5_123 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline Closure5_123 ( const Closure5_123 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~Closure5_123 ()
			{
			};
			
			inline Return Call ( Arg4 A4, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( Default1, Default2, Default3, A4, A5 );
				
			};
			
			inline Return operator() ( Arg4 A4, Arg5 A5 ) const
			{
				
				return Call ( A4, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_124 : public virtual IFunction2 <Return, Arg3, Arg5>
		{
		public:
			
			inline Closure5_124 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline Closure5_124 ( const Closure5_124 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~Closure5_124 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( Default1, Default2, A3, Default4, A5 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg5 A5 ) const
			{
				
				return Call ( A3, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_125 : public virtual IFunction2 <Return, Arg3, Arg4>
		{
		public:
			
			inline Closure5_125 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg2 Default2, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure5_125 ( const Closure5_125 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure5_125 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4 ) const
			{
				
				return ( * FAddress ) ( Default1, Default2, A3, A4, Default5 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4 ) const
			{
				
				return Call ( A3, A4 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg2 Default2;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_134 : public virtual IFunction2 <Return, Arg2, Arg5>
		{
		public:
			
			inline Closure5_134 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline Closure5_134 ( const Closure5_134 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~Closure5_134 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, Default3, Default4, A5 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg5 A5 ) const
			{
				
				return Call ( A2, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_135 : public virtual IFunction2 <Return, Arg2, Arg4>
		{
		public:
			
			inline Closure5_135 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure5_135 ( const Closure5_135 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure5_135 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, Default3, A4, Default5 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4 ) const
			{
				
				return Call ( A2, A4 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_145 : public virtual IFunction2 <Return, Arg2, Arg3>
		{
		public:
			
			inline Closure5_145 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure5_145 ( const Closure5_145 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure5_145 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, A3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3 ) const
			{
				
				return Call ( A2, A3 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_234 : public virtual IFunction2 <Return, Arg1, Arg5>
		{
		public:
			
			inline Closure5_234 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline Closure5_234 ( const Closure5_234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~Closure5_234 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, Default3, Default4, A5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg5 A5 ) const
			{
				
				return Call ( A1, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_235 : public virtual IFunction2 <Return, Arg1, Arg4>
		{
		public:
			
			inline Closure5_235 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg2 Default2, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure5_235 ( const Closure5_235 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure5_235 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, Default3, A4, Default5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4 ) const
			{
				
				return Call ( A1, A4 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_245 : public virtual IFunction2 <Return, Arg1, Arg3>
		{
		public:
			
			inline Closure5_245 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg2 Default2, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure5_245 ( const Closure5_245 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure5_245 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, A3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3 ) const
			{
				
				return Call ( A1, A3 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_345 : public virtual IFunction2 <Return, Arg1, Arg2>
		{
		public:
			
			inline Closure5_345 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure5_345 ( const Closure5_345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure5_345 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2 ) const
			{
				
				return ( * FAddress ) ( A1, A2, Default3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2 ) const
			{
				
				return Call ( A1, A2 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_1234 : public virtual IFunction1 <Return, Arg5>
		{
		public:
			
			inline Closure5_1234 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline Closure5_1234 ( const Closure5_1234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~Closure5_1234 ()
			{
			};
			
			inline Return Call ( Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( Default1, Default2, Default3, Default4, A5 );
				
			};
			
			inline Return operator() ( Arg5 A5 ) const
			{
				
				return Call ( A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_1235 : public virtual IFunction1 <Return, Arg4>
		{
		public:
			
			inline Closure5_1235 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure5_1235 ( const Closure5_1235 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure5_1235 ()
			{
			};
			
			inline Return Call ( Arg4 A4 ) const
			{
				
				return ( * FAddress ) ( Default1, Default2, Default3, A4, Default5 );
				
			};
			
			inline Return operator() ( Arg4 A4 ) const
			{
				
				return Call ( A4 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_1245 : public virtual IFunction1 <Return, Arg3>
		{
		public:
			
			inline Closure5_1245 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure5_1245 ( const Closure5_1245 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure5_1245 ()
			{
			};
			
			inline Return Call ( Arg3 A3 ) const
			{
				
				return ( * FAddress ) ( Default1, Default2, A3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Arg3 A3 ) const
			{
				
				return Call ( A3 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_1345 : public virtual IFunction1 <Return, Arg2>
		{
		public:
			
			inline Closure5_1345 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure5_1345 ( const Closure5_1345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure5_1345 ()
			{
			};
			
			inline Return Call ( Arg2 A2 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, Default3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Arg2 A2 ) const
			{
				
				return Call ( A2 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_2345 : public virtual IFunction1 <Return, Arg1>
		{
		public:
			
			inline Closure5_2345 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure5_2345 ( const Closure5_2345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure5_2345 ()
			{
			};
			
			inline Return Call ( Arg1 A1 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, Default3, Default4, Default5 );
				
			};
			
			inline Return operator() ( Arg1 A1 ) const
			{
				
				return Call ( A1 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class Closure5_12345 : public virtual IFunction <Return>
		{
		public:
			
			inline Closure5_12345 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 ), Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure5_12345 ( const Closure5_12345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure5_12345 ()
			{
			};
			
			inline Return Call () const
			{
				
				return ( * FAddress ) ( Default1, Default2, Default3, Default4, Default5 );
				
			};
			
			inline Return operator() () const
			{
				
				return Call ();
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_1 : public virtual IFunction5 <Return, Arg2, Arg3, Arg4, Arg5, Arg6>
		{
		public:
			
			inline Closure6_1 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1 ):
				FAddress ( FAddress ),
				Default1 ( Default1 )
			{
			};
			
			inline Closure6_1 ( const Closure6_1 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 )
			{
			};
			
			inline ~Closure6_1 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, A3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return Call ( A2, A3, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_2 : public virtual IFunction5 <Return, Arg1, Arg3, Arg4, Arg5, Arg6>
		{
		public:
			
			inline Closure6_2 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2 ):
				FAddress ( FAddress ),
				Default2 ( Default2 )
			{
			};
			
			inline Closure6_2 ( const Closure6_2 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~Closure6_2 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, A3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return Call ( A1, A3, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_3 : public virtual IFunction5 <Return, Arg1, Arg2, Arg4, Arg5, Arg6>
		{
		public:
			
			inline Closure6_3 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg3 Default3 ):
				FAddress ( FAddress ),
				Default3 ( Default3 )
			{
			};
			
			inline Closure6_3 ( const Closure6_3 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~Closure6_3 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( A1, A2, Default3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return Call ( A1, A2, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg3 Default3;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_4 : public virtual IFunction5 <Return, Arg1, Arg2, Arg3, Arg5, Arg6>
		{
		public:
			
			inline Closure6_4 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg4 Default4 ):
				FAddress ( FAddress ),
				Default4 ( Default4 )
			{
			};
			
			inline Closure6_4 ( const Closure6_4 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~Closure6_4 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( A1, A2, A3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return Call ( A1, A2, A3, A5, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg4 Default4;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_5 : public virtual IFunction5 <Return, Arg1, Arg2, Arg3, Arg4, Arg6>
		{
		public:
			
			inline Closure6_5 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg5 Default5 ):
				FAddress ( FAddress ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure6_5 ( const Closure6_5 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure6_5 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( A1, A2, A3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return Call ( A1, A2, A3, A4, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_6 : public virtual IFunction5 <Return, Arg1, Arg2, Arg3, Arg4, Arg5>
		{
		public:
			
			inline Closure6_6 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg6 Default6 ):
				FAddress ( FAddress ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_6 ( const Closure6_6 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_6 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( A1, A2, A3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return Call ( A1, A2, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_12 : public virtual IFunction4 <Return, Arg3, Arg4, Arg5, Arg6>
		{
		public:
			
			inline Closure6_12 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 )
			{
			};
			
			inline Closure6_12 ( const Closure6_12 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 )
			{
			};
			
			inline ~Closure6_12 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( Default1, Default2, A3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return Call ( A3, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_13 : public virtual IFunction4 <Return, Arg2, Arg4, Arg5, Arg6>
		{
		public:
			
			inline Closure6_13 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 )
			{
			};
			
			inline Closure6_13 ( const Closure6_13 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~Closure6_13 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, Default3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return Call ( A2, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg3 Default3;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_14 : public virtual IFunction4 <Return, Arg2, Arg3, Arg5, Arg6>
		{
		public:
			
			inline Closure6_14 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default4 ( Default4 )
			{
			};
			
			inline Closure6_14 ( const Closure6_14 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~Closure6_14 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, A3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return Call ( A2, A3, A5, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg4 Default4;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_15 : public virtual IFunction4 <Return, Arg2, Arg3, Arg4, Arg6>
		{
		public:
			
			inline Closure6_15 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure6_15 ( const Closure6_15 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure6_15 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, A3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return Call ( A2, A3, A4, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_16 : public virtual IFunction4 <Return, Arg2, Arg3, Arg4, Arg5>
		{
		public:
			
			inline Closure6_16 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_16 ( const Closure6_16 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_16 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, A3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return Call ( A2, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_23 : public virtual IFunction4 <Return, Arg1, Arg4, Arg5, Arg6>
		{
		public:
			
			inline Closure6_23 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline Closure6_23 ( const Closure6_23 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~Closure6_23 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, Default3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return Call ( A1, A4, A5, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_24 : public virtual IFunction4 <Return, Arg1, Arg3, Arg5, Arg6>
		{
		public:
			
			inline Closure6_24 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline Closure6_24 ( const Closure6_24 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~Closure6_24 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, A3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return Call ( A1, A3, A5, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_25 : public virtual IFunction4 <Return, Arg1, Arg3, Arg4, Arg6>
		{
		public:
			
			inline Closure6_25 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure6_25 ( const Closure6_25 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure6_25 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, A3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return Call ( A1, A3, A4, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_26 : public virtual IFunction4 <Return, Arg1, Arg3, Arg4, Arg5>
		{
		public:
			
			inline Closure6_26 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_26 ( const Closure6_26 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_26 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, A3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return Call ( A1, A3, A4, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_34 : public virtual IFunction4 <Return, Arg1, Arg2, Arg5, Arg6>
		{
		public:
			
			inline Closure6_34 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline Closure6_34 ( const Closure6_34 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~Closure6_34 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( A1, A2, Default3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg5 A5, Arg6 A6 ) const
			{
				
				return Call ( A1, A2, A5, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_35 : public virtual IFunction4 <Return, Arg1, Arg2, Arg4, Arg6>
		{
		public:
			
			inline Closure6_35 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure6_35 ( const Closure6_35 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure6_35 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( A1, A2, Default3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4, Arg6 A6 ) const
			{
				
				return Call ( A1, A2, A4, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_36 : public virtual IFunction4 <Return, Arg1, Arg2, Arg4, Arg5>
		{
		public:
			
			inline Closure6_36 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg3 Default3, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_36 ( const Closure6_36 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_36 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( A1, A2, Default3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				return Call ( A1, A2, A4, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg3 Default3;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_45 : public virtual IFunction4 <Return, Arg1, Arg2, Arg3, Arg6>
		{
		public:
			
			inline Closure6_45 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure6_45 ( const Closure6_45 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure6_45 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( A1, A2, A3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg6 A6 ) const
			{
				
				return Call ( A1, A2, A3, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_46 : public virtual IFunction4 <Return, Arg1, Arg2, Arg3, Arg5>
		{
		public:
			
			inline Closure6_46 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_46 ( const Closure6_46 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_46 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( A1, A2, A3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				return Call ( A1, A2, A3, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_56 : public virtual IFunction4 <Return, Arg1, Arg2, Arg3, Arg4>
		{
		public:
			
			inline Closure6_56 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_56 ( const Closure6_56 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_56 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( * FAddress ) ( A1, A2, A3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return Call ( A1, A2, A3, A4 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_123 : public virtual IFunction3 <Return, Arg4, Arg5, Arg6>
		{
		public:
			
			inline Closure6_123 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg3 Default3 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 )
			{
			};
			
			inline Closure6_123 ( const Closure6_123 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 )
			{
			};
			
			inline ~Closure6_123 ()
			{
			};
			
			inline Return Call ( Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( Default1, Default2, Default3, A4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg4 A4, Arg5 A5, Arg6 A6 ) const
			{
				
				return Call ( A4, A5, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_124 : public virtual IFunction3 <Return, Arg3, Arg5, Arg6>
		{
		public:
			
			inline Closure6_124 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 )
			{
			};
			
			inline Closure6_124 ( const Closure6_124 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~Closure6_124 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( Default1, Default2, A3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg5 A5, Arg6 A6 ) const
			{
				
				return Call ( A3, A5, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_125 : public virtual IFunction3 <Return, Arg3, Arg4, Arg6>
		{
		public:
			
			inline Closure6_125 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure6_125 ( const Closure6_125 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure6_125 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( Default1, Default2, A3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4, Arg6 A6 ) const
			{
				
				return Call ( A3, A4, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_126 : public virtual IFunction3 <Return, Arg3, Arg4, Arg5>
		{
		public:
			
			inline Closure6_126 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_126 ( const Closure6_126 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_126 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( Default1, Default2, A3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4, Arg5 A5 ) const
			{
				
				return Call ( A3, A4, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_134 : public virtual IFunction3 <Return, Arg2, Arg5, Arg6>
		{
		public:
			
			inline Closure6_134 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline Closure6_134 ( const Closure6_134 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~Closure6_134 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, Default3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg5 A5, Arg6 A6 ) const
			{
				
				return Call ( A2, A5, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_135 : public virtual IFunction3 <Return, Arg2, Arg4, Arg6>
		{
		public:
			
			inline Closure6_135 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure6_135 ( const Closure6_135 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure6_135 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, Default3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4, Arg6 A6 ) const
			{
				
				return Call ( A2, A4, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_136 : public virtual IFunction3 <Return, Arg2, Arg4, Arg5>
		{
		public:
			
			inline Closure6_136 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg3 Default3, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_136 ( const Closure6_136 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_136 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, Default3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4, Arg5 A5 ) const
			{
				
				return Call ( A2, A4, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg3 Default3;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_145 : public virtual IFunction3 <Return, Arg2, Arg3, Arg6>
		{
		public:
			
			inline Closure6_145 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure6_145 ( const Closure6_145 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure6_145 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, A3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg6 A6 ) const
			{
				
				return Call ( A2, A3, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_146 : public virtual IFunction3 <Return, Arg2, Arg3, Arg5>
		{
		public:
			
			inline Closure6_146 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_146 ( const Closure6_146 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_146 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, A3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg5 A5 ) const
			{
				
				return Call ( A2, A3, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_156 : public virtual IFunction3 <Return, Arg2, Arg3, Arg4>
		{
		public:
			
			inline Closure6_156 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_156 ( const Closure6_156 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_156 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, A3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3, Arg4 A4 ) const
			{
				
				return Call ( A2, A3, A4 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_234 : public virtual IFunction3 <Return, Arg1, Arg5, Arg6>
		{
		public:
			
			inline Closure6_234 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline Closure6_234 ( const Closure6_234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~Closure6_234 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg5 A5, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, Default3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg5 A5, Arg6 A6 ) const
			{
				
				return Call ( A1, A5, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_235 : public virtual IFunction3 <Return, Arg1, Arg4, Arg6>
		{
		public:
			
			inline Closure6_235 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure6_235 ( const Closure6_235 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure6_235 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, Default3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4, Arg6 A6 ) const
			{
				
				return Call ( A1, A4, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_236 : public virtual IFunction3 <Return, Arg1, Arg4, Arg5>
		{
		public:
			
			inline Closure6_236 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg3 Default3, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_236 ( const Closure6_236 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_236 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, Default3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4, Arg5 A5 ) const
			{
				
				return Call ( A1, A4, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg3 Default3;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_245 : public virtual IFunction3 <Return, Arg1, Arg3, Arg6>
		{
		public:
			
			inline Closure6_245 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure6_245 ( const Closure6_245 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure6_245 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, A3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg6 A6 ) const
			{
				
				return Call ( A1, A3, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_246 : public virtual IFunction3 <Return, Arg1, Arg3, Arg5>
		{
		public:
			
			inline Closure6_246 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_246 ( const Closure6_246 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_246 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, A3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg5 A5 ) const
			{
				
				return Call ( A1, A3, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_256 : public virtual IFunction3 <Return, Arg1, Arg3, Arg4>
		{
		public:
			
			inline Closure6_256 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_256 ( const Closure6_256 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_256 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, A3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3, Arg4 A4 ) const
			{
				
				return Call ( A1, A3, A4 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_345 : public virtual IFunction3 <Return, Arg1, Arg2, Arg6>
		{
		public:
			
			inline Closure6_345 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure6_345 ( const Closure6_345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure6_345 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( A1, A2, Default3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg6 A6 ) const
			{
				
				return Call ( A1, A2, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_346 : public virtual IFunction3 <Return, Arg1, Arg2, Arg5>
		{
		public:
			
			inline Closure6_346 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg3 Default3, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_346 ( const Closure6_346 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_346 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( A1, A2, Default3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg5 A5 ) const
			{
				
				return Call ( A1, A2, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_356 : public virtual IFunction3 <Return, Arg1, Arg2, Arg4>
		{
		public:
			
			inline Closure6_356 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg3 Default3, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_356 ( const Closure6_356 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_356 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				return ( * FAddress ) ( A1, A2, Default3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg4 A4 ) const
			{
				
				return Call ( A1, A2, A4 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_456 : public virtual IFunction3 <Return, Arg1, Arg2, Arg3>
		{
		public:
			
			inline Closure6_456 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_456 ( const Closure6_456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_456 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				return ( * FAddress ) ( A1, A2, A3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2, Arg3 A3 ) const
			{
				
				return Call ( A1, A2, A3 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_1234 : public virtual IFunction2 <Return, Arg5, Arg6>
		{
		public:
			
			inline Closure6_1234 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 )
			{
			};
			
			inline Closure6_1234 ( const Closure6_1234 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 )
			{
			};
			
			inline ~Closure6_1234 ()
			{
			};
			
			inline Return Call ( Arg5 A5, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( Default1, Default2, Default3, Default4, A5, A6 );
				
			};
			
			inline Return operator() ( Arg5 A5, Arg6 A6 ) const
			{
				
				return Call ( A5, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_1235 : public virtual IFunction2 <Return, Arg4, Arg6>
		{
		public:
			
			inline Closure6_1235 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure6_1235 ( const Closure6_1235 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure6_1235 ()
			{
			};
			
			inline Return Call ( Arg4 A4, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( Default1, Default2, Default3, A4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg4 A4, Arg6 A6 ) const
			{
				
				return Call ( A4, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_1236 : public virtual IFunction2 <Return, Arg4, Arg5>
		{
		public:
			
			inline Closure6_1236 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_1236 ( const Closure6_1236 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_1236 ()
			{
			};
			
			inline Return Call ( Arg4 A4, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( Default1, Default2, Default3, A4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg4 A4, Arg5 A5 ) const
			{
				
				return Call ( A4, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_1245 : public virtual IFunction2 <Return, Arg3, Arg6>
		{
		public:
			
			inline Closure6_1245 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure6_1245 ( const Closure6_1245 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure6_1245 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( Default1, Default2, A3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg6 A6 ) const
			{
				
				return Call ( A3, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_1246 : public virtual IFunction2 <Return, Arg3, Arg5>
		{
		public:
			
			inline Closure6_1246 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_1246 ( const Closure6_1246 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_1246 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( Default1, Default2, A3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg5 A5 ) const
			{
				
				return Call ( A3, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_1256 : public virtual IFunction2 <Return, Arg3, Arg4>
		{
		public:
			
			inline Closure6_1256 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_1256 ( const Closure6_1256 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_1256 ()
			{
			};
			
			inline Return Call ( Arg3 A3, Arg4 A4 ) const
			{
				
				return ( * FAddress ) ( Default1, Default2, A3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg3 A3, Arg4 A4 ) const
			{
				
				return Call ( A3, A4 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_1345 : public virtual IFunction2 <Return, Arg2, Arg6>
		{
		public:
			
			inline Closure6_1345 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure6_1345 ( const Closure6_1345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure6_1345 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, Default3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg6 A6 ) const
			{
				
				return Call ( A2, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_1346 : public virtual IFunction2 <Return, Arg2, Arg5>
		{
		public:
			
			inline Closure6_1346 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_1346 ( const Closure6_1346 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_1346 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, Default3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg5 A5 ) const
			{
				
				return Call ( A2, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_1356 : public virtual IFunction2 <Return, Arg2, Arg4>
		{
		public:
			
			inline Closure6_1356 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg3 Default3, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_1356 ( const Closure6_1356 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_1356 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg4 A4 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, Default3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg4 A4 ) const
			{
				
				return Call ( A2, A4 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_1456 : public virtual IFunction2 <Return, Arg2, Arg3>
		{
		public:
			
			inline Closure6_1456 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_1456 ( const Closure6_1456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_1456 ()
			{
			};
			
			inline Return Call ( Arg2 A2, Arg3 A3 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, A3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg2 A2, Arg3 A3 ) const
			{
				
				return Call ( A2, A3 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_2345 : public virtual IFunction2 <Return, Arg1, Arg6>
		{
		public:
			
			inline Closure6_2345 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure6_2345 ( const Closure6_2345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure6_2345 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, Default3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg6 A6 ) const
			{
				
				return Call ( A1, A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_2346 : public virtual IFunction2 <Return, Arg1, Arg5>
		{
		public:
			
			inline Closure6_2346 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_2346 ( const Closure6_2346 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_2346 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, Default3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg5 A5 ) const
			{
				
				return Call ( A1, A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_2356 : public virtual IFunction2 <Return, Arg1, Arg4>
		{
		public:
			
			inline Closure6_2356 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg3 Default3, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_2356 ( const Closure6_2356 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_2356 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg4 A4 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, Default3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg4 A4 ) const
			{
				
				return Call ( A1, A4 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_2456 : public virtual IFunction2 <Return, Arg1, Arg3>
		{
		public:
			
			inline Closure6_2456 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_2456 ( const Closure6_2456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_2456 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg3 A3 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, A3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg3 A3 ) const
			{
				
				return Call ( A1, A3 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_3456 : public virtual IFunction2 <Return, Arg1, Arg2>
		{
		public:
			
			inline Closure6_3456 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_3456 ( const Closure6_3456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_3456 ()
			{
			};
			
			inline Return Call ( Arg1 A1, Arg2 A2 ) const
			{
				
				return ( * FAddress ) ( A1, A2, Default3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1, Arg2 A2 ) const
			{
				
				return Call ( A1, A2 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_12345 : public virtual IFunction1 <Return, Arg6>
		{
		public:
			
			inline Closure6_12345 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 )
			{
			};
			
			inline Closure6_12345 ( const Closure6_12345 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 )
			{
			};
			
			inline ~Closure6_12345 ()
			{
			};
			
			inline Return Call ( Arg6 A6 ) const
			{
				
				return ( * FAddress ) ( Default1, Default2, Default3, Default4, Default5, A6 );
				
			};
			
			inline Return operator() ( Arg6 A6 ) const
			{
				
				return Call ( A6 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_12346 : public virtual IFunction1 <Return, Arg5>
		{
		public:
			
			inline Closure6_12346 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_12346 ( const Closure6_12346 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_12346 ()
			{
			};
			
			inline Return Call ( Arg5 A5 ) const
			{
				
				return ( * FAddress ) ( Default1, Default2, Default3, Default4, A5, Default6 );
				
			};
			
			inline Return operator() ( Arg5 A5 ) const
			{
				
				return Call ( A5 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_12356 : public virtual IFunction1 <Return, Arg4>
		{
		public:
			
			inline Closure6_12356 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_12356 ( const Closure6_12356 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_12356 ()
			{
			};
			
			inline Return Call ( Arg4 A4 ) const
			{
				
				return ( * FAddress ) ( Default1, Default2, Default3, A4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg4 A4 ) const
			{
				
				return Call ( A4 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg3 Default3;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_12456 : public virtual IFunction1 <Return, Arg3>
		{
		public:
			
			inline Closure6_12456 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_12456 ( const Closure6_12456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_12456 ()
			{
			};
			
			inline Return Call ( Arg3 A3 ) const
			{
				
				return ( * FAddress ) ( Default1, Default2, A3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg3 A3 ) const
			{
				
				return Call ( A3 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg2 Default2;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_13456 : public virtual IFunction1 <Return, Arg2>
		{
		public:
			
			inline Closure6_13456 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_13456 ( const Closure6_13456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_13456 ()
			{
			};
			
			inline Return Call ( Arg2 A2 ) const
			{
				
				return ( * FAddress ) ( Default1, A2, Default3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg2 A2 ) const
			{
				
				return Call ( A2 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg1 Default1;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_23456 : public virtual IFunction1 <Return, Arg1>
		{
		public:
			
			inline Closure6_23456 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_23456 ( const Closure6_23456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_23456 ()
			{
			};
			
			inline Return Call ( Arg1 A1 ) const
			{
				
				return ( * FAddress ) ( A1, Default2, Default3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() ( Arg1 A1 ) const
			{
				
				return Call ( A1 );
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
			Arg2 Default2;
			Arg3 Default3;
			Arg4 Default4;
			Arg5 Default5;
			Arg6 Default6;
			
		};
		

		template <typename Return, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class Closure6_123456 : public virtual IFunction <Return>
		{
		public:
			
			inline Closure6_123456 ( Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 ), Arg1 Default1, Arg2 Default2, Arg3 Default3, Arg4 Default4, Arg5 Default5, Arg6 Default6 ):
				FAddress ( FAddress ),
				Default1 ( Default1 ),
				Default2 ( Default2 ),
				Default3 ( Default3 ),
				Default4 ( Default4 ),
				Default5 ( Default5 ),
				Default6 ( Default6 )
			{
			};
			
			inline Closure6_123456 ( const Closure6_123456 & CopyFrom ):
				FAddress ( CopyFrom.FAddress ),
				Default1 ( CopyFrom.Default1 ),
				Default2 ( CopyFrom.Default2 ),
				Default3 ( CopyFrom.Default3 ),
				Default4 ( CopyFrom.Default4 ),
				Default5 ( CopyFrom.Default5 ),
				Default6 ( CopyFrom.Default6 )
			{
			};
			
			inline ~Closure6_123456 ()
			{
			};
			
			inline Return Call () const
			{
				
				return ( * FAddress ) ( Default1, Default2, Default3, Default4, Default5, Default6 );
				
			};
			
			inline Return operator() () const
			{
				
				return Call ();
				
			};
			
		private:
			
			Return ( * FAddress ) ( Arg1, Arg2, Arg3, Arg4, Arg5, Arg6 );
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
