#pragma once
#include <map>
#include <memory>
#include <string>

class Audio {
   public:
    void addAudio(const std::string& name, std::shared_ptr<Texture> texture);
    void removeAudio(const std::string& name);
    void updateAudio(const std::string& name, std::shared_ptr<Texture> texture);

   private:
    std::string id;
    int size;
    std::string assetName;
    std::string description;
    std::string path;
};