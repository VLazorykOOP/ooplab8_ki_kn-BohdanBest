#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// оголошення шаблонної функції partition, яка буде використовуватись в quickSort
template <typename T>
int partition(vector<T>& arr, int low, int high) {
    T pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// оголошення шаблонної функції quickSort
template <typename T>
void quickSort(vector<T>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// оголошення спеціалізованої функції partition для масиву char*
template <>
int partition<char*>(vector<char*>& arr, int low, int high) {
    char* pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j], pivot) <= 0) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int main() {
    vector<int> int_arr = { 10, 7, 8, 9, 1, 5 };
    vector<char*> str_arr = { (char*)"apple", (char*)"orange", (char*)"banana", (char*)"grape", (char*)"pear" };

    quickSort(int_arr, 0, int_arr.size() - 1);
    quickSort(str_arr, 0, str_arr.size() - 1);

    cout << "Sorted integer array: ";
    for (int i : int_arr) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Sorted string array: ";
    for (char* s : str_arr) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}