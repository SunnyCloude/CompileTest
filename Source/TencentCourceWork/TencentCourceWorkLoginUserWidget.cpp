// Fill out your copyright notice in the Description page of Project Settings.


#include "TencentCourceWorkLoginUserWidget.h"

void UTencentCourceWorkLoginUserWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (ButtonLogin)
	{
		ButtonLogin->OnClicked.AddDynamic(this, &UTencentCourceWorkLoginUserWidget::Login);
	}

	GetOwningPlayer()->SetPause(true);
	GetOwningPlayer()->bShowMouseCursor = true;
}

void UTencentCourceWorkLoginUserWidget::Login()
{
	FString InputUserName = EditableTextBoxUserName->GetText().ToString();
	FString InputPassword = EditableTextBoxPassword->GetText().ToString();

	if (UserName.Equals(InputUserName) && Password.Equals(InputPassword))
	{
		UE_LOG(LogTemp, Display, TEXT("User %s Login Success!"), *InputUserName);
		TextBlockLoginResult->SetText(FText::FromString(TEXT("登录成功！")));

		GetOwningPlayer()->SetPause(false);
		GetOwningPlayer()->bShowMouseCursor = false;
		this->SetVisibility(ESlateVisibility::Hidden);
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("Login Failure!"));
		EditableTextBoxPassword->SetText(FText());
		TextBlockLoginResult->SetText(FText::FromString(TEXT("登录失败，请检查用户名和密码。")));
	}
}