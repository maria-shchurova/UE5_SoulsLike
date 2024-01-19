// Fill out your copyright notice in the Description page of Project Settings.


#include "Crossroads_AttributeSet.h"
#include "Net/UnrealNetwork.h"

UCrossroads_AttributeSet::UCrossroads_AttributeSet()
{
}

void UCrossroads_AttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	DOREPLIFETIME_CONDITION_NOTIFY(UCrossroads_AttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCrossroads_AttributeSet, Endurance, COND_None, REPNOTIFY_Always);
}

void UCrossroads_AttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCrossroads_AttributeSet, Health, OldHealth);
}

void UCrossroads_AttributeSet::OnRep_Endurance(const FGameplayAttributeData& OldEndurance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCrossroads_AttributeSet, Endurance, OldEndurance);
}
