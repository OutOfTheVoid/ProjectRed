#ifndef XENON_GEOMETRY_CUBE_H
#define XENON_GEOMETRY_CUBE_H

#include <Xenon/Xenon.h>

#include <Xenon/Geometry/Geometry.h>
#include <Xenon/Geometry/Mesh.h>
#include <Xenon/Geometry/MeshAttribute.h>
#include <Xenon/Geometry/MeshAttributeData.h>

#include <Xenon/Math/Vec2.h>
#include <Xenon/Math/Vec3.h>
#include <Xenon/Math/Quaternion.h>

#include <Xenon/GPU/VertexArray.h>

namespace Xenon
{
	
	namespace Geometry
	{
		
		class Primitives
		{
		public:
			
			typedef uint32_t AttributeFlags;
			
			static const AttributeFlags kAttributeFlags_Position = 1;
			static const AttributeFlags kAttributeFlags_Normal = 2;
			static const AttributeFlags kAttributeFlags_Tangent = 4;
			static const AttributeFlags kAttributeFlags_Color = 8;
			static const AttributeFlags kAttributeFlags_TexturePositions = 16;
			
			typedef uint32_t CubeFaceVertexIndex;
			
			static const CubeFaceVertexIndex kCubeFaceVertexIndex_XNeg_YNeg = 0;
			static const CubeFaceVertexIndex kCubeFaceVertexIndex_XNeg_YPos = 1;
			static const CubeFaceVertexIndex kCubeFaceVertexIndex_XPos_YPos = 2;
			static const CubeFaceVertexIndex kCubeFaceVertexIndex_XPos_YNeg = 3;
			
			static const CubeFaceVertexIndex kCubeFaceVertexIndex_Modulus = 4;
			
			typedef uint32_t CubeFaceIndex;
			
			static const CubeFaceIndex kCubeFaceIndex_ZPos = 0;
			static const CubeFaceIndex kCubeFaceIndex_ZNeg = 1;
			static const CubeFaceIndex kCubeFaceIndex_YPos = 2;
			static const CubeFaceIndex kCubeFaceIndex_YNeg = 3;
			static const CubeFaceIndex kCubeFaceIndex_XPos = 4;
			static const CubeFaceIndex kCubeFaceIndex_XNeg = 5;
			
			typedef uint32_t CubeVertexPositionIndex;
			
			static const CubeVertexPositionIndex kCubeVertexPositionIndex_ZNeg_XNeg_YNeg = 0;
			static const CubeVertexPositionIndex kCubeVertexPositionIndex_ZNeg_XNeg_YPos = 1;
			static const CubeVertexPositionIndex kCubeVertexPositionIndex_ZNeg_XPos_YPos = 2;
			static const CubeVertexPositionIndex kCubeVertexPositionIndex_ZNeg_XPos_YNeg = 3;
			static const CubeVertexPositionIndex kCubeVertexPositionIndex_ZPos_XNeg_YNeg = 4;
			static const CubeVertexPositionIndex kCubeVertexPositionIndex_ZPos_XNeg_YPos = 5;
			static const CubeVertexPositionIndex kCubeVertexPositionIndex_ZPos_XPos_YPos = 6;
			static const CubeVertexPositionIndex kCubeVertexPositionIndex_ZPos_XPos_YNeg = 7;
			
			typedef struct CubePositionSpec_Struct
			{
				
				inline CubePositionSpec_Struct ()
				{
				};
				
				inline ~CubePositionSpec_Struct ()
				{
				};
				
				std :: string AttributeName;
				bool Static;
				
				bool NonClosed;
				
				Math :: Vec3 Scale;				
				Math :: Vec3 BlowUp;
				Math :: Vec3 Offset;
				
			} CubePositionSpec;
			
			typedef struct CubeNormalSpec_Struct
			{
				
				inline CubeNormalSpec_Struct ()
				{
				};
				
				inline ~CubeNormalSpec_Struct ()
				{
				};
				
				enum NormalLayout
				{
					
					kNormalLayout_CommonVertex,
					kNormalLayout_FaceVertex,
					kNormalLayout_Face
					
				};
				
				std :: string AttributeName;
				bool Static;
				
				NormalLayout Layout;
				
				union
				{
					
					Math :: Vec3 CommonVertexNormals [ 8 ];
					Math :: Vec3 FaceVertexNormals [ 6 ][ 4 ];
					Math :: Vec3 FaceNormals [ 6 ];
					
				};
				
			} CubeNormalSpec;
			
			typedef struct CubeTangentSpec_Struct
			{
				
				inline CubeTangentSpec_Struct ()
				{
				};
				
				inline ~CubeTangentSpec_Struct ()
				{
				};
				
				enum TangentLayout
				{
					
					kTangentLayout_CommonVertex,
					kTangentLayout_FaceVertex,
					kTangentlLayout_Face
					
				};
				
				std :: string AttributeName;
				bool Static;
				
				TangentLayout Layout;
				
				union
				{
					
					Math :: Vec3 CommonVertexTangent [ 8 ];
					Math :: Vec3 FaceVertexTangent [ 6 ][ 4 ];
					Math :: Vec3 FaceTangent [ 6 ];
					
				};
				
			} CubeTangentSpec;
			
			typedef struct CubeColorSpec_Struct
			{
				
				inline CubeColorSpec_Struct ()
				{
				};
				
				inline ~CubeColorSpec_Struct ()
				{
				};
				
				enum ColorLayout
				{
					
					kColorLayout_CommonVertex,
					kColorLayout_FaceVertex,
					kColorLayout_Face
					
				};
				
				std :: string AttributeName;
				bool Static;
				
				ColorLayout Layout;
				
				union
				{
					
					Math :: Vec3 CommonVertexColors [ 8 ];
					Math :: Vec3 FaceVertexColors [ 6 ][ 4 ];
					Math :: Vec3 FaceColors [ 6 ];
					
				};
				
			} CubeColorSpec;
			
			typedef struct CubeTexturePositionSpec_Struct
			{
				
				inline CubeTexturePositionSpec_Struct ()
				{
				};
				
				inline ~CubeTexturePositionSpec_Struct ()
				{
				};
				
				enum TexturePositionLayout
				{
					
					kTexturePositionLayout_CommonFaceRightAngleRotation,
					kTexturePositionLayout_PerCommonVertex,
					kTexturePositionLayout_PerFaceVertex,
					kTexturePositionLayout_PerCommonVertexCubeTexture
					
				};
				
				typedef struct
				{
					
					enum RightFaceRotation
					{
						
						kRightFaceRotation_0 = 0,
						kRightFaceRotation_90 = 1,
						kRightFaceRotation_180 = 2,
						kRightFaceRotation_270 = 3,
						
					};
					
					Math :: Vec2 FaceVertexTexPositions [ 4 ];
					RightFaceRotation FaceRotations [ 6 ];
					
				} CommonFaceRightAngleTexturePositions;
				
				std :: string AttributeName;
				bool Static;
				
				union
				{
					
					CommonFaceRightAngleTexturePositions PerFaceComonRightAngleTexturePositions;
					Math :: Vec2 PerFaceSpecificTexturePositions [ 6 ][ 4 ];
					Math :: Vec2 PerCommonVertexTexturePositions [ 8 ];
					Math :: Vec3 PerCommonVertexCubeTexturePositions [ 8 ];
					
				};
				
				TexturePositionLayout Layout;
				
			} CubeTexturePositionSpec;
			
			enum StaticAttributeCompositionMode
			{
				
				kStaticAttributeCompositionMode_SeperateBuffers,
				kStaticAttributeCompositionMode_SequentialBlocks,
				kStaticAttributeCompositionMode_Interleaved
				
			};
			
			typedef struct CubeSpec_Struct
			{
				
				inline CubeSpec_Struct ()
				{
				};
				
				inline ~CubeSpec_Struct ()
				{
				};
				
				bool WindOutwardFacesClockwise;
				
				StaticAttributeCompositionMode CompositionMode;
				
				AttributeFlags Attributes;
				
				CubePositionSpec PositionSpec;
				CubeColorSpec ColorSpec;
				CubeNormalSpec NormalSpec;
				CubeTangentSpec TangentSpec;
				
				uint32_t TexturePositionCount;
				CubeTexturePositionSpec TexturePositionSpecs [];
				
			} CubeSpec;
			
			static void SetupUnitCubeVertexPositionSpec ( CubePositionSpec & Spec, const std :: string AttributeName, bool Static );
			
			static void SetupRealCubeFaceNormalSpec ( CubeNormalSpec & Spec, const std :: string AttributeName, bool Static );
			static void SetupRadialCubeVertexNormalSpec ( CubeNormalSpec & Spec, const std :: string AttributeName, bool Static );
			
			static void SetupRealCubeFaceTangentSpec ( CubeTangentSpec & Spec, const std :: string AttributeName, const CubeTexturePositionSpec & DirectionReference, bool Clockwise = true );
			
			static void SetupRegularCubeFaceTexturePositionSpec ( CubeTexturePositionSpec & Spec, CubeTexturePositionSpec::CommonFaceRightAngleTexturePositions :: RightFaceRotation FaceRotations [ 6 ] = NULL );
			
			static bool GenerateCubeMesh ( Mesh ** Target, const CubeSpec & Spec );
			
		};
		
	};
	
};

#endif
