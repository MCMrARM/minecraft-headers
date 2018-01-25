#pragma once

#include "Tag.h"

class CompoundTag : public Tag {

public:
    // virtual
    virtual ~CompoundTag();
    virtual void* write(IDataOutput&) const;
    virtual void* load(IDataInput&);
    virtual void* toString() const;
    virtual void* getId() const;
    virtual void* equals(Tag const&) const;
    virtual void* print(std::string const&, PrintStream&) const;
    virtual void* copy() const;

    // non virtual
    CompoundTag();
    CompoundTag(std::string const&);
    CompoundTag(CompoundTag&&);

};
