// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5_SoulsLikeCharacter.h"
#include "AbilitySystemComponent.h"
#include "Crossroads_AttributeSet.h"

//////////////////////////////////////////////////////////////////////////
// AUE5_SoulsLikeCharacter

AUE5_SoulsLikeCharacter::AUE5_SoulsLikeCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	Attributes = CreateDefaultSubobject<UCrossroads_AttributeSet>("Attributes");

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}
UAbilitySystemComponent* AUE5_SoulsLikeCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AUE5_SoulsLikeCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}

	InitializeAttributes();
	GiveDefaultAbilities();
}

void AUE5_SoulsLikeCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}

	InitializeAttributes();
}

void AUE5_SoulsLikeCharacter::InitializeAttributes()
{
	UE_LOG(LogTemp, Warning, TEXT("trying InitializeAttributes"));

	if (AbilitySystemComponent && DefaultAttributeEffect)
	{
		FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
		EffectContext.AddSourceObject(this);
		FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributeEffect, 1, EffectContext);

		if (SpecHandle.IsValid())
		{
			FActiveGameplayEffectHandle GEHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
		}

	}
}

void AUE5_SoulsLikeCharacter::GiveDefaultAbilities()
{
	UE_LOG(LogTemp, Warning, TEXT("trying GiveDefaultAbilities"));

	if (HasAuthority() && AbilitySystemComponent)
	{
		for (TSubclassOf<UGameplayAbility>& StartupAbility : DefaultAbilities)
		{
			AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(StartupAbility, 0, -1));
			UE_LOG(LogTemp, Warning, TEXT("default ability given"));
		}
	}
}

