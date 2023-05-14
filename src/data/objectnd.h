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
    // mass is better than just m... -5/14/2023 2 months since pi day i guess idk but why isn't there an e day!...
    float mass;
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
};

#endif