// Fill out your copyright notice in the Description page of Project Settings.


#include "TencentCourceWorkPlayerState.h"

ATencentCourceWorkPlayerState::ATencentCourceWorkPlayerState()
{
	SetScore(0);
}

void ATencentCourceWorkPlayerState::IncreaseScore()
{
	float newScore = hitScore + GetScore();
	SetScore(newScore);
	UE_LOG(LogTemp, Log, TEXT("In PlayerState: New Score: %f"), newScore);
}