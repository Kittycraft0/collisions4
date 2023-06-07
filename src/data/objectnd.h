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
    std::vector<double> p;
    std::vector<double> v;
    // mass is better than just m... -5/14/2023 2 months since pi day i guess idk but why isn't there an e day!...
    double m;
    std::vector<double> scale;
    std::vector<double> linMom;
    std::vector<double> linImp;

    //rotational mass? -5/11/2023
    double i;
    //rotational angle?
    std::vector<double> a;
    //angular velocity?
    std::vector<double> av;
    std::vector<double> rotMom;
    std::vector<double> rotImp;
    double radius;

    // 6/1/2023
    // constructor
    // integer d for the number of dimensions
    // 6/6/2023 added pointer to data
    ObjectNd(int d,Data* data);

    // 6/6/2023 update velocity and position and reset impulse
    void update(double deltaTime);
};

#endif