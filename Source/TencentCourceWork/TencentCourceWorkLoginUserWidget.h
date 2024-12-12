// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/EditableTextBox.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TencentCourceWorkLoginUserWidget.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable, BlueprintType, ClassGroup = UI)
class TENCENTCOURCEWORK_API UTencentCourceWorkLoginUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category="Login")
	FString UserName;

	UPROPERTY(EditAnywhere, Category = "Login")
	FString Password;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UEditableTextBox* EditableTextBoxUserName;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UEditableTextBox* EditableTextBoxPassword;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* ButtonLogin;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* TextBlockLoginResult;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UProgressBar* ProgressBarLoadGame;

	virtual void NativeOnInitialized() override;

private:
	UFUNCTION(BlueprintCallable, Category="TencentCourceWorkWidget")
	void Login();
};
