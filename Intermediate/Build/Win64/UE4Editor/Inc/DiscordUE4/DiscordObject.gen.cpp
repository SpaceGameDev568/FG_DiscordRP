// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DiscordUE4/Public/DiscordObject.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDiscordObject() {}
// Cross Module References
	DISCORDUE4_API UFunction* Z_Construct_UDelegateFunction_DiscordUE4_OnDiscordResult__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_DiscordUE4();
	DISCORDUE4_API UEnum* Z_Construct_UEnum_DiscordUE4_EDiscordReturnResult();
	DISCORDUE4_API UClass* Z_Construct_UClass_UDiscordObject_NoRegister();
	DISCORDUE4_API UClass* Z_Construct_UClass_UDiscordObject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_DiscordUE4_OnDiscordResult__DelegateSignature_Statics
	{
		struct _Script_DiscordUE4_eventOnDiscordResult_Parms
		{
			EDiscordReturnResult StateSetResult;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_StateSetResult_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_StateSetResult;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_DiscordUE4_OnDiscordResult__DelegateSignature_Statics::NewProp_StateSetResult_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_DiscordUE4_OnDiscordResult__DelegateSignature_Statics::NewProp_StateSetResult = { "StateSetResult", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_DiscordUE4_eventOnDiscordResult_Parms, StateSetResult), Z_Construct_UEnum_DiscordUE4_EDiscordReturnResult, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_DiscordUE4_OnDiscordResult__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_DiscordUE4_OnDiscordResult__DelegateSignature_Statics::NewProp_StateSetResult_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_DiscordUE4_OnDiscordResult__DelegateSignature_Statics::NewProp_StateSetResult,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_DiscordUE4_OnDiscordResult__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_DiscordUE4_OnDiscordResult__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_DiscordUE4, nullptr, "OnDiscordResult__DelegateSignature", nullptr, nullptr, sizeof(_Script_DiscordUE4_eventOnDiscordResult_Parms), Z_Construct_UDelegateFunction_DiscordUE4_OnDiscordResult__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DiscordUE4_OnDiscordResult__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_DiscordUE4_OnDiscordResult__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_DiscordUE4_OnDiscordResult__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_DiscordUE4_OnDiscordResult__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_DiscordUE4_OnDiscordResult__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	static UEnum* EDiscordReturnResult_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_DiscordUE4_EDiscordReturnResult, Z_Construct_UPackage__Script_DiscordUE4(), TEXT("EDiscordReturnResult"));
		}
		return Singleton;
	}
	template<> DISCORDUE4_API UEnum* StaticEnum<EDiscordReturnResult>()
	{
		return EDiscordReturnResult_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EDiscordReturnResult(EDiscordReturnResult_StaticEnum, TEXT("/Script/DiscordUE4"), TEXT("EDiscordReturnResult"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_DiscordUE4_EDiscordReturnResult_Hash() { return 3277381937U; }
	UEnum* Z_Construct_UEnum_DiscordUE4_EDiscordReturnResult()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_DiscordUE4();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EDiscordReturnResult"), 0, Get_Z_Construct_UEnum_DiscordUE4_EDiscordReturnResult_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EDiscordReturnResult::Ok", (int64)EDiscordReturnResult::Ok },
				{ "EDiscordReturnResult::ServiceUnavailable", (int64)EDiscordReturnResult::ServiceUnavailable },
				{ "EDiscordReturnResult::InvalidVersion", (int64)EDiscordReturnResult::InvalidVersion },
				{ "EDiscordReturnResult::LockFailed", (int64)EDiscordReturnResult::LockFailed },
				{ "EDiscordReturnResult::InternalError", (int64)EDiscordReturnResult::InternalError },
				{ "EDiscordReturnResult::InvalidPayload", (int64)EDiscordReturnResult::InvalidPayload },
				{ "EDiscordReturnResult::InvalidCommand", (int64)EDiscordReturnResult::InvalidCommand },
				{ "EDiscordReturnResult::InvalidPermissions", (int64)EDiscordReturnResult::InvalidPermissions },
				{ "EDiscordReturnResult::NotFetched", (int64)EDiscordReturnResult::NotFetched },
				{ "EDiscordReturnResult::NotFound", (int64)EDiscordReturnResult::NotFound },
				{ "EDiscordReturnResult::Conflict", (int64)EDiscordReturnResult::Conflict },
				{ "EDiscordReturnResult::InvalidSecret", (int64)EDiscordReturnResult::InvalidSecret },
				{ "EDiscordReturnResult::InvalidJoinSecret", (int64)EDiscordReturnResult::InvalidJoinSecret },
				{ "EDiscordReturnResult::NoEligibleActivity", (int64)EDiscordReturnResult::NoEligibleActivity },
				{ "EDiscordReturnResult::InvalidInvite", (int64)EDiscordReturnResult::InvalidInvite },
				{ "EDiscordReturnResult::NotAuthenticated", (int64)EDiscordReturnResult::NotAuthenticated },
				{ "EDiscordReturnResult::InvalidAccessToken", (int64)EDiscordReturnResult::InvalidAccessToken },
				{ "EDiscordReturnResult::ApplicationMismatch", (int64)EDiscordReturnResult::ApplicationMismatch },
				{ "EDiscordReturnResult::InvalidDataUrl", (int64)EDiscordReturnResult::InvalidDataUrl },
				{ "EDiscordReturnResult::InvalidBase64", (int64)EDiscordReturnResult::InvalidBase64 },
				{ "EDiscordReturnResult::NotFiltered", (int64)EDiscordReturnResult::NotFiltered },
				{ "EDiscordReturnResult::LobbyFull", (int64)EDiscordReturnResult::LobbyFull },
				{ "EDiscordReturnResult::InvalidLobbySecret", (int64)EDiscordReturnResult::InvalidLobbySecret },
				{ "EDiscordReturnResult::InvalidFilename", (int64)EDiscordReturnResult::InvalidFilename },
				{ "EDiscordReturnResult::InvalidFileSize", (int64)EDiscordReturnResult::InvalidFileSize },
				{ "EDiscordReturnResult::InvalidEntitlement", (int64)EDiscordReturnResult::InvalidEntitlement },
				{ "EDiscordReturnResult::NotInstalled", (int64)EDiscordReturnResult::NotInstalled },
				{ "EDiscordReturnResult::NotRunning", (int64)EDiscordReturnResult::NotRunning },
				{ "EDiscordReturnResult::InsufficientBuffer", (int64)EDiscordReturnResult::InsufficientBuffer },
				{ "EDiscordReturnResult::PurchaseCanceled", (int64)EDiscordReturnResult::PurchaseCanceled },
				{ "EDiscordReturnResult::InvalidGuild", (int64)EDiscordReturnResult::InvalidGuild },
				{ "EDiscordReturnResult::InvalidEvent", (int64)EDiscordReturnResult::InvalidEvent },
				{ "EDiscordReturnResult::InvalidChannel", (int64)EDiscordReturnResult::InvalidChannel },
				{ "EDiscordReturnResult::InvalidOrigin", (int64)EDiscordReturnResult::InvalidOrigin },
				{ "EDiscordReturnResult::RateLimited", (int64)EDiscordReturnResult::RateLimited },
				{ "EDiscordReturnResult::OAuth2Error", (int64)EDiscordReturnResult::OAuth2Error },
				{ "EDiscordReturnResult::SelectChannelTimeout", (int64)EDiscordReturnResult::SelectChannelTimeout },
				{ "EDiscordReturnResult::GetGuildTimeout", (int64)EDiscordReturnResult::GetGuildTimeout },
				{ "EDiscordReturnResult::SelectVoiceForceRequired", (int64)EDiscordReturnResult::SelectVoiceForceRequired },
				{ "EDiscordReturnResult::CaptureShortcutAlreadyListening", (int64)EDiscordReturnResult::CaptureShortcutAlreadyListening },
				{ "EDiscordReturnResult::UnauthorizedForAchievement", (int64)EDiscordReturnResult::UnauthorizedForAchievement },
				{ "EDiscordReturnResult::InvalidGiftCode", (int64)EDiscordReturnResult::InvalidGiftCode },
				{ "EDiscordReturnResult::PurchaseError", (int64)EDiscordReturnResult::PurchaseError },
				{ "EDiscordReturnResult::TransactionAborted", (int64)EDiscordReturnResult::TransactionAborted },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ApplicationMismatch.Name", "EDiscordReturnResult::ApplicationMismatch" },
				{ "BlueprintType", "true" },
				{ "CaptureShortcutAlreadyListening.Name", "EDiscordReturnResult::CaptureShortcutAlreadyListening" },
				{ "Conflict.Name", "EDiscordReturnResult::Conflict" },
				{ "GetGuildTimeout.Name", "EDiscordReturnResult::GetGuildTimeout" },
				{ "InsufficientBuffer.Name", "EDiscordReturnResult::InsufficientBuffer" },
				{ "InternalError.Name", "EDiscordReturnResult::InternalError" },
				{ "InvalidAccessToken.Name", "EDiscordReturnResult::InvalidAccessToken" },
				{ "InvalidBase64.Name", "EDiscordReturnResult::InvalidBase64" },
				{ "InvalidChannel.Name", "EDiscordReturnResult::InvalidChannel" },
				{ "InvalidCommand.Name", "EDiscordReturnResult::InvalidCommand" },
				{ "InvalidDataUrl.Name", "EDiscordReturnResult::InvalidDataUrl" },
				{ "InvalidEntitlement.Name", "EDiscordReturnResult::InvalidEntitlement" },
				{ "InvalidEvent.Name", "EDiscordReturnResult::InvalidEvent" },
				{ "InvalidFilename.Name", "EDiscordReturnResult::InvalidFilename" },
				{ "InvalidFileSize.Name", "EDiscordReturnResult::InvalidFileSize" },
				{ "InvalidGiftCode.Name", "EDiscordReturnResult::InvalidGiftCode" },
				{ "InvalidGuild.Name", "EDiscordReturnResult::InvalidGuild" },
				{ "InvalidInvite.Name", "EDiscordReturnResult::InvalidInvite" },
				{ "InvalidJoinSecret.Name", "EDiscordReturnResult::InvalidJoinSecret" },
				{ "InvalidLobbySecret.Name", "EDiscordReturnResult::InvalidLobbySecret" },
				{ "InvalidOrigin.Name", "EDiscordReturnResult::InvalidOrigin" },
				{ "InvalidPayload.Name", "EDiscordReturnResult::InvalidPayload" },
				{ "InvalidPermissions.Name", "EDiscordReturnResult::InvalidPermissions" },
				{ "InvalidSecret.Name", "EDiscordReturnResult::InvalidSecret" },
				{ "InvalidVersion.Name", "EDiscordReturnResult::InvalidVersion" },
				{ "LobbyFull.Name", "EDiscordReturnResult::LobbyFull" },
				{ "LockFailed.Name", "EDiscordReturnResult::LockFailed" },
				{ "ModuleRelativePath", "Public/DiscordObject.h" },
				{ "NoEligibleActivity.Name", "EDiscordReturnResult::NoEligibleActivity" },
				{ "NotAuthenticated.Name", "EDiscordReturnResult::NotAuthenticated" },
				{ "NotFetched.Name", "EDiscordReturnResult::NotFetched" },
				{ "NotFiltered.Name", "EDiscordReturnResult::NotFiltered" },
				{ "NotFound.Name", "EDiscordReturnResult::NotFound" },
				{ "NotInstalled.Name", "EDiscordReturnResult::NotInstalled" },
				{ "NotRunning.Name", "EDiscordReturnResult::NotRunning" },
				{ "OAuth2Error.Name", "EDiscordReturnResult::OAuth2Error" },
				{ "Ok.Name", "EDiscordReturnResult::Ok" },
				{ "PurchaseCanceled.Name", "EDiscordReturnResult::PurchaseCanceled" },
				{ "PurchaseError.Name", "EDiscordReturnResult::PurchaseError" },
				{ "RateLimited.Name", "EDiscordReturnResult::RateLimited" },
				{ "SelectChannelTimeout.Name", "EDiscordReturnResult::SelectChannelTimeout" },
				{ "SelectVoiceForceRequired.Name", "EDiscordReturnResult::SelectVoiceForceRequired" },
				{ "ServiceUnavailable.Name", "EDiscordReturnResult::ServiceUnavailable" },
				{ "TransactionAborted.Name", "EDiscordReturnResult::TransactionAborted" },
				{ "UnauthorizedForAchievement.Name", "EDiscordReturnResult::UnauthorizedForAchievement" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_DiscordUE4,
				nullptr,
				"EDiscordReturnResult",
				"EDiscordReturnResult",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	DEFINE_FUNCTION(UDiscordObject::execStopDiscordTimer)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopDiscordTimer();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDiscordObject::execStartDiscordTimer)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StartDiscordTimer();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDiscordObject::execSetJoinSecret)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_InNewJoinSecret);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetJoinSecret(Z_Param_InNewJoinSecret);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDiscordObject::execSetPartyMax)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_InNewPartyMax);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetPartyMax(Z_Param_InNewPartyMax);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDiscordObject::execSetPartySize)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_InNewPartySize);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetPartySize(Z_Param_InNewPartySize);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDiscordObject::execSetPartyId)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_InNewPartyId);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetPartyId(Z_Param_InNewPartyId);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDiscordObject::execSetSmallImageText)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_InKeyName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSmallImageText(Z_Param_InKeyName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDiscordObject::execSetLargeImageText)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_InKeyName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetLargeImageText(Z_Param_InKeyName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDiscordObject::execSetSmallImage)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_InKeyName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSmallImage(Z_Param_InKeyName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDiscordObject::execSetLargeImage)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_InKeyName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetLargeImage(Z_Param_InKeyName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDiscordObject::execSetDetails)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_InNewDetails);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetDetails(Z_Param_InNewDetails);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDiscordObject::execSetState)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_InNewState);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetState(Z_Param_InNewState);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDiscordObject::execGetDiscordResultString)
	{
		P_GET_ENUM(EDiscordReturnResult,Z_Param_InDiscordResult);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UDiscordObject::GetDiscordResultString(EDiscordReturnResult(Z_Param_InDiscordResult));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDiscordObject::execDestroyDiscordObject)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		UDiscordObject::DestroyDiscordObject();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDiscordObject::execGetDiscordObject)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UDiscordObject**)Z_Param__Result=UDiscordObject::GetDiscordObject();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDiscordObject::execCreateDiscordObject)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_InClientID);
		P_GET_UBOOL(Z_Param_bRequireDiscordRunning);
		P_GET_UBOOL(Z_Param_bStartElapsedTimer);
		P_FINISH;
		P_NATIVE_BEGIN;
		UDiscordObject::CreateDiscordObject(Z_Param_InClientID,Z_Param_bRequireDiscordRunning,Z_Param_bStartElapsedTimer);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDiscordObject::execGetOrCreateDiscordObject)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_InClientID);
		P_GET_UBOOL(Z_Param_bRequireDiscordRunning);
		P_GET_UBOOL(Z_Param_bStartElapsedTimer);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UDiscordObject**)Z_Param__Result=UDiscordObject::GetOrCreateDiscordObject(Z_Param_InClientID,Z_Param_bRequireDiscordRunning,Z_Param_bStartElapsedTimer);
		P_NATIVE_END;
	}
	void UDiscordObject::StaticRegisterNativesUDiscordObject()
	{
		UClass* Class = UDiscordObject::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CreateDiscordObject", &UDiscordObject::execCreateDiscordObject },
			{ "DestroyDiscordObject", &UDiscordObject::execDestroyDiscordObject },
			{ "GetDiscordObject", &UDiscordObject::execGetDiscordObject },
			{ "GetDiscordResultString", &UDiscordObject::execGetDiscordResultString },
			{ "GetOrCreateDiscordObject", &UDiscordObject::execGetOrCreateDiscordObject },
			{ "SetDetails", &UDiscordObject::execSetDetails },
			{ "SetJoinSecret", &UDiscordObject::execSetJoinSecret },
			{ "SetLargeImage", &UDiscordObject::execSetLargeImage },
			{ "SetLargeImageText", &UDiscordObject::execSetLargeImageText },
			{ "SetPartyId", &UDiscordObject::execSetPartyId },
			{ "SetPartyMax", &UDiscordObject::execSetPartyMax },
			{ "SetPartySize", &UDiscordObject::execSetPartySize },
			{ "SetSmallImage", &UDiscordObject::execSetSmallImage },
			{ "SetSmallImageText", &UDiscordObject::execSetSmallImageText },
			{ "SetState", &UDiscordObject::execSetState },
			{ "StartDiscordTimer", &UDiscordObject::execStartDiscordTimer },
			{ "StopDiscordTimer", &UDiscordObject::execStopDiscordTimer },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDiscordObject_CreateDiscordObject_Statics
	{
		struct DiscordObject_eventCreateDiscordObject_Parms
		{
			FString InClientID;
			bool bRequireDiscordRunning;
			bool bStartElapsedTimer;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_InClientID;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bRequireDiscordRunning_MetaData[];
#endif
		static void NewProp_bRequireDiscordRunning_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bRequireDiscordRunning;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bStartElapsedTimer_MetaData[];
#endif
		static void NewProp_bStartElapsedTimer_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bStartElapsedTimer;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDiscordObject_CreateDiscordObject_Statics::NewProp_InClientID = { "InClientID", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DiscordObject_eventCreateDiscordObject_Parms, InClientID), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_CreateDiscordObject_Statics::NewProp_bRequireDiscordRunning_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_UDiscordObject_CreateDiscordObject_Statics::NewProp_bRequireDiscordRunning_SetBit(void* Obj)
	{
		((DiscordObject_eventCreateDiscordObject_Parms*)Obj)->bRequireDiscordRunning = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDiscordObject_CreateDiscordObject_Statics::NewProp_bRequireDiscordRunning = { "bRequireDiscordRunning", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DiscordObject_eventCreateDiscordObject_Parms), &Z_Construct_UFunction_UDiscordObject_CreateDiscordObject_Statics::NewProp_bRequireDiscordRunning_SetBit, METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_CreateDiscordObject_Statics::NewProp_bRequireDiscordRunning_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_CreateDiscordObject_Statics::NewProp_bRequireDiscordRunning_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_CreateDiscordObject_Statics::NewProp_bStartElapsedTimer_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_UDiscordObject_CreateDiscordObject_Statics::NewProp_bStartElapsedTimer_SetBit(void* Obj)
	{
		((DiscordObject_eventCreateDiscordObject_Parms*)Obj)->bStartElapsedTimer = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDiscordObject_CreateDiscordObject_Statics::NewProp_bStartElapsedTimer = { "bStartElapsedTimer", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DiscordObject_eventCreateDiscordObject_Parms), &Z_Construct_UFunction_UDiscordObject_CreateDiscordObject_Statics::NewProp_bStartElapsedTimer_SetBit, METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_CreateDiscordObject_Statics::NewProp_bStartElapsedTimer_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_CreateDiscordObject_Statics::NewProp_bStartElapsedTimer_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDiscordObject_CreateDiscordObject_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDiscordObject_CreateDiscordObject_Statics::NewProp_InClientID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDiscordObject_CreateDiscordObject_Statics::NewProp_bRequireDiscordRunning,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDiscordObject_CreateDiscordObject_Statics::NewProp_bStartElapsedTimer,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_CreateDiscordObject_Statics::Function_MetaDataParams[] = {
		{ "Category", "Discord" },
		{ "Comment", "/**\n\x09* public static UDiscordObject::CreateDiscordObject\n\x09* Creates the static Discord Object Instance.\n\x09* @See Make sure you setup your app as per this documentation https://discord.com/developers/docs/game-sdk/sdk-starter-guide\n\x09* @param InClientID [FString] The client ID of your application after creating it in https://discord.com/developers/\n\x09* @param bRequireDiscordRunning [const bool] If true, the game will close, opens Discord, and will try to launch your game. IMPORTANT NOTE: Only works in packaged game and NOT in Editor, PIE etc.\n\x09* @param bStartElapsedTimer [const bool] If true, rich presence will show elapsed time. You can manually start time stamps by calling Start/Stop Discord Timer.\n\x09**/" },
		{ "CPP_Default_bRequireDiscordRunning", "false" },
		{ "CPP_Default_bStartElapsedTimer", "true" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
		{ "ToolTip", "public static UDiscordObject::CreateDiscordObject\nCreates the static Discord Object Instance.\n@See Make sure you setup your app as per this documentation https://discord.com/developers/docs/game-sdk/sdk-starter-guide\n@param InClientID [FString] The client ID of your application after creating it in https://discord.com/developers/\n@param bRequireDiscordRunning [const bool] If true, the game will close, opens Discord, and will try to launch your game. IMPORTANT NOTE: Only works in packaged game and NOT in Editor, PIE etc.\n@param bStartElapsedTimer [const bool] If true, rich presence will show elapsed time. You can manually start time stamps by calling Start/Stop Discord Timer." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDiscordObject_CreateDiscordObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDiscordObject, nullptr, "CreateDiscordObject", nullptr, nullptr, sizeof(DiscordObject_eventCreateDiscordObject_Parms), Z_Construct_UFunction_UDiscordObject_CreateDiscordObject_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_CreateDiscordObject_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_CreateDiscordObject_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_CreateDiscordObject_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDiscordObject_CreateDiscordObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDiscordObject_CreateDiscordObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDiscordObject_DestroyDiscordObject_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_DestroyDiscordObject_Statics::Function_MetaDataParams[] = {
		{ "Category", "Discord" },
		{ "Comment", "/**\n\x09* public static UDiscordObject::DestroyDiscordObject\n\x09* Destroys the static Discord Object Instance.\n\x09**/" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
		{ "ToolTip", "public static UDiscordObject::DestroyDiscordObject\nDestroys the static Discord Object Instance." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDiscordObject_DestroyDiscordObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDiscordObject, nullptr, "DestroyDiscordObject", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_DestroyDiscordObject_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_DestroyDiscordObject_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDiscordObject_DestroyDiscordObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDiscordObject_DestroyDiscordObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDiscordObject_GetDiscordObject_Statics
	{
		struct DiscordObject_eventGetDiscordObject_Parms
		{
			UDiscordObject* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDiscordObject_GetDiscordObject_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DiscordObject_eventGetDiscordObject_Parms, ReturnValue), Z_Construct_UClass_UDiscordObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDiscordObject_GetDiscordObject_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDiscordObject_GetDiscordObject_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_GetDiscordObject_Statics::Function_MetaDataParams[] = {
		{ "Category", "Discord" },
		{ "Comment", "/**\n\x09* public static UDiscordObject::GetDiscordObject\n\x09* Returns static DiscordObjectInstance.\n\x09* @return [UDiscordObject*] Discord object instance if valid.\n\x09**/" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
		{ "ToolTip", "public static UDiscordObject::GetDiscordObject\nReturns static DiscordObjectInstance.\n@return [UDiscordObject*] Discord object instance if valid." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDiscordObject_GetDiscordObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDiscordObject, nullptr, "GetDiscordObject", nullptr, nullptr, sizeof(DiscordObject_eventGetDiscordObject_Parms), Z_Construct_UFunction_UDiscordObject_GetDiscordObject_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_GetDiscordObject_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_GetDiscordObject_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_GetDiscordObject_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDiscordObject_GetDiscordObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDiscordObject_GetDiscordObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDiscordObject_GetDiscordResultString_Statics
	{
		struct DiscordObject_eventGetDiscordResultString_Parms
		{
			EDiscordReturnResult InDiscordResult;
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_InDiscordResult_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_InDiscordResult;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UDiscordObject_GetDiscordResultString_Statics::NewProp_InDiscordResult_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UDiscordObject_GetDiscordResultString_Statics::NewProp_InDiscordResult = { "InDiscordResult", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DiscordObject_eventGetDiscordResultString_Parms, InDiscordResult), Z_Construct_UEnum_DiscordUE4_EDiscordReturnResult, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_GetDiscordResultString_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDiscordObject_GetDiscordResultString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000582, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DiscordObject_eventGetDiscordResultString_Parms, ReturnValue), METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_GetDiscordResultString_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_GetDiscordResultString_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDiscordObject_GetDiscordResultString_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDiscordObject_GetDiscordResultString_Statics::NewProp_InDiscordResult_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDiscordObject_GetDiscordResultString_Statics::NewProp_InDiscordResult,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDiscordObject_GetDiscordResultString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_GetDiscordResultString_Statics::Function_MetaDataParams[] = {
		{ "Category", "Discord" },
		{ "Comment", "/**\n\x09* public static UDiscordObject::GetDiscordResultString\n\x09* Returns a string representation of given discord result. Can be used with Discord delegates. @See OnStateSet, OnDetailsSet etc.\n\x09* @param InDiscordResult [EDiscordReturnResult] Result to check for.\n\x09* @return [const FString] Human readable string representation of the given result.\n\x09**/" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
		{ "ToolTip", "public static UDiscordObject::GetDiscordResultString\nReturns a string representation of given discord result. Can be used with Discord delegates. @See OnStateSet, OnDetailsSet etc.\n@param InDiscordResult [EDiscordReturnResult] Result to check for.\n@return [const FString] Human readable string representation of the given result." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDiscordObject_GetDiscordResultString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDiscordObject, nullptr, "GetDiscordResultString", nullptr, nullptr, sizeof(DiscordObject_eventGetDiscordResultString_Parms), Z_Construct_UFunction_UDiscordObject_GetDiscordResultString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_GetDiscordResultString_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_GetDiscordResultString_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_GetDiscordResultString_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDiscordObject_GetDiscordResultString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDiscordObject_GetDiscordResultString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject_Statics
	{
		struct DiscordObject_eventGetOrCreateDiscordObject_Parms
		{
			FString InClientID;
			bool bRequireDiscordRunning;
			bool bStartElapsedTimer;
			UDiscordObject* ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_InClientID;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bRequireDiscordRunning_MetaData[];
#endif
		static void NewProp_bRequireDiscordRunning_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bRequireDiscordRunning;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bStartElapsedTimer_MetaData[];
#endif
		static void NewProp_bStartElapsedTimer_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bStartElapsedTimer;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject_Statics::NewProp_InClientID = { "InClientID", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DiscordObject_eventGetOrCreateDiscordObject_Parms, InClientID), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject_Statics::NewProp_bRequireDiscordRunning_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject_Statics::NewProp_bRequireDiscordRunning_SetBit(void* Obj)
	{
		((DiscordObject_eventGetOrCreateDiscordObject_Parms*)Obj)->bRequireDiscordRunning = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject_Statics::NewProp_bRequireDiscordRunning = { "bRequireDiscordRunning", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DiscordObject_eventGetOrCreateDiscordObject_Parms), &Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject_Statics::NewProp_bRequireDiscordRunning_SetBit, METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject_Statics::NewProp_bRequireDiscordRunning_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject_Statics::NewProp_bRequireDiscordRunning_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject_Statics::NewProp_bStartElapsedTimer_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject_Statics::NewProp_bStartElapsedTimer_SetBit(void* Obj)
	{
		((DiscordObject_eventGetOrCreateDiscordObject_Parms*)Obj)->bStartElapsedTimer = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject_Statics::NewProp_bStartElapsedTimer = { "bStartElapsedTimer", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DiscordObject_eventGetOrCreateDiscordObject_Parms), &Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject_Statics::NewProp_bStartElapsedTimer_SetBit, METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject_Statics::NewProp_bStartElapsedTimer_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject_Statics::NewProp_bStartElapsedTimer_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DiscordObject_eventGetOrCreateDiscordObject_Parms, ReturnValue), Z_Construct_UClass_UDiscordObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject_Statics::NewProp_InClientID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject_Statics::NewProp_bRequireDiscordRunning,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject_Statics::NewProp_bStartElapsedTimer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject_Statics::Function_MetaDataParams[] = {
		{ "Category", "Discord" },
		{ "CPP_Default_bRequireDiscordRunning", "false" },
		{ "CPP_Default_bStartElapsedTimer", "true" },
		{ "DeprecatedFunction", "" },
		{ "DeprecationMessage", "Please use Create Discord Object and Get Discord Object methods." },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDiscordObject, nullptr, "GetOrCreateDiscordObject", nullptr, nullptr, sizeof(DiscordObject_eventGetOrCreateDiscordObject_Parms), Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDiscordObject_SetDetails_Statics
	{
		struct DiscordObject_eventSetDetails_Parms
		{
			FString InNewDetails;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_InNewDetails;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDiscordObject_SetDetails_Statics::NewProp_InNewDetails = { "InNewDetails", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DiscordObject_eventSetDetails_Parms, InNewDetails), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDiscordObject_SetDetails_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDiscordObject_SetDetails_Statics::NewProp_InNewDetails,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_SetDetails_Statics::Function_MetaDataParams[] = {
		{ "Category", "Discord" },
		{ "Comment", "/**\n\x09* public UDiscordObject::SetDetails\n\x09* Sets new details that you can see on Discord Rich Presence.\n\x09* @See OnDetailsSet delegate.\n\x09* @param InNewDetails [FString] Details to set.\n\x09**/" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
		{ "ToolTip", "public UDiscordObject::SetDetails\nSets new details that you can see on Discord Rich Presence.\n@See OnDetailsSet delegate.\n@param InNewDetails [FString] Details to set." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDiscordObject_SetDetails_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDiscordObject, nullptr, "SetDetails", nullptr, nullptr, sizeof(DiscordObject_eventSetDetails_Parms), Z_Construct_UFunction_UDiscordObject_SetDetails_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_SetDetails_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_SetDetails_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_SetDetails_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDiscordObject_SetDetails()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDiscordObject_SetDetails_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDiscordObject_SetJoinSecret_Statics
	{
		struct DiscordObject_eventSetJoinSecret_Parms
		{
			FString InNewJoinSecret;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InNewJoinSecret_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_InNewJoinSecret;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_SetJoinSecret_Statics::NewProp_InNewJoinSecret_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDiscordObject_SetJoinSecret_Statics::NewProp_InNewJoinSecret = { "InNewJoinSecret", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DiscordObject_eventSetJoinSecret_Parms, InNewJoinSecret), METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_SetJoinSecret_Statics::NewProp_InNewJoinSecret_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_SetJoinSecret_Statics::NewProp_InNewJoinSecret_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDiscordObject_SetJoinSecret_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDiscordObject_SetJoinSecret_Statics::NewProp_InNewJoinSecret,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_SetJoinSecret_Statics::Function_MetaDataParams[] = {
		{ "Category", "Discord" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDiscordObject_SetJoinSecret_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDiscordObject, nullptr, "SetJoinSecret", nullptr, nullptr, sizeof(DiscordObject_eventSetJoinSecret_Parms), Z_Construct_UFunction_UDiscordObject_SetJoinSecret_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_SetJoinSecret_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_SetJoinSecret_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_SetJoinSecret_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDiscordObject_SetJoinSecret()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDiscordObject_SetJoinSecret_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDiscordObject_SetLargeImage_Statics
	{
		struct DiscordObject_eventSetLargeImage_Parms
		{
			FString InKeyName;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InKeyName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_InKeyName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_SetLargeImage_Statics::NewProp_InKeyName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDiscordObject_SetLargeImage_Statics::NewProp_InKeyName = { "InKeyName", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DiscordObject_eventSetLargeImage_Parms, InKeyName), METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_SetLargeImage_Statics::NewProp_InKeyName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_SetLargeImage_Statics::NewProp_InKeyName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDiscordObject_SetLargeImage_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDiscordObject_SetLargeImage_Statics::NewProp_InKeyName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_SetLargeImage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Discord" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDiscordObject_SetLargeImage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDiscordObject, nullptr, "SetLargeImage", nullptr, nullptr, sizeof(DiscordObject_eventSetLargeImage_Parms), Z_Construct_UFunction_UDiscordObject_SetLargeImage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_SetLargeImage_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_SetLargeImage_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_SetLargeImage_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDiscordObject_SetLargeImage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDiscordObject_SetLargeImage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDiscordObject_SetLargeImageText_Statics
	{
		struct DiscordObject_eventSetLargeImageText_Parms
		{
			FString InKeyName;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InKeyName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_InKeyName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_SetLargeImageText_Statics::NewProp_InKeyName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDiscordObject_SetLargeImageText_Statics::NewProp_InKeyName = { "InKeyName", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DiscordObject_eventSetLargeImageText_Parms, InKeyName), METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_SetLargeImageText_Statics::NewProp_InKeyName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_SetLargeImageText_Statics::NewProp_InKeyName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDiscordObject_SetLargeImageText_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDiscordObject_SetLargeImageText_Statics::NewProp_InKeyName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_SetLargeImageText_Statics::Function_MetaDataParams[] = {
		{ "Category", "Discord" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDiscordObject_SetLargeImageText_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDiscordObject, nullptr, "SetLargeImageText", nullptr, nullptr, sizeof(DiscordObject_eventSetLargeImageText_Parms), Z_Construct_UFunction_UDiscordObject_SetLargeImageText_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_SetLargeImageText_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_SetLargeImageText_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_SetLargeImageText_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDiscordObject_SetLargeImageText()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDiscordObject_SetLargeImageText_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDiscordObject_SetPartyId_Statics
	{
		struct DiscordObject_eventSetPartyId_Parms
		{
			FString InNewPartyId;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InNewPartyId_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_InNewPartyId;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_SetPartyId_Statics::NewProp_InNewPartyId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDiscordObject_SetPartyId_Statics::NewProp_InNewPartyId = { "InNewPartyId", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DiscordObject_eventSetPartyId_Parms, InNewPartyId), METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_SetPartyId_Statics::NewProp_InNewPartyId_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_SetPartyId_Statics::NewProp_InNewPartyId_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDiscordObject_SetPartyId_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDiscordObject_SetPartyId_Statics::NewProp_InNewPartyId,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_SetPartyId_Statics::Function_MetaDataParams[] = {
		{ "Category", "Discord" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDiscordObject_SetPartyId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDiscordObject, nullptr, "SetPartyId", nullptr, nullptr, sizeof(DiscordObject_eventSetPartyId_Parms), Z_Construct_UFunction_UDiscordObject_SetPartyId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_SetPartyId_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_SetPartyId_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_SetPartyId_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDiscordObject_SetPartyId()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDiscordObject_SetPartyId_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDiscordObject_SetPartyMax_Statics
	{
		struct DiscordObject_eventSetPartyMax_Parms
		{
			int32 InNewPartyMax;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InNewPartyMax_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_InNewPartyMax;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_SetPartyMax_Statics::NewProp_InNewPartyMax_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDiscordObject_SetPartyMax_Statics::NewProp_InNewPartyMax = { "InNewPartyMax", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DiscordObject_eventSetPartyMax_Parms, InNewPartyMax), METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_SetPartyMax_Statics::NewProp_InNewPartyMax_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_SetPartyMax_Statics::NewProp_InNewPartyMax_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDiscordObject_SetPartyMax_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDiscordObject_SetPartyMax_Statics::NewProp_InNewPartyMax,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_SetPartyMax_Statics::Function_MetaDataParams[] = {
		{ "Category", "Discord" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDiscordObject_SetPartyMax_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDiscordObject, nullptr, "SetPartyMax", nullptr, nullptr, sizeof(DiscordObject_eventSetPartyMax_Parms), Z_Construct_UFunction_UDiscordObject_SetPartyMax_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_SetPartyMax_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_SetPartyMax_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_SetPartyMax_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDiscordObject_SetPartyMax()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDiscordObject_SetPartyMax_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDiscordObject_SetPartySize_Statics
	{
		struct DiscordObject_eventSetPartySize_Parms
		{
			int32 InNewPartySize;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InNewPartySize_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_InNewPartySize;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_SetPartySize_Statics::NewProp_InNewPartySize_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDiscordObject_SetPartySize_Statics::NewProp_InNewPartySize = { "InNewPartySize", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DiscordObject_eventSetPartySize_Parms, InNewPartySize), METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_SetPartySize_Statics::NewProp_InNewPartySize_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_SetPartySize_Statics::NewProp_InNewPartySize_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDiscordObject_SetPartySize_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDiscordObject_SetPartySize_Statics::NewProp_InNewPartySize,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_SetPartySize_Statics::Function_MetaDataParams[] = {
		{ "Category", "Discord" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDiscordObject_SetPartySize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDiscordObject, nullptr, "SetPartySize", nullptr, nullptr, sizeof(DiscordObject_eventSetPartySize_Parms), Z_Construct_UFunction_UDiscordObject_SetPartySize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_SetPartySize_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_SetPartySize_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_SetPartySize_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDiscordObject_SetPartySize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDiscordObject_SetPartySize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDiscordObject_SetSmallImage_Statics
	{
		struct DiscordObject_eventSetSmallImage_Parms
		{
			FString InKeyName;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InKeyName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_InKeyName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_SetSmallImage_Statics::NewProp_InKeyName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDiscordObject_SetSmallImage_Statics::NewProp_InKeyName = { "InKeyName", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DiscordObject_eventSetSmallImage_Parms, InKeyName), METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_SetSmallImage_Statics::NewProp_InKeyName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_SetSmallImage_Statics::NewProp_InKeyName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDiscordObject_SetSmallImage_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDiscordObject_SetSmallImage_Statics::NewProp_InKeyName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_SetSmallImage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Discord" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDiscordObject_SetSmallImage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDiscordObject, nullptr, "SetSmallImage", nullptr, nullptr, sizeof(DiscordObject_eventSetSmallImage_Parms), Z_Construct_UFunction_UDiscordObject_SetSmallImage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_SetSmallImage_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_SetSmallImage_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_SetSmallImage_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDiscordObject_SetSmallImage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDiscordObject_SetSmallImage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDiscordObject_SetSmallImageText_Statics
	{
		struct DiscordObject_eventSetSmallImageText_Parms
		{
			FString InKeyName;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InKeyName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_InKeyName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_SetSmallImageText_Statics::NewProp_InKeyName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDiscordObject_SetSmallImageText_Statics::NewProp_InKeyName = { "InKeyName", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DiscordObject_eventSetSmallImageText_Parms, InKeyName), METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_SetSmallImageText_Statics::NewProp_InKeyName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_SetSmallImageText_Statics::NewProp_InKeyName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDiscordObject_SetSmallImageText_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDiscordObject_SetSmallImageText_Statics::NewProp_InKeyName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_SetSmallImageText_Statics::Function_MetaDataParams[] = {
		{ "Category", "Discord" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDiscordObject_SetSmallImageText_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDiscordObject, nullptr, "SetSmallImageText", nullptr, nullptr, sizeof(DiscordObject_eventSetSmallImageText_Parms), Z_Construct_UFunction_UDiscordObject_SetSmallImageText_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_SetSmallImageText_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_SetSmallImageText_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_SetSmallImageText_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDiscordObject_SetSmallImageText()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDiscordObject_SetSmallImageText_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDiscordObject_SetState_Statics
	{
		struct DiscordObject_eventSetState_Parms
		{
			FString InNewState;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_InNewState;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDiscordObject_SetState_Statics::NewProp_InNewState = { "InNewState", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DiscordObject_eventSetState_Parms, InNewState), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDiscordObject_SetState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDiscordObject_SetState_Statics::NewProp_InNewState,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_SetState_Statics::Function_MetaDataParams[] = {
		{ "Category", "Discord" },
		{ "Comment", "/**\n\x09* public UDiscordObject::SetState\n\x09* Sets a new state that you can see on Discord Rich Presence.\n\x09* @See OnStateSet delegate.\n\x09* @param InNewState [FString] State to set.\n\x09**/" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
		{ "ToolTip", "public UDiscordObject::SetState\nSets a new state that you can see on Discord Rich Presence.\n@See OnStateSet delegate.\n@param InNewState [FString] State to set." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDiscordObject_SetState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDiscordObject, nullptr, "SetState", nullptr, nullptr, sizeof(DiscordObject_eventSetState_Parms), Z_Construct_UFunction_UDiscordObject_SetState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_SetState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_SetState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_SetState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDiscordObject_SetState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDiscordObject_SetState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDiscordObject_StartDiscordTimer_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_StartDiscordTimer_Statics::Function_MetaDataParams[] = {
		{ "Category", "Discord" },
		{ "Comment", "/**\n\x09* public UDiscordObject::StartDiscordTimer\n\x09* Starts elapsed timer in Rich Presence.\n\x09**/" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
		{ "ToolTip", "public UDiscordObject::StartDiscordTimer\nStarts elapsed timer in Rich Presence." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDiscordObject_StartDiscordTimer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDiscordObject, nullptr, "StartDiscordTimer", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_StartDiscordTimer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_StartDiscordTimer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDiscordObject_StartDiscordTimer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDiscordObject_StartDiscordTimer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDiscordObject_StopDiscordTimer_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDiscordObject_StopDiscordTimer_Statics::Function_MetaDataParams[] = {
		{ "Category", "Discord" },
		{ "Comment", "/**\n\x09* public UDiscordObject::StopDiscordTimer\n\x09* Stops elapsed timer in Rich Presence.\n\x09**/" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
		{ "ToolTip", "public UDiscordObject::StopDiscordTimer\nStops elapsed timer in Rich Presence." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDiscordObject_StopDiscordTimer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDiscordObject, nullptr, "StopDiscordTimer", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDiscordObject_StopDiscordTimer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDiscordObject_StopDiscordTimer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDiscordObject_StopDiscordTimer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDiscordObject_StopDiscordTimer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UDiscordObject_NoRegister()
	{
		return UDiscordObject::StaticClass();
	}
	struct Z_Construct_UClass_UDiscordObject_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnStateSet_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStateSet;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnDetailsSet_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDetailsSet;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnLargeImageSet_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnLargeImageSet;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnSmallImageSet_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSmallImageSet;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnPartyIdSet_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPartyIdSet;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnPartySizeSet_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPartySizeSet;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnPartyMaxSet_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPartyMaxSet;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnJoinSecretSet_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnJoinSecretSet;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnLargeTextSet_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnLargeTextSet;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnSmallTextSet_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSmallTextSet;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnTimerStart_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTimerStart;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnTimerEnd_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTimerEnd;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDiscordObject_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_DiscordUE4,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UDiscordObject_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDiscordObject_CreateDiscordObject, "CreateDiscordObject" }, // 4254265224
		{ &Z_Construct_UFunction_UDiscordObject_DestroyDiscordObject, "DestroyDiscordObject" }, // 1131247380
		{ &Z_Construct_UFunction_UDiscordObject_GetDiscordObject, "GetDiscordObject" }, // 1141383161
		{ &Z_Construct_UFunction_UDiscordObject_GetDiscordResultString, "GetDiscordResultString" }, // 2162084413
		{ &Z_Construct_UFunction_UDiscordObject_GetOrCreateDiscordObject, "GetOrCreateDiscordObject" }, // 266742310
		{ &Z_Construct_UFunction_UDiscordObject_SetDetails, "SetDetails" }, // 1396543166
		{ &Z_Construct_UFunction_UDiscordObject_SetJoinSecret, "SetJoinSecret" }, // 1646443859
		{ &Z_Construct_UFunction_UDiscordObject_SetLargeImage, "SetLargeImage" }, // 980805714
		{ &Z_Construct_UFunction_UDiscordObject_SetLargeImageText, "SetLargeImageText" }, // 3149732401
		{ &Z_Construct_UFunction_UDiscordObject_SetPartyId, "SetPartyId" }, // 3350938317
		{ &Z_Construct_UFunction_UDiscordObject_SetPartyMax, "SetPartyMax" }, // 1193288812
		{ &Z_Construct_UFunction_UDiscordObject_SetPartySize, "SetPartySize" }, // 403986619
		{ &Z_Construct_UFunction_UDiscordObject_SetSmallImage, "SetSmallImage" }, // 2466053258
		{ &Z_Construct_UFunction_UDiscordObject_SetSmallImageText, "SetSmallImageText" }, // 724151121
		{ &Z_Construct_UFunction_UDiscordObject_SetState, "SetState" }, // 978482115
		{ &Z_Construct_UFunction_UDiscordObject_StartDiscordTimer, "StartDiscordTimer" }, // 868198479
		{ &Z_Construct_UFunction_UDiscordObject_StopDiscordTimer, "StopDiscordTimer" }, // 2317131280
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDiscordObject_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "DiscordObject.h" },
		{ "IsBlueprintBase", "false" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnStateSet_MetaData[] = {
		{ "Category", "Discord|Delegates" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnStateSet = { "OnStateSet", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDiscordObject, OnStateSet), Z_Construct_UDelegateFunction_DiscordUE4_OnDiscordResult__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnStateSet_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnStateSet_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnDetailsSet_MetaData[] = {
		{ "Category", "Discord|Delegates" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnDetailsSet = { "OnDetailsSet", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDiscordObject, OnDetailsSet), Z_Construct_UDelegateFunction_DiscordUE4_OnDiscordResult__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnDetailsSet_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnDetailsSet_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnLargeImageSet_MetaData[] = {
		{ "Category", "Discord|Delegates" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnLargeImageSet = { "OnLargeImageSet", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDiscordObject, OnLargeImageSet), Z_Construct_UDelegateFunction_DiscordUE4_OnDiscordResult__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnLargeImageSet_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnLargeImageSet_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnSmallImageSet_MetaData[] = {
		{ "Category", "Discord|Delegates" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnSmallImageSet = { "OnSmallImageSet", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDiscordObject, OnSmallImageSet), Z_Construct_UDelegateFunction_DiscordUE4_OnDiscordResult__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnSmallImageSet_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnSmallImageSet_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnPartyIdSet_MetaData[] = {
		{ "Category", "Discord|Delegates" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnPartyIdSet = { "OnPartyIdSet", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDiscordObject, OnPartyIdSet), Z_Construct_UDelegateFunction_DiscordUE4_OnDiscordResult__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnPartyIdSet_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnPartyIdSet_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnPartySizeSet_MetaData[] = {
		{ "Category", "Discord|Delegates" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnPartySizeSet = { "OnPartySizeSet", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDiscordObject, OnPartySizeSet), Z_Construct_UDelegateFunction_DiscordUE4_OnDiscordResult__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnPartySizeSet_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnPartySizeSet_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnPartyMaxSet_MetaData[] = {
		{ "Category", "Discord|Delegates" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnPartyMaxSet = { "OnPartyMaxSet", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDiscordObject, OnPartyMaxSet), Z_Construct_UDelegateFunction_DiscordUE4_OnDiscordResult__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnPartyMaxSet_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnPartyMaxSet_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnJoinSecretSet_MetaData[] = {
		{ "Category", "Discord|Delegates" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnJoinSecretSet = { "OnJoinSecretSet", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDiscordObject, OnJoinSecretSet), Z_Construct_UDelegateFunction_DiscordUE4_OnDiscordResult__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnJoinSecretSet_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnJoinSecretSet_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnLargeTextSet_MetaData[] = {
		{ "Category", "Discord|Delegates" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnLargeTextSet = { "OnLargeTextSet", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDiscordObject, OnLargeTextSet), Z_Construct_UDelegateFunction_DiscordUE4_OnDiscordResult__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnLargeTextSet_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnLargeTextSet_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnSmallTextSet_MetaData[] = {
		{ "Category", "Discord|Delegates" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnSmallTextSet = { "OnSmallTextSet", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDiscordObject, OnSmallTextSet), Z_Construct_UDelegateFunction_DiscordUE4_OnDiscordResult__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnSmallTextSet_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnSmallTextSet_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnTimerStart_MetaData[] = {
		{ "Category", "Discord|Delegates" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnTimerStart = { "OnTimerStart", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDiscordObject, OnTimerStart), Z_Construct_UDelegateFunction_DiscordUE4_OnDiscordResult__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnTimerStart_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnTimerStart_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnTimerEnd_MetaData[] = {
		{ "Category", "Discord|Delegates" },
		{ "ModuleRelativePath", "Public/DiscordObject.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnTimerEnd = { "OnTimerEnd", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDiscordObject, OnTimerEnd), Z_Construct_UDelegateFunction_DiscordUE4_OnDiscordResult__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnTimerEnd_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnTimerEnd_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDiscordObject_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnStateSet,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnDetailsSet,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnLargeImageSet,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnSmallImageSet,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnPartyIdSet,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnPartySizeSet,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnPartyMaxSet,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnJoinSecretSet,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnLargeTextSet,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnSmallTextSet,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnTimerStart,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDiscordObject_Statics::NewProp_OnTimerEnd,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDiscordObject_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDiscordObject>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UDiscordObject_Statics::ClassParams = {
		&UDiscordObject::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UDiscordObject_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UDiscordObject_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UDiscordObject_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UDiscordObject_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UDiscordObject()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UDiscordObject_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UDiscordObject, 3752768927);
	template<> DISCORDUE4_API UClass* StaticClass<UDiscordObject>()
	{
		return UDiscordObject::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UDiscordObject(Z_Construct_UClass_UDiscordObject, &UDiscordObject::StaticClass, TEXT("/Script/DiscordUE4"), TEXT("UDiscordObject"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDiscordObject);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
