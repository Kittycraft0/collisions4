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
    
    // what
    std::random_device rd;
    // performing black magic
    std::mt19937 gen(rd());
    // Initialize the n-th position component randomizer thing>
    std::vector<std::uniform_int_distribution<>> posDistD;
    // set the initial x- and y- position randomizers
    std::uniform_int_distribution<> posDistX(
        -(int)(data->settings->windowWidth)/2+data->settings->objectSpawnMargin,
        (int)(data->settings->windowWidth)/2-data->settings->objectSpawnMargin
    );
    std::uniform_int_distribution<> posDistY(
        -(int)(data->settings->windowHeight)/2+data->settings->objectSpawnMargin,
        (int)(data->settings->windowHeight)/2-data->settings->objectSpawnMargin
    );
    // push dimensions
    posDistD.push_back(posDistX);
    posDistD.push_back(posDistY);
    // push other dimensions
    for(int j=1;j<d;j++){
        // uses width because why not
        std::uniform_int_distribution<> posDistN(
            -(int)(data->settings->windowWidth)/2,
            (int)(data->settings->windowWidth)/2
        );
        posDistD.push_back(posDistN);
    }

    // set the velocity randomizer
    std::uniform_real_distribution<> velDist(-100.f, 100.f);
    
    // 0 as a placeholder
    int modelID=0;

    // mass
    m=1;
    
    // rotational mass 5/11/2023
    i=1;
    
    for(int j=0;j<d;j++){
        std::cout<<j;
        p.push_back(posDistD[j](gen));
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

// 6/6/2023 update object properties
void ObjectNd::update(double deltaTime){
    // For linear values
    for(int j=0;j<this->linImp.size();j++){
        // Change the linear velocity by the linear impulse
        this->v[j]+=this->linImp[j]/this->m*deltaTime;
        // Set the linear impulse to zero
        this->linImp[j]=0;
        // Change the linear position by the linear velocity
        this->p[j]+=this->v[j]*deltaTime;
        // Set the linear momentum to the linear velocity times the mass
        this->linMom[j]=this->v[j]*this->m;
    }
    // For rotational values
    for(int j=0;j<this->rotImp.size();j++){
        // Change the angular velocity by the angular impulse
        this->av[j]+=this->rotImp[j]/this->i*deltaTime;
        // Set the angular impulse to zero
        this->rotImp[j]=0;
        // Change the angular position (the angle) by the angular velocity
        this->a[j]+=this->av[j]*deltaTime;
        // Set the rotaional momentum to the rotational 
        // velocity times the rotational mass
        this->rotMom[j]=this->av[j]*this->i;
    }

    // 6/7/2023 Set the circular radius in base pixels
    this->radius=10;
}