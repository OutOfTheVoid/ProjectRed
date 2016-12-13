#include <Red/Graphics/Model.h>

#include <string.h>

Red::Graphics::Model :: Model ( Xenon::Geometry :: Mesh * ModelMesh, DrawMethod Method, const ModelShaderConfigurationNames & ShaderConfigurationNames ):
	Method ( Method ),
	Visible ( true ),
	ModelMesh ( ModelMesh ),
	DoInstancedTransformUniformName ( * ShaderConfigurationNames.DoInstancedTransformUniformName ),
	DoNormalTextureUniformName ( * ShaderConfigurationNames.DoNormalTextureUniformName ),
	DoColorTextureUniformName ( * ShaderConfigurationNames.DoColorTextureUniformName ),
	// Note: for now, most of this is hardcoded, but will be configurable once I add in support for normal mapping & etc.
	DoInstancedTransformUniform ( Method == kDrawMethod_Instanced ),
	DoNormalTextureUniform ( false ),
	DoColorTextureUniform ( false )
{
	
	switch ( Method )
	{
		
		case kDrawMethod_Single:
		{
			
			TransformData.Single = new SingleData ( * ShaderConfigurationNames.ModelMatrixUniformName, * ShaderConfigurationNames.NormalMatrixUniformName );
			ModelMesh -> ConfigureIndexedDrawCall ( TransformData.Single -> Draw );
			
		}
		break;
		
		case kDrawMethod_Instanced:
		{
			
			TransformData.Instanced = new InstancedData ( * ShaderConfigurationNames.InstancedModelTransformAttributeName, * ShaderConfigurationNames.InstancedNormalTransformAttributeName );
			ModelMesh -> ConfigureInstancedIndexedDrawCall ( TransformData.Instanced -> Draw );
			
		}
		break;
		
		default:
			
			TransformData.Instanced = NULL;
			
			break;
		
	}
	
	ModelMesh -> Reference ();
	
}

Red::Graphics::Model::InstancedData :: InstancedData ( const std :: string & ModelTransformName, const std :: string & NormalTransformName ):
	InstancedModelTransforms ( new Red::Util :: RCMem ( NULL, NULL ) ),
	InstancedNormalTransforms ( new Red::Util :: RCMem ( NULL, NULL ) ),
	InstancedModelTransformData ( InstancedModelTransforms, 0, Xenon::GPU::VertexBuffer :: kUsageType_Dynamic_Draw, true ),
	InstancedNormalTransformData ( InstancedNormalTransforms, 0, Xenon::GPU::VertexBuffer :: kUsageType_Dynamic_Draw, true ),
	InstancedModelTransformAttribute ( ModelTransformName, Xenon::GPU::VertexArray :: kFPAttributeInputType_Float, false, 4, sizeof ( Xenon::Math :: Matrix4x4 ), NULL, & InstancedModelTransformData, 1, 4, sizeof ( float ) * 4 ),
	InstancedNormalTransformAttribute ( NormalTransformName, Xenon::GPU::VertexArray :: kFPAttributeInputType_Float, false, 4, sizeof ( Xenon::Math :: Matrix4x4 ), NULL, & InstancedNormalTransformData, 1, 4, sizeof ( float ) * 4 ),
	InstanceCount ( 0 ),
	InstanceCountAllocated ( 0 ),
	Draw ( Xenon::GPU::InstancedIndexedDrawCall :: NO_INIT )
{
	
	InstancedModelTransformAttribute.Reference ();
	InstancedNormalTransformAttribute.Reference ();
	
}

Red::Graphics::Model::InstancedData :: ~InstancedData ()
{	
}

Red::Graphics::Model::SingleData :: SingleData ( const std :: string & ModelTransformName, const std :: string & NormalTransformName ):
	NonIndexedModelTransform (),
	NonIndexedNormalTransform (),
	ModelTransformUniform ( & NonIndexedModelTransform, true ),
	NormalTransformUniform ( & NonIndexedNormalTransform, true ),
	ModelTransformName ( ModelTransformName ),
	NormalTransformName ( NormalTransformName ),
	Draw ( Xenon::GPU::IndexedDrawCall :: NO_INIT )
{
	
	ModelTransformUniform.Reference ();
	NormalTransformUniform.Reference ();
	
}

Red::Graphics::Model::SingleData :: ~SingleData ()
{
}

Red::Graphics::Model :: ~Model ()
{
	
	switch ( Method )
	{
		
		case kDrawMethod_Single:
			delete TransformData.Single;
			break;
			
		case kDrawMethod_Instanced:
			delete TransformData.Instanced;
			break;
			
		default:
			break;
			 
	}
	
	TransformData.Instanced = NULL;
	
	ModelMesh -> Dereference ();
	
}

void Red::Graphics::Model :: GPUAlloc ()
{
	
	ModelMesh -> GPUResourceAlloc ();
	
	switch ( Method )
	{
		
		case kDrawMethod_Single:
		{
			
			
			
		}
		break;
			
		case kDrawMethod_Instanced:
		{
			
			TransformData.Instanced -> InstancedModelTransformData.GPUResourceAlloc ();
			TransformData.Instanced -> InstancedNormalTransformData.GPUResourceAlloc ();
			
		}
		break;
			
		default:
			break;
			 
	}
	
}

void Red::Graphics::Model :: GPUFree ()
{
	
	switch ( Method )
	{
		
		case kDrawMethod_Single:
		{
			
			
			
		}
		break;
			
		case kDrawMethod_Instanced:
		{
			
			TransformData.Instanced -> InstancedModelTransformData.GPUResourceFree ();
			TransformData.Instanced -> InstancedNormalTransformData.GPUResourceFree ();
			
		}
		break;
			
		default:
			break;
			 
	}
	
}

void Red::Graphics::Model :: FlushData ()
{
	
	ModelMesh -> FlushData ();
	
	switch ( Method )
	{
		
		case kDrawMethod_Single:
		{
			
			
			
		}
		break;
		
		case kDrawMethod_Instanced:
		{
			
			TransformData.Instanced -> InstancedModelTransformData.Update ( false );
			TransformData.Instanced -> InstancedNormalTransformData.Update ( false );
			
		}
		break;
		
		default:
			break;
		
	}
	
}

void Red::Graphics::Model :: SetVisible ( bool Visible )
{
	
	this -> Visible = Visible;
	
}

void Red::Graphics::Model :: DeleteMatrixArray ( void * MatrixArray )
{
	
	delete[] reinterpret_cast <Xenon::Math::Matrix4x4 *> ( MatrixArray );
	
}

void Red::Graphics::Model :: SetInstanceCount ( uint32_t InstanceCount )
{
	
	if ( Method = kDrawMethod_Instanced )
	{
		
		if ( TransformData.Instanced -> InstanceCountAllocated < InstanceCount )
		{
			
			Xenon::Math::Matrix4x4 * NewModelMatrixArray = new Xenon::Math::Matrix4x4 [ InstanceCount ];
			Xenon::Math::Matrix4x4 * NewNormalMatrixArray = new Xenon::Math::Matrix4x4 [ InstanceCount ];
			
			void * OldModelMatrixArray = TransformData.Instanced -> InstancedModelTransforms -> GetData ();
			void * OldNormalMatrixArray = TransformData.Instanced -> InstancedNormalTransforms -> GetData ();
			
			if ( TransformData.Instanced -> InstanceCount != 0 )
			{
				
				memcpy ( NewModelMatrixArray, OldModelMatrixArray, sizeof ( Xenon::Math::Matrix4x4 ) * InstanceCount );
				memcpy ( NewNormalMatrixArray, OldNormalMatrixArray, sizeof ( Xenon::Math::Matrix4x4 ) * InstanceCount );
				
			}
			
			for ( uint32_t I = TransformData.Instanced -> InstanceCount; I < InstanceCount; I ++ )
			{
				
				Xenon::Math::Matrix4x4 :: Identity ( NewModelMatrixArray [ I ] );
				Xenon::Math::Matrix4x4 :: Identity ( NewNormalMatrixArray [ I ] );
				
			}
			
			TransformData.Instanced -> InstancedModelTransforms = new Red::Util :: RCMem ( reinterpret_cast <void *> ( NewModelMatrixArray ), & DeleteMatrixArray );
			TransformData.Instanced -> InstancedNormalTransforms = new Red::Util :: RCMem ( reinterpret_cast <void *> ( NewNormalMatrixArray ), & DeleteMatrixArray );
			
			TransformData.Instanced -> InstancedModelTransformData.~MeshAttributeData (); 
			TransformData.Instanced -> InstancedNormalTransformData.~MeshAttributeData ();
			
			new ( & TransformData.Instanced -> InstancedModelTransformData ) Xenon::Geometry :: MeshAttributeData ( TransformData.Instanced -> InstancedModelTransforms, sizeof ( Xenon::Math::Matrix4x4 ) * InstanceCount, Xenon::GPU::VertexBuffer :: kUsageType_Dynamic_Draw, true );
			new ( & TransformData.Instanced -> InstancedNormalTransformData ) Xenon::Geometry :: MeshAttributeData ( TransformData.Instanced -> InstancedNormalTransforms, sizeof ( Xenon::Math::Matrix4x4 ) * InstanceCount, Xenon::GPU::VertexBuffer :: kUsageType_Dynamic_Draw, true );
			
			
			TransformData.Instanced -> InstanceCountAllocated = InstanceCount;
			
		}
		
		TransformData.Instanced -> InstanceCount = InstanceCount;
		TransformData.Instanced -> Draw.SetInstanceCount ( InstanceCount );
		
	}
	
}

void Red::Graphics::Model :: CopyModelTransform ( const Xenon::Math::Matrix4x4 & CopyFrom, uint32_t Index )
{
	
	switch ( Method )
	{
		
		case kDrawMethod_Single:
		{
			
			if ( Index != 0 )
				return;
			
			Xenon::Math::Matrix4x4 :: Copy ( TransformData.Single -> NonIndexedModelTransform, CopyFrom );
			
		}
		break;
			
		case kDrawMethod_Instanced:
		{
			
			if ( Index >= TransformData.Instanced -> InstanceCount )
				return;
			
			Xenon::Math::Matrix4x4 :: Copy ( reinterpret_cast <Xenon::Math :: Matrix4x4 *> ( TransformData.Instanced -> InstancedModelTransforms -> GetData () ) [ Index ], CopyFrom );
			
		}
		break;
			
		default:
			break;
			 
	}
	
}

void Red::Graphics::Model :: CopyNormalTransform ( const Xenon::Math::Matrix4x4 & CopyFrom, uint32_t Index )
{
	
	switch ( Method )
	{
		
		case kDrawMethod_Single:
		{
			
			if ( Index != 0 )
				return;
			
			Xenon::Math::Matrix4x4 :: Copy ( TransformData.Single -> NonIndexedNormalTransform, CopyFrom );
			
		}
		break;
			
		case kDrawMethod_Instanced:
		{
			
			if ( Index >= TransformData.Instanced -> InstanceCount )
				return;
			
			Xenon::Math::Matrix4x4 :: Copy ( reinterpret_cast <Xenon::Math :: Matrix4x4 *> ( TransformData.Instanced -> InstancedNormalTransforms -> GetData () ) [ Index ], CopyFrom );
			
		}
		break;
			
		default:
			break;
			 
	}
	
}

void Red::Graphics::Model :: ApplyUniforms ( Xenon::GPU :: UniformSet & TargetSet )
{
	
	switch ( Method )
	{
		
		case kDrawMethod_Single:
		{
			
			TargetSet.AddMatrix4x4Uniform ( TransformData.Single -> ModelTransformName, & TransformData.Single -> ModelTransformUniform );
			TargetSet.AddMatrix4x4Uniform ( TransformData.Single -> NormalTransformName, & TransformData.Single -> NormalTransformUniform );
			
		}
		break;
		
		default:
			break;
		
	}
	
	TargetSet.AddBoolUniform ( DoInstancedTransformUniformName, & DoInstancedTransformUniform );
	TargetSet.AddBoolUniform ( DoNormalTextureUniformName, & DoNormalTextureUniform );
	
}

void Red::Graphics::Model :: ApplyVertexData ( Xenon::GPU :: VertexArray & VArray )
{
	
	
	ModelMesh -> FlushVertexes ( false );
	ModelMesh -> BuildVertexArray ( VArray );
	
	switch ( Method )
	{
		
		case kDrawMethod_Instanced:
		{
			
			TransformData.Instanced -> InstancedModelTransformAttribute.ApplyToVertexArray ( VArray );
			TransformData.Instanced -> InstancedNormalTransformAttribute.ApplyToVertexArray ( VArray );
			
		}
		
	}
	
}

void Red::Graphics::Model :: Draw ()
{
	
	switch ( Method )
	{
		
		case kDrawMethod_Instanced:
			return TransformData.Instanced -> Draw.Draw ();
			
		case kDrawMethod_Single:
			return TransformData.Single -> Draw.Draw ();
			
		default:
			break;
		
	}
	
}
