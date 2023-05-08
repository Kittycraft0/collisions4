// 5/8/2023
// defining an object of n dimensions...
// ooh this can probably be used like everywhere else i make things now
// tungsten
#ifndef OBJECTND_H
#define OBJECTND_H

#include <vector>

class ObjectNd{
public:
    int modelID;
    std::vector<float> p;
    std::vector<float> v;
    float m;
    std::vector<float> scale;
};

#endif