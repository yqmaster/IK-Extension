#include "IKDebugExtension.h"

#include "Engine/World.h"
#include "Kismet/KismetSystemLibrary.h"
#include "ControlRigDefines.h"
#include "IKExtensionFunctionLibrary.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(IKDebugExtension)

FRigUnit_DebugDrawDebugLine_Execute()
{
	DECLARE_SCOPE_HIERARCHICAL_COUNTER_RIGUNIT()

#if ENABLE_DRAW_DEBUG
	if (EnableDebug)
	{
		const FVector FixStart = UIKExtensionFunctionLibrary::CastLocationByDebugSpace(ExecuteContext, Setting.DrawDebugSpace, Start);
		const FVector FixEnd = UIKExtensionFunctionLibrary::CastLocationByDebugSpace(ExecuteContext, Setting.DrawDebugSpace, End);
		UKismetSystemLibrary::DrawDebugLine(ExecuteContext.GetWorld(), FixStart, FixEnd, Setting.Color, Setting.Duration, Thickness);
	}
#endif // ENABLE_DRAW_DEBUG
}

FRigUnit_DebugDrawDebugPoint_Execute()
{
	DECLARE_SCOPE_HIERARCHICAL_COUNTER_RIGUNIT()

#if ENABLE_DRAW_DEBUG
	if (EnableDebug)
	{
		const FVector FixPosition = UIKExtensionFunctionLibrary::CastLocationByDebugSpace(ExecuteContext, Setting.DrawDebugSpace, Position);
		UKismetSystemLibrary::DrawDebugPoint(ExecuteContext.GetWorld(), FixPosition, Size, Setting.Color, Setting.Duration);
	}
#endif // ENABLE_DRAW_DEBUG
}

FRigUnit_DebugDrawDebugArrow_Execute()
{
	DECLARE_SCOPE_HIERARCHICAL_COUNTER_RIGUNIT()

#if ENABLE_DRAW_DEBUG
	if (EnableDebug)
	{
		const FVector FixStart = UIKExtensionFunctionLibrary::CastLocationByDebugSpace(ExecuteContext, Setting.DrawDebugSpace, Start);
		const FVector FixEnd = UIKExtensionFunctionLibrary::CastLocationByDebugSpace(ExecuteContext, Setting.DrawDebugSpace, End);
		UKismetSystemLibrary::DrawDebugArrow(ExecuteContext.GetWorld(), FixStart, FixEnd, Size, Setting.Color, Setting.Duration, Thickness);
	}
#endif // ENABLE_DRAW_DEBUG
}


FRigUnit_DebugDrawDebugBox_Execute()
{
	DECLARE_SCOPE_HIERARCHICAL_COUNTER_RIGUNIT()

#if ENABLE_DRAW_DEBUG
	if (EnableDebug)
	{
		const FVector FixCenter = UIKExtensionFunctionLibrary::CastLocationByDebugSpace(ExecuteContext, Setting.DrawDebugSpace, Center);
		const FRotator FixRotation = UIKExtensionFunctionLibrary::CastRotationByDebugSpace(ExecuteContext, Setting.DrawDebugSpace, Rotation);
		UKismetSystemLibrary::DrawDebugBox(ExecuteContext.GetWorld(), FixCenter, Extent, Setting.Color, FixRotation, Setting.Duration, Thickness);
	}
#endif // ENABLE_DRAW_DEBUG
}

FRigUnit_DebugDrawDebugSphere_Execute()
{
	DECLARE_SCOPE_HIERARCHICAL_COUNTER_RIGUNIT()

#if ENABLE_DRAW_DEBUG
	if (EnableDebug)
	{
		const FVector FixCenter = UIKExtensionFunctionLibrary::CastLocationByDebugSpace(ExecuteContext, Setting.DrawDebugSpace, Center);
		UKismetSystemLibrary::DrawDebugSphere(ExecuteContext.GetWorld(), FixCenter, Radius, Segments, Setting.Color, Setting.Duration, Thickness);
	}
#endif // ENABLE_DRAW_DEBUG
}

FRigUnit_DebugDrawDebugCylinder_Execute()
{
	DECLARE_SCOPE_HIERARCHICAL_COUNTER_RIGUNIT()

#if ENABLE_DRAW_DEBUG
	if (EnableDebug)
	{
		const FVector FixStart = UIKExtensionFunctionLibrary::CastLocationByDebugSpace(ExecuteContext, Setting.DrawDebugSpace, Start);
		const FVector FixEnd = UIKExtensionFunctionLibrary::CastLocationByDebugSpace(ExecuteContext, Setting.DrawDebugSpace, End);
		UKismetSystemLibrary::DrawDebugCylinder(ExecuteContext.GetWorld(), FixStart, FixEnd, Radius, Segments, Setting.Color, Setting.Duration, Thickness);
	}
#endif // ENABLE_DRAW_DEBUG
}

FRigUnit_DebugDrawDebugCone_Execute()
{
	DECLARE_SCOPE_HIERARCHICAL_COUNTER_RIGUNIT()

#if ENABLE_DRAW_DEBUG
	if (EnableDebug)
	{
		const FVector FixOrigin = UIKExtensionFunctionLibrary::CastLocationByDebugSpace(ExecuteContext, Setting.DrawDebugSpace, Origin);
		const FVector FixDirection = UIKExtensionFunctionLibrary::CastDirectionByDebugSpace(ExecuteContext, Setting.DrawDebugSpace, Direction);
		UKismetSystemLibrary::DrawDebugCone(ExecuteContext.GetWorld(), FixOrigin, FixDirection, Length, AngleWidth, AngleHeight, Segments, Setting.Color, Setting.Duration, Thickness);
	}
#endif // ENABLE_DRAW_DEBUG
}

FRigUnit_DebugDrawDebugConeInDegrees_Execute()
{
	DECLARE_SCOPE_HIERARCHICAL_COUNTER_RIGUNIT()

#if ENABLE_DRAW_DEBUG
	if (EnableDebug)
	{
		const FVector FixOrigin = UIKExtensionFunctionLibrary::CastLocationByDebugSpace(ExecuteContext, Setting.DrawDebugSpace, Origin);
		const FVector FixDirection = UIKExtensionFunctionLibrary::CastDirectionByDebugSpace(ExecuteContext, Setting.DrawDebugSpace, Direction);
		UKismetSystemLibrary::DrawDebugConeInDegrees(ExecuteContext.GetWorld(), FixOrigin, FixDirection, Length, AngleWidth, AngleHeight, Segments, Setting.Color, Setting.Duration, Thickness);
	}
#endif // ENABLE_DRAW_DEBUG
}

FRigUnit_DebugDrawDebugCapsule_Execute()
{
	DECLARE_SCOPE_HIERARCHICAL_COUNTER_RIGUNIT()

#if ENABLE_DRAW_DEBUG
	if (EnableDebug)
	{
		const FVector FixCenter = UIKExtensionFunctionLibrary::CastLocationByDebugSpace(ExecuteContext, Setting.DrawDebugSpace, Center);
		const FRotator FixRotation = UIKExtensionFunctionLibrary::CastRotationByDebugSpace(ExecuteContext, Setting.DrawDebugSpace, Rotation);
		UKismetSystemLibrary::DrawDebugCapsule(ExecuteContext.GetWorld(), FixCenter, HalfHeight, Radius, FixRotation, Setting.Color, Setting.Duration, Thickness);
	}
#endif // ENABLE_DRAW_DEBUG
}

FRigUnit_DebugDrawDebugPlane_Execute()
{
	DECLARE_SCOPE_HIERARCHICAL_COUNTER_RIGUNIT()

#if ENABLE_DRAW_DEBUG
	if (EnableDebug)
	{
		const FVector FixLocation = UIKExtensionFunctionLibrary::CastLocationByDebugSpace(ExecuteContext, Setting.DrawDebugSpace, Location);
		const FVector FixNormal = UIKExtensionFunctionLibrary::CastDirectionByDebugSpace(ExecuteContext, Setting.DrawDebugSpace, Normal);
		const FPlane Plane = FPlane(FixLocation, FixNormal);
		UKismetSystemLibrary::DrawDebugPlane(ExecuteContext.GetWorld(), Plane, FixLocation, Size, Setting.Color, Setting.Duration);
	}
#endif // ENABLE_DRAW_DEBUG
}
