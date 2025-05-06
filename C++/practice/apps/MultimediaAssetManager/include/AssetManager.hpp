#include <uuids.h>

#include <map>
#include <memory>

class Asset;  // forward declaration -> Tell compiler Texture named class exits.

class AssetManager {
   private:
    std::map<std::string, std::shared_ptr<Asset>> assets;

   public:
    void addAssets();
    void getAssets();
    void getAllAssets();
    void removeAssets();
    void updateAssets();
    void saveAllAssets();
};