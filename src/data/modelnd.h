// modelnd.h
#ifndef MODELND_H
#define MODELND_H
// the model of N dimensions
#include <vector>
#include <iostream>

// TODO: include something with like constructors and definitions
// and maybe even getting from files and also including the number of dimensions
// that the model is
class ModelNd{
public:
    std::vector<std::vector<float>> points;
    std::vector<std::vector<int>> faces;
    std::vector<int> colors;
    
    // 6/1/2023
    // constructor
    ModelNd(std::string modelPath);
};

#endif