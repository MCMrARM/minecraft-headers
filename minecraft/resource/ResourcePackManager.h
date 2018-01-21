#pragma once

class ResourcePackManager {

public:
    virtual ~ResourcePackManager();
    virtual void load(ResourceLocation const&, std::string&);

};