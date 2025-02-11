// Fill out your copyright notice in the Description page of Project Settings.
#include "MyCppMoveComp.h"

// Sets default values for this component's properties
UMyCppMoveComp::UMyCppMoveComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	/*SetMoveSpeed(5.0);
	SetTurnSpeed(5.0);*/
	// ...
}




//Functions
//Handles all translational movement of the pawn
void UMyCppMoveComp::Move(float UDInput, float LRInput, float FBInput)
{
	//FVector ActorLoc = FVector(0.0, 0.0, 0.0);
	//AActor::SetActorLocation(FVector(0.0, 0.0, 0.0));
	AActor* Owner = UActorComponent::GetOwner();
	FVector FLoc = Owner->GetActorForwardVector();
	FVector ULoc =  Owner->GetActorUpVector();
	FVector RLoc = Owner->GetActorRightVector();
	FVector CurrLoc = Owner->GetActorLocation();

	float FBMove = FBInput * MoveSpeed;
	float LRMove = LRInput * MoveSpeed;
	float UDMove = UDInput * MoveSpeed;

	Owner->SetActorLocation((UMyCppMoveComp::MoveSpeed * FLoc) + CurrLoc);
}



void UMyCppMoveComp::Turn(float UDInput, float LRInput)
{
	AActor* Owner = UActorComponent::GetOwner();
	FRotator UDRot = FRotator(0.0, (UDInput * TurnSpeed), 0.0);
	FRotator LRRot = FRotator(0.0, 0.0, (LRInput * TurnSpeed));
}

//void SetMoveSpeed(float ms)
//{
//	/*MoveSpeed = ms;*/
//	return;
//}
//
//void SetTurnSpeed(float ts)
//{
//	/*TurnSpeed = ts;*/
//	return;
//}

// Called when the game starts
void UMyCppMoveComp::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMyCppMoveComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

