// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCPPPawn.h"

// Sets default values
AMyCPPPawn::AMyCPPPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCPPPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCPPPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCPPPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

