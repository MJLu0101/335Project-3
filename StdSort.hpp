/*
Author: MINGJUN LU
Course: CSCI-335
Instructor: Justin Tojeira
Assignment: Project 3
The StdSort
hpp file
This code by sort and find he minimum, 25th percentile, median (50th percentile), 75th percentile, and maximum values.*/
#ifndef STDSORT_HPP
#define STDSORT_HPP
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include<chrono>
/*The stdSort function sorts a given vector of integers in ascending order and
 then prints predefined statistical measures: the minimum, 25th percentile, median
  (50th percentile), 75th percentile, and maximum values.*/
void stdSort(const std::string &header, std::vector<int>data);
#endif // STDSORT_HPP