#pragma once

#include <memory>
#include "Mob.h"
#include "Abilities.h"

class ChunkSource;
class NetworkIdentifier;
class ChalkboardBlockEntity;
class InventoryTransaction;
class ComplexInventoryTransaction;
class Container;
class IContainerManager;
class Tick;
class Packet;
class EventPacket;
class Item;
class PlayerInventoryProxy;
enum class CooldownType;
enum class GameType;

class Player : public Mob {

public:
    char filler[0x1074 - 0x6C];
    Abilities abilities;

    // virtual
    virtual void* reloadHardcoded(Entity::InitializationMethod, VariantParameterList const&);
    virtual void* initializeComponents(Entity::InitializationMethod, VariantParameterList const&);
    virtual ~Player();
    virtual void* remove();
    virtual void* teleportTo(Vec3 const&, bool, int, int);
    virtual void* getAddPacket();
    virtual void* normalTick();
    virtual void* rideTick();
    virtual void* getRidingHeight();
    virtual std::string getFormattedNameTag() const;
    virtual void* getAlwaysShowNameTag() const;
    virtual void* getCameraOffset() const;
    virtual bool isImmobile() const;
    virtual bool isPushable() const;
    virtual bool isPushableByPiston() const;
    virtual bool isShootable();
    virtual bool isCreativeModeAllowed();
    virtual bool isInvulnerableTo(EntityDamageSource const&) const;
    virtual void* onBounceStarted(BlockPos const&, FullBlock const&);
    virtual void* feed(int);
    virtual void* handleEntityEvent(EntityEvent, int);
    virtual void* awardKillScore(Entity&, int);
    virtual void setEquippedSlot(ArmorSlot, int, int);
    virtual void setEquippedSlot(ArmorSlot, ItemInstance const&);
    virtual EntityType getEntityTypeId() const;
    virtual void* getPortalCooldown() const;
    virtual void* getPortalWaitTime() const;
    virtual void* onSynchedDataUpdate(int);
    virtual bool canAddRider(Entity&) const;
    virtual bool canBePulledIntoVehicle() const;
    virtual void* sendMotionPacketIfNeeded();
    virtual CommandPermissionLevel getCommandPermissionLevel() const;
    virtual void* useItem(ItemInstance&) const;
    virtual void* getMapDecorationRotation();
    virtual bool isWorldBuilder();
    virtual bool isCreative() const;
    virtual bool isAdventure() const;
    virtual void* add(ItemInstance&);
    virtual void* drop(ItemInstance const&, bool);
    virtual void* _hurt(EntityDamageSource const&, int, bool, bool);
    virtual void* lavaHurt();
    virtual void* readAdditionalSaveData(CompoundTag const&);
    virtual void* addAdditionalSaveData(CompoundTag&);
    virtual void* onSizeUpdated();
    virtual void* die(EntityDamageSource const&);
    virtual bool isSleeping() const;
    virtual void* getSpeed() const;
    virtual void setSpeed(float);
    virtual bool isJumping() const;
    virtual void* actuallyHurt(int, EntityDamageSource const*, bool);
    virtual void* travel(float, float);
    virtual void* aiStep();
    virtual void* getCarriedItem() const;
    virtual void setCarriedItem(ItemInstance const&);
    virtual void* getItemUseDuration();
    virtual void* getItemUseStartupProgress();
    virtual void* getItemUseIntervalProgress();
    virtual void setArmor(ArmorSlot, ItemInstance const&);
    virtual void* getAllHand() const;
    virtual void* getAllEquipment() const;
    virtual void* sendInventory(bool);
    virtual void setOffhandSlot(ItemInstance const&);
    virtual void* getEquippedTotem();
    virtual void* consumeTotem();
    virtual bool canExistWhenDisallowMob() const;
    virtual void* jumpFromGround();
    virtual void* updateAi();
    virtual void* getExperienceReward() const;
    virtual void* dropEquipment(EntityDamageSource const&, int);
    virtual void* useNewAi() const;
    virtual void* updateGliding();
    virtual void* prepareRegion(ChunkSource&);
    virtual void* destroyRegion();
    virtual void* suspendRegion();
    virtual void* _fireWillChangeDimension();
    virtual void* _fireDimensionChanged();
    virtual void* changeDimensionWithCredits(DimensionId);
    virtual void* tickWorld(Tick const&);
    virtual void* moveView();
    virtual void setName(std::string const&);
    virtual void* checkMovementStats(Vec3 const&);
    virtual void* getCurrentStructureFeature() const;
    virtual void* respawn();
    virtual void* resetRot();
    virtual void* resetPos(bool);
    virtual bool isInTrialMode();
    virtual bool hasResource(int);
    virtual void* completeUsingItem();
    virtual void setPermissions(CommandPermissionLevel);
    virtual void* startCrafting(BlockPos const&, bool);
    virtual void* startStonecutting(BlockPos const&);
    virtual void* startDestroying();
    virtual void* stopDestroying();
    virtual void* openContainer(BlockPos const&);
    virtual void* openContainer(EntityUniqueID const&);
    virtual void* openFurnace(BlockPos const&);
    virtual void* openEnchanter(BlockPos const&);
    virtual void* openAnvil(BlockPos const&);
    virtual void* openBrewingStand(BlockPos const&);
    virtual void* openHopper(BlockPos const&);
    virtual void* openHopper(EntityUniqueID const&);
    virtual void* openDispenser(BlockPos const&, bool);
    virtual void* openBeacon(BlockPos const&);
    virtual void* openPortfolio();
    virtual void* openBook(int, bool);
    virtual void* openCommandBlock(BlockPos const&);
    virtual void* openCommandBlockMinecart(EntityUniqueID const&);
    virtual void* openHorseInventory(EntityUniqueID const&);
    virtual void* openTrading(EntityUniqueID const&);
    virtual bool canOpenContainerScreen();
    virtual void* openChalkboard(ChalkboardBlockEntity&, bool);
    virtual void* openNpcInteractScreen(Entity&);
    virtual void* openInventory();
    virtual void* openStructureEditor(BlockPos const&);
    virtual void* displayChatMessage(std::string const&, std::string const&);
    virtual void* displayClientMessage(std::string const&);
    virtual void* displayLocalizableMessage(std::string const&, std::vector<std::string, std::allocator<std::string>> const&, bool);
    virtual void* displayWhisperMessage(std::string const&, std::string const&, std::string const&);
    virtual void* startSleepInBed(BlockPos const&);
    virtual void* stopSleepInBed(bool, bool);
    virtual bool canStartSleepInBed();
    virtual void* getSleepTimer() const;
    virtual void* getPreviousTickSleepTimer() const;
    virtual void* openSign(BlockPos const&);
    virtual bool isLocalPlayer() const;
    virtual bool isHostingPlayer() const;
    virtual void setSkin(std::string const&, std::vector<unsigned char, std::allocator<unsigned char>> const&, std::vector<unsigned char, std::allocator<unsigned char>> const&, std::string const&, std::string const&);
    virtual void* stopLoading();
    virtual void* registerTrackedBoss(EntityUniqueID);
    virtual void* unRegisterTrackedBoss(EntityUniqueID);
    virtual void setPlayerGameType(GameType);
    virtual void* _crit(Entity&);
    virtual void* getEventing() const;
    virtual void* getUserId() const;
    virtual void* sendEventPacket(EventPacket&) const;
    virtual void* addExperience(int);
    virtual void* addLevels(int);
    virtual void setContainerData(IContainerManager&, int, int) = 0;
    virtual void* slotChanged(IContainerManager&, int, ItemInstance const&, ItemInstance const&, bool) = 0;
    virtual void* inventoryChanged(Container&, int, ItemInstance const&, ItemInstance const&);
    virtual void* refreshContainer(IContainerManager&, std::vector<ItemInstance, std::allocator<ItemInstance>> const&) = 0;
    virtual void* deleteContainerManager();
    virtual void setFieldOfViewModifier(float);
    virtual bool isPositionRelevant(DimensionId, BlockPos const&);
    virtual bool isEntityRelevant(Entity const&);
    virtual bool isTeacher() const = 0;
    virtual void* onSuspension();
    virtual void* onLinkedSlotsChanged();
    virtual void* startCooldown(Item const*);
    virtual void* getItemCooldownLeft(CooldownType) const;
    virtual bool isItemInCooldown(CooldownType) const;
    virtual void* sendInventoryTransaction(InventoryTransaction const&) const = 0;
    virtual void* sendComplexInventoryTransaction(std::unique_ptr<ComplexInventoryTransaction, std::default_delete<ComplexInventoryTransaction>>) const = 0;
    virtual void sendNetworkPacket(Packet&) const;
    virtual void* chorusFruitTeleport();
    virtual void* onMovePlayerPacketNormal(Vec3 const&, Vec2 const&, float);

    PlayerInventoryProxy& getSupplies() const;
    NetworkIdentifier const& getClientId() const;
    unsigned char getClientSubId() const;

    static Attribute HUNGER;
    static Attribute SATURATION;

};

enum class DimensionId;
class NetworkIdentifier;

class ServerPlayer : public Player {

public:
    void disconnect();

};