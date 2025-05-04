#include <cstring>
#include <iostream>
using namespace std;

class Image {
    char* data;

   public:
    Image(const char* input) {
        int size = strlen(input) + 1;
        data = new char[size];
        strcpy(data, input);
    }

    Image(const Image& obj) {
        int size = strlen(obj.data) + 1;
        data = new char[size];
        strcpy(this->data, obj.data);
    }

    // Copy Assignment Operator if we do like this img2 = img1; it will work.
    Image& operator=(const Image& obj) {
        if (this != &obj) {
            delete[] data;

            int size = strlen(obj.data) + 1;
            data = new char[size];
            strcpy(data, obj.data);
        }
        return *this;
    }

    ~Image() { delete[] data; }

    void getImageData() const {
        cout << "Image Data is " << endl;
        cout << data << endl;
    }
};

int main() {
    Image* img1 = new Image("image-data");
    Image img2(*img1);

    img1->getImageData();
    img2.getImageData();

    delete img1;
    return 0;
}