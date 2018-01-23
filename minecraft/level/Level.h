#pragma once

#include <memory>
#include <vector>
#include "BlockSourceListener.h"

class Player;
class PacketSender;
class LevelStorage;
class LevelData;

class Level : public BlockSourceListener {

public:
    char filler[0xc-4];
    std::vector<std::unique_ptr<Player>> players;

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

};
