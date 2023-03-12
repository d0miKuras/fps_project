// Fill out your copyright notice in the Description page of Project Settings.


#include "Action.h"
#include "ActionComponent.h"

void UAction::StartAction_Implementation(AActor* Instigator)
{
	UE_LOG(LogTemp, Log, TEXT("Running: %s"), *GetNameSafe(this));

	UActionComponent* Comp = GetOwningComponent();
	Comp->ActiveGameplayTags.AppendTags(mGrantsTags);
	bIsRunning = true;
}

void UAction::StopAction_Implementation(AActor* Instigator)
{
	UE_LOG(LogTemp, Log, TEXT("Stopped: %s"), *GetNameSafe(this));

	ensureAlways(bIsRunning);
	UActionComponent* Comp = GetOwningComponent();
	Comp->ActiveGameplayTags.RemoveTags(mGrantsTags);
	bIsRunning = false;
}

bool UAction::CanStart_Implementation(AActor* Instigator)
{
	UActionComponent* Comp = GetOwningComponent();
	return !Comp->ActiveGameplayTags.HasAny(mBlockedTags);
}

UActionComponent* UAction::GetOwningComponent() const
{
	return Cast<UActionComponent>(GetOuter());
}


UWorld* UAction::GetWorld() const
{
	UActorComponent* Comp = Cast<UActorComponent>(GetOuter());
	if(Comp)
	{
		return Comp->GetWorld();
	}
	return nullptr;
}
