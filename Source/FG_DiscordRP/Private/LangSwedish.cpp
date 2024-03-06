// Copyright 2023 - 2024 Jesse Hodgson. All Rights Reserved.

#include "LangSwedish.h"
#include "FG_DiscordRP.h"
#include "DiscordObject.h"

void ULangSwedish::InterpretSwedish(FString InStateString, FString InTierString, FString InPresenceString, UDiscordObject* DiscordObject, bool EnableDebugLogging, bool &TutorialException)
{
	// Add small image with tier info
	DiscordObject->SetSmallImage("satisfactory_logo");
	DiscordObject->SetSmallImageText(InTierString);
	UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("%s"),*InTierString);

	// Parse Biome String

	// Abyss Cliffs
	if(InStateString.Contains("Abyssklipporna") == 1)
	{
			UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Abyss Cliffs/Abyssklipporna"));

	DiscordObject->SetLargeImage("abyss_cliffs");
	DiscordObject->SetLargeImageText("Abyssklipporna");
	} // Blue Crater
	else if(InStateString.Contains("Blå Kratern") == 1)
	{
			UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Blue Crater/Blå Kratern"));

		DiscordObject->SetLargeImage("blue_crater");
		DiscordObject->SetLargeImageText("Blå Kratern");
	} // Crater Lakes
	else if(InStateString.Contains("Kratersjöar") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Crater Lakes/Kratersjöar"));

		DiscordObject->SetLargeImage("crater_lakes");
		DiscordObject->SetLargeImageText("Kratersjöar");
	} // Dune Desert
	else if(InStateString.Contains("Dynöknen") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Dune Desert/Dynöknen"));

		DiscordObject->SetLargeImage("dune_desert");
		DiscordObject->SetLargeImageText("Dynöknen");
	} // Grass Fields
	else if(InStateString.Contains("Gräsängar") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Grass Fields/Gräsängar"));

		DiscordObject->SetLargeImage("grass_fields");
		DiscordObject->SetLargeImageText("Gräsängar");
	} // Jungle Spires
	else if(InStateString.Contains("Djungelspiror") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Jungle Spires/Djungelspiror"));

		DiscordObject->SetLargeImage("jungle_spires");
		DiscordObject->SetLargeImageText("Djungelspiror");
	} // Lake Forest
	else if(InStateString.Contains("Sjöskog") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Lake Forest/Sjöskog"));

		DiscordObject->SetLargeImage("lake_forest");
		DiscordObject->SetLargeImageText("Sjöskog");
	} // Maze Canyon
	else if(InStateString.Contains("Labyrintravinen") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Maze Canyon/Labyrintravinen"));

		DiscordObject->SetLargeImage("maze_canyon");
		DiscordObject->SetLargeImageText("Labyrintravinen");
	} // No Man's Land
	else if(InStateString.Contains("Ingenmansland") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: No Man's Land/Ingenmansland"));

		DiscordObject->SetLargeImage("no_mans_land");
		DiscordObject->SetLargeImageText("Ingenmansland");
	} // Northern Forest
	else if(InStateString.Contains("Norra skogen") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Northern Forest/Norra skogen"));

		DiscordObject->SetLargeImage("northern_forest");
		DiscordObject->SetLargeImageText("Norra skogen");
	} // Red Bamboo Fields
	else if(InStateString.Contains("Röda bambufält") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Red Bamboo Fields/Röda bambufält"));

		DiscordObject->SetLargeImage("red_bamboo_fields");
		DiscordObject->SetLargeImageText("Röda bambufält");
	} // Red Jungle
	else if(InStateString.Contains("Rödjungeln") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Red Jungle/Rödjungeln"));

		DiscordObject->SetLargeImage("red_jungle");
		DiscordObject->SetLargeImageText("Rödjungeln");
	} // Rocky Desert
	else if(InStateString.Contains("Stenöknen") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Rocky Desert/Stenöknen"));

		DiscordObject->SetLargeImage("rocky_desert");
		DiscordObject->SetLargeImageText("Stenöknen");
	} // Southern Forest
	else if(InStateString.Contains("Södra skogen") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Southern Forest/Södra skogen"));

		DiscordObject->SetLargeImage("southern_forest");
		DiscordObject->SetLargeImageText("Södra skogen");
	} // Spire Coast
	else if(InStateString.Contains("Spetsiga kusten") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Spire Coast/Spetsiga kusten"));

		DiscordObject->SetLargeImage("spire_coast");
		DiscordObject->SetLargeImageText("Spetsiga kusten");
	} // Swamp
	else if(InStateString.Contains("Träsk") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Swamp/Träsk"));

		DiscordObject->SetLargeImage("swamp");
		DiscordObject->SetLargeImageText("Träsk");
	} // Titan Forest
	else if(InStateString.Contains("Titanens skog") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Titan Forest/Titanens skog"));

		DiscordObject->SetLargeImage("titan_forest");
		DiscordObject->SetLargeImageText("Titanens skog");
	} // Western Dune Forest
	else if(InStateString.Contains("Västra dynskogen") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Western Dune Forest/Västra dynskogen"));

		DiscordObject->SetLargeImage("western_dune_forest");
		DiscordObject->SetLargeImageText("Västra dynskogen");
	} // Desert Canyon
	else if(InStateString.Contains("Ökenravinen") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: Desert Canyon/Ökenravinen"));

		DiscordObject->SetLargeImage("desert_canyon");
		DiscordObject->SetLargeImageText("Ökenravinen");
	} // somewhere
	else if(InStateString.Contains("någonstans") == 1)
	{
		UE_LOG(LogFG_DISCORDRP, Verbose, TEXT("Detected Biome: somewhere. This means that the game is loading OR something went terribly wrong."));

		DiscordObject->SetLargeImage("ssd_logo");
		DiscordObject->SetLargeImageText("Error Processing Biome String");
	} // Did we find a biome or do we need to put in the fallback text?
	else if(InPresenceString.Contains(TEXT("Precis landat på den främmande planeten.")))
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

