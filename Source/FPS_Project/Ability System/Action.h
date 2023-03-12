// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "Action.generated.h"

/**
 * 
 */
class UActionComponent;
UCLASS(Blueprintable)
class FPS_PROJECT_API UAction : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category="Action")
    	UActionComponent* GetOwningComponent() const;
    
    	UFUNCTION(BlueprintCallable, Category="Action")
    	FORCEINLINE bool IsRunning() const { return bIsRunning; }
    	
    	UFUNCTION(BlueprintNativeEvent, Category="Action")
    	void StartAction(AActor* Instigator);
    	virtual void StartAction_Implementation(AActor* Instigator);
    	
    	UFUNCTION(BlueprintNativeEvent, Category="Action")
    	void StopAction(AActor* Instigator);
    	virtual void StopAction_Implementation(AActor* Instigator);
    	
    	UFUNCTION(BlueprintNativeEvent, Category="Action")
    	bool CanStart(AActor* Instigator);
    	virtual bool CanStart_Implementation(AActor* Instigator);
    	
    	UFUNCTION(BlueprintCallable)
    	virtual UWorld* GetWorld() const override;
    
    	UFUNCTION(BlueprintCallable)
    	FORCEINLINE FGameplayTagContainer GetGrantsTags() const { return mGrantsTags; }
    
    	UFUNCTION(BlueprintCallable, Category="Action")
    	FORCEINLINE bool GetCancelsRunningActions() const { return bCancelsRunningActions; }
    
    	UFUNCTION(BlueprintCallable)
    	FORCEINLINE FGameplayTagContainer GetBlockedTags() const { return mBlockedTags; }
    public:
    	UPROPERTY(EditDefaultsOnly, Category="Action")
    	FName ActionName;
    
    	UPROPERTY(EditDefaultsOnly, Category="Action")
    	bool bAutoStart;
    	
    protected:
    	UPROPERTY(EditDefaultsOnly, Category="Tags")
    	FGameplayTagContainer mGrantsTags;
    	
    	UPROPERTY(EditDefaultsOnly, Category="Action")
    	bool bCancelsRunningActions;
    	
    	UPROPERTY(EditDefaultsOnly, Category="Tags")
    	FGameplayTagContainer mBlockedTags;
    
    	UPROPERTY()
    	bool bIsRunning;
};
