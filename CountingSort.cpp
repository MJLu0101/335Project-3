#include "CountingSort.hpp"
bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.first < b.first;
}
void countingSort (const std::string & header, std::vector<int> data){
   std::unordered_map<int, int> countMap;
   for(auto i=data.begin();i!=data.end();++i){
    countMap[*i]++;
   }
   // Convert map to vector of pairs
    std::vector<std::pair<int, int>> sortedDatavector;
    for(auto i=countMap.begin();i!=countMap.end();++i){
        sortedDatavector.emplace_back(i->first,i->second);
    }

    std::sort(sortedDatavector.begin(),sortedDatavector.end(),comparePairs);
    int total=0;
    int size=data.size();
    
    std::vector<int> targets = {1, size/4, size/2, 3*size/4, size};
    int targetsize=targets.size();
    std::vector<int> result(5);
    int idx=0;
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
    std::cout << header << std::endl;
    std::cout << "Min: " << result[0] << std::endl;
    std::cout << "P25: " << result[1] << std::endl;
    std::cout << "P50: " << result[2] << std::endl;
    std::cout << "P75: " << result[3] << std::endl;
    std::cout << "Max: " << result[4] << std::endl;
    std::cout << "Unique: " << countMap.size() << std::endl;
}