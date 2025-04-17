// Copyright 2023 - 2025 Jesse Hodgson

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DiscordPartnerSDK/Public/DiscordLocalPlayerSubsystem.h"
#include "DiscordAuthorization.generated.h"

/**
 * 
 */
UCLASS()
class FG_DISCORDRP_API UDiscordAuthorization : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	EDiscordClientStatus DiscordClientStatus;

	UFUNCTION()
	void DiscordConnect();

	UFUNCTION()
	void OnStatusChanged(EDiscordClientStatus Status, EDiscordClientError Error, int32 ErrorDetail);

	UPROPERTY()
	UDiscordAuthorizationCodeVerifier* CodeVerifier;

	UPROPERTY()
	UDiscordLocalPlayerSubsystem* Discord;

	UFUNCTION(BlueprintCallable)
	void Init(AActor* Actor);

protected:

	void OnLogMessage(FString Message, EDiscordLoggingSeverity Severity);
	void OnAuthorizeCompleted(UDiscordClientResult* Result, FString Code, FString RedirectUri);
	void OnTokenExchange(UDiscordClientResult* Result, FString AccessToken, FString RefreshToken, EDiscordAuthorizationTokenType TokenType, int32 ExpiresIn, FString Scope);
	void OnTokenUpdated(UDiscordClientResult* Result);
	
};
