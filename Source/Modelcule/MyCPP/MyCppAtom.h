// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Math/Vector.h"
#include "Engine/StaticMesh.h"
#include "MyCppAtom.generated.h"

UCLASS()
class MODELCULE_API AMyCppAtom : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyCppAtom();

	//Components
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Sphere;

	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* Collision;
	//Variables


	//Functions
	void SetColor();

	void AttachToMe(AActor* OtherA);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
