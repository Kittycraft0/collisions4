// objectNd.cpp
#include "objectnd.h"
// 5/8/2023 definition of objectNd.cpp
#include <vector>

// 5/8/2023 the object should be a solid block of data
/*class ObjectNd{public:
    int modelID; // index of model in data.modelData.models
    //position
    std::vector<float> p;
    //velocity
    std::vector<float> v;
    //mass
    float mass;
    // linear momentum
    std::vector<float> linMom;
    // linear impulse
    std::vector<float> linImp;
    
    //rotational mass? -5/11/2023
    // rotational inertia
    float i;
    //rotational angle?
    std::vector<float> a;
    //angular velocity?
    std::vector<float> av;
    // rotational momentum
    std::vector<float> rotMom;
    // rotational impulse -5/14/2023
    std::vector<float> rotImp;
    
    //the scale, default of one in every dimension
    std::vector<float> scale;
};*/
/*
class ObjectNd{
public:
    int modelID;
    std::vector<float> p;
    std::vector<float> v;
    float m;
    std::vector<float> scale;
};*/

// 6/1/2023
// constructore
ObjectNd::ObjectNd(int d,Data* data){
    // randomizers -6/6/2023
    // create 10 circles with random positions and velocities
    std::random_device rd;
    std::mt19937 gen(rd());
    //std::uniform_int_distribution<> posDistX(0, window.getSize().x);
    //std::uniform_int_distribution<> posDistY(0, window.getSize().y);
    //std::uniform_int_distribution<> posDistX(-data->settings->windowWidth/2,data->settings->windowWidth/2);
    //std::uniform_int_distribution<> posDistY(-data->settings->windowHeight/2,data->settings->windowHeight/2);
    //std::uniform_real_distribution<> velDist(-100.f, 100.f);
    

    // 0 i guess as a placeholder just like everything else...?
    int modelID=0;

    // mass is better than just m... -5/14/2023 2 months 
    // since pi day i guess idk but why isn't there an e day!...
    // 6/1/2023 yes but i think consistancy is better, and what would i write for i?
    // iMass? i don't want to get sued by apple!!! hahaahaha...
    m=1;
    
    //rotational mass? -5/11/2023
    i=1;
    
    for(int j=0;j<d;j++){
        p.push_back(0);
        v.push_back(0);
        scale.push_back(1);
        linMom.push_back(v[i]*m);
        linImp.push_back(0);

    }

    // what hapens here with the number of dimensions???
    // i found a formula! good.
    // using j instead of i because i is already taken
    for(int j=0;j<d*(d-1)/2;j++){
        //rotational angle?
        a.push_back(0);
        //angular velocity?
        av.push_back(0);
        rotMom.push_back(av[i]*i);
        rotImp.push_back(0);
    }
}