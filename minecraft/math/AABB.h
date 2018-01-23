#pragma once

#include "Vec3.h"

class AABB {

public:
    Vec3 min, max;
    bool empty;

    AABB();
    AABB(float, float, float, float, float, float);
    AABB(Vec3 const&, Vec3 const&);
    AABB(Vec3 const&, float);

    bool contains(Vec3 const&) const;

};