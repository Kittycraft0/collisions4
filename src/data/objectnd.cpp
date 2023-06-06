// objectNd.cpp
#include "objectnd.h"
// 5/8/2023 definition of objectNd.cpp
#include <vector>

// 5/8/2023 the object should be a solid block of data
// 6/6/2023 GUESS NOT

#include <iostream>

// 6/6/2023 what the why is this REQUIRED IN HERE!?
// IS C++ ON SOMETHING
// Note: it can't be moved to the header file without breaking things.
// And yet the initWindow method worked...? WHY!??
#include "initdata.h"


// 6/1/2023
// constructore
ObjectNd::ObjectNd(int d,Data* data){
    // randomizers -6/6/2023
    // create 10 circles with random positions and velocities
    std::random_device rd;
    std::mt19937 gen(rd());
    //std::uniform_int_distribution<> posDistX(0, window.getSize().x);
    //std::uniform_int_distribution<> posDistY(0, window.getSize().y);
    //std::uniform_int_distribution<> posDistX(-(int)(data->settings->windowWidth)/2,(int)(data->settings->windowWidth)/2);
    //std::uniform_int_distribution<> posDistY(-(int)(data->settings->windowHeight)/2,(int)(data->settings->windowHeight)/2);
    //std::uniform_real_distribution<> velDist(-100.f, 100.f);
    //Data anotherData=*data; // <-- HERE CHATGPT RIGHT HERE
    // 6/6/2023 test
    //std::cout<<"\nWindow width: "<<typeid(data).name(); // the what
    //std::cout<<"\nWindow width: "<<data->settings->windowWidth;

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
    // uses number of angular dimensions formula supplied by ChatGPT
    for(int j=0;j<d*(d-1)/2;j++){
        //rotational angle?
        a.push_back(0);
        //angular velocity?
        av.push_back(0);
        rotMom.push_back(av[i]*i);
        rotImp.push_back(0);
    }
}