// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actors/RiverPickupActor.h"
#include "Actors/RiverActor.h"
#include "RiverPickupSpawnerActor.generated.h"

UCLASS()
class RIVERRIDE_API ARiverPickupSpawnerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARiverPickupSpawnerActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// The type that represents the blueprint we want to spawn instances of
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		TSubclassOf<ARiverPickupActor> RiverPickupActorTemplate;

	// How many should we initially spawn
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		int InitialSpawnAmount;

	// Reference to RiverActor that provides info on where to spawn the river pickups
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		ARiverActor* RiverActor;
};
