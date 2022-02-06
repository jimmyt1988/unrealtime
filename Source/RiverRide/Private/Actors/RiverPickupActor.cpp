// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/RiverPickupActor.h"
#include "Controllers/MainPlayerController.h"
#include "PlayerStates/MainPlayerPlayerState.h"

// Sets default values
ARiverPickupActor::ARiverPickupActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(FName("CapsuleComponent"));
	SetRootComponent(CapsuleComponent);

	if (CapsuleComponent) {
		CapsuleComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
	}
}

// Called when the game starts or when spawned
void ARiverPickupActor::BeginPlay()
{
	Super::BeginPlay();

	if (CapsuleComponent)
	{
		CapsuleComponent->OnClicked.AddDynamic(this, &ARiverPickupActor::OnClicked);
	}

}

// Called every frame
void ARiverPickupActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (RiverActor)
	{
		if (RiverSpeed == 0.0f)
		{
			UE_LOG(LogTemp, Warning, TEXT("ARiverPickupActor::Tick - RiverSpeed is 0.0f. Did you mean to set this to something else?"));
		}

		if (RiverActor->SplineComponent->GetSplineLength() > DistanceAlongSpline)
		{
			FVector LocationAlongSpline = RiverActor->SplineComponent->GetLocationAtDistanceAlongSpline(DistanceAlongSpline, ESplineCoordinateSpace::World);
			SetActorLocation(LocationAlongSpline);
			DistanceAlongSpline += RiverSpeed * DeltaTime;
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("ARiverPickupActor::Tick - RiverActor has reached the end of the spline."));
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("ARiverPickupActor::Tick - RiverActor is null."));
	}
}

void ARiverPickupActor::OnClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{
	if (!IsActorBeingDestroyed())
	{
		RiverActorWasPickedUp();
	}
}

#pragma optimize("", off)
void ARiverPickupActor::RiverActorWasPickedUp_Implementation()
{
	if (!HasBeenPickedUp)
	{
		UWorld* World = GetWorld();
		if (World)
		{
			APlayerController* PlayerController = World->GetFirstPlayerController();
			if (PlayerController)
			{
				AMainPlayerController* MainPlayerController = Cast<AMainPlayerController>(PlayerController);
				if (MainPlayerController)
				{
					AMainPlayerPlayerState* MainPlayerPlayerState = MainPlayerController->GetPlayerState<AMainPlayerPlayerState>();
					if (MainPlayerPlayerState)
					{
						float CurrentScore = MainPlayerPlayerState->GetScore();
						CurrentScore += 1;
						MainPlayerPlayerState->SetScore(CurrentScore);
						HasBeenPickedUp = true;
						CapsuleComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
					}
				}
			}
		}
	}
}
#pragma optimize("", off)

void ARiverPickupActor::SignalThatPickupActionNowComplete()
{
	if (HasBeenPickedUp)
	{
		Destroy();
	}
}