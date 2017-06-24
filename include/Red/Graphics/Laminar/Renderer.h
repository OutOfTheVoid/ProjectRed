#ifndef RED_GRAPHICS_LAMINAR_RENDERER_H
#define RED_GRAPHICS_LAMINAR_RENDERER_H

#include <Red/Graphics/Laminar/Laminar.h>
#include <Red/Graphics/Laminar/Sprite.h>

#include <Xenon/GPU/Texture2D.h>
#include <Xenon/GPU/FrameBuffer.h>
#include <Xenon/GPU/VertexArray.h>
#include <Xenon/GPU/VertexBuffer.h>
#include <Xenon/GPU/IndexBuffer.h>
#include <Xenon/GPU/VertexShader.h>
#include <Xenon/GPU/FragmentShader.h>
#include <Xenon/GPU/ShaderProgram.h>
#include <Xenon/GPU/InstancedIndexedDrawCall.h>

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
				
				Renderer ( Xenon::GPU::Context * RenderContext, uint32_t TargetWidth, uint32_t TargetHeight, uint32_t InitialLayerCount = 10, bool DefaultMaskModeCleared = false, bool OrphanGeometry = true );
				~Renderer ();
				
				void SetRenderTarget ( Xenon::GPU :: FrameBuffer * TargetBuffer );
				
				void Resize ( uint32_t TargetWidth, uint32_t TargetHeight );
				
				// Note: Calling AddSprite on a sprite that has already been added will just move it to the selected layer, rather than duplicate it.
				void AddSprite ( Sprite * Instance, uint32_t Layer );
				void RemoveSprite ( Sprite * Instance );
				
				void SetLayerMaskMode ( uint32_t Layer, bool Cleared );
				
				void Begin ();
				void End ();
				
				void Render ();
				
				//void Destroy ();
				
			private:
				
				typedef struct
				{
					
					Xenon::GPU::ITexture * Texture;
					uint32_t UsageCount;
					
				} TextureUsageRecord;
				
				typedef struct LayerModeGeometry_Struct
				{
					
					LayerModeGeometry_Struct ( uint32_t MinElementCount, Xenon::GPU :: IndexBuffer * QuadBuffer );
					~LayerModeGeometry_Struct ();
					
					void SizeTo ( uint32_t ElementCount );
					
					Xenon::GPU :: VertexBuffer TransformBuff;
					uint32_t TransformBufferSize;
					
					uint32_t TransformArraySize;
					uint32_t TransformArrayBufferSize;
					
					std :: vector <TextureUsageRecord> TextureUseRecords;
					
					uint32_t * TextureIndexArray;
					Xenon::Math :: Matrix3x3 * TransformArray;
					int64_t * TransformIterationList;
					Sprite ** TransformSourceList;
					
					Xenon::GPU :: VertexArray VArray;
					
					Xenon::GPU :: InstancedIndexedDrawCall DrawCall;
					
					bool Dirty;
					
				} LayerModeGeometry;
				
				typedef struct
				{
					
					Sprite * OverlayListHead;
					uint32_t OverlayListLength;
					LayerModeGeometry * OverlayListGeometry;
					
					Sprite * AddListHead;
					uint32_t AddListLength;
					LayerModeGeometry * AddListGeometry;
					
					Sprite * SubtractListHead;
					uint32_t SubtractListLength;
					LayerModeGeometry * SubtractListGeometry;
					
					Sprite * MultiplyListHead;
					uint32_t MultiplyListLength;
					LayerModeGeometry * MultiplyListGeometry;
					
					Sprite * MaxListHead;
					uint32_t MaxListLength;
					LayerModeGeometry * MaxListGeometry;
					
					Sprite * MinListHead;
					uint32_t MinListLength;
					LayerModeGeometry * MinListGeometry;
					
					Sprite * MaskListHead;
					uint32_t MaskListLength;
					LayerModeGeometry * MaskListGeometry;
					
					Sprite * NegativeMaskListHead;
					uint32_t NegativeMaskListLength;
					LayerModeGeometry * NegativeMaskListGeometry;
					
					bool ClearMasked;
					
				} RenderLayer;
				
				void SetupGPUResources ();
				void FreeGPUResources ();
				
				void PrepGeometry ();
				void UpdateGeometry ();
				
				void PrepGeometryList ( LayerModeGeometry *& GeometryPTR, Sprite * ListHead, uint32_t ListLength, Xenon::GPU :: ShaderProgram * Program, Xenon::GPU :: IndexBuffer * QuadIndexBuffer );
				void UpdateGeometryBuffers ( LayerModeGeometry & Geometry );
				
				Xenon::GPU :: Context * RenderContext;
				
				bool DefaultMaskModeCleared;
				
				std :: vector <RenderLayer *> Layers;
				
				Xenon::GPU :: Texture2D LayerMaskTex;
				Xenon::GPU :: FrameBuffer LayerMaskBuffer;
				
				Xenon::GPU :: Texture2D AccumulatorTex;
				Xenon::GPU :: FrameBuffer AccumulatorBuffer;
				
				Xenon::GPU :: FrameBuffer * TargetBuffer;
				
				Xenon::GPU :: IndexBuffer QuadIBuff;
				Xenon::GPU :: VertexBuffer QuadVBuff;
				
				static const char * kQuadVShader_String;
				Xenon::GPU :: VertexShader QuadVShader;
				
				static const char * kMaskFShader_String;
				Xenon::GPU :: FragmentShader MaskFShader;
				Xenon::GPU :: ShaderProgram MaskProgram;
				
				static const char * kColorFShader_String;
				Xenon::GPU :: FragmentShader ColorFShader;
				Xenon::GPU :: ShaderProgram ColorProgram;
				
				bool Running;
				bool GPUAlloc;
				
				uint32_t TargetWidth;
				uint32_t TargetHeight;
				
				bool OrphanGeometry;
				
			};
			
		}
		
	}
	
}

#endif
