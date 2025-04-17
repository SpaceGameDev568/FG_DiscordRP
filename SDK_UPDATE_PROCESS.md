NOTE: For the initial launch, the Unreal plugin has a name of DiscordPartnerSDK but this name will be changing to DiscordSocialSDK in a future version. This will probably require a refactor.

SDK Version: 1.1.8166

1. Make a manual backup of the entire mod

2. Delete the old SDK files in the source folder (`DiscordPartnerSDK` and `ThirdParty/DiscordPartnerSDKLibrary`)

3. Download new SDK from https://discord.com/developers/applications/1082738646173614143/social-sdk/downloads

4. Copy the `Binaries`, `Config`, and `Source` folders from the new plugin to the mod

5. Regenerate project files

6. Edit line `45` of DiscordParterSDK.cpp to change the plugin base directory to that of the mod:

	`FString BaseDir = IPluginManager::Get().FindPlugin("FG_DiscordRP")->GetBaseDir();`

7. Done