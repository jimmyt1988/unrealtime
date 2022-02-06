// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidgets/HUDUserWidget.h"
#include "Controllers/MainPlayerController.h"

void UHUDUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (!MainPlayerPlayerState)
	{
		UWorld* World = GetWorld();
		if (World)
		{
			APlayerController* PlayerController = World->GetFirstPlayerController();
			if (PlayerController)
			{
				AMainPlayerController* MainPlayerController = Cast<AMainPlayerController>(PlayerController);
				if (MainPlayerController)
				{
					MainPlayerPlayerState = MainPlayerController->GetPlayerState<AMainPlayerPlayerState>();
				}
			}
		}
	}
}