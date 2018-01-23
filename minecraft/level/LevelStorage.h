#pragma once

#include <string>
#include <memory>
class KeySpan;
class StringByteInput;
class LevelData;
class ChunkSource;
class Player;
class Entity;
class CompoundTag;
enum class StorageVersion;
enum class CompactionStatus;

class LevelStorage {

public:
    // virtual
    virtual ~LevelStorage();
    virtual void* getKeysForPrefix(std::string const&) = 0;
    virtual void* deserializeKey(KeySpan const&, StringByteInput&);
    virtual void* loadLevelData(LevelData&) = 0;
    virtual std::unique_ptr<ChunkSource> createChunkStorage(std::unique_ptr<ChunkSource>, StorageVersion) = 0;
    virtual void* saveLevelData(LevelData const&) = 0;
    virtual void* getFullPath() const = 0;
    virtual void* savePlayerData(std::string const&, std::string&&) = 0;
    virtual void* saveData(std::string const&, std::string&&) = 0;
    virtual void* deleteData(std::string const&) = 0;
    virtual void* getStatistics(std::string&) const = 0;
    virtual void* clonePlayerData(std::string const&, std::string const&);
    virtual bool isCorrupted() const = 0;
    virtual void* loadData(std::string const&);
    virtual void* getState() const = 0;
    virtual void* loadPlayerData(std::string const&, std::string const&, std::string const&) = 0;
    virtual void* loadLocalPlayerData() = 0;
    virtual void* loadAllPlayerIDs() = 0;
    virtual void* save(Player&) = 0;
    virtual void* save(Entity&) = 0;
    virtual void* getLevelId() const = 0;
    virtual void* pauseModificationsAndGetFiles() = 0;
    virtual void* resumeModifications() = 0;
    virtual void* compactStorage() = 0;
    virtual void* syncAndSuspendStorage() = 0;
    virtual void* resumeStorage() = 0;
    virtual void setCompactionCallback(std::function<void (CompactionStatus)>) = 0;
    virtual void setCriticalSyncSaveCallback(std::function<void (std::string const&)>) = 0;
    virtual void* _savePlayerDataSync(std::string const&, std::string&&) = 0;

    // non virtual
    void* loadServerPlayerData(Player const&);
    void* saveData(std::string const&, CompoundTag const&);
    void* savePlayerData(std::string const&, CompoundTag const&);

    // static fields
    static void* LOCAL_PLAYER_TAG;

};
