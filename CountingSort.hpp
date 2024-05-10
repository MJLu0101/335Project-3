/*
Author: MINGJUN LU
Course: CSCI-335
Instructor: Justin Tojeira
Assignment: Project 3
The Counting Sort
hpp file
This code effectively utilizes the counting sort mechanism adapted to find specific quantiles
 and extremes in a dataset without fully sorting the original data, making it efficient especially
  for large datasets with limited unique elements. The use of a frequency map (hash map) allows for
   quick counting and the sorted vector of these counts facilitates rapid quantile computation.
*/
#ifndef COUNTING_SORT_HPP
#define COUNTING_SORT_HPP
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include<chrono>
void countingSort (const std::string & header, std::vector<int> data);
/*Purpose: This helper function is used by std::sort to order pairs based on the element value (first part of the pair).
countingSort:
Purpose: Sorts the given data using a counting sort method and computes statistical values such as min, max, and quartiles.
Process:
Counts each element's occurrence in the data vector using an unordered map.
Transfers these counts into a vector of pairs (element and its frequency).
Sorts this vector based on the element values.
Computes the minimum, 25th percentile, median, 75th percentile, and maximum by examining the sorted elements and their cumulative frequencies.
Output:
Prints the results along with a header and the count of unique elements found in data.*/
bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b);
#endif