#pragma once
#include <map>
#include <memory>
#include <string>

class Texture {
   public:
    void addTexture(const std::string& name, std::shared_ptr<Texture> texture);
    void removeTexture(const std::string& name);
    void updateTexture(const std::string& name, std::shared_ptr<Texture> texture);

   private:
    std::string id;
    int size;
    std::string assetName;
    std::string description;
    std::string path;
};