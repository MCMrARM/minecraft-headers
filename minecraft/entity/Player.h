#pragma once

#include "Entity.h"

class NetworkIdentifier;

class Player : public Entity {

public:
    NetworkIdentifier const& getClientId() const;

    unsigned char getClientSubId() const;

};

enum class DimensionId;
class NetworkIdentifier;

class ServerPlayer : public Player {

public:
    void changeDimension(DimensionId, bool);

};