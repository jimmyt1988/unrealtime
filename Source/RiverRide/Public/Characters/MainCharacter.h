// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Actors/RiverActor.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MainCharacter.generated.h"

UCLASS()
class RIVERRIDE_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Reference to RiverActor that provides info on where the spline is that we are moving across
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		ARiverActor* RiverActor;

	UFUNCTION(Category = "Custom")
		void Move(float AxisValue);

};
