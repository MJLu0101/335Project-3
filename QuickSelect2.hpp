/*
Author: MINGJUN LU
Course: CSCI-335
Instructor: Justin Tojeira
Assignment: Project 3
The QuickSelect2
hpp file
This code uses a targeted version of the Quickselect algorithm to efficiently locate and sort only those elements 
of the vector that correspond to specific statistical values, thereby avoiding the overhead of fully sorting the entire dataset.
  The recursive strategy divides the problem into smaller subsets centered around key indices (minimum, quartiles, maximum), which are processed individually. 
*/
#ifndef QUICK_SELECT2_HPP
#define QUICK_SELECT2_HPP

#include <vector>
#include <string>
#include <iostream>
#include "InsertionSort.hpp"
#include<chrono>
/*This is the main function that initializes the process of finding specific order statistics in the data vector.
 It is designed to demonstrate how Quickselect can be used to efficiently find not only the median but also other
 quartiles and extreme values without sorting the entire dataset.*/
void quickSelect2 (const std::string & header, std::vector<int> data);
//help function 
/*The MyPartition function reorganizes the elements of the vector around a pivot chosen based on the pivotIndex parameter.
 The goal is to place the pivot element in its correct position in a sorted vector,
 such that all elements to the left of the pivot are less than or equal to the pivot, and all elements to the right are greater.*/
int MyPartition(std::vector<int>& data, int low, int high,int pivotIndex);
/*This function applies the Quickselect algorithm recursively to the data vector, targeting specific indices (provided in keys) that
 need to be sorted to find order statistics like quartiles. It effectively reduces the sorting effort to just the necessary parts of
  the vector.
*/
void quickSelectRecursive(std::vector<int>& data,int low, int high, std::vector<int> keys);
#endif