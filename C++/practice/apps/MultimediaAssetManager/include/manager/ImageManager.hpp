#pragma once

#include <memory.h>

#include "Asset.hpp"
#include "AssetManager.hpp"

class ImageManager : public Asset {
   private:
    std::shared_ptr<AssetManager> assetManager;

   public:
    ImageManager(std::shared_ptr<AssetManager> assetManger);

    void load();
    void save();
    void getInfo(const std::string& id);
};