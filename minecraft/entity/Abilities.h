#pragma once

enum class PlayerPermissionLevel {
    VIEWER, MEMBER, OPERATOR
};

class Abilities {

public:
    void setPlayerPermissions(PlayerPermissionLevel level);

    bool getBool(std::string const&) const;
    float getFloat(std::string const&);

    void setAbility(std::string const&, bool);
    void setAbility(std::string const&, float);

    static std::string WALKSPEED;

};