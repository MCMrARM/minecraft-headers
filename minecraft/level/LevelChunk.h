#pragma once

#include "../util/buffer_span.h"
#include "BlockID.h"
#include "../util/NibblePair.h"

enum class DimensionId;
enum class ChunkState;
class ChunkSource;

class LevelChunk {

public:

    DimensionId getDimensionId() const;

    void setSaved();

    void changeState(ChunkState, ChunkState);

    void setAllBlockIDs(buffer_span<BlockID>, short);
    void setAllBlockData(buffer_span<NibblePair>, short);

    void _setGenerator(ChunkSource*);

};