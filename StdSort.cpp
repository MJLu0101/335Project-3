/*
Author: MINGJUN LU
Course: CSCI-335
Instructor: Justin Tojeira
Assignment: Project 3
The StdSort
cpp file
This code by sort and find he minimum, 25th percentile, median (50th percentile), 75th percentile, and maximum values.*/
#include "StdSort.hpp"
/*The stdSort function sorts a given vector of integers in ascending order and then prints predefined statistical
 measures: the minimum, 25th percentile, median (50th percentile), 75th percentile, and maximum values.*/
void stdSort(const std::string &header, std::vector<int>data){
    //time:beging:
    auto start=std::chrono::high_resolution_clock::now();
    // Print the header provided as a description of the output
    std::cout<<header<<std::endl;
    // Sort the vector of integers using std::sort from the C++ Standard Library
    std::sort(data.begin(),data.end());
    int size=data.size();
    
    std::cout << "Min: " << data.front() << std::endl;// Output minimum value, located at the front of the sorted vector
    std::cout << "P25: " << data[size/4-1] << std::endl;// Calculate and output the 25th percentile
    std::cout << "P50: " << data[size/2-1] << std::endl; // Calculate and output the median (50th percentile)
    std::cout << "P75: " << data[size*3/4-1] << std::endl;// Calculate and output the 75th percentile
    std::cout << "Max: " << data.back()<< std::endl; // Output the maximum value, located at the back of the sorted vector
    //time end:
    auto end=std::chrono::high_resolution_clock::now();
     std::chrono::duration<double,std::micro>elapsed=end-start;
     std::cout<< "Execution time: "<<elapsed.count()<<" microseconds\n";
}