// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/Vector.h"
#include "GameFramework/Actor.h"
#include "MyCppMoveComp.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MODELCULE_API UMyCppMoveComp : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyCppMoveComp();

	//Variables
	UPROPERTY(VisibleAnywhere)
	float MoveSpeed;

	UPROPERTY(VisibleAnywhere)
	float TurnSpeed;

	//Functions
	UFUNCTION(BlueprintCallable)
	void Move(float UDInput, float LRInput, float FBInput);

	UFUNCTION(BlueprintCallable)
	void Turn(float UDInput, float LRInput);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
