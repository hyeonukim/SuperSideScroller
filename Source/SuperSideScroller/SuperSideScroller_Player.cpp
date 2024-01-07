// Fill out your copyright notice in the Description page of Project Settings.


#include "SuperSideScroller_Player.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

ASuperSideScroller_Player::ASuperSideScroller_Player()
{
	bIsSprinting = false;
	GetCharacterMovement()->MaxWalkSpeed = 300.0f;
}

void ASuperSideScroller_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedPlayerInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	
	if (EnhancedPlayerInput) {
		APlayerController* PlayerController = Cast<APlayerController>(GetController());
		UEnhancedInputLocalPlayerSubsystem* EnhancedSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		
		if (EnhancedSubsystem) {
			EnhancedSubsystem->AddMappingContext(IC_Character, 1);

			EnhancedPlayerInput->BindAction(IA_Sprint, ETriggerEvent::Triggered, this, &ASuperSideScroller_Player::Sprint);
			EnhancedPlayerInput->BindAction(IA_Sprint, ETriggerEvent::Completed, this, &ASuperSideScroller_Player::StopSprinting);
		}
	}
}

void ASuperSideScroller_Player::Sprint()
{
	if (!bIsSprinting) {
		bIsSprinting = true;
		GetCharacterMovement()->MaxWalkSpeed = 500.0f;
	}
}

void ASuperSideScroller_Player::StopSprinting()
{
	if (bIsSprinting) {
		bIsSprinting = false;
		GetCharacterMovement()->MaxWalkSpeed = 300.0f;
	}

}
