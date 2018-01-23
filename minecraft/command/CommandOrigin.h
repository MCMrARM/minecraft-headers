#pragma once

#include <string>
class Entity;
class Level;
class Dimension;
namespace mce { class UUID; }

enum class CommandOriginType {
    PLAYER, BLOCK /* etc. */
};

class CommandOrigin {

public:
    virtual ~CommandOrigin();
    virtual void getRequestId() = 0;
    virtual void getName() = 0;
    virtual void getBlockPosition() = 0;
    virtual void getWorldPosition() = 0;
    virtual Level* getLevel() const = 0;
    virtual Dimension* getDimension() = 0;
    virtual Entity* getEntity() const = 0;
    virtual void* getPermissionsLevel() const = 0;
    virtual void* clone() const = 0;
    virtual bool canCallHiddenCommands() const;
    virtual bool hasChatPerms() const;
    virtual bool hasTellPerms() const;
    virtual bool canUseAbility(std::string const&) const;
    virtual void* getSourceId() const;
    virtual void* getSourceSubId() const;
    virtual void* getOutputReceiver() const;
    virtual CommandOriginType getOriginType() const = 0;
    virtual void* toCommandOriginData() const;
    virtual void* getUUID() const;
    virtual void* _setUUID(mce::UUID const&);

};