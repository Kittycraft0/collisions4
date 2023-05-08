// objectNd.cpp
#include "objectnd.h"
// 5/8/2023 definition of objectNd.cpp
#include <vector>

class ObjectNd{
public:
    int modelID;
    std::vector<float> p;
    std::vector<float> v;
    float m;
    std::vector<float> scale;
};