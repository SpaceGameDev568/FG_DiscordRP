// Created by Satheesh (ryanjon2040). Twitter: https://twitter.com/ryanjon2040. Discord: @ryanjon2040#5319

#include "DiscordRPCServer.h"
#include "../DiscordSDK/discord.h"
#include "UObject/Class.h"

discord::Core* core{};
discord::Activity activity{};

UDiscordRPCServer* UDiscordRPCServer::DiscordRPCServerInstance = nullptr;


UDiscordRPCServer::UDiscordRPCServer()
{
	bCanTick = bTimerStarted = false;
}

UDiscordRPCServer* UDiscordRPCServer::GetOrCreateDiscordRPCServer(FString InClientID, const bool bRequireDiscordRunning /*= false*/, const bool bStartElapsedTimer /*= true*/)
{
	if (DiscordRPCServerInstance == nullptr)
	{
		CreateDiscordRPCServer(InClientID, bRequireDiscordRunning, bStartElapsedTimer);
	}
	
	return DiscordRPCServerInstance;
}

void UDiscordRPCServer::CreateDiscordRPCServer(FString InClientID, const bool bRequireDiscordRunning /*= false*/, const bool bStartElapsedTimer /*= true*/)
{
	if (DiscordRPCServerInstance == nullptr)
	{
		DiscordRPCServerInstance = NewObject<UDiscordRPCServer>();
		DiscordRPCServerInstance->AddToRoot();
		DiscordRPCServerInstance->Internal_CreateDiscordRPCServer(InClientID, bRequireDiscordRunning, bStartElapsedTimer);
	}
}

UDiscordRPCServer* UDiscordRPCServer::GetDiscordRPCServer()
{
	return DiscordRPCServerInstance;
}

void UDiscordRPCServer::DestroyDiscordRPCServer()
{
	if (DiscordRPCServerInstance)
	{
		DiscordRPCServerInstance->SetState("");
		DiscordRPCServerInstance->SetDetails("");
		DiscordRPCServerInstance->StopDiscordTimer();
		DiscordRPCServerInstance->bCanTick = false;
		delete core;
		core = nullptr;
		DiscordRPCServerInstance->RemoveFromRoot();
		DiscordRPCServerInstance->ConditionalBeginDestroy();
		DiscordRPCServerInstance = nullptr;
	}
}

const FString UDiscordRPCServer::GetDiscordResultString(EDiscordReturnResult InDiscordResult)
{
	return UEnum::GetDisplayValueAsText(InDiscordResult).ToString();
}

void UDiscordRPCServer::SetState(FString InNewState)
{
	activity.SetState(TCHAR_TO_UTF8(*InNewState));
	if (core)
	{
		core->ActivityManager().UpdateActivity(activity, [](discord::Result result)
		{
			uint8 ResultByte = (uint8)result;
			DiscordRPCServerInstance->OnStateSet.Broadcast(static_cast<EDiscordReturnResult>(ResultByte));
		});
	}
}

void UDiscordRPCServer::SetDetails(FString InNewDetails)
{
	activity.SetDetails(TCHAR_TO_UTF8(*InNewDetails));
	if (core)
	{
		core->ActivityManager().UpdateActivity(activity, [](discord::Result result)
		{
			uint8 ResultByte = (uint8)result;
			DiscordRPCServerInstance->OnDetailsSet.Broadcast(static_cast<EDiscordReturnResult>(ResultByte));
		});
	}
}

void UDiscordRPCServer::SetLargeImage(const FString InKeyName)
{
	activity.GetAssets().SetLargeImage(TCHAR_TO_UTF8(*InKeyName));
	if (core)
	{
		core->ActivityManager().UpdateActivity(activity, [](discord::Result result)
		{
			uint8 ResultByte = (uint8)result;
			DiscordRPCServerInstance->OnLargeImageSet.Broadcast(static_cast<EDiscordReturnResult>(ResultByte));
		});
	}
}

void UDiscordRPCServer::SetSmallImage(const FString InKeyName)
{
	activity.GetAssets().SetSmallImage(TCHAR_TO_UTF8(*InKeyName));
	if (core)
	{
		core->ActivityManager().UpdateActivity(activity, [](discord::Result result)
		{
			uint8 ResultByte = (uint8)result;
			DiscordRPCServerInstance->OnSmallImageSet.Broadcast(static_cast<EDiscordReturnResult>(ResultByte));
		});
	}
}

void UDiscordRPCServer::SetLargeImageText(FString InNewDetails)
{
	activity.GetAssets().SetLargeText(TCHAR_TO_UTF8(*InNewDetails));
	if (core)
	{
		core->ActivityManager().UpdateActivity(activity, [](discord::Result result)
			{
				uint8 ResultByte = (uint8)result;
				DiscordRPCServerInstance->OnLargeTextSet.Broadcast(static_cast<EDiscordReturnResult>(ResultByte));
			});
	}
}

void UDiscordRPCServer::SetSmallImageText(FString InNewDetails)
{
	activity.GetAssets().SetSmallText(TCHAR_TO_UTF8(*InNewDetails));
	if (core)
	{
		core->ActivityManager().UpdateActivity(activity, [](discord::Result result)
			{
				uint8 ResultByte = (uint8)result;
				DiscordRPCServerInstance->OnSmallTextSet.Broadcast(static_cast<EDiscordReturnResult>(ResultByte));
			});
	}
}

void UDiscordRPCServer::SetPartyId(FString InNewPartyId)
{
	activity.GetParty().SetId(TCHAR_TO_UTF8(*InNewPartyId));
	if (core)
	{
		core->ActivityManager().UpdateActivity(activity, [](discord::Result result)
			{
				uint8 ResultByte = (uint8)result;
				DiscordRPCServerInstance->OnPartyIdSet.Broadcast(static_cast<EDiscordReturnResult>(ResultByte));
			});
	}
}

void UDiscordRPCServer::SetPartySize(int32 InNewPartySize)
{
	activity.GetParty().GetSize().SetCurrentSize(InNewPartySize);
	if (core)
	{
		core->ActivityManager().UpdateActivity(activity, [](discord::Result result)
			{
				uint8 ResultByte = (uint8)result;
				DiscordRPCServerInstance->OnPartySizeSet.Broadcast(static_cast<EDiscordReturnResult>(ResultByte));
			});
	}
}

void UDiscordRPCServer::SetPartyMax(int32 InNewPartyMax)
{
	activity.GetParty().GetSize().SetMaxSize(InNewPartyMax);
	if (core)
	{
		core->ActivityManager().UpdateActivity(activity, [](discord::Result result)
			{
				uint8 ResultByte = (uint8)result;
				DiscordRPCServerInstance->OnPartyMaxSet.Broadcast(static_cast<EDiscordReturnResult>(ResultByte));
			});
	}
}

void UDiscordRPCServer::SetJoinSecret(FString InNewJoinSecret)
{
	activity.GetSecrets().SetJoin(TCHAR_TO_UTF8(*InNewJoinSecret));
	if (core)
	{
		core->ActivityManager().UpdateActivity(activity, [](discord::Result result)
			{
				uint8 ResultByte = (uint8)result;
				DiscordRPCServerInstance->OnJoinSecretSet.Broadcast(static_cast<EDiscordReturnResult>(ResultByte));
			});
	}
}

void UDiscordRPCServer::StartDiscordTimer()
{
	// probably only needed in the editor, but this resets the time across multiple sessions, preventing 00:00 remaining from displaying.
	activity.GetTimestamps().SetEnd(0);

	activity.GetTimestamps().SetStart(FDateTime::UtcNow().ToUnixTimestamp());
	if (core)
	{
		core->ActivityManager().UpdateActivity(activity, [](discord::Result result)
		{
			uint8 ResultByte = (uint8)result;
			DiscordRPCServerInstance->OnTimerStart.Broadcast(static_cast<EDiscordReturnResult>(ResultByte));
		});
	}
}

void UDiscordRPCServer::StopDiscordTimer()
{
	DiscordRPCServerInstance->bTimerStarted = false;
	activity.GetTimestamps().SetEnd(FDateTime::UtcNow().ToUnixTimestamp());
	if (core)
	{
		core->ActivityManager().UpdateActivity(activity, [](discord::Result result)
		{
			uint8 ResultByte = (uint8)result;
			DiscordRPCServerInstance->OnTimerEnd.Broadcast(static_cast<EDiscordReturnResult>(ResultByte));
		});
	}
}

void UDiscordRPCServer::Internal_CreateDiscordRPCServer(const FString& InClientID, const bool bRequireDiscordRunning, const bool bStartElapsedTimer)
{	
#if WITH_EDITOR
	discord::Result result = discord::Core::Create(FCString::Atoi64(*InClientID), DiscordCreateFlags_NoRequireDiscord, &core);
#else
	discord::Result result = discord::Core::Create(FCString::Atoi64(*InClientID), bRequireDiscordRunning ? DiscordCreateFlags_Default : DiscordCreateFlags_NoRequireDiscord, &core);
#endif
	if (result == discord::Result::Ok)
	{
		DiscordRPCServerInstance->bCanTick = true;

		if (bStartElapsedTimer)
		{
			DiscordRPCServerInstance->StartDiscordTimer();
		}
	}
}

void UDiscordRPCServer::Tick(float DeltaTime)
{
	if (bCanTick)
	{
		::core->RunCallbacks();
	}
}