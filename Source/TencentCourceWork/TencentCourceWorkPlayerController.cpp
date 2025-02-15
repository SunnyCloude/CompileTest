// Copyright Epic Games, Inc. All Rights Reserved.


#include "TencentCourceWorkPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"

void ATencentCourceWorkPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}

	if (LoginUIClass)
	{
		LoginUI = Cast<UTencentCourceWorkLoginUserWidget>(CreateWidget<UUserWidget>(this, LoginUIClass, FName("LoginUI")));
		if (LoginUI)
		{
			LoginUI->AddToViewport();
		}
	}
}

void ATencentCourceWorkPlayerController::DisplayGameOverUI()
{
	if (GameOverUIClass)
	{
		GameOverUI = Cast<UTencentCourceWorkUserWidget>(CreateWidget<UUserWidget>(this, GameOverUIClass, FName("GameOverUI")));
		if (GameOverUI)
		{
			GameOverUI->AddToViewport();
		}
	}
}
