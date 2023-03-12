// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionComponent.h"
#include "Action.h"

UActionComponent::UActionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	mActions.Reserve(8);
}

void UActionComponent::BeginPlay()
{
	Super::BeginPlay();
	for (auto& action : mStartingActions)
	{
		AddAction(GetOwner(), action);
	}
}

void UActionComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                       FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FString DebugMsg = GetNameSafe(GetOwner()) + " : " + ActiveGameplayTags.ToStringSimple();
	GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::White, DebugMsg);
}

bool UActionComponent::AddAction(AActor* Instigator, TSubclassOf<UAction> ActionClass)
{
	if (!ensure(ActionClass)) return false;

	UAction* NewAction = NewObject<UAction>(this, ActionClass);
	if (NewAction)
	{
		if (!mActions.Contains(NewAction->ActionName))
		{
			mActions.Add(NewAction->ActionName, NewAction);
			if (NewAction->bAutoStart)
			{
				StartAction(Instigator, NewAction->ActionName);
			}
			return true;
		}
	}
	return false;
}

bool UActionComponent::RemoveAction(UAction* ActionToRemove)
{
	if (ensure(ActionToRemove && !IsRunning(ActionToRemove->ActionName)))
	{
		mActions.Remove(ActionToRemove->ActionName);
		return true;
	}
	return false;
}

bool UActionComponent::StartAction(AActor* Instigator, FName ActionName)
{
	if (ensure(mActions.Contains(ActionName)))
	{
		if (mActions[ActionName]->CanStart(Instigator))
		{
			mActions[ActionName]->StartAction(Instigator);
			mRunningActions.Add(ActionName, mActions[ActionName]);
			return true;
		}
		if (mActions[ActionName]->GetCancelsRunningActions())
		{
			for (auto& action : mRunningActions)
			{
				if (action.Value->GetGrantsTags().HasAny(mActions[ActionName]->GetBlockedTags()))
					mActions[action.Key]->StopAction(Instigator);
			}
			mActions[ActionName]->StartAction(Instigator);
			mRunningActions.Add(ActionName, mActions[ActionName]);
			return true;
		}
	}
	return false;
}

bool UActionComponent::StopAction(AActor* Instigator, FName ActionName)
{
	if (ensure(mActions.Contains(ActionName)))
	{
		if (mActions[ActionName]->IsRunning())
		{
			mActions[ActionName]->StopAction(Instigator);
			mRunningActions.Remove(ActionName);
			return true;
		}
	}
	return false;
}

bool UActionComponent::IsRunning(FName ActionName) const
{
	return mActions.Contains(ActionName) && mActions[ActionName]->IsRunning();
}
