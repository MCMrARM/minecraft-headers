#pragma once

#include "../entity/EntityRuntimeID.h"
#include "../math/Vec3.h"

class BinaryStream;
class NetworkIdentifier;
class NetEventCallback;

class Packet {

public:
    int unk_4 = 2, unk_8 = 1;
    bool unk_C = 0;

    virtual ~Packet();
    virtual void* getId() const = 0;
    virtual void* getName() const = 0;
    virtual void* write(BinaryStream&) const = 0;
    virtual void* read(BinaryStream&) = 0;
    virtual void* handle(NetworkIdentifier const&, NetEventCallback&) const = 0;
    virtual bool disallowBatching() const;

};

class ChangeDimensionPacket : public Packet {
public:
    int dimension;
    Vec3 pos;
    bool b;
    virtual void* getId() const;
    virtual void* getName() const;
    virtual void* write(BinaryStream&) const;
    virtual void* read(BinaryStream&);
    virtual void* handle(NetworkIdentifier const&, NetEventCallback&) const;
};
class PlayStatusPacket : public Packet {
public:
    int status;
    virtual void* getId() const;
    virtual void* getName() const;
    virtual void* write(BinaryStream&) const;
    virtual void* read(BinaryStream&);
    virtual void* handle(NetworkIdentifier const&, NetEventCallback&) const;
};
class FullChunkDataPacket : public Packet {
public:
    int chunkX, chunkZ;
    std::string data;
    virtual void* getId() const;
    virtual void* getName() const;
    virtual void* write(BinaryStream&) const;
    virtual void* read(BinaryStream&);
    virtual void* handle(NetworkIdentifier const&, NetEventCallback&) const;
};
class PlayerActionPacket : public Packet {
public:
    int filler[3]; // 1C
    int face; // 20
    int action; // 24
    EntityRuntimeID entityId;
    virtual void* getId() const;
    virtual void* getName() const;
    virtual void* write(BinaryStream&) const;
    virtual void* read(BinaryStream&);
    virtual void* handle(NetworkIdentifier const&, NetEventCallback&) const;
};
enum class TextPacketType : unsigned char { };
class TextPacket : public Packet {
public:
    TextPacketType type; // 10
    std::string str1, str2; // 14, 18
    std::vector<std::string> params; // 24
    bool unkBool; // 25
    std::string str3;

    virtual void* getId() const;
    virtual void* getName() const;
    virtual void* write(BinaryStream&) const;
    virtual void* read(BinaryStream&);
    virtual void* handle(NetworkIdentifier const&, NetEventCallback&) const;

    TextPacket(TextPacketType, std::string const&, std::string const&, std::vector<std::string> const&, bool, std::string const&);
    static TextPacket createRaw(std::string const&);
};