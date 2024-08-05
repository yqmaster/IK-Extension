#include "IKCollisionExtension.h"

#include "Units/RigUnitContext.h"
#include "Components/PrimitiveComponent.h"
#include "KismetTraceUtils.h"
#include "RigVMFunctions/Math/RigVMMathLibrary.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(IKCollisionExtension)

FRigUnit_SphereTraceByObjectTypesWithDebug_Execute()
{
	DECLARE_SCOPE_HIERARCHICAL_COUNTER_RIGUNIT()

	bHit = false;
	HitLocation = FVector::ZeroVector;
	HitNormal = FVector::UpVector;
	NormalRotation = FQuat::Identity;

	const UWorld* World = ExecuteContext.GetWorld();
	if (World == nullptr)
	{
		return;
	}

	const FVector FixStart = ExecuteContext.ToWorldSpace(Start);
	const FVector FixEnd = ExecuteContext.ToWorldSpace(End);
	const ECollisionChannel CollisionChannel = UEngineTypes::ConvertToCollisionChannel(TraceChannel);
	const FCollisionShape CollisionShape = FCollisionShape::MakeSphere(Radius);

	FCollisionQueryParams QueryParams;
	QueryParams.bTraceComplex = true;

	if (ExecuteContext.GetOwningActor())
	{
		QueryParams.AddIgnoredActor(ExecuteContext.GetOwningActor());
	}
	else if (const UPrimitiveComponent* PrimitiveComponent = Cast<UPrimitiveComponent>(ExecuteContext.GetOwningComponent()))
	{
		QueryParams.AddIgnoredComponent(PrimitiveComponent);
	}

	FHitResult HitResult;
	bHit = World->SweepSingleByChannel(HitResult, FixStart, FixEnd, FQuat::Identity, CollisionChannel, CollisionShape, QueryParams);

#if ENABLE_DRAW_DEBUG
	if (bEnableDebug)
	{
		if (bHit)
		{
			const FVector NormalStart = HitResult.ImpactPoint + 0.01f;
			const FVector NormalVector = HitResult.ImpactNormal;
			if (HitResult.bBlockingHit)
			{
				DrawDebugSweptSphere(World, FixStart, HitResult.Location, Radius, FColor::Red, false, 0.f);
				DrawDebugSweptSphere(World, HitResult.Location, FixEnd, Radius, FColor::Green, false, 0.f);
			}
			if (DebugSetting.bDrawDebugNormal)
			{
				const FVector NormalEnd = NormalStart + NormalVector * DebugSetting.NormalSetting.Length;
				const FVector UpEnd = NormalStart + FVector::UpVector * DebugSetting.NormalSetting.Length;
				const FColor NormalArrorColor = DebugSetting.NormalSetting.NormalArrorColor.ToFColor(true);
				const FColor UpDirectionColor = DebugSetting.NormalSetting.UpDirectionColor.ToFColor(true);
				DrawDebugLine(World, NormalStart, UpEnd, UpDirectionColor, false, 0.f, SDPG_World, 1.f);
				DrawDebugDirectionalArrow(World, NormalStart, NormalEnd, 5.f, NormalArrorColor, false, 0.f, SDPG_World, 1.f);
			}
			if (DebugSetting.bDrawDebugPlane)
			{
				const FPlane Plane = FPlane(NormalStart, NormalVector);
				const FColor PlaneColor = DebugSetting.PlaneSetting.Color.ToFColor(true);
				DrawDebugSolidPlane(World, Plane, NormalStart, DebugSetting.PlaneSetting.Size, PlaneColor, false, 0.f, SDPG_World);
			}
		}
		else
		{
			DrawDebugSweptSphere(World, Start, End, Radius, FColor::Red, false, 0.f);
		}
	}
#endif

	if (bHit)
	{
		const FTransform ToWorldSpaceTransform = ExecuteContext.GetToWorldSpaceTransform();
		const FVector UpVector = ToWorldSpaceTransform.InverseTransformVector(FVector::UpVector);
		HitLocation = ExecuteContext.ToVMSpace(HitResult.ImpactPoint);
		HitNormal = ToWorldSpaceTransform.InverseTransformVector(HitResult.ImpactNormal);
		NormalRotation = FRigVMMathLibrary::FindQuatBetweenVectors(UpVector, HitNormal);
	}
}
