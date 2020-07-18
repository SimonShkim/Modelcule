// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//Actor Components
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PrimitiveComponent.h"

#include "Engine/EngineTypes.h"
#include "Templates/Casts.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/Material.h"
#include "Math/Vector.h"
#include "Materials/MaterialInstance.h"
//#include "MyBasicPawn2.h"
//#include "MyCppAtom.h"
#include "MyCppBond.generated.h"

//fixing circular dependency
class AMyBasicPawn2;
class AMyCppAtom;
class UMyCppUserWidget;

UCLASS()
class MODELCULE_API AMyCppBond : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyCppBond();

	//Components
	//Visible Static Mesh
	UPROPERTY(EditAnywhere, Category="Component")
	UStaticMeshComponent* Cylinder;

	//Components to detect overlap
	UPROPERTY(VisibleAnywhere, Category = "Component")
	UCapsuleComponent* Collision1;
	
	UPROPERTY(VisibleAnywhere, Category = "Component")
	UCapsuleComponent* Collision2;

	//Attachment Locations
	UPROPERTY(VisibleAnywhere, Category = "Component")
	USceneComponent* End1;
	
	UPROPERTY(VisibleAnywhere, Category = "Component")
	USceneComponent* End2;
	
	//Variables
	UPROPERTY(EditAnywhere)
	bool IsGrabbed = false;

	//UPROPERTY(VisibleAnywhere)
	//bool IsE1Attached;
	//UPROPERTY(VisibleAnywhere)
	//bool IsE2Attached;

	//Attached Actors
	UPROPERTY(EditAnywhere)
	AActor* E1Actor;

	UPROPERTY(EditAnywhere)
	AActor* E2Actor;
	
	UPROPERTY(EditAnywhere)
	AActor* ParentActor;
	
	//Functions
	UFUNCTION()
	void AttachLogic(UPrimitiveComponent* TouchedComp, AActor* ParentAct, UPrimitiveComponent* OtherComp, int32 OtherIndex, bool FromSweep, const FHitResult& SweepResult);

	void AttachEnd1(UPrimitiveComponent* TouchedComp, AActor* ParentAct, UPrimitiveComponent* OtherComp, int32 OtherIndex, bool FromSweep, const FHitResult& SweepResult);
	void AttachEnd2(UPrimitiveComponent* TouchedComp, AActor* ParentAct, UPrimitiveComponent* OtherComp, int32 OtherIndex, bool FromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	AActor*& GetEndAttActor(USceneComponent* End);
	void	SetEndAttActor(USceneComponent* End);

	void DetachPawn();
	void DetachEnd1Obj();
	void DetachEnd2Obj();

	void SetIsGrabbed(bool status);

	AActor* FindRoot();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
