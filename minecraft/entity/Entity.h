#pragma once

#include <string>
#include <vector>

class Vec2;
class Vec3;
class AABB;
class BlockPos;
class Level;
class Dimension;
class Block;
class FullBlock;
class ItemInstance;
class EntityRuntimeID;
class UIProfanityContext;
class EntityDamageSource;
class CompoundTag;
class SetEntityDataPacket;
class ChangeDimensionPacket;
class Mob;
class Player;
class EntityInteraction;
struct EntityLink;
struct EntityUniqueID;
struct EntityPos;
enum class DimensionId;
enum class LevelSoundEvent;
enum class EntityEvent;
enum class InputMode;
enum class MaterialType;
enum class ArmorSlot;
namespace Util { class HashString; }

class Entity {

public:
    enum class InitializationMethod;
    class VariantParameterList;

    // virtual
    virtual void* reloadHardcoded(Entity::InitializationMethod, VariantParameterList const&);
    virtual void* reloadHardcodedClient(Entity::InitializationMethod, VariantParameterList const&);
    virtual void* initializeComponents(Entity::InitializationMethod, VariantParameterList const&);
    virtual void* reloadComponents(Entity::InitializationMethod, VariantParameterList const&);
    virtual bool hasComponent(Util::HashString const&) const;
    virtual bool hasInventory() const;
    virtual void* getInventory();
    virtual ~Entity();
    virtual void* reset();
    virtual void* getOwnerEntityType();
    virtual void* remove();
    virtual void setPos(Vec3 const&);
    virtual Vec3 const& getPos() const;
    virtual void* getPosOld() const;
    virtual void* getPosExtrapolated(float) const;
    virtual void* getVelocity() const;
    virtual void* getFiringPos() const;
    virtual void setRot(Vec2 const&);
    virtual void* move(Vec3 const&);
    virtual void* getInterpolatedRidingPosition(float) const;
    virtual void* getInterpolatedBodyRot(float) const;
    virtual void* checkBlockCollisions(AABB const&);
    virtual void* checkBlockCollisions();
    virtual void* breaksFallingBlocks() const;
    virtual void* moveRelative(float, float, float);
    virtual void* teleportTo(Vec3 const&, bool, int, int);
    virtual void* tryTeleportTo(Vec3 const&, bool, bool, int, int);
    virtual void* lerpTo(Vec3 const&, Vec2 const&, int);
    virtual void* lerpMotion(Vec3 const&);
    virtual void* getAddPacket();
    virtual void* normalTick();
    virtual void* baseTick();
    virtual void* rideTick();
    virtual void* positionRider(Entity&, float) const;
    virtual void* getRidingHeight();
    virtual void* startRiding(Entity&);
    virtual void* addRider(Entity&);
    virtual void* flagRiderToRemove(Entity&);
    virtual void* getExitTip(std::string const&, InputMode) const;
    virtual void* intersects(Vec3 const&, Vec3 const&);
    virtual bool isFree(Vec3 const&, float);
    virtual bool isFree(Vec3 const&);
    virtual bool isInWall() const;
    virtual bool isInvisible() const;
    virtual bool canShowNameTag();
    virtual bool canExistInPeaceful() const;
    virtual void setNameTagVisible(bool);
    virtual void* getNameTag() const;
    virtual std::string getFormattedNameTag() const;
    virtual void* filterFormattedNameTag(UIProfanityContext const&);
    virtual void setNameTag(std::string const&);
    virtual void* getAlwaysShowNameTag() const;
    virtual bool isInWater() const;
    virtual bool isInWaterOrRain() const;
    virtual bool isInLava() const;
    virtual bool isUnderLiquid(MaterialType) const;
    virtual bool isOverWater() const;
    virtual void* makeStuckInWeb();
    virtual void* getCameraOffset() const;
    virtual void* getShadowHeightOffs();
    virtual void* getShadowRadius() const;
    virtual void* getHeadLookVector(float);
    virtual bool canSeeInvisible();
    virtual bool canSee(Entity const&) const;
    virtual bool isSkyLit(float);
    virtual void* getBrightness(float) const;
    virtual void* interactPreventDefault();
    virtual void* playerTouch(Player&);
    virtual void* push(Entity&, bool);
    virtual void* push(Vec3 const&);
    virtual void* partialPush(Vec3 const&);
    virtual bool isImmobile() const;
    virtual bool isSilent();
    virtual bool isPickable();
    virtual bool isFishable() const;
    virtual bool isPushable() const;
    virtual bool isPushableByPiston() const;
    virtual bool isShootable();
    virtual bool isSneaking() const;
    virtual bool isAlive() const;
    virtual bool isOnFire() const;
    virtual bool isOnMagma() const;
    virtual bool isCreativeModeAllowed();
    virtual bool isSurfaceMob() const;
    virtual bool isTargetable() const;
    virtual void setTarget(Entity*);
    virtual void* findAttackTarget();
    virtual bool isValidTarget(Entity*) const;
    virtual void setOwner(EntityUniqueID);
    virtual void setSitting(bool);
    virtual void* onTame();
    virtual void* onFailedTame();
    virtual void* onMate(Mob&);
    virtual void* getInventorySize() const;
    virtual void* getEquipSlots() const;
    virtual void* getChestSlots() const;
    virtual void setStanding(bool);
    virtual bool canPowerJump() const;
    virtual void setCanPowerJump(bool);
    virtual void* rideJumped();
    virtual void* rideLanded(Vec3 const&, Vec3 const&);
    virtual void* shouldRender() const;
    virtual bool isInvulnerableTo(EntityDamageSource const&) const;
    virtual void* animateHurt();
    virtual void* doFireHurt(int);
    virtual void* onLightningHit();
    virtual void* onBounceStarted(BlockPos const&, FullBlock const&);
    virtual void* feed(int);
    virtual void* handleEntityEvent(EntityEvent, int);
    virtual void* getPickRadius();
    virtual void* spawnAtLocation(int, int);
    virtual void* spawnAtLocation(int, int, float);
    virtual void* spawnAtLocation(FullBlock, int);
    virtual void* spawnAtLocation(FullBlock, int, float);
    virtual void* spawnAtLocation(ItemInstance const&, float);
    virtual void* killed(Entity*);
    virtual void* awardKillScore(Entity&, int);
    virtual void setEquippedSlot(ArmorSlot, int, int);
    virtual void setEquippedSlot(ArmorSlot, ItemInstance const&);
    virtual void* save(CompoundTag&);
    virtual void* saveWithoutId(CompoundTag&);
    virtual void* load(CompoundTag const&);
    virtual void* loadLinks(CompoundTag const&, std::vector<EntityLink>&);
    virtual void* getEntityTypeId() const = 0;
    virtual void* acceptClientsideEntityData(Player&, SetEntityDataPacket const&);
    virtual void* queryEntityRenderer();
    virtual void* getSourceUniqueID() const;
    virtual void setOnFire(int);
    virtual void* getHandleWaterAABB() const;
    virtual void* handleInsidePortal(BlockPos const&);
    virtual void* getPortalCooldown() const;
    virtual void* getPortalWaitTime() const;
    virtual DimensionId getDimensionId() const;
    virtual bool canChangeDimensions() const;
    virtual void changeDimension(DimensionId, bool);
    virtual void changeDimension(ChangeDimensionPacket const&);
    virtual void* getControllingPlayer() const;
    virtual void* checkFallDamage(float, bool);
    virtual void* causeFallDamage(float);
    virtual void* handleFallDistanceOnServer(float, bool);
    virtual void* playSynchronizedSound(LevelSoundEvent, Vec3 const&, int, bool);
    virtual void* onSynchedDataUpdate(int);
    virtual bool canAddRider(Entity&) const;
    virtual bool canBePulledIntoVehicle() const;
    virtual void* inCaravan() const;
    virtual bool canBeLeashed();
    virtual bool isLeashableType();
    virtual void* tickLeash();
    virtual void* sendMotionPacketIfNeeded();
    virtual bool canSynchronizeNewEntity() const;
    virtual void* stopRiding(bool, bool);
    virtual void* buildDebugInfo(std::string&) const;
    virtual void* getCommandPermissionLevel() const;
    virtual void* openContainerComponent(Player&);
    virtual void* useItem(ItemInstance&) const;
    virtual bool hasOutputSignal(signed char) const;
    virtual void* getOutputSignal() const;
    virtual void* getDebugText(std::vector<std::string>&);
    virtual void* startSeenByPlayer(Player&);
    virtual void* stopSeenByPlayer(Player&);
    virtual void* getMapDecorationRotation();
    virtual void* getRiderDecorationRotation(Player&);
    virtual void* getYHeadRot() const;
    virtual bool isWorldBuilder();
    virtual bool isCreative() const;
    virtual bool isAdventure() const;
    virtual void* add(ItemInstance&);
    virtual void* drop(ItemInstance const&, bool);
    virtual void* getInteraction(Player&, EntityInteraction&, Vec3 const&);
    virtual bool canDestroyBlock(Block const&) const;
    virtual void setAuxValue(int);
    virtual void setSize(float, float);
    virtual void* wobble();
    virtual void setPos(EntityPos const&);
    virtual void* outOfWorld();
    virtual void* _hurt(EntityDamageSource const&, int, bool, bool);
    virtual void* markHurt();
    virtual void* lavaHurt();
    virtual void* readAdditionalSaveData(CompoundTag const&);
    virtual void* addAdditionalSaveData(CompoundTag&);
    virtual void* _playStepSound(BlockPos const&, int);
    virtual void* _playFlySound(BlockPos const&, int);
    virtual void* _makeFlySound() const;
    virtual void* checkInsideBlocks(float);
    virtual void* pushOutOfBlocks(Vec3 const&);
    virtual void* updateWaterState();
    virtual void* doWaterSplashEffect();
    virtual void* spawnTrailBubbles();
    virtual void* updateInsideBlock();
    virtual void* getLootTable();
    virtual void* getDefaultLootTable();
    virtual void* _removeRider(Entity&, bool);
    virtual void* onSizeUpdated();

    // non virtual
    Level* getLevel();
    Level const* getLevel() const;
    void _setLevelPtr(Level*);
    void _setDimension(Dimension&);
    EntityRuntimeID getRuntimeID() const;
    void _usePortal(DimensionId, DimensionId, int);

};