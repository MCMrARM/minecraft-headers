#pragma once

#include <string>

class IDataInput;
class IDataOutput;
class PrintStream;

class Tag {

public:
    // virtual
    virtual ~Tag();
    virtual void* deleteChildren();
    virtual void* write(IDataOutput&) const = 0;
    virtual void* load(IDataInput&) = 0;
    virtual void* toString() const = 0;
    virtual void* getId() const = 0;
    virtual void* equals(Tag const&) const;
    virtual void* print(PrintStream&) const;
    virtual void* print(std::string const&, PrintStream&) const;
    virtual void setName(std::string const&);
    virtual void* getName() const;
    virtual void* copy() const = 0;

    // non virtual
    Tag(std::string const&);

};
