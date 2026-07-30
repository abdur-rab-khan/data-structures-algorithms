#include <cstring>
#include <iostream>
#include <map>
#include <memory>
using namespace std;

class Texture {
    char* texture;
    int size;

   public:
    Texture(const char* imageData) {
        size = strlen(imageData) + 1;
        texture = new char[size];
        strcpy(texture, imageData);
    }

    Texture(const Texture& obj) {
        int size = strlen(obj.texture) + 1;
        texture = new char[size];
        strcpy(texture, obj.texture);
    }

    ~Texture() { delete[] texture; }

    Texture& operator=(const Texture& obj) {
        if (&obj != this) {
            delete[] texture;

            size = strlen(obj.texture) + 1;
            texture = new char[size];
            strcpy(texture, obj.texture);
        }
        return *this;
    }
};

class TextureManager {
    map<string, shared_ptr<Texture>> textureObject;

   public:
    void addTexture(shared_ptr<Texture> texture, string message) {
        textureObject.insert({message, texture});
        cout << "Texture is added successfully " << endl;
    }

    void removeTexture(string message) {
        textureObject.erase(message);
        cout << "Texture is removed successfully" << endl;
    }

    void updateTexture(shared_ptr<Texture> texture, string message) {
        textureObject[message] = texture;
        cout << "Texture is updated successfully" << endl;
    }
};

int main() {
    shared_ptr<Texture> t1 = make_shared<Texture>("image-data-texture-1");
    shared_ptr<Texture> t2 = make_shared<Texture>("image-data-texture-2");
    shared_ptr<Texture> t3 = make_shared<Texture>("image-data-texture-3");

    TextureManager* manager = new TextureManager();

    manager->addTexture(t1, "rectangle-texture");
    manager->addTexture(t2, "circle-texture");
    manager->addTexture(t3, "shape2-texture");

    manager->updateTexture(make_shared<Texture>("updated-data"), "circle-texture");

    manager->removeTexture("shape2-texture");

    delete manager;
    return 0;
}