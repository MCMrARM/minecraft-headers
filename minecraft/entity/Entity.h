#pragma once

class Level;
class Dimension;
class EntityRuntimeID;

class Entity {

public:
    virtual ~Entity();

    Level* getLevel();
    Level const* getLevel() const;
    void _setLevelPtr(Level*);
    void _setDimension(Dimension&);
    EntityRuntimeID getRuntimeID() const;

};