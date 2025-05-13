#pragma once
#include <map>
#include <memory>
#include <string>

class Image {
   public:
    void addImage(const std::string& name, std::shared_ptr<Texture> texture);
    void removeImage(const std::string& name);
    void updateImage(const std::string& name, std::shared_ptr<Texture> texture);

   private:
    std::string id;
    int size;
    std::string assetName;
    std::string description;
    std::string path;
};