// Copyright 2023 - 2025 Jesse Hodgson

#include "DiscordActions.h"

#include "FG_DiscordRP.h"
#include "DiscordPartnerSDK/Public/DiscordUnreal.h"
#include "Engine/GameInstance.h"
#include "Runtime/Engine/Classes/Engine/LocalPlayer.h"
#include "GameFramework/Actor.h"

#define APPLICATION_ID 1082738646173614143

void ADiscordActions::BeginPlay() {
  auto PlayerController = Cast<APlayerController>(this->GetWorld()->GetFirstPlayerController());
  auto LocalPlayer = PlayerController->GetLocalPlayer();
  Discord = ULocalPlayer::GetSubsystem<UDiscordLocalPlayerSubsystem>(LocalPlayer);

  auto LogCallback = FDiscordClientLogCallback::CreateUObject(this, &ADiscordActions::OnLogMessage);
  FScriptDelegate StatusChanged;
  StatusChanged.BindUFunction(this, "OnStatusChanged");
  Discord->Client->AddLogCallback(LogCallback, EDiscordLoggingSeverity::Info);
  Discord->OnStatusChanged.Add(StatusChanged);

  UE_LOG(LogFG_DISCORDRP, Log, TEXT("Post-Init Status: %hhd"), Discord->Client->GetStatus());

  auto TokenExpiryCallback = FDiscordClientTokenExpirationCallback::CreateUObject(this, &ADiscordActions::OnTokenRefresh);
  Discord->Client->SetTokenExpirationCallback(TokenExpiryCallback);

  {
    #if WITH_EDITOR
        UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Can't load config in editor!"));
    #else
        ModConfig = FDRP_ConfigStruct::GetActiveConfig(GetWorld());
    #endif
  }

  DiscordAccessToken = ModConfig.DiscordAccessToken;
  DiscordRefreshToken = ModConfig.DiscordRefreshToken;
  //DiscordRefreshTokenType = ModConfig.DiscordRefreshTokenType;
}

void ADiscordActions::HandleAuthentication()
{
  if (DiscordAccessToken == "")
  {
    DiscordConnect();
  }
  else
  {
    Discord->Client->UpdateToken(EDiscordAuthorizationTokenType::Bearer, DiscordAccessToken, FDiscordClientUpdateTokenCallback::CreateUObject(this, &ADiscordActions::OnTokenRetrievedFromConfig));
  }
}

void ADiscordActions::ConnectToDiscordClient()
{
  Discord->Client->Connect();
}

void ADiscordActions::DiscordConnect() {
  CodeVerifier = Discord->Client->CreateAuthorizationCodeVerifier();
  auto AuthArgs = NewObject<UDiscordAuthorizationArgs>();
  AuthArgs->Init();
  AuthArgs->SetClientId(APPLICATION_ID);
  AuthArgs->SetScopes(UDiscordClient::GetDefaultPresenceScopes());
  AuthArgs->SetCodeChallenge(CodeVerifier->Challenge());
  Discord->Client->Authorize(AuthArgs, FDiscordClientAuthorizationCallback::CreateUObject(this, &ADiscordActions::OnAuthorizeCompleted));
}

void ADiscordActions::OnLogMessage(FString Message, EDiscordLoggingSeverity Severity) {
  UE_LOG(LogFG_DISCORDRP, Log, TEXT("[%s] %s"), *UEnum::GetValueAsString(Severity), *Message);
}

void ADiscordActions::OnStatusChanged(EDiscordClientStatus Status, EDiscordClientError Error, int32 ErrorDetail) {
  UE_LOG(LogFG_DISCORDRP, Log, TEXT("Connection status: %s"), *UEnum::GetValueAsString(Status));
  if (Status == EDiscordClientStatus::Ready) {
    UE_LOG(LogFG_DISCORDRP, Log, TEXT("Connected to Discord! Ready to go! You can now start using Discord features."));
    UE_LOG(LogFG_DISCORDRP, Log, TEXT("👥 Friends Count: %d"), Discord->Client->GetRelationships().Num());

    InitializeRichPresence();
  }
  else if (Error != EDiscordClientError::None) {
    UE_LOG(LogFG_DISCORDRP, Log, TEXT("Connection error: %s (Detail: %d)"), *UEnum::GetValueAsString(Error), ErrorDetail);
  }
}

void ADiscordActions::OnAuthorizeCompleted(UDiscordClientResult* Result, FString Code, FString RedirectUri) {
  if (!Result->Successful()) {
    UE_LOG( LogFG_DISCORDRP, Error, TEXT("Discord authorization failed: %s"), *Result->Error());
    return;
  }

  UE_LOG(LogFG_DISCORDRP, Log, TEXT("Authorization successful! Getting access token..."));
  Discord->Client->GetToken(APPLICATION_ID, Code, CodeVerifier->Verifier(), RedirectUri, FDiscordClientTokenExchangeCallback::CreateUObject(this, &ADiscordActions::OnTokenExchange));
}

void ADiscordActions::OnTokenExchange(UDiscordClientResult* Result, FString AccessToken, FString RefreshToken, EDiscordAuthorizationTokenType TokenType, int32 ExpiresIn, FString Scope) {
  if (!Result->Successful()) {
    UE_LOG(LogFG_DISCORDRP, Error, TEXT("Discord token exchange failed: %s"), *Result->Error());
  }

  // Set Variables in memory, then set config variables to be flushed to disk
  DiscordAccessToken = AccessToken;
  DiscordRefreshToken = RefreshToken;

  ModConfig.DiscordAccessToken = AccessToken;
  ModConfig.DiscordRefreshToken = RefreshToken;

  FConfigId ConfigId = {
    "FG_DiscordRP"
  };
  UConfigManager* ConfigManager = GetWorld()->GetGameInstance()->GetSubsystem<UConfigManager>();
  ConfigManager->MarkConfigurationDirty(ConfigId);
  ConfigManager->FlushPendingSaves();

  Discord->Client->UpdateToken(TokenType, AccessToken, FDiscordClientUpdateTokenCallback::CreateUObject(this, &ADiscordActions::OnTokenUpdated));
}

void ADiscordActions::OnTokenUpdated(UDiscordClientResult* Result) {
  UE_LOG(LogFG_DISCORDRP, Log, TEXT("Token Updated, connecting..."));

  Discord->Client->Connect();
}

void ADiscordActions::OnTokenRefresh()
{
  auto TokenRefreshCallback = FDiscordClientTokenExchangeCallback::CreateUObject(this, &ADiscordActions::OnTokenRefreshComplete);
  Discord->Client->RefreshToken(APPLICATION_ID, DiscordRefreshToken, TokenRefreshCallback);
}

void ADiscordActions::OnTokenRefreshComplete(UDiscordClientResult* Result, FString AccessToken, FString RefreshToken, EDiscordAuthorizationTokenType TokenType, int32 ExpiresIn, FString Scope)
{
  if (!Result->Successful()) {
    UE_LOG(LogFG_DISCORDRP, Error, TEXT("Discord token exchange failed: %s"), *Result->Error());
  }

  Discord->Client->UpdateToken(TokenType, AccessToken, FDiscordClientUpdateTokenCallback::CreateUObject(this, &ADiscordActions::OnTokenUpdated));
}

void ADiscordActions::InitializeRichPresence()
{
  //if (Discord->Client->GetStatus() == EDiscordClientStatus::Ready)
  //{
    Activity = NewObject<UDiscordActivity>();
    Assets = NewObject<UDiscordActivityAssets>();

    Activity->Init();
    Assets->Init();
  //}
  //else
  //{
  //  UE_LOG(LogFG_DISCORDRP, Log, TEXT("Discord Client Status Not Ready!"));
  //}

}

void ADiscordActions::UpdateRichPresence(FString State, FString Details, FString LargeImage, FString LargeImageText, FString SmallImage, FString SmallImageText)
{
  // Set Activity info
  Activity->SetType(EDiscordActivityTypes::Playing);
  Activity->SetState(State);
  Activity->SetDetails(Details);

  // Set Assets
  Assets->SetLargeImage(LargeImage);
  Assets->SetLargeText(LargeImageText);

  Assets->SetSmallImage(SmallImage);
  Assets->SetSmallText(SmallImageText);

  // Commit Assets to presence
  Activity->SetAssets(Assets);

  // Commit Presence to client
  Discord->Client->UpdateRichPresence(Activity, FDiscordClientUpdateRichPresenceCallback::CreateUObject(this, &ADiscordActions::OnRichPresenceUpdated));
}

void ADiscordActions::OnRichPresenceUpdated(UDiscordClientResult* Result)
{
  if (Result->Successful()) {
    UE_LOG(LogFG_DISCORDRP, Log, TEXT("Rich Presence updated successfully!"));
  } else {
    UE_LOG(LogFG_DISCORDRP, Error, TEXT("Rich Presence update failed"));
  }
}

void ADiscordActions::OnTokenRetrievedFromConfig(UDiscordClientResult* Result)
{
  UE_LOG(LogFG_DISCORDRP, Log, TEXT("Token Updated from config, connecting..."));

  if (Discord->Client->IsAuthenticated())
  {
    UE_LOG(LogFG_DISCORDRP, Log, TEXT("Authenticated, connecting..."));

    Discord->Client->Connect();
  }
  else
  {
    UE_LOG(LogFG_DISCORDRP, Log, TEXT("Not authenticated, prompting user..."));

    DiscordConnect();
  }
}
