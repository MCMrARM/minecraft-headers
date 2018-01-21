#pragma once

#include "BlockSourceListener.h"

enum class ParticleType;
enum class EntityType;
enum class LevelEvent;
enum class LevelSoundEvent;
class Vec3;
class CompoundTag;
class LevelChunk;
class ScreenshotOptions;
class Player;
namespace mce { class ImageBuffer; };

class LevelListener : public BlockSourceListener {

public:
    virtual ~LevelListener();
    virtual void* allChanged();
    virtual void* addParticle(ParticleType, Vec3 const&, Vec3 const&, int, CompoundTag const*, bool);
    virtual void* playMusic(std::string const&, Vec3 const&, float, float);
    virtual void* playStreamingMusic(std::string const&, int, int, int);
    virtual void* onEntityAdded(Entity&);
    virtual void* onEntityRemoved(Entity&);
    virtual void* onNewChunk(BlockSource&, LevelChunk&);
    virtual void* onNewChunkFor(Player&, LevelChunk&);
    virtual void* onChunkLoaded(LevelChunk&);
    virtual void* onChunkUnloaded(LevelChunk&);
    virtual void* onLevelDestruction(std::string const&);
    virtual void* levelEvent(LevelEvent, Vec3 const&, int);
    virtual void* levelSoundEvent(LevelSoundEvent, Vec3 const&, int, EntityType, bool, bool);
    virtual void* levelSoundEvent(std::string const&, Vec3 const&, float, float);
    virtual void* stopSoundEvent(std::string const&);
    virtual void* stopAllSounds();
    virtual void* takePicture(mce::ImageBuffer&, Entity*, Entity*, ScreenshotOptions&);
    virtual void* playerListChanged();

};