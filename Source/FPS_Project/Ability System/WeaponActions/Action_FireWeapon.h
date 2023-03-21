// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPS_Project/Ability System/Action.h"
#include "UObject/Object.h"
#include "Action_FireWeapon.generated.h"

/**
 * 
 */
UCLASS()
class FPS_PROJECT_API UAction_FireWeapon : public UAction
{
	GENERATED_BODY()
public:
	virtual void StartAction_Implementation(AActor* Instigator) override;
	virtual void StopAction_Implementation(AActor* Instigator) override;
};
