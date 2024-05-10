#ifndef COUNTING_SORT_HPP
#define COUNTING_SORT_HPP
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
void countingSort (const std::string & header, std::vector<int> data);
bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b);
#endif