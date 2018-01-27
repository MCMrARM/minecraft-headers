#pragma once

#include <string>
class Entity;
enum class EntityDamageCause;

struct DeathMessage {
    std::string message;
    std::vector<std::string> args;
};

class EntityDamageSource {

public:
    // virtual
    virtual ~EntityDamageSource();
    virtual bool isEntitySource() const;
    virtual bool isChildEntitySource() const;
    virtual bool isBlockSource() const;
    virtual DeathMessage getDeathMessage(std::string, Entity*) const;
    virtual void* getIsCreative() const;
    virtual void* getIsWorldBuilder() const;
    virtual void* getEntityUniqueID() const;
    virtual void* getEntityType() const;
    virtual void* getEntityCategories() const;
    virtual void* getDamagingEntityIsCreative() const;
    virtual void* getDamagingEntityIsWorldBuilder() const;
    virtual void* getDamagingEntityUniqueID() const;
    virtual void* getDamagingEntityType() const;
    virtual void* getDamagingEntityCategories() const;

    // non virtual
    static void* lookupCause(std::string const&);
    EntityDamageSource(std::string const&);
    EntityDamageSource(EntityDamageCause);
    EntityDamageCause getCause() const;

};
