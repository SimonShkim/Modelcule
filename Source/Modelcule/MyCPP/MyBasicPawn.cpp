// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBasicPawn.h"

// Sets default values
AMyBasicPawn::AMyBasicPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Added
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	
	UCameraComponent* Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);



}

// Called when the game starts or when spawned
void AMyBasicPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyBasicPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Added
	//{
	//	if (!CurrentVel.IsZero())
	//	{
	//		FVector NewLoc = GetActorLocation() + (CurrentVel * DeltaTime);
	//		SetActorLocation(NewLoc);

	//	}
	//}

	{
		if (!CurrentRot.IsZero())
		{
			FRotator NewRot = GetActorRotation() + (CurrentRot * DeltaTime);
			SetActorRotation(NewRot);
		}
	}
}

// Called to bind functionality to input
void AMyBasicPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	//Added
	//Inputs for moving
	InputComponent->BindAxis("MoveForward", this, &AMyBasicPawn::MoveFB);

	InputComponent->BindAxis("MoveRight", this, &AMyBasicPawn::MoveLR);

	InputComponent->BindAxis("MoveUp", this, &AMyBasicPawn::MoveUD);

	//Inputs for turning
	InputComponent->BindAxis("Turn", this, &AMyBasicPawn::TurnLR);
	InputComponent->BindAxis("LookUp", this, &AMyBasicPawn::TurnUD);

	InputComponent->BindAction("Fire", IE_Pressed, this, & AMyBasicPawn::LineTrace);

}

//Moving
void AMyBasicPawn::MoveFB(float input)
{
	//UE_LOG(LogTemp, Warning, TEXT("FB"));
	//CurrentVel.X = FMath::Clamp(input, -1.0f, 1.0f) * 1000.0f;
	FVector Forward = GetActorForwardVector();
	Forward = Forward.operator*(FMath::Clamp(input, -1.0f, 1.0f) * 10.0f);
	CurrentVel.Set(Forward.X,Forward.Y,Forward.Z);

	FVector NewLoc = GetActorLocation() + (CurrentVel);
	SetActorLocation(NewLoc);

}

void AMyBasicPawn::MoveLR(float input)
{
	//UE_LOG(LogTemp, Warning, TEXT("lr"));
	//CurrentVel.X = FMath::Clamp(input, -1.0f, 1.0f) * 1000.0f;
	FVector Right = GetActorRightVector();
	Right = Right.operator*(FMath::Clamp(input, -1.0f, 1.0f) * 10.0f);
	CurrentVel.X = Right.X;
	CurrentVel.Y = Right.Y;
	CurrentVel.Z = Right.Z;

	FVector NewLoc = GetActorLocation() + (CurrentVel);
	SetActorLocation(NewLoc);

}
void AMyBasicPawn::MoveUD(float input)
{
	//UE_LOG(LogTemp, Warning, TEXT("ud"));
	//CurrentVel.X = FMath::Clamp(input, -1.0f, 1.0f) * 1000.0f;
	FVector Up = GetActorUpVector();
	Up = Up.operator*(FMath::Clamp(input, -1.0f, 1.0f) * 10.0f);
	CurrentVel.Set(Up.X, Up.Y, Up.Z);

	FVector NewLoc = GetActorLocation() + (CurrentVel);
	SetActorLocation(NewLoc);
}
//Turning
void AMyBasicPawn::TurnLR(float input)
{
	//UE_LOG(LogTemp, Warning, TEXT("turn lr"));
	CurrentRot.Yaw = FMath::Clamp(input, -1.0f, 1.0f) * 1000.0f;

}
void AMyBasicPawn::TurnUD(float input)
{
	//UE_LOG(LogTemp, Warning, TEXT("turn ud"));
	CurrentRot.Pitch = FMath::Clamp(input, -1.0f, 1.0f) * 1000.0f;

}


void AMyBasicPawn::LineTrace()
{
	UE_LOG(LogTemp, Warning, TEXT("Hi"));
	FVector Start = GetActorLocation();
	//determines grab distance
	FVector End = GetActorForwardVector();
	End = End.operator*(1000.0f);
	End.operator+=(Start);

	//Object type
	//FCollisionObjectQueryParams()
	TArray<TEnumAsByte<EObjectTypeQuery>> TraceObjectTypes;

	FHitResult Hit;

	TraceObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldDynamic));
	if (GetWorld()->LineTraceSingleByObjectType(Hit, Start, End, TraceObjectTypes))
	{
		UE_LOG(LogTemp, Warning, TEXT("hit"));
	}
}

	


