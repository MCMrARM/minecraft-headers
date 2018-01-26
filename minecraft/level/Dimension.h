#pragma once

#include <string>
#include "../util/ThreadLocal.h"

#include "LevelListener.h"
#include "SavedData.h"

enum class DimensionId;
enum class GeneratorType;
class Player;
class Level;
class BiomeSource;
class Packet;
class ChunkSource;
class BlockSource;
class RuntimeLightingManager;
class WorldGenerator;

class Dimension : public LevelListener, public SavedData {

public:
    char filler[0xC-8];
    std::string dimensionName; // 10
    Level* level; // 14
    short unk_14; // 18
    ThreadLocal<BiomeSource> biomeSource; // 40
    std::unique_ptr<BlockSource> blockSource; // 44
    char filler3[0x6C - 0x44];
    unsigned char maxBrightness; // 0x6D
    char filler4[0x70 - 0x6D];
    DimensionId id;
    char filler5[0x76 - 0x74];
    bool unk_76;
    char filler6[0xC4 - 0x77];
    std::unique_ptr<ChunkSource> chunkSource; // C8
    WorldGenerator* generator; // CC
    char filler7[0x134 - 0xCC];
    std::unique_ptr<RuntimeLightingManager> runtimeLightingManager;
    char filler8[0x2000];

    // virtual
    virtual ~Dimension();
    virtual void onBlockChanged(BlockSource&, BlockPos const&, FullBlock, FullBlock, int, Entity*);
    virtual void onBlockEvent(BlockSource&, int, int, int, int, int);
    virtual void* onNewChunk(BlockSource&, LevelChunk&);
    virtual void* onChunkLoaded(LevelChunk&);
    virtual void* onLevelDestruction(std::string const&);
    virtual void init();
    virtual void* tick();
    virtual void* tickRedstone();
    virtual void* updateLightRamp();
    virtual bool isNaturalDimension() const;
    virtual bool isValidSpawn(int, int) const;
    virtual void* getFogColor(float) const;
    virtual void* getMaxFogEnd() const;
    virtual void* getMaxFogStart() const;
    virtual bool isFoggyAt(int, int) const;
    virtual void* getCloudHeight() const;
    virtual void* getDefaultBiome() const;
    virtual void* mayRespawn() const;
    virtual bool hasGround() const;
    virtual void* getSpawnPos() const;
    virtual void* getSpawnYPosition() const;
    virtual bool hasBedrockFog();
    virtual void* getClearColorScale();
    virtual std::string getName() const = 0;
    virtual void* showSky() const;
    virtual bool isDay() const;
    virtual Vec3 translatePosAcrossDimension(Vec3 const&, DimensionId) const = 0;
    virtual void* deserialize(CompoundTag const&);
    virtual void* serialize(CompoundTag&) const;
    virtual void* sendBroadcast(Packet const&, Player*);
    virtual void* startLeaveGame();
    virtual void* getTimeOfDay(int, float) const;

    // non virtual
    Dimension(Level&, DimensionId, short);

    std::unique_ptr<ChunkSource> _createGenerator(GeneratorType);

};