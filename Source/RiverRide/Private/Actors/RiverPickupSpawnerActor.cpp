// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/RiverPickupSpawnerActor.h"

// Sets default values
ARiverPickupSpawnerActor::ARiverPickupSpawnerActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARiverPickupSpawnerActor::BeginPlay()
{
	Super::BeginPlay();


	if (RiverPickupActorTemplate)
	{
		if (InitialSpawnAmount == 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("ARiverPickupSpawnerActor::BeginPlay - InitialSpawnAmount should be greater than 0. Please define the property in the UE editor"));
		}

		if (RiverActor) {
			float StartingLocationOfSpline = 0.0f;
			FVector Location = RiverActor->SplineComponent->GetWorldLocationAtDistanceAlongSpline(StartingLocationOfSpline);
			FRotator Rotation = RiverActor->SplineComponent->GetWorldRotationAtDistanceAlongSpline(StartingLocationOfSpline);
			FActorSpawnParameters SpawnParameters;

			for (int I = 0; I < InitialSpawnAmount; I++)
			{
				ARiverPickupActor* SpawnedActor = GetWorld()->SpawnActor<ARiverPickupActor>(RiverPickupActorTemplate, Location, Rotation, SpawnParameters);
				SpawnedActor->RiverActor = RiverActor;
			}
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("ARiverPickupSpawnerActor::BeginPlay - RiverActor is null. Please define the property in the UE editor within the world"));
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("ARiverPickupSpawnerActor::BeginPlay - RiverActorTemplate is null. Please define the property in the UE editor"));
	}
}

// Called every frame
void ARiverPickupSpawnerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

