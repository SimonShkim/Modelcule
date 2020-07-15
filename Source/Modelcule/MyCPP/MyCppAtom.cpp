// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCppAtom.h"

// Sets default values
AMyCppAtom::AMyCppAtom()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create components
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
	Collision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision"));
	
	//Set parenting
	Sphere->SetupAttachment(RootComponent); 
	Collision->SetupAttachment(Sphere);

	//Set material
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/MyModelculeStuff/MyStaticMeshes/MySphere_StaticMesh.MySphere_StaticMesh'"));
	UStaticMesh* SphereMesh = MeshAsset.Object;
	Sphere->SetStaticMesh(SphereMesh);

	//Set Scale
	Collision->SetRelativeScale3D(FVector(1.0f, 1.0f, 0.5f));

	//Overlap settings
	Collision->SetGenerateOverlapEvents(true);

	SetColor();
}

void AMyCppAtom::SetColor()
{
	static ConstructorHelpers::FObjectFinder<UMaterialInstance>Material(TEXT("MaterialInstanceConstant'/Game/MyModelculeStuff/MyMaterials/Colors/MyBlackMat.MyBlackMat'"));
	UMaterialInstance* BlackMat = Material.Object;
	Sphere->SetMaterial(0, BlackMat);
}

void AMyCppAtom::AttachToMe(AActor* OtherA)
{
	
}

// Called when the game starts or when spawned
void AMyCppAtom::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCppAtom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

