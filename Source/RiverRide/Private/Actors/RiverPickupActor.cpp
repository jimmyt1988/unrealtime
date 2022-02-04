// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/RiverPickupActor.h"

// Sets default values
ARiverPickupActor::ARiverPickupActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARiverPickupActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARiverPickupActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

