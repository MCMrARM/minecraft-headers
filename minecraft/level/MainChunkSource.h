#pragma once

#include "ChunkSource.h"

class MainChunkSource : public ChunkSource {

public:
    char filler[0x40];

    MainChunkSource(std::unique_ptr<ChunkSource>);

};