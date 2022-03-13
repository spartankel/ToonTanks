// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Tank.h"

ATank::ATank() : Speed(5.f)
{
	CameraArmComp = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	CameraArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComp->SetupAttachment(CameraArmComp);
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
}

void ATank::Move(float Direction)
{
	UE_LOG(LogTemp, Log, TEXT("Received Move Value of %f to %s"), Direction, *this->GetName());
	FVector DeltaLocation(Speed, 0, 0);
	DeltaLocation.X *= Direction;
	AddActorLocalOffset(DeltaLocation);
}