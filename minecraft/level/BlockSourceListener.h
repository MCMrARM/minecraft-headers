#pragma once

#include <memory>

class BlockSource;
class BlockPos;
class FullBlock;
class Entity;
class BlockEntity;

class BlockSourceListener {
public:
    virtual ~BlockSourceListener();
    virtual void onSourceCreated(BlockSource&);
    virtual void onSourceDestroyed(BlockSource&);
    virtual void onAreaChanged(BlockSource&, BlockPos const&, BlockPos const&);
    virtual void onBlockChanged(BlockSource&, BlockPos const&, FullBlock, FullBlock, int, Entity*);
    virtual void onBrightnessChanged(BlockSource&, BlockPos const&);
    virtual void onBlockEntityChanged(BlockSource&, BlockEntity&);
    virtual void onEntityChanged(BlockSource&, Entity&);
    virtual void onBlockEntityRemoved(BlockSource&, std::unique_ptr<BlockEntity>);
    virtual void onBlockEvent(BlockSource&, int, int, int, int, int);
};