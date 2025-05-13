#pragma once

#include <memory>

#include "AssetManager.hpp"

class Asset {
   public:
    virtual void load() = 0;
    virtual void save() = 0;
    virtual void getInfo(const std::string& id) = 0;
};