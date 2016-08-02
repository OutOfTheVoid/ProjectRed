#ifndef XENON_GPU_UNIFORMSET_H
#define XENON_GPU_UNIFORMSET_H

#include <Xenon/Xenon.h>
#include <Xenon/GPU/GPU.h>
#include <Xenon/GPU/GLInclude.h>
#include <Xenon/GPU/ShaderProgram.h>
#include <Xenon/GPU/IFloatUniformSource.h>
#include <Xenon/GPU/IFloatVec2UniformSource.h>
#include <Xenon/GPU/IFloatVec3UniformSource.h>
#include <Xenon/GPU/IFloatVec4UniformSource.h>
#include <Xenon/GPU/IMatrix3x3UniformSource.h>
#include <Xenon/GPU/IMatrix4x4UniformSource.h>
#include <Xenon/Util/RefCounted.h>

#include <string>
#include <vector>

namespace Xenon
{
	
	namespace GPU
	{
		
		class UniformSet : public Util :: RefCounted
		{
		public:
			
			explicit UniformSet ( ShaderProgram * Program = NULL, uint32_t Matrix4x4Prealloc = 0, uint32_t Matrix3x3Prealloc = 0, uint32_t Vec4Prealloc = 0, uint32_t Vec3Prealloc = 0, uint32_t Vec2Prealloc = 0, uint32_t FloatPrealloc = 0 );
			~UniformSet ();
			
			void AddFloatUniform ( const std :: string Name, const IFloatUniformSource * Source, bool LocateImmediately = true );
			void AddFloatVec2Uniform ( const std :: string Name, const IFloatVec2UniformSource * Source, bool LocateImmediately = true );
			void AddFloatVec3Uniform ( const std :: string Name, const IFloatVec3UniformSource * Source, bool LocateImmediately = true );
			void AddFloatVec4Uniform ( const std :: string Name, const IFloatVec4UniformSource * Source, bool LocateImmediately = true );
			
			void AddMatrix3x3Uniform ( const std :: string Name, const IMatrix3x3UniformSource * Source, bool LocateImmediately = true );
			void AddMatrix4x4Uniform ( const std :: string Name, const Xenon::GPU::IMatrix4x4UniformSource * Source, bool LocateImmediately = true );
			
			void Link ();
			
			void ResetUniformStates ();
			void UpdateUniforms ( bool Relink = false );
			
			void SetProgram ( ShaderProgram * Program );
			
		private:
			
			typedef struct
			{
				
				const IFloatUniformSource * Source;
				std :: string Name;
				
				GLint UniformLocation;
				
				int64_t LastUploadedIteration;
				
			} FloatUniformTracker;
			
			typedef struct
			{
				
				const IFloatVec2UniformSource * Source;
				std :: string Name;
				
				GLint UniformLocation;
				
				int64_t LastUploadedIteration;
				
			} FloatVec2UniformTracker;
			
			typedef struct
			{
				
				const IFloatVec3UniformSource * Source;
				std :: string Name;
				
				GLint UniformLocation;
				
				int64_t LastUploadedIteration;
				
			} FloatVec3UniformTracker;
			
			typedef struct
			{
				
				const IFloatVec4UniformSource * Source;
				std :: string Name;
				
				GLint UniformLocation;
				
				int64_t LastUploadedIteration;
				
			} FloatVec4UniformTracker;
			
			typedef struct
			{
				
				const IMatrix3x3UniformSource * Source;
				std :: string Name;
				
				GLint UniformLocation;
				
				int64_t LastUploadedIteration;
				
			} Matrix3x3UniformTracker;
			
			typedef struct Matrix4x4UniformTracker_Struct
			{
				
				const IMatrix4x4UniformSource * Source;
				std :: string Name;
				
				GLint UniformLocation;
				
				int64_t LastUploadedIteration;
				
			} Matrix4x4UniformTracker;
			
			ShaderProgram * Program;
			
			int64_t LastLinkIteration;
			
			std :: vector <FloatUniformTracker> FloatUniforms;
			std :: vector <FloatVec2UniformTracker> FloatVec2Uniforms;
			std :: vector <FloatVec3UniformTracker> FloatVec3Uniforms;
			std :: vector <FloatVec4UniformTracker> FloatVec4Uniforms;
			
			std :: vector <Matrix3x3UniformTracker> Matrix3x3Uniforms;
			std :: vector <Matrix4x4UniformTracker> Matrix4x4Uniforms;
			
		};
		
	}
	
}

#endif
