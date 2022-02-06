// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/MainCharacter.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCharacterMovement()->GravityScale = 0.0f;
	AutoReceiveInput = EAutoReceiveInput::Player0;
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (RiverActor)
	{
		FVector LocationAlongSpline = RiverActor->SplineComponent->GetLocationAtDistanceAlongSpline(0.0f, ESplineCoordinateSpace::World);
		SetActorLocation(LocationAlongSpline);
	}
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMainCharacter::Move(float AxisValue)
{
	if (RiverActor)
	{
		FVector LocationAlongSpline = RiverActor->SplineComponent->GetLocationAtDistanceAlongSpline(0.0f, ESplineCoordinateSpace::World);
		LocationAlongSpline.X += AxisValue + 100;
		SetActorLocation(LocationAlongSpline);
	}
}