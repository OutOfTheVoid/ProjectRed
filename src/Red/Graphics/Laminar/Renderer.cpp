#include <Red/Graphics/Laminar/Renderer.h>

#include <Xenon/Math/Vec2.h>
#include <Xenon/Math/Transform2D.h>
#include <Xenon/Math/Matrix3x3.h>

Red::Graphics::Laminar::Renderer :: Renderer ( uint32_t TargetWidth, uint32_t TargetHeight, uint32_t InitialLayerCount, bool DefaultMasking ):
	DefaultMaskModeCleared ( DefaultMasking ),
	Layers (),
	LayerMaskTex (),
	LayerMaskBuffer (),
	AccumulatorTex (),
	AccumulatorBuffer (),
	TargetBuffer ( NULL ),
	Running ( false ),
	GPUAlloc ( false ),
	TargetWidth ( TargetWidth ),
	TargetHeight ( TargetHeight ),
	QuadIBuff ( Xenon::GPU::IndexBuffer :: kUsageType_Static_Draw, Xenon::GPU::IndexBuffer :: kIndexType_UBytes ),
	QuadVBuff ( Xenon::GPU::VertexBuffer :: kUsageType_Static_Draw )
{
	
	for ( uint32_t I = 0; I < InitialLayerCount; I ++ )
	{
		
		RenderLayer * Layer = new RenderLayer ();
		
		Layer -> OverlayListHead = NULL;
		Layer -> OverlayListLength = 0;
		Layer -> AddListHead = NULL;
		Layer -> AddListLength = 0;
		Layer -> SubtractListHead = NULL;
		Layer -> SubtractListLength = 0;
		Layer -> MultiplyListHead = NULL;
		Layer -> MultiplyListLength = 0;
		Layer -> MaxListHead = NULL;
		Layer -> MaxListLength = 0;
		Layer -> MinListHead = NULL;
		Layer -> MinListLength = 0;
		Layer -> MaskListHead = NULL;
		Layer -> MaskListLength = 0;
		Layer -> NegativeMaskListHead = NULL;
		Layer -> NegativeMaskListLength = 0;
		
		Layer -> ClearMasked = DefaultMasking;
		
		Layers.push_back ( Layer );
		
	}
	
}

Red::Graphics::Laminar::Renderer :: ~Renderer ()
{
}

Red::Graphics::Laminar::Renderer::LayerModeGeometry_Struct :: LayerModeGeometry_Struct ():
	TransformBuff ( Xenon::GPU::VertexBuffer :: kUsageType_Dynamic_Draw ),
	VArray ()
{
}

Red::Graphics::Laminar::Renderer::LayerModeGeometry_Struct :: ~LayerModeGeometry_Struct ()
{
}
			
void Red::Graphics::Laminar::Renderer :: SetLayerMaskMode ( uint32_t Layer, bool Cleared )
{
	
	while ( Layer >= Layers.size () )
	{
		
		RenderLayer * Layer = new RenderLayer ();
		
		Layer -> OverlayListHead = NULL;
		Layer -> OverlayListLength = 0;
		Layer -> AddListHead = NULL;
		Layer -> AddListLength = 0;
		Layer -> SubtractListHead = NULL;
		Layer -> SubtractListLength = 0;
		Layer -> MultiplyListHead = NULL;
		Layer -> MultiplyListLength = 0;
		Layer -> MaxListHead = NULL;
		Layer -> MaxListLength = 0;
		Layer -> MinListHead = NULL;
		Layer -> MinListLength = 0;
		Layer -> MaskListHead = NULL;
		Layer -> MaskListLength = 0;
		Layer -> NegativeMaskListHead = NULL;
		Layer -> NegativeMaskListLength = 0;
		
		Layer -> ClearMasked = DefaultMaskModeCleared;
		
		Layers.push_back ( Layer );
		
	}
	
	Layers [ Layer ] -> ClearMasked = Cleared;
	
}

void Red::Graphics::Laminar::Renderer :: SetRenderTarget ( Xenon::GPU :: FrameBuffer * TargetBuffer )
{
	
	if ( TargetBuffer == NULL )
	{
		
		if ( this -> TargetBuffer == NULL )
			return;
		
		FreeGPUResources ();
		
		this -> TargetBuffer -> Dereference ();
		this -> TargetBuffer = NULL;
		
	}
	else
	{
		
		if ( this -> TargetBuffer != NULL )
			this -> TargetBuffer -> Dereference ();
		
		this -> TargetBuffer = TargetBuffer;
		TargetBuffer -> Reference ();
		
		if ( Running )
			SetupGPUResources ();
		
	}
	
}

void Red::Graphics::Laminar::Renderer :: AddSprite ( Sprite * Instance, uint32_t Layer )
{
	
	if ( Instance -> RenderInstance != NULL )
		Instance -> RenderInstance -> RemoveSprite ( Instance );
	
	Instance -> Layer = Layer;
	
	while ( Layer >= Layers.size () )
	{
		
		RenderLayer * Layer = new RenderLayer ();
		
		Layer -> OverlayListHead = NULL;
		Layer -> OverlayListLength = 0;
		Layer -> AddListHead = NULL;
		Layer -> AddListLength = 0;
		Layer -> SubtractListHead = NULL;
		Layer -> SubtractListLength = 0;
		Layer -> MultiplyListHead = NULL;
		Layer -> MultiplyListLength = 0;
		Layer -> MaxListHead = NULL;
		Layer -> MaxListLength = 0;
		Layer -> MinListHead = NULL;
		Layer -> MinListLength = 0;
		Layer -> MaskListHead = NULL;
		Layer -> MaskListLength = 0;
		Layer -> NegativeMaskListHead = NULL;
		Layer -> NegativeMaskListLength = 0;
		
		Layer -> ClearMasked = DefaultMaskModeCleared;
		
		Layers.push_back ( Layer );
		
	}
	
	Instance -> RenderInstance = this;
	
	switch ( Instance -> Layout.Mode )
	{
		
		case kRenderMode_Default:
			Instance -> Layout.Mode = kRenderMode_Overlay;
		case kRenderMode_Overlay:
			Layers [ Instance -> Layer ] -> OverlayListHead -> Last = Instance;
			Instance -> Next = Layers [ Instance -> Layer ] -> OverlayListHead -> Last;
			Layers [ Instance -> Layer ] -> OverlayListHead = Instance;
			break;
			
		case kRenderMode_Add:
			Layers [ Instance -> Layer ] -> AddListHead -> Last = Instance;
			Instance -> Next = Layers [ Instance -> Layer ] -> AddListHead -> Last;
			Layers [ Instance -> Layer ] -> AddListHead = Instance;
			break;
			
		case kRenderMode_Subtract:
			Layers [ Instance -> Layer ] -> SubtractListHead -> Last = Instance;
			Instance -> Next = Layers [ Instance -> Layer ] -> SubtractListHead -> Last;
			Layers [ Instance -> Layer ] -> SubtractListHead = Instance;
			break;
			
		case kRenderMode_Multiply:
			Layers [ Instance -> Layer ] -> MultiplyListHead -> Last = Instance;
			Instance -> Next = Layers [ Instance -> Layer ] -> MultiplyListHead -> Last;
			Layers [ Instance -> Layer ] -> MultiplyListHead = Instance;
			break;
			
		case kRenderMode_Max:
			Layers [ Instance -> Layer ] -> MaxListHead -> Last = Instance;
			Instance -> Next = Layers [ Instance -> Layer ] -> MaxListHead -> Last;
			Layers [ Instance -> Layer ] -> MaxListHead = Instance;
			break;
								
		case kRenderMode_Min:
			Layers [ Instance -> Layer ] -> MinListHead -> Last = Instance;
			Instance -> Next = Layers [ Instance -> Layer ] -> MinListHead -> Last;
			Layers [ Instance -> Layer ] -> MinListHead = Instance;
			break;
			
		case kRenderMode_Mask:
			Layers [ Instance -> Layer ] -> MaskListHead -> Last = Instance;
			Instance -> Next = Layers [ Instance -> Layer ] -> MaskListHead -> Last;
			Layers [ Instance -> Layer ] -> MaskListHead = Instance;
			break;
			
		case kRenderMode_NegativeMask:
			Layers [ Instance -> Layer ] -> NegativeMaskListHead -> Last = Instance;
			Instance -> Next = Layers [ Instance -> Layer ] -> NegativeMaskListHead -> Last;
			Layers [ Instance -> Layer ] -> NegativeMaskListHead = Instance;
			break;
		
	}
	
}

void Red::Graphics::Laminar::Renderer :: RemoveSprite ( Sprite * Instance )
{
	
	if ( Instance -> RenderInstance != this )
		return;
	
	if ( Instance -> Next == NULL )
	{
		
		if ( Instance -> Last == NULL )
		{
			
			switch ( Instance -> Layout.Mode )
			{
				
				case kRenderMode_Overlay:
					Layers [ Instance -> Layer ] -> OverlayListHead = NULL;
					Layers [ Instance -> Layer ] -> OverlayListLength --;
					break;
					
				case kRenderMode_Add:
					Layers [ Instance -> Layer ] -> AddListHead = NULL;
					Layers [ Instance -> Layer ] -> AddListLength --;
					break;
					
				case kRenderMode_Subtract:
					Layers [ Instance -> Layer ] -> SubtractListHead = NULL;
					Layers [ Instance -> Layer ] -> SubtractListLength --;
					break;
					
				case kRenderMode_Multiply:
					Layers [ Instance -> Layer ] -> MultiplyListHead = NULL;
					Layers [ Instance -> Layer ] -> MultiplyListLength --;
					break;
					
				case kRenderMode_Max:
					Layers [ Instance -> Layer ] -> MaxListHead = NULL;
					Layers [ Instance -> Layer ] -> MaxListLength --;
					break;
					
				case kRenderMode_Min:
					Layers [ Instance -> Layer ] -> MinListHead = NULL;
					Layers [ Instance -> Layer ] -> MinListLength --;
					break;
					
				case kRenderMode_Mask:
					Layers [ Instance -> Layer ] -> MaskListHead = NULL;
					Layers [ Instance -> Layer ] -> MaskListLength --;
					break;
					
				case kRenderMode_NegativeMask:
					Layers [ Instance -> Layer ] -> NegativeMaskListHead = NULL;
					Layers [ Instance -> Layer ] -> NegativeMaskListLength --;
					break;
					
				case kRenderMode_Default:
				default:
					break;
				
			}
			
		}
		else
		{
			
			Instance -> Last -> Next = NULL;
			Instance -> Last = NULL;
			
			switch ( Instance -> Layout.Mode )
			{
				
				case kRenderMode_Overlay:
					Layers [ Instance -> Layer ] -> OverlayListLength --;
					break;
					
				case kRenderMode_Add:
					Layers [ Instance -> Layer ] -> AddListLength --;
					break;
					
				case kRenderMode_Subtract:
					Layers [ Instance -> Layer ] -> SubtractListLength --;
					break;
					
				case kRenderMode_Multiply:
					Layers [ Instance -> Layer ] -> MultiplyListLength --;
					break;
					
				case kRenderMode_Max:
					Layers [ Instance -> Layer ] -> MaxListLength --;
					break;
					
				case kRenderMode_Min:
					Layers [ Instance -> Layer ] -> MinListLength --;
					break;
					
				case kRenderMode_Mask:
					Layers [ Instance -> Layer ] -> MaskListLength --;
					break;
					
				case kRenderMode_NegativeMask:
					Layers [ Instance -> Layer ] -> NegativeMaskListLength --;
					break;
					
				default:
				break;
				
			}
			
		}
		
	}
	else
	{
		
		Instance -> Next -> Last = Instance -> Last;
		
		if ( Instance -> Last == NULL )
		{
			
			switch ( Instance -> Layout.Mode )
			{
				
				case kRenderMode_Overlay:
					Layers [ Instance -> Layer ] -> OverlayListHead = Instance -> Next;
					Layers [ Instance -> Layer ] -> OverlayListLength --;
					break;
					
				case kRenderMode_Add:
					Layers [ Instance -> Layer ] -> AddListHead = Instance -> Next;
					Layers [ Instance -> Layer ] -> AddListLength --;
					break;
					
				case kRenderMode_Subtract:
					Layers [ Instance -> Layer ] -> SubtractListHead = Instance -> Next;
					Layers [ Instance -> Layer ] -> SubtractListLength --;
					break;
					
				case kRenderMode_Multiply:
					Layers [ Instance -> Layer ] -> MultiplyListHead = Instance -> Next;
					Layers [ Instance -> Layer ] -> MultiplyListLength --;
					break;
					
				case kRenderMode_Max:
					Layers [ Instance -> Layer ] -> MaxListHead = Instance -> Next;
					Layers [ Instance -> Layer ] -> MaxListLength --;
					break;
					
				case kRenderMode_Min:
					Layers [ Instance -> Layer ] -> MinListHead = Instance -> Next;
					Layers [ Instance -> Layer ] -> MinListLength --;
					break;
					
				case kRenderMode_Mask:
					Layers [ Instance -> Layer ] -> MaskListHead = Instance -> Next;
					Layers [ Instance -> Layer ] -> MaskListLength --;
					break;
					
				case kRenderMode_NegativeMask:
					Layers [ Instance -> Layer ] -> NegativeMaskListHead = Instance -> Next;
					Layers [ Instance -> Layer ] -> NegativeMaskListLength --;
					break;
					
				case kRenderMode_Default:
				default:
					break;
				
			}
			
			Instance -> Next = NULL;
			
		}
		else
		{
			
			Instance -> Last -> Next = Instance -> Next;
			Instance -> Next = NULL;
			Instance -> Last = NULL;
			
			switch ( Instance -> Layout.Mode )
			{
				
				case kRenderMode_Overlay:
					Layers [ Instance -> Layer ] -> OverlayListLength --;
					break;
					
				case kRenderMode_Add:
					Layers [ Instance -> Layer ] -> AddListLength --;
					break;
					
				case kRenderMode_Subtract:
					Layers [ Instance -> Layer ] -> SubtractListLength --;
					break;
					
				case kRenderMode_Multiply:
					Layers [ Instance -> Layer ] -> MultiplyListLength --;
					break;
					
				case kRenderMode_Max:
					Layers [ Instance -> Layer ] -> MaxListLength --;
					break;
					
				case kRenderMode_Min:
					Layers [ Instance -> Layer ] -> MinListLength --;
					break;
					
				case kRenderMode_Mask:
					Layers [ Instance -> Layer ] -> MaskListLength --;
					break;
					
				case kRenderMode_NegativeMask:
					Layers [ Instance -> Layer ] -> NegativeMaskListLength --;
					break;
					
				default:
				break;
				
			}
			
		}
		
	}
	
	Instance -> RenderInstance = NULL;
	
}

void Red::Graphics::Laminar::Renderer :: Begin ()
{
	
	if ( Running )
		return;
	
	Running = true;
	
	SetupGPUResources ();
	
}

void Red::Graphics::Laminar::Renderer :: End ()
{
	
	Running = false;
	
}

void Red::Graphics::Laminar::Renderer :: FreeGPUResources ()
{
	
	if ( ! GPUAlloc )
		return;
	
	LayerMaskTex.GPUResourceFree ();
	AccumulatorTex.GPUResourceFree ();
	AccumulatorBuffer.GPUResourceFree ();
	
	QuadVBuff.GPUResourceFree ();
	QuadIBuff.GPUResourceFree ();
	
	Running = false;
	GPUAlloc = false;
	
}

void Red::Graphics::Laminar::Renderer :: SetupGPUResources ()
{
	
	if ( GPUAlloc )
		return;
	
	LayerMaskTex.GPUResourceAlloc ();
	LayerMaskBuffer.GPUResourceAlloc ();
	
	AccumulatorTex.GPUResourceAlloc ();
	AccumulatorBuffer.GPUResourceAlloc ();
	
	QuadVBuff.GPUResourceAlloc ();
	QuadIBuff.GPUResourceAlloc ();
	
	LayerMaskTex.BlankTextureImage ( 0, Xenon::GPU::Texture2D :: kInternalFormat_R, TargetWidth, TargetHeight );
	LayerMaskBuffer.SetRenderTexture2D ( Xenon::GPU::FrameBuffer :: kOutputAttachment_ColorBuffer, 0, LayerMaskTex, 0 );
	LayerMaskBuffer.SetClearColor ( 1.0f, 0.0f, 0.0f, 1.0f );
	
	AccumulatorTex.BlankTextureImage ( 0, Xenon::GPU::Texture2D :: kInternalFormat_RGBA, TargetWidth, TargetHeight );
	AccumulatorBuffer.SetRenderTexture2D ( Xenon::GPU::FrameBuffer :: kOutputAttachment_ColorBuffer, 0, AccumulatorTex, 0 );
	
	Xenon::Math :: Vec2 Coords [] = { Xenon::Math :: Vec2 ( - 1.0f, - 1.0f ), Xenon::Math :: Vec2 ( 1.0f, - 1.0f ), Xenon::Math :: Vec2 ( 1.0f, 1.0f ), Xenon::Math :: Vec2 ( 1.0f, 1.0f ), Xenon::Math :: Vec2 ( - 1.0f, 1.0f ), Xenon::Math :: Vec2 ( - 1.0f, - 1.0f ) };
	uint8_t Indexes [] = { 0, 1, 2, 3, 4, 5 };
	
	QuadVBuff.Buffer ( reinterpret_cast <const void *> ( Coords ), sizeof ( Coords ) );
	QuadIBuff.Buffer ( reinterpret_cast <const void *> ( Indexes ), 6, 0 );
	
	// Setup shaders
	// Setup vertex arrays
	
	GPUAlloc = true;
	
}

void Red::Graphics::Laminar::Renderer :: Render ()
{
	
	if ( ! Running )
		Begin ();
	
	if ( TargetBuffer == NULL )
		return;
	
	for ( uint32_t I = 0; I < Layers.size (); I ++ )
	{
		
		LayerMaskBuffer.Bind ();
		LayerMaskBuffer.Clear ();
		
		uint32_t MaskListLength = Layers [ I ] -> MaskListLength;
		Sprite * MaskListHead = Layers [ I ] -> MaskListHead;
		
		
		
	}
	
	// Render to target buffer
	
}
