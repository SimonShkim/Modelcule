// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/EditableText.h"

#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Templates/SubclassOf.h"
#include "UObject/UObjectGlobals.h"

#include "Blueprint/UserWidget.h"
#include "MyCppUserWidget.generated.h"



class AMyBasicPawn2;
class AMyCppAtom;
class AMyCppBond;

/**
 * 
 */
UCLASS()
class MODELCULE_API UMyCppUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void SynchronizeProperties() override;
	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category = "Widget")
	UButton* force;

	UPROPERTY(EditAnywhere, meta = (BindWidget), Category = "Widget")
	UEditableText* TextInput;

	UFUNCTION()
	UEditableText*& GetTextInputWidget();
};
