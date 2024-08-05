#pragma once

#include "Engine/EngineTypes.h"
#include "RigVMFunctions/Math/RigVMFunction_MathQuaternion.h"
#include "Units/RigUnit.h"
#include "IKMathExtension.generated.h"

/**
 * GlobalNormal To GlobalQuat
 */
USTRUCT(meta = (DisplayName = "GlobalNormal To GlobalQuat", TemplateName = "GlobalNormalToGlobalQuat", Keywords = "Make,Normal,Global"))
struct IKEXTENSION_API FRigVMFunction_MathQuaternionGlobalNormalToGlobalQuat : public FRigVMFunction_MathQuaternionBase
{
	GENERATED_BODY()

	FRigVMFunction_MathQuaternionGlobalNormalToGlobalQuat()
		:Normal(FVector::UpVector)
		, Result(FQuat::Identity)
	{

	}

	RIGVM_METHOD()
	virtual void Execute() override;

	/** Normal vector */
	UPROPERTY(meta = (Input))
	FVector Normal;

	/** Rotation result */
	UPROPERTY(meta = (Output))
	FQuat Result;
};

/**
 * GlobalQuat To LocalQuat
 */
USTRUCT(meta = (DisplayName = "GlobalQuat To LocalQuat", NodeColor="0.462745, 1,0, 0.329412", Keywords = "Make,Quat,Global,Local", Varying))
struct IKEXTENSION_API FRigUnit_HierarchyGlobalQuatToLocalQuat : public FRigUnit
{
	GENERATED_BODY()

	FRigUnit_HierarchyGlobalQuatToLocalQuat()
		:Rotation(FQuat::Identity)
		, Space(FRigElementKey(NAME_None, ERigElementType::Bone))
		, Result(FQuat::Identity)
	{

	}

	RIGVM_METHOD()
	virtual void Execute() override;

	/** Rotation */
	UPROPERTY(meta = (Input))
	FQuat Rotation;

	/** Bone space */
	UPROPERTY(meta = (Input, ExpandByDefault))
	FRigElementKey Space;

	/** Quat result */
	UPROPERTY(meta = (Output))
	FQuat Result;

	/** Used to cache the internally used space */
	UPROPERTY()
	FCachedRigElement CachedSpace;

	/** Used to cache the internally used parent */
	UPROPERTY()
	FCachedRigElement CachedParent;
};
