#include <Xenon/Xenon.h>

#include <Xenon/GPU/GLInclude.h>

void Xenon::Init()
{
	
#ifdef XENON_GL3W_GL_LOADER

	gl3wInit ();

#endif

}
