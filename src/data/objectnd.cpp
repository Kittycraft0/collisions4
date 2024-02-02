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
    // set the velocity randomizer
    std::uniform_real_distribution<> velDist(data->settings->velMin,data->settings->velMax);
    // the mass randomizer
    std::uniform_real_distribution<> massRandomizer(data->settings->massMin,data->settings->massMax);
    // set the radius randomizer
    std::uniform_real_distribution<> radiusRandomizer(5.0f, 10.0f);
    
    // what
    //std::random_device rd;
    // performing black magic
    //std::mt19937 gen(rd());
    // 6/23/2023 get it from data
    std::mt19937* gen=data->gen;

    // Initialize the n-th position component randomizer thing>
    std::vector<std::uniform_int_distribution<>> posDistD;
    // set the initial x- and y- position randomizers
    //std::uniform_int_distribution<> posDistX(
    //    -(int)(data->settings->windowWidth)/2+data->settings->objectSpawnMargin,
    //    (int)(data->settings->windowWidth)/2-data->settings->objectSpawnMargin
    //);
    //std::uniform_int_distribution<> posDistY(
    //    -(int)(data->settings->windowHeight)/2+data->settings->objectSpawnMargin,
    //    (int)(data->settings->windowHeight)/2-data->settings->objectSpawnMargin
    //);
    // push dimensions
    //posDistD.push_back(posDistX);
    //posDistD.push_back(posDistY);
    // push other dimensions
    for(int j=0;j<d;j++){
        // uses width because why not
        std::uniform_int_distribution<> posDistN(
            //-(int)(data->settings->windowWidth)/2,
            //(int)(data->settings->windowWidth)/2
            data->settings->border1[j]/2,
            data->settings->border2[j]/2
        );
        posDistD.push_back(posDistN);
    }

    
    // 0 as a placeholder
    int modelID=0;

    // Linear mass
    // for some reason two objects of equal mass freak out on collision
    m=massRandomizer(*gen);
    // 10/11/2023 test AAAAAAA.
    //int thepow=data->objects.size();
    //m=pow(10,thepow);
    //m=5.76185f;
    //std::cout<<" "<<m;
    //m=2;

    // 6/8/2023 moved to here...
    // 6/7/2023 Set the circular radius in base pixels
    //this->radius=10;
    this->radius=radiusRandomizer(*gen);
    
    // Rotational mass 5/11/2023
    // 6/8/2023 changed to maybe a more accurate value
    // 6/8/2023 or not - there is so much math behind the moment of inertia!!!
    // 10/26/2023 
    // https://math.stackexchange.com/questions/565333/moment-of-inertia-of-a-n-dimensional-sphere
    // mr^2(d-1)/(d+2)d
    i=m*radius*radius*(d-1)/(d+2);

    for(int j=0;j<d;j++){
        //std::cout<<j;
        // position
        p.push_back(posDistD[j](*gen));
        // velocity
        v.push_back(velDist(*gen));
        scale.push_back(1);
        linDisp.push_back(0);
        linMom.push_back(0);//v[i]*m);
        linImp.push_back(0);
        linForce.push_back(0);
    }
    // uses number of angular dimensions formula supplied by ChatGPT
    for(int j=0;j<d*(d-1)/2;j++){
        //rotational angle?
        a.push_back(0);
        //angular velocity?
        av.push_back(0);
        rotDisp.push_back(0);
        rotMom.push_back(0);
        rotImp.push_back(0);
        rotForce.push_back(0);
    }
}

// 6/6/2023 update object properties
void ObjectNd::update(double deltaTime){
    // For linear values
    for(int j=0;j<this->linImp.size();j++){
        // Change the linear velocity by the linear impulse
        // IMPULSE SHOULD NOT BE MULTIPLIED BY DELTATIME
        //std::cout<<this->m<<" ";
        this->v[j]+=this->linImp[j]/this->m;
        // Change the linear position by the linear velocity
        this->p[j]+=this->v[j]*deltaTime
            // 11/01/2023 plus the acceleration part of kinematics
            +0.5*this->linForce[j]/this->m*deltaTime*deltaTime;

        // 11/01/2023 Change the velocity by force divided by the mass times the deltaTime 
        this->v[j]+=this->linForce[j]/this->m*deltaTime;
        
        //std::cout<<this->linForce[j]<<" ";
        //std::cout<<0.5*this->linForce[j]/this->m*deltaTime*deltaTime<<" ";
        
        // Set the accumulated linear force equal to zero
        this->linForce[j]=0;
        // Set the linear momentum to the linear velocity times the mass
        // never used
        //this->linMom[j]=this->v[j]*this->m;
        // Set the linear impulse to zero
        this->linImp[j]=0;

        // 6/23/2023 Change the position by the displacement
        this->p[j]+=this->linDisp[j];
        // Set the displacement to zero
        this->linDisp[j]=0;
    }
    // For rotational values
    for(int j=0;j<this->rotImp.size();j++){
        // Change the angular velocity by the angular impulse
        this->av[j]+=this->rotImp[j]/this->i;
        // Change the angular position (the angle) by the angular velocity
        this->a[j]+=this->av[j]*deltaTime
            // plus the acceleration part of rotational kinematics
            +0.5*this->rotForce[j]/this->i*deltaTime*deltaTime;

        // 11/01/2023 Change the velocity by force divided by the mass times the deltaTime 
        this->v[j]+=this->linForce[j]/this->m*deltaTime;

        // Set the accumulated rotational force (or torque) equal to zero
        this->rotForce[j]=0;
        // Set the rotaional momentum to the rotational 
        // velocity times the rotational mass
        // never used
        //this->rotMom[j]=this->av[j]*this->i;

        // Set the angular impulse to zero
        this->rotImp[j]=0;


        // 6/23/2023 Change the angle by the angular displacement
        this->p[j]+=this->rotDisp[j];
        // Set the angular displacement to zero
        this->rotDisp[j]=0;
    }

    // 2/2/2024 cringe extra properties
    this->lastKineticEnergy=-1;
    this->lastPotentialEnergy=-1;
}