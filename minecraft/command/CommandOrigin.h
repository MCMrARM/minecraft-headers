#pragma once

class Entity;
class Level;

class CommandOrigin {

public:
    virtual ~CommandOrigin();
    virtual void getRequestId();
    virtual void getName();
    virtual void getBlockPosition();
    virtual void getWorldPosition();
    virtual Level* getLevel() const;
    virtual void getDimension();
    virtual Entity* getEntity() const;

};