#ifndef RED_GRAPHICS_LAMINAR_RENDERER_H
#define RED_GRAPHICS_LAMINAR_RENDERER_H

#include <Red/Graphics/Laminar/Laminar.h>
#include <Red/Graphics/Laminar/Sprite.h>

#include <Xenon/GPU/Texture2D.h>
#include <Xenon/GPU/FrameBuffer.h>
#include <Xenon/GPU/VertexArray.h>
#include <Xenon/GPU/VertexBuffer.h>
#include <Xenon/GPU/IndexBuffer.h>

#include <vector>

namespace Red
{
	
	namespace Graphics
	{
		
		namespace Laminar
		{
			
			class Renderer
			{
			public:
				
				Renderer ( uint32_t TargetWidth, uint32_t TargetHeight, uint32_t InitialLayerCount = 100, bool DefaultMaskModeCleared = true );
				~Renderer ();
				
				void SetRenderTarget ( Xenon::GPU :: FrameBuffer * TargetBuffer );
				
				// Note: Calling AddSprite on a sprite that has already been added will just move it to the selected layer, rather than duplicate it.
				void AddSprite ( Sprite * Instance, uint32_t Layer );
				void RemoveSprite ( Sprite * Instance );
				
				void SetLayerMaskMode ( uint32_t Layer, bool Cleared );
				
				void Begin ();
				void End ();
				
				void Render ();
				
			private:
				
				void SetupGPUResources ();
				void FreeGPUResources ();
				
				typedef struct LayerModeGeometry_Struct
				{
					
					LayerModeGeometry_Struct ();
					~LayerModeGeometry_Struct ();
					
					Xenon::GPU :: VertexBuffer TransformBuff;
					Xenon::GPU :: VertexArray VArray;
					
				} LayerModeGeometry;
				
				typedef struct
				{
					
					Sprite * OverlayListHead;
					uint32_t OverlayListLength;
					
					Sprite * AddListHead;
					uint32_t AddListLength;
					
					Sprite * SubtractListHead;
					uint32_t SubtractListLength;
					
					Sprite * MultiplyListHead;
					uint32_t MultiplyListLength;
					
					Sprite * MaxListHead;
					uint32_t MaxListLength;
					
					Sprite * MinListHead;
					uint32_t MinListLength;
					
					Sprite * MaskListHead;
					uint32_t MaskListLength;
					
					Sprite * NegativeMaskListHead;
					uint32_t NegativeMaskListLength;
					
					bool ClearMasked;
					
				} RenderLayer;
				
				bool DefaultMaskModeCleared;
				
				std :: vector <RenderLayer *> Layers;
				
				Xenon::GPU :: Texture2D LayerMaskTex;
				Xenon::GPU :: FrameBuffer LayerMaskBuffer;
				
				Xenon::GPU :: Texture2D AccumulatorTex;
				Xenon::GPU :: FrameBuffer AccumulatorBuffer;
				
				Xenon::GPU :: FrameBuffer * TargetBuffer;
				
				Xenon::GPU :: IndexBuffer QuadIBuff;
				Xenon::GPU :: VertexBuffer QuadVBuff;
				
				bool Running;
				bool GPUAlloc;
				
				uint32_t TargetWidth;
				uint32_t TargetHeight;
				
			};
			
		}
		
	}
	
}

#endif
