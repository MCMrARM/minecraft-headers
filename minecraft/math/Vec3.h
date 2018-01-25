#pragma once

class BlockPos;

struct Vec3 {
    float x, y, z;

    Vec3() : x(0.f), y(0.f), z(0.f) {}
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {}
    Vec3(BlockPos const&);
};