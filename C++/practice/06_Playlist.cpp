#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Playlist {
   private:
    char** playlist;
    int size;

   public:
    Playlist() {
        cout << "Enter the number of songs ";
        cin >> size;

        playlist = new char*[size];

        cin.ignore();
        for (int i = 0; i < size; i++) {
            string songTitle;
            cout << endl << "Enter your song " << endl;

            getline(cin, songTitle);

            playlist[i] = new char[songTitle.length() + 1];
            strcpy(playlist[i], songTitle.c_str());
        }
    }

    Playlist(const Playlist& obj) {
        size = obj.size;
        playlist = new char*[size];

        for (int i = 0; i < size; i++) {
            char* song = obj.playlist[i];

            playlist[i] = new char[strlen(song) + 1];
            strcpy(playlist[i], song);
        }
    }

    ~Playlist() {
        for (int i = 0; i < size; i++) {
            delete[] playlist[i];
        }

        delete[] playlist;
    }

    Playlist& operator=(const Playlist& obj) {
        if (&obj != this) {
            for (int i = 0; i < size; i++) {
                delete[] playlist[i];
            }
            delete[] playlist;

            size = obj.size;
            playlist = new char*[size];
            for (int i = 0; i < size; i++) {
                playlist[i] = new char[strlen(obj.playlist[i]) + 1];
                strcpy(playlist[i], obj.playlist[i]);
            }
        }

        return *this;
    }

    // Member functions
    void getPlaylistSongs() {
        cout << "\nList of songs:\n";
        for (int i = 0; i < size; i++) {
            cout << "- " << playlist[i] << endl;
        }
    }
};

int main() {
    Playlist* p1 = new Playlist();
    p1->getPlaylistSongs();

    // Optional: test copy
    Playlist p2 = *p1;
    p2.getPlaylistSongs();

    delete p1;
    return 0;
}