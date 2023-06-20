// modeldata.cpp
#include "modeldata.h"
// 5/8/2923
// define the implementation or whatever of ModelData
#include "modelnd.h"

// 5/8/2023 the ModelData class is only defined one - as such, 
// it should be directly with data.
/*class ModelData{public:
    std::vector<std::string> modelNames;
    std::vector<ModelNd*> models;
};*/

//check initData.cpp for method implementation? -5/30/2023
#include <iostream>
ModelData::ModelData(std::string modelPath){
    std::cout<<"Passed model path "<<modelPath<<"\n";
}
ModelData::ModelData(){
    std::cout<<"Passed with nothing";
}