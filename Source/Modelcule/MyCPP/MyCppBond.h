// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Templates/Casts.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/Material.h"
#include "Math/Vector.h"
#include "MyCppBond.generated.h"

UCLASS()
class MODELCULE_API AMyCppBond : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyCppBond();

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
	
	UPROPERTY(VisibleAnywhere)
	bool IsGrabbed = false;


	
	//Functions
	void AttachGrabbedObj(AActor* ParentActor, bool IsEnd1);

	void DetachPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
