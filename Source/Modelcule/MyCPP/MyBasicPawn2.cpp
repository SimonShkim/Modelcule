// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBasicPawn2.h"
#include "MyCppAtom.h"
#include "MyCppBond.h"
#include "MyCppUserWidget.h"


// Sets default values
AMyBasicPawn2::AMyBasicPawn2()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Added
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);

	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->SetupAttachment(Camera);
	Arrow->SetRelativeLocation(FVector(20.f, 0.f, -30.f));
	Arrow->SetVisibility(true);

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	MyMesh->SetupAttachment(RootComponent);

	GrabLoc = CreateDefaultSubobject<USceneComponent>(TEXT("GrabLoc"));
	GrabLoc->SetupAttachment(RootComponent);
	GrabLoc->SetRelativeLocation(FVector(1500.f, 0.f, -30.f));

	//NewObject<UMyCppUserWidget>(MyWidgetBlueprint2);

	//MyUI = CreateDefaultSubobject<UMyCppUserWidget>(TEXT("UI"));

	static ConstructorHelpers::FClassFinder<UMyCppUserWidget> BPUserWidget(TEXT("WidgetBlueprint'/Game/MyModelculeStuff/MyWidgetStuff/MyWidgetBlueprint2'"));
	if (BPUserWidget.Succeeded())
	{
		UE_LOG(LogTemp, Warning, TEXT("find success"));
		TheBPUI = BPUserWidget.Class;

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("find fail"));
	}

}

// Called when the game starts or when spawned
void AMyBasicPawn2::BeginPlay()
{
	Super::BeginPlay();
	if (*TheBPUI)
	{
		UE_LOG(LogTemp, Warning, TEXT("UI"));
		MyUI = CreateWidget<UMyCppUserWidget>(GetWorld()->GetFirstPlayerController(), TheBPUI);

		MyUI->AddToViewport(100);


	}
}

// Called every frame
void AMyBasicPawn2::Tick(float DeltaTime)
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
void AMyBasicPawn2::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	//Added
	//Inputs for moving
	InputComponent->BindAxis("MoveForward", this, &AMyBasicPawn2::MoveFB);

	InputComponent->BindAxis("MoveRight", this, &AMyBasicPawn2::MoveLR);

	InputComponent->BindAxis("MoveUp", this, &AMyBasicPawn2::MoveUD);

	//Inputs for turning
	InputComponent->BindAxis("Turn", this, &AMyBasicPawn2::TurnLR);
	InputComponent->BindAxis("LookUp", this, &AMyBasicPawn2::TurnUD);
	
	//Inputs for grabbing
	InputComponent->BindAction("Fire", IE_Pressed, this, & AMyBasicPawn2::LineTrace);

	//Inputs for rotating object
	InputComponent->BindAxis("TurnRate", this, &AMyBasicPawn2::RotateLR);
	InputComponent->BindAxis("LookUpRate", this, &AMyBasicPawn2::RotateUD);

	InputComponent->BindAction("OpenUI", IE_Pressed, this, &AMyBasicPawn2::OpenUI);
}

void AMyBasicPawn2::RotateUD(float input)
{
	RotateHeldObj(FRotator(0.f, 0.f, input));
}
void AMyBasicPawn2::RotateLR(float input)
{
	RotateHeldObj(FRotator(0.f, input, 0.f));
}
void AMyBasicPawn2::RotateHeldObj(FRotator InRot)
{

	if (IsGrabbing)
	{
		FRotator NewRot = OtherGuy->GetActorRotation();
		OtherGuy->SetActorRotation(UKismetMathLibrary::ComposeRotators(NewRot, InRot));
	}

}

//Moving
void AMyBasicPawn2::MoveFB(float input)
{
	//UE_LOG(LogTemp, Warning, TEXT("FB"));
	//CurrentVel.X = FMath::Clamp(input, -1.0f, 1.0f) * 1000.0f;
	FVector Forward = GetActorForwardVector();
	Forward = Forward.operator*(FMath::Clamp(input, -1.0f, 1.0f) * 10.0f);
	CurrentVel.Set(Forward.X,Forward.Y,Forward.Z);

	FVector NewLoc = GetActorLocation() + (CurrentVel);
	SetActorLocation(NewLoc);

}

void AMyBasicPawn2::MoveLR(float input)
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

void AMyBasicPawn2::MoveUD(float input)
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
void AMyBasicPawn2::TurnLR(float input)
{
	//UE_LOG(LogTemp, Warning, TEXT("turn lr"));
	CurrentRot.Yaw = FMath::Clamp(input, -1.0f, 1.0f) * 500.0f;

}
void AMyBasicPawn2::TurnUD(float input)
{
	//UE_LOG(LogTemp, Warning, TEXT("turn ud"));
	CurrentRot.Pitch = FMath::Clamp(input, -1.0f, 1.0f) * 500.0f;
	//CurrentRot = new FRotator(0.f, input, 0.f).operator+=(CurrentRot);
}

void AMyBasicPawn2::LineTrace()
{
	if (!IsGrabbing) 
	{

	
		UE_LOG(LogTemp, Warning, TEXT("Trace"));
		
		FVector Start = GetActorLocation();
		//determines grab distance
		FVector End = GetActorForwardVector();
		End = End.operator*(1000.0f);
		End.operator+=(Start);

		//Draw Debug Line
		const FName TraceTag("MyTraceTag");
		GetWorld()->DebugDrawTraceTag = TraceTag;
		FCollisionQueryParams CollisionParams;
		CollisionParams.TraceTag = TraceTag;
		

		//Object type
		//FCollisionObjectQueryParams()
		TArray<TEnumAsByte<EObjectTypeQuery>> TraceObjectTypes;

		//Stores all information about a line trace hit
		FHitResult Hit;

		//Select object type line trace is looking for
		TraceObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldDynamic));


		//Transform Rules
		const FAttachmentTransformRules AttachRules = FAttachmentTransformRules(EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, false);

		//if line trace gets a hit, get the hit actor
		if (GetWorld()->LineTraceSingleByObjectType(Hit, Start, End, TraceObjectTypes, TraceTag))
		{
			UE_LOG(LogTemp, Warning, TEXT("hit"));
			OtherGuy = GetRoot(Hit.GetActor());

			//log info
			FString ActorName = OtherGuy->GetName();
			if (ActorName.IsEmpty())
			{
				UE_LOG(LogTemp, Warning, TEXT("Empty"));
			}
			else {
				UE_LOG(LogTemp, Warning, TEXT("%s"), *ActorName);
			}
			//attach the hit actor
			OtherGuy->AActor::AttachToComponent(GrabLoc, AttachRules);
			IsGrabbing = true;
		}

	}
	else
	{
		//detach the hit actor
		OtherGuy->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		IsGrabbing = false;
		OtherGuy = nullptr;
	}

}

AActor* AMyBasicPawn2::GetRoot(AActor* HitActor)
{
	if (Cast<AMyCppBond>(HitActor) != nullptr)
	{
		return Cast<AMyCppBond>(HitActor)->FindRoot();
	}
	else
	{
		return Cast<AMyCppAtom>(HitActor)->FindRoot();
	}
	//if (Cast<AMyCppAtom>(HitActor) != nullptr)
}

void AMyBasicPawn2::OpenUI()
{
	//if (*TheBPUI)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("UI"));
	//	MyUI = CreateWidget<UMyCppUserWidget>(GetWorld()->GetFirstPlayerController(), TheBPUI);
	//
	//	MyUI->AddToViewport(100);

	//	
	//}
	UE_LOG(LogTemp, Warning, TEXT("OpenUI Called"));
	MyUI->TextInput->SetKeyboardFocus();
	//MyUI->TextInput->OnTextChanged(GetText());
	
	

	//FInputModeGameAndUI Mode;
	//Mode.SetLockMouseToViewport(true);
	//Mode.SetHideCursorDuringCapture(false);
	//SetInputMode(Mode);




	
}
	


