// Copyright 2023 - 2025 Jesse Hodgson

#include "ReporterSubsystem.h"

#include "FG_DiscordRP.h"
#include "FGBlueprintFunctionLibrary.h"
#include "FGPlayerController.h"
#include "FGLocalPlayer.h"
#include "GameFramework/GameMode.h"
#include "DRP_ConfigStruct.h"
#include "ModLoading/ModLoadingLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "DiscordLocalPlayerSubsystem.h"
#include "StructuredLog.h"

#define APPLICATION_ID 1082738646173614143 // This is public

AReporterSubsystem::AReporterSubsystem()
{
	UpdateInterval = 5.0f;
	NumPlayersInSession = 1;
	MaxPlayers = 4;
	PlayerPresence = "Session Loading...";
	DiscordTier = "Session Loading...";
	DiscordDetails = "Session Loading...";
	DiscordState = "Session Loading...";
	GameLanguage = "Session Loading...";

	// Get the current UTC time when we load a save, this will be reset if another save is loaded, or the player goes back to the main menu
	GameStartTime = FDateTime::UtcNow().ToUnixTimestamp();

	Activity = nullptr;
	Assets = nullptr;
	//Party = nullptr;
	//Button = nullptr;
	Timestamps = nullptr;
	Discord = nullptr;

	bAllowDebugLogging = ModConfig.bAllowDebugLogging;
	UpdateInterval = ModConfig.UpdateInterval;

	// Initialize variables from config, unless we are in the editor, as that would crash the engine
	{
	#if WITH_EDITOR
		UE_LOGFMT(LogFG_DISCORDRP, Verbose, "Shipping env not detected, avoiding crash");
	#else
		ModConfig = FDRP_ConfigStruct::GetActiveConfig(GetWorld());
	#endif
	}
}

// Initialize Subsystem
void AReporterSubsystem::BeginPlay()
{
	Super::BeginPlay();

	UE_LOGFMT(LogFG_DISCORDRP, Verbose, "Loaded Discord Rich Presence Reporter Subsystem");

	FModInfo ModInfo;
	UModLoadingLibrary* ModLoadingLibrary = GetGameInstance()->GetSubsystem<UModLoadingLibrary>();
	ModLoadingLibrary->GetLoadedModInfo("FG_DiscordRP", ModInfo);

	// Log the name, version, and build date of the mod
	UE_LOGFMT(LogFG_DISCORDRP, Verbose, "{ModNameAndVersion}", ("ModNameAndVersion", ModInfo.FriendlyName.Append(", " + ModInfo.Version.ToString())));
	UE_LOGFMT(LogFG_DISCORDRP, Verbose, "Build Date & Time: {BuildDate} {BuildTime}", ("BuildDate", ANSI_TO_TCHAR(__DATE__)), ("BuildTime", ANSI_TO_TCHAR(__TIME__)));

	// Get the language for the interpreter to use later
	GameLanguage = UFGBlueprintFunctionLibrary::GetLanguage();
	UE_LOGFMT(LogFG_DISCORDRP, Verbose, "Language: {GameLanguage}", ("GameLanguage", GameLanguage));

    // Initialize Discord RPC
	auto PlayerController = Cast<APlayerController>(this->GetWorld()->GetFirstPlayerController());
	auto LocalPlayer = PlayerController->GetLocalPlayer();
	Discord = ULocalPlayer::GetSubsystem<UDiscordLocalPlayerSubsystem>(LocalPlayer);

	auto LogCallback = FDiscordClientLogCallback::CreateUObject(this, &AReporterSubsystem::OnLogMessage);
	FScriptDelegate StatusChanged;
	StatusChanged.BindUFunction(this, "OnStatusChanged");
	Discord->Client->AddLogCallback(LogCallback, EDiscordLoggingSeverity::Info);
	Discord->OnStatusChanged.Add(StatusChanged);

	Discord->Client->SetApplicationId(APPLICATION_ID);

	Activity = NewObject<UDiscordActivity>();
	Assets = NewObject<UDiscordActivityAssets>();
	// Party = NewObject<UDiscordActivityParty>();
	//Button = NewObject<UDiscordActivityButton>();
	Timestamps = NewObject<UDiscordActivityTimestamps>();

	Activity->Init();
	Assets->Init();
	// Party->Init();
	//Button->Init();

	//Button->SetLabel("Get Mod");
	//Button->SetUrl("https://ficsit.app/mod/FG_DiscordRP");

	Timestamps->Init();
	Timestamps->SetStart(GameStartTime);

	// const APlayerState* PlayerState = PlayerController->GetPlayerState<APlayerState>();

	// UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("%s"), *PlayerState->GetPlayerName().Append(" has joined the game."));

	// if (AFGAdminInterface* AdminInterface = PlayerController->GetAdminInterface())
	// {
		// Get the amount of players allowed in the game session
		//MaxPlayers = AdminInterface->GetGameSession()->MaxPlayers;

		// Set our session visibility which affects whether we can retrieve the data we want
		// AdminInterface->SetSessionVisibility(ESessionVisibility::SV_FriendsOnly);
	// }

	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AReporterSubsystem::ProcessPresenceString, 5.0f,true, 5.0f);
}

// End the subsystem when leaving the world to prevent crashing
void AReporterSubsystem::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EEndPlayReason::LevelTransition);

	GetWorldTimerManager().ClearTimer(MemberTimerHandle);
}

// Get and process the local player presence string
void AReporterSubsystem::ProcessPresenceString()
{
	// Thanks to SirDigby for helping me with this

	FPlayerPresenceState PlayerPresenceState;
	Cast<UFGLocalPlayer>(this->GetWorld()->GetGameInstance()->GetFirstLocalPlayerController()->GetLocalPlayer())->GetPresenceState(PlayerPresenceState);
	PlayerPresence = PlayerPresenceState.mPresenceString;

	if (bAllowDebugLogging)
	{
		UE_LOGFMT(LogFG_DISCORDRP, Verbose, "Player Presence String: {PlayerPresence}", ("PlayerPresence", PlayerPresence));
	}

	FString OutTier;
	FString OutDetails;
	FString OutState;
	bool bTutorialException = false;

	PlayerPresence.Split(TEXT(":"), &DiscordTier, &OutTier);
	OutTier.Split(TEXT("in"), &DiscordDetails, &OutDetails, ESearchCase::IgnoreCase, ESearchDir::FromEnd);
	OutDetails.Split(TEXT("."), &DiscordState, &OutState, ESearchCase::IgnoreCase, ESearchDir::FromEnd);

	//If we are a client, skip this step
	if (this->GetWorld()->GetNetMode() != NM_Client)
	{
		// Get Player Count
		NumPlayersInSession = UGameplayStatics::GetGameMode(GetWorld())->GetNumPlayers();
	}


	// This crashes the game
	// MaxPlayers = 4;

	// Party->SetCurrentSize(NumPlayersInSession);
	// Party->SetMaxSize(MaxPlayers);
	// Activity->SetParty(Party);


	// Add a catch for if the player is currently in the tutorial phase
	if (bTutorialException)
	{
		PlayerPresence.Split(TEXT("."), &DiscordDetails, &DiscordState);
	}

	UpdateThumbnails(bTutorialException);
}

void AReporterSubsystem::UpdateThumbnails(bool& bTutorialException)
{

	// Add small image with tier info
	SmallImage = "satisfactory_logo";
	SmallImageText = DiscordTier;

	// Parse Biome String

	// Abyss Cliffs
	if (DiscordState.Contains("Abyss Cliffs") == 1)
	{
		LargeImage = "abyss_cliffs";
		LargeImageText = "Abyss Cliffs";
	} // Blue Crater
	else if (DiscordState.Contains("Blue Crater") == 1)
	{
		LargeImage = "blue_crater";
		LargeImageText = "Blue Crater";
	} // Crater Lakes
	else if (DiscordState.Contains("Crater Lakes") == 1)
	{
		LargeImage = "crater_lakes";
		LargeImageText = "Crater Lakes";
	} // Dune Desert
	else if (DiscordState.Contains("Dune Desert") == 1)
	{
		LargeImage = "dune_desert";
		LargeImageText = "Dune Desert";
	} // Grass Fields
	else if (DiscordState.Contains("Grass Fields") == 1)
	{
		LargeImage = "grass_fields";
		LargeImageText = "Grass Fields";
	} // Jungle Spires
	else if (DiscordState.Contains("Jungle Spires") == 1)
	{
		LargeImage = "jungle_spires";
		LargeImageText = "Jungle Spires";
	} // Lake Forest
	else if (DiscordState.Contains("Lake Forest") == 1)
	{
		LargeImage = "lake_forest";
		LargeImageText = "Lake Forest";
	} // Maze Canyon
	else if (DiscordState.Contains("Maze Canyon") == 1)
	{
		LargeImage = "maze_canyon";
		LargeImageText = "Maze Canyon";
	} // No Man's Land
	else if (DiscordState.Contains("No Man's Land") == 1)
	{
		LargeImage = "no_mans_land";
		LargeImageText = "No Man's Land";
	} // Northern Forest
	else if (DiscordState.Contains("Northern Forest") == 1)
	{
		LargeImage = "northern_forest";
		LargeImageText = "Northern Forest";
	} // Red Bamboo Fields
	else if (DiscordState.Contains("Red Bamboo Fields") == 1)
	{
		LargeImage = "red_bamboo_fields";
		LargeImageText = "Red Bamboo Fields";
	} // Red Jungle
	else if (DiscordState.Contains("Red Jungle") == 1)
	{
		LargeImage = "red_jungle";
		LargeImageText = "Red Jungle";
	} // Rocky Desert
	else if (DiscordState.Contains("Rocky Desert") == 1)
	{
		LargeImage = "rocky_desert";
		LargeImageText = "Rocky Desert";
	} // Southern Forest
	else if (DiscordState.Contains("Southern Forest") == 1)
	{
		LargeImage = "southern_forest";
		LargeImageText = "Southern Forest";
	} // Spire Coast
	else if (DiscordState.Contains("Spire Coast") == 1)
	{
		LargeImage = "spire_coast";
		LargeImageText = "Spire Coast";
	} // Swamp
	else if (DiscordState.Contains("Swamp") == 1)
	{
		LargeImage = "swamp";
		LargeImageText = "Swamp";
	} // Titan Forest
	else if (DiscordState.Contains("Titan Forest") == 1)
	{
		LargeImage = "titan_forest";
		LargeImageText = "Titan Forest";
	} // Western Dune Forest
	else if (DiscordState.Contains("Western Dune Forest") == 1)
	{
		LargeImage = "western_dune_forest";
		LargeImageText = "Western Dune Forest";
	} // Desert Canyon
	else if (DiscordState.Contains("Desert Canyon") == 1)
	{
		LargeImage = "desert_canyon";
		LargeImageText = "Desert Canyon";
	} // somewhere
	else if (DiscordState.Contains("somewhere") == 1)
	{
		if (bAllowDebugLogging)
		{
			UE_LOGFMT(LogFG_DISCORDRP, Verbose, "Current biome listed as \"somewhere\". This means that the game is loading or something went terribly wrong");
		}

		LargeImage = "ssd_logo";
		LargeImageText = "Error Processing Biome String";
	} // Did we find a biome or do we need to put in the fallback text?
	else if (PlayerPresence.Contains(TEXT("Just landed on the alien planet.")))
	{
		bTutorialException = true;
	}
	else
	{
		UE_LOGFMT(LogFG_DISCORDRP, Verbose, "Biome string not valid. Showing fallback image");

		LargeImage = "satisfactory_logo";
		LargeImageText = "Satisfactory";
	}

	UpdateRichPresence();
}

void AReporterSubsystem::UpdateRichPresence()
{
	// Set Activity info
	Activity->SetName("Satisfactory");
	Activity->SetType(EDiscordActivityTypes::Playing);
	Activity->SetState(DiscordState);
	Activity->SetDetails(DiscordDetails);

	// Set Assets
	Assets->SetLargeImage(LargeImage);
	Assets->SetLargeText(LargeImageText);

	Assets->SetSmallImage(SmallImage);
	Assets->SetSmallText(SmallImageText);

	// Commit Assets to presence
	Activity->SetAssets(Assets);

	// Add custom buttons
	//Activity->AddButton(Button);

	// Commit Timestamps to presence
	Activity->SetTimestamps(Timestamps);

	//Activity->SetParty(Party);

	// Commit Presence to the client
	Discord->Client->UpdateRichPresence(Activity, FDiscordClientUpdateRichPresenceCallback::CreateUObject(this, &AReporterSubsystem::OnRichPresenceUpdated));
}

void AReporterSubsystem::OnRichPresenceUpdated(UDiscordClientResult* Result)
{
	if (bAllowDebugLogging)
	{
		if (Result->Successful()) {
			UE_LOGFMT(LogFG_DISCORDRP, Verbose, "Rich Presence updated successfully!");
		} else {
			UE_LOGFMT(LogFG_DISCORDRP, Verbose, "Rich Presence update failed!");
		}
	}
}

void AReporterSubsystem::OnLogMessage(FString Message, EDiscordLoggingSeverity Severity) {
	UE_LOGFMT(LogFG_DISCORDRP, Verbose, "Message from DiscordSocialSDK: {Severity} {DiscordSocialSDKMessage}", ("Severity", UEnum::GetValueAsString(Severity)), ("DiscordSocialSDKMessage", *Message));
}