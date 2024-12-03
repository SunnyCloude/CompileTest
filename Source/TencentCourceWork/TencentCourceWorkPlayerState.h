// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "TencentCourceWorkPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class TENCENTCOURCEWORK_API ATencentCourceWorkPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=GameSetting)
	float hitScore = 1.0;
	
	void IncreaseScore();
};
