// Fill out your copyright notice in the Description page of Project Settings.

//My Classes
#include "MyCppBond.h"
#include "MyBasicPawn2.h"
#include "MyCppAtom.h"
#include "MyCppUserWidget.h"


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

	End1->SetupAttachment(Cylinder);
	End2->SetupAttachment(Cylinder);

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
	//Choose collision preset
	Cylinder->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	//Cylinder->SetCollisionResponseToChannel

	//Set Scale
	End1->SetAbsolute(false, false, true);
	End1->SetRelativeLocation(FVector(0.f, 0.f, 50.0f));
	End1->SetRelativeScale3D(FVector(1.0f, 1.0f, 0.5f));

	End2->SetAbsolute(false, false, true);
	End2->SetRelativeLocation(FVector(0.f, 0.f, -50.0f));
	End2->SetRelativeScale3D(FVector(1.0f, 1.0f, 0.5f));

	Cylinder->SetRelativeScale3D(FVector(0.5f, 0.5f, 6.f));
	Cylinder->SetRelativeLocation(FVector(0.f, 0.f, 300.0f));
	

	//Overlap Events
	Collision1->SetGenerateOverlapEvents(true);
	Collision2->SetGenerateOverlapEvents(true);

	Collision1->OnComponentBeginOverlap.AddDynamic(this, &AMyCppBond::AttachLogic);
	Collision2->OnComponentBeginOverlap.AddDynamic(this, &AMyCppBond::AttachLogic);

	End1->SetActive(true);
	End2->SetActive(true);
	Collision1->SetActive(true);
	Collision2->SetActive(true);

}

void AMyCppBond::AttachLogic(UPrimitiveComponent* TouchedComp, AActor* ParentAct, UPrimitiveComponent* OtherComp, int32 OtherIndex, bool FromSweep, const FHitResult& SweepResult)
{
	//TODO
	//handle attachment
	//set actor variable with attached actor
	//only attach if end is empty
	//change attachment rules
	//change attach location when atom parent
	//check other actor is atom
	UE_LOG(LogTemp, Warning, TEXT("I'm In"));
	USceneComponent* TheEnd = TouchedComp->GetAttachParent();

	const FAttachmentTransformRules AttachRules = FAttachmentTransformRules(EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, false);
	if (ParentAct->GetClass() != GetClass())
	{
		//both ends empty
		if (!(E1Actor->IsValidLowLevel() || E2Actor->IsValidLowLevel()))
		{
			UE_LOG(LogTemp, Warning, TEXT("1"));
			//OtherActor is parent
			DetachPawn();
			this->AttachToComponent(Cast<AMyCppAtom>(ParentAct)->AttachLoc, AttachRules);
			ParentActor = ParentAct;
			GetEndAttActor(TheEnd) = ParentAct;
		}
		//both ends occupied
		else if (E1Actor->IsValidLowLevel() && E2Actor->IsValidLowLevel())
		{
			UE_LOG(LogTemp, Warning, TEXT("2"));
			return;
		}

		else
		{
			UE_LOG(LogTemp, Warning, TEXT("3"));
			if (!GetEndAttActor(TheEnd)->IsValidLowLevel())
			{
				//Self is parent
				ParentAct->AttachToComponent(TheEnd, AttachRules);
				GetEndAttActor(TheEnd) = ParentAct;

				Cast<AMyCppAtom>(ParentAct)->SetParentActor(this);
			}
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("4"));
	//if (TheEnd == End1)
	//{
	//	E1Actor = ParentAct;
	//}w
	//else if(TheEnd == End2)
	//{
	//	E2Actor = ParentAct;
	//}
	//(GetEndAttActor(TheEnd)) = ParentAct;

	//SetEndAttActor(TheEnd);


}

void AMyCppBond::AttachEnd1(UPrimitiveComponent* TouchedComp, AActor* ParentAct, UPrimitiveComponent* OtherComp, int32 OtherIndex, bool FromSweep, const FHitResult& SweepResult)
{
	if (!(E1Actor->IsValidLowLevel() || E2Actor->IsValidLowLevel()))
	{
		//OtherActor is parent
		DetachPawn();
		this->AttachToComponent(OtherComp, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	}
	else 
	{
		//Self is parent
		ParentAct->AttachToComponent(End1, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	}
	E1Actor = ParentAct;
}

void AMyCppBond::AttachEnd2(UPrimitiveComponent* TouchedComp, AActor* ParentAct, UPrimitiveComponent* OtherComp, int32 OtherIndex, bool FromSweep, const FHitResult& SweepResult)
{
	//Other Actor is parent
	//this->AttachToComponent(OtherComp, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	
	//Self is parent
	ParentAct->AttachToComponent(End2, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	E2Actor = ParentAct;
}

AActor*& AMyCppBond::GetEndAttActor(USceneComponent* End)
{
	UE_LOG(LogTemp, Warning, TEXT("5"));
	if (End == End1) 
	{ 
		UE_LOG(LogTemp, Warning, TEXT("6")); 
		return E1Actor; }
	
	else  { UE_LOG(LogTemp, Warning, TEXT("7")); 
	return E2Actor; }
	

}

void AMyCppBond::SetEndAttActor(USceneComponent* End)
{
	//if (End == End1) {  E1Actor = ; }

	//else if (End == End2) { return E2Actor; }

	//else { return nullptr; }
}


void AMyCppBond::DetachPawn()
{
	//AActor::DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	//AActor::DetachRootComponentFromParent(true);

	//Cast<AMyBasicPawn2>(GetAttachParentActor())->AMyBasicPawn2::LineTrace();


}

void AMyCppBond::DetachEnd1Obj()
{
	DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	SetIsGrabbed(false);
}

void AMyCppBond::DetachEnd2Obj()
{
	DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	SetIsGrabbed(false);
}

void AMyCppBond::SetIsGrabbed(bool status)
{
	IsGrabbed = status;
}

AActor* AMyCppBond::FindRoot()
{
	if (ParentActor == nullptr)
	{
		return this;
	}
	else
	{
		return Cast<AMyCppAtom>(ParentActor)->FindRoot();
	}
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

