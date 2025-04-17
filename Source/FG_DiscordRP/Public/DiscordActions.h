// Copyright 2023 - 2025 Jesse Hodgson

#pragma once

#include "CoreMinimal.h"
#include "DRP_ConfigStruct.h"
#include "DiscordPartnerSDK/Public/DiscordLocalPlayerSubsystem.h"
#include "DiscordActions.generated.h"

UCLASS()
class FG_DISCORDRP_API ADiscordActions : public AActor
{
	GENERATED_BODY()

public:

	UDiscordActivity* Activity;

	UDiscordActivityAssets* Assets;

	EDiscordClientStatus DiscordClientStatus;

	FString DiscordAccessToken;
	FString DiscordRefreshToken;
	//int32 DiscordRefreshTokenType;

	FDRP_ConfigStruct ModConfig; // Our global mod configuration structure

	// Only call this from the main menu when we need to initialize
	UFUNCTION(BlueprintCallable)
	void HandleAuthentication();

	UFUNCTION(BlueprintCallable)
	void ConnectToDiscordClient();

	UFUNCTION(Exec, BlueprintCallable)
	void DiscordConnect();

	UFUNCTION()
	void OnStatusChanged(EDiscordClientStatus Status, EDiscordClientError Error, int32 ErrorDetail);

	UFUNCTION(BlueprintCallable)
	void InitializeRichPresence();

	UFUNCTION(BlueprintCallable)
	void UpdateRichPresence(FString State, FString Details, FString LargeImage, FString LargeImageText, FString SmallImage, FString SmallImageText);

	UFUNCTION()
	void OnRichPresenceUpdated(UDiscordClientResult* Result);

	UPROPERTY()
	UDiscordAuthorizationCodeVerifier* CodeVerifier;

	UPROPERTY()
	UDiscordLocalPlayerSubsystem* Discord;


protected:
	void BeginPlay() override;
	void OnLogMessage(FString Message, EDiscordLoggingSeverity Severity);
	void OnAuthorizeCompleted(UDiscordClientResult* Result, FString Code, FString RedirectUri);
	void OnTokenExchange(UDiscordClientResult* Result, FString AccessToken, FString RefreshToken, EDiscordAuthorizationTokenType TokenType, int32 ExpiresIn, FString Scope);
	void OnTokenUpdated(UDiscordClientResult* Result);
	void OnTokenRetrievedFromConfig(UDiscordClientResult* Result);
	void OnTokenRefresh();
	void OnTokenRefreshComplete(UDiscordClientResult* Result, FString AccessToken, FString RefreshToken, EDiscordAuthorizationTokenType TokenType, int32 ExpiresIn, FString Scope);
	static void OnTokenExpired();
};
