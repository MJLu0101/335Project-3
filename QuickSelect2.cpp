/*
Author: MINGJUN LU
Course: CSCI-335
Instructor: Justin Tojeira
Assignment: Project 3
The QuickSelect2
hpp file
This code uses a targeted version of the Quickselect algorithm to efficiently locate and sort only those elements 
of the array that correspond to specific statistical values, thereby avoiding the overhead of fully sorting the entire dataset.
 The recursive strategy divides the problem into smaller subsets centered around key indices (minimum, quartiles, maximum), which are processed individually. 
*/
#include "QuickSelect2.hpp"
/*The MyPartition function reorganizes the elements of the array around a pivot chosen based on the pivotIndex parameter.
 The goal is to place the pivot element in its correct position in a sorted array,
 such that all elements to the left of the pivot are less than or equal to the pivot, and all elements to the right are greater.*/
int MyPartition(std::vector<int>& data, int low, int high, int pivotIndex)//low is beging  ,high is last 
{      
    std::swap(data[pivotIndex],data[high]);// Swap the chosen pivot element with the last element
    int pivot=data[high];// The pivot value
    int i=low;// Index of the first element
    // Rearrange elements based on their comparison with the pivot
    for (int j = low; j <= high - 1; j++) { 
        if (data[j] <= pivot) { 
            std::swap(data[i],data[j]);
            i++; 
        } 
    } 
     // Place the pivot element at its correct position
    std::swap(data[i],data[high]);
    return i;// Return the final position of the pivot
} 
/*This function applies the Quickselect algorithm recursively to the data vector, targeting specific indices (provided in keys) that
 need to be sorted to find order statistics like quartiles. It effectively reduces the sorting effort to just the necessary parts of
  the vector.
*/
void quickSelectRecursive(std::vector<int>& data,int low, int high, std::vector<int> keys){
    if(low<high&&high-low>20){
        int middle=low+(high-low)/2; // Choosing the middle index as pivot
        int pivotindex=MyPartition(data,low,high,middle);
        // Determine which indices are to the left and right of the pivot
        std::vector<int> leftKeys;
        std::vector<int> rightKeys;
        for(auto i=keys.begin();i!=keys.end();++i){
            if(*i<pivotindex){
                leftKeys.push_back(*i);
            }
            else if(*i>pivotindex){
                rightKeys.push_back(*i);
            }
        }
         // Recursively sort left and right subarrays based on the needed keys
        if(!leftKeys.empty()){
            quickSelectRecursive(data,low,pivotindex-1,leftKeys);
        }
        if(!rightKeys.empty()){
            quickSelectRecursive(data,pivotindex+1,high,rightKeys);
        }
    }
    else{// Use insertion sort if vector size smaller 20
        insertionSort(data,low,high);
    }
}
/*This is the main function that initializes the process of finding specific order statistics in the data vector.
 It is designed to demonstrate how Quickselect can be used to efficiently find not only the median but also other
 quartiles and extreme values without sorting the entire dataset.*/
void quickSelect2 (const std::string & header, std::vector<int> data){
    //  //time:beging:
    // auto start=std::chrono::high_resolution_clock::now();

    int size = data.size()-1;
    std::vector<int> keys = {0, size/4, size/2, 3*size/4, size};// Indices for required statistics

    quickSelectRecursive(data, 0, size, keys); // Apply the quickSelectRecursive to find statistics
    // Print the result with the header and calculated statistics


    std::cout << header << std::endl;
    std::cout << "Min: " << data[0] << std::endl;
    std::cout << "P25: " << data[size/4] << std::endl;
    std::cout << "P50: " << data[size/2] << std::endl;
    std::cout << "P75: " << data[3*size/4] << std::endl;
    std::cout << "Max: " << data[size] << std::endl;
    // //time end:
    // auto end=std::chrono::high_resolution_clock::now();
    //  std::chrono::duration<double,std::micro>elapsed=end-start;
    //  std::cout<< "Execution time: "<<elapsed.count()<<" microseconds\n";
}