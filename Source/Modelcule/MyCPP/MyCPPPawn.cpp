// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCPPPawn.h"


// Sets default values
AMyCPPPawn::AMyCPPPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Components
	MainSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("MainSceneComponent"));
	RootComponent = MainSceneComponent;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera -> SetupAttachment(RootComponent);
	
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->SetupAttachment(Camera);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh -> SetupAttachment(RootComponent);
	
	Collision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision"));
	Collision->SetupAttachment(Mesh);

	GrabLocation = CreateDefaultSubobject<USceneComponent>(TEXT("GrabLocation"));
	GrabLocation->SetupAttachment(MainSceneComponent);
	
	//Variables
	IsGrabbing = false;
	IsOpenUI = false;

	//StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'

}

//Functions
void AMyCPPPawn::GrabObject() 
{
	
}

AActor* AMyCPPPawn::FindRootObj(AActor* currObj)
{

	return currObj;
}

void AMyCPPPawn::RotateGrabbedObj(FRotator rot)
{

}

// Called when the game starts or when spawned
void AMyCPPPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCPPPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCPPPawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	SetupPlayerInputComponent(PlayerInputComponent);

}

