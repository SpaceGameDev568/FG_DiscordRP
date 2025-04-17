// Copyright 2023 - 2025 Jesse Hodgson

#include "DiscordAuthorization.h"
#include "FG_DiscordRP.h"
#include "DiscordPartnerSDK/Public/DiscordUnreal.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/Actor.h"

#define APPLICATION_ID 1082738646173614143

void UDiscordAuthorization::Init(AActor* Actor) {

  auto PlayerController = Cast<APlayerController>(Actor->GetWorld()->GetGameInstance()->GetFirstLocalPlayerController());
  auto LocalPlayer = PlayerController->GetLocalPlayer();
  Discord = ULocalPlayer::GetSubsystem<UDiscordLocalPlayerSubsystem>(LocalPlayer);
  auto LogCallback = FDiscordClientLogCallback::CreateUObject(this, &UDiscordAuthorization::OnLogMessage);

  FScriptDelegate StatusChanged;
  StatusChanged.BindUFunction(this, "OnStatusChanged");
  Discord->Client->AddLogCallback(LogCallback, EDiscordLoggingSeverity::Info);
  Discord->OnStatusChanged.Add(StatusChanged);
}

void UDiscordAuthorization::DiscordConnect() {

  CodeVerifier = Discord->Client->CreateAuthorizationCodeVerifier();
  auto AuthArgs = NewObject<UDiscordAuthorizationArgs>();

  AuthArgs->Init();
  AuthArgs->SetClientId(APPLICATION_ID);
  AuthArgs->SetScopes(UDiscordClient::GetDefaultPresenceScopes());
  AuthArgs->SetCodeChallenge(CodeVerifier->Challenge());

  Discord->Client->Authorize(AuthArgs, FDiscordClientAuthorizationCallback::CreateUObject(this, &UDiscordAuthorization::OnAuthorizeCompleted));

}

void UDiscordAuthorization::OnLogMessage(FString Message, EDiscordLoggingSeverity Severity) {

  UE_LOG(LogFG_DISCORDRP, Log, TEXT("[%s] %s"), *UEnum::GetValueAsString(Severity), *Message);

}

void UDiscordAuthorization::OnStatusChanged(EDiscordClientStatus Status, EDiscordClientError Error, int32 ErrorDetail) {

  UE_LOG(LogFG_DISCORDRP, Log, TEXT("Connection status: %s"), *UEnum::GetValueAsString(Status));

  if (Status == EDiscordClientStatus::Ready) {

    UE_LOG(LogFG_DISCORDRP, Log, TEXT("Connected to Discord! Ready to go! You can now start using Discord features."));
    UE_LOG(LogFG_DISCORDRP, Log, TEXT("👥 Friends Count: %d"), Discord->Client->GetRelationships().Num());

  }
  else if (Error != EDiscordClientError::None) {

    UE_LOG(LogFG_DISCORDRP, Log, TEXT("Connection error: %s (Detail: %d)"), *UEnum::GetValueAsString(Error), ErrorDetail);

  }
}

void UDiscordAuthorization::OnAuthorizeCompleted(UDiscordClientResult* Result, FString Code, FString RedirectUri) {

  if (!Result->Successful()) {

    UE_LOG( LogFG_DISCORDRP, Error, TEXT("Discord authorization failed: %s"), *Result->Error());
    return;
  }

  UE_LOG(LogFG_DISCORDRP, Log, TEXT("Authorization successful! Getting access token..."));
  Discord->Client->GetToken(APPLICATION_ID, Code, CodeVerifier->Verifier(), RedirectUri, FDiscordClientTokenExchangeCallback::CreateUObject(this, &UDiscordAuthorization::OnTokenExchange));
}

void UDiscordAuthorization::OnTokenExchange(UDiscordClientResult* Result, FString AccessToken, FString RefreshToken, EDiscordAuthorizationTokenType TokenType, int32 ExpiresIn, FString Scope) {

  if (!Result->Successful()) {
    UE_LOG(LogFG_DISCORDRP, Error, TEXT("Discord token exchange failed: %s"), *Result->Error());
  }

  Discord->Client->UpdateToken(TokenType, AccessToken, FDiscordClientUpdateTokenCallback::CreateUObject(this, &UDiscordAuthorization::OnTokenUpdated));
}

void UDiscordAuthorization::OnTokenUpdated(UDiscordClientResult* Result) {
  Discord->Client->Connect();
}