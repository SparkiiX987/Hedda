#include "GameModeDefaultPawnOverridable.h"

void AGameModeDefaultPawnOverridable::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
    Super::InitGame(MapName, Options, ErrorMessage);

    if (GEngine)
        GEngine->AddOnScreenDebugMessage(1, 10.0f, FColor::Blue, FString::Printf(TEXT("Options : %s"), *Options));

    pawnPath = UGameplayStatics::ParseOption(Options, TEXT("OverridePawn"));
}

UClass* AGameModeDefaultPawnOverridable::GetDefaultPawnClassForController_Implementation(AController* InController)
{
    if (!pawnPath.IsEmpty())
    {
        FSoftClassPath SoftPath(pawnPath);
        UClass* LoadedClass = SoftPath.TryLoadClass<APawn>();

        if (LoadedClass)
        {
            return LoadedClass;
        }
    }

    return Super::GetDefaultPawnClassForController_Implementation(InController);
}