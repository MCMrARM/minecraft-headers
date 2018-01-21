#pragma once

#include <string>
#include "ResourceFileSystem.h"

class ResourceLocation {

private:
    std::string name;
    ResourceFileSystem fs;

public:
    ResourceLocation(std::string const& name, ResourceFileSystem fs = ResourceFileSystem::InAppPackage) : name(name), fs(fs) {}

};