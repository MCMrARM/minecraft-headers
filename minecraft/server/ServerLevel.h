#pragma once

#include <string>
#include "../level/Level.h"

class SoundPlayer;
class LevelSettings;
class LevelStorage;
class MinecraftEventing;
class ResourcePackManager;
class StructureManager;
class MinecraftCommands;
namespace minecraft { namespace api { class Api; } }

class ServerLevel : public Level {

private:
    char filler[0x2000];

public:
    ServerLevel(SoundPlayer&, std::unique_ptr<LevelStorage>, std::string const&, LevelSettings const&, MinecraftEventing&, ResourcePackManager&, ResourcePackManager&, StructureManager&, MinecraftCommands&, minecraft::api::Api*);

};