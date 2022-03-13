// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BasePawn.h"
#include "CoreMinimal.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void Move(float);
	// Called to bind functionality to input

public:
	UPROPERTY(EditDefaultsOnly)
	float Speed;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "CPP Controlled", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraArmComp;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "CPP Controlled", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComp;
};
