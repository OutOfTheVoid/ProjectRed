#include <Red/Graphics/Laminar/Renderer.h>

#include <Xenon/Math/Vec2.h>
#include <Xenon/Math/Transform2D.h>
#include <Xenon/Math/Matrix3x3.h>

#include <cstring>

#include <iostream>

#define LAMINAR_RENDERER_DEFAULT_GEOMETRY_BUFFER_ALLOC 32

const GLchar * Red::Graphics::Laminar::Renderer :: kQuadVShader_String =
"#version 330 core\n"

"layout (location = 0) in vec2 Vertex;\n"
"layout (location = 1) in mat3 Transform;\n"

"out vec2 TexturePosition;\n"

"void main ()\n"
"{\n"

"	TexturePosition = ( ( Vertex + vec2 ( 1.0, 1.0 ) ) * 0.5 ).xy;\n"

"	gl_Position = vec4 ( vec3 ( Vertex, 0.0 ) * Transform, 1.0 );\n"

"}\n";

const GLchar * Red::Graphics::Laminar::Renderer :: kMaskFShader_String =
"#version 330 core\n"

"in vec2 TexturePosition;\n"

"out vec4 MaskOutput;\n"

//"uniform sampler2D MaskTexture;\n"

"void main ()\n"
"{\n"
//"	MaskOutput = texture ( MaskTexture, TexturePosition ).r"	
//"	MaskOutput = vec4 ( texture ( MaskTexture, TexturePosition ).r, 0.0, 0.0, 1.0 );\n"
"	MaskOutput = vec4 ( TexturePosition.x, TexturePosition.y, 1.0, 1.0 );\n"
	
"}\n";

const GLchar * Red::Graphics::Laminar::Renderer :: kColorFShader_String =
"#version 330 core\n"

"in vec2 TexturePosition;\n"

"out vec4 ColorOutput;\n"

//"uniform sampler2D ColorTexture;\n"

"void main ()\n"
"{\n"
	
//"	ColorOutput = texture ( ColorTexture, TexturePosition );\n"
"	ColorOutput = vec4 ( 0.0, 0.0, 1.0, 1.0 );\n"
	
"}\n";

Red::Graphics::Laminar::Renderer :: Renderer ( Xenon::GPU::Context * RenderContext, uint32_t TargetWidth, uint32_t TargetHeight, uint32_t InitialLayerCount, bool DefaultMasking, bool OrphanGeometry ):
	RenderContext ( RenderContext ),
	DefaultMaskModeCleared ( DefaultMasking ),
	Layers (),
	LayerMaskTex (),
	LayerMaskBuffer (),
	AccumulatorTex (),
	AccumulatorBuffer (),
	TargetBuffer ( NULL ),
	
	QuadIBuff ( Xenon::GPU::IndexBuffer :: kUsageType_Static_Draw, Xenon::GPU::IndexBuffer :: kIndexType_UBytes ),
	QuadVBuff ( Xenon::GPU::VertexBuffer :: kUsageType_Static_Draw ),
	
	QuadVShader ( kQuadVShader_String, "Laminar renderer - generic quad vshader" ),
	
	MaskFShader ( kMaskFShader_String, "Laminar renderer - mask fshader" ),
	MaskProgram ( "Laminar renderer - mask program" ),
	
	ColorFShader ( kColorFShader_String, "Laminar renderer - color fshader" ),
	ColorProgram ( "Laminar renderer - color program" ),
	
	Running ( false ),
	GPUAlloc ( false ),
	
	TargetWidth ( TargetWidth ),
	TargetHeight ( TargetHeight ),
	
	OrphanGeometry ( OrphanGeometry )
{
	
	for ( uint32_t I = 0; I < InitialLayerCount; I ++ )
	{
		
		RenderLayer * Layer = new RenderLayer ();
		
		Layer -> OverlayListHead = NULL;
		Layer -> OverlayListLength = 0;
		Layer -> OverlayListGeometry = NULL;
		
		Layer -> AddListHead = NULL;
		Layer -> AddListLength = 0;
		Layer -> AddListGeometry = NULL;
		
		Layer -> SubtractListHead = NULL;
		Layer -> SubtractListLength = 0;
		Layer -> SubtractListGeometry = NULL;
		
		Layer -> MultiplyListHead = NULL;
		Layer -> MultiplyListLength = 0;
		Layer -> MultiplyListGeometry = NULL;
		
		Layer -> MaxListHead = NULL;
		Layer -> MaxListLength = 0;
		Layer -> MaxListGeometry = NULL;
		
		Layer -> MinListHead = NULL;
		Layer -> MinListLength = 0;
		Layer -> MinListGeometry = NULL;
		
		Layer -> MaskListHead = NULL;
		Layer -> MaskListLength = 0;
		Layer -> MaskListGeometry = NULL;
		
		Layer -> NegativeMaskListHead = NULL;
		Layer -> NegativeMaskListLength = 0;
		Layer -> NegativeMaskListGeometry = NULL;
		
		Layer -> ClearMasked = DefaultMasking;
		
		Layers.push_back ( Layer );
		
	}
	
}

inline uint32_t NextPowerOfTwo ( uint32_t X )
{
	
	if ( X == 0 )
		return 1;
	
	X --;
	
	X |= X >> 16;
	X |= X >> 8;
	X |= X >> 4;
	X |= X >> 2;
	X |= X >> 1;
	
	X ++;
	
	return X;
	
}

Red::Graphics::Laminar::Renderer :: ~Renderer ()
{
	
	for ( uint32_t I = 0; I < Layers.size (); I ++ )
	{
		
		delete Layers [ I ];
		
	}
	
	QuadVShader.GPUResourceFree ();
	MaskFShader.GPUResourceFree ();
	ColorFShader.GPUResourceFree ();
	
}

Red::Graphics::Laminar::Renderer::LayerModeGeometry_Struct :: LayerModeGeometry_Struct ( uint32_t MinElementCount, Xenon::GPU :: IndexBuffer * QuadBuffer ):
	TransformBuff ( Xenon::GPU::VertexBuffer :: kUsageType_Dynamic_Draw ),
	TransformBufferSize ( 0 ),
	TransformArraySize ( 0 ),
	TransformArrayBufferSize ( NextPowerOfTwo ( MinElementCount ) > LAMINAR_RENDERER_DEFAULT_GEOMETRY_BUFFER_ALLOC ?  NextPowerOfTwo ( MinElementCount ) : LAMINAR_RENDERER_DEFAULT_GEOMETRY_BUFFER_ALLOC ),
	TextureUseRecords (),
	TextureIndexArray ( new uint32_t [ TransformArrayBufferSize ] ),
	TransformArray ( new Xenon::Math :: Matrix3x3 [ TransformArrayBufferSize ] ),
	TransformIterationList ( new int64_t [ TransformArrayBufferSize ] ),
	TransformSourceList ( new Sprite * [ TransformArrayBufferSize ] ),
	VArray (),
	DrawCall ( Xenon::GPU::DrawCall :: kDrawMode_Triangle, * QuadBuffer, 0 ),
	Dirty ( true )
{
	
	for ( uint32_t I = 0; I < MinElementCount; I ++ )
	{
		
		TransformIterationList [ I ] = 0;
		TransformSourceList [ I ] = NULL;
		TextureIndexArray [ I ] = 0xFFFFFFFF;
		
	}
	
}

Red::Graphics::Laminar::Renderer::LayerModeGeometry_Struct :: ~LayerModeGeometry_Struct ()
{
	
	delete [] TextureIndexArray;
	delete [] TransformArray;
	delete [] TransformIterationList;
	delete [] TransformSourceList;
	
}

void Red::Graphics::Laminar::Renderer::LayerModeGeometry_Struct :: SizeTo ( uint32_t ElementCount )
{
	
	if ( TransformArrayBufferSize >= ElementCount )
		return;
	
	uint32_t NewSize = NextPowerOfTwo ( ElementCount );
	
	uint32_t * TextureIndexArray = new uint32_t [ NewSize ];
	Xenon::Math :: Matrix3x3 * TransformArray = new Xenon::Math::Matrix3x3 [ NewSize ];
	int64_t * TransformIterationList = new int64_t [ NewSize ];
	Sprite ** TransformSourceList = new Sprite * [ NewSize ];
	
	std :: memcpy ( TextureIndexArray, this -> TextureIndexArray, sizeof ( uint32_t ) * TransformArraySize );
	std :: memcpy ( TransformArray, this -> TransformArray, sizeof ( Xenon::Math :: Matrix3x3 ) * TransformArraySize );
	std :: memcpy ( TransformIterationList, this -> TransformIterationList, sizeof ( int64_t ) * TransformArraySize );
	std :: memcpy ( TransformSourceList, this -> TransformSourceList, sizeof ( Sprite * ) * TransformArraySize );
	
	delete [] this -> TextureIndexArray;
	delete [] this -> TransformArray;
	delete [] this -> TransformIterationList;
	delete [] this -> TransformSourceList;
	
	this -> TextureIndexArray = TextureIndexArray;
	this -> TransformArray = TransformArray;
	this -> TransformIterationList = TransformIterationList;
	this -> TransformSourceList = TransformSourceList;
	
	TransformArrayBufferSize = NewSize;
	
}
			
void Red::Graphics::Laminar::Renderer :: SetLayerMaskMode ( uint32_t Layer, bool Cleared )
{
	
	while ( Layer >= Layers.size () )
	{
		
		RenderLayer * Layer = new RenderLayer ();
		
		Layer -> OverlayListHead = NULL;
		Layer -> OverlayListLength = 0;
		Layer -> OverlayListGeometry = NULL;
		
		Layer -> AddListHead = NULL;
		Layer -> AddListLength = 0;
		Layer -> AddListGeometry = NULL;
		
		Layer -> SubtractListHead = NULL;
		Layer -> SubtractListLength = 0;
		Layer -> SubtractListGeometry = NULL;
		
		Layer -> MultiplyListHead = NULL;
		Layer -> MultiplyListLength = 0;
		Layer -> MultiplyListGeometry = NULL;
		
		Layer -> MaxListHead = NULL;
		Layer -> MaxListLength = 0;
		Layer -> MaxListGeometry = NULL;
		
		Layer -> MinListHead = NULL;
		Layer -> MinListLength = 0;
		Layer -> MinListGeometry = NULL;
		
		Layer -> MaskListHead = NULL;
		Layer -> MaskListLength = 0;
		Layer -> MaskListGeometry = NULL;
		
		Layer -> NegativeMaskListHead = NULL;
		Layer -> NegativeMaskListLength = 0;
		Layer -> NegativeMaskListGeometry = NULL;
		
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
		Layer -> OverlayListGeometry = NULL;
		
		Layer -> AddListHead = NULL;
		Layer -> AddListLength = 0;
		Layer -> AddListGeometry = NULL;
		
		Layer -> SubtractListHead = NULL;
		Layer -> SubtractListLength = 0;
		Layer -> SubtractListGeometry = NULL;
		
		Layer -> MultiplyListHead = NULL;
		Layer -> MultiplyListLength = 0;
		Layer -> MultiplyListGeometry = NULL;
		
		Layer -> MaxListHead = NULL;
		Layer -> MaxListLength = 0;
		Layer -> MaxListGeometry = NULL;
		
		Layer -> MinListHead = NULL;
		Layer -> MinListLength = 0;
		Layer -> MinListGeometry = NULL;
		
		Layer -> MaskListHead = NULL;
		Layer -> MaskListLength = 0;
		Layer -> MaskListGeometry = NULL;
		
		Layer -> NegativeMaskListHead = NULL;
		Layer -> NegativeMaskListLength = 0;
		Layer -> NegativeMaskListGeometry = NULL;
		
		Layer -> ClearMasked = DefaultMaskModeCleared;
		
		Layers.push_back ( Layer );
		
	}
	
	Instance -> RenderInstance = this;
	
	switch ( Instance -> Layout.Mode )
	{
		
		case kRenderMode_Default:
			Instance -> Layout.Mode = kRenderMode_Overlay;
		case kRenderMode_Overlay:
			
			if ( Layers [ Instance -> Layer ] -> OverlayListHead != NULL )
			{
				
				Layers [ Instance -> Layer ] -> OverlayListHead -> Last = Instance;
				Instance -> Next = Layers [ Instance -> Layer ] -> OverlayListHead -> Last;
				
			}
			
			Layers [ Instance -> Layer ] -> OverlayListHead = Instance;
			Layers [ Instance -> Layer ] -> OverlayListLength ++;
			
			if ( Layers [ Instance -> Layer ] -> OverlayListGeometry != NULL )
				Layers [ Instance -> Layer ] -> OverlayListGeometry -> Dirty = true;
			
			break;
			
		case kRenderMode_Add:
			
			if ( Layers [ Instance -> Layer ] -> AddListHead != NULL )
			{
				
				Layers [ Instance -> Layer ] -> AddListHead -> Last = Instance;
				Instance -> Next = Layers [ Instance -> Layer ] -> AddListHead -> Last;
				
			}
			
			Layers [ Instance -> Layer ] -> AddListHead = Instance;
			Layers [ Instance -> Layer ] -> AddListLength ++;
			
			if ( Layers [ Instance -> Layer ] -> AddListGeometry != NULL )
				Layers [ Instance -> Layer ] -> AddListGeometry -> Dirty = true;
			
			break;
			
		case kRenderMode_Subtract:
			
			if ( Layers [ Instance -> Layer ] -> SubtractListHead != NULL )
			{
				
				Layers [ Instance -> Layer ] -> SubtractListHead -> Last = Instance;
				Instance -> Next = Layers [ Instance -> Layer ] -> SubtractListHead -> Last;
				
			}
			
			Layers [ Instance -> Layer ] -> SubtractListHead = Instance;
			Layers [ Instance -> Layer ] -> SubtractListLength ++;
			
			if ( Layers [ Instance -> Layer ] -> SubtractListGeometry != NULL )
				Layers [ Instance -> Layer ] -> SubtractListGeometry -> Dirty = true;
			
			break;
			
		case kRenderMode_Multiply:
			
			if ( Layers [ Instance -> Layer ] -> MultiplyListHead != NULL )
			{
				
				Layers [ Instance -> Layer ] -> MultiplyListHead -> Last = Instance;
				Instance -> Next = Layers [ Instance -> Layer ] -> MultiplyListHead -> Last;
				
			}
			
			Layers [ Instance -> Layer ] -> MultiplyListHead = Instance;
			Layers [ Instance -> Layer ] -> MultiplyListLength ++;
			
			if ( Layers [ Instance -> Layer ] -> MultiplyListGeometry != NULL )
				Layers [ Instance -> Layer ] -> MultiplyListGeometry -> Dirty = true;
			
			break;
			
		case kRenderMode_Max:
			
			if ( Layers [ Instance -> Layer ] -> MaxListHead != NULL )
			{
				
				Layers [ Instance -> Layer ] -> MaxListHead -> Last = Instance;
				Instance -> Next = Layers [ Instance -> Layer ] -> MaxListHead -> Last;
				
			}
			
			Layers [ Instance -> Layer ] -> MaxListHead = Instance;
			Layers [ Instance -> Layer ] -> MaxListLength ++;
			
			if ( Layers [ Instance -> Layer ] -> MaxListGeometry != NULL )
				Layers [ Instance -> Layer ] -> MaxListGeometry -> Dirty = true;
			
			break;
								
		case kRenderMode_Min:
			
			if ( Layers [ Instance -> Layer ] -> MinListHead != NULL )
			{
				
				Layers [ Instance -> Layer ] -> MinListHead -> Last = Instance;
				Instance -> Next = Layers [ Instance -> Layer ] -> MinListHead -> Last;
				
			}
			
			Layers [ Instance -> Layer ] -> MinListHead = Instance;
			Layers [ Instance -> Layer ] -> MinListLength ++;
			
			if ( Layers [ Instance -> Layer ] -> MinListGeometry != NULL )
				Layers [ Instance -> Layer ] -> MinListGeometry -> Dirty = true;
			
			break;
			
		case kRenderMode_Mask:
			
			if ( Layers [ Instance -> Layer ] -> MaskListHead != NULL )
			{
				
				Layers [ Instance -> Layer ] -> MaskListHead -> Last = Instance;
				Instance -> Next = Layers [ Instance -> Layer ] -> MaskListHead -> Last;
				
			}
			
			Layers [ Instance -> Layer ] -> MaskListHead = Instance;
			Layers [ Instance -> Layer ] -> MaskListLength ++;
			
			if ( Layers [ Instance -> Layer ] -> MaskListGeometry != NULL )
				Layers [ Instance -> Layer ] -> MaskListGeometry -> Dirty = true;
			
			break;
			
		case kRenderMode_NegativeMask:
			
			if ( Layers [ Instance -> Layer ] -> NegativeMaskListHead != NULL )
			{
				
				Layers [ Instance -> Layer ] -> NegativeMaskListHead -> Last = Instance;
				Instance -> Next = Layers [ Instance -> Layer ] -> NegativeMaskListHead -> Last;
				
			}
			
			Layers [ Instance -> Layer ] -> NegativeMaskListHead = Instance;
			Layers [ Instance -> Layer ] -> NegativeMaskListLength ++;
			
			if ( Layers [ Instance -> Layer ] -> NegativeMaskListGeometry != NULL )
				Layers [ Instance -> Layer ] -> NegativeMaskListGeometry -> Dirty = true;
			
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
					
					if ( Layers [ Instance -> Layer ] -> OverlayListGeometry != NULL )
						Layers [ Instance -> Layer ] -> OverlayListGeometry -> Dirty = true;
					
					break;
					
				case kRenderMode_Add:
					Layers [ Instance -> Layer ] -> AddListHead = NULL;
					Layers [ Instance -> Layer ] -> AddListLength --;
					
					if ( Layers [ Instance -> Layer ] -> AddListGeometry != NULL )
						Layers [ Instance -> Layer ] -> AddListGeometry -> Dirty = true;
					
					break;
					
				case kRenderMode_Subtract:
					Layers [ Instance -> Layer ] -> SubtractListHead = NULL;
					Layers [ Instance -> Layer ] -> SubtractListLength --;
					
					if ( Layers [ Instance -> Layer ] -> OverlayListGeometry != NULL )
						Layers [ Instance -> Layer ] -> OverlayListGeometry -> Dirty = true;
					
					break;
					
				case kRenderMode_Multiply:
					Layers [ Instance -> Layer ] -> MultiplyListHead = NULL;
					Layers [ Instance -> Layer ] -> MultiplyListLength --;
					
					if ( Layers [ Instance -> Layer ] -> OverlayListGeometry != NULL )
						Layers [ Instance -> Layer ] -> OverlayListGeometry -> Dirty = true;
					
					break;
					
				case kRenderMode_Max:
					Layers [ Instance -> Layer ] -> MaxListHead = NULL;
					Layers [ Instance -> Layer ] -> MaxListLength --;
					
					if ( Layers [ Instance -> Layer ] -> OverlayListGeometry != NULL )
						Layers [ Instance -> Layer ] -> OverlayListGeometry -> Dirty = true;
					
					break;
					
				case kRenderMode_Min:
					Layers [ Instance -> Layer ] -> MinListHead = NULL;
					Layers [ Instance -> Layer ] -> MinListLength --;
					
					if ( Layers [ Instance -> Layer ] -> OverlayListGeometry != NULL )
						Layers [ Instance -> Layer ] -> OverlayListGeometry -> Dirty = true;
					
					break;
					
				case kRenderMode_Mask:
					Layers [ Instance -> Layer ] -> MaskListHead = NULL;
					Layers [ Instance -> Layer ] -> MaskListLength --;
					
					if ( Layers [ Instance -> Layer ] -> MaskListGeometry != NULL )
						Layers [ Instance -> Layer ] -> MaskListGeometry -> Dirty = true;
					
					break;
					
				case kRenderMode_NegativeMask:
					Layers [ Instance -> Layer ] -> NegativeMaskListHead = NULL;
					Layers [ Instance -> Layer ] -> NegativeMaskListLength --;
					
					if ( Layers [ Instance -> Layer ] -> NegativeMaskListGeometry != NULL )
						Layers [ Instance -> Layer ] -> NegativeMaskListGeometry -> Dirty = true;
					
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
					
					if ( Layers [ Instance -> Layer ] -> OverlayListGeometry != NULL )
						Layers [ Instance -> Layer ] -> OverlayListGeometry -> Dirty = true;
					
					break;
					
				case kRenderMode_Add:
					Layers [ Instance -> Layer ] -> AddListLength --;
					
					if ( Layers [ Instance -> Layer ] -> AddListGeometry != NULL )
						Layers [ Instance -> Layer ] -> AddListGeometry -> Dirty = true;
					
					break;
					
				case kRenderMode_Subtract:
					Layers [ Instance -> Layer ] -> SubtractListLength --;
					
					if ( Layers [ Instance -> Layer ] -> SubtractListGeometry != NULL )
						Layers [ Instance -> Layer ] -> SubtractListGeometry -> Dirty = true;
					
					break;
					
				case kRenderMode_Multiply:
					Layers [ Instance -> Layer ] -> MultiplyListLength --;
					
					if ( Layers [ Instance -> Layer ] -> MultiplyListGeometry != NULL )
						Layers [ Instance -> Layer ] -> MultiplyListGeometry -> Dirty = true;
					
					break;
					
				case kRenderMode_Max:
					Layers [ Instance -> Layer ] -> MaxListLength --;
					
					if ( Layers [ Instance -> Layer ] -> MaxListGeometry != NULL )
						Layers [ Instance -> Layer ] -> MaxListGeometry -> Dirty = true;
					
					break;
					
				case kRenderMode_Min:
					Layers [ Instance -> Layer ] -> MinListLength --;
					
					if ( Layers [ Instance -> Layer ] -> MinListGeometry != NULL )
						Layers [ Instance -> Layer ] -> MinListGeometry -> Dirty = true;
					
					break;
					
				case kRenderMode_Mask:
					Layers [ Instance -> Layer ] -> MaskListLength --;
					
					if ( Layers [ Instance -> Layer ] -> MaskListGeometry != NULL )
						Layers [ Instance -> Layer ] -> MaskListGeometry -> Dirty = true;
					
					break;
					
				case kRenderMode_NegativeMask:
					Layers [ Instance -> Layer ] -> NegativeMaskListLength --;
					
					if ( Layers [ Instance -> Layer ] -> NegativeMaskListGeometry != NULL )
						Layers [ Instance -> Layer ] -> NegativeMaskListGeometry -> Dirty = true;
					
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
					
					if ( Layers [ Instance -> Layer ] -> OverlayListGeometry != NULL )
						Layers [ Instance -> Layer ] -> OverlayListGeometry -> Dirty = true;
					
					break;
					
				case kRenderMode_Add:
					Layers [ Instance -> Layer ] -> AddListHead = Instance -> Next;
					Layers [ Instance -> Layer ] -> AddListLength --;
					
					if ( Layers [ Instance -> Layer ] -> AddListGeometry != NULL )
						Layers [ Instance -> Layer ] -> AddListGeometry -> Dirty = true;
					
					break;
					
				case kRenderMode_Subtract:
					Layers [ Instance -> Layer ] -> SubtractListHead = Instance -> Next;
					Layers [ Instance -> Layer ] -> SubtractListLength --;
					
					if ( Layers [ Instance -> Layer ] -> SubtractListGeometry != NULL )
						Layers [ Instance -> Layer ] -> SubtractListGeometry -> Dirty = true;
					
					break;
					
				case kRenderMode_Multiply:
					Layers [ Instance -> Layer ] -> MultiplyListHead = Instance -> Next;
					Layers [ Instance -> Layer ] -> MultiplyListLength --;
					
					if ( Layers [ Instance -> Layer ] -> MultiplyListGeometry != NULL )
						Layers [ Instance -> Layer ] -> MultiplyListGeometry -> Dirty = true;
					
					break;
					
				case kRenderMode_Max:
					Layers [ Instance -> Layer ] -> MaxListHead = Instance -> Next;
					Layers [ Instance -> Layer ] -> MaxListLength --;
					
					if ( Layers [ Instance -> Layer ] -> MaxListGeometry != NULL )
						Layers [ Instance -> Layer ] -> MaxListGeometry -> Dirty = true;
					
					break;
					
				case kRenderMode_Min:
					Layers [ Instance -> Layer ] -> MinListHead = Instance -> Next;
					Layers [ Instance -> Layer ] -> MinListLength --;
					
					if ( Layers [ Instance -> Layer ] -> MinListGeometry != NULL )
						Layers [ Instance -> Layer ] -> MinListGeometry -> Dirty = true;
					
					break;
					
				case kRenderMode_Mask:
					Layers [ Instance -> Layer ] -> MaskListHead = Instance -> Next;
					Layers [ Instance -> Layer ] -> MaskListLength --;
					
					if ( Layers [ Instance -> Layer ] -> MaskListGeometry != NULL )
						Layers [ Instance -> Layer ] -> MaskListGeometry -> Dirty = true;
					
					break;
					
				case kRenderMode_NegativeMask:
					Layers [ Instance -> Layer ] -> NegativeMaskListHead = Instance -> Next;
					Layers [ Instance -> Layer ] -> NegativeMaskListLength --;
					
					if ( Layers [ Instance -> Layer ] -> NegativeMaskListGeometry != NULL )
						Layers [ Instance -> Layer ] -> NegativeMaskListGeometry -> Dirty = true;
					
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
					
					if ( Layers [ Instance -> Layer ] -> OverlayListGeometry != NULL )
						Layers [ Instance -> Layer ] -> OverlayListGeometry -> Dirty = true;
					
					break;
					
				case kRenderMode_Add:
					Layers [ Instance -> Layer ] -> AddListLength --;
					
					if ( Layers [ Instance -> Layer ] -> AddListGeometry != NULL )
						Layers [ Instance -> Layer ] -> AddListGeometry -> Dirty = true;
					
					break;
					
				case kRenderMode_Subtract:
					Layers [ Instance -> Layer ] -> SubtractListLength --;
					
					if ( Layers [ Instance -> Layer ] -> SubtractListGeometry != NULL )
						Layers [ Instance -> Layer ] -> SubtractListGeometry -> Dirty = true;
					
					break;
					
				case kRenderMode_Multiply:
					Layers [ Instance -> Layer ] -> MultiplyListLength --;
					
					if ( Layers [ Instance -> Layer ] -> MultiplyListGeometry != NULL )
						Layers [ Instance -> Layer ] -> MultiplyListGeometry -> Dirty = true;
					
					break;
					
				case kRenderMode_Max:
					Layers [ Instance -> Layer ] -> MaxListLength --;
					
					if ( Layers [ Instance -> Layer ] -> MaxListGeometry != NULL )
						Layers [ Instance -> Layer ] -> MaxListGeometry -> Dirty = true;
					
					break;
					
				case kRenderMode_Min:
					Layers [ Instance -> Layer ] -> MinListLength --;
					
					if ( Layers [ Instance -> Layer ] -> MinListGeometry != NULL )
						Layers [ Instance -> Layer ] -> MinListGeometry -> Dirty = true;
					
					break;
					
				case kRenderMode_Mask:
					Layers [ Instance -> Layer ] -> MaskListLength --;
					
					if ( Layers [ Instance -> Layer ] -> MaskListGeometry != NULL )
						Layers [ Instance -> Layer ] -> MaskListGeometry -> Dirty = true;
					
					break;
					
				case kRenderMode_NegativeMask:
					Layers [ Instance -> Layer ] -> NegativeMaskListLength --;
					
					if ( Layers [ Instance -> Layer ] -> NegativeMaskListGeometry != NULL )
						Layers [ Instance -> Layer ] -> NegativeMaskListGeometry -> Dirty = true;
					
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
	PrepGeometry ();
	
}

void Red::Graphics::Laminar::Renderer :: End ()
{
	
	Running = false;
	
}

void Red::Graphics::Laminar::Renderer :: Resize ( uint32_t TargetWidth, uint32_t TargetHeight )
{
	
	this -> TargetWidth = TargetWidth;
	this -> TargetHeight = TargetHeight;
	
	if ( GPUAlloc )
	{
		
		LayerMaskTex.BlankTextureImage ( 0, Xenon::GPU::Texture2D :: kInternalFormat_R, TargetWidth, TargetHeight );
		AccumulatorTex.BlankTextureImage ( 0, Xenon::GPU::Texture2D :: kInternalFormat_RGBA, TargetWidth, TargetHeight );
		
	}
	
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
	
	MaskProgram.GPUResourceFree ();
	ColorProgram.GPUResourceFree ();
	
	Running = false;
	GPUAlloc = false;
	
}

void Red::Graphics::Laminar::Renderer :: SetupGPUResources ()
{
	
	if ( GPUAlloc )
		return;
	
	RenderContext -> MakeCurrent ();
	
	LayerMaskTex.GPUResourceAlloc ();
	LayerMaskBuffer.GPUResourceAlloc ();
	
	AccumulatorTex.GPUResourceAlloc ();
	AccumulatorBuffer.GPUResourceAlloc ();
	
	QuadVBuff.GPUResourceAlloc ();
	QuadIBuff.GPUResourceAlloc ();
	
	QuadVShader.GPUResourceAlloc ();
	MaskFShader.GPUResourceAlloc ();
	MaskProgram.GPUResourceAlloc ();
	ColorFShader.GPUResourceAlloc ();
	ColorProgram.GPUResourceAlloc ();
	
	if ( ! LayerMaskBuffer.GPUResourceAllocated () )
		std :: cout << "Layer mask buffer alloc failed" << std :: endl;
	
	if ( ! LayerMaskTex.GPUResourceAllocated () )
		std :: cout << "Layer mask texture alloc failed" << std :: endl;
	
	LayerMaskTex.BlankTextureImage ( 0, Xenon::GPU::Texture2D :: kInternalFormat_R, TargetWidth, TargetHeight );
	LayerMaskBuffer.SetRenderTexture2D ( Xenon::GPU::FrameBuffer :: kOutputAttachment_ColorBuffer, 0, LayerMaskTex, 0 );
	
	AccumulatorTex.BlankTextureImage ( 0, Xenon::GPU::Texture2D :: kInternalFormat_RGBA, TargetWidth, TargetHeight );
	AccumulatorBuffer.SetRenderTexture2D ( Xenon::GPU::FrameBuffer :: kOutputAttachment_ColorBuffer, 0, AccumulatorTex, 0 );
	
	Xenon::Math :: Vec2 Coords [] = { Xenon::Math :: Vec2 ( - 1.0f, - 1.0f ), Xenon::Math :: Vec2 ( 1.0f, - 1.0f ), Xenon::Math :: Vec2 ( 1.0f, 1.0f ), Xenon::Math :: Vec2 ( 1.0f, 1.0f ), Xenon::Math :: Vec2 ( - 1.0f, 1.0f ), Xenon::Math :: Vec2 ( - 1.0f, - 1.0f ) };
	uint8_t Indexes [] = { 0, 1, 2, 3, 4, 5 };
	
	QuadVBuff.Buffer ( reinterpret_cast <const void *> ( Coords ), sizeof ( Coords ) );
	QuadIBuff.Buffer ( reinterpret_cast <const void *> ( Indexes ), 6 );
	
	// Setup shaders
	
	if ( ! QuadVShader.Compile ( true, true ) )
		std :: cout << "QuadVShader: " << QuadVShader.GetCompilationLog () << std :: endl;
	
	if ( ! MaskFShader.Compile ( true, true ) )
		std :: cout << "MaskFShader: " << MaskFShader.GetCompilationLog () << std :: endl;
	
	MaskProgram.AddShader ( QuadVShader );
	MaskProgram.AddShader ( MaskFShader );
	
	if ( ! MaskProgram.Link () )
		std :: cout << "MaskProgram: " << MaskProgram.GetInfoLog () << std :: endl;
	
	if ( ! ColorFShader.Compile ( true, true ) )
		std :: cout << "ColorFShader: " << ColorFShader.GetCompilationLog () << std :: endl;
	
	ColorProgram.AddShader ( QuadVShader );
	ColorProgram.AddShader ( ColorFShader );
	
	if ( ! ColorProgram.Link () )
		std :: cout << "ColorProgram: " << ColorProgram.GetInfoLog () << std :: endl;
	
	// Setup vertex arrays
	
	PrepGeometry ();
	UpdateGeometry ();
	
	GPUAlloc = true;
	
}

void Red::Graphics::Laminar::Renderer :: UpdateGeometryBuffers ( LayerModeGeometry & Geometry )
{
	
	if ( Geometry.TransformArraySize == 0 )
		return;
	
	if ( Geometry.TransformBufferSize < Geometry.TransformArraySize )
	{
		
		Geometry.TransformBufferSize = Geometry.TransformArrayBufferSize;
		Geometry.TransformBuff.Buffer ( reinterpret_cast <const void *> ( Geometry.TransformArray ), Geometry.TransformBufferSize * sizeof ( Xenon::Math :: Matrix3x3 ) );
		
	}
	else
	{
		
		if ( OrphanGeometry )
			Geometry.TransformBuff.Orphan ();
		
		Geometry.TransformBuff.SubBuffer ( reinterpret_cast <const void *> ( Geometry.TransformArray ), Geometry.TransformArraySize * sizeof ( Xenon::Math :: Matrix3x3 ), 0 );
		
	}
	
	Geometry.DrawCall.SetInstanceCount ( Geometry.TransformArraySize );
	
	Geometry.Dirty = false;
	
}

void Red::Graphics::Laminar::Renderer :: PrepGeometryList ( LayerModeGeometry *& GeometryPTR, Sprite * ListHead, uint32_t ListLength, Xenon::GPU :: ShaderProgram * Program, Xenon::GPU :: IndexBuffer * QuadIndexBuffer )
{
	
	if ( ListLength == 0 )
		return;
	
	if ( GeometryPTR == NULL )
	{
		
		GeometryPTR = new LayerModeGeometry ( ListLength, QuadIndexBuffer );
		
		GeometryPTR -> VArray.SetProgram ( Program );
		
		GeometryPTR -> VArray.AddFPAttribute ( "Vertex", 2, Xenon::GPU::VertexArray :: kFPAttributeInputType_Float, false, 0, NULL, & QuadVBuff );
		
		GeometryPTR -> VArray.AddFPAttribute ( "Transform", 3, Xenon::GPU::VertexArray :: kFPAttributeInputType_Float, false, ( sizeof ( float ) * 9 ), NULL, & GeometryPTR -> TransformBuff, 1, 0 );
		GeometryPTR -> VArray.AddFPAttribute ( "Transform", 3, Xenon::GPU::VertexArray :: kFPAttributeInputType_Float, false, ( sizeof ( float ) * 9 ), (void *) ( sizeof ( float ) * 3 ), & GeometryPTR -> TransformBuff, 1, 1 );
		GeometryPTR -> VArray.AddFPAttribute ( "Transform", 3, Xenon::GPU::VertexArray :: kFPAttributeInputType_Float, false, ( sizeof ( float ) * 9 ), (void *) ( sizeof ( float ) * 6 ), & GeometryPTR -> TransformBuff, 1, 2 );
		
		GeometryPTR -> VArray.SetIndexBuffer ( & QuadIBuff );
		
		GeometryPTR -> VArray.Build ();
		
	}
	else
		GeometryPTR -> SizeTo ( ListLength );
	
	bool Dirty = false;
	
	for ( uint32_t I = 0; I < ListLength; I ++ )
	{
		
		Xenon::Math :: Transform2D & Transform = ListHead -> GetTransform ();
		int64_t Iteration = Transform.GetTransformUniformSource () -> GetIteration ();
		
		if ( ( GeometryPTR -> TransformSourceList [ I ] != ListHead ) || ( GeometryPTR -> TransformIterationList [ I ] < Iteration ) )
		{
			
			Dirty = true;
			
			GeometryPTR -> TransformSourceList [ I ] = ListHead;
			
			GeometryPTR -> TransformIterationList [ I ] = Transform.GetTransformUniformSource () -> GetIteration ();
			GeometryPTR -> TransformArray [ I ] = Transform.ReadMatrix ();
			
		}
		
		I2DTextureSource * TexSource = ListHead -> GetTextureSource ();
		
		std :: cout << "TSOURCE: " << reinterpret_cast <void *> ( TexSource ) << std :: endl;
		std :: cout << "TEX: " << reinterpret_cast <void *> ( TexSource -> GetOutputTexture () ) << std :: endl;
		
		Xenon::GPU:: ITexture * SourceTexture = TexSource -> GetOutputTexture ();
		
		uint32_t TextureIndex = GeometryPTR -> TextureIndexArray [ I ];
		
		bool TexSearch = false;
		
		if ( TextureIndex >= GeometryPTR -> TextureUseRecords.size () )
			TexSearch = true;
		else if ( GeometryPTR -> TextureUseRecords [ TextureIndex ].Texture != SourceTexture )
		{
			
			GeometryPTR -> TextureUseRecords [ TextureIndex ].UsageCount --;
			
			if ( GeometryPTR -> TextureUseRecords [ TextureIndex ].UsageCount == 0 )
			{
				
				GeometryPTR -> TextureUseRecords [ TextureIndex ].Texture -> Dereference ();
				GeometryPTR -> TextureUseRecords.erase ( GeometryPTR -> TextureUseRecords.begin () + TextureIndex );
				
			}
			
			TexSearch = true;
			
		}
		
		if ( TexSearch )
		{
			
			Dirty = true;
			
			bool Found = false;
			
			uint32_t RecordCount = GeometryPTR -> TextureUseRecords.size ();
			
			for ( uint32_t J = 0; J < RecordCount; J ++ )
			{
				
				if ( GeometryPTR -> TextureUseRecords [ J ].Texture == SourceTexture )
				{
					
					GeometryPTR -> TextureIndexArray [ I ] = J;
					GeometryPTR -> TextureUseRecords [ J ].UsageCount ++;
					
					Found = true;
					
					break;
					
				}
				
			}
			
			if ( ! Found )
			{
				
				GeometryPTR -> TextureIndexArray [ I ] = RecordCount;
				GeometryPTR -> TextureUseRecords.push_back ( { SourceTexture, 1 } );
				SourceTexture -> Reference ();
				
			}
			
		}
		
		ListHead = ListHead -> Next;
		
	}
	
	for ( uint32_t I = ListLength; I < GeometryPTR -> TransformArrayBufferSize; I ++ )
	{
		
		uint32_t TextureIndex = GeometryPTR -> TextureIndexArray [ I ];
		uint32_t RecordCount = GeometryPTR -> TextureUseRecords.size ();
		
		if ( TextureIndex < GeometryPTR -> TextureUseRecords.size () )
		{
			
			GeometryPTR -> TextureUseRecords [ TextureIndex ].UsageCount --;
			GeometryPTR -> TextureIndexArray [ I ] = 0xFFFFFFFF;
			
			if ( GeometryPTR -> TextureUseRecords [ TextureIndex ].UsageCount == 0 )
			{
				
				GeometryPTR -> TextureUseRecords [ TextureIndex ].Texture -> Dereference ();
				GeometryPTR -> TextureUseRecords.erase ( GeometryPTR -> TextureUseRecords.begin () + TextureIndex );
				
			}
			
		}
		
	}
	
	GeometryPTR -> Dirty = Dirty;
	GeometryPTR -> TransformArraySize = ListLength;
	
}

void Red::Graphics::Laminar::Renderer :: UpdateGeometry ()
{
	
	RenderContext -> MakeCurrent ();
	
	for ( uint32_t I = 0; I < Layers.size (); I ++ )
	{
		
		if ( ( Layers [ I ] -> OverlayListGeometry != NULL ) && ( Layers [ I ] -> OverlayListGeometry -> Dirty ) )
			UpdateGeometryBuffers ( * Layers [ I ] -> OverlayListGeometry );
		
		if ( ( Layers [ I ] -> AddListGeometry != NULL ) && ( Layers [ I ] -> AddListGeometry -> Dirty ) )
			UpdateGeometryBuffers ( * Layers [ I ] -> AddListGeometry );
		
		if ( ( Layers [ I ] -> SubtractListGeometry != NULL ) && ( Layers [ I ] -> SubtractListGeometry -> Dirty ) )
			UpdateGeometryBuffers ( * Layers [ I ] -> SubtractListGeometry );
		
		if ( ( Layers [ I ] -> MultiplyListGeometry != NULL ) && ( Layers [ I ] -> MultiplyListGeometry -> Dirty ) )
			UpdateGeometryBuffers ( * Layers [ I ] -> MultiplyListGeometry );
		
		if ( ( Layers [ I ] -> MaxListGeometry != NULL ) && ( Layers [ I ] -> MaxListGeometry -> Dirty ) )
			UpdateGeometryBuffers ( * Layers [ I ] -> MaxListGeometry );
		
		if ( ( Layers [ I ] -> MinListGeometry != NULL ) && ( Layers [ I ] -> MinListGeometry -> Dirty ) )
			UpdateGeometryBuffers ( * Layers [ I ] -> MinListGeometry );
		
		if ( ( Layers [ I ] -> MaskListGeometry != NULL ) && ( Layers [ I ] -> MaskListGeometry -> Dirty ) )
			UpdateGeometryBuffers ( * Layers [ I ] -> MaskListGeometry );
		
		if ( ( Layers [ I ] -> NegativeMaskListGeometry != NULL ) && ( Layers [ I ] -> NegativeMaskListGeometry -> Dirty ) )
			UpdateGeometryBuffers ( * Layers [ I ] -> NegativeMaskListGeometry );
		
	}
	
}

void Red::Graphics::Laminar::Renderer :: PrepGeometry ()
{
	
	RenderContext -> MakeCurrent ();
	
	for ( uint32_t I = 0; I < Layers.size (); I ++ )
	{
		
		PrepGeometryList ( Layers [ I ] -> OverlayListGeometry, Layers [ I ] -> OverlayListHead, Layers [ I ] -> OverlayListLength, & ColorProgram, & QuadIBuff );
		PrepGeometryList ( Layers [ I ] -> AddListGeometry, Layers [ I ] -> AddListHead, Layers [ I ] -> AddListLength, & ColorProgram, & QuadIBuff );
		PrepGeometryList ( Layers [ I ] -> SubtractListGeometry, Layers [ I ] -> SubtractListHead, Layers [ I ] -> SubtractListLength, & ColorProgram, & QuadIBuff );
		PrepGeometryList ( Layers [ I ] -> MultiplyListGeometry, Layers [ I ] -> MultiplyListHead, Layers [ I ] -> MultiplyListLength, & ColorProgram, & QuadIBuff );
		PrepGeometryList ( Layers [ I ] -> MaxListGeometry, Layers [ I ] -> MaxListHead, Layers [ I ] -> MaxListLength, & ColorProgram, & QuadIBuff );
		PrepGeometryList ( Layers [ I ] -> MinListGeometry, Layers [ I ] -> MinListHead, Layers [ I ] -> MinListLength, & ColorProgram, & QuadIBuff );
		PrepGeometryList ( Layers [ I ] -> MaskListGeometry, Layers [ I ] -> MaskListHead, Layers [ I ] -> MaskListLength, & MaskProgram, & QuadIBuff );
		PrepGeometryList ( Layers [ I ] -> NegativeMaskListGeometry, Layers [ I ] -> NegativeMaskListHead, Layers [ I ] -> NegativeMaskListLength, & MaskProgram, & QuadIBuff );
		
	}
	
}

void Red::Graphics::Laminar::Renderer :: Render ()
{
	
	// This could potentially be done in another thread, but would still require a barrier between Render() calls
	PrepGeometry ();
	UpdateGeometry ();
	
	if ( ! Running )
		Begin ();
	
	if ( TargetBuffer == NULL )
		return;
	
	for ( uint32_t I = 0; I < Layers.size (); I ++ )
	{
		
		if ( ( Layers [ I ] -> MaskListLength != 0 ) || ( Layers [ I ] -> NegativeMaskListLength != 0 ) )
		{
			
			MaskProgram.Bind ();
			
			// TEST! We're rendering masks directly to output buffer for debug purposes for now.
			TargetBuffer -> Bind ();
			TargetBuffer -> SetClearColor ( Layers [ I ] -> ClearMasked ? 1.0f : 0.0f, 0.0f, 0.0f, 1.0f );
			TargetBuffer -> Clear ();
			/*LayerMaskBuffer.Bind ();
			LayerMaskBuffer.SetClearColor ( Layers [ I ] -> ClearMasked ? 1.0f : 0.0f, 0.0f, 0.0f, 1.0f );
			LayerMaskBuffer.Clear ();
			*/
			
			if ( NULL != Layers [ I ] -> MaskListGeometry )
			{
				
				RenderContext -> BlendEquation ( Xenon::GPU::Context :: kBlendOperator_Add, Xenon::GPU::Context :: kBlendOperator_Max );
				
				Layers [ I ] -> MaskListGeometry -> VArray.Bind ();
				Layers [ I ] -> MaskListGeometry -> DrawCall.Draw ();
				
			}
			
			if ( NULL != Layers [ I ] -> NegativeMaskListGeometry )
			{
				
				//RenderContext -> BlendEquation ( Xenon::GPU::Context :: kBlendOperator_Subtract, Xenon::GPU::Context :: kBlendOperator_Max );
				
				//Layers [ I ] -> MaskListGeometry -> VArray.Bind ();
				//Layers [ I ] -> MaskListGeometry -> DrawCall.Draw ();
				
			}
			
		}
		
	}
	
	// Render to target buffer
	
}
