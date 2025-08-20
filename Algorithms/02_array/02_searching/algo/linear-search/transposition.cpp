#include <initializer_list>
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class MArray {
   private:
    int size;

   public:
    T* data;

    MArray(initializer_list<T> values) {
        int length = values.size();
        size = length;
        data = new T[length];

        int i = 0;
        for (const T& v : values) {
            data[i++] = v;
        }
    }

    void display() const {
        if (data == nullptr)
            throw runtime_error("There is no data");

        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    int getSize() const { return size; }

    ~MArray() { delete[] data; }
};

int transpositionSearch(MArray<int>& arr, int x) {
    for (int i = 0; i < arr.getSize(); i++) {
        if (arr.data[i] == x) {
            if (i == 0) {
                return i;
            }

            swap(arr.data[i], arr.data[i - 1]);

            return i;
        }
    }

    return -1;
}

int main() {
    MArray<int> arr({1, 2, 3, 4});

    cout << "4 in array is found at: " << transpositionSearch(arr, 4) << endl;
    cout << "4 in array is found at: " << transpositionSearch(arr, 4) << endl;
    cout << "4 in array is found at: " << transpositionSearch(arr, 4) << endl;
    cout << "4 in array is found at: " << transpositionSearch(arr, 4) << endl;

    return 0;
}
