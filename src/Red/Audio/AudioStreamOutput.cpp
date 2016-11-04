#include <Red/Audio/AudioStreamOutput.h>

Red::Audio::AudioStreamOutput :: AudioStreamOutput ( IAudioOutputDevice * OutputDevice, uint32_t MaxChannelCount ):
	CallbackClosure ( & Red::Audio::AudioStreamOutput :: AudioCallback, this ),
	Sources ( new IStreamSource * [ ( MaxChannelCount == 0 ) ? OutputDevice -> GetChannelCount () : MaxChannelCount ] ),
	ChannelCount ( MaxChannelCount ),
	OutputDevice ( OutputDevice )
{
	
	for ( uint32_t I = 0; I < MaxChannelCount; I ++ )
		Sources [ I ] = NULL;
	
	if ( OutputDevice != NULL )
	{
		
		OutputDevice -> Reference ();
		OutputDevice -> SetFillCallback ( & CallbackClosure );
		
	}
	
}

Red::Audio::AudioStreamOutput :: ~AudioStreamOutput ()
{

	SetOutputDevice ( NULL );
	
	for ( uint32_t I = 0; I < ChannelCount; I ++ )
	{
		
		if ( Sources [ I ] != NULL )
		{
			
			Sources [ I ] -> Dereference ();
			Sources [ I ] = NULL;
			
		}
		
	}
	
	delete [] Sources;
	
}

void Red::Audio::AudioStreamOutput :: SetOutputDevice ( IAudioOutputDevice * OutputDevice )
{
	
	if ( this -> OutputDevice != NULL )
	{
		
		if ( this -> OutputDevice == OutputDevice )
			return;
		
		this -> OutputDevice -> SetFillCallback ( NULL );
		this -> OutputDevice -> Dereference ();
		
	}
	
	this -> OutputDevice = OutputDevice;
	
	if ( OutputDevice != NULL )
	{
		
		OutputDevice -> Reference ();
		OutputDevice -> SetFillCallback ( & CallbackClosure );
		
	}
	
}

void Red::Audio::AudioStreamOutput :: SetStreamSource ( uint32_t Channel, IStreamSource * Source )
{
	
	if ( Channel >= ChannelCount )
		return;
	
	if ( Sources [ Channel ] == Source )
		return;
	
	if ( this -> OutputDevice != NULL )
		OutputDevice -> Lock ();
	
	if ( Sources [ Channel ] != NULL )
		Sources [ Channel ] -> Dereference ();
	
	Sources [ Channel ] = Source;
	
	if ( Source != NULL )
		Source -> Reference ();
	
	if ( this -> OutputDevice != NULL )
		OutputDevice -> Unlock ();
	
}

void Red::Audio::AudioStreamOutput :: Start ()
{
	
	if ( this -> OutputDevice != NULL )
		OutputDevice -> Start ();
	
}

void Red::Audio::AudioStreamOutput :: Stop ()
{
	
	if ( this -> OutputDevice != NULL )
		OutputDevice -> Stop ();
	
}

void Red::Audio::AudioStreamOutput :: AudioCallback ( uint8_t * Data, int DataSize )
{
	
	(void) DataSize;

	if ( OutputDevice == NULL )
		return;
	
	AudioBuffer FillBuffer ( reinterpret_cast <void *> ( Data ), OutputDevice -> GetSampleFormat (), OutputDevice -> GetChannelCount (), OutputDevice -> GetSampleSize () );
	FillBuffer.Reference (); // Prevent accidental destruction
	
	uint32_t ActiveChannelCount = ( ChannelCount < OutputDevice -> GetChannelCount () ) ? ChannelCount : OutputDevice -> GetChannelCount ();
	uint32_t I;
	
	for ( I = 0; I < ActiveChannelCount; I ++ )
	{
		
		if ( Sources [ I ] != NULL )
		{
			
			IStreamSource :: StreamFillCode FillCode = Sources [ I ] -> FillAudioBuffer ( & FillBuffer, I );
			
			switch ( FillCode )
			{
				
				case IStreamSource :: kStreamFillCode_Success_Normal:
					break;
				
				case IStreamSource :: kStreamFillCode_Success_ControlParameter_Constant:	
				case IStreamSource :: kStreamFillCode_Success_DC:
				{
					
					if ( ( FillBuffer.GetDataType () == kAudioBufferType_Float32_LittleEndian ) || ( FillBuffer.GetDataType () == kAudioBufferType_Float32_BigEndian ) )
						FillBuffer.ClearBufferFloat ( I, FillBuffer.ReadSampleFloat ( I, 0 ) );
					else
						FillBuffer.ClearBufferInt ( I, FillBuffer.ReadSampleInt ( I, 0 ) );
					
				}
				break;
				
				case IStreamSource :: kStreamFillCode_Success_Silence:
				default:
					
					FillBuffer.ClearBufferFloat ( I, FillBuffer.GetCenterValueFloat () );
					
					break;
				
			}
			
		}
		else
			FillBuffer.ClearBufferInt ( I );
		
	}
	
	for ( I = ActiveChannelCount; I < OutputDevice -> GetChannelCount (); I ++ )
		FillBuffer.ClearBufferFloat ( I, FillBuffer.GetCenterValueFloat () );
	
}



