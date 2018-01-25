#pragma once

class Level;
class LevelStorageSource;

class Minecraft {

public:
    Level* getLevel() const;
    LevelStorageSource& getLevelSource();

};