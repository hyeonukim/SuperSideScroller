// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SuperSideScrollerCharacter.h"
#include "SuperSideScroller_Player.generated.h"

/**
 * 
 */
UCLASS()
class SUPERSIDESCROLLER_API ASuperSideScroller_Player : public ASuperSideScrollerCharacter
{
	GENERATED_BODY()

public:
	ASuperSideScroller_Player();
	
protected:
	//re set the charaacter input component from its parent class
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputMappingContext* IC_Character; 

	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputAction* IA_Sprint;

	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputAction* IA_Throw;

	//start sprinting
	void Sprint();

	//stop sprinting
	void StopSprinting();

	//throw projectile
	void ThrowProjectile();

private:
	bool bIsSprinting;
};
