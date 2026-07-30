#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;

class FileHandler {
    fstream file;
    string fileName;

   public:
    FileHandler(const string& fileName) {
        if (!filesystem::exists(fileName)) {
            ofstream createFile(fileName);

            if (!createFile) {
                throw runtime_error("Failed to create file");
            }
        }

        file.open(fileName, ios::in | ios::out);
        if (!file.is_open()) {
            throw runtime_error("Failed to open file");
        }
    }

    FileHandler(const FileHandler& obj) = delete;

    FileHandler& operator=(const FileHandler&) = delete;

    ~FileHandler() {
        if (file.is_open()) {
            file.close();
        }
    }

    // Member Functions
    void writeLine(const string& line) { file << line << endl; };

    void readLine() {
        file.clear();
        file.seekg(0);

        string line;
        while (getline(file, line)) {
            std::cout << line << '\n';
        }
    };
};

int main() {
    FileHandler f1("./files/file_1.txt");

    f1.writeLine(
        "In C++, file handling refers to each operation that is related to a file, such as "
        "creating, reading, and writing data. It allows us is used to store data permanently in "
        "the secondary memory of the computer (like the hard drive or SSD). In this way, the data "
        "can be preserved and accessed even after the program stops running.");

    f1.readLine();
    return 0;
}