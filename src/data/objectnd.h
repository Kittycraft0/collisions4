// 5/8/2023
// defining an object of n dimensions...
// ooh this can probably be used like everywhere else i make things now

#ifndef OBJECTND_H
#define OBJECTND_H
// tungsten tungstone heavy stone in swedish
#include <vector>

// 6/6/2023 - randomness
#include <random>

// what
#include "settings.h"
// Data class - NO INCLUDE STATEMENT FOR DATA, JUST ONLY THIS
class Data;


class ObjectNd{
public:
    int modelID;
    std::vector<float> p;
    std::vector<float> v;
    // mass is better than just m... -5/14/2023 2 months since pi day i guess idk but why isn't there an e day!...
    float m;
    std::vector<float> scale;
    std::vector<float> linMom;
    std::vector<float> linImp;

    //rotational mass? -5/11/2023
    float i;
    //rotational angle?
    std::vector<float> a;
    //angular velocity?
    std::vector<float> av;
    std::vector<float> rotMom;
    std::vector<float> rotImp;

    // 6/1/2023
    // constructor
    // integer d for the number of dimensions
    // 6/6/2023 added pointer to data
    ObjectNd(int d,Data* data);
};

#endif