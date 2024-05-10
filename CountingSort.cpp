/*
Author: MINGJUN LU
Course: CSCI-335
Instructor: Justin Tojeira
Assignment: Project 3
The Counting Sort
cpp file
This code effectively utilizes the counting sort mechanism adapted to find specific quantiles
 and extremes in a dataset without fully sorting the original data, making it efficient especially
  for large datasets with limited unique elements. The use of a frequency map (hash map) allows for
   quick counting and the sorted vector of these counts facilitates rapid quantile computation.
*/
#include "CountingSort.hpp"
// Function to compare two pairs based on their first element
bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.first < b.first;// Returns true if the first pair's first element is less than the second's
}
// Function to perform counting sort and calculate statistical measures
void countingSort (const std::string & header, std::vector<int> data){
   std::unordered_map<int, int> countMap;
    // Count frequency of each element in the data
   for(auto i=data.begin();i!=data.end();++i){
    countMap[*i]++;
   }
   // Convert the frequency map to a sorted vector of pairs
    std::vector<std::pair<int, int>> sortedDatavector;
    for(auto i=countMap.begin();i!=countMap.end();++i){
        sortedDatavector.emplace_back(i->first,i->second);
    }
    // Sort the vector of pairs by the element value
    std::sort(sortedDatavector.begin(),sortedDatavector.end(),comparePairs);
    int total=0;
    int size=data.size();
    // Define target indices for minimum, 25%, 50%, 75% and maximum
    std::vector<int> targets = {1, size/4, size/2, 3*size/4, size};
    int targetsize=targets.size();
    std::vector<int> result(5);
    int idx=0;
     // Calculate the results based on the sorted data and frequency
    for(auto i=sortedDatavector.begin();i!=sortedDatavector.end();++i){
        while(idx<targets.size()&&total+i->second>=targets[idx]){
            result[idx]=i->first;
            idx++;
        }
        total+=i->second;
        if (idx >= targetsize) {
            break;
        }
    }
    // Output the statistical results
    std::cout << header << std::endl;
    std::cout << "Min: " << result[0] << std::endl;
    std::cout << "P25: " << result[1] << std::endl;
    std::cout << "P50: " << result[2] << std::endl;
    std::cout << "P75: " << result[3] << std::endl;
    std::cout << "Max: " << result[4] << std::endl;
    std::cout << "Unique: " << countMap.size() << std::endl;
}