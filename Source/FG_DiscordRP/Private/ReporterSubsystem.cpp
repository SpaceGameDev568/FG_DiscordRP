// Copyright 2023 - 2025 Jesse Hodgson

#include "ReporterSubsystem.h"
#include "FG_DiscordRP.h"
#include "FGBlueprintFunctionLibrary.h"
#include "FGPlayerController.h"
#include "FGLocalPlayer.h"
#include "FGAdminInterface.h"
#include "GameFramework/GameMode.h"
#include "DRP_ConfigStruct.h"
#include "ModLoading/ModLoadingLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "DiscordLocalPlayerSubsystem.h"

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

	Activity = nullptr;
	Assets = nullptr;
	//Party = nullptr;
	Button = nullptr;
	Timestamps = nullptr;
	Discord = nullptr;

	bAllowDebugLogging = ModConfig.bAllowDebugLogging;
	UpdateInterval = ModConfig.UpdateInterval;

	// Initialize variables from config, unless we are in the editor, as that would crash the engine
	{
	#if WITH_EDITOR
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Shipping env not detected, avoiding crash"));
	#else
		ModConfig = FDRP_ConfigStruct::GetActiveConfig(GetWorld());
	#endif
	}
}

// Initialize Subsystem
void AReporterSubsystem::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Loaded FG_DRP Reporter Subsystem."));

	FModInfo ModInfo;
	UModLoadingLibrary* ModLoadingLibrary = GetGameInstance()->GetSubsystem<UModLoadingLibrary>();
	ModLoadingLibrary->GetLoadedModInfo("FG_DiscordRP", ModInfo);

	// Log the name, version, and build date of the mod
	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("%s"), *ModInfo.FriendlyName.Append(", " + ModInfo.Version.ToString()));
	UE_LOG(LogFG_DISCORDRP, Display, TEXT("Build Date: %s %s"), ANSI_TO_TCHAR(__DATE__), ANSI_TO_TCHAR(__TIME__));

	// Get the language for the interpreter to use later
	GameLanguage = UFGBlueprintFunctionLibrary::GetLanguage();
	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("%s"), *GameLanguage.Append(" is the language being used."));

    // Initialize Discord RPC
	auto PlayerController = Cast<APlayerController>(this->GetWorld()->GetFirstPlayerController());
	auto LocalPlayer = PlayerController->GetLocalPlayer();
	Discord = ULocalPlayer::GetSubsystem<UDiscordLocalPlayerSubsystem>(LocalPlayer);

	auto LogCallback = FDiscordClientLogCallback::CreateUObject(this, &AReporterSubsystem::OnLogMessage);
	FScriptDelegate StatusChanged;
	StatusChanged.BindUFunction(this, "OnStatusChanged");
	Discord->Client->AddLogCallback(LogCallback, EDiscordLoggingSeverity::Info);
	Discord->OnStatusChanged.Add(StatusChanged);

	UE_LOG(LogFG_DISCORDRP, Log, TEXT("Post-Init Status: %hhd"), Discord->Client->GetStatus());

	Discord->Client->SetApplicationId(APPLICATION_ID);

	Activity = NewObject<UDiscordActivity>();
	Assets = NewObject<UDiscordActivityAssets>();
	// Party = NewObject<UDiscordActivityParty>();
	Button = NewObject<UDiscordActivityButton>();
	Timestamps = NewObject<UDiscordActivityTimestamps>();

	Activity->Init();
	Assets->Init();
	// Party->Init();
	Button->Init();
	Timestamps->Init();
//
	// Timestamps->Start();

	// const APlayerState* PlayerState = PlayerController->GetPlayerState<APlayerState>();

	// UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("%s"), *PlayerState->GetPlayerName().Append(" has joined the game."));

	// if (AFGAdminInterface* AdminInterface = PlayerController->GetAdminInterface())
	// {
		//UCLASS(notplaceable)
		//class FACTORYGAME_API AFGAdminInterface : public AInfo
		//{
		//	GENERATED_BODY()
		//
		//	friend class AReporterSubsystem;

		// IF THIS ERRORS IN NEWER VERSIONS, ADD 'friend class AReporterSubsystem;' TO THE AREA ABOVE ON FGAdminInterface.h

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
	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Beginning processing..."));

	// Thanks to SirDigby for helping me with this

	//UCLASS(BlueprintType)
	//class FACTORYGAME_API UFGLocalPlayer : public ULocalPlayer
	//{
	//	GENERATED_BODY()
	//
	//	friend class AReporterSubsystem;

	// IF THIS CREATES ERRORS IN NEWER VERSIONS, ADD 'friend class AReporterSubsystem;' TO THE AREA ABOVE ON FGLocalPlayer.h
	FPlayerPresenceState PlayerPresenceState;
	Cast<UFGLocalPlayer>(this->GetWorld()->GetGameInstance()->GetFirstLocalPlayerController()->GetLocalPlayer())->GetPresenceState(PlayerPresenceState);
	PlayerPresence = PlayerPresenceState.mPresenceString;

	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Current presence string: %s"), *PlayerPresence);

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

	Button->SetLabel("Get Mod");
	Button->SetUrl("https://ficsit.app/mod/FG_DiscordRP");


	// Add a catch for if the player is currently in the tutorial phase
	if (bTutorialException)
	{
		PlayerPresence.Split(TEXT("."), &DiscordDetails, &DiscordState);
	}

		//TArray<AActor*> OutActors;
		//TSubclassOf<ADiscordActions> ActorClass;
		//UGameplayStatics::GetAllActorsOfClass(GetWorld(), ActorClass, OutActors);
//
		//for (auto&  Actor: OutActors)
		//{
		//	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Actor found"));
//
		//	ADiscordActions* DiscordActions = Cast<ADiscordActions>(Actor);
		//	DiscordActions->UpdateRichPresence("InGameState", "InGameDetails");
		//}

	UpdateThumbnails(bTutorialException);
}

void AReporterSubsystem::UpdateThumbnails(bool& bTutorialException)
{

	// Add small image with tier info
	SmallImage = "satisfactory_logo";
	SmallImageText = DiscordTier;

	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Current tier: %s"), *DiscordTier);

	// Parse Biome String

	// Abyss Cliffs
	if (DiscordState.Contains("Abyss Cliffs") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Current biome: Abyss Cliffs"));

		LargeImage = "abyss_cliffs";
		LargeImageText = "Abyss Cliffs";
	} // Blue Crater
	else if (DiscordState.Contains("Blue Crater") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Current biome: Blue Crater"));

		LargeImage = "blue_crater";
		LargeImageText = "Blue Crater";
	} // Crater Lakes
	else if (DiscordState.Contains("Crater Lakes") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Current biome: Crater Lakes"));

		LargeImage = "crater_lakes";
		LargeImageText = "Crater Lakes";
	} // Dune Desert
	else if (DiscordState.Contains("Dune Desert") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Current biome: Dune Desert"));

		LargeImage = "dune_desert";
		LargeImageText = "Dune Desert";
	} // Grass Fields
	else if (DiscordState.Contains("Grass Fields") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Current biome: Grass Fields"));

		LargeImage = "grass_fields";
		LargeImageText = "Grass Fields";
	} // Jungle Spires
	else if (DiscordState.Contains("Jungle Spires") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Current biome: Jungle Spires"));

		LargeImage = "jungle_spires";
		LargeImageText = "Jungle Spires";
	} // Lake Forest
	else if (DiscordState.Contains("Lake Forest") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Current biome: Lake Forest"));

		LargeImage = "lake_forest";
		LargeImageText = "Lake Forest";
	} // Maze Canyon
	else if (DiscordState.Contains("Maze Canyon") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Current biome: Maze Canyon"));

		LargeImage = "maze_canyon";
		LargeImageText = "Maze Canyon";
	} // No Man's Land
	else if (DiscordState.Contains("No Man's Land") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Current biome: No Man's Land"));

		LargeImage = "no_mans_land";
		LargeImageText = "No Man's Land";
	} // Northern Forest
	else if (DiscordState.Contains("Northern Forest") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Current biome: Northern Forest"));

		LargeImage = "northern_forest";
		LargeImageText = "Northern Forest";
	} // Red Bamboo Fields
	else if (DiscordState.Contains("Red Bamboo Fields") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Current biome: Red Bamboo Fields"));

		LargeImage = "red_bamboo_fields";
		LargeImageText = "Red Bamboo Fields";
	} // Red Jungle
	else if (DiscordState.Contains("Red Jungle") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Current biome: Red Jungle"));

		LargeImage = "red_jungle";
		LargeImageText = "Red Jungle";
	} // Rocky Desert
	else if (DiscordState.Contains("Rocky Desert") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Current biome: Rocky Desert"));

		LargeImage = "rocky_desert";
		LargeImageText = "Rocky Desert";
	} // Southern Forest
	else if (DiscordState.Contains("Southern Forest") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Current biome: Southern Forest"));

		LargeImage = "southern_forest";
		LargeImageText = "Southern Forest";
	} // Spire Coast
	else if (DiscordState.Contains("Spire Coast") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Current biome: Spire Coast"));

		LargeImage = "spire_coast";
		LargeImageText = "Spire Coast";
	} // Swamp
	else if (DiscordState.Contains("Swamp") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Current biome: Swamp"));

		LargeImage = "swamp";
		LargeImageText = "Swamp";
	} // Titan Forest
	else if (DiscordState.Contains("Titan Forest") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Current biome: Titan Forest"));

		LargeImage = "titan_forest";
		LargeImageText = "Titan Forest";
	} // Western Dune Forest
	else if (DiscordState.Contains("Western Dune Forest") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Current biome: Western Dune Forest"));

		LargeImage = "western_dune_forest";
		LargeImageText = "Western Dune Forest";
	} // Desert Canyon
	else if (DiscordState.Contains("Desert Canyon") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Current biome: Desert Canyon"));

		LargeImage = "desert_canyon";
		LargeImageText = "Desert Canyon";
	} // somewhere
	else if (DiscordState.Contains("somewhere") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Current biome: somewhere. This means that the game is loading or something went terribly wrong."));

		LargeImage = "ssd_logo";
		LargeImageText = "Error Processing Biome String";
	} // Did we find a biome or do we need to put in the fallback text?
	else if (PlayerPresence.Contains(TEXT("Just landed on the alien planet.")))
	{
		bTutorialException = true;
	}
	else
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Biome String not valid. Showing fallback image..."));

		LargeImage = "satisfactory_logo";
		LargeImageText = "Satisfactory";
	}

	UpdateRichPresence();
}

void AReporterSubsystem::UpdateRichPresence()
{
	// Set Activity info
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

	// Commit Timestamps to presence
	Activity->SetTimestamps(Timestamps);

	//Activity->SetParty(Party);

	// Add custom buttons
	Activity->AddButton(Button);

	// Commit Presence to the client
	Discord->Client->UpdateRichPresence(Activity, FDiscordClientUpdateRichPresenceCallback::CreateUObject(this, &AReporterSubsystem::OnRichPresenceUpdated));
}

void AReporterSubsystem::OnRichPresenceUpdated(UDiscordClientResult* Result)
{
	if (Result->Successful()) {
		UE_LOG(LogFG_DISCORDRP, Log, TEXT("Rich Presence updated successfully!"));
	} else {
		UE_LOG(LogFG_DISCORDRP, Error, TEXT("Rich Presence update failed"));
	}
}

void AReporterSubsystem::OnLogMessage(FString Message, EDiscordLoggingSeverity Severity) {
	UE_LOG(LogFG_DISCORDRP, Log, TEXT("[%s] %s"), *UEnum::GetValueAsString(Severity), *Message);
}