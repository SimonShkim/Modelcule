// Fill out your copyright notice in the Description page of Project Settings.

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

	End1->SetupAttachment(RootComponent);
	End2->SetupAttachment(RootComponent);

	Collision1->SetupAttachment(End1);
	Collision2->SetupAttachment(End2);


	//Set Static Mesh used by static mesh component
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/MyModelculeStuff/MyStaticMeshes/MyCylinder_StaticMesh.MyCylinder_StaticMesh'"));
	UStaticMesh* CylinderMesh = MeshAsset.Object;
	Cylinder->SetStaticMesh(CylinderMesh);
	
	//Set material of static mesh component
	static ConstructorHelpers::FObjectFinder<UMaterialInstance>Material(TEXT("MaterialInstanceConstant'/Game/MyModelculeStuff/MyMaterials/Colors/MyBlackMat.MyBlackMat'"));
	UMaterialInstance* BlackMat = Material.Object;
	Cylinder->SetMaterial(0, BlackMat);

	//Set Scale
	End1->SetRelativeLocation(FVector(0.f, 0.f, 300.0f));
	End1->SetRelativeScale3D(FVector(1.0f, 1.0f, 0.5f));

	End2->SetRelativeLocation(FVector(0.f, 0.f, -300.0f));
	End2->SetRelativeScale3D(FVector(1.0f, 1.0f, 0.5f));

	Cylinder->SetRelativeScale3D(FVector(0.5f, 0.5f, 6.f));

	

	//Overlap Events
	Collision1->SetGenerateOverlapEvents(true);

	Collision1->OnComponentBeginOverlap.AddDynamic(this, &AMyCppBond::AttachEnd1);
	Collision2->OnComponentBeginOverlap.AddDynamic(this, &AMyCppBond::AttachEnd2);



}


void AMyCppBond::AttachEnd1(UPrimitiveComponent* OtherComp, AActor* ParentAct, UPrimitiveComponent* thing, int32 OtherIndex, bool FromSweep, const FHitResult& SweepResult)
{
	//if (!IsGrabbed)
	//{
		//ParentActor = Cast<MyCppBond>(ParentActor);
	//}
	//OtherActor is parent
	DetachPawn();
	this->AttachToComponent(thing, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	//Self is parent
	//ParentAct->AttachToComponent(End1, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	
	E1Actor = ParentAct;
}

void AMyCppBond::AttachEnd2(UPrimitiveComponent* OtherComp, AActor* ParentAct, UPrimitiveComponent* thing, int32 OtherIndex, bool FromSweep, const FHitResult& SweepResult)
{
	//Other Actor is parent
	//this->AttachToComponent(OtherComp, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	
	//Self is parent
	ParentAct->AttachToComponent(End2, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	
	E2Actor = ParentAct;
}

void AMyCppBond::DetachPawn()
{
	AActor::DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);

}

void AMyCppBond::SetIsGrabbed(bool status)
{
	IsGrabbed = status;
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
	//Collision1->OnComponentBeginOverlap

}

