#ifndef QUICK_SELECT2_HPP
#define QUICK_SELECT2_HPP

#include <vector>
#include <string>
#include <iostream>

void quickSelect2(const std::string& header, std::vector<int> data);
//help function 
int MyPartition(std::vector<int>& data, int low, int high,int pivotIndex);
void quickSelectRecursive(std::vector<int>& data,int low, int high, std::vector<int> keys);
#endif