#ifndef RED_GRAPHICS_MODEL_H
#define RED_GRAPHICS_MODEL_H

#include <Red/Graphics/Graphics.h>

#include <Red/Util/RefCounted.h>

#include <Xenon/GPU/VertexArray.h>
#include <Xenon/GPU/UniformSet.h>
#include <Xenon/GPU/DrawCall.h>
#include <Xenon/GPU/IndexedDrawCall.h>
#include <Xenon/GPU/InstancedIndexedDrawCall.h>

#include <Xenon/Geometry/Mesh.h>

#include <Xenon/Math/Matrix4x4.h>
#include <Xenon/Math/RawMatrix4x4UniformSource.h>
#include <Xenon/Math/ConstantBoolUniformSource.h>

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
			
			typedef struct
			{
				
				const std :: string * InstancedModelTransformAttributeName;
				const std :: string * InstancedNormalTransformAttributeName;
				const std :: string * PositionAttributeName;
				const std :: string * NormalAttributeName;
				const std :: string * TangentAttributeName;
				const std :: string * ColorAttributeName;
				const std :: string * TextureCoordAttributeName;
				
				const std :: string * ModelMatrixUniformName;
				const std :: string * NormalMatrixUniformName;
				
				const std :: string * DoInstancedTransformUniformName;
				const std :: string * DoNormalTextureUniformName;
				const std :: string * DoColorTextureUniformName;
				
			} ModelShaderConfigurationNames;
			
			Model ( Xenon::Geometry :: Mesh * ModelMesh, DrawMethod Method, const ModelShaderConfigurationNames & ShaderConfigurationNames );
			~Model ();
			
			void SetVisible ( bool Visible );
			void SetInstanceCount ( uint32_t InstanceCount );
			
			void CopyModelTransform ( const Xenon::Math::Matrix4x4 & CopyFrom, uint32_t Index = 0 );
			void CopyNormalTransform ( const Xenon::Math::Matrix4x4 & CopyFrom, uint32_t Index = 0 );
			
			void ApplyUniforms ( Xenon::GPU :: UniformSet & TargetSet );
			void ApplyVertexData ( Xenon::GPU :: VertexArray & Array );
			
			void FlushData ();
			
			void Draw ();
			
		private:
			
			static void DeleteMatrixArray ( void * MatrixArray );
			
			class InstancedData
			{
			public:
				
				InstancedData ( const std :: string & ModelTransformName, const std :: string & NormalTransformName );
				~InstancedData ();
				
				Util::RCMem * InstancedModelTransforms;
				Util::RCMem * InstancedNormalTransforms;
				
				Xenon::Geometry :: MeshAttributeData InstancedModelTransformData;
				Xenon::Geometry :: MeshAttributeData InstancedNormalTransformData;
				
				Xenon::Geometry :: MeshAttribute InstancedModelTransformAttribute;
				Xenon::Geometry :: MeshAttribute InstancedNormalTransformAttribute;
				
				uint32_t InstanceCount;
				uint32_t InstanceCountAllocated;
				
				Xenon::GPU :: InstancedIndexedDrawCall Draw;
				
			};
			
			class SingleData
			{
			public:
				
				SingleData ( const std :: string & ModelTransformName, const std :: string & NormalTransformName );
				~SingleData ();
				
				Xenon::Math :: Matrix4x4 NonIndexedModelTransform;
				Xenon::Math :: Matrix4x4 NonIndexedNormalTransform;
				
				Xenon::Math :: RawMatrix4x4UniformSource ModelTransformUniform;
				Xenon::Math :: RawMatrix4x4UniformSource NormalTransformUniform;
				
				const std :: string ModelTransformName;
				const std :: string NormalTransformName;
				
				Xenon::GPU :: IndexedDrawCall Draw;
				
			};
			
			friend class DeferredModelRenderer;
			
			void GPUAlloc ();
			void GPUFree ();
			
			DrawMethod Method;
			
			union
			{
				
				InstancedData * Instanced;
				SingleData * Single;
				
			} TransformData;
			
			bool Visible;
			
			Xenon::Geometry :: Mesh * ModelMesh;
			
			const std :: string DoInstancedTransformUniformName;
			const std :: string DoNormalTextureUniformName;
			const std :: string DoColorTextureUniformName;
			
			Xenon::Math :: ConstantBoolUniformSource DoInstancedTransformUniform;
			Xenon::Math :: ConstantBoolUniformSource DoNormalTextureUniform;
			Xenon::Math :: ConstantBoolUniformSource DoColorTextureUniform;
			
		};
		
	}
	
}

#endif
