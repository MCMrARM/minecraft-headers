#pragma once

class SavedData {
public:
    virtual ~SavedData() = 0;
    virtual void* deserialize(CompoundTag const&) = 0;
    virtual void* serialize(CompoundTag&) const = 0;
};