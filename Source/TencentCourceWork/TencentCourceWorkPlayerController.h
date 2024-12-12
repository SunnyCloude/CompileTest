// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TencentCourceWorkUserWidget.h"
#include "TencentCourceWorkLoginUserWidget.h"
#include "GameFramework/PlayerController.h"
#include "TencentCourceWorkPlayerController.generated.h"

class UInputMappingContext;

/**
 *
 */
UCLASS()
class TENCENTCOURCEWORK_API ATencentCourceWorkPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:

	/** Input Mapping Context to be used for player input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;

	// Begin Actor interface
protected:

	virtual void BeginPlay() override;

	// End Actor interface
public:
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> GameOverUIClass;

	UPROPERTY()
	UTencentCourceWorkUserWidget* GameOverUI;
	
	UFUNCTION()
	void DisplayGameOverUI();

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> LoginUIClass;

	UPROPERTY()
	UTencentCourceWorkLoginUserWidget* LoginUI;
};
