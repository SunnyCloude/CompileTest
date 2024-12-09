// Fill out your copyright notice in the Description page of Project Settings.


#include "TencentCourceWorkUserWidget.h"
#include "TencentCourceWorkPlayerState.h"

float UTencentCourceWorkUserWidget::GetPlayerScore()
{
	return GetOwningPlayer()->GetPlayerState<ATencentCourceWorkPlayerState>()->GetScore();
}
