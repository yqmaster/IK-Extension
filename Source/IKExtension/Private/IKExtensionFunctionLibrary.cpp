#include "IKExtensionFunctionLibrary.h"
#include "IKDebugExtension.h"
#include "RigVMCore/RigVMExecuteContext.h"

FVector UIKExtensionFunctionLibrary::CastLocationByDebugSpace(FRigVMExecuteContext ExecuteContext, EDrawDebugSpace DebugSpace, FVector Location)
{
	if (DebugSpace == EDrawDebugSpace::GlobalSpace)
	{
		return ExecuteContext.ToWorldSpace(Location);
	}

	if (DebugSpace == EDrawDebugSpace::WorldSpace)
	{
		return Location;
	}

	checkf(false, TEXT("Invalid DebugSpace"));
	return Location;
}

FVector UIKExtensionFunctionLibrary::CastDirectionByDebugSpace(struct FRigVMExecuteContext ExecuteContext, enum EDrawDebugSpace DebugSpace, FVector Direction)
{
	if (DebugSpace == EDrawDebugSpace::GlobalSpace)
	{
		return ExecuteContext.GetToWorldSpaceTransform().TransformVector(Direction);
	}

	if (DebugSpace == EDrawDebugSpace::WorldSpace)
	{
		return Direction;
	}

	checkf(false, TEXT("Invalid DebugSpace"));
	return Direction;
}

FRotator UIKExtensionFunctionLibrary::CastRotationByDebugSpace(struct FRigVMExecuteContext ExecuteContext, enum EDrawDebugSpace DebugSpace, FQuat Rotation)
{
	if (DebugSpace == EDrawDebugSpace::GlobalSpace)
	{
		return ExecuteContext.ToWorldSpace(Rotation).Rotator();
	}

	if (DebugSpace == EDrawDebugSpace::WorldSpace)
	{
		return Rotation.Rotator();
	}

	checkf(false, TEXT("Invalid DebugSpace"));
	return Rotation.Rotator();
}
