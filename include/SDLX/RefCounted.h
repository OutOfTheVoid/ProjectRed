#ifndef SDLX_REFCOUNTED_H
#define SDLX_REFCOUNTED_H

#include <SDLX/SDLX.h>

#include <stdint.h>

namespace SDLX
{

	class RefCounted
	{
	public:
		
		RefCounted ();
		RefCounted ( uint32_t InitialCount );
		virtual ~RefCounted ();
		
		void Own ();
		void Disown ();
		
	protected:
		
		virtual void Delete ();
		
		uint32_t RefCount;
		
	};

};

#endif
