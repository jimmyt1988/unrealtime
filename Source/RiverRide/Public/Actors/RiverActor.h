// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "Components/SceneComponent.h"
#include "RiverActor.generated.h"

// This serves as a container for all things related to the management of the river and pickups etc
UCLASS()
class RIVERRIDE_API ARiverActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARiverActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// The spline that represents the river
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		USceneComponent* SceneComponent;

	// The spline that represents the river
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		USplineComponent* SplineComponent;

};
