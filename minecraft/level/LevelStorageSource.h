#pragma once

#include <memory>

class LevelStorage;
class IContentKeyProvider;

class LevelStorageSource {

public:
    virtual ~LevelStorageSource();
    virtual void getName();
    virtual void getLevelList();
    virtual void getLevelList2();
    virtual void getLevelData();
    virtual void setLevelData();
    virtual std::unique_ptr<LevelStorage> createLevelStorage(std::string const&, std::string const&, IContentKeyProvider const&);

};