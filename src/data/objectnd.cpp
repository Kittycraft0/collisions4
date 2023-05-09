// objectNd.cpp
#include "objectnd.h"
// 5/8/2023 definition of objectNd.cpp
#include <vector>

// 5/8/2023 the object should be a solid block of data
class ObjectNd{public:
    int modelID; // index of model in data.modelData.models
    //position
    std::vector<float> p;
    //velocity
    std::vector<float> v;
    //mass
    float m;
    //the scale, default of one in every dimension
    std::vector<float> scale;
};
/*
class ObjectNd{
public:
    int modelID;
    std::vector<float> p;
    std::vector<float> v;
    float m;
    std::vector<float> scale;
};*/