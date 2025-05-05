#pragma once
#include <map>
#include <memory>
#include <string>

class Texture;

class TextureManager {
   public:
    void addTexture(const std::string& name, std::shared_ptr<Texture> texture);
    void removeTexture(const std::string& name);
    void updateTexture(const std::string& name, std::shared_ptr<Texture> texture);

   private:
    std::map<std::string, std::shared_ptr<Texture>> texture;
}