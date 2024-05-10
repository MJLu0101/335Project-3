/*
Author: MINGJUN LU
Course: CSCI-335
Instructor: Justin Tojeira
Assignment: Project 3
The QuickSelect1
hpp file
this application of the Quickselect algorithm in C++, designed to efficiently find key statistical metrics 
such as the minimum, 25th percentile (P25), median (P50), 75th percentile (P75), and maximum from an unsorted
 array of integers without fully sorting the data
*/
#ifndef QUICK_SELECT1_HPP
#define QUICK_SELECT1_HPP
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "InsertionSort.hpp"
#include<chrono>
/*Purpose: Utilizes the Quickselect function to find and display the minimum, 25th, 50th, and 75th percentiles, and the maximum of the array.
Details:
Finds the median by targeting the middle index.
Finds the quartiles by targeting appropriate indices calculated as fractions of the array’s length.
Directly finds and displays the minimum and maximum using std::min_element and std::max_element.*/
void quickSelect1 (const std::string & header, std::vector<int> data);
//help function 
/*Partition Function:
Purpose: Rearranges elements in the array so that all elements less than a chosen pivot come before it and all greater elements come after it.
Mechanism: It swaps a pivot element (initially chosen via an index) with the last element, then moves all elements less than the pivot to its left, finally placing the pivot in its correct sorted position.
Output: Returns the index of the pivot, now placed in its correct position.*/
int Partition(std::vector<int>& data, int low, int high,int pi);
/*Purpose: Finds the k-th smallest element in the array by using the partitioning logic.
Process:
If the range of the search is small, it switches to insertion sort for efficiency.
Recursively selects either the left or right segment of the array based on the position of the pivot relative to the k-th position needed.
Efficiency: This method is typically more efficient than full sorting, especially for finding elements at specific positions, due to its average O(n) complexity.*/
int quickSelect(std::vector<int>& data,int low, int high, int k);
#endif