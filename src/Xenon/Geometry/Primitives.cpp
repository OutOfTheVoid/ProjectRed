#include <Xenon/Geometry/Primitives.h>
#include <Xenon/Util/RCMem.h>

#include <iostream>

void Xenon::Geometry::Primitives :: SetupRealCubeFaceNormalSpec ( CubeNormalSpec & Spec, const std :: string & AttributeName, bool Static )
{
	
	Spec.Layout = CubeNormalSpec::NormalLayout :: kNormalLayout_Face;
	
	Spec.FaceNormals [ kCubeFaceIndex_ZPos ] = Math::Vec3 :: FORWARD;
	Spec.FaceNormals [ kCubeFaceIndex_ZNeg ] = Math::Vec3 :: BACKWARD;
	Spec.FaceNormals [ kCubeFaceIndex_YPos ] = Math::Vec3 :: UP;
	Spec.FaceNormals [ kCubeFaceIndex_YNeg ] = Math::Vec3 :: DOWN;
	Spec.FaceNormals [ kCubeFaceIndex_XPos ] = Math::Vec3 :: RIGHT;
	Spec.FaceNormals [ kCubeFaceIndex_XNeg ] = Math::Vec3 :: LEFT;
	
	Spec.Static = Static;
	Spec.AttributeName = AttributeName;
	
}

void Xenon::Geometry::Primitives :: SetupRadialCubeVertexNormalSpec ( CubeNormalSpec & Spec, const std :: string & AttributeName, bool Static )
{
	
	Spec.Layout = CubeNormalSpec::NormalLayout :: kNormalLayout_CommonVertex;
	
	Spec.CommonVertexNormals [ kCubeVertexPositionIndex_ZNeg_XNeg_YNeg ] = Math :: Vec3 ( - 1.0f, - 1.0f, - 1.0f );
	Spec.CommonVertexNormals [ kCubeVertexPositionIndex_ZPos_XNeg_YNeg ] = Math :: Vec3 ( - 1.0f, - 1.0f, + 1.0f );
	Spec.CommonVertexNormals [ kCubeVertexPositionIndex_ZNeg_XNeg_YPos ] = Math :: Vec3 ( - 1.0f, + 1.0f, - 1.0f );
	Spec.CommonVertexNormals [ kCubeVertexPositionIndex_ZPos_XNeg_YPos ] = Math :: Vec3 ( - 1.0f, + 1.0f, + 1.0f );
	Spec.CommonVertexNormals [ kCubeVertexPositionIndex_ZNeg_XPos_YNeg ] = Math :: Vec3 ( + 1.0f, - 1.0f, - 1.0f );
	Spec.CommonVertexNormals [ kCubeVertexPositionIndex_ZPos_XPos_YNeg ] = Math :: Vec3 ( + 1.0f, - 1.0f, + 1.0f );
	Spec.CommonVertexNormals [ kCubeVertexPositionIndex_ZNeg_XPos_YPos ] = Math :: Vec3 ( + 1.0f, + 1.0f, - 1.0f );
	Spec.CommonVertexNormals [ kCubeVertexPositionIndex_ZPos_XPos_YPos ] = Math :: Vec3 ( + 1.0f, + 1.0f, + 1.0f );
	
	Spec.Static = Static;
	Spec.AttributeName = AttributeName;
	
}

void Xenon::Geometry::Primitives :: SetupUnitCubeVertexPositionSpec ( CubePositionSpec & Spec, const std :: string & AttributeName, bool Static )
{
	
	Spec.Scale = Math::Vec3 :: IDENTITY;
	Spec.BlowUp = Math::Vec3 :: ZERO;
	Spec.Offset = Math::Vec3 :: ZERO;
	
	Spec.NonClosed = false;
	Spec.Static = Static;
	Spec.AttributeName = AttributeName;
	
}

void Xenon::Geometry::Primitives :: SetupRealCubeFaceTangentSpec ( CubeTangentSpec & Spec, const std :: string & Name, const CubeTexturePositionSpec & DirectionReference, bool Clockwise )
{
	
	Spec.AttributeName = Name;
	
	switch ( DirectionReference.Layout )
	{
		
		case CubeTexturePositionSpec :: kTexturePositionLayout_CommonFaceRightAngleRotation:
		{
			
			Spec.Layout = CubeTangentSpec :: kTangentlLayout_Face;
			
			Math::Vec2 DiffTop ( Math::Vec2 :: NO_INIT );
			Math::Vec2 DiffBottom ( Math::Vec2 :: NO_INIT );
			Math::Vec3 NormalSpaceTangent ( Math::Vec2 :: NO_INIT );
			Math::Quaternion NormalToModelSpaceRotation ( Math::Quaternion :: NO_INIT );
			
			Math::Vec2 :: Subtract ( DiffTop, DirectionReference.PerFaceComonRightAngleTexturePositions.FaceVertexTexPositions [ ( ( Clockwise ? kCubeFaceVertexIndex_XPos_YPos : kCubeFaceVertexIndex_XNeg_YPos ) + DirectionReference.PerFaceComonRightAngleTexturePositions.FaceRotations [ kCubeFaceIndex_ZPos ] ) % kCubeFaceVertexIndex_Modulus ], DirectionReference.PerFaceComonRightAngleTexturePositions.FaceVertexTexPositions [ ( ( Clockwise ? kCubeFaceVertexIndex_XNeg_YPos : kCubeFaceVertexIndex_XPos_YPos ) + DirectionReference.PerFaceComonRightAngleTexturePositions.FaceRotations [ kCubeFaceIndex_ZPos ] ) % kCubeFaceVertexIndex_Modulus ] );
			Math::Vec2 :: Subtract ( DiffBottom, DirectionReference.PerFaceComonRightAngleTexturePositions.FaceVertexTexPositions [ ( ( Clockwise ? kCubeFaceVertexIndex_XPos_YNeg : kCubeFaceVertexIndex_XNeg_YNeg ) + DirectionReference.PerFaceComonRightAngleTexturePositions.FaceRotations [ kCubeFaceIndex_ZPos ] ) % kCubeFaceVertexIndex_Modulus ], DirectionReference.PerFaceComonRightAngleTexturePositions.FaceVertexTexPositions [ ( ( Clockwise ? kCubeFaceVertexIndex_XNeg_YNeg : kCubeFaceVertexIndex_XPos_YNeg ) + DirectionReference.PerFaceComonRightAngleTexturePositions.FaceRotations [ kCubeFaceIndex_ZPos ] ) % kCubeFaceVertexIndex_Modulus ] );
			Math::Vec2 :: Add ( DiffTop, DiffBottom );
			Math::Vec2 :: Normalize ( DiffTop );
			
			NormalSpaceTangent = Math :: Vec3 ( DiffTop, 0.0f );
			Math::Quaternion :: FromBetweenVectors ( NormalToModelSpaceRotation, Math::Vec3 :: BACKWARD, Math::Vec3 :: FORWARD );
			Math::Vec3 :: Rotate ( Spec.FaceTangent [ kCubeFaceIndex_ZPos ], NormalSpaceTangent, NormalToModelSpaceRotation );
			
			Math::Vec2 :: Subtract ( DiffTop, DirectionReference.PerFaceComonRightAngleTexturePositions.FaceVertexTexPositions [ ( ( Clockwise ? kCubeFaceVertexIndex_XPos_YPos : kCubeFaceVertexIndex_XNeg_YPos ) + DirectionReference.PerFaceComonRightAngleTexturePositions.FaceRotations [ kCubeFaceIndex_ZNeg ] ) % kCubeFaceVertexIndex_Modulus ], DirectionReference.PerFaceComonRightAngleTexturePositions.FaceVertexTexPositions [ ( ( Clockwise ? kCubeFaceVertexIndex_XNeg_YPos : kCubeFaceVertexIndex_XPos_YPos ) + DirectionReference.PerFaceComonRightAngleTexturePositions.FaceRotations [ kCubeFaceIndex_ZNeg ] ) % kCubeFaceVertexIndex_Modulus ] );
			Math::Vec2 :: Subtract ( DiffBottom, DirectionReference.PerFaceComonRightAngleTexturePositions.FaceVertexTexPositions [ ( ( Clockwise ? kCubeFaceVertexIndex_XPos_YNeg : kCubeFaceVertexIndex_XNeg_YNeg ) + DirectionReference.PerFaceComonRightAngleTexturePositions.FaceRotations [ kCubeFaceIndex_ZNeg ] ) % kCubeFaceVertexIndex_Modulus ], DirectionReference.PerFaceComonRightAngleTexturePositions.FaceVertexTexPositions [ ( ( Clockwise ? kCubeFaceVertexIndex_XNeg_YNeg : kCubeFaceVertexIndex_XPos_YNeg ) + DirectionReference.PerFaceComonRightAngleTexturePositions.FaceRotations [ kCubeFaceIndex_ZNeg ] ) % kCubeFaceVertexIndex_Modulus ] );
			Math::Vec2 :: Add ( DiffTop, DiffBottom );
			Math::Vec2 :: Normalize ( DiffTop );
			
			Spec.FaceTangent [ kCubeFaceIndex_ZNeg ] = Math :: Vec3 ( DiffTop, 0.0f );;
			
			Math::Vec2 :: Subtract ( DiffTop, DirectionReference.PerFaceComonRightAngleTexturePositions.FaceVertexTexPositions [ ( ( Clockwise ? kCubeFaceVertexIndex_XPos_YPos : kCubeFaceVertexIndex_XNeg_YPos ) + DirectionReference.PerFaceComonRightAngleTexturePositions.FaceRotations [ kCubeFaceIndex_YPos ] ) % kCubeFaceVertexIndex_Modulus ], DirectionReference.PerFaceComonRightAngleTexturePositions.FaceVertexTexPositions [ ( ( Clockwise ? kCubeFaceVertexIndex_XNeg_YPos : kCubeFaceVertexIndex_XPos_YPos ) + DirectionReference.PerFaceComonRightAngleTexturePositions.FaceRotations [ kCubeFaceIndex_YPos ] ) % kCubeFaceVertexIndex_Modulus ] );
			Math::Vec2 :: Subtract ( DiffBottom, DirectionReference.PerFaceComonRightAngleTexturePositions.FaceVertexTexPositions [ ( ( Clockwise ? kCubeFaceVertexIndex_XPos_YNeg : kCubeFaceVertexIndex_XNeg_YNeg ) + DirectionReference.PerFaceComonRightAngleTexturePositions.FaceRotations [ kCubeFaceIndex_YPos ] ) % kCubeFaceVertexIndex_Modulus ], DirectionReference.PerFaceComonRightAngleTexturePositions.FaceVertexTexPositions [ ( ( Clockwise ? kCubeFaceVertexIndex_XNeg_YNeg : kCubeFaceVertexIndex_XPos_YNeg ) + DirectionReference.PerFaceComonRightAngleTexturePositions.FaceRotations [ kCubeFaceIndex_YPos ] ) % kCubeFaceVertexIndex_Modulus ] );
			Math::Vec2 :: Add ( DiffTop, DiffBottom );
			Math::Vec2 :: Normalize ( DiffTop );
			
			NormalSpaceTangent = Math :: Vec3 ( DiffTop, 0.0f );
			Math::Quaternion :: FromBetweenVectors ( NormalToModelSpaceRotation, Math::Vec3 :: BACKWARD, Math::Vec3 :: UP );
			Math::Vec3 :: Rotate ( Spec.FaceTangent [ kCubeFaceIndex_YPos ], NormalSpaceTangent, NormalToModelSpaceRotation );
			
			Math::Vec2 :: Subtract ( DiffTop, DirectionReference.PerFaceComonRightAngleTexturePositions.FaceVertexTexPositions [ ( ( Clockwise ? kCubeFaceVertexIndex_XPos_YPos : kCubeFaceVertexIndex_XNeg_YPos ) + DirectionReference.PerFaceComonRightAngleTexturePositions.FaceRotations [ kCubeFaceIndex_YNeg ] ) % kCubeFaceVertexIndex_Modulus ], DirectionReference.PerFaceComonRightAngleTexturePositions.FaceVertexTexPositions [ ( ( Clockwise ? kCubeFaceVertexIndex_XNeg_YPos : kCubeFaceVertexIndex_XPos_YPos ) + DirectionReference.PerFaceComonRightAngleTexturePositions.FaceRotations [ kCubeFaceIndex_YNeg ] ) % kCubeFaceVertexIndex_Modulus ] );
			Math::Vec2 :: Subtract ( DiffBottom, DirectionReference.PerFaceComonRightAngleTexturePositions.FaceVertexTexPositions [ ( ( Clockwise ? kCubeFaceVertexIndex_XPos_YNeg : kCubeFaceVertexIndex_XNeg_YNeg ) + DirectionReference.PerFaceComonRightAngleTexturePositions.FaceRotations [ kCubeFaceIndex_YNeg ] ) % kCubeFaceVertexIndex_Modulus ], DirectionReference.PerFaceComonRightAngleTexturePositions.FaceVertexTexPositions [ ( ( Clockwise ? kCubeFaceVertexIndex_XNeg_YNeg : kCubeFaceVertexIndex_XPos_YNeg ) + DirectionReference.PerFaceComonRightAngleTexturePositions.FaceRotations [ kCubeFaceIndex_YNeg ] ) % kCubeFaceVertexIndex_Modulus ] );
			Math::Vec2 :: Add ( DiffTop, DiffBottom );
			Math::Vec2 :: Normalize ( DiffTop );
			
			NormalSpaceTangent = Math :: Vec3 ( DiffTop, 0.0f );
			Math::Quaternion :: FromBetweenVectors ( NormalToModelSpaceRotation, Math::Vec3 :: BACKWARD, Math::Vec3 :: DOWN );
			Math::Vec3 :: Rotate ( Spec.FaceTangent [ kCubeFaceIndex_YNeg ], NormalSpaceTangent, NormalToModelSpaceRotation );
			
			Math::Vec2 :: Subtract ( DiffTop, DirectionReference.PerFaceComonRightAngleTexturePositions.FaceVertexTexPositions [ ( ( Clockwise ? kCubeFaceVertexIndex_XPos_YPos : kCubeFaceVertexIndex_XNeg_YPos ) + DirectionReference.PerFaceComonRightAngleTexturePositions.FaceRotations [ kCubeFaceIndex_XPos ] ) % kCubeFaceVertexIndex_Modulus ], DirectionReference.PerFaceComonRightAngleTexturePositions.FaceVertexTexPositions [ ( ( Clockwise ? kCubeFaceVertexIndex_XNeg_YPos : kCubeFaceVertexIndex_XPos_YPos ) + DirectionReference.PerFaceComonRightAngleTexturePositions.FaceRotations [ kCubeFaceIndex_XPos ] ) % kCubeFaceVertexIndex_Modulus ] );
			Math::Vec2 :: Subtract ( DiffBottom, DirectionReference.PerFaceComonRightAngleTexturePositions.FaceVertexTexPositions [ ( ( Clockwise ? kCubeFaceVertexIndex_XPos_YNeg : kCubeFaceVertexIndex_XNeg_YNeg ) + DirectionReference.PerFaceComonRightAngleTexturePositions.FaceRotations [ kCubeFaceIndex_XPos ] ) % kCubeFaceVertexIndex_Modulus ], DirectionReference.PerFaceComonRightAngleTexturePositions.FaceVertexTexPositions [ ( ( Clockwise ? kCubeFaceVertexIndex_XNeg_YNeg : kCubeFaceVertexIndex_XPos_YNeg ) + DirectionReference.PerFaceComonRightAngleTexturePositions.FaceRotations [ kCubeFaceIndex_XPos ] ) % kCubeFaceVertexIndex_Modulus ] );
			Math::Vec2 :: Add ( DiffTop, DiffBottom );
			Math::Vec2 :: Normalize ( DiffTop );
			
			NormalSpaceTangent = Math :: Vec3 ( DiffTop, 0.0f );
			Math::Quaternion :: FromBetweenVectors ( NormalToModelSpaceRotation, Math::Vec3 :: BACKWARD, Math::Vec3 :: RIGHT );
			Math::Vec3 :: Rotate ( Spec.FaceTangent [ kCubeFaceIndex_XPos ], NormalSpaceTangent, NormalToModelSpaceRotation );
			
			Math::Vec2 :: Subtract ( DiffTop, DirectionReference.PerFaceComonRightAngleTexturePositions.FaceVertexTexPositions [ ( ( Clockwise ? kCubeFaceVertexIndex_XPos_YPos : kCubeFaceVertexIndex_XNeg_YPos ) + DirectionReference.PerFaceComonRightAngleTexturePositions.FaceRotations [ kCubeFaceIndex_XNeg ] ) % kCubeFaceVertexIndex_Modulus ], DirectionReference.PerFaceComonRightAngleTexturePositions.FaceVertexTexPositions [ ( ( Clockwise ? kCubeFaceVertexIndex_XNeg_YPos : kCubeFaceVertexIndex_XPos_YPos ) + DirectionReference.PerFaceComonRightAngleTexturePositions.FaceRotations [ kCubeFaceIndex_XNeg ] ) % kCubeFaceVertexIndex_Modulus ] );
			Math::Vec2 :: Subtract ( DiffBottom, DirectionReference.PerFaceComonRightAngleTexturePositions.FaceVertexTexPositions [ ( ( Clockwise ? kCubeFaceVertexIndex_XPos_YNeg : kCubeFaceVertexIndex_XNeg_YNeg ) + DirectionReference.PerFaceComonRightAngleTexturePositions.FaceRotations [ kCubeFaceIndex_XNeg ] ) % kCubeFaceVertexIndex_Modulus ], DirectionReference.PerFaceComonRightAngleTexturePositions.FaceVertexTexPositions [ ( ( Clockwise ? kCubeFaceVertexIndex_XNeg_YNeg : kCubeFaceVertexIndex_XPos_YNeg ) + DirectionReference.PerFaceComonRightAngleTexturePositions.FaceRotations [ kCubeFaceIndex_XNeg ] ) % kCubeFaceVertexIndex_Modulus ] );
			Math::Vec2 :: Add ( DiffTop, DiffBottom );
			Math::Vec2 :: Normalize ( DiffTop );
			
			NormalSpaceTangent = Math :: Vec3 ( DiffTop, 0.0f );
			Math::Quaternion :: FromBetweenVectors ( NormalToModelSpaceRotation, Math::Vec3 :: BACKWARD, Math::Vec3 :: LEFT );
			Math::Vec3 :: Rotate ( Spec.FaceTangent [ kCubeFaceIndex_XNeg ], NormalSpaceTangent, NormalToModelSpaceRotation );
			
		}
		
		case CubeTexturePositionSpec :: kTexturePositionLayout_PerCommonVertex:
		{
			
			// TODO
			
		}
		
		case CubeTexturePositionSpec :: kTexturePositionLayout_PerFaceVertex:
		{
			
			// TODO
			
		}
		
		case CubeTexturePositionSpec :: kTexturePositionLayout_PerCommonVertexCubeTexture:
		{
			
			// TODO
			
		}
		
	};
	
}

void Xenon::Geometry::Primitives :: SetupRegularCubeFaceTexturePositionSpec ( CubeTexturePositionSpec & Spec, CubeTexturePositionSpec::CommonFaceRightAngleTexturePositions :: RightFaceRotation FaceRotations [ 6 ] )
{
	
	Spec.Layout = CubeTexturePositionSpec :: kTexturePositionLayout_CommonFaceRightAngleRotation;
	
	Spec.PerFaceComonRightAngleTexturePositions.FaceVertexTexPositions [ kCubeFaceVertexIndex_XNeg_YNeg ] = Math :: Vec2 ( - 1.0f, - 1.0f );
	Spec.PerFaceComonRightAngleTexturePositions.FaceVertexTexPositions [ kCubeFaceVertexIndex_XNeg_YPos ] = Math :: Vec2 ( - 1.0f, + 1.0f );
	Spec.PerFaceComonRightAngleTexturePositions.FaceVertexTexPositions [ kCubeFaceVertexIndex_XPos_YPos ] = Math :: Vec2 ( + 1.0f, + 1.0f );
	Spec.PerFaceComonRightAngleTexturePositions.FaceVertexTexPositions [ kCubeFaceVertexIndex_XPos_YNeg ] = Math :: Vec2 ( + 1.0f, - 1.0f );
	
	if ( FaceRotations == NULL )
	{
		
		Spec.PerFaceComonRightAngleTexturePositions.FaceRotations [ 0 ] = CubeTexturePositionSpec::CommonFaceRightAngleTexturePositions :: kRightFaceRotation_0;
		Spec.PerFaceComonRightAngleTexturePositions.FaceRotations [ 1 ] = CubeTexturePositionSpec::CommonFaceRightAngleTexturePositions :: kRightFaceRotation_0;
		Spec.PerFaceComonRightAngleTexturePositions.FaceRotations [ 2 ] = CubeTexturePositionSpec::CommonFaceRightAngleTexturePositions :: kRightFaceRotation_0;
		Spec.PerFaceComonRightAngleTexturePositions.FaceRotations [ 3 ] = CubeTexturePositionSpec::CommonFaceRightAngleTexturePositions :: kRightFaceRotation_0;
		Spec.PerFaceComonRightAngleTexturePositions.FaceRotations [ 4 ] = CubeTexturePositionSpec::CommonFaceRightAngleTexturePositions :: kRightFaceRotation_0;
		Spec.PerFaceComonRightAngleTexturePositions.FaceRotations [ 5 ] = CubeTexturePositionSpec::CommonFaceRightAngleTexturePositions :: kRightFaceRotation_0;
		
	}
	else
	{
		
		Spec.PerFaceComonRightAngleTexturePositions.FaceRotations [ 0 ] = FaceRotations [ 0 ];
		Spec.PerFaceComonRightAngleTexturePositions.FaceRotations [ 1 ] = FaceRotations [ 1 ];
		Spec.PerFaceComonRightAngleTexturePositions.FaceRotations [ 2 ] = FaceRotations [ 2 ];
		Spec.PerFaceComonRightAngleTexturePositions.FaceRotations [ 3 ] = FaceRotations [ 3 ];
		Spec.PerFaceComonRightAngleTexturePositions.FaceRotations [ 4 ] = FaceRotations [ 4 ];
		Spec.PerFaceComonRightAngleTexturePositions.FaceRotations [ 5 ] = FaceRotations [ 5 ];
		
	}
	
}

bool Xenon::Geometry::Primitives :: GenerateCubeMesh ( Mesh ** Target, const CubeSpec & Spec )
{
	
	* Target = NULL;
	
	bool CommonVertexMode = true;
	
	uint32_t AttributeCount = 0;
	uint32_t AttributeDataCount = 0;
	
	if ( Spec.Attributes & kAttributeFlags_Position )
	{
		
		AttributeCount ++;
		
		CommonVertexMode = Spec.PositionSpec.NonClosed ? false : CommonVertexMode;
		
	}
	
	if ( Spec.Attributes & kAttributeFlags_Normal )
	{
		
		AttributeCount ++;
		
		CommonVertexMode = ( Spec.NormalSpec.Layout != CubeNormalSpec :: kNormalLayout_CommonVertex ) ? false : CommonVertexMode;
		
	}
	
	if ( Spec.Attributes & kAttributeFlags_Tangent )
	{
		
		AttributeCount ++;
		
		CommonVertexMode = ( Spec.TangentSpec.Layout != CubeTangentSpec :: kTangentLayout_CommonVertex ) ? false : CommonVertexMode;
		
	}
	
	if ( Spec.Attributes & kAttributeFlags_Color )
	{
		
		AttributeCount ++;
		
		CommonVertexMode = ( Spec.ColorSpec.Layout != CubeColorSpec :: kColorLayout_CommonVertex ) ? false : CommonVertexMode;
		
	}
	
	if ( Spec.Attributes & kAttributeFlags_TexturePositions )
	{
		
		AttributeCount += Spec.TexturePositionCount;
		
		for ( uint32_t I = 0; I < Spec.TexturePositionCount; I ++ )
			CommonVertexMode = ( ( Spec.TexturePositionSpecs [ I ].Layout != CubeTexturePositionSpec :: kTexturePositionLayout_PerCommonVertex ) && ( Spec.TexturePositionSpecs [ I ].Layout != CubeTexturePositionSpec :: kTexturePositionLayout_PerCommonVertexCubeTexture ) ) ? false : CommonVertexMode;
		
	}
	
	typedef struct AttributeGenTracker_Struct
	{
		
		inline AttributeGenTracker_Struct ():
		Attribute ( NULL )
		{
		};
		
		size_t Offset;
		size_t Stride;
		
		MeshAttribute * Attribute;
		
	} AttributeGenTracker;
	
	if ( AttributeCount > 40 ) // Something obviously went wrong, we shouldn't have more than 100 attributes.
		return NULL;
	
	AttributeGenTracker AttributeTrackers [ 40 ];
	
	uint32_t AttributeTrackerIndex;
	
	
	AttributeTrackerIndex = 0;
	
	size_t CommonStaticBufferAttributeStride = 0;
	size_t CommonStaticBufferAttributeTotal = 0;
	
	if ( Spec.Attributes & kAttributeFlags_Position )
	{
		
		AttributeTrackers [ AttributeTrackerIndex ].Offset = ( Spec.PositionSpec.Static && ( Spec.CompositionMode == kStaticAttributeCompositionMode_Interleaved ) ) ? CommonStaticBufferAttributeStride : 0;
		AttributeTrackerIndex ++;
		
		if ( Spec.PositionSpec.Static )
		{
			
			CommonStaticBufferAttributeTotal += sizeof ( GLfloat ) * 3 * ( CommonVertexMode ? 8 : 24 );
			CommonStaticBufferAttributeStride += sizeof ( GLfloat ) * 3;
			
		}
		else
			AttributeDataCount ++;
		
	}
	
	if ( Spec.Attributes & kAttributeFlags_Normal )
	{
		
		AttributeTrackers [ AttributeTrackerIndex ].Offset = ( Spec.NormalSpec.Static && ( Spec.CompositionMode == kStaticAttributeCompositionMode_Interleaved ) ) ? CommonStaticBufferAttributeStride : 0;
		
		AttributeTrackerIndex ++;
		
		if ( Spec.NormalSpec.Static )
		{
			
			CommonStaticBufferAttributeTotal += sizeof ( GLfloat ) * 3 * ( CommonVertexMode ? 8 : 24 );
			CommonStaticBufferAttributeStride += sizeof ( GLfloat ) * 3;
			
		}
		else
			AttributeDataCount ++;
		
	}
	
	if ( Spec.Attributes & kAttributeFlags_Tangent )
	{
		
		AttributeTrackers [ AttributeTrackerIndex ].Offset = ( Spec.TangentSpec.Static && ( Spec.CompositionMode == kStaticAttributeCompositionMode_Interleaved ) ) ? CommonStaticBufferAttributeStride : 0;
		
		AttributeTrackerIndex ++;
		
		if ( Spec.TangentSpec.Static )
		{
			
			CommonStaticBufferAttributeTotal += sizeof ( GLfloat ) * 3 * ( CommonVertexMode ? 8 : 24 );
			CommonStaticBufferAttributeStride += sizeof ( GLfloat ) * 3;
			
		}
		else
			AttributeDataCount ++;
		
	}
	
	if ( Spec.Attributes & kAttributeFlags_Color )
	{
		
		AttributeTrackers [ AttributeTrackerIndex ].Offset = ( Spec.ColorSpec.Static && ( Spec.CompositionMode == kStaticAttributeCompositionMode_Interleaved ) ) ? CommonStaticBufferAttributeStride : 0;
		
		AttributeTrackerIndex ++;
		
		if ( Spec.ColorSpec.Static )
		{
			
			CommonStaticBufferAttributeTotal += sizeof ( GLfloat ) * 3 * ( CommonVertexMode ? 8 : 24 );
			CommonStaticBufferAttributeStride += sizeof ( GLfloat ) * 3;
			
		}
		else
			AttributeDataCount ++;
		
	}
	
	if ( Spec.Attributes & kAttributeFlags_TexturePositions )
	{
		
		for ( uint32_t I = 0; I < Spec.TexturePositionCount; I ++ )
		{
			
			AttributeTrackers [ AttributeTrackerIndex ].Offset = ( Spec.TexturePositionSpecs [ I ].Static && ( Spec.CompositionMode == kStaticAttributeCompositionMode_Interleaved ) ) ? CommonStaticBufferAttributeStride : 0;
			
			AttributeTrackerIndex ++;
			
			if ( Spec.TexturePositionSpecs [ I ].Static )
			{
				
				CommonStaticBufferAttributeTotal += sizeof ( GLfloat ) * ( ( Spec.TexturePositionSpecs [ I ].Layout != CubeTexturePositionSpec :: kTexturePositionLayout_PerCommonVertexCubeTexture ) ? 2 : 3 ) * ( CommonVertexMode ? 8 : 24 );
				CommonStaticBufferAttributeStride += sizeof ( GLfloat ) * ( ( Spec.TexturePositionSpecs [ I ].Layout != CubeTexturePositionSpec :: kTexturePositionLayout_PerCommonVertexCubeTexture ) ? 2 : 3 );
				
			}
			else
				AttributeDataCount ++;
			
		}
		
	}
	
	if ( Spec.CompositionMode == kStaticAttributeCompositionMode_Interleaved )
	{
		
		AttributeTrackerIndex = 0;
		
		if ( Spec.Attributes & kAttributeFlags_Position )
		{
			
			AttributeTrackers [ AttributeTrackerIndex ].Stride = Spec.PositionSpec.Static ? CommonStaticBufferAttributeStride : 3 * sizeof ( GLfloat );
			
			AttributeTrackerIndex ++;
			
		}
		
		if ( Spec.Attributes & kAttributeFlags_Normal )
		{
			
			AttributeTrackers [ AttributeTrackerIndex ].Stride = Spec.NormalSpec.Static ? CommonStaticBufferAttributeStride : 3 * sizeof ( GLfloat );
			
			AttributeTrackerIndex ++;
			
		}
		
		if ( Spec.Attributes & kAttributeFlags_Tangent )
		{
			
			AttributeTrackers [ AttributeTrackerIndex ].Stride = Spec.TangentSpec.Static ? CommonStaticBufferAttributeStride : 3 * sizeof ( GLfloat );
			
			AttributeTrackerIndex ++;
			
		}
		
		if ( Spec.Attributes & kAttributeFlags_Color )
		{
			
			AttributeTrackers [ AttributeTrackerIndex ].Stride = Spec.ColorSpec.Static ? CommonStaticBufferAttributeStride : 3 * sizeof ( GLfloat );
			
			AttributeTrackerIndex ++;
			
		}
		
		if ( Spec.Attributes & kAttributeFlags_TexturePositions )
		{
			
			for ( uint32_t I = 0; I < Spec.TexturePositionCount; I ++ )
			{
				
				AttributeTrackers [ AttributeTrackerIndex ].Stride = Spec.TexturePositionSpecs [ I ].Static ? CommonStaticBufferAttributeStride : ( Spec.TexturePositionSpecs [ I ].Layout == CubeTexturePositionSpec :: kTexturePositionLayout_PerCommonVertexCubeTexture ) ? 3 * sizeof ( GLfloat ) : 2 * sizeof ( GLfloat );
				
				AttributeTrackerIndex ++;
				
			}
			
		}
		
	}
	else
	{
		
		AttributeTrackerIndex = 0;
		
		if ( Spec.Attributes & kAttributeFlags_Position )
		{
			
			AttributeTrackers [ AttributeTrackerIndex ].Stride = 3 * sizeof ( GLfloat );
			
			AttributeTrackerIndex ++;
			
		}
		
		if ( Spec.Attributes & kAttributeFlags_Normal )
		{
			
			AttributeTrackers [ AttributeTrackerIndex ].Stride = 3 * sizeof ( GLfloat );
			
			AttributeTrackerIndex ++;
			
		}
		
		if ( Spec.Attributes & kAttributeFlags_Tangent )
		{
			
			AttributeTrackers [ AttributeTrackerIndex ].Stride = 3 * sizeof ( GLfloat );
			
			AttributeTrackerIndex ++;
			
		}
		
		if ( Spec.Attributes & kAttributeFlags_Color )
		{
			
			AttributeTrackers [ AttributeTrackerIndex ].Stride = 3 * sizeof ( GLfloat );
			
			AttributeTrackerIndex ++;
			
		}
		
		if ( Spec.Attributes & kAttributeFlags_TexturePositions )
		{
			
			for ( uint32_t I = 0; I < Spec.TexturePositionCount; I ++ )
			{
				
				AttributeTrackers [ AttributeTrackerIndex ].Stride = ( Spec.TexturePositionSpecs [ I ].Layout == CubeTexturePositionSpec :: kTexturePositionLayout_PerCommonVertexCubeTexture ) ? 3 * sizeof ( GLfloat ) : 2 * sizeof ( GLfloat );
				
				AttributeTrackerIndex ++;
				
			}
			
		}
		
	}
	
	if ( CommonStaticBufferAttributeTotal != 0 )
		AttributeDataCount ++;
	
	if ( AttributeDataCount > 40 )
		return NULL;
	
	uint32_t AttributeDataIndex = 0;
	MeshAttributeData * AttributeDataList [ 40 ];
	
	Util :: RCMem * StaticDataBuffer = ( CommonStaticBufferAttributeTotal != 0 ) ? new Util :: RCMem ( CommonStaticBufferAttributeTotal ) : NULL;
	void * StaticData = ( CommonStaticBufferAttributeTotal != 0 ) ? StaticDataBuffer -> GetData () : NULL;
	
	MeshAttributeData * StaticAttributeData = ( CommonStaticBufferAttributeTotal != 0 ) ? new MeshAttributeData ( StaticDataBuffer, CommonStaticBufferAttributeTotal, GPU::VertexBuffer :: kUsageType_Static_Draw, false ) : NULL;
	
	if ( ( CommonStaticBufferAttributeTotal != 0 ) )
	{
		
		AttributeDataList [ AttributeDataIndex ] = StaticAttributeData;
		AttributeDataIndex ++;
		
		if ( StaticData == NULL )
		{
			
			delete StaticDataBuffer;
			
			return false;
			
		}
		
	}
	
	AttributeTrackerIndex = 0;
	
	if ( Spec.Attributes & kAttributeFlags_Position )
	{
		
		void * PositionData;
		size_t PositionOffset = AttributeTrackers [ AttributeTrackerIndex ].Offset;
		size_t PositionStride = AttributeTrackers [ AttributeTrackerIndex ].Stride;
		
		if ( Spec.PositionSpec.Static && ( Spec.CompositionMode != kStaticAttributeCompositionMode_SeperateBuffers ) )
		{
			
			PositionData = StaticData;
			
			AttributeTrackers [ AttributeTrackerIndex ].Attribute = new MeshAttribute ( Spec.PositionSpec.AttributeName, GPU::VertexArray :: kFPAttributeInputType_Float, false, 3, PositionStride, reinterpret_cast <void *> ( PositionOffset ), StaticAttributeData );
			AttributeTrackerIndex ++;
			
		}
		else
		{
			
			Util :: RCMem * PositionDataBuffer = new Util :: RCMem ( sizeof ( GLfloat ) * 3 * ( CommonVertexMode ? 8 : 24 ) );
			PositionData = PositionDataBuffer -> GetData ();
			
			MeshAttributeData * PositionAttributeData =  new MeshAttributeData ( PositionDataBuffer, sizeof ( GLfloat ) * 3 * ( CommonVertexMode ? 8 : 24 ), Spec.ColorSpec.Static ? GPU::VertexBuffer :: kUsageType_Static_Draw : GPU::VertexBuffer :: kUsageType_Dynamic_Draw, true );
			
			AttributeDataList [ AttributeDataIndex ] = PositionAttributeData;
			AttributeDataIndex ++;
			
			if ( PositionData == NULL )
			{
				
				delete StaticDataBuffer;
				delete PositionDataBuffer;
				
				return false;
				
			}
			
			AttributeTrackers [ AttributeTrackerIndex ].Attribute = new MeshAttribute ( Spec.PositionSpec.AttributeName, GPU::VertexArray :: kFPAttributeInputType_Float, false, 3, PositionStride, reinterpret_cast <void *> ( PositionOffset ), PositionAttributeData );
			AttributeTrackerIndex ++;
			
		}
		
		
		Math :: Vec3 Temp ( Math::Vec3 :: NO_INIT );
		
		if ( CommonVertexMode )
		{
			
			Math::Vec3 :: Set ( Temp, - 1.0f, - 1.0f, - 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * kCubeVertexPositionIndex_ZNeg_XNeg_YNeg ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, - 1.0f, - 1.0f, + 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * kCubeVertexPositionIndex_ZPos_XNeg_YNeg ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, - 1.0f, + 1.0f, - 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * kCubeVertexPositionIndex_ZNeg_XNeg_YPos ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, - 1.0f, + 1.0f, + 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * kCubeVertexPositionIndex_ZPos_XNeg_YPos ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, + 1.0f, - 1.0f, - 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * kCubeVertexPositionIndex_ZNeg_XPos_YNeg ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, + 1.0f, - 1.0f, + 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * kCubeVertexPositionIndex_ZPos_XPos_YNeg ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, + 1.0f, + 1.0f, - 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * kCubeVertexPositionIndex_ZNeg_XPos_YPos ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, + 1.0f, + 1.0f, + 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * kCubeVertexPositionIndex_ZPos_XPos_YPos ) ), Temp );
			
		}
		else
		{
			
			Math::Vec3 :: Set ( Temp, + 1.0f, - 1.0f, + 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			if ( Spec.PositionSpec.NonClosed )
				Temp.Z += Spec.PositionSpec.BlowUp.Z;
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * ( kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, + 1.0f, + 1.0f, + 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			if ( Spec.PositionSpec.NonClosed )
				Temp.Z += Spec.PositionSpec.BlowUp.Z;
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * ( kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, - 1.0f, + 1.0f, + 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			if ( Spec.PositionSpec.NonClosed )
				Temp.Z += Spec.PositionSpec.BlowUp.Z;
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * ( kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, - 1.0f, - 1.0f, + 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			if ( Spec.PositionSpec.NonClosed )
				Temp.Z += Spec.PositionSpec.BlowUp.Z;
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * ( kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, - 1.0f, - 1.0f, - 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			if ( Spec.PositionSpec.NonClosed )
				Temp.Z -= Spec.PositionSpec.BlowUp.Z;
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * ( kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, - 1.0f, + 1.0f, - 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			if ( Spec.PositionSpec.NonClosed )
				Temp.Z -= Spec.PositionSpec.BlowUp.Z;
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * ( kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, + 1.0f, + 1.0f, - 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			if ( Spec.PositionSpec.NonClosed )
				Temp.Z -= Spec.PositionSpec.BlowUp.Z;
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * ( kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, + 1.0f, - 1.0f, - 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			if ( Spec.PositionSpec.NonClosed )
				Temp.Z -= Spec.PositionSpec.BlowUp.Z;
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * ( kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, - 1.0f, + 1.0f, - 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			if ( Spec.PositionSpec.NonClosed )
				Temp.Y += Spec.PositionSpec.BlowUp.Y;
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * ( kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, - 1.0f, + 1.0f, + 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			if ( Spec.PositionSpec.NonClosed )
				Temp.Y += Spec.PositionSpec.BlowUp.Y;
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * ( kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, + 1.0f, + 1.0f, + 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			if ( Spec.PositionSpec.NonClosed )
				Temp.Y += Spec.PositionSpec.BlowUp.Y;
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * ( kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, + 1.0f, + 1.0f, - 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			if ( Spec.PositionSpec.NonClosed )
				Temp.Y += Spec.PositionSpec.BlowUp.Y;
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * ( kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, + 1.0f, - 1.0f, - 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			if ( Spec.PositionSpec.NonClosed )
				Temp.Y -= Spec.PositionSpec.BlowUp.Y;
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * ( kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, + 1.0f, - 1.0f, + 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			if ( Spec.PositionSpec.NonClosed )
				Temp.Y -= Spec.PositionSpec.BlowUp.Y;
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * ( kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, - 1.0f, - 1.0f, + 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			if ( Spec.PositionSpec.NonClosed )
				Temp.Y -= Spec.PositionSpec.BlowUp.Y;
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * ( kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, - 1.0f, - 1.0f, - 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			if ( Spec.PositionSpec.NonClosed )
				Temp.Y -= Spec.PositionSpec.BlowUp.Y;
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * ( kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, + 1.0f, - 1.0f, - 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			if ( Spec.PositionSpec.NonClosed )
				Temp.X += Spec.PositionSpec.BlowUp.X;
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * ( kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, + 1.0f, + 1.0f, - 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			if ( Spec.PositionSpec.NonClosed )
				Temp.X += Spec.PositionSpec.BlowUp.X;
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * ( kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, + 1.0f, + 1.0f, + 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			if ( Spec.PositionSpec.NonClosed )
				Temp.X += Spec.PositionSpec.BlowUp.X;
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * ( kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, + 1.0f, - 1.0f, + 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			if ( Spec.PositionSpec.NonClosed )
				Temp.X += Spec.PositionSpec.BlowUp.X;
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * ( kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, - 1.0f, - 1.0f, + 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			if ( Spec.PositionSpec.NonClosed )
				Temp.X -= Spec.PositionSpec.BlowUp.X;
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * ( kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, - 1.0f, + 1.0f, + 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			if ( Spec.PositionSpec.NonClosed )
				Temp.X -= Spec.PositionSpec.BlowUp.X;
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * ( kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, - 1.0f, + 1.0f, - 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			if ( Spec.PositionSpec.NonClosed )
				Temp.X -= Spec.PositionSpec.BlowUp.X;
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * ( kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Temp );
			
			Math::Vec3 :: Set ( Temp, - 1.0f, - 1.0f, - 1.0f );
			Math::Vec3 :: Scale ( Temp, Spec.PositionSpec.Scale );
			Math::Vec3 :: Add ( Temp, Spec.PositionSpec.Offset );
			if ( Spec.PositionSpec.NonClosed )
				Temp.X -= Spec.PositionSpec.BlowUp.X;
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * ( kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Temp );
			
		}
		
	}
	
	if ( Spec.Attributes & kAttributeFlags_Normal )
	{
		
		void * NormalData;
		size_t NormalOffset = AttributeTrackers [ AttributeTrackerIndex ].Offset;
		size_t NormalStride = AttributeTrackers [ AttributeTrackerIndex ].Stride;
		
		if ( Spec.NormalSpec.Static && ( Spec.CompositionMode != kStaticAttributeCompositionMode_SeperateBuffers ) )
		{
			
			NormalData = StaticData;
			
			AttributeTrackers [ AttributeTrackerIndex ].Attribute = new MeshAttribute ( Spec.NormalSpec.AttributeName, GPU::VertexArray :: kFPAttributeInputType_Float, false, 3, NormalStride, reinterpret_cast <void *> ( NormalOffset ), StaticAttributeData );
			AttributeTrackerIndex ++;
			
		}
		else
		{
			
			Util :: RCMem * NormalDataBuffer = new Util :: RCMem ( sizeof ( GLfloat ) * 3 * ( CommonVertexMode ? 8 : 24 ) );
			NormalData = NormalDataBuffer -> GetData ();
			
			MeshAttributeData * NormalAttributeData =  new MeshAttributeData ( NormalDataBuffer, sizeof ( GLfloat ) * 3 * ( CommonVertexMode ? 8 : 24 ), Spec.ColorSpec.Static ? GPU::VertexBuffer :: kUsageType_Static_Draw : GPU::VertexBuffer :: kUsageType_Dynamic_Draw, true );
			
			AttributeDataList [ AttributeDataIndex ] = NormalAttributeData;
			AttributeDataIndex ++;
			
			if ( NormalData == NULL )
			{
				
				delete StaticDataBuffer;
				delete NormalDataBuffer;
				
				return false;
				
			}
			
			AttributeTrackers [ AttributeTrackerIndex ].Attribute = new MeshAttribute ( Spec.NormalSpec.AttributeName, GPU::VertexArray :: kFPAttributeInputType_Float, false, 3, NormalStride, reinterpret_cast <void *> ( NormalOffset ), NormalAttributeData );
			AttributeTrackerIndex ++;
			
		}
		
		Math :: Vec3 Temp ( Math::Vec3 :: NO_INIT );
		
		if ( CommonVertexMode )
		{
			
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * kCubeVertexPositionIndex_ZPos_XPos_YPos ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZPos_XPos_YPos ] );
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * kCubeVertexPositionIndex_ZPos_XNeg_YPos ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZPos_XNeg_YPos ] );
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * kCubeVertexPositionIndex_ZPos_XPos_YNeg ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZPos_XPos_YNeg ] );
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * kCubeVertexPositionIndex_ZPos_XNeg_YNeg ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZPos_XNeg_YNeg ] );
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * kCubeVertexPositionIndex_ZNeg_XPos_YPos ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZNeg_XPos_YPos ] );
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * kCubeVertexPositionIndex_ZNeg_XNeg_YPos ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZNeg_XNeg_YPos ] );
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * kCubeVertexPositionIndex_ZNeg_XPos_YNeg ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZNeg_XPos_YNeg ] );
			Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * kCubeVertexPositionIndex_ZNeg_XNeg_YNeg ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZNeg_XNeg_YNeg ] );
			
		}
		else
		{
			
			if ( Spec.NormalSpec.Layout == CubeNormalSpec :: kNormalLayout_Face )
			{
				
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Spec.NormalSpec.FaceNormals [ kCubeFaceIndex_XNeg ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Spec.NormalSpec.FaceNormals [ kCubeFaceIndex_XNeg ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Spec.NormalSpec.FaceNormals [ kCubeFaceIndex_XNeg ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Spec.NormalSpec.FaceNormals [ kCubeFaceIndex_XNeg ] );
				
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Spec.NormalSpec.FaceNormals [ kCubeFaceIndex_XPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Spec.NormalSpec.FaceNormals [ kCubeFaceIndex_XPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Spec.NormalSpec.FaceNormals [ kCubeFaceIndex_XPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Spec.NormalSpec.FaceNormals [ kCubeFaceIndex_XPos ] );
				
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Spec.NormalSpec.FaceNormals [ kCubeFaceIndex_YNeg ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Spec.NormalSpec.FaceNormals [ kCubeFaceIndex_YNeg ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Spec.NormalSpec.FaceNormals [ kCubeFaceIndex_YNeg ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Spec.NormalSpec.FaceNormals [ kCubeFaceIndex_YNeg ] );
				
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Spec.NormalSpec.FaceNormals [ kCubeFaceIndex_YPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Spec.NormalSpec.FaceNormals [ kCubeFaceIndex_YPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Spec.NormalSpec.FaceNormals [ kCubeFaceIndex_YPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Spec.NormalSpec.FaceNormals [ kCubeFaceIndex_YPos ] );
				
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Spec.NormalSpec.FaceNormals [ kCubeFaceIndex_ZNeg ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Spec.NormalSpec.FaceNormals [ kCubeFaceIndex_ZNeg ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Spec.NormalSpec.FaceNormals [ kCubeFaceIndex_ZNeg ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Spec.NormalSpec.FaceNormals [ kCubeFaceIndex_ZNeg ] );
				
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Spec.NormalSpec.FaceNormals [ kCubeFaceIndex_ZPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Spec.NormalSpec.FaceNormals [ kCubeFaceIndex_ZPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Spec.NormalSpec.FaceNormals [ kCubeFaceIndex_ZPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Spec.NormalSpec.FaceNormals [ kCubeFaceIndex_ZPos ] );
				
			}
			else if ( Spec.NormalSpec.Layout == CubeNormalSpec :: kNormalLayout_FaceVertex )
			{
				
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Spec.NormalSpec.FaceVertexNormals [ kCubeFaceIndex_XNeg ] [ kCubeFaceVertexIndex_XNeg_YNeg ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Spec.NormalSpec.FaceVertexNormals [ kCubeFaceIndex_XNeg ] [ kCubeFaceVertexIndex_XNeg_YPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Spec.NormalSpec.FaceVertexNormals [ kCubeFaceIndex_XNeg ] [ kCubeFaceVertexIndex_XPos_YPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Spec.NormalSpec.FaceVertexNormals [ kCubeFaceIndex_XNeg ] [ kCubeFaceVertexIndex_XPos_YNeg ] );
				
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Spec.NormalSpec.FaceVertexNormals [ kCubeFaceIndex_XPos ] [ kCubeFaceVertexIndex_XNeg_YNeg ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Spec.NormalSpec.FaceVertexNormals [ kCubeFaceIndex_XPos ] [ kCubeFaceVertexIndex_XNeg_YPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Spec.NormalSpec.FaceVertexNormals [ kCubeFaceIndex_XPos ] [ kCubeFaceVertexIndex_XPos_YPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Spec.NormalSpec.FaceVertexNormals [ kCubeFaceIndex_XPos ] [ kCubeFaceVertexIndex_XPos_YNeg ] );
				
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Spec.NormalSpec.FaceVertexNormals [ kCubeFaceIndex_YNeg ] [ kCubeFaceVertexIndex_XNeg_YNeg ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Spec.NormalSpec.FaceVertexNormals [ kCubeFaceIndex_YNeg ] [ kCubeFaceVertexIndex_XNeg_YPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Spec.NormalSpec.FaceVertexNormals [ kCubeFaceIndex_YNeg ] [ kCubeFaceVertexIndex_XPos_YPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Spec.NormalSpec.FaceVertexNormals [ kCubeFaceIndex_YNeg ] [ kCubeFaceVertexIndex_XPos_YNeg ] );
				
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Spec.NormalSpec.FaceVertexNormals [ kCubeFaceIndex_YPos ] [ kCubeFaceVertexIndex_XNeg_YNeg ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Spec.NormalSpec.FaceVertexNormals [ kCubeFaceIndex_YPos ] [ kCubeFaceVertexIndex_XNeg_YPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Spec.NormalSpec.FaceVertexNormals [ kCubeFaceIndex_YPos ] [ kCubeFaceVertexIndex_XPos_YPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Spec.NormalSpec.FaceVertexNormals [ kCubeFaceIndex_YPos ] [ kCubeFaceVertexIndex_XPos_YNeg ] );
				
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Spec.NormalSpec.FaceVertexNormals [ kCubeFaceIndex_ZNeg ] [ kCubeFaceVertexIndex_XNeg_YNeg ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Spec.NormalSpec.FaceVertexNormals [ kCubeFaceIndex_ZNeg ] [ kCubeFaceVertexIndex_XNeg_YPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Spec.NormalSpec.FaceVertexNormals [ kCubeFaceIndex_ZNeg ] [ kCubeFaceVertexIndex_XPos_YPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Spec.NormalSpec.FaceVertexNormals [ kCubeFaceIndex_ZNeg ] [ kCubeFaceVertexIndex_XPos_YNeg ] );
				
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Spec.NormalSpec.FaceVertexNormals [ kCubeFaceIndex_ZPos ] [ kCubeFaceVertexIndex_XNeg_YNeg ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Spec.NormalSpec.FaceVertexNormals [ kCubeFaceIndex_ZPos ] [ kCubeFaceVertexIndex_XNeg_YPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Spec.NormalSpec.FaceVertexNormals [ kCubeFaceIndex_ZPos ] [ kCubeFaceVertexIndex_XPos_YPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Spec.NormalSpec.FaceVertexNormals [ kCubeFaceIndex_ZPos ] [ kCubeFaceVertexIndex_XPos_YNeg ] );
				
			}
			else
			{
				
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZPos_XPos_YNeg ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZPos_XPos_YNeg ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZPos_XNeg_YPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZPos_XNeg_YNeg ] );
				
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZNeg_XNeg_YNeg ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZNeg_XNeg_YPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZNeg_XPos_YPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZNeg_XPos_YNeg ] );
				
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZNeg_XNeg_YPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZPos_XNeg_YPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZPos_XPos_YPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZNeg_XPos_YPos ] );
				
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZNeg_XPos_YNeg ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZPos_XPos_YNeg ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZPos_XNeg_YNeg ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZNeg_XNeg_YNeg ] );
				
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZNeg_XPos_YNeg ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZNeg_XPos_YPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZPos_XPos_YPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZPos_XPos_YNeg ] );
				
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZPos_XNeg_YNeg ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZPos_XNeg_YPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZNeg_XNeg_YPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( NormalData ) + ( NormalOffset + NormalStride * ( kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Spec.NormalSpec.CommonVertexNormals [ kCubeVertexPositionIndex_ZNeg_XNeg_YNeg ] );
				
			}
			
		}
		
	}
	
	if ( Spec.Attributes & kAttributeFlags_Tangent )
	{
		
		void * TangentData;
		size_t TangentOffset = AttributeTrackers [ AttributeTrackerIndex ].Offset;
		size_t TangentStride = AttributeTrackers [ AttributeTrackerIndex ].Stride;
		
		if ( Spec.TangentSpec.Static && ( Spec.CompositionMode != kStaticAttributeCompositionMode_SeperateBuffers ) )
		{
			
			TangentData = StaticData;
			
			AttributeTrackers [ AttributeTrackerIndex ].Attribute = new MeshAttribute ( Spec.TangentSpec.AttributeName, GPU::VertexArray :: kFPAttributeInputType_Float, false, 3, TangentStride, reinterpret_cast <void *> ( TangentOffset ), StaticAttributeData );
			AttributeTrackerIndex ++;
			
		}
		else
		{
			
			Util :: RCMem * TangentDataBuffer = new Util :: RCMem ( sizeof ( GLfloat ) * 3 * ( CommonVertexMode ? 8 : 24 ) );
			TangentData = TangentDataBuffer -> GetData ();
			
			MeshAttributeData * TangentAttributeData =  new MeshAttributeData ( TangentDataBuffer, sizeof ( GLfloat ) * 3 * ( CommonVertexMode ? 8 : 24 ), Spec.ColorSpec.Static ? GPU::VertexBuffer :: kUsageType_Static_Draw : GPU::VertexBuffer :: kUsageType_Dynamic_Draw, true );
			
			AttributeDataList [ AttributeDataIndex ] = TangentAttributeData;
			AttributeDataIndex ++;
			
			if ( TangentData == NULL )
			{
				
				delete StaticDataBuffer;
				delete TangentDataBuffer;
				
				return false;
				
			}
			
			AttributeTrackers [ AttributeTrackerIndex ].Attribute = new MeshAttribute ( Spec.TangentSpec.AttributeName, GPU::VertexArray :: kFPAttributeInputType_Float, false, 3, TangentStride, reinterpret_cast <void *> ( TangentOffset ), TangentAttributeData );
			AttributeTrackerIndex ++;
			
		}
		
		// TODO: Fill in data
		
	}
	
	if ( Spec.Attributes & kAttributeFlags_Color )
	{
		
		void * ColorData;
		size_t ColorOffset = AttributeTrackers [ AttributeTrackerIndex ].Offset;
		size_t ColorStride = AttributeTrackers [ AttributeTrackerIndex ].Stride;
		
		if ( Spec.ColorSpec.Static && ( Spec.CompositionMode != kStaticAttributeCompositionMode_SeperateBuffers ) )
		{
			
			ColorData = StaticData;
			
			AttributeTrackers [ AttributeTrackerIndex ].Attribute = new MeshAttribute ( Spec.ColorSpec.AttributeName, GPU::VertexArray :: kFPAttributeInputType_Float, false, 3, ColorStride, reinterpret_cast <void *> ( ColorOffset ), StaticAttributeData );
			AttributeTrackerIndex ++;
			
		}
		else
		{
			
			Util :: RCMem * ColorDataBuffer = new Util :: RCMem ( sizeof ( GLfloat ) * 3 * ( CommonVertexMode ? 8 : 24 ) );
			ColorData = ColorDataBuffer -> GetData ();
			
			MeshAttributeData * ColorAttributeData =  new MeshAttributeData ( ColorDataBuffer, sizeof ( GLfloat ) * 3 * ( CommonVertexMode ? 8 : 24 ), Spec.ColorSpec.Static ? GPU::VertexBuffer :: kUsageType_Static_Draw : GPU::VertexBuffer :: kUsageType_Dynamic_Draw, true );
			
			AttributeDataList [ AttributeDataIndex ] = ColorAttributeData;
			AttributeDataIndex ++;
			
			if ( ColorData == NULL )
			{
				
				delete StaticDataBuffer;
				delete ColorDataBuffer;
				
				return false;
				
			}
			
			AttributeTrackers [ AttributeTrackerIndex ].Attribute = new MeshAttribute ( Spec.ColorSpec.AttributeName, GPU::VertexArray :: kFPAttributeInputType_Float, false, 3, ColorStride, reinterpret_cast <void *> ( ColorOffset ), ColorAttributeData );
			AttributeTrackerIndex ++;
			
		}
		
		// TODO: Fill in data
		
	}
	
	if ( Spec.Attributes & kAttributeFlags_TexturePositions )
	{
		
		AttributeCount += Spec.TexturePositionCount;
		
		for ( uint32_t I = 0; I < Spec.TexturePositionCount; I ++ )
		{
			
			void * TexturePositionData;
			size_t TexturePositionOffset = AttributeTrackers [ AttributeTrackerIndex ].Offset;
			size_t TexturePositionStride = AttributeTrackers [ AttributeTrackerIndex ].Stride;
			
			if ( Spec.TexturePositionSpecs [ I ].Static && ( Spec.CompositionMode != kStaticAttributeCompositionMode_SeperateBuffers ) )
			{
				
				TexturePositionData = StaticData;
				
				AttributeTrackers [ AttributeTrackerIndex ].Attribute = new MeshAttribute ( Spec.TexturePositionSpecs [ I ].AttributeName, GPU::VertexArray :: kFPAttributeInputType_Float, false, ( Spec.TexturePositionSpecs [ I ].Layout == CubeTexturePositionSpec :: kTexturePositionLayout_PerCommonVertexCubeTexture ) ? 3 : 2, TexturePositionStride, reinterpret_cast <void *> ( TexturePositionOffset ), StaticAttributeData );
				AttributeTrackerIndex ++;
				
			}
			else
			{
				
				Util :: RCMem * TexturePositionDataBuffer = new Util :: RCMem ( ( ( Spec.TexturePositionSpecs [ I ].Layout == CubeTexturePositionSpec :: kTexturePositionLayout_PerCommonVertexCubeTexture ) ? 3 * sizeof ( GLfloat ) : 2 * sizeof ( GLfloat ) ) * ( CommonVertexMode ? 8 : 24 ) );
				TexturePositionData = TexturePositionDataBuffer -> GetData ();
				
				MeshAttributeData * TexturePositionAttributeData =  new MeshAttributeData ( TexturePositionDataBuffer, ( ( Spec.TexturePositionSpecs [ I ].Layout == CubeTexturePositionSpec :: kTexturePositionLayout_PerCommonVertexCubeTexture ) ? 3 * sizeof ( GLfloat ) : 2 * sizeof ( GLfloat ) ) * ( CommonVertexMode ? 8 : 24 ), Spec.TexturePositionSpecs [ I ].Static ? GPU::VertexBuffer :: kUsageType_Static_Draw : GPU::VertexBuffer :: kUsageType_Dynamic_Draw, true );
				
				AttributeDataList [ AttributeDataIndex ] = TexturePositionAttributeData;
				AttributeDataIndex ++;
				
				if ( TexturePositionData == NULL )
				{
					
					delete StaticDataBuffer;
					delete TexturePositionDataBuffer;
					
					return false;
					
				}
				
				AttributeTrackers [ AttributeTrackerIndex ].Attribute = new MeshAttribute ( Spec.TexturePositionSpecs [ I ].AttributeName, GPU::VertexArray :: kFPAttributeInputType_Float, false, 3, TexturePositionStride, reinterpret_cast <void *> ( TexturePositionOffset ), TexturePositionAttributeData );
				AttributeTrackerIndex ++;
				
			}
			
			if ( CommonVertexMode )
			{
				
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * kCubeVertexPositionIndex_ZNeg_XNeg_YNeg ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZNeg_XNeg_YNeg ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * kCubeVertexPositionIndex_ZNeg_XPos_YNeg ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZNeg_XPos_YNeg ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * kCubeVertexPositionIndex_ZNeg_XNeg_YPos ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZNeg_XNeg_YPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * kCubeVertexPositionIndex_ZNeg_XPos_YPos ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZNeg_XPos_YPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * kCubeVertexPositionIndex_ZPos_XNeg_YNeg ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZPos_XNeg_YNeg ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * kCubeVertexPositionIndex_ZPos_XPos_YNeg ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZPos_XPos_YNeg ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * kCubeVertexPositionIndex_ZPos_XNeg_YPos ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZPos_XNeg_YPos ] );
				Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * kCubeVertexPositionIndex_ZPos_XPos_YPos ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZPos_XPos_YPos ] );
				
				
			}
			else
			{
			
				if ( Spec.TexturePositionSpecs [ I ].Layout == CubeTexturePositionSpec :: kTexturePositionLayout_PerCommonVertexCubeTexture )
				{
					
					Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * ( kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZPos_XPos_YNeg ] );
					Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * ( kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZPos_XPos_YNeg ] );
					Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * ( kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZPos_XNeg_YPos ] );
					Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * ( kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZPos_XNeg_YNeg ] );
					
					Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * ( kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZNeg_XNeg_YNeg ] );
					Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * ( kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZNeg_XNeg_YPos ] );
					Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * ( kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZNeg_XPos_YPos ] );
					Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * ( kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZNeg_XPos_YNeg ] );
					
					Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * ( kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZNeg_XNeg_YPos ] );
					Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * ( kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZPos_XNeg_YPos ] );
					Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * ( kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZPos_XPos_YPos ] );
					Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * ( kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZNeg_XPos_YPos ] );
					
					Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * ( kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZNeg_XPos_YNeg ] );
					Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * ( kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZPos_XPos_YNeg ] );
					Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * ( kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZPos_XNeg_YNeg ] );
					Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * ( kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZNeg_XNeg_YNeg ] );
					
					Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * ( kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZNeg_XPos_YNeg ] );
					Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * ( kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZNeg_XPos_YPos ] );
					Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * ( kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZPos_XPos_YPos ] );
					Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * ( kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZPos_XPos_YNeg ] );
					
					Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * ( kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg ) ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZPos_XNeg_YNeg ] );
					Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * ( kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos ) ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZPos_XNeg_YPos ] );
					Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * ( kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos ) ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZNeg_XNeg_YPos ] );
					Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * ( kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg ) ) ), Spec.TexturePositionSpecs [ I ].PerCommonVertexCubeTexturePositions [ kCubeVertexPositionIndex_ZNeg_XNeg_YNeg ] );
					
				}
				else
				{
					
					// TODO: Other Texture Position Layouts.
					
				}
				
			}
			
		}
		
	}
	
	// TODO: Other attributes
	
	Util :: RCMem * IndexDataBuffer = new Util :: RCMem ( sizeof ( GLubyte ) * 36 );
	GLubyte * IndexData = reinterpret_cast <GLubyte *> ( IndexDataBuffer -> GetData () );
	
	if ( ! CommonVertexMode )
	{
		
		if ( ! Spec.WindOutwardFacesClockwise )
		{
			
			IndexData [ 0 ] = kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg;
			IndexData [ 1 ] = kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos;
			IndexData [ 2 ] = kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos;
			IndexData [ 3 ] = kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos;
			IndexData [ 4 ] = kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg;
			IndexData [ 5 ] = kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg;
			
			IndexData [ 6 ] = kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg;
			IndexData [ 7 ] = kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos;
			IndexData [ 8 ] = kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos;
			IndexData [ 9 ] = kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos;
			IndexData [ 10 ] = kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg;
			IndexData [ 11 ] = kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg;
			
			IndexData [ 12 ] = kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg;
			IndexData [ 13 ] = kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos;
			IndexData [ 14 ] = kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos;
			IndexData [ 15 ] = kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos;
			IndexData [ 16 ] = kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg;
			IndexData [ 17 ] = kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg;
			
			IndexData [ 18 ] = kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg;
			IndexData [ 19 ] = kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos;
			IndexData [ 20 ] = kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos;
			IndexData [ 21 ] = kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos;
			IndexData [ 22 ] = kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg;
			IndexData [ 23 ] = kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg;
			
			IndexData [ 24 ] = kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg;
			IndexData [ 25 ] = kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos;
			IndexData [ 26 ] = kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos;
			IndexData [ 27 ] = kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos;
			IndexData [ 28 ] = kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg;
			IndexData [ 29 ] = kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg;
			
			IndexData [ 30 ] = kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg;
			IndexData [ 31 ] = kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos;
			IndexData [ 32 ] = kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos;
			IndexData [ 33 ] = kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos;
			IndexData [ 34 ] = kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg;
			IndexData [ 35 ] = kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg;
			
		}
		else
		{
			
			IndexData [ 0 ] = kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg;
			IndexData [ 2 ] = kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos;
			IndexData [ 1 ] = kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos;
			IndexData [ 3 ] = kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos;
			IndexData [ 5 ] = kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg;
			IndexData [ 4 ] = kCubeFaceIndex_ZPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg;
			
			IndexData [ 6 ] = kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg;
			IndexData [ 8 ] = kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos;
			IndexData [ 7 ] = kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos;
			IndexData [ 9 ] = kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos;
			IndexData [ 11 ] = kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg;
			IndexData [ 10 ] = kCubeFaceIndex_ZNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg;
			
			IndexData [ 12 ] = kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg;
			IndexData [ 14 ] = kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos;
			IndexData [ 13 ] = kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos;
			IndexData [ 15 ] = kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos;
			IndexData [ 17 ] = kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg;
			IndexData [ 16 ] = kCubeFaceIndex_YPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg;
			
			IndexData [ 18 ] = kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg;
			IndexData [ 20 ] = kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos;
			IndexData [ 19 ] = kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos;
			IndexData [ 21 ] = kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos;
			IndexData [ 23 ] = kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg;
			IndexData [ 22 ] = kCubeFaceIndex_YNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg;
			
			IndexData [ 24 ] = kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg;
			IndexData [ 26 ] = kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos;
			IndexData [ 25 ] = kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos;
			IndexData [ 27 ] = kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos;
			IndexData [ 29 ] = kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg;
			IndexData [ 28 ] = kCubeFaceIndex_XPos * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg;
			
			IndexData [ 30 ] = kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg;
			IndexData [ 32 ] = kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YPos;
			IndexData [ 31 ] = kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos;
			IndexData [ 33 ] = kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YPos;
			IndexData [ 35 ] = kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XPos_YNeg;
			IndexData [ 34 ] = kCubeFaceIndex_XNeg * kCubeFaceVertexIndex_Modulus + kCubeFaceVertexIndex_XNeg_YNeg;
			
		}
		
	}
	else
	{
		
		if ( ! Spec.WindOutwardFacesClockwise )
		{
			
			IndexData [ 0 ] = kCubeVertexPositionIndex_ZNeg_XNeg_YNeg;
			IndexData [ 1 ] = kCubeVertexPositionIndex_ZNeg_XNeg_YPos;
			IndexData [ 2 ] = kCubeVertexPositionIndex_ZNeg_XPos_YPos;
			IndexData [ 3 ] = kCubeVertexPositionIndex_ZNeg_XPos_YPos;
			IndexData [ 4 ] = kCubeVertexPositionIndex_ZNeg_XPos_YNeg;
			IndexData [ 5 ] = kCubeVertexPositionIndex_ZNeg_XNeg_YNeg;
			
			IndexData [ 6 ] = kCubeVertexPositionIndex_ZPos_XNeg_YPos;
			IndexData [ 7 ] = kCubeVertexPositionIndex_ZPos_XNeg_YNeg;
			IndexData [ 8 ] = kCubeVertexPositionIndex_ZPos_XPos_YNeg;
			IndexData [ 9 ] = kCubeVertexPositionIndex_ZPos_XPos_YNeg;
			IndexData [ 10 ] = kCubeVertexPositionIndex_ZPos_XPos_YPos;
			IndexData [ 11 ] = kCubeVertexPositionIndex_ZPos_XNeg_YPos;
			
			IndexData [ 12 ] = kCubeVertexPositionIndex_ZNeg_XNeg_YPos;
			IndexData [ 13 ] = kCubeVertexPositionIndex_ZPos_XNeg_YPos;
			IndexData [ 14 ] = kCubeVertexPositionIndex_ZPos_XPos_YPos;
			IndexData [ 15 ] = kCubeVertexPositionIndex_ZPos_XPos_YPos;
			IndexData [ 16 ] = kCubeVertexPositionIndex_ZNeg_XPos_YPos;
			IndexData [ 17 ] = kCubeVertexPositionIndex_ZNeg_XNeg_YPos;
			
			IndexData [ 18 ] = kCubeVertexPositionIndex_ZPos_XNeg_YNeg;
			IndexData [ 19 ] = kCubeVertexPositionIndex_ZNeg_XNeg_YNeg;
			IndexData [ 20 ] = kCubeVertexPositionIndex_ZNeg_XPos_YNeg;
			IndexData [ 21 ] = kCubeVertexPositionIndex_ZNeg_XPos_YNeg;
			IndexData [ 22 ] = kCubeVertexPositionIndex_ZPos_XPos_YNeg;
			IndexData [ 23 ] = kCubeVertexPositionIndex_ZPos_XNeg_YNeg;
			
			IndexData [ 24 ] = kCubeVertexPositionIndex_ZNeg_XPos_YNeg;
			IndexData [ 25 ] = kCubeVertexPositionIndex_ZNeg_XPos_YPos;
			IndexData [ 26 ] = kCubeVertexPositionIndex_ZPos_XPos_YPos;
			IndexData [ 27 ] = kCubeVertexPositionIndex_ZPos_XPos_YPos;
			IndexData [ 28 ] = kCubeVertexPositionIndex_ZPos_XPos_YNeg;
			IndexData [ 29 ] = kCubeVertexPositionIndex_ZNeg_XPos_YNeg;
			
			IndexData [ 30 ] = kCubeVertexPositionIndex_ZPos_XNeg_YNeg;
			IndexData [ 31 ] = kCubeVertexPositionIndex_ZPos_XNeg_YPos;
			IndexData [ 32 ] = kCubeVertexPositionIndex_ZNeg_XNeg_YPos;
			IndexData [ 33 ] = kCubeVertexPositionIndex_ZNeg_XNeg_YPos;
			IndexData [ 34 ] = kCubeVertexPositionIndex_ZNeg_XNeg_YNeg;
			IndexData [ 35 ] = kCubeVertexPositionIndex_ZPos_XNeg_YNeg;
			
		}
		else
		{
			
			IndexData [ 0 ] = kCubeVertexPositionIndex_ZNeg_XNeg_YNeg;
			IndexData [ 2 ] = kCubeVertexPositionIndex_ZNeg_XNeg_YPos;
			IndexData [ 1 ] = kCubeVertexPositionIndex_ZNeg_XPos_YPos;
			IndexData [ 3 ] = kCubeVertexPositionIndex_ZNeg_XPos_YPos;
			IndexData [ 5 ] = kCubeVertexPositionIndex_ZNeg_XPos_YNeg;
			IndexData [ 4 ] = kCubeVertexPositionIndex_ZNeg_XNeg_YNeg;
			
			IndexData [ 6 ] = kCubeVertexPositionIndex_ZPos_XNeg_YPos;
			IndexData [ 8 ] = kCubeVertexPositionIndex_ZPos_XNeg_YNeg;
			IndexData [ 7 ] = kCubeVertexPositionIndex_ZPos_XPos_YNeg;
			IndexData [ 9 ] = kCubeVertexPositionIndex_ZPos_XPos_YNeg;
			IndexData [ 11 ] = kCubeVertexPositionIndex_ZPos_XPos_YPos;
			IndexData [ 10 ] = kCubeVertexPositionIndex_ZPos_XNeg_YPos;
			
			IndexData [ 12 ] = kCubeVertexPositionIndex_ZNeg_XNeg_YPos;
			IndexData [ 14 ] = kCubeVertexPositionIndex_ZPos_XNeg_YPos;
			IndexData [ 13 ] = kCubeVertexPositionIndex_ZPos_XPos_YPos;
			IndexData [ 15 ] = kCubeVertexPositionIndex_ZPos_XPos_YPos;
			IndexData [ 17 ] = kCubeVertexPositionIndex_ZNeg_XPos_YPos;
			IndexData [ 16 ] = kCubeVertexPositionIndex_ZNeg_XNeg_YPos;
			
			IndexData [ 18 ] = kCubeVertexPositionIndex_ZPos_XNeg_YNeg;
			IndexData [ 20 ] = kCubeVertexPositionIndex_ZNeg_XNeg_YNeg;
			IndexData [ 19 ] = kCubeVertexPositionIndex_ZNeg_XPos_YNeg;
			IndexData [ 21 ] = kCubeVertexPositionIndex_ZNeg_XPos_YNeg;
			IndexData [ 23 ] = kCubeVertexPositionIndex_ZPos_XPos_YNeg;
			IndexData [ 22 ] = kCubeVertexPositionIndex_ZPos_XNeg_YNeg;
			
			IndexData [ 24 ] = kCubeVertexPositionIndex_ZNeg_XPos_YNeg;
			IndexData [ 26 ] = kCubeVertexPositionIndex_ZNeg_XPos_YPos;
			IndexData [ 25 ] = kCubeVertexPositionIndex_ZPos_XPos_YPos;
			IndexData [ 27 ] = kCubeVertexPositionIndex_ZPos_XPos_YPos;
			IndexData [ 29 ] = kCubeVertexPositionIndex_ZPos_XPos_YNeg;
			IndexData [ 28 ] = kCubeVertexPositionIndex_ZNeg_XPos_YNeg;
			
			IndexData [ 30 ] = kCubeVertexPositionIndex_ZPos_XNeg_YNeg;
			IndexData [ 32 ] = kCubeVertexPositionIndex_ZPos_XNeg_YPos;
			IndexData [ 31 ] = kCubeVertexPositionIndex_ZNeg_XNeg_YPos;
			IndexData [ 33 ] = kCubeVertexPositionIndex_ZNeg_XNeg_YPos;
			IndexData [ 35 ] = kCubeVertexPositionIndex_ZNeg_XNeg_YNeg;
			IndexData [ 34 ] = kCubeVertexPositionIndex_ZPos_XNeg_YNeg;
			
		}
		
	}
	
	* Target = new Mesh ( Mesh :: kDrawMode_Triangle, IndexDataBuffer, 36, GPU::IndexBuffer :: kIndexType_UBytes, GPU::IndexBuffer :: kUsageType_Static_Draw );
	
	uint32_t I;
	
	for ( I = 0; I < AttributeDataCount; I ++ )
		( * Target ) -> AddAttributeData ( AttributeDataList [ I ] );
	
	for ( I = 0; I < AttributeCount; I ++ )
		( * Target ) -> AddAttribute ( AttributeTrackers [ I ].Attribute );
	
	return true;
	
}

void Xenon::Geometry::Primitives :: SetupNormalQuad2DPositionSpec ( Quad2DPositionSpec & Spec, const std :: string & AttributeName, bool Static )
{
	
	Spec.AttributeName = AttributeName;
	Spec.Static = Static;
	
	Spec.Positions [ kQuad2DVertexIndex_XNeg_YNeg ] = Math :: Vec2 ( - 1.0f, - 1.0f );
	Spec.Positions [ kQuad2DVertexIndex_XPos_YNeg ] = Math :: Vec2 ( + 1.0f, - 1.0f );
	Spec.Positions [ kQuad2DVertexIndex_XNeg_YPos ] = Math :: Vec2 ( - 1.0f, + 1.0f );
	Spec.Positions [ kQuad2DVertexIndex_XPos_YPos ] = Math :: Vec2 ( + 1.0f, + 1.0f );
	
}

void Xenon::Geometry::Primitives :: SetupNormalQuad2DTexturePositionSpec ( Quad2DTexturePositionSpec & Spec, const std :: string & AttributeName, bool Static )
{
	
	Spec.AttributeName = AttributeName;
	Spec.Static = Static;
	
	Spec.Positions [ kQuad2DVertexIndex_XNeg_YNeg ] = Math :: Vec2 ( 0.0f, 1.0f );
	Spec.Positions [ kQuad2DVertexIndex_XPos_YNeg ] = Math :: Vec2 ( 1.0f, 1.0f );
	Spec.Positions [ kQuad2DVertexIndex_XNeg_YPos ] = Math :: Vec2 ( 0.0f, 0.0f );
	Spec.Positions [ kQuad2DVertexIndex_XPos_YPos ] = Math :: Vec2 ( 1.0f, 0.0f );
	
}

bool Xenon::Geometry::Primitives :: GenerateQuad2DMesh ( Mesh ** Target, const Quad2DSpec & Spec )
{
	
	* Target = NULL;
	
	uint32_t AttributeCount = 0;
	uint32_t AttributeDataCount = 0;
	
	if ( Spec.Attributes & kAttributeFlags_Position )
		AttributeCount ++;
	
	if ( Spec.Attributes & kAttributeFlags_Color )
		AttributeCount ++;
	
	if ( Spec.Attributes & kAttributeFlags_TexturePositions )
		AttributeCount += Spec.TexturePositionCount;
	
	typedef struct AttributeGenTracker_Struct
	{
		
		inline AttributeGenTracker_Struct ():
			Attribute ( NULL )
		{
		};
		
		size_t Offset;
		size_t Stride;
		
		MeshAttribute * Attribute;
		
	} AttributeGenTracker;
	
	if ( AttributeCount > 40 ) // Something obviously went wrong, we shouldn't have more than 40 attributes for a simple quad.
		return NULL;
	
	AttributeGenTracker AttributeTrackers [ 40 ];
	
	uint32_t AttributeTrackerIndex;
	
	AttributeTrackerIndex = 0;
	
	size_t CommonStaticBufferAttributeStride = 0;
	size_t CommonStaticBufferAttributeTotal = 0;
	
	if ( Spec.Attributes & kAttributeFlags_Position )
	{
		
		AttributeTrackers [ AttributeTrackerIndex ].Offset = ( Spec.PositionSpec.Static && ( Spec.CompositionMode == kStaticAttributeCompositionMode_Interleaved ) ) ? CommonStaticBufferAttributeStride : 0;
		AttributeTrackerIndex ++;
		
		if ( Spec.PositionSpec.Static )
		{
			
			CommonStaticBufferAttributeTotal += sizeof ( GLfloat ) * 8;
			CommonStaticBufferAttributeStride += sizeof ( GLfloat ) * 2;
			
		}
		else
			AttributeDataCount ++;
		
	}
	
	if ( Spec.Attributes & kAttributeFlags_Color )
	{
		
		AttributeTrackers [ AttributeTrackerIndex ].Offset = ( Spec.ColorSpec.Static && ( Spec.CompositionMode == kStaticAttributeCompositionMode_Interleaved ) ) ? CommonStaticBufferAttributeStride : 0;
		
		AttributeTrackerIndex ++;
		
		if ( Spec.ColorSpec.Static )
		{
			
			CommonStaticBufferAttributeTotal += sizeof ( GLfloat ) * 12;
			CommonStaticBufferAttributeStride += sizeof ( GLfloat ) * 3;
			
		}
		else
			AttributeDataCount ++;
		
	}
	
	if ( Spec.Attributes & kAttributeFlags_TexturePositions )
	{
		
		for ( uint32_t I = 0; I < Spec.TexturePositionCount; I ++ )
		{
			
			AttributeTrackers [ AttributeTrackerIndex ].Offset = ( Spec.TexturePositionSpecs [ I ].Static && ( Spec.CompositionMode == kStaticAttributeCompositionMode_Interleaved ) ) ? CommonStaticBufferAttributeStride : 0;
			
			AttributeTrackerIndex ++;
			
			if ( Spec.TexturePositionSpecs [ I ].Static )
			{
				
				CommonStaticBufferAttributeTotal += sizeof ( GLfloat ) * 8;
				CommonStaticBufferAttributeStride += sizeof ( GLfloat ) * 2;
				
			}
			else
				AttributeDataCount ++;
			
		}
		
	}
	
	if ( Spec.CompositionMode == kStaticAttributeCompositionMode_Interleaved )
	{
		
		AttributeTrackerIndex = 0;
		
		if ( Spec.Attributes & kAttributeFlags_Position )
		{
			
			AttributeTrackers [ AttributeTrackerIndex ].Stride = Spec.PositionSpec.Static ? CommonStaticBufferAttributeStride : 2 * sizeof ( GLfloat );
			
			AttributeTrackerIndex ++;
			
		}
		
		if ( Spec.Attributes & kAttributeFlags_Color )
		{
			
			AttributeTrackers [ AttributeTrackerIndex ].Stride = Spec.ColorSpec.Static ? CommonStaticBufferAttributeStride : 3 * sizeof ( GLfloat );
			
			AttributeTrackerIndex ++;
			
		}
		
		if ( Spec.Attributes & kAttributeFlags_TexturePositions )
		{
			
			for ( uint32_t I = 0; I < Spec.TexturePositionCount; I ++ )
			{
				
				AttributeTrackers [ AttributeTrackerIndex ].Stride = Spec.TexturePositionSpecs [ I ].Static ? CommonStaticBufferAttributeStride : ( 2 * sizeof ( GLfloat ) );
				
				AttributeTrackerIndex ++;
				
			}
			
		}
		
	}
	else
	{
		
		AttributeTrackerIndex = 0;
		
		if ( Spec.Attributes & kAttributeFlags_Position )
		{
			
			AttributeTrackers [ AttributeTrackerIndex ].Stride = 3 * sizeof ( GLfloat );
			
			AttributeTrackerIndex ++;
			
		}
		
		if ( Spec.Attributes & kAttributeFlags_Color )
		{
			
			AttributeTrackers [ AttributeTrackerIndex ].Stride = 3 * sizeof ( GLfloat );
			
			AttributeTrackerIndex ++;
			
		}
		
		if ( Spec.Attributes & kAttributeFlags_TexturePositions )
		{
			
			for ( uint32_t I = 0; I < Spec.TexturePositionCount; I ++ )
			{
				
				AttributeTrackers [ AttributeTrackerIndex ].Stride = 2 * sizeof ( GLfloat );
				
				AttributeTrackerIndex ++;
				
			}
			
		}
		
	}
	
	if ( CommonStaticBufferAttributeTotal != 0 )
		AttributeDataCount ++;
	
	if ( AttributeDataCount > 40 )
		return NULL;
	
	uint32_t AttributeDataIndex = 0;
	MeshAttributeData * AttributeDataList [ 40 ];
	
	Util :: RCMem * StaticDataBuffer = ( CommonStaticBufferAttributeTotal != 0 ) ? new Util :: RCMem ( CommonStaticBufferAttributeTotal ) : NULL;
	void * StaticData = ( CommonStaticBufferAttributeTotal != 0 ) ? StaticDataBuffer -> GetData () : NULL;
	
	MeshAttributeData * StaticAttributeData = ( CommonStaticBufferAttributeTotal != 0 ) ? new MeshAttributeData ( StaticDataBuffer, CommonStaticBufferAttributeTotal, GPU::VertexBuffer :: kUsageType_Static_Draw, false ) : NULL;
	
	if ( ( CommonStaticBufferAttributeTotal != 0 ) )
	{
		
		AttributeDataList [ AttributeDataIndex ] = StaticAttributeData;
		AttributeDataIndex ++;
		
		if ( StaticData == NULL )
		{
			
			delete StaticDataBuffer;
			
			return false;
			
		}
		
	}
	
	AttributeTrackerIndex = 0;
	
	if ( Spec.Attributes & kAttributeFlags_Position )
	{
		
		void * PositionData;
		size_t PositionOffset = AttributeTrackers [ AttributeTrackerIndex ].Offset;
		size_t PositionStride = AttributeTrackers [ AttributeTrackerIndex ].Stride;
		
		if ( Spec.PositionSpec.Static && ( Spec.CompositionMode != kStaticAttributeCompositionMode_SeperateBuffers ) )
		{
			
			PositionData = StaticData;
			
			AttributeTrackers [ AttributeTrackerIndex ].Attribute = new MeshAttribute ( Spec.PositionSpec.AttributeName, GPU::VertexArray :: kFPAttributeInputType_Float, false, 2, PositionStride, reinterpret_cast <void *> ( PositionOffset ), StaticAttributeData );
			AttributeTrackerIndex ++;
			
		}
		else
		{
			
			Util :: RCMem * PositionDataBuffer = new Util :: RCMem ( sizeof ( GLfloat ) * 2 );
			PositionData = PositionDataBuffer -> GetData ();
			
			MeshAttributeData * PositionAttributeData =  new MeshAttributeData ( PositionDataBuffer, sizeof ( GLfloat ) * 8, Spec.ColorSpec.Static ? GPU::VertexBuffer :: kUsageType_Static_Draw : GPU::VertexBuffer :: kUsageType_Dynamic_Draw, true );
			
			AttributeDataList [ AttributeDataIndex ] = PositionAttributeData;
			AttributeDataIndex ++;
			
			if ( PositionData == NULL )
			{
				
				delete StaticDataBuffer;
				delete PositionDataBuffer;
				
				return false;
				
			}
			
			AttributeTrackers [ AttributeTrackerIndex ].Attribute = new MeshAttribute ( Spec.PositionSpec.AttributeName, GPU::VertexArray :: kFPAttributeInputType_Float, false, 2, PositionStride, reinterpret_cast <void *> ( PositionOffset ), PositionAttributeData );
			AttributeTrackerIndex ++;
			
		}
		
		Math::Vec2 :: Copy ( * reinterpret_cast <Math :: Vec2 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * kQuad2DVertexIndex_XNeg_YNeg ) ), Spec.PositionSpec.Positions [ kQuad2DVertexIndex_XNeg_YNeg ] );
		Math::Vec2 :: Copy ( * reinterpret_cast <Math :: Vec2 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * kQuad2DVertexIndex_XPos_YNeg ) ), Spec.PositionSpec.Positions [ kQuad2DVertexIndex_XPos_YNeg ] );
		Math::Vec2 :: Copy ( * reinterpret_cast <Math :: Vec2 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * kQuad2DVertexIndex_XNeg_YPos ) ), Spec.PositionSpec.Positions [ kQuad2DVertexIndex_XNeg_YPos ] );
		Math::Vec2 :: Copy ( * reinterpret_cast <Math :: Vec2 *> ( reinterpret_cast <char *> ( PositionData ) + ( PositionOffset + PositionStride * kQuad2DVertexIndex_XPos_YPos ) ), Spec.PositionSpec.Positions [ kQuad2DVertexIndex_XPos_YPos ] );
		
	}
	
	if ( Spec.Attributes & kAttributeFlags_Color )
	{
		
		void * ColorData;
		size_t ColorOffset = AttributeTrackers [ AttributeTrackerIndex ].Offset;
		size_t ColorStride = AttributeTrackers [ AttributeTrackerIndex ].Stride;
		
		if ( Spec.ColorSpec.Static && ( Spec.CompositionMode != kStaticAttributeCompositionMode_SeperateBuffers ) )
		{
			
			ColorData = StaticData;
			
			AttributeTrackers [ AttributeTrackerIndex ].Attribute = new MeshAttribute ( Spec.ColorSpec.AttributeName, GPU::VertexArray :: kFPAttributeInputType_Float, false, 3, ColorStride, reinterpret_cast <void *> ( ColorOffset ), StaticAttributeData );
			AttributeTrackerIndex ++;
			
		}
		else
		{
			
			Util :: RCMem * ColorDataBuffer = new Util :: RCMem ( sizeof ( GLfloat ) * 12 );
			ColorData = ColorDataBuffer -> GetData ();
			
			MeshAttributeData * ColorAttributeData =  new MeshAttributeData ( ColorDataBuffer, sizeof ( GLfloat ) * 12, Spec.ColorSpec.Static ? GPU::VertexBuffer :: kUsageType_Static_Draw : GPU::VertexBuffer :: kUsageType_Dynamic_Draw, true );
			
			AttributeDataList [ AttributeDataIndex ] = ColorAttributeData;
			AttributeDataIndex ++;
			
			if ( ColorData == NULL )
			{
				
				delete StaticDataBuffer;
				delete ColorDataBuffer;
				
				return false;
				
			}
			
			AttributeTrackers [ AttributeTrackerIndex ].Attribute = new MeshAttribute ( Spec.ColorSpec.AttributeName, GPU::VertexArray :: kFPAttributeInputType_Float, false, 3, ColorStride, reinterpret_cast <void *> ( ColorOffset ), ColorAttributeData );
			AttributeTrackerIndex ++;
			
		}
		
		Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( ColorData ) + ( ColorOffset + ColorStride * kQuad2DVertexIndex_XNeg_YNeg ) ), Spec.ColorSpec.Colors [ kQuad2DVertexIndex_XNeg_YNeg ] );
		Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( ColorData ) + ( ColorOffset + ColorStride * kQuad2DVertexIndex_XPos_YNeg ) ), Spec.ColorSpec.Colors [ kQuad2DVertexIndex_XPos_YNeg ] );
		Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( ColorData ) + ( ColorOffset + ColorStride * kQuad2DVertexIndex_XNeg_YPos ) ), Spec.ColorSpec.Colors [ kQuad2DVertexIndex_XNeg_YPos ] );
		Math::Vec3 :: Copy ( * reinterpret_cast <Math :: Vec3 *> ( reinterpret_cast <char *> ( ColorData ) + ( ColorOffset + ColorStride * kQuad2DVertexIndex_XPos_YPos ) ), Spec.ColorSpec.Colors [ kQuad2DVertexIndex_XPos_YPos ] );
		
	}
	
	if ( Spec.Attributes & kAttributeFlags_TexturePositions )
	{
		
		for ( uint32_t I = 0; I < Spec.TexturePositionCount; I ++ )
		{
			
			void * TexturePositionData;
			size_t TexturePositionOffset = AttributeTrackers [ AttributeTrackerIndex ].Offset;
			size_t TexturePositionStride = AttributeTrackers [ AttributeTrackerIndex ].Stride;
			
			if ( Spec.TexturePositionSpecs [ I ].Static && ( Spec.CompositionMode != kStaticAttributeCompositionMode_SeperateBuffers ) )
			{
				
				TexturePositionData = StaticData;
				
				AttributeTrackers [ AttributeTrackerIndex ].Attribute = new MeshAttribute ( Spec.TexturePositionSpecs [ I ].AttributeName, GPU::VertexArray :: kFPAttributeInputType_Float, false, 2, TexturePositionStride, reinterpret_cast <void *> ( TexturePositionOffset ), StaticAttributeData );
				AttributeTrackerIndex ++;
				
			}
			else
			{
				
				Util :: RCMem * TexturePositionDataBuffer = new Util :: RCMem ( 8 * sizeof ( float ) );
				TexturePositionData = TexturePositionDataBuffer -> GetData ();
				
				MeshAttributeData * TexturePositionAttributeData =  new MeshAttributeData ( TexturePositionDataBuffer, 8 * sizeof ( float ), Spec.TexturePositionSpecs [ I ].Static ? GPU::VertexBuffer :: kUsageType_Static_Draw : GPU::VertexBuffer :: kUsageType_Dynamic_Draw, true );
				
				AttributeDataList [ AttributeDataIndex ] = TexturePositionAttributeData;
				AttributeDataIndex ++;
				
				if ( TexturePositionData == NULL )
				{
					
					delete StaticDataBuffer;
					delete TexturePositionDataBuffer;
					
					return false;
					
				}
				
			}
			
			Math::Vec2 :: Copy ( * reinterpret_cast <Math :: Vec2 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * kQuad2DVertexIndex_XNeg_YNeg ) ), Spec.TexturePositionSpecs [ I ].Positions [ kQuad2DVertexIndex_XNeg_YNeg ] );
			Math::Vec2 :: Copy ( * reinterpret_cast <Math :: Vec2 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * kQuad2DVertexIndex_XPos_YNeg ) ), Spec.TexturePositionSpecs [ I ].Positions [ kQuad2DVertexIndex_XPos_YNeg ] );
			Math::Vec2 :: Copy ( * reinterpret_cast <Math :: Vec2 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * kQuad2DVertexIndex_XNeg_YPos ) ), Spec.TexturePositionSpecs [ I ].Positions [ kQuad2DVertexIndex_XNeg_YPos ] );
			Math::Vec2 :: Copy ( * reinterpret_cast <Math :: Vec2 *> ( reinterpret_cast <char *> ( TexturePositionData ) + ( TexturePositionOffset + TexturePositionStride * kQuad2DVertexIndex_XPos_YPos ) ), Spec.TexturePositionSpecs [ I ].Positions [ kQuad2DVertexIndex_XPos_YPos ] );
			
		}
		
	}
	
	Util :: RCMem * IndexDataBuffer = new Util :: RCMem ( sizeof ( GLubyte ) * 6 );
	GLubyte * IndexData = reinterpret_cast <GLubyte *> ( IndexDataBuffer -> GetData () );
	
	if ( Spec.WindOutwardFacesClockwise )
	{
		
		IndexData [ 0 ] = kQuad2DVertexIndex_XNeg_YNeg;
		IndexData [ 1 ] = kQuad2DVertexIndex_XNeg_YPos;
		IndexData [ 2 ] = kQuad2DVertexIndex_XPos_YPos;
		
		IndexData [ 3 ] = kQuad2DVertexIndex_XPos_YPos;
		IndexData [ 4 ] = kQuad2DVertexIndex_XPos_YNeg;
		IndexData [ 5 ] = kQuad2DVertexIndex_XNeg_YNeg;
		
	}
	else
	{
		
		IndexData [ 0 ] = kQuad2DVertexIndex_XNeg_YNeg;
		IndexData [ 2 ] = kQuad2DVertexIndex_XNeg_YPos;
		IndexData [ 1 ] = kQuad2DVertexIndex_XPos_YPos;
		
		IndexData [ 3 ] = kQuad2DVertexIndex_XPos_YPos;
		IndexData [ 5 ] = kQuad2DVertexIndex_XPos_YNeg;
		IndexData [ 4 ] = kQuad2DVertexIndex_XNeg_YNeg;
		
	}
	
	* Target = new Mesh ( Mesh :: kDrawMode_Triangle, IndexDataBuffer, 6, GPU::IndexBuffer :: kIndexType_UBytes, GPU::IndexBuffer :: kUsageType_Static_Draw );
	
	uint32_t I;
	
	for ( I = 0; I < AttributeDataCount; I ++ )
		( * Target ) -> AddAttributeData ( AttributeDataList [ I ] );
	
	for ( I = 0; I < AttributeCount; I ++ )
		( * Target ) -> AddAttribute ( AttributeTrackers [ I ].Attribute );
	
	return true;
	
}
