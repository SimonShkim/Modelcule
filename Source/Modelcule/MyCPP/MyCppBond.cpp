// Fill out your copyright notice in the Description page of Project Settings.

#include "Materials/MaterialInstance.h"
#include "MyCppBond.h"

// Sets default values
AMyCppBond::AMyCppBond()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//Create
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	Cylinder = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cylinder"));

	Collision1 = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision1"));
	Collision2 = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision2"));
	
	End1 = CreateDefaultSubobject<USceneComponent>(TEXT("End1"));
	End2 = CreateDefaultSubobject<USceneComponent>(TEXT("End2"));

	//Set Parenting
	Cylinder->SetupAttachment(RootComponent);

	Collision1->SetupAttachment(Cylinder);
	Collision2->SetupAttachment(Cylinder);
	
	End1->SetupAttachment(Collision1);
	End2->SetupAttachment(Collision2);

	//Set Static Mesh used by static mesh component
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/MyModelculeStuff/MyStaticMeshes/MyCylinder_StaticMesh.MyCylinder_StaticMesh'"));
	UStaticMesh* CylinderMesh = MeshAsset.Object;
	Cylinder->SetStaticMesh(CylinderMesh);
	
	//Set material of static mesh component
	static ConstructorHelpers::FObjectFinder<UMaterialInstance>Material(TEXT("MaterialInstanceConstant'/Game/MyModelculeStuff/MyMaterials/Colors/MyBlackMat.MyBlackMat'"));
	UMaterialInstance* BlackMat = Material.Object;
	Cylinder->SetMaterial(0, BlackMat);

	//Set Scale
	RootComponent->SetWorldScale3D(FVector(0.5f, 0.5f, 6.f));




}


void AMyCppBond::AttachGrabbedObj(AActor* ParentActor, bool IsEnd1)
{
	if (!IsGrabbed)
	{
		//ParentActor = Cast<MyCppBond>(ParentActor);
	}
}

void AMyCppBond::DetachPawn()
{

}

// Called when the game starts or when spawned
void AMyCppBond::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCppBond::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

