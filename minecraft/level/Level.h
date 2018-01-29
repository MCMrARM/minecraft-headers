#pragma once

#include <memory>
#include <vector>
#include <unordered_map>
#include "BlockSourceListener.h"

class Player;
class PacketSender;
class LevelStorage;
class LevelData;
class Dimension;
class ChangeDimensionRequest;
class AdventureSettings;
class Abilities;
class BlockPos;
enum class DimensionId;

class Level : public BlockSourceListener {

public:
    char filler[0xc-4];
    std::vector<std::unique_ptr<Player>> players; // 18
    char filler2[0x208 - 0x18];
    std::unordered_map<int, std::unique_ptr<Dimension>> dimensions;

    virtual ~Level();
    virtual void addEntity(BlockSource&, std::unique_ptr<Entity>);
    virtual void addGlobalEntity(BlockSource&, std::unique_ptr<Entity>);
    virtual void addAutonomousEntity(BlockSource&, std::unique_ptr<Entity>);
    virtual void addPlayer(std::unique_ptr<Player>);
    virtual void takeEntity();
    virtual void borrowEntity();
    virtual void onPlayerDeath();
    virtual void tick();

    std::vector<std::unique_ptr<Player>>& getUsers();

    LevelStorage* getLevelStorage();

    LevelData* getLevelData();

    void setPacketSender(PacketSender*);
    PacketSender* getPacketSender() const;

    Dimension* createDimension(DimensionId);

    void requestPlayerChangeDimension(Player&, std::unique_ptr<ChangeDimensionRequest>);

    AdventureSettings& getAdventureSettings();

    Abilities& getDefaultAbilities();

    BlockPos const& getSharedSpawnPos();

};
