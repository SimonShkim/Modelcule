// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Math/Vector.h"
#include "Engine/StaticMesh.h"
#include "MyCppBond.h"
#include "MyCppAtom.generated.h"

class AMyBasicPawn2;
class AMyCppBond;
class UMyCppUserWidget;


UCLASS()
class MODELCULE_API AMyCppAtom : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyCppAtom();

	//Components
	UPROPERTY(EditAnywhere, Category = "Component")
	UStaticMeshComponent* Sphere;

	UPROPERTY(EditAnywhere, Category = "Component")
	UCapsuleComponent* Collision;

	UPROPERTY(EditAnywhere, Category = "Component")
	USceneComponent* AttachLoc;
	//Variables
	UPROPERTY(EditAnywhere, Category = "Variables")
	AActor* ParentActor;

	//Functions
	UFUNCTION()
	void SetParentActor(AActor* parent);

	void SetColor();

	void AttachToMe(AActor* OtherA);

	UFUNCTION()
	AActor* FindRoot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
