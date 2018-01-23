#pragma once

#include "../math/Vec3.h"

class Player;
enum class DimensionId;

struct ChangeDimensionRequest {

    int unknown; // 4
    DimensionId sourceDimension; // 8
    DimensionId targetDimension; // c
    Vec3 position; // 18
    bool unknown2, unknown3; // 19, 1a ~1c
    int unknown4; // 0x20

};