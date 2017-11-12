// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "JuanitoGameMode.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeJuanitoGameMode() {}
// Cross Module References
	JUANITO_API UClass* Z_Construct_UClass_AJuanitoGameMode_NoRegister();
	JUANITO_API UClass* Z_Construct_UClass_AJuanitoGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Juanito();
// End Cross Module References
	void AJuanitoGameMode::StaticRegisterNativesAJuanitoGameMode()
	{
	}
	UClass* Z_Construct_UClass_AJuanitoGameMode_NoRegister()
	{
		return AJuanitoGameMode::StaticClass();
	}
	UClass* Z_Construct_UClass_AJuanitoGameMode()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AGameModeBase();
			Z_Construct_UPackage__Script_Juanito();
			OuterClass = AJuanitoGameMode::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20880288u;


				static TCppClassTypeInfo<TCppClassTypeTraits<AJuanitoGameMode> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("JuanitoGameMode.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("JuanitoGameMode.h"));
				MetaData->SetValue(OuterClass, TEXT("ShowCategories"), TEXT("Input|MouseInput Input|TouchInput"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AJuanitoGameMode, 3792575530);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AJuanitoGameMode(Z_Construct_UClass_AJuanitoGameMode, &AJuanitoGameMode::StaticClass, TEXT("/Script/Juanito"), TEXT("AJuanitoGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AJuanitoGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
