// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerStates/MainPlayerPlayerState.h"
#include "HUDUserWidget.generated.h"

/**
 *
 */
UCLASS()
class RIVERRIDE_API UHUDUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Custom")
		AMainPlayerPlayerState* MainPlayerPlayerState;
};
