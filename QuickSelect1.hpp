#ifndef QUICK_SELECT1_HPP
#define QUICK_SELECT1_HPP
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
void quickSelect1 (const std::string & header, std::vector<int>& data);
//help function 
int MyPartition(std::vector<int>& data, int low, int high) ;
int kthSmallest(std::vector<int>& data,int low, int high, int k);
#endif