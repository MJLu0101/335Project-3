#include "QuickSelect2.hpp"

int MyPartition(std::vector<int>& data, int low, int high, int pivotIndex)//low is beging  ,high is last 
{      
    std::swap(data[pivotIndex],data[high]);
    int pivot=data[high];
    int i=low;
    for (int j = low; j <= high - 1; j++) { 
        if (data[j] <= pivot) { 
            std::swap(data[i],data[j]);
            i++; 
        } 
    } 
    std::swap(data[i],data[high]);
    return i;
} 
void quickSelectRecursive(std::vector<int>& data,int low, int high, std::vector<int> keys){
    if(low<high){
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
        // Recurse into the relevant parts of the array
        if(!leftKeys.empty()){
            quickSelectRecursive(data,low,pivotindex-1,leftKeys);
        }
        if(!rightKeys.empty()){
            quickSelectRecursive(data,pivotindex+1,high,rightKeys);
        }
    }
    else{
        return;
    }
}
void quickSelect2(const std::string& header, std::vector<int> data) {
    int size = data.size()-1;
    std::vector<int> keys = {0, size/4, size/2, 3*size/4, size};
    quickSelectRecursive(data, 0, size, keys);

    std::cout << header << std::endl;
    std::cout << "Min: " << data[0] << std::endl;
    std::cout << "P25: " << data[size/4] << std::endl;
    std::cout << "P50: " << data[size/2] << std::endl;
    std::cout << "P75: " << data[3*size/4] << std::endl;
    std::cout << "Max: " << data[size] << std::endl;
}