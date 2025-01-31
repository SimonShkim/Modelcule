// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
//for line trace capabilities
#include "Engine/World.h"
//choose object type for line trace
#include "Engine/EngineTypes.h"
#include "CollisionQueryParams.h"
#include "Math/Color.h"
#include "Kismet/KismetSystemLibrary.h"
#include "MyBasicPawn.generated.h"

UCLASS()
class MODELCULE_API AMyBasicPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyBasicPawn();


	//Variables
	UPROPERTY(EditAnywhere)
		USceneComponent* Mesh;

	UPROPERTY(EditAnywhere)


	FVector CurrentVel;
	FRotator CurrentRot;
	//Functions
	void MoveFB(float input);
	void MoveLR(float input);
	void MoveUD(float input);

	void TurnLR(float input);
	void TurnUD(float input);

	void LineTrace();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



	
};
