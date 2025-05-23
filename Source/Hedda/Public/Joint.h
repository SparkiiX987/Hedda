#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Member.h"
#include "Joint.generated.h"


UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class HEDDA_API UJoint : public UActorComponent
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JointRefs")
	UMember* attachedMember;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JointRefs")
	USkeletalMeshComponent* SkeletalMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JointRefs")
	FName boneName;
};
