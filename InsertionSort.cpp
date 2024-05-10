#include "InsertionSort.hpp"
void insertionSort(std::vector<int>& data, int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = data[i];
        int j = i - 1;
        while (j >= low && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}