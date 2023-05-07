#include <iostream>
using namespace std;
template<typename T>
class Array {
private:
    T* arr;
    int size;
public:
    Array(int sz) {
        arr = new T[sz];
        size = sz;
    }
    Array(const Array& other) {
        size = other.size;
        arr = new T[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }
    ~Array() {
        delete[] arr;
    }
    // перевантажені оператори
    T& operator[](int index) {
        if (index < 0 || index >= size) {
            cerr << "Index out of range" << endl;
            exit(1);
        }
        return arr[index];
    }
    Array<T>& operator=(const Array<T>& other) {
        if (this == &other) {
            return *this;
        }
        delete[] arr;
        size = other.size;
        arr = new T[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
        return *this;
    }
    Array<T> operator+(const Array<T>& other) const {
        if (size != other.size) {
            cerr << "Arrays must have the same size" << endl;
            exit(1);
        }
        Array<T> result(size);
        for (int i = 0; i < size; i++) {
            result.arr[i] = arr[i] + other.arr[i];
        }
        return result;
    }
    Array<T>& operator+=(const Array<T>& other) {
        if (size != other.size) {
            cerr << "Arrays must have the same size" << endl;
            exit(1);
        }
        for (int i = 0; i < size; i++) {
            arr[i] += other.arr[i];
        }
        return *this;
    }
    Array<T> operator-(const Array<T>& other) const {
        if (size != other.size) {
            cerr << "Arrays must have the same size" << endl;
            exit(1);
        }
        Array<T> result(size);
        for (int i = 0; i < size; i++) {
            result.arr[i] = arr[i] - other.arr[i];
        }
        return result;
    }
    Array<T>& operator-=(const Array<T>& other) {
        if (size != other.size) {
            cerr << "Arrays must have the same size" << endl;
            exit(1);
        }
        for (int i = 0; i < size; i++) {
            arr[i] -= other.arr[i];
        }
        return *this;
    }
};

int main() {
    // створення масивів
    Array<int> a(3);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;

    Array<int> b(3);
    b[0] = 4;
    b[1] = 5;
    b[2] = 6;
    // додавання масивів та виведення результату
    Array<int> c = a + b;
    cout << "c[0] = " << c[0] << ", c[1] = " << c[1] << ", c[2] = " << c[2] << endl;
    // віднімання одного масиву від іншого та виведення результату
    c -= a;
    cout << "c[0] = " << c[0] << ", c[1] = " << c[1] << ", c[2] = " << c[2] << endl;
    // копіювання масиву та виведення результату
    Array<int> d = c;
    cout << "d[0] = " << d[0] << ", d[1] = " << d[1] << ", d[2] = " << d[2] << endl;

    return 0;
}