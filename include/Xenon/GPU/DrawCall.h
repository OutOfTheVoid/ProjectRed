#ifndef XENON_GPU_DRAWCALL_H
#define XENON_GPU_DRAWCALL_H

#include <Xenon/GPU/GPU.h>
#include <Xenon/GPU/GLInclude.h>

#include <Red/Util/IRefCounted.h>

namespace Xenon
{
	
	namespace GPU
	{
		
		class DrawCall : public virtual Red::Util :: IRefCounted
		{
		public:
				
			typedef GLenum DrawMode;
			
			static const DrawMode kDrawMode_Point = GL_POINTS;
			
			static const DrawMode kDrawMode_Line_Strip = GL_LINE_STRIP;
			static const DrawMode kDrawMode_Line_Loop = GL_LINE_LOOP;
			static const DrawMode kDrawMode_Line = GL_LINES;
			static const DrawMode kDrawMode_Line_Adjecent = GL_LINES_ADJACENCY;
			static const DrawMode kDrawMode_Line_Strip_Adjacent = GL_LINE_STRIP_ADJACENCY;
			
			static const DrawMode kDrawMode_Triangle_Strip = GL_TRIANGLE_STRIP;
			static const DrawMode kDrawMode_Triangle_Fan = GL_TRIANGLE_FAN;
			static const DrawMode kDrawMode_Triangle = GL_TRIANGLES;
			static const DrawMode kDrawMode_Triangle_Strip_Adjacent = GL_TRIANGLE_STRIP_ADJACENCY;
			static const DrawMode kDrawMode_Triangle_Adjacency = GL_TRIANGLES_ADJACENCY;
			
			static const DrawMode kDrawMode_Patches = GL_PATCHES;
			
			virtual ~DrawCall () {};
			
			virtual void Draw () = 0;
			
		};
		
	}
	
}

#endif
