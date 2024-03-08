// Copyright 2023 - 2024 Jesse Hodgson. All Rights Reserved.

#include "LangEnglish.h"
#include "FG_DiscordRP.h"
#include "DiscordObject.h"

void ULangEnglish::InterpretEnglish(FString InStateString, FString InTierString, FString InPresenceString, UDiscordObject* DiscordObject, bool EnableDebugLogging, bool &TutorialException)
{
	// Add small image with tier info
	DiscordObject->SetSmallImage("satisfactory_logo");
	DiscordObject->SetSmallImageText(InTierString);
	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("%s"),*InTierString);

	// Parse Biome String

	// Abyss Cliffs
	if(InStateString.Contains("Abyss Cliffs") == 1)
	{
			UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Abyss Cliffs"));

	DiscordObject->SetLargeImage("abyss_cliffs");
	DiscordObject->SetLargeImageText("Abyss Cliffs");
	} // Blue Crater
	else if(InStateString.Contains("Blue Crater") == 1)
	{
			UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Blue Crater"));

		DiscordObject->SetLargeImage("blue_crater");
		DiscordObject->SetLargeImageText("Blue Crater");
	} // Crater Lakes
	else if(InStateString.Contains("Crater Lakes") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Crater Lakes"));

		DiscordObject->SetLargeImage("crater_lakes");
		DiscordObject->SetLargeImageText("Crater Lakes");
	} // Dune Desert
	else if(InStateString.Contains("Dune Desert") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Dune Desert"));

		DiscordObject->SetLargeImage("dune_desert");
		DiscordObject->SetLargeImageText("Dune Desert");
	} // Grass Fields
	else if(InStateString.Contains("Grass Fields") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Grass Fields"));

		DiscordObject->SetLargeImage("grass_fields");
		DiscordObject->SetLargeImageText("Grass Fields");
	} // Jungle Spires
	else if(InStateString.Contains("Jungle Spires") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Jungle Spires"));

		DiscordObject->SetLargeImage("jungle_spires");
		DiscordObject->SetLargeImageText("Jungle Spires");
	} // Lake Forest
	else if(InStateString.Contains("Lake Forest") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Lake Forest"));

		DiscordObject->SetLargeImage("lake_forest");
		DiscordObject->SetLargeImageText("Lake Forest");
	} // Maze Canyon
	else if(InStateString.Contains("Maze Canyon") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Maze Canyon"));

		DiscordObject->SetLargeImage("maze_canyon");
		DiscordObject->SetLargeImageText("Maze Canyon");
	} // No Man's Land
	else if(InStateString.Contains("No Man's Land") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: No Man's Land"));

		DiscordObject->SetLargeImage("no_mans_land");
		DiscordObject->SetLargeImageText("No Man's Land");
	} // Northern Forest
	else if(InStateString.Contains("Northern Forest") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Northern Forest"));

		DiscordObject->SetLargeImage("northern_forest");
		DiscordObject->SetLargeImageText("Northern Forest");
	} // Red Bamboo Fields
	else if(InStateString.Contains("Red Bamboo Fields") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Red Bamboo Fields"));

		DiscordObject->SetLargeImage("red_bamboo_fields");
		DiscordObject->SetLargeImageText("Red Bamboo Fields");
	} // Red Jungle
	else if(InStateString.Contains("Red Jungle") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Red Jungle"));

		DiscordObject->SetLargeImage("red_jungle");
		DiscordObject->SetLargeImageText("Red Jungle");
	} // Rocky Desert
	else if(InStateString.Contains("Rocky Desert") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Rocky Desert"));

		DiscordObject->SetLargeImage("rocky_desert");
		DiscordObject->SetLargeImageText("Rocky Desert");
	} // Southern Forest
	else if(InStateString.Contains("Southern Forest") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Southern Forest"));

		DiscordObject->SetLargeImage("southern_forest");
		DiscordObject->SetLargeImageText("Southern Forest");
	} // Spire Coast
	else if(InStateString.Contains("Spire Coast") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Spire Coast"));

		DiscordObject->SetLargeImage("spire_coast");
		DiscordObject->SetLargeImageText("Spire Coast");
	} // Swamp
	else if(InStateString.Contains("Swamp") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Swamp"));

		DiscordObject->SetLargeImage("swamp");
		DiscordObject->SetLargeImageText("Swamp");
	} // Titan Forest
	else if(InStateString.Contains("Titan Forest") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Titan Forest"));

		DiscordObject->SetLargeImage("titan_forest");
		DiscordObject->SetLargeImageText("Titan Forest");
	} // Western Dune Forest
	else if(InStateString.Contains("Western Dune Forest") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Western Dune Forest"));

		DiscordObject->SetLargeImage("western_dune_forest");
		DiscordObject->SetLargeImageText("Western Dune Forest");
	} // Desert Canyon
	else if(InStateString.Contains("Desert Canyon") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Desert Canyon"));

		DiscordObject->SetLargeImage("desert_canyon");
		DiscordObject->SetLargeImageText("Desert Canyon");
	} // somewhere
	else if(InStateString.Contains("somewhere") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: somewhere. This means that the game is loading OR something went terribly wrong."));

		DiscordObject->SetLargeImage("ssd_logo");
		DiscordObject->SetLargeImageText("Error Processing Biome String");
	} // Did we find a biome or do we need to put in the fallback text?
	else if(InPresenceString.Contains(TEXT("Just landed on the alien planet.")))
	{
		TutorialException = true;
	}
	else
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Biome String not valid. Showing fallback image..."));

		DiscordObject->SetLargeImage("satisfactory_logo");
		DiscordObject->SetLargeImageText("Satisfactory");
	}
}

