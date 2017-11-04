// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "JuanitoCharacter.h"
#include "JuanitoGameMode.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "UObject/ConstructorHelpers.h"

//////////////////////////////////////////////////////////////////////////
// AJuanitoCharacter

AJuanitoCharacter::AJuanitoCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 2500.0f; 
	CameraBoom->RelativeRotation = FRotator(-45.f, -30.f, 0.f);
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
	
	ConstructorHelpers::FObjectFinder<UMaterial> HumanMaterialFinder(_T("Material'/Game/Mannequin/Character/Materials/M_UE4Man_Body.M_UE4Man_Body'"));
	ConstructorHelpers::FObjectFinder<UMaterial> SpiritMaterialFinder(_T("Material'/Game/Mannequin/Character/Materials/Spirit''"));
	if (HumanMaterialFinder.Object != NULL) 
	{
		HumanMaterial = (UMaterialInterface*)HumanMaterialFinder.Object;
	}
	
	if (SpiritMaterialFinder.Object != NULL)
	{
		SpiritMaterial = (UMaterialInterface*)SpiritMaterialFinder.Object;
	}
	
	IsHuman = true;
}

//////////////////////////////////////////////////////////////////////////
// Input

void AJuanitoCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction("ToggleGhost", IE_Pressed, this, &AJuanitoCharacter::ToggleGhostMode);

	PlayerInputComponent->BindAxis("MoveForward", this, &AJuanitoCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AJuanitoCharacter::MoveRight);
}

void AJuanitoCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AJuanitoCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void AJuanitoCharacter::ToggleGhostMode()
{
	IsHuman = !IsHuman;
	UMaterialInterface* CorrectMaterial = (IsHuman)? HumanMaterial: SpiritMaterial;
	UMaterialInstanceDynamic* ChangedMaterial = UMaterialInstanceDynamic::Create(CorrectMaterial, GetMesh());
	
	GetMesh()->SetMaterial(0, ChangedMaterial);
}
