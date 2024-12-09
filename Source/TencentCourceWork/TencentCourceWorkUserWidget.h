// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TencentCourceWorkUserWidget.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable, BlueprintType, ClassGroup = UI)
class TENCENTCOURCEWORK_API UTencentCourceWorkUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category="TencentCourceWorkWidget")
	float GetPlayerScore();
};
