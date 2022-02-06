// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UserWidgets/StartScreenHUDUserWidget.h"
#include "StartScreenHUD.generated.h"

/**
 *
 */
UCLASS()
class RIVERRIDE_API AStartScreenHUD : public AHUD
{
	GENERATED_BODY()

public:

	void ShowHUD() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		TSubclassOf<UStartScreenHUDUserWidget> StartScreenHUDUserWidgetClass;

	UPROPERTY()
		UStartScreenHUDUserWidget* StartScreenHUDUserWidget;

};
