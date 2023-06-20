// modeldata.h
#ifndef MODELDATA_H
#define MODELDATA_H
// 5/8/2023 defining modeldata.h the header file for the model organization thing
// also maybe TODO: include methods for getting models by name
#include "modelnd.h"
#include <vector>
#include <string>
class ModelData{
public:
    std::vector<std::string> modelNames;
    std::vector<ModelNd*> models;
    
    // constructor -6/2/2023
    ModelData(std::string modelPath);
    // 6/5/2023
    ModelData();
};

#endif