#pragma once

#include <memory>

class ChunkPos;
class ChunkViewSource;
class Random;
class BlockSource;
class LevelChunk;
class Dimension;

class ChunkSource {

public:
    char filler[0x14];

    enum class LoadMode;

    virtual ~ChunkSource();
    virtual void shutdown();
    virtual bool isShutdownDone();
    virtual void* getExistingChunk(ChunkPos const&);
    virtual void* getRandomChunk(Random&);
    virtual void* createNewChunk(ChunkPos const&, LoadMode);
    virtual void* postProcess(ChunkViewSource&);
    virtual void* checkAndReplaceChunk(ChunkViewSource&, LevelChunk&);
    virtual void loadChunk(LevelChunk&, bool);
    virtual void* postProcessMobsAt(BlockSource*, int, int, Random&);
    virtual void saveLiveChunk(LevelChunk&);
    virtual void* hintDiscardBatchBegin();
    virtual void* hintDiscardBatchEnd();
    virtual void* acquireDiscarded(std::unique_ptr<LevelChunk>);
    virtual void* compact();
    virtual void flushPendingWrites();
    virtual bool isWithinWorldLimit(ChunkPos const&);
    virtual void* getStorage() const;

    ChunkSource(ChunkSource&);
    ChunkSource(Dimension*, int);
    ChunkSource(std::unique_ptr<ChunkSource>);

};