#pragma once

#include "../game/GameType.h"

enum class StorageVersion;

class LevelData {

public:
    char filler[0x104];
    std::string flatPreset;

    StorageVersion getStorageVersion() const;

    GameType getGameType() const;
    void setGameType(GameType);

};