NOTE: For the initial launch, the Unreal plugin has a name of DiscordPartnerSDK but this name will be changing to DiscordSocialSDK in a future version. This will probably require a refactor.

SDK Version: 1.10.19337

1. Make a manual backup of the entire mod

2. Delete the old SDK files in the source folder (`DiscordPartnerSDK` and `ThirdParty/DiscordPartnerSDKLibrary`)

3. Nuke the `Binaries` and `Intermediate` folders inside `FG_DiscordRP` to avoid conflicts with outdated build caches

4. Download new SDK from https://discord.com/developers/applications/1082738646173614143/social-sdk/downloads

5. Copy the `Binaries`, `Config`, and `Source` folders from the new plugin to the mod

6. Regenerate project files

7. Edit line `35` of DiscordParterSDK.cpp to change the plugin base directory to that of the mod:

	`FString BaseDir = IPluginManager::Get().FindPlugin("FG_DiscordRP")->GetBaseDir();`

8. If all is working correctly, update the SDK Version at the top of this file.

9. Done
