// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCppUserWidget.h"
#include "MyBasicPawn2.h"
#include "MyCppAtom.h"
#include "MyCppBond.h"


void UMyCppUserWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();
}
void UMyCppUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
}
UEditableText*& UMyCppUserWidget::GetTextInputWidget()
{
	return TextInput;
}