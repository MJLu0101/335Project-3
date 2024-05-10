/*
Author: MINGJUN LU
Course: CSCI-335
Instructor: Justin Tojeira
Assignment: Project 3
The QuickSelect1
cpp file
this application of the Quickselect algorithm in C++, designed to efficiently find key statistical metrics 
such as the minimum, 25th percentile (P25), median (P50), 75th percentile (P75), and maximum from an unsorted
 array of integers without fully sorting the data
*/
#include "QuickSelect1.hpp"
/*Partition Function:
Purpose: Rearranges elements in the array so that all elements less than a chosen pivot come before it and all greater elements come after it.
Mechanism: It swaps a pivot element (initially chosen via an index) with the last element, then moves all elements less than the pivot to its left, finally placing the pivot in its correct sorted position.
Output: Returns the index of the pivot, now placed in its correct position.*/
int Partition(std::vector<int>& data, int low, int high, int pi)//low is beging  ,high is last 
{      
    // Swap the pivot element with the last element
    std::swap(data[pi],data[high]);
    int pivot=data[high];   // Pivot value
    int i=low;// Index for elements is first element
    // Rearrange elements around the pivot
    for (int j = low; j <= high - 1; j++) { 
        if (data[j] <= pivot) { 
            std::swap(data[i],data[j]);
            i++; 
        } 
    } 
    // Place the pivot in its correct position
    std::swap(data[i],data[high]);
    return i;// Return the position of the pivot
} 
/*Purpose: Finds the k-th smallest element in the array by using the partitioning logic.
Process:
If the range of the search is small, it switches to insertion sort for efficiency.
Recursively selects either the left or right segment of the array based on the position of the pivot relative to the k-th position needed.
Efficiency: This method is typically more efficient than full sorting, especially for finding elements at specific positions, due to its average O(n) complexity.*/
int quickSelect(std::vector<int>& data,int low, int high, int k){
    if (low == high) {
        return data[low];// Base case: one element
    }
    if(high-low>20){
        int pivotIndex = low + (high - low) / 2;   // Use the middle element as a simple pivot
        int pi = Partition(data, low, high, pivotIndex);
        if (k== pi) { // Check if the pivot position is the one we're looking for
            return data[pi];
        } 
        if (k < pi) {// Recurse on the left subvector
            return quickSelect(data, low, pi-1, k);
        } 
        else {// Recurse on the right subvector
            return quickSelect(data, pi+1, high, k);
        }
    }
    else{// If the vector size is small 20, use insertion sort and directly access the k-th element
        insertionSort(data,low,high);
        return data[low+k];
    }
}
/*Purpose: Utilizes the Quickselect function to find and display the minimum, 25th, 50th, and 75th percentiles, and the maximum of the array.
Details:
Finds the median by targeting the middle index.
Finds the quartiles by targeting appropriate indices calculated as fractions of the array’s length.
Directly finds and displays the minimum and maximum using std::min_element and std::max_element.*/
void quickSelect1 (const std::string & header, std::vector<int> data){
    std::cout<<header<<std::endl;// Output header

    int size=data.size();
    int median=quickSelect(data,0,size-1,(size/2)-1);// Find the median
    //std::cout<<"p25:"<<std::endl;
    int P25= quickSelect(data,0,size/2,(size/4)-1);// Find the 25th percentile
    int P75= quickSelect(data,0,size-1,(3*size/4)-1);// Find the 75th percentile
    // Display the results
    std::cout << "Min: " << *std::min_element(data.begin(), data.end()) << std::endl;
    std::cout << "P25: " << P25 << std::endl;
    std::cout << "P50: " << median << std::endl;
    std::cout << "P75: " << P75 << std::endl;
    std::cout << "Max: " << *std::max_element(data.begin(), data.end()) << std::endl;
}