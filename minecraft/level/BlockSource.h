#pragma once

class Level;
class Dimension;
class ChunkSource;
class Entity;
class ItemInstance;
struct BlockPos;

class BlockSource {

public:
    char filler[0x100];

    virtual ~BlockSource();

    BlockSource(Level&, Dimension&, ChunkSource&, bool, bool);

    BlockPos getHeightmapPos(BlockPos const&);

    bool checkBlockDestroyPermissions(Entity&, BlockPos const&, ItemInstance const&, bool);

};