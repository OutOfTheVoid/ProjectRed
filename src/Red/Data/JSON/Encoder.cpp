#include <Red/Data/JSON/Encoder.h>

#include <Red/Data/JSON/Boolean.h>
#include <Red/Data/JSON/Number.h>
#include <Red/Data/JSON/String.h>
#include <Red/Data/JSON/Array.h>
#include <Red/Data/JSON/Object.h>

#include <iomanip>
#include <sstream>

Red::Data::JSON::Encoder :: Encoder ( EncodeFlags Flags, uint32_t IndentSize, const std :: string & NewlineSequence ):
	NewlineSequence ( NewlineSequence ),
	Flags ( Flags ),
	IndentSize ( IndentSize )
{
}

Red::Data::JSON::Encoder :: ~Encoder ()
{
}

bool Red::Data::JSON::Encoder :: Encode ( IType * RootObj, std :: string & OutString, uint32_t BaseIndent )
{
	
	if ( RootObj == NULL )
	{
		
		OutString += "null";
		
		return true;
		
	}
	
	switch ( RootObj -> GetType () )
	{
		
		case IType :: kDataType_Boolean:
		{
			
			Boolean * BoolValue = dynamic_cast <Boolean *> ( RootObj );
			
			if ( BoolValue != NULL )
			{
				
				if ( BoolValue -> Get () )
					OutString += "true";
				else
					OutString += "false";
				
				return true;
				
			}
			
			return false;
			
		}
		break;
		
		case IType :: kDataType_Number:
		{
			
			Number * NumValue = dynamic_cast <Number *> ( RootObj );
			
			if ( NumValue != NULL )
			{
				
				double Val = NumValue -> Get ();
				
				std :: stringstream FormatStream;
				FormatStream << std :: setprecision ( 17 ) << Val;
				OutString += FormatStream.str ();
				
				return true;
				
			}
			
			return false;
			
		}
		break;
		
		case IType :: kDataType_String:
		{
			
			String * StringValue = dynamic_cast <String *> ( RootObj );
			
			if ( StringValue != NULL )
			{
				
				std :: string Temp;
				
				StringValue -> Get ( Temp );
				
				uint32_t StringLength = Temp.size ();
				
				OutString += '\"';
				
				for ( uint32_t I = 0; I < StringLength; I ++ )
				{
					
					char C = Temp.at ( I );
					
					switch ( C )
					{
						
						case '\n':
							OutString += "\\n";
							break;
							
						case '\t':
							OutString += "\\t";
							break;
							
						case '\b':
							OutString += "\\b";
							break;
							
						case '\r':
							OutString += "\\r";
							break;
							
						case '\f':
							OutString += "\\f";
							break;
							
						case '\\':
							OutString += "\\\\";
							break;
							
						case '/':
							OutString += "\\/";
							break;
							
						default:
							OutString += C;
							break;
						
					}
					
				}
				
				OutString += '\"';
				
				return true;
				
			}
			
			return false;
			
		}
		break;
		
		case IType :: kDataType_Array:
		{
			
			Array * ArrayValue = dynamic_cast <Array *> ( RootObj );
			
			if ( ArrayValue != NULL )
			{
				
				uint32_t ItemCount = ArrayValue -> GetItemCount ();
				
				bool IsObjectArray = false;
				
				for ( uint32_t I = 0; I < ItemCount; I ++ )
				{
					
					IType * Item = ArrayValue -> GetItem ( I );
					
					if ( Item != NULL )
					{
						
						IType :: DataType Type = Item -> GetType ();
						
						if ( ( Type == IType :: kDataType_Object ) || ( Type == IType :: kDataType_Array ) )
							IsObjectArray = true;
						
					}
					
				}
								
				std :: string IndentString;
				std :: string EndIndentString;
				
				if ( ( Flags & kEncodeFlags_Pretty ) != 0 )
				{
					
					if ( Flags & kEncodeFlags_SpaceIndentation )
					{
						
						for ( uint32_t I = 0; I < BaseIndent * IndentSize; I ++ )
							EndIndentString += " ";
						
						IndentString = EndIndentString;
						
						for ( uint32_t I = 0; I < IndentSize; I ++ )
							IndentString += " ";
						
					}
					else
					{
						
						for ( uint32_t I = 0; I < BaseIndent * IndentSize; I ++ )
							EndIndentString += "\t";
						
						IndentString = EndIndentString;
						
						for ( uint32_t I = 0; I < IndentSize; I ++ )
							IndentString += "\t";
						
					}
					
				}
				
				OutString += "[";
				
				if ( ItemCount == 0 )
				{
					
					if ( ( ( Flags & kEncodeFlags_AllArrayNewlines ) != 0 ) && ( ( Flags & kEncodeFlags_Pretty ) != 0 ) )
					{
						
						OutString += NewlineSequence;
						OutString += EndIndentString;
						OutString += "]";
						
					}
					else
						OutString += "]";
					
					return true;
					
				}
				
				bool PrettyNewlines = ( ( Flags & kEncodeFlags_AllArrayNewlines ) != 0 ) || ( ( ( Flags & kEncodeFlags_NoObjectArrayNewlines ) == 0 ) && IsObjectArray );
				
				for ( uint32_t I = 0; I < ItemCount; I ++ )
				{
					
					if ( PrettyNewlines )
					{
						
						OutString += NewlineSequence;
						OutString += IndentString;
						
					}
					else if ( ( Flags & kEncodeFlags_Pretty ) != 0 )
						OutString += " ";
					
					if ( ! Encode ( ArrayValue -> GetItem ( I ), OutString, BaseIndent + 1 ) )
						return false;
					
					if ( ( I + 1 < ItemCount ) || ( ( Flags & kEncodeFlags_TrailingCommaLists ) != 0 ) )
						OutString += ",";
					
				}
				
				if ( PrettyNewlines )
				{
					
					OutString += NewlineSequence;
					OutString += EndIndentString;
					OutString += "]";
					
				}
				else
					OutString += ( ( Flags & kEncodeFlags_Pretty ) != 0 ) ? " ]" : "]";
				
				return true;
				
			}
			
			return false;
			
		}
		break;
		
		case IType :: kDataType_Object:
		{
			
			Object * ObjectValue = dynamic_cast <Object *> ( RootObj );
			
			if ( ObjectValue != NULL )
			{
				
				uint32_t MemberCount = ObjectValue -> GetKeyCount ();
				
				bool IsObjectObject = false;
				
				for ( uint32_t I = 0; I < MemberCount; I ++ )
				{
					
					IType * Member = ObjectValue -> GetItemByIndex ( I );
					
					if ( Member != NULL )
					{
						
						IType :: DataType Type = Member -> GetType ();
						
						if ( ( Type == IType :: kDataType_Object ) || ( Type == IType :: kDataType_Array ) )
							IsObjectObject = true;
						
					}
					
				}
				
				std :: string IndentString;
				std :: string EndIndentString;
				std :: string MemberIDSeperator;
				
				if ( ( Flags & kEncodeFlags_Pretty ) != 0 )
				{
					
					if ( Flags & kEncodeFlags_SpaceIndentation )
					{
						
						for ( uint32_t I = 0; I < BaseIndent * IndentSize; I ++ )
							EndIndentString += " ";
						
						IndentString = EndIndentString;
						
						for ( uint32_t I = 0; I < IndentSize; I ++ )
							IndentString += " ";
						
					}
					else
					{
						
						for ( uint32_t I = 0; I < BaseIndent * IndentSize; I ++ )
							EndIndentString += "\t";
						
						IndentString = EndIndentString;
						
						for ( uint32_t I = 0; I < IndentSize; I ++ )
							IndentString += "\t";
						
					}
					
					if ( Flags & kEncodeFlags_MemberNameSeperator_PrefixSpace )
						MemberIDSeperator = " ";
					
					MemberIDSeperator += ":";
					
					if ( Flags & kEncodeFlags_MemberNameSeperator_SuffixSpace )
						MemberIDSeperator += " ";
				}
				else
					MemberIDSeperator = ":";
				
				OutString += "{";
				
				if ( MemberCount == 0 )
				{
					
					if ( ( ( Flags & kEncodeFlags_AllObjectNewlines ) != 0 ) && ( ( Flags & kEncodeFlags_Pretty ) != 0 ) )
					{
						
						OutString += NewlineSequence;
						OutString += EndIndentString;
						OutString += "}";
						
					}
					else
						OutString += "}";
					
					return true;
					
				}
				
				bool PrettyNewlines = ( ( ( Flags & kEncodeFlags_Pretty ) != 0 ) && ( ( ( Flags & kEncodeFlags_AllObjectNewlines ) != 0 ) || ( ( ( Flags & kEncodeFlags_NoRecursiveObjectNewlines ) == 0 ) && IsObjectObject ) ) );
				
				for ( uint32_t I = 0; I < MemberCount; I ++ )
				{
					
					if ( PrettyNewlines )
					{
						
						OutString += NewlineSequence;
						OutString += IndentString;
						
					}
					
					std :: string ItemKey;
					IType * Member = NULL;
					
					ObjectValue -> GetKeyByIndex ( I, ItemKey );
					Member = ObjectValue -> GetItemByIndex ( I );
					
					String TempString ( ItemKey );
					
					if ( ! Encode ( & TempString, OutString, BaseIndent + 1 ) )
						return false;
					
					OutString += MemberIDSeperator;
					
					if ( ( ( Flags & kEncodeFlags_Pretty ) != 0 ) && ( ( Flags & kEncodeFlags_ArrayObjectMemberSeperateLine ) != 0 ) && IsObjectObject )
					{
						
						if ( Member != NULL )
						{
							
							IType :: DataType Type = Member -> GetType ();
							
							if ( ( Type == IType :: kDataType_Array ) || ( Type == IType :: kDataType_Object ) )
							{
								
								OutString += NewlineSequence;
								OutString += IndentString;
								
							}
							
						}
						
					}
					
					if ( ! Encode ( Member, OutString, BaseIndent + 1 ) )
						return false;
					
					if ( ( I + 1 < MemberCount ) || ( ( Flags & kEncodeFlags_TrailingCommaLists ) != 0 ) )
						OutString += ",";
					
				}
				
				if ( PrettyNewlines )
				{
					
					OutString += NewlineSequence;
					OutString += EndIndentString;
					OutString += "}";
					
				}
				else
					OutString += ( ( Flags & kEncodeFlags_Pretty ) != 0 ) ? " }" : "}";
				
				return true;
				
			}
			
			return false;
			
		}
		break;
		
	}
	
}
