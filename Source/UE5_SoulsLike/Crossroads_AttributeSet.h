// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Crossroads_AttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class UE5_SOULSLIKE_API UCrossroads_AttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public: UCrossroads_AttributeSet();
	
	  virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	  UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	  FGameplayAttributeData Health = 100.0f;
	  ATTRIBUTE_ACCESSORS(UCrossroads_AttributeSet, Health);
	  
	  UFUNCTION()
	  virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);

	  UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	  FGameplayAttributeData Endurance = 100.0f;
	  ATTRIBUTE_ACCESSORS(UCrossroads_AttributeSet, Endurance);

	  UFUNCTION()
	  virtual void OnRep_Endurance(const FGameplayAttributeData& OldEndurance);
};
