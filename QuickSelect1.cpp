#include "QuickSelect1.hpp"

int MyPartition(std::vector<int>& data, int low, int high)//low is beging  ,high is last 
{ 
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
    if(low==high){
        return data[low];
    }
    if(low<high&&k>0){
        int p = MyPartition(data,low,high);
        int length = p - low + 1;
        if(k == length){
            return data[p];
        }
        else if(k<length){
            return kthSmallest(data, low, p-1,k);
        }
        else if(k>length){
            return kthSmallest(data, p+1, high, k- length);
        }
    }
    return INT_MAX;
}

void quickSelect1 (const std::string & header, std::vector<int>& data){
    std::cout<<header<<std::endl;

    int size=data.size();
    int median=kthSmallest(data,0,size-1,size/2);
    int P25=kthSmallest(data,0,size-1,size/4);
    int P75= kthSmallest(data,0,size-1,3*size/4);
 
    std::cout << "Min: " << *std::min_element(data.begin(), data.begin() + size / 4) << std::endl;
    std::cout << "P25: " << P25 << std::endl;
    std::cout << "P50: " << median << std::endl;
    std::cout << "P75: " << P75 << std::endl;
    std::cout << "Max: " << *std::max_element(data.begin(), data.end()) << std::endl;

}