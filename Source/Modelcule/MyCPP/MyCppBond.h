// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Templates/Casts.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/Material.h"
#include "MyCppBond.generated.h"

UCLASS()
class MODELCULE_API AMyCppBond : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyCppBond();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Cylinder;

	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* Collision;

	UPROPERTY(VisibleAnywhere)
	bool IsGrabbed = false;

	//UPROPERTY(VisibleAnywhere)
	//UMaterialInterface* BlackMat;
	
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
