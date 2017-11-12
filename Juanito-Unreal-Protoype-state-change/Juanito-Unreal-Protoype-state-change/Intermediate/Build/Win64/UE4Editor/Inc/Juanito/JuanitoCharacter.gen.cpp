// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "JuanitoCharacter.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeJuanitoCharacter() {}
// Cross Module References
	JUANITO_API UClass* Z_Construct_UClass_AJuanitoCharacter_NoRegister();
	JUANITO_API UClass* Z_Construct_UClass_AJuanitoCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_Juanito();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
// End Cross Module References
	void AJuanitoCharacter::StaticRegisterNativesAJuanitoCharacter()
	{
	}
	UClass* Z_Construct_UClass_AJuanitoCharacter_NoRegister()
	{
		return AJuanitoCharacter::StaticClass();
	}
	UClass* Z_Construct_UClass_AJuanitoCharacter()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_ACharacter();
			Z_Construct_UPackage__Script_Juanito();
			OuterClass = AJuanitoCharacter::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20800080u;


				UProperty* NewProp_FollowCamera = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("FollowCamera"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(FollowCamera, AJuanitoCharacter), 0x00400000000a001d, Z_Construct_UClass_UCameraComponent_NoRegister());
				UProperty* NewProp_CameraBoom = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("CameraBoom"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(CameraBoom, AJuanitoCharacter), 0x00400000000a001d, Z_Construct_UClass_USpringArmComponent_NoRegister());
				OuterClass->ClassConfigName = FName(TEXT("Game"));
				static TCppClassTypeInfo<TCppClassTypeTraits<AJuanitoCharacter> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Navigation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("JuanitoCharacter.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("JuanitoCharacter.h"));
				MetaData->SetValue(NewProp_FollowCamera, TEXT("AllowPrivateAccess"), TEXT("true"));
				MetaData->SetValue(NewProp_FollowCamera, TEXT("Category"), TEXT("Camera"));
				MetaData->SetValue(NewProp_FollowCamera, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_FollowCamera, TEXT("ModuleRelativePath"), TEXT("JuanitoCharacter.h"));
				MetaData->SetValue(NewProp_FollowCamera, TEXT("ToolTip"), TEXT("Follow camera"));
				MetaData->SetValue(NewProp_CameraBoom, TEXT("AllowPrivateAccess"), TEXT("true"));
				MetaData->SetValue(NewProp_CameraBoom, TEXT("Category"), TEXT("Camera"));
				MetaData->SetValue(NewProp_CameraBoom, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_CameraBoom, TEXT("ModuleRelativePath"), TEXT("JuanitoCharacter.h"));
				MetaData->SetValue(NewProp_CameraBoom, TEXT("ToolTip"), TEXT("Camera boom positioning the camera behind the character"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AJuanitoCharacter, 1856279349);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AJuanitoCharacter(Z_Construct_UClass_AJuanitoCharacter, &AJuanitoCharacter::StaticClass, TEXT("/Script/Juanito"), TEXT("AJuanitoCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AJuanitoCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
