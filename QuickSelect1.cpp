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
    if(low<high){
        int p = MyPartition(data,low,high);
        if(k == p){
            return data[p];
        }
        else if(k<p){
            return kthSmallest(data, low, p-1,k);
        }
        else if(k>p){
            return kthSmallest(data, p+1, high,k);
        }
    }
    return INT_MAX;
}

void quickSelect1 (const std::string & header, std::vector<int>& data){
    std::cout<<header<<std::endl;

    int size=data.size();
    int median=kthSmallest(data,0,size-1,size/2);
    int P25=kthSmallest(data,0,size/2-1,size/4);
    int P75= kthSmallest(data,size/2+1,size-1,3*size/4);
 
    std::cout << "Min: " << *std::min_element(data.begin(), data.begin() + size / 4) << std::endl;
    std::cout << "P25: " << P25 << std::endl;
    std::cout << "P50: " << median << std::endl;
    std::cout << "P75: " << P75 << std::endl;
    std::cout << "Max: " << *std::max_element(data.begin() + 3 * size / 4, data.end()) << std::endl;

}