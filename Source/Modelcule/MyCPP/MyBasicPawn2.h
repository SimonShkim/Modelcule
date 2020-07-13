// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
//for line trace capabilities
#include "Engine/World.h"
//choose object type for line trace
#include "Engine/EngineTypes.h"
#include "Misc/CoreMiscDefines.h"
#include "Components/PrimitiveComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/SceneComponent.h"
#include "CollisionQueryParams.h"
#include "Math/Color.h"
#include "Engine/Public/DrawDebugHelpers.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Math/Color.h"
#include "MyBasicPawn2.generated.h"

UCLASS()
class MODELCULE_API AMyBasicPawn2 : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyBasicPawn2();


	//Variables
	UPROPERTY(EditAnywhere)
	USceneComponent* MyMesh;

	UPROPERTY(EditAnywhere)
	USceneComponent* GrabLoc;

	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
	UArrowComponent* Arrow;

	UPROPERTY(EditAnywhere)
	AActor* OtherGuy;

	FVector CurrentVel;
	FRotator CurrentRot;

	bool IsGrabbing = false;

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
