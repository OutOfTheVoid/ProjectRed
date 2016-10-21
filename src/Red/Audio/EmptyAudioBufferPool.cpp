#include <Red/Audio/EmptyAudioBufferPool.h>

Red::Audio::EmptyAudioBufferPool :: EmptyAudioBufferPool ( uint32_t InitialPool, uint32_t MaxFree ):
	MaxFree ( MaxFree == 0 ? 0xFFFFFFFF : MaxFree ),
	Pool (),
	PoolLock (),
	OnUnReferenceAudioBufferClosure ( & Red::Audio::EmptyAudioBufferPool :: OnUnReferenceAudioBuffer, this )
{
	
	for ( uint32_t I = 0; I < InitialPool; I ++ )
		Pool.push_back ( new AudioBuffer ( NULL, kAudioBufferType_UInt8, 0, 0, NULL, NULL ) );
		// Actual object here is garbage. We just want to allocate storage.
	
}

Red::Audio::EmptyAudioBufferPool :: ~EmptyAudioBufferPool ()
{
	
	DestroyPool ();
	
}

Red::Audio :: AudioBuffer * Red::Audio::EmptyAudioBufferPool :: New ( void * Data, AudioBufferType Type, uint32_t Channels, uint32_t SampleCount, Util :: IFunction1 <void, void *> * OnFree )
{
	
	PoolLock.Lock ();
	
	if ( Pool.size () != 0 )
	{
		
		AudioBuffer * NewBuffer = Pool.back ();
		Pool.pop_back ();
		
		PoolLock.Unlock ();
		
		this -> Reference ();
		
		return new ( reinterpret_cast <void *> ( NewBuffer ) ) AudioBuffer ( Data, Type, Channels, SampleCount, OnFree, & OnUnReferenceAudioBufferClosure );
		
	}
	
	PoolLock.Unlock ();
	
	this -> Reference ();
	
	return new AudioBuffer ( Data, Type, Channels, SampleCount, OnFree, & OnUnReferenceAudioBufferClosure );
	
}

void Red::Audio::EmptyAudioBufferPool :: DestroyPool ()
{
	
	PoolLock.Lock ();
	
	while ( Pool.size () > 0 )
	{
		
		delete Pool.back ();
		Pool.pop_back ();
		
	}
	
	PoolLock.Unlock ();
	
}

void Red::Audio::EmptyAudioBufferPool :: SetFreeCap ( uint32_t MaxFree )
{
	
	if ( MaxFree == 0 )
		MaxFree = 0xFFFFFFFF;
	
	PoolLock.Lock ();
	
	this -> MaxFree = MaxFree;
	
	while ( Pool.size () > 0 )
	{
		
		delete Pool.back ();
		Pool.pop_back ();
		
	}
	
	PoolLock.Unlock ();
	
}

void Red::Audio::EmptyAudioBufferPool :: PreallocateTo ( uint32_t ExpectedCount )
{
	
	PoolLock.Lock ();
	
	if ( ExpectedCount > MaxFree )
		MaxFree = ExpectedCount;
	
	while ( Pool.size () < ExpectedCount )
		Pool.push_back ( new AudioBuffer ( NULL, kAudioBufferType_UInt8, 0, 0, NULL, NULL ) );
	
	PoolLock.Unlock ();
	
}


bool Red::Audio::EmptyAudioBufferPool :: OnUnReferenceAudioBuffer ( AudioBuffer * Buffer )
{
	
	PoolLock.Lock ();
	
	if ( Pool.size () < MaxFree )
	{
		
		Buffer -> ~AudioBuffer ();
		Pool.push_back ( Buffer );
		
		PoolLock.Unlock ();
		
		this -> Dereference ();
		
		return false;
		
	}
	
	PoolLock.Unlock ();
	
	this -> Dereference ();
	
	return true;
	
}
