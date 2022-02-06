// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/MainPlayerController.h"
#include "Characters/MainCharacter.h"

AMainPlayerController::AMainPlayerController()
{
	SetShowMouseCursor(true);
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
}

void AMainPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (InputComponent)
    {
        // Bind an action to it
        InputComponent->BindAxis
        (
            "Movement", // The input binding (specified in DefaultInput.ini)
            this, // The object that is going to react to the input
            &AMainPlayerController::MovementAxisEvent // The function that will fire when input is received
        );
    }
}

#pragma optimize("", off)
void AMainPlayerController::MovementAxisEvent(float AxisValue)
{
    AMainCharacter* MainCharacter = GetPawn<AMainCharacter>();
    if (MainCharacter)
    {
        MainCharacter->Move(AxisValue);
    }    
}
#pragma optimize("", on)