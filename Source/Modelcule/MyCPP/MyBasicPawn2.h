// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

//for line trace capabilities
#include "Engine/World.h"

//choose object type for line trace
#include "Engine/EngineTypes.h"

//Actor Components
#include "Camera/CameraComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/SceneComponent.h"
#include "Components/InputComponent.h"
#include "Components/EditableText.h"

//My Classes
//#include "MyCppAtom.h"
//#include "MyCppBond.h"
//#include "MyCppUserWidget.h"

#include "CollisionQueryParams.h"
#include "Math/Color.h"
#include "Engine/Public/DrawDebugHelpers.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Math/Color.h"
#include "Misc/CoreMiscDefines.h"

//UI Stuff
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Templates/SubclassOf.h"
#include "UObject/UObjectGlobals.h"
#include "UObject/ConstructorHelpers.h"
#include "UObject/Class.h"
#include "Engine/LocalPlayer.h"
//#include "Blueprint/UserWidget.h"

#include "MyBasicPawn2.generated.h"

//trying to fix circular dependencies
class AMyCppAtom;
class AMyCppBond;
class UMyCppUserWidget;

UCLASS()
class MODELCULE_API AMyBasicPawn2 : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyBasicPawn2();


	//Variables
	UPROPERTY(EditAnywhere, Category = "Component")
	USceneComponent* MyMesh;

	UPROPERTY(EditAnywhere, Category = "Component")
	USceneComponent* GrabLoc;

	UPROPERTY(EditAnywhere, Category = "Component")
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "Component")
	UArrowComponent* Arrow;

	UPROPERTY(EditAnywhere, Category = "OtherStuff")
	AActor* OtherGuy;

	//UI Things
	//class
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UMyCppUserWidget> TheBPUI;
	//instance
	UPROPERTY(EditAnywhere, Category = "UI")
	UMyCppUserWidget* MyUI;


	FVector CurrentVel;
	FRotator CurrentRot;

	bool IsGrabbing = false;

	//Functions
	UFUNCTION()
	void RotateLR(float input);
	UFUNCTION()
	void RotateUD(float input);
	UFUNCTION()
	void RotateHeldObj(FRotator InRot);

	void MoveFB(float input);
	void MoveLR(float input);
	void MoveUD(float input);

	void TurnLR(float input);
	void TurnUD(float input);

	void LineTrace();
	
	UFUNCTION()
	AActor* GetRoot(AActor* HitActor);

	UFUNCTION()
	void OpenUI();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



	
};
