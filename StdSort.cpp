#include "StdSort.hpp"
void stdSort(const std::string &header, std::vector<int>data){
    std::cout<<header<<std::endl;
    std::sort(data.begin(),data.end());
    int size=data.size();

    std::cout << "Min: " << data.front() << std::endl;
    std::cout << "P25: " << data[size/4-1] << std::endl;
    std::cout << "P50: " << data[size/2-1] << std::endl;
    std::cout << "P75: " << data[size*3/4-1] << std::endl;
    std::cout << "Max: " << data.back()<< std::endl;
}