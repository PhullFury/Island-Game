// Fill out your copyright notice in the Description page of Project Settings.


#include "IslandMan.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AIslandMan::AIslandMan()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(34.f, 60.f);

	FPSCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FPS Camera"));
	FPSCamera->SetupAttachment(GetCapsuleComponent());
	FPSCamera->SetRelativeLocation(0.f, 0.f, 40.f);
	FPSCamera->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void AIslandMan::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AIslandMan::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AIslandMan::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveVertical", this, &AIslandMan::MoveVertical);
	PlayerInputComponent->BindAxis("MoveSideways", this, &AIslandMan::MoveSideways);
	PlayerInputComponent->BindAxis("TurnVertical", this, &AIslandMan::TurnVertical);
	PlayerInputComponent->BindAxis("TurnSideways", this, &AIslandMan::TurnSideways);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AIslandMan::StartSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AIslandMan::StopSprint);
}

void AIslandMan::MoveVertical(float AxisValue)
{
	AddMovementInput(GetActorForwardVector(), AxisValue * CurrentSpeed);
}

void AIslandMan::MoveSideways(float AxisValue)
{
	AddMovementInput(GetActorRightVector(), AxisValue * CurrentSpeed);
}

void AIslandMan::TurnVertical(float AxisValue)
{
	AddControllerPitchInput(AxisValue * TurnRate * GetWorld()->GetDeltaSeconds());
}

void AIslandMan::TurnSideways(float AxisValue)
{
	AddControllerYawInput(AxisValue * TurnRate * GetWorld()->GetDeltaSeconds());
}

void AIslandMan::StartSprint()
{
	UE_LOG(LogTemp, Warning, TEXT("Sprint iniated"));
}

void AIslandMan::StopSprint()
{
	UE_LOG(LogTemp, Warning, TEXT("Sprint ended"));
}