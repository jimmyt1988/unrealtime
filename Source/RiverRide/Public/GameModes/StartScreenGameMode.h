// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "StartScreenGameMode.generated.h"

/**
 * 
 */
UCLASS()
class RIVERRIDE_API AStartScreenGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		FName MainLevelName;

};
