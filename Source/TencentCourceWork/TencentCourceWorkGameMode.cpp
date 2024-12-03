// Copyright Epic Games, Inc. All Rights Reserved.

#include "TencentCourceWorkGameMode.h"
#include "TencentCourceWorkCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"
#include "TencentCourceWorkPlayerController.h"
#include "TencentCourceWorkPlayerState.h"

ATencentCourceWorkGameMode::ATencentCourceWorkGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;


}

void ATencentCourceWorkGameMode::StartPlay()
{
	Super::StartPlay();

	TArray<AActor*> ActorsWithTag;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "Box", ActorsWithTag);

	//Set [ImportantNum] Important Box. 
	int i = 0;
	while (i < ImportantNum && i < ActorsWithTag.Num() ) 
	{
		int ImportantIndex = FMath::RandRange(1, ActorsWithTag.Num() - 1);
		if (!ActorsWithTag[ImportantIndex]->Tags.Contains("Important"))
		{
			ActorsWithTag[ImportantIndex]->Tags.Add("Important");
			i++;
		}
	}

	//Set Game Timer.
	FTimerHandle handle;
	GetWorld()->GetTimerManager().SetTimer(handle, [this]()
		{
			int i = 0;
			for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
			{
				ATencentCourceWorkPlayerController* PlayerActor = Cast<ATencentCourceWorkPlayerController>(Iterator->Get());
				ATencentCourceWorkPlayerState* playerState = PlayerActor->GetPlayerState<ATencentCourceWorkPlayerState>();
				UE_LOG(LogTemp, Log, TEXT("Player%d Score: %f"), i++, playerState->GetScore());
				SetPause(PlayerActor);
			}
		}, GameTimeLimit, false);
}