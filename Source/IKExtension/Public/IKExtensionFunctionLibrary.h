#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "IKExtensionFunctionLibrary.generated.h"

enum class EDrawDebugSpace :uint8;
struct FRigVMExecuteContext;

UCLASS()
class IKEXTENSION_API UIKExtensionFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static FVector CastLocationByDebugSpace(struct FRigVMExecuteContext ExecuteContext, enum EDrawDebugSpace DebugSpace, FVector Location);
	static FVector CastDirectionByDebugSpace(struct FRigVMExecuteContext ExecuteContext, enum EDrawDebugSpace DebugSpace, FVector Direction);
	static FRotator CastRotationByDebugSpace(struct FRigVMExecuteContext ExecuteContext, enum EDrawDebugSpace DebugSpace, FQuat Rotation);
};
