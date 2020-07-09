// Fill out your copyright notice in the Description page of Project Settings.

#include "Materials/MaterialInstance.h"
#include "MyCppBond.h"

// Sets default values
AMyCppBond::AMyCppBond()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Collision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision"));
	Cylinder = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cylinder"));
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	Collision->SetupAttachment(RootComponent);
	Cylinder->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/MyModelculeStuff/MyStaticMeshes/MyCylinder_StaticMesh.MyCylinder_StaticMesh'"));
	UStaticMesh* CylinderMesh = MeshAsset.Object;
	Cylinder->SetStaticMesh(CylinderMesh);

	static ConstructorHelpers::FObjectFinder<UMaterialInstance>Material(TEXT("MaterialInstanceConstant'/Game/MyModelculeStuff/MyMaterials/Colors/MyBlackMat.MyBlackMat'"));
	UMaterialInstance* BlackMat = Material.Object;
	Cylinder->SetMaterial(0, BlackMat);

	//SetMaterial();

	
	//UMaterial* BlackMat = CreateDefaultSubobject<UMaterial>(TEXT("MaterialInstanceConstant'/Game/MyModelculeStuff/MyMaterials/Colors/MyBlackMat.MyBlackMat'"));
	
	//Cylinder->SetMaterial(0, BlackMatDy);

	//ConstructorHelpers::FObjectFinder<UMaterial>MeshAss(TEXT("MaterialInstanceConstant'/Game/MyModelculeStuff/MyMaterials/Colors/MyBlackMat.MyBlackMat'"));
	//UMaterial* BlackMat = MeshAss.Object;
	//Cylinder->SetMaterial(BlackMat);



	//StaticMesh* MyCylinder = CreateDefaultSubobject<MyCylinder_StaticMesh> ;
		
		//StaticMesh'/Game/MyModelculeStuff/MyStaticMeshes/MySphere_StaticMesh.MySphere_StaticMesh'
	//Cylinder->SetStaticMesh();

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

