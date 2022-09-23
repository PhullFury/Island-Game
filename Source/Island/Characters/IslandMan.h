// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "IslandMan.generated.h"

class UCameraComponent;

UCLASS()
class ISLAND_API AIslandMan : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AIslandMan();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* FPSCamera;
	UPROPERTY(EditAnywhere, Category = "Movement", meta = (AllowPrivateAccess = "true"))
		float IslandManSpeed = 600.f;
	UPROPERTY(EditAnywhere, Category = "Movement", meta = (AllowPrivateAccess = "true"))
		float TurnRate = 50.f;
	UPROPERTY(EditAnywhere, Category = "Movement", meta = (AllowPrivateAccess = "true"))
		float SpeedRate = 1.f;
	UPROPERTY(EditAnywhere, Category = "Movement", meta = (AllowPrivateAccess = "true"))
		float MaxMultiplier = 1.5;
	UPROPERTY(EditAnywhere, Category = "Debug", meta = (AllowPrivateAccess = "true"))
		bool bShowDebug = false;

	void MoveVertical(float AxisValue);
	void MoveSideways(float AxisValue);
	void TurnVertical(float AxisValue);
	void TurnSideways(float AxisValue);
	void StartSprint();
	void StopSprint();
	void SetSpeed(float DeltaTime);

	bool bIsSprinting;
	float CurrentMultiplier;
};