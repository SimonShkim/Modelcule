// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Templates/Casts.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/Material.h"
#include "Math/Vector.h"
#include "Materials/MaterialInstance.h"
#include "MyCppBond.generated.h"

UCLASS()
class MODELCULE_API AMyCppBond : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyCppBond();

	//Components
	//Visible Static Mesh
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Cylinder;

	//Components to detect overlap
	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* Collision1;
	
	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* Collision2;

	//Attachment Locations
	UPROPERTY(VisibleAnywhere)
	USceneComponent* End1;
	
	UPROPERTY(VisibleAnywhere)
	USceneComponent* End2;
	
	//Variables
	UPROPERTY(VisibleAnywhere)
	bool IsGrabbed = false;

	//UPROPERTY(VisibleAnywhere)
	//bool IsE1Attached;
	//UPROPERTY(VisibleAnywhere)
	//bool IsE2Attached;

	//Attached Actors
	UPROPERTY(VisibleAnywhere)
	AActor* E1Actor;

	UPROPERTY(VisibleAnywhere)
	AActor* E2Actor;
	
	UPROPERTY(VisibleAnywhere)
	AActor* ParentActor;
	
	//Functions
	UFUNCTION()
	void AttachEnd1(UPrimitiveComponent* OtherComp, AActor* ParentAct, UPrimitiveComponent* thing, int32 OtherIndex, bool FromSweep, const FHitResult& SweepResult);
	void AttachEnd2(UPrimitiveComponent* OtherComp, AActor* ParentAct, UPrimitiveComponent* thing, int32 OtherIndex, bool FromSweep, const FHitResult& SweepResult);
	
	void DetachPawn();

	void SetIsGrabbed(bool status);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
