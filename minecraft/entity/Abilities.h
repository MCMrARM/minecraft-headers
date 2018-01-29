#pragma once

enum class PlayerPermissionLevel {
    VIEWER, MEMBER, OPERATOR
};

class Abilities {

public:
    char filler[0x48];

    Abilities();
    Abilities(Abilities const&);

    void setPlayerPermissions(PlayerPermissionLevel level);

    bool getBool(std::string const&) const;
    float getFloat(std::string const&);

    void setAbility(std::string const&, bool);
    void setAbility(std::string const&, float);

    static std::string MAYFLY;
    static std::string WALKSPEED;
    static std::string INVULNERABLE;
    static std::string DOORS_AND_SWITCHES;

    Abilities& operator=(Abilities const&);

};