#pragma once

#include "../game/GameType.h"

enum class StorageVersion;

class LevelData {

public:
    StorageVersion getStorageVersion() const;

    GameType getGameType() const;
    void setGameType(GameType);

};