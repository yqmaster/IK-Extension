#pragma once

#include "Engine/EngineTypes.h"
#include "Units/RigUnit.h"
#include "IKCollisionExtension.generated.h"

/**
 * IK Rig Normal Debug Setting
 */
USTRUCT(BlueprintType)
struct IKEXTENSION_API FDebugNormalSetting
{
	GENERATED_BODY()

	FDebugNormalSetting()
		:Length(50.f)
		,NormalArrorColor(FLinearColor::Yellow)
		,UpDirectionColor(FLinearColor::Blue)
	{

	}

	/** Debug normal length */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Length;

	/** Debug normal arror color */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor NormalArrorColor;

	/** Debug up direction color */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor UpDirectionColor;
};


/**
 * IK Rig Plane Debug Setting
 */
USTRUCT(BlueprintType)
struct IKEXTENSION_API FDebugPlaneSetting
{
	GENERATED_BODY()

	FDebugPlaneSetting()
		:Size(FVector2D(10.f,10.f))
		,Color(FLinearColor::Gray)
	{

	}

	/** Debug plane size */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D Size;

	/** Debug plan color */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor Color;
};


/**
 * IK Rig Custom Trace Debug Setting
 */
USTRUCT(BlueprintType)
struct IKEXTENSION_API FCustomTraceDebugSetting
{
	GENERATED_BODY()

	FCustomTraceDebugSetting()
		:bDrawDebugNormal(true)
		,bDrawDebugPlane(false)
	{

	}

	/** Need draw debug normal */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bDrawDebugNormal;

	/** Debug normal setting */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FDebugNormalSetting NormalSetting;

	/** Need draw debug plane */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bDrawDebugPlane;

	/** Debug plane setting */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FDebugPlaneSetting PlaneSetting;
};

/**
 * Custom Trace In IK Rig
 */
USTRUCT(meta = (DisplayName = "Sphere Trace By Object Types With Debug", Category = "Collision", DocumentationPolicy = "Strict", Keywords = "Sweep,Raytrace,Collision,Collide,Trace", Varying, NodeColor = "0.2 0.4 0.7"))
struct IKEXTENSION_API FRigUnit_SphereTraceByObjectTypesWithDebug : public FRigUnit
{
	GENERATED_BODY()

	FRigUnit_SphereTraceByObjectTypesWithDebug() 
		:Start(EForceInit::ForceInitToZero)
		,End(EForceInit::ForceInitToZero)
		,TraceChannel(ETraceTypeQuery::TraceTypeQuery1)
		,Radius(5.f)
		,bEnableDebug(false)
		,bHit(false)
		,HitLocation(EForceInit::ForceInitToZero)
		,HitNormal(FVector::UpVector)
		,NormalRotation(FQuat::Identity)
	{

	}


	RIGVM_METHOD()
	virtual void Execute() override;

	/** Start of the trace in rig / global space */
	UPROPERTY(meta = (Input))
	FVector Start;

	/** End of the trace in rig / global space */
	UPROPERTY(meta = (Input))
	FVector End;

	/** The 'channel' that this trace is in, used to determine which components to hit */
	UPROPERTY(meta = (Input))
	TEnumAsByte<ETraceTypeQuery> TraceChannel;

	/** Radius of the sphere to use for sweeping / tracing */
	UPROPERTY(meta = (Input, UIMin = "0.0", UIMax = "100.0"))
	float Radius;

	/** Enable debug */
	UPROPERTY(meta = (Input))
	bool bEnableDebug;

	/** Debug setting */
	UPROPERTY(meta = (Input))
	FCustomTraceDebugSetting DebugSetting;

	/** Returns true if there was a hit */
	UPROPERTY(meta = (Output))
	bool bHit;

	/** Hit location in rig / global Space */
	UPROPERTY(meta = (Output))
	FVector HitLocation;

	/** Hit normal in rig / global Space */
	UPROPERTY(meta = (Output))
	FVector HitNormal;

	/** Hit normal rotation in rig / global Space */
	UPROPERTY(meta = (Output))
	FQuat NormalRotation;
};
