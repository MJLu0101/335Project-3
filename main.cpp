#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "StdSort.hpp"
#include "QuickSelect1.hpp"
#include "QuickSelect2.hpp"
#include "CountingSort.hpp"
int main(){
    std::string filename;
    std::cout<<"enter file name: "<<std::endl;
    std::cin>>filename;
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file " << filename << std::endl;
        return -1;
    }
    
    std::string header, dataLine;
    // Read header
    std::getline(inputFile, header);
    // Read data line
    std::getline(inputFile, dataLine);

    // Parse data line
    std::vector<int> data;
    int num;
    std::istringstream iss(dataLine);
    while (iss >> num) {
        data.push_back(num);
    }
    stdSort(header,data);
    //quickSelect1(header,data);
    //quickSelect2(header,data);
    countingSort(header,data);
}