// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actors/RiverActor.h"
#include "Components/CapsuleComponent.h"
#include "RiverPickupActor.generated.h"

//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRiverActorWasPickedUpDelegate);

UCLASS()
class RIVERRIDE_API ARiverPickupActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARiverPickupActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		bool HasBeenPickedUp;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		float RiverSpeed;

	// Reference to RiverActor that provides info on where the spline is that we are moving across
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		ARiverActor* RiverActor;

	// Distance that this pickup has travelled
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		float DistanceAlongSpline;

	// Collision sphere that reacts to pick up events (click events)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom")
		UCapsuleComponent* CapsuleComponent;

	// Raised when someone clicks the pickup actor
	//UPROPERTY(BlueprintAssignable, Category = "Custom")
	//	FRiverActorWasPickedUpDelegate RiverActorWasPickedUpDelegate;

	UFUNCTION(Category = "Custom")
		void OnClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed);

	UFUNCTION(BlueprintNativeEvent, Category = "Custom")
		void RiverActorWasPickedUp();

	// Some visual effects may occur. We only want to delete this actor once all that has finished
	UFUNCTION(BlueprintCallable, Category = "Custom")
		void SignalThatPickupActionNowComplete();
};
