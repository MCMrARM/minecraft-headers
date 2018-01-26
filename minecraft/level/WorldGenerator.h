#pragma once

#include "../util/buffer_span.h"

class BlockPos;
class BlockVolume;
class ChunkPos;
class LevelChunk;
enum class StructureFeatureType;

class WorldGenerator {

public:
    char filler[4];

    // virtual
    virtual ~WorldGenerator();
    virtual int getFeatureTypeAt(BlockPos const&) = 0;
    virtual int findNearestFeature(StructureFeatureType, BlockPos const&, BlockPos&) = 0;
    virtual void prepareHeights(BlockVolume&, int, int) = 0;
    virtual void prepareStructureBlueprints(ChunkPos const&) = 0;
    virtual void garbageCollectBlueprints(buffer_span<ChunkPos>) = 0;
    virtual void addHardcodedSpawnAreas(LevelChunk&);

    // non virtual
    WorldGenerator();

};
