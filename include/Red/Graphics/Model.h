#ifndef RED_GRAPHICS_MODEL_H
#define RED_GRAPHICS_MODEL_H

#include <Red/Graphics/Graphics.h>

#include <Red/Util/RefCounted.h>

#include <Xenon/GPU/VertexArray.h>

#include <Xenon/Geometry/Mesh.h>

namespace Red
{
	
	namespace Graphics
	{
		
		class DeferredModelRenderer;
		
		class Model : public Util :: RefCounted
		{
		public:
			
			enum DrawMethod
			{
				
				kDrawMethod_Single = 0,
				kDrawMethod_Instanced = 1
				
			};
			
			Model ( Xenon::Geometry :: Mesh * ModelMesh, DrawMethod Method = kDrawMethod_Single );
			~Model ();
			
			
			
		private:
			
			friend class DeferredModelRenderer;
			
			void GPUAlloc ();
			void GPUFree ();
			
			Xenon::GPU :: VertexArray & GetVertexArray ();
			void InternalApplyVertexArray ();
			
			DrawMethod Method;
			uint32_t InstanceCount;
			
			Xenon::GPU::VertexArray VertexAttributes;
			
			Xenon::Geometry :: Mesh * ModelMesh;
			
		};
		
	}
	
}

#endif
