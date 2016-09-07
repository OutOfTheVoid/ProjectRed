#include <Xenon/GPU/Context.h>
#include <Xenon/GPU/FrameBuffer.h>

Xenon::GPU :: Context Xenon::GPU::Context :: NullContext ( NULL );

thread_local Xenon::GPU :: Context * Xenon::GPU::Context :: CurrentBoundContext = & NullContext;

Xenon::GPU::Context :: Context ( IGLContext * GLContext ):
	RefCounted ( 0 ),
	GLContext ( GLContext ),
	CurrentBoundShader ( NULL ),
	CurrentBoundArrayBuffer ( NULL ),
	CurrentBoundIndexBuffer ( NULL ),
	CurrentBoundVertexArray ( NULL ),
	CurrentBoundTexture2D ( NULL ),
	CurrentBoundReadFrameBuffer ( NULL ),
	CurrentBoundDrawFrameBuffer ( NULL ),
	DefaultFrameBuffer ( 0 ),
	CullingEnabledCurrent ( false ),
	CullingFaceCurrent ( kCullingFace_Back ),
	FrontFaceCurrent ( kFrontFace_CounterClockwise ),
	DepthTestEnabledCurrent ( false )
{
	
	DefaultFrameBuffer.Reference ();
	
}

Xenon::GPU::Context :: ~Context ()
{
}

void Xenon::GPU::Context :: MakeCurrent ()
{
	
	if ( CurrentBoundContext != this )
	{
		
		if ( GLContext -> MakeCurrent () == 0 )
			CurrentBoundContext = this;
		
	}
	
}

void Xenon::GPU::Context :: BlendFunc ( BlendFactor SourceRGB, BlendFactor DestinationRGB, BlendFactor SourceAlpha, BlendFactor DestinationAlpha )
{
	
	MakeCurrent ();
	
	if ( CurrentBoundContext != this )
		return;
	
	glEnable ( GL_BLEND );
	glBlendFuncSeparate ( SourceRGB, DestinationRGB, SourceAlpha, DestinationAlpha );
	
}

void Xenon::GPU::Context :: BlendEquation ( BlendOperator OperatorRGB, BlendOperator OperatorAlpha )
{
	
	MakeCurrent ();
	
	if ( CurrentBoundContext != this )
		return;
	
	glEnable ( GL_BLEND );
	glBlendEquationSeparate ( OperatorRGB, OperatorAlpha );
	
}

Xenon::GPU :: FrameBuffer * Xenon::GPU::Context :: GetDefaultFrameBuffer ()
{
	
	return & DefaultFrameBuffer;
	
}

void Xenon::GPU::Context :: SetCullingEnabled ( bool Enabled )
{
	
	MakeCurrent ();
	
	if ( CurrentBoundContext != this )
		return;
	
	if ( CullingEnabledCurrent == Enabled )
		return;
	
	CullingEnabledCurrent = Enabled;
	
	if ( Enabled )
		glEnable ( GL_CULL_FACE );
	else
		glDisable ( GL_CULL_FACE );
	
}

void Xenon::GPU::Context :: SetCullingFace ( CullingFace Face )
{
	
	MakeCurrent ();
	
	if ( CurrentBoundContext != this )
		return;
	
	if ( CullingFaceCurrent == Face )
		return;
	
	CullingFaceCurrent = Face;
	
	glCullFace ( Face );
	
}

void Xenon::GPU::Context :: SetFrontFace ( FrontFace Face )
{
	
	MakeCurrent ();
	
	if ( CurrentBoundContext != this )
		return;
	
	if ( FrontFaceCurrent == Face )
		return;
	
	FrontFaceCurrent = Face;
	
	glFrontFace ( Face );
	
}

void Xenon::GPU::Context :: SetDepthTestEnabled ( bool Enabled )
{
	
	MakeCurrent ();
	
	if ( CurrentBoundContext != this )
		return;
	
	if ( Enabled == DepthTestEnabledCurrent )
		return;
	
	DepthTestEnabledCurrent = Enabled;
	
	if ( Enabled )
		glEnable ( GL_DEPTH_TEST );
	else
		glDisable ( GL_DEPTH_TEST );
	
}
