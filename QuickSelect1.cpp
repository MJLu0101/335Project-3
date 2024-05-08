#include "QuickSelect1.hpp"

int Partition(std::vector<int>& data, int low, int high, int pivotIndex)//low is beging  ,high is last 
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
int kthSmallest(std::vector<int>& data,int low, int high, int k){
    if (low == high) {
        return data[low];
    }
    int pivotIndex = low + (high - low) / 2;  // Simple choice, can be randomized
    int pi = Partition(data, low, high, pivotIndex);
    if (k== pi) {
        return data[pi];
    } 
    if (k < pi) {
        return kthSmallest(data, low, pi-1, k);
    } 
    else {
        return kthSmallest(data, pi+1, high, k);
    }
    return data[pi];
}

void quickSelect1 (const std::string & header, std::vector<int>& data){
    std::cout<<header<<std::endl;

    int size=data.size();
    int median=kthSmallest(data,0,size-1,(size/2)-1);
    //std::cout<<"p25:"<<std::endl;
    int P25= kthSmallest(data,0,size/2,(size/4)-1);
    int P75= kthSmallest(data,size/2,size-1,(3*size/4)-1);
 
    std::cout << "Min: " << *std::min_element(data.begin(), data.end()) << std::endl;
    std::cout << "P25: " << P25 << std::endl;
    std::cout << "P50: " << median << std::endl;
    std::cout << "P75: " << P75 << std::endl;
    std::cout << "Max: " << *std::max_element(data.begin(), data.end()) << std::endl;
}