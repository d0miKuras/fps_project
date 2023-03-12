// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "ActionComponent.generated.h"


class UAction;
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FPS_PROJECT_API UActionComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tags")
	FGameplayTagContainer ActiveGameplayTags;
	
public:
	UFUNCTION(BlueprintCallable, Category="Actions")
	bool AddAction(AActor* Instigator, TSubclassOf<UAction> ActionClass);

	UFUNCTION(BlueprintCallable, Category="Actions")
	bool RemoveAction(UAction* ActionToRemove);

	UFUNCTION(BlueprintCallable, Category="Actions")
	bool StartAction(AActor* Instigator, FName ActionName);

	UFUNCTION(BlueprintCallable, Category="Actions")
	bool StopAction(AActor* Instigator, FName ActionName);

	UFUNCTION(BlueprintCallable, Category="Actions")
	bool IsRunning(FName ActionName) const;
	
protected:
	UPROPERTY(EditDefaultsOnly, Category="Action")
	TArray<TSubclassOf<UAction>> mStartingActions;
	
	UPROPERTY()
	TMap<FName, UAction*> mActions;

	UPROPERTY()
	TMap<FName, UAction*> mRunningActions;
	
public:
	// Sets default values for this component's properties
	UActionComponent();
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

};
