#pragma once
#include <map>
#include <memory>
#include <string>

class Video {
   public:
    void addVideo(const std::string& name, std::shared_ptr<Texture> texture);
    void removeVideo(const std::string& name);
    void updateVideo(const std::string& name, std::shared_ptr<Texture> texture);

   private:
    std::string id;
    int size;
    std::string assetName;
    std::string description;
    std::string path;
};