// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StartScreenHUDUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class RIVERRIDE_API UStartScreenHUDUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Custom")
		void StartGame();

};
