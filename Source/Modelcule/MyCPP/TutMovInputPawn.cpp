// Fill out your copyright notice in the Description page of Project Settings.


#include "TutMovInputPawn.h"

// Sets default values
ATutMovInputPawn::ATutMovInputPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Set this pawn to be controlled by the lowest-numbered player
    AutoPossessPlayer = EAutoReceiveInput::Player0;

    // Create a dummy root component we can attach things to.
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
   
    // Create a camera and a visible object
    UCameraComponent* OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
    OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
   
    // Attach our camera and visible object to our root component. Offset and rotate the camera.
    OurCamera->SetupAttachment(RootComponent);
    OurCamera->SetRelativeLocation(FVector(-250.0f, 0.0f, 200.0f));
    OurCamera->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));
    OurVisibleComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ATutMovInputPawn::BeginPlay()
{
	Super::BeginPlay();
	
   
}

// Called every frame
void ATutMovInputPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    // Handle growing and shrinking based on our "Grow" action
    {
        float CurrentScale = OurVisibleComponent->GetComponentScale().X;
        if (bGrowing)
        {
            // Grow to double size over the course of one second
            CurrentScale += DeltaTime;
        }
        else
        {
            // Shrink half as fast as we grow
            CurrentScale -= (DeltaTime * 0.5f);
        }
        // Make sure we never drop below our starting size, or increase past double size.
        CurrentScale = FMath::Clamp(CurrentScale, 1.0f, 2.0f);
        OurVisibleComponent->SetWorldScale3D(FVector(CurrentScale));
    }

    // Handle movement based on our "MoveX" and "MoveY" axes
    {
        if (!CurrentVelocity.IsZero())
        {
            FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
            SetActorLocation(NewLocation);
        }
    }

}

// Called to bind functionality to input
void ATutMovInputPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Respond when our "Grow" key is pressed or released.
    InputComponent->BindAction("Jump", IE_Pressed, this, &ATutMovInputPawn::StartGrowing);
    InputComponent->BindAction("Jump", IE_Released, this, &ATutMovInputPawn::StopGrowing);

    // Respond every frame to the values of our two movement axes, "MoveX" and "MoveY".
    InputComponent->BindAxis("MoveForward", this, &ATutMovInputPawn::Move_XAxis);
    InputComponent->BindAxis("MoveRight", this, &ATutMovInputPawn::Move_YAxis);
}

void ATutMovInputPawn::Move_XAxis(float AxisValue)
{
    // Move at 100 units per second forward or backward
    UE_LOG(LogTemp, Warning, TEXT("X"));
    CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 1000.0f;
}

void ATutMovInputPawn::Move_YAxis(float AxisValue)
{
    // Move at 100 units per second right or left
    UE_LOG(LogTemp, Warning, TEXT("Y"));
    CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 1000.0f;
}

void ATutMovInputPawn::StartGrowing()
{
    UE_LOG(LogTemp, Warning, TEXT("big"));
    bGrowing = true;
}

void ATutMovInputPawn::StopGrowing()
{
    UE_LOG(LogTemp, Warning, TEXT("small"));
    bGrowing = false;
}