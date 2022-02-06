// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/MainGameHUD.h"

void AMainGameHUD::ShowHUD()
{
	Super::ShowHUD();

	if (HUDUserWidgetClass && !HUDUserWidget)
	{
		HUDUserWidget = CreateWidget<UHUDUserWidget>(GetWorld(), HUDUserWidgetClass);
	}

	if (!HUDUserWidget->IsInViewport())
	{
		HUDUserWidget->AddToPlayerScreen();
	}
}