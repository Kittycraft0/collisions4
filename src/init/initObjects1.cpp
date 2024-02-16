// 2/15/2024
// initObjects1.cpp
#include "initobjects1.h"

// initialize the objects to specific posiitions?!
// random stuffs is a bit random and unpredictable and hard to test stuffs with idk

// 2/16/2024 default original initialization
void initObjects1(Data* data){
    std::cout<<"initialized objects 1";
    //initObjects(settings)
    //this->objects=0;
    // 5/11/2023
    for(int i=0;i<data->settings->numObjects;i++){
        //ObjectNd* obj=new ObjectNd(settings->d);
        // added this-> at 6/5/2023
        //this->objects.push_back(obj);
        data->objects.push_back(new ObjectNd(data->settings->d,data));
    }
}

// 2/16/2024
// doing something cool idk
// initialize two objects imperfectly orbiting each other
void initObjects2(Data* data){
    std::cout<<"initialized objects 1";
    //initObjects(settings)
    //this->objects=0;
    // 5/11/2023
    /*for(int i=0;i<data->settings->numObjects;i++){
        //ObjectNd* obj=new ObjectNd(settings->d);
        // added this-> at 6/5/2023
        //this->objects.push_back(obj);
        data->objects.push_back(new ObjectNd(data->settings->d,data));
    }*/
    // 2/16/2024 - initialize an object by setting all of the properties manually
data->objects.push_back(new ObjectNd(
    // position
    {-50.0,50.0},
    // velocity
    {0.0,200.0},
    // angle
    {0.0},
    // angular velocity
    {0.0},
    // mass
    10.0,
    // rotational inertia
    2.0,
    // # of dimensions - be consistent maybe
    2,
    // radius for circles rendering and circular collisions
    10,
    // model id for future model rendering
    0,
    // scale for model stretching
    {0.0,0.0}
));
data->objects.push_back(new ObjectNd(
    // position
    {50.0,-50.0},
    // velocity
    {0.0,-200.0},
    // angle
    {0.0},
    // angular velocity
    {0.0},
    // mass
    11.0,
    // rotational inertia
    1.0,
    // # of dimensions - be consistent maybe
    2,
    // radius for circles rendering and circular collisions
    11.0,
    // model id for future model rendering
    0,
    // scale for model stretching
    {0.0,0.0}
));
    //found: energy is not conserved because of outwards drift during orbits
}