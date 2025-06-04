// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Kismet/GameplayStatics.h"
#include "GameModeDefaultPawnOverridable.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class HEDDA_API AGameModeDefaultPawnOverridable : public AGameMode
{ 
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<APawn> overridPawnClass;

protected:
	FString pawnPath;
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	virtual UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override;
};
