// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/StartScreenHUD.h"


void AStartScreenHUD::ShowHUD()
{
	Super::ShowHUD();

	if (StartScreenHUDUserWidgetClass && !StartScreenHUDUserWidget)
	{
		StartScreenHUDUserWidget = CreateWidget<UStartScreenHUDUserWidget>(GetWorld(), StartScreenHUDUserWidgetClass);
	}

	if (StartScreenHUDUserWidget)
	{
		if (!StartScreenHUDUserWidget->IsInViewport())
		{
			StartScreenHUDUserWidget->AddToPlayerScreen();
		}
	}
}