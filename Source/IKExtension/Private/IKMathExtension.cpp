#include "IKMathExtension.h"

#include "Units/RigUnit.h"
#include "Units/RigUnitContext.h"
#include "RigVMFunctions/Math/RigVMMathLibrary.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(IKMathExtension)

FRigVMFunction_MathQuaternionGlobalNormalToGlobalQuat_Execute()
{
	DECLARE_SCOPE_HIERARCHICAL_COUNTER_RIGUNIT()

	Result = FQuat::Identity;

	if (Normal.IsNearlyZero())
	{
		return;
	}

	const FTransform ToWorldSpaceTransform = ExecuteContext.GetToWorldSpaceTransform();
	const FVector UpVector = ToWorldSpaceTransform.InverseTransformVector(FVector::UpVector);
	Result = FRigVMMathLibrary::FindQuatBetweenVectors(UpVector, Normal);
}


FRigUnit_HierarchyGlobalQuatToLocalQuat_Execute()
{
	DECLARE_SCOPE_HIERARCHICAL_COUNTER_RIGUNIT()

	URigHierarchy* Hierarchy = ExecuteContext.Hierarchy;
	Result = Rotation;

	FRigElementKey Parent;
	if (CachedSpace.IsIdentical(Space, Hierarchy))
	{
		Parent = CachedParent.GetKey();
	}
	else
	{
		CachedSpace.Reset();
		CachedParent.Reset();

		Parent = Hierarchy->GetFirstParent(Space);
		if (Parent.IsValid())
		{
			CachedParent.UpdateCache(Parent, Hierarchy);
			CachedSpace.UpdateCache(Space, Hierarchy);
		}
	}

	if (Parent.IsValid())
	{
		const FQuat TrasnformRotation = Hierarchy->GetGlobalTransform(Parent).GetRotation();
		Result = TrasnformRotation.Inverse() * Rotation * TrasnformRotation;
	}
}