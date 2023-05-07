#include <iostream>
#include <cstring>
using namespace std;
template<typename T>
class SequentialSearch {
public:
    SequentialSearch(T array[], int size, T key) : m_array(array), m_size(size), m_key(key) {}

    int search() {
        int index = -1; // індекс останнього знайденого елемента, рівного ключу
        for (int i = 0; i < m_size; i++) {
            if (m_array[i] == m_key) {
                index = i;
            }
        }
        return index;
    }

private:
    T* m_array;
    int m_size;
    T m_key;
};

// специфікація функції-шаблон для типу char*
template<>
class SequentialSearch<char*> {
public:
    SequentialSearch(char* array[], int size, char* key) : m_array(array), m_size(size), m_key(key) {}

    int search() {
        int index = -1; // індекс останнього знайденого елемента, рівного ключу
        for (int i = 0; i < m_size; i++) {
            if (strcmp(m_array[i], m_key) == 0) {
                index = i;
            }
        }
        return index;
    }

private:
    char** m_array;
    int m_size;
    char* m_key;
};

int main() {
    int int_array[] = { 1, 2, 3, 4, 5, 6, 1, 4, 3, 2 };
    SequentialSearch<int> int_search(int_array, 5, 5);

    cout << "The array is: \n";
    for (int i : int_array) {
        cout << int_array[i] << " ";
    }

    cout << "\n\n";

    cout << "Index of last occurrence of key in int_array: " << int_search.search() << endl;
    cout << "------------\n";

    char* str_array[] = { (char*)"apple", (char*)"banana", (char*)"orange", (char*)"grape", (char*)"kiwi" };
    SequentialSearch<char*> str_search(str_array, 5, (char*)"orange");

    cout << "The array of words is:\n";
    for (int i = 0; i < sizeof(str_array) / sizeof(str_array[0]); i++) {
        cout << "[" << i << "] " << str_array[i] << '\n';
    }
    cout << "------------\n";

    cout << "Index of last occurrence of key in str_array: " << str_search.search() << endl;

    return 0;
}
