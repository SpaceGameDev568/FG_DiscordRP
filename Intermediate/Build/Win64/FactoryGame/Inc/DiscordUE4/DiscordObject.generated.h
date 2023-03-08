// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EDiscordReturnResult : uint8;
class UDiscordObject;
#ifdef DISCORDUE4_DiscordObject_generated_h
#error "DiscordObject.generated.h already included, missing '#pragma once' in DiscordObject.h"
#endif
#define DISCORDUE4_DiscordObject_generated_h

#define SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h_59_DELEGATE \
struct _Script_DiscordUE4_eventOnDiscordResult_Parms \
{ \
	EDiscordReturnResult StateSetResult; \
}; \
static inline void FOnDiscordResult_DelegateWrapper(const FMulticastScriptDelegate& OnDiscordResult, EDiscordReturnResult StateSetResult) \
{ \
	_Script_DiscordUE4_eventOnDiscordResult_Parms Parms; \
	Parms.StateSetResult=StateSetResult; \
	OnDiscordResult.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h_64_SPARSE_DATA
#define SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h_64_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execStopDiscordTimer); \
	DECLARE_FUNCTION(execStartDiscordTimer); \
	DECLARE_FUNCTION(execSetJoinSecret); \
	DECLARE_FUNCTION(execSetPartyMax); \
	DECLARE_FUNCTION(execSetPartySize); \
	DECLARE_FUNCTION(execSetPartyId); \
	DECLARE_FUNCTION(execSetSmallImageText); \
	DECLARE_FUNCTION(execSetLargeImageText); \
	DECLARE_FUNCTION(execSetSmallImage); \
	DECLARE_FUNCTION(execSetLargeImage); \
	DECLARE_FUNCTION(execSetDetails); \
	DECLARE_FUNCTION(execSetState); \
	DECLARE_FUNCTION(execGetDiscordResultString); \
	DECLARE_FUNCTION(execDestroyDiscordObject); \
	DECLARE_FUNCTION(execGetDiscordObject); \
	DECLARE_FUNCTION(execCreateDiscordObject); \
	DECLARE_FUNCTION(execGetOrCreateDiscordObject);


#define SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h_64_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execStopDiscordTimer); \
	DECLARE_FUNCTION(execStartDiscordTimer); \
	DECLARE_FUNCTION(execSetJoinSecret); \
	DECLARE_FUNCTION(execSetPartyMax); \
	DECLARE_FUNCTION(execSetPartySize); \
	DECLARE_FUNCTION(execSetPartyId); \
	DECLARE_FUNCTION(execSetSmallImageText); \
	DECLARE_FUNCTION(execSetLargeImageText); \
	DECLARE_FUNCTION(execSetSmallImage); \
	DECLARE_FUNCTION(execSetLargeImage); \
	DECLARE_FUNCTION(execSetDetails); \
	DECLARE_FUNCTION(execSetState); \
	DECLARE_FUNCTION(execGetDiscordResultString); \
	DECLARE_FUNCTION(execDestroyDiscordObject); \
	DECLARE_FUNCTION(execGetDiscordObject); \
	DECLARE_FUNCTION(execCreateDiscordObject); \
	DECLARE_FUNCTION(execGetOrCreateDiscordObject);


#define SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h_64_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDiscordObject(); \
	friend struct Z_Construct_UClass_UDiscordObject_Statics; \
public: \
	DECLARE_CLASS(UDiscordObject, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DiscordUE4"), NO_API) \
	DECLARE_SERIALIZER(UDiscordObject)


#define SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h_64_INCLASS \
private: \
	static void StaticRegisterNativesUDiscordObject(); \
	friend struct Z_Construct_UClass_UDiscordObject_Statics; \
public: \
	DECLARE_CLASS(UDiscordObject, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DiscordUE4"), NO_API) \
	DECLARE_SERIALIZER(UDiscordObject)


#define SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h_64_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDiscordObject(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDiscordObject) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDiscordObject); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDiscordObject); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDiscordObject(UDiscordObject&&); \
	NO_API UDiscordObject(const UDiscordObject&); \
public:


#define SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h_64_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDiscordObject(UDiscordObject&&); \
	NO_API UDiscordObject(const UDiscordObject&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDiscordObject); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDiscordObject); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDiscordObject)


#define SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h_64_PRIVATE_PROPERTY_OFFSET
#define SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h_61_PROLOG
#define SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h_64_FRIENDS \
private:


#define SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h_64_INLINE_ACCESSORS \
public:


#define SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h_64_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h_64_PRIVATE_PROPERTY_OFFSET \
	SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h_64_SPARSE_DATA \
	SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h_64_RPC_WRAPPERS \
	SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h_64_INCLASS \
	SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h_64_STANDARD_CONSTRUCTORS \
	SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h_64_FRIENDS \
	SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h_64_INLINE_ACCESSORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h_64_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h_64_PRIVATE_PROPERTY_OFFSET \
	SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h_64_SPARSE_DATA \
	SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h_64_RPC_WRAPPERS_NO_PURE_DECLS \
	SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h_64_INCLASS_NO_PURE_DECLS \
	SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h_64_ENHANCED_CONSTRUCTORS \
	SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h_64_FRIENDS \
	SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h_64_INLINE_ACCESSORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> DISCORDUE4_API UClass* StaticClass<class UDiscordObject>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SatisfactoryModLoader_Plugins_FG_DiscordRP_Source_DiscordUE4_Public_DiscordObject_h


#define FOREACH_ENUM_EDISCORDRETURNRESULT(op) \
	op(EDiscordReturnResult::Ok) \
	op(EDiscordReturnResult::ServiceUnavailable) \
	op(EDiscordReturnResult::InvalidVersion) \
	op(EDiscordReturnResult::LockFailed) \
	op(EDiscordReturnResult::InternalError) \
	op(EDiscordReturnResult::InvalidPayload) \
	op(EDiscordReturnResult::InvalidCommand) \
	op(EDiscordReturnResult::InvalidPermissions) \
	op(EDiscordReturnResult::NotFetched) \
	op(EDiscordReturnResult::NotFound) \
	op(EDiscordReturnResult::Conflict) \
	op(EDiscordReturnResult::InvalidSecret) \
	op(EDiscordReturnResult::InvalidJoinSecret) \
	op(EDiscordReturnResult::NoEligibleActivity) \
	op(EDiscordReturnResult::InvalidInvite) \
	op(EDiscordReturnResult::NotAuthenticated) \
	op(EDiscordReturnResult::InvalidAccessToken) \
	op(EDiscordReturnResult::ApplicationMismatch) \
	op(EDiscordReturnResult::InvalidDataUrl) \
	op(EDiscordReturnResult::InvalidBase64) \
	op(EDiscordReturnResult::NotFiltered) \
	op(EDiscordReturnResult::LobbyFull) \
	op(EDiscordReturnResult::InvalidLobbySecret) \
	op(EDiscordReturnResult::InvalidFilename) \
	op(EDiscordReturnResult::InvalidFileSize) \
	op(EDiscordReturnResult::InvalidEntitlement) \
	op(EDiscordReturnResult::NotInstalled) \
	op(EDiscordReturnResult::NotRunning) \
	op(EDiscordReturnResult::InsufficientBuffer) \
	op(EDiscordReturnResult::PurchaseCanceled) \
	op(EDiscordReturnResult::InvalidGuild) \
	op(EDiscordReturnResult::InvalidEvent) \
	op(EDiscordReturnResult::InvalidChannel) \
	op(EDiscordReturnResult::InvalidOrigin) \
	op(EDiscordReturnResult::RateLimited) \
	op(EDiscordReturnResult::OAuth2Error) \
	op(EDiscordReturnResult::SelectChannelTimeout) \
	op(EDiscordReturnResult::GetGuildTimeout) \
	op(EDiscordReturnResult::SelectVoiceForceRequired) \
	op(EDiscordReturnResult::CaptureShortcutAlreadyListening) \
	op(EDiscordReturnResult::UnauthorizedForAchievement) \
	op(EDiscordReturnResult::InvalidGiftCode) \
	op(EDiscordReturnResult::PurchaseError) \
	op(EDiscordReturnResult::TransactionAborted) 

enum class EDiscordReturnResult : uint8;
template<> DISCORDUE4_API UEnum* StaticEnum<EDiscordReturnResult>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
