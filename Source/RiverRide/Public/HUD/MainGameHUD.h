// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UserWidgets/HUDUserWidget.h"
#include "MainGameHUD.generated.h"

/**
 * 
 */
UCLASS()
class RIVERRIDE_API AMainGameHUD : public AHUD
{
	GENERATED_BODY()

public:

	void ShowHUD() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		TSubclassOf<UHUDUserWidget> HUDUserWidgetClass;

	UPROPERTY()
		UHUDUserWidget* HUDUserWidget;
	
};
