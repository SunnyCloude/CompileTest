// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TencentCourceWorkGameMode.generated.h"

UCLASS(minimalapi)
class ATencentCourceWorkGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATencentCourceWorkGameMode();
	virtual void StartPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GameSetting)
	int ImportantNum = 3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GameSetting)
	float GameTimeLimit = 20.0;
};



