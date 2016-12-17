#include <Red/Data/JSON/Decoder.h>

#include <Red/Data/JSON/Boolean.h>
#include <Red/Data/JSON/Number.h>
#include <Red/Data/JSON/String.h>
#include <Red/Data/JSON/Array.h>
#include <Red/Data/JSON/Object.h>

#include <iostream>

Red::Data::JSON::Decoder :: Decoder ( DecodeFlags Flags ):
	Flags ( Flags )
{
}

Red::Data::JSON::Decoder :: ~Decoder ()
{
}

Red::Data::JSON :: IType * Red::Data::JSON::Decoder :: Decode ( const std :: string & StringData, uint32_t StartOffset, uint32_t Length )
{
	
	DecodeInfo Info;
	
	std :: vector <IType *> ObjectStack;
	
	if ( StartOffset + Length >= StringData.size () )
		Length = StringData.size () - StartOffset;
	
	Info.Text = & StringData;
	Info.TextSize = Length + StartOffset;
	Info.TextOffset = StartOffset;
	Info.RootObject = NULL;
	Info.ObjectStack = & ObjectStack;
	Info.Error = false;
	
	SkipWhitespace ( Info );
	DecodeSubObject ( Info );
	
	if ( Info.ObjectStack -> size () == 0 )
		Info.RootObject = NULL;
	
	if ( Info.Error )
	{
		
		if ( ( Flags & kDecodeFlags_KeepOnError ) != 0 )
			return Info.RootObject;
		
		if ( Info.RootObject != NULL )
			delete Info.RootObject;
		
		return NULL;
		
	}
	
	return Info.RootObject; 
	
}

void Red::Data::JSON::Decoder :: SkipWhitespace ( DecodeInfo & Info )
{
	
	if ( Info.TextOffset >= Info.TextSize )
		return;
	
	char C = Info.Text -> at ( Info.TextOffset );
	
	while ( ( C == ' ' ) || ( C == '\n' ) || ( C == '\r' ) || ( C == '\f' ) || ( C == '\t' ) )
	{
		
		Info.TextOffset ++;
		
		if ( Info.TextOffset >= Info.TextSize )
			return;
		
		C = Info.Text -> at ( Info.TextOffset );
		
	}
	
}

void Red::Data::JSON::Decoder :: DecodeSubObject ( DecodeInfo & Info )
{
	
	if ( Info.TextOffset >= Info.TextSize )
		return;
	
	char C = Info.Text -> at ( Info.TextOffset );
	
	switch ( C )
	{
		
		case '{':
		{
			
			std :: cout << "Object begin" << std :: endl;
			
			Object * Obj = new Object ();
			
			Info.ObjectStack -> push_back ( Obj );
			
			if ( Info.RootObject == NULL )
				Info.RootObject = Obj;
			
			Info.TextOffset ++;
			
			SkipWhitespace ( Info );
			
			while ( Info.TextOffset < Info.TextSize )
			{
				
				char C = Info.Text -> at ( Info.TextOffset );
				
				if ( C == '}' )
				{
					
					Info.TextOffset ++;
					
					return;
					
				}
				
				if ( C != '\"' )
				{
					
					Info.Error = true;
					
					Info.ObjectStack -> pop_back ();
					delete Obj;
					
					return;
					
				}
				
				Info.TextOffset ++;
				
				std :: string Key;
				
				ReadbackString ( Info, Key );
				
				if ( Key.size () == 0 )
				{
					
					Info.Error = true;
					
					Info.ObjectStack -> pop_back ();
					delete Obj;
					
					return;
					
				}
				
				if ( ( Flags & kDecodeFlags_AllowKeyOverwrite ) == 0 )
				{
					
					if ( Obj -> Exists ( Key ) )
					{
						
						Info.Error = true;
						
						Info.ObjectStack -> pop_back ();
						delete Obj;
						
						return;
						
					}
					
				}
				
				SkipWhitespace ( Info );
				
				if ( Info.TextOffset >= Info.TextSize )
				{
					
					Info.Error = true;
					
					Info.ObjectStack -> pop_back ();
					delete Obj;
					
					return;
					
				}
				
				if ( Info.Text -> at ( Info.TextOffset ) != ':' )
				{
					
					Info.Error = true;
					
					Info.ObjectStack -> pop_back ();
					delete Obj;
					
					return;
					
				}
				
				Info.TextOffset ++;
				
				SkipWhitespace ( Info );
				
				if ( Info.TextOffset >= Info.TextSize )
				{
					
					Info.Error = true;
					
					Info.ObjectStack -> pop_back ();
					delete Obj;
					
					return;
					
				}
				
				std :: cout << "Decoding sub object: " << Key << std :: endl;
				
				DecodeSubObject ( Info );
				
				if ( Info.Error )
				{
					
					Info.ObjectStack -> pop_back ();
					delete Obj;
					
					return;
					
				}
				
				std :: cout << "Decoded!" << std :: endl;
				
				Obj -> Set ( Key, ( * Info.ObjectStack ) [ Info.ObjectStack -> size () - 1 ] );
				Info.ObjectStack -> pop_back ();
				
				SkipWhitespace ( Info );
				
				if ( Info.TextOffset >= Info.TextSize )
				{
					
					Info.Error = true;
					
					Info.ObjectStack -> pop_back ();
					delete Obj;
					
					return;
					
				}
				
				std :: cout << "Obj per-key end loop" << std :: endl;
				
				C = Info.Text -> at ( Info.TextOffset );
				
				if ( C == ',' )
				{
					
					std :: cout << "found comma!" << std :: endl;
					
					Info.TextOffset ++;
					
					SkipWhitespace ( Info );
					
					if ( Info.TextOffset >= Info.TextSize )
					{
						
						Info.Error = true;
						
						Info.ObjectStack -> pop_back ();
						delete Obj;
						
						return;
						
					}
					
				}
				else if ( C != '}' )
				{
					
					std :: cout << "object error!" << std :: endl;
					
					break;
				}
				
			}
			
			Info.Error = true;
			
			Info.ObjectStack -> pop_back ();
			
			delete Obj;
			
		}
		break;
		
		case '\"':
		{
			
			Info.TextOffset ++;
			
			std :: string Str;
			
			ReadbackString ( Info, Str );
			
			if ( ! Info.Error )
				Info.ObjectStack -> push_back ( new String ( Str ) );
			
			return;
			
		}
		break;
		
		case 't':
		{
			
			if ( Info.TextOffset + 3 >= Info.TextSize )
			{
				
				Info.Error = true;
				
				return;
				
			}
			
			if ( Info.Text -> substr ( Info.TextOffset, 4 ) != "true" )
			{
				
				Info.Error = true;
				
				return;
				
			}
			
			Info.TextOffset += 4;
			
			Info.ObjectStack -> push_back ( new Boolean ( true ) );
			
			return;
			
		}
		break;
		
		case 'f':
		{
			
			if ( Info.TextOffset + 4 >= Info.TextSize )
			{
				
				Info.Error = true;
				
				return;
				
			}
			
			if ( Info.Text -> substr ( Info.TextOffset, 5 ) != "false" )
			{
				
				Info.Error = true;
				
				return;
				
			}
			
			Info.TextOffset += 5;
			
			Info.ObjectStack -> push_back ( new Boolean ( false ) );
			
			return;
			
		}
		break;
		
		case 'n':
		{
			
			if ( Info.TextOffset + 3 >= Info.TextSize )
			{
				
				Info.Error = true;
				
				return;
				
			}
			
			if ( Info.Text -> substr ( Info.TextOffset, 4 ) != "null" )
			{
				
				Info.Error = true;
				
				return;
				
			}
			
			Info.TextOffset += 4;
			
			Info.ObjectStack -> push_back ( NULL );
			
			return;
			
		}
		break;
		
		case '-':
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		{
			
			std :: cout << "Number case found!" << std :: endl;
			
			uint32_t InitialOffset = Info.TextOffset;
			
			if ( C == '-' )
			{
				
				Info.TextOffset ++;
				
				if ( Info.TextOffset >= Info.TextSize )
				{
					
					Info.Error = true;
					
					return;
					
				}
				
				C = Info.Text -> at ( Info.TextOffset );
				
			}
			
			int64_t IntValue = 0;
			
			if ( ! ( ( C >= '0' ) && ( C <= '9' ) ) )
			{
				
				Info.Error = true;
				
				return;
				
			}
			
			while ( ( Info.TextOffset < Info.TextSize ) && ( ( C >= '0' ) && ( C <= '9' ) ) )
			{
				
				Info.TextOffset ++;
				
				if ( Info.TextOffset < Info.TextSize )
					C = Info.Text -> at ( Info.TextOffset );
				
			}
			
			if ( ( Info.TextOffset < Info.TextSize ) && C == '.' )
			{
				
				Info.TextOffset ++;
				
				if ( Info.TextOffset >= Info.TextSize )
				{
					
					Info.Error = true;
					
					return;
					
				}
				
				C = Info.Text -> at ( Info.TextOffset );
				
				while ( ( Info.TextOffset < Info.TextSize ) && ( ( C >= '0' ) && ( C <= '9' ) ) )
				{
					
					Info.TextOffset ++;
					
					if ( Info.TextOffset < Info.TextSize )
						C = Info.Text -> at ( Info.TextOffset );
					
				}
				
			}
			
			if ( ( Info.TextOffset < Info.TextSize ) && Info.Text -> at ( Info.TextOffset ) == 'e' )
			{
				
				Info.TextOffset ++;
				
				if ( Info.TextOffset >= Info.TextSize )
				{
					
					Info.Error = true;
					
					return;
					
				}
				
				C = Info.Text -> at ( Info.TextOffset );
				
				if ( ( C == '-' ) || ( C == '+' ) )
					Info.TextOffset ++;
				
				if ( Info.TextOffset >= Info.TextSize )
				{
					
					Info.Error = true;
					
					return;
					
				}
				
				C = Info.Text -> at ( Info.TextOffset );
					
				while ( ( C >= '0' ) && ( C <= '9' ) )
				{
					
					Info.TextOffset ++;
					
					if ( Info.TextOffset >= Info.TextSize )
					{
						
						Info.Error = true;
						
						return;
						
					}
					
					C = Info.Text -> at ( Info.TextOffset );
					
				}
				
			}
			
			std :: string NumberSubStr = Info.Text -> substr ( InitialOffset, Info.TextOffset - InitialOffset );
			
			Info.ObjectStack -> push_back ( new Number ( std :: stod ( NumberSubStr ) ) );
			
		}
		break;
		
		case '[':
		{
			
			std :: cout << "Array case found!" << std :: endl;
			
			Info.TextOffset ++;
			
			Array * Arr = new Array ();
			
			Info.ObjectStack -> push_back ( Arr );
			
			while ( Info.TextOffset < Info.TextSize )
			{
				
				SkipWhitespace ( Info );
				
				if ( Info.TextOffset >= Info.TextSize )
				{
					
					Info.Error = true;
					
					Info.ObjectStack -> pop_back ();
					delete Arr;
					
					return;
					
				}
				
				C = Info.Text -> at ( Info.TextOffset );
				
				if ( C == ']' )
				{
					
					std :: cout << "Array ended" << std :: endl;
					
					Info.TextOffset ++;
					
					return;
					
				}
				
				std :: cout << "Decoding sub object with remaining string: \"" << Info.Text -> substr ( Info.TextOffset ) << "\"" << std :: endl;
				
				DecodeSubObject ( Info );
				
				if ( Info.Error )
				{
					
					Info.ObjectStack -> pop_back ();
					delete Arr;
					
					return;
					
				}
				
				std :: cout << "Decoded!" << std :: endl;
				
				Arr -> AddItem ( ( * Info.ObjectStack ) [ Info.ObjectStack -> size () - 1 ] );
				Info.ObjectStack -> pop_back ();
				
				SkipWhitespace ( Info );
				
				if ( Info.TextOffset >= Info.TextSize )
				{
					
					Info.Error = true;
					
					Info.ObjectStack -> pop_back ();
					delete Arr;
					
					return;
					
				}
				
				C = Info.Text -> at ( Info.TextOffset );
				
				if ( C == ']' )
					continue;
				
				if ( C != ',' )
				{
					
					Info.Error = true;
					
					Info.ObjectStack -> pop_back ();
					delete Arr;
					
					return;
					
				}
				
				Info.TextOffset ++;
				
			}
			
			Info.Error = true;
			
			Info.ObjectStack -> pop_back ();
			delete Arr;
			
			return;
			
		}
		break;
		
		default:
		{
			
			Info.Error = true;
			
			return;
			
		}
		break;
		
	}
	
}

void Red::Data::JSON::Decoder :: ReadbackString ( DecodeInfo & Info, std :: string & OutString )
{
	
	while ( Info.TextOffset < Info.TextSize )
	{
		
		char C = Info.Text -> at ( Info.TextOffset );
		
		switch ( C )
		{
			
			case '\\':
			{
				
				Info.TextOffset ++;
				
				if ( Info.TextOffset >= Info.TextSize )
				{
					
					Info.Error = true;
					return;
					
				}
				
				C = Info.Text -> at ( Info.TextOffset );
				
				switch ( C )
				{
					
					case '\"':
					{
						
						Info.TextOffset ++;
						OutString += '\"';
						
					}
					break;
					
					case '\\':
					{
						
						Info.TextOffset ++;
						OutString += '\\';
						
					}
					break;
					
					case '/':
					{
						
						Info.TextOffset ++;
						OutString += '/';
						
					}
					break;
					
					case 'b':
					{
						
						Info.TextOffset ++;
						OutString += '\b';
						
					}
					break;
					
					case 'f':
					{
						
						Info.TextOffset ++;
						OutString += '\f';
						
					}
					break;
					
					case 'n':
					{
						
						Info.TextOffset ++;
						OutString += '\n';
						
					}
					break;
					
					case 'r':
					{
						
						Info.TextOffset ++;
						OutString += '\r';
						
					}
					break;
					
					case 't':
					{
						
						Info.TextOffset ++;
						OutString += '\t';
						
					}
					break;
					
					case 'u':
					{
						
						Info.TextOffset ++;
						
						if ( Info.TextSize - Info.TextOffset < 4 )
						{
							
							Info.Error = true;
							return;
							
						}
						
						uint32_t Value = 0;
						
						for ( uint32_t I = 0; I < 4; I ++ )
						{
							
							Value <<= 4;
							
							C = Info.Text -> at ( Info.TextOffset );
							
							if ( ( C <= '9' ) && ( C >= '0' ) )
								Value += static_cast <uint32_t> ( C - '0' );
							else if ( ( C <= 'f' ) && ( C >= 'a' ) )
								Value += static_cast <uint32_t> ( C - 'a' ) + 10;
							else if ( ( C <= 'F' ) && ( C >= 'A' ) )
								Value += static_cast <uint32_t> ( C - 'A' ) + 10;
							else
							{
								
								Info.Error = true;
								return;
								
							}
							
							Info.TextOffset ++;
							
						}
						
						if ( Value > 255 )
						{
							
							Info.Error = true;
							return;
							
						}
						
						OutString += static_cast <char> ( Value );
						
					}
					break;
					
				}
				
			}
			break;
			
			case '\"':
			{
				
				Info.TextOffset ++;
				return;
				
			}
			break;
			
			case '\0':
			{
				
				std :: string Dummy;
				
				Info.TextOffset ++;
				
				ReadbackString ( Info, Dummy );
				
				return;
				
			}
			break;
			
			default:
			{
				
				Info.TextOffset ++;
				OutString += C;
				
			}
			break;
			
		}
		
	}
	
}
