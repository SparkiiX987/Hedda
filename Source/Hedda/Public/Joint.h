#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Member.h"
#include "UObject/ObjectPtr.h"
#include "Joint.generated.h"


UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class HEDDA_API UJoint : public USceneComponent
{
	GENERATED_BODY()

public:	
	UJoint();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable, Category = "Joint")
	void Dismember();
	UPROPERTY(EditAnyWhere, Category = "JointRefs", meta = (AllowPrivateAccess = "true"))
	UMember* attachedMember;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JointRefs")
	USkeletalMeshComponent* SkeletalMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JointRefs")
	FName boneName;
};
