// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "Math/Rotator.h"
#include "MyCPPPawn.generated.h"


UCLASS()
class MODELCULE_API AMyCPPPawn : public APawn
{
	GENERATED_BODY()
public:
	// Sets default values for this pawn's properties
	AMyCPPPawn();

	//Components
	UPROPERTY(VisibleAnywhere)
	USceneComponent* MainSceneComponent;
	
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere)
	UArrowComponent* Arrow;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* Collision;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* GrabLocation;


	//Variables
	UPROPERTY(Category = Default, BlueprintReadOnly)
	bool IsGrabbing;

	UPROPERTY(Category=Default, BlueprintReadOnly)
	bool IsOpenUI;

	//Fuctions
	UFUNCTION(BlueprintCallable)
	void GrabObject();

	UFUNCTION(BlueprintCallable)
	AActor* FindRootObj(AActor* currObj);

	UFUNCTION(BlueprintCallable)
		void RotateGrabbedObj(FRotator rot);



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
