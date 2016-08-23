#ifndef XENON_TEXTURE_H
#define XENON_TEXTURE_H

#include <Xenon/Xenon.h>
#include <Xenon/GPU/GPU.h>
#include <Xenon/GPU/GLInclude.h>
#include <Xenon/GPU/Context.h>
#include <Xenon/GPU/IGPUResourceUser.h>
#include <Xenon/GPU/ITexture.h>

#include <Red/Util/RefCounted.h>

namespace Xenon
{
	
	namespace GPU
	{
		
		class Texture2D : public ITexture, public Red::Util :: RefCounted
		{
		public:
			
			typedef GLint InternalFormat;
			
		// Defaults
			static const InternalFormat kInternalFormat_Depth = GL_DEPTH_COMPONENT;
			static const InternalFormat kInternalFormat_DepthStencil = GL_DEPTH_STENCIL;
			static const InternalFormat kInternalFormat_R = GL_RED;
			static const InternalFormat kInternalFormat_RG = GL_RG;
			static const InternalFormat kInternalFormat_RGB = GL_RGB;
			static const InternalFormat kInternalFormat_RGBA = GL_RGBA;
			
		// Sized
			static const InternalFormat kInternalFormat_R8 = GL_R8;
			static const InternalFormat kInternalFormat_R8_SignedNormalized = GL_R8_SNORM;
			static const InternalFormat kInternalFormat_R16 = GL_R16;
			static const InternalFormat kInternalFormat_R16_SignedNormalized = GL_R16_SNORM;
			static const InternalFormat kInternalFormat_RG8 = GL_RG8;
			static const InternalFormat kInternalFormat_RG8_SignedNormalized = GL_RG8_SNORM;
			static const InternalFormat kInternalFormat_RG16 = GL_RG16;
			static const InternalFormat kInternalFormat_RG16_SignedNormalized = GL_RG16_SNORM;
			static const InternalFormat kInternalFormat_R3G3B2 = GL_R3_G3_B2;
			static const InternalFormat kInternalFormat_RGB4 = GL_RGB4;
			static const InternalFormat kInternalFormat_RGB5 = GL_RGB5;
			static const InternalFormat kInternalFormat_RGB8 = GL_RGB8;
			static const InternalFormat kInternalFormat_RGB8_SignedNormalized = GL_RGB8_SNORM;
			static const InternalFormat kInternalFormat_RGB10 = GL_RGB10;
			static const InternalFormat kInternalFormat_RGB12 = GL_RGB12;
			static const InternalFormat kInternalFormat_RGB16_SignedNormalized = GL_RGB16_SNORM;
			static const InternalFormat kInternalFormat_RGBA2 = GL_RGBA2;
			static const InternalFormat kInternalFormat_RGBA4 = GL_RGBA4;
			static const InternalFormat kInternalFormat_RGB5A1 = GL_RGB5_A1;
			static const InternalFormat kInternalFormat_RGBA8 = GL_RGBA8;
			static const InternalFormat kInternalFormat_RGBA8_SignedNormalized = GL_RGBA8_SNORM;
			static const InternalFormat kInternalFormat_RGB10A2 = GL_RGB10_A2;
			static const InternalFormat kInternalFormat_RGB10A2ui = GL_RGB10_A2UI;
			static const InternalFormat kInternalFormat_RGBA12 = GL_RGBA12;
			static const InternalFormat kInternalFormat_RGBA16 = GL_RGBA16;
			static const InternalFormat kInternalFormat_sRGB8 = GL_SRGB8;
			static const InternalFormat kInternalFormat_sRGB8A8 = GL_SRGB8_ALPHA8;
			static const InternalFormat kInternalFormat_R16f = GL_R16F;
			static const InternalFormat kInternalFormat_RG16f = GL_RG16F;
			static const InternalFormat kInternalFormat_RGB16f = GL_RGB16F;
			static const InternalFormat kInternalFormat_RGBA16f = GL_RGBA16F;
			static const InternalFormat kInternalFormat_R32f = GL_R32F;
			static const InternalFormat kInternalFormat_RG32f = GL_RG32F;
			static const InternalFormat kInternalFormat_RGB32f = GL_RGB32F;
			static const InternalFormat kInternalFormat_RGBA32f = GL_RGBA32F;
			static const InternalFormat kInternalFormat_RG11fB10f = GL_R11F_G11F_B10F;
			static const InternalFormat kInternalFormat_RGB9E5 = GL_RGB9_E5;
			static const InternalFormat kInternalFormat_R8i = GL_R8I;
			static const InternalFormat kInternalFormat_R8ui = GL_R8UI;
			static const InternalFormat kInternalFormat_R16i = GL_R16I;
			static const InternalFormat kInternalFormat_R16ui = GL_R16UI;
			static const InternalFormat kInternalFormat_R32i = GL_R32I;
			static const InternalFormat kInternalFormat_R32ui = GL_R32UI;
			static const InternalFormat kInternalFormat_RG8i = GL_RG8I;
			static const InternalFormat kInternalFormat_RG8ui = GL_RG8UI;
			static const InternalFormat kInternalFormat_RG16i = GL_RG16I;
			static const InternalFormat kInternalFormat_RG16ui = GL_RG16UI;
			static const InternalFormat kInternalFormat_RG32i = GL_RG32I;
			static const InternalFormat kInternalFormat_RG32ui = GL_RG32UI;
			static const InternalFormat kInternalFormat_RGB8i = GL_RGB8I;
			static const InternalFormat kInternalFormat_RGB8ui = GL_RGB8UI;
			static const InternalFormat kInternalFormat_RGB16i = GL_RGB16I;
			static const InternalFormat kInternalFormat_RGB16ui = GL_RGB16UI;
			static const InternalFormat kInternalFormat_RGB32i = GL_RGB32I;
			static const InternalFormat kInternalFormat_RGB32ui = GL_RGB32UI;
			static const InternalFormat kInternalFormat_RGBA8i = GL_RGBA8I;
			static const InternalFormat kInternalFormat_RGBA8ui = GL_RGBA8UI;
			static const InternalFormat kInternalFormat_RGBA16i = GL_RGBA16I;
			static const InternalFormat kInternalFormat_RGBA16ui = GL_RGBA16UI;
			static const InternalFormat kInternalFormat_RGBA32i = GL_RGBA32I;
			static const InternalFormat kInternalFormat_RGBA32ui = GL_RGBA32UI;
			
		// Default compression
			static const InternalFormat kInternalFormat_R_Compressed = GL_COMPRESSED_RED;
			static const InternalFormat kInternalFormat_RG_Compressed = GL_COMPRESSED_RG;
			static const InternalFormat kInternalFormat_RGB_Compressed = GL_COMPRESSED_RGB;
			static const InternalFormat kInternalFormat_RGBA_Compressed = GL_COMPRESSED_RGBA;
			static const InternalFormat kInternalFormat_sRGB_Compressed = GL_COMPRESSED_SRGB;
			static const InternalFormat kInternalFormat_sRGBA_Compressed = GL_COMPRESSED_SRGB_ALPHA;
			
			typedef GLenum ExternalFormat;
			
			static const ExternalFormat kExternalFormat_R = GL_RED;
			static const ExternalFormat kExternalFormat_RG = GL_RG;
			static const ExternalFormat kExternalFormat_RGB = GL_RGB;
			static const ExternalFormat kExternalFormat_BGR = GL_BGR;
			static const ExternalFormat kExternalFormat_RGBA = GL_RGBA;
			static const ExternalFormat kExternalFormat_BGRA = GL_BGRA;
			static const ExternalFormat kExternalFormat_Ri = GL_RED_INTEGER;
			static const ExternalFormat kExternalFormat_RGi = GL_RG_INTEGER;
			static const ExternalFormat kExternalFormat_RGBi = GL_RGB_INTEGER;
			static const ExternalFormat kExternalFormat_BGRi = GL_BGR_INTEGER;
			static const ExternalFormat kExternalFormat_RGBAi = GL_RGBA_INTEGER;
			static const ExternalFormat kExternalFormat_BGRAi = GL_BGRA_INTEGER;
			static const ExternalFormat kExternalFormat_Stencil = GL_STENCIL_INDEX;
			static const ExternalFormat kExternalFormat_Depth = GL_DEPTH_COMPONENT;
			static const ExternalFormat kExternalFormat_DepthStencil = GL_DEPTH_STENCIL;
			
			typedef GLenum ExternalLayout;
			
			static const ExternalLayout kExternalLayout_UByte = GL_UNSIGNED_BYTE;
			static const ExternalLayout kExternalLayout_Byte = GL_BYTE;
			static const ExternalLayout kExternalLayout_UShort = GL_UNSIGNED_SHORT;
			static const ExternalLayout kExternalLayout_Short = GL_SHORT;
			static const ExternalLayout kExternalLayout_UInt = GL_UNSIGNED_INT;
			static const ExternalLayout kExternalLayout_Int = GL_INT;
			static const ExternalLayout kExternalLayout_Float = GL_FLOAT;
			static const ExternalLayout kExternalLayout_UByte_3_3_2 = GL_UNSIGNED_BYTE_3_3_2;
			static const ExternalLayout kExternalLayout_UByte_2_3_3_Rev = GL_UNSIGNED_BYTE_2_3_3_REV;
			static const ExternalLayout kExternalLayout_UByte_5_6_5 = GL_UNSIGNED_SHORT_5_6_5;
			static const ExternalLayout kExternalLayout_UByte_5_6_5_Rev = GL_UNSIGNED_SHORT_5_6_5_REV;
			static const ExternalLayout kExternalLayout_UShort_4_4_4_4 = GL_UNSIGNED_SHORT_4_4_4_4;
			static const ExternalLayout kExternalLayout_UShort_4_4_4_4_Rev = GL_UNSIGNED_SHORT_4_4_4_4_REV;
			static const ExternalLayout kExternalLayout_UShort_5_5_5_1 = GL_UNSIGNED_SHORT_5_5_5_1;
			static const ExternalLayout kExternalLayout_UShort_1_5_5_5_Rev = GL_UNSIGNED_SHORT_1_5_5_5_REV;
			static const ExternalLayout kExternalLayout_UInt_8_8_8_8 = GL_UNSIGNED_INT_8_8_8_8;
			static const ExternalLayout kExternalLayout_UInt_8_8_8_8_Rev = GL_UNSIGNED_INT_8_8_8_8_REV;
			static const ExternalLayout kExternalLayout_UInt_10_10_10_2 = GL_UNSIGNED_INT_10_10_10_2;
			static const ExternalLayout kExternalLayout_UInt_2_10_10_10_Rev = GL_UNSIGNED_INT_2_10_10_10_REV;
			
			typedef GLint MinimizingFilter;
			
			static const MinimizingFilter kMinimizingFilter_Nearest = GL_NEAREST;
			static const MinimizingFilter kMinimizingFilter_Linear = GL_LINEAR;
			static const MinimizingFilter kMinimizingFilter_Nearest_MipMapNearest = GL_NEAREST_MIPMAP_NEAREST;
			static const MinimizingFilter kMinimizingFilter_Nearest_MipMapLinear = GL_NEAREST_MIPMAP_LINEAR;
			static const MinimizingFilter kMinimizingFilter_Linear_MipMapNearest = GL_LINEAR_MIPMAP_NEAREST;
			static const MinimizingFilter kMinimizingFilter_Linear_MipMapLinear = GL_LINEAR_MIPMAP_LINEAR;
			
			typedef GLint MagnificationFilter;
			
			static const MagnificationFilter kMagnificationFilter_Nearest = GL_NEAREST;
			static const MagnificationFilter kMagnificationFilter_Linear = GL_LINEAR;
			
			typedef GLint WrapMode;
			
			static const WrapMode kWrapMode_EdgeClamp = GL_CLAMP_TO_EDGE;
			static const WrapMode kWrapMode_MirroredRepeat = GL_MIRRORED_REPEAT;
			static const WrapMode kWrapMode_Repeat = GL_REPEAT;
			
			Texture2D ();
			~Texture2D ();
			
			void GPUResourceAlloc ();
			void GPUResourceFree ();
			
			bool GPUResourceAllocated ();
			
			void BlankTextureImage ( GLint DetailLevel, InternalFormat FInternal, GLsizei Width, GLsizei Height, ExternalLayout ELayout, ExternalFormat EFormat );
			void TextureImage ( GLint DetailLevel, InternalFormat FInternal, GLsizei Width, GLsizei Height, ExternalFormat EFormat, ExternalLayout ELayout, const GLvoid * Data, GLuint Alignment = 1 );
			
			void GenerateMipMaps ();
			
			void Bind ();
			
			void SetFiltering ( MinimizingFilter MinFilter, MagnificationFilter MagFilter );
			
			void SetWrapMode ( WrapMode Mode );
			void SetWrapMode ( WrapMode ModeS, WrapMode ModeT );
			
			void AssignToTextureUnit ( GLuint Unit );
			
		private:
			
			bool Allocated;
			
			GLuint THandle;
			
		};
		
	}

}

#endif
