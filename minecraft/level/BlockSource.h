#pragma once

class BlockSource {

public:
    char filler[0x100];

    virtual ~BlockSource();

    BlockSource(Level&, Dimension&, ChunkSource&, bool, bool);

};