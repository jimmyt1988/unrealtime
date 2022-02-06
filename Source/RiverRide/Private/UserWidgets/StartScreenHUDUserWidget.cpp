// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidgets/StartScreenHUDUserWidget.h"
#include "GameModes/StartScreenGameMode.h"
#include "Kismet/GameplayStatics.h"

void UStartScreenHUDUserWidget::StartGame()
{
	UWorld* World = GetWorld();
	if (World)
	{
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(World);
		if (GameMode)
		{
			AStartScreenGameMode* StartScreenGameMode = Cast<AStartScreenGameMode>(GameMode);
			if (StartScreenGameMode)
			{
				UGameplayStatics::OpenLevel(World, StartScreenGameMode->MainLevelName);
			}
		}
	}
}