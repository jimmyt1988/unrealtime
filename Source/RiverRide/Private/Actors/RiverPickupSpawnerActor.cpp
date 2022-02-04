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
	
	FVector Location = FVector(0.0f, 0.0f, 0.0);
	FRotator Rotation = FRotator(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnParameters;

	if (RiverPickupActorTemplate)
	{
		GetWorld()->SpawnActor<ARiverPickupActor>(RiverPickupActorTemplate, Location, Rotation, SpawnParameters);
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

