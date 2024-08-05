#pragma once

#include "Engine/EngineTypes.h"
#include "Units/RigUnit.h"
#include "IKDebugExtension.generated.h"

UENUM(BlueprintType)
enum class EDrawDebugSpace : uint8
{
	GlobalSpace	UMETA(DisplayName = "GlobalSpace"),
	WorldSpace	UMETA(DisplayName = "WorldSpace"),
};

USTRUCT(BlueprintType)
struct IKEXTENSION_API FRigUnit_DebugSetting
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EDrawDebugSpace DrawDebugSpace = EDrawDebugSpace::GlobalSpace;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FLinearColor Color = FLinearColor::Red;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Duration = 0.f;
};


USTRUCT(meta = (Abstract, Category = "DrawDebug", NodeColor = "0.83077 0.846873 0.049707"))
struct IKEXTENSION_API FRigUnit_DebugBaseDrawDebug : public FRigUnitMutable
{
	GENERATED_BODY()

	/** Enable debug */
	UPROPERTY(meta = (Input))
	bool EnableDebug = true;

	/** Debug setting */
	UPROPERTY(meta = (Input))
	FRigUnit_DebugSetting Setting;
};


/**
 * Draw Debug Line
 */
USTRUCT(meta = (DisplayName = "Draw Debug Line"))
struct IKEXTENSION_API FRigUnit_DebugDrawDebugLine : public FRigUnit_DebugBaseDrawDebug
{
	GENERATED_BODY()

	RIGVM_METHOD()
		virtual void Execute() override;

	/** Line start */
	UPROPERTY(meta = (Input))
	FVector Start = FVector::ZeroVector;

	/** Line end */
	UPROPERTY(meta = (Input))
	FVector End = FVector::ZeroVector;

	/** Line thickness */
	UPROPERTY(meta = (Input, UIMin = "0.0", UIMax = "100.0"))
	float Thickness = 0.f;
};


/**
 * Draw Debug Point
 */
USTRUCT(meta = (DisplayName = "Draw Debug Point"))
struct IKEXTENSION_API FRigUnit_DebugDrawDebugPoint : public FRigUnit_DebugBaseDrawDebug
{
	GENERATED_BODY()

	RIGVM_METHOD()
		virtual void Execute() override;

	/** Point position */
	UPROPERTY(meta = (Input))
	FVector Position = FVector::ZeroVector;

	/** Point size */
	UPROPERTY(meta = (Input))
	float Size = 1.f;
};

/**
 * Draw Debug Arrow
 */
USTRUCT(meta = (DisplayName = "Draw Debug Arrow"))
struct IKEXTENSION_API FRigUnit_DebugDrawDebugArrow : public FRigUnit_DebugBaseDrawDebug
{
	GENERATED_BODY()

	RIGVM_METHOD()
		virtual void Execute() override;

	/** Arrow start */
	UPROPERTY(meta = (Input))
	FVector Start = FVector::ZeroVector;

	/** Arrow end */
	UPROPERTY(meta = (Input))
	FVector End = FVector::ZeroVector;

	/** Arrow size */
	UPROPERTY(meta = (Input))
	float Size = 1.f;

	/** Arrow thickness */
	UPROPERTY(meta = (Input, UIMin = "0.0", UIMax = "100.0"))
	float Thickness = 0.f;
};

/**
 * Draw Debug Box
 */
USTRUCT(meta = (DisplayName = "Draw Debug Box"))
struct IKEXTENSION_API FRigUnit_DebugDrawDebugBox : public FRigUnit_DebugBaseDrawDebug
{
	GENERATED_BODY()

	RIGVM_METHOD()
		virtual void Execute() override;

	/** Box center */
	UPROPERTY(meta = (Input))
	FVector Center = FVector::ZeroVector;

	/** Box extent */
	UPROPERTY(meta = (Input))
	FVector Extent = FVector::ZeroVector;

	/** Box rotation */
	UPROPERTY(meta = (Input))
	FQuat Rotation = FQuat::Identity;

	/** Box thickness */
	UPROPERTY(meta = (Input, UIMin = "0.0", UIMax = "100.0"))
	float Thickness = 0.f;
};

/**
 * Draw Debug Sphere
 */
USTRUCT(meta = (DisplayName = "Draw Debug Sphere"))
struct IKEXTENSION_API FRigUnit_DebugDrawDebugSphere : public FRigUnit_DebugBaseDrawDebug
{
	GENERATED_BODY()

	RIGVM_METHOD()
		virtual void Execute() override;

	/** Sphere center */
	UPROPERTY(meta = (Input))
	FVector Center = FVector::ZeroVector;

	/** Sphere radius */
	UPROPERTY(meta = (Input, UIMin = "0.0", UIMax = "1000.0"))
	float Radius = 20.f;

	/** Sphere segments */
	UPROPERTY(meta = (Input, UIMin = "0.0", UIMax = "100.0"))
	int32 Segments = 12;

	/** Sphere thickness */
	UPROPERTY(meta = (Input, UIMin = "0.0", UIMax = "100.0"))
	float Thickness = 0.f;
};

/**
 * Draw Debug Cylinder
 */
USTRUCT(meta = (DisplayName = "Draw Debug Cylinder"))
struct IKEXTENSION_API FRigUnit_DebugDrawDebugCylinder : public FRigUnit_DebugBaseDrawDebug
{
	GENERATED_BODY()

	RIGVM_METHOD()
		virtual void Execute() override;

	/** Cylinder start */
	UPROPERTY(meta = (Input))
	FVector Start = FVector::ZeroVector;

	/** Cylinder end */
	UPROPERTY(meta = (Input))
	FVector End = FVector::ZeroVector;

	/** Cylinder radius */
	UPROPERTY(meta = (Input, UIMin = "0.0", UIMax = "1000.0"))
	float Radius = 20.f;

	/** Cylinder segments */
	UPROPERTY(meta = (Input, UIMin = "0", UIMax = "100"))
	int32 Segments = 12;

	/** Cylinder thickness */
	UPROPERTY(meta = (Input, UIMin = "0.0", UIMax = "100.0"))
	float Thickness = 0.f;
};

/**
 * Draw Debug Cone
 */
USTRUCT(meta = (DisplayName = "Draw Debug Cone"))
struct IKEXTENSION_API FRigUnit_DebugDrawDebugCone : public FRigUnit_DebugBaseDrawDebug
{
	GENERATED_BODY()

	RIGVM_METHOD()
		virtual void Execute() override;

	/** Cone origin */
	UPROPERTY(meta = (Input))
	FVector Origin = FVector::ZeroVector;

	/** Cone direction */
	UPROPERTY(meta = (Input))
	FVector Direction = FVector::UpVector;

	/** Cone radius */
	UPROPERTY(meta = (Input, UIMin = "0.0", UIMax = "1000.0"))
	float Length = 50.f;

	/** Cone angle width */
	UPROPERTY(meta = (Input, UIMin = "-1.0", UIMax = "1.0"))
	float AngleWidth = .5f;

	/** Cone angle height */
	UPROPERTY(meta = (Input, UIMin = "-1.0", UIMax = "1.0"))
	float AngleHeight = .5f;

	/** Cone segments */
	UPROPERTY(meta = (Input, UIMin = "0", UIMax = "100"))
	int32 Segments = 12;

	/** Cone thickness */
	UPROPERTY(meta = (Input, UIMin = "0.0", UIMax = "100.0"))
	float Thickness = 0.f;
};

/**
 * Draw Debug Cone In Degrees
 */
USTRUCT(meta = (DisplayName = "Draw Debug Cone In Degrees"))
struct IKEXTENSION_API FRigUnit_DebugDrawDebugConeInDegrees : public FRigUnit_DebugBaseDrawDebug
{
	GENERATED_BODY()

	RIGVM_METHOD()
		virtual void Execute() override;

	/** Cone origin */
	UPROPERTY(meta = (Input))
	FVector Origin = FVector::ZeroVector;

	/** Cone direction */
	UPROPERTY(meta = (Input))
	FVector Direction = FVector::UpVector;

	/** Cone radius */
	UPROPERTY(meta = (Input, UIMin = "0.0", UIMax = "1000.0"))
	float Length = 50.f;

	/** Cone angle width */
	UPROPERTY(meta = (Input, UIMin = "-180.0", UIMax = "180.0"))
	float AngleWidth = 45.f;

	/** Cone angle height */
	UPROPERTY(meta = (Input, UIMin = "-180.0", UIMax = "180.0"))
	float AngleHeight = 45.f;

	/** Cone segments */
	UPROPERTY(meta = (Input, UIMin = "0", UIMax = "100"))
	int32 Segments = 12;

	/** Cone thickness */
	UPROPERTY(meta = (Input, UIMin = "0.0", UIMax = "100.0"))
	float Thickness = 0.f;
};

/**
 * Draw Debug Capsule
 */
USTRUCT(meta = (DisplayName = "Draw Debug Capsule"))
struct IKEXTENSION_API FRigUnit_DebugDrawDebugCapsule : public FRigUnit_DebugBaseDrawDebug
{
	GENERATED_BODY()

	RIGVM_METHOD()
		virtual void Execute() override;

	/** Capsule center */
	UPROPERTY(meta = (Input))
	FVector Center = FVector::ZeroVector;

	/** Capsule half height */
	UPROPERTY(meta = (Input, UIMin = "0.0", UIMax = "1000.0"))
	float HalfHeight = 20.f;

	/** Capsule radius */
	UPROPERTY(meta = (Input, UIMin = "0.0", UIMax = "1000.0"))
	float Radius = 10.f;

	/** Capsule rotation */
	UPROPERTY(meta = (Input))
	FQuat Rotation = FQuat::Identity;

	/** Capsule thickness */
	UPROPERTY(meta = (Input, UIMin = "0.0", UIMax = "100.0"))
	float Thickness = 0.f;
};


/**
 * Draw Debug Plane
 */
USTRUCT(meta = (DisplayName = "Draw Debug Plane"))
struct IKEXTENSION_API FRigUnit_DebugDrawDebugPlane : public FRigUnit_DebugBaseDrawDebug
{
	GENERATED_BODY()

	RIGVM_METHOD()
		virtual void Execute() override;

	/** Plane location */
	UPROPERTY(meta = (Input))
	FVector Location = FVector::ZeroVector;

	/** Plane normal */
	UPROPERTY(meta = (Input))
	FVector Normal = FVector::UpVector;

	/** Plane size */
	UPROPERTY(meta = (Input, UIMin = "0.0", UIMax = "1000.0"))
	float Size = 20.f;
};
