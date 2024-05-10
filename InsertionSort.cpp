/*
Author: MINGJUN LU
Course: CSCI-335
Instructor: Justin Tojeira
Assignment: Project 3
The InsertionSort
cpp file
this application of Insertion Sort meth
*/
#include "InsertionSort.hpp"
void insertionSort(std::vector<int>& data, int low, int high) {
    // Start from the second element of the range
    for (int i = low + 1; i <= high; i++) {
        int key = data[i];// The element to be inserted
        int j = i - 1;// Start comparing with the element just before i
        // Move elements of data[low..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= low && data[j] > key) {
            data[j + 1] = data[j];// Shift element to the right
            j--;// Move to the next element on the left 
        }
        data[j + 1] = key;// Place the key at after the last shifted element
    }
}