#include "collisionmath.h"
//collisionMath.cpp 5/8/2023
#include "../data/objectnd.h"


/*
    6/2/2023
    Some quick lessons to better understand the code:
    
    1.
    If you see a * between the data type and the variable name like so:
    float* number=3;
    Just read it as float numbers=3;
    Forget the star, as the star is making a pointer, and it functions
    sort of like as if it wasn't there.

    2.
    If you see a * right before the variable name in expressions,
    then it is dereferencing the pointer, 
    or reading the data at the memory address.
    For simplicity, just pretend it's not there. For example:
    float m1i=(*obj1).m;
    Read it as the following:
    float m1i=obj1.m;

    3.
    Some data types in the code here are objects.
    Objects typically have properties (of which in this case I set)
    such as position, velocity, mass, etc.
    You can read the following:
    obj1.m
    as getting the objects mass. In physics talk, it would be:
    m sub 1
    being the mass of the first object.

    4. read std::vector<float> as making a vector

    5. read vector[number] as getting the number'th component of the vector

    6. push_back() adds a new component to the vector (they start empty)
    7. .size() returns the number of components of the vector
*/

#include <iostream>

// 5/15/2023
// (the coefficient of) restitution should be between 0 and 1, 
// 0 is inelastic, 1 is elastic
void collide(ObjectNd* obj1, ObjectNd* obj2, double restitution, double deltaTime){
    // 5/24/2023
    // the initial masses
    // pointers are really nice
    // looks at the memory address (pointer) of both objects
    // and gets the masses from them
    float m1i=obj1->m;
    float m2i=obj2->m;
    // The final mass is equal to the starting mass.
    float m1f=m1i;
    float m2f=m2i;
    // Get coefficient of restitution
    float c=restitution;
    // Get initial velocity vectors
    std::vector<double> v1iV=obj1->v;
    std::vector<double> v2iV=obj2->v;

    // 6/8/2023 - Get the sum of the velocity components squared for square rooting
    double v1Squared=0;
    double v2Squared=0;
    // 6/8/2023 - Get the direction vector from the first to the second
    std::vector<double> dV;
    double dVSquared=0;

    // Calculate the initial velocities and the squared distance magnitude
    for(int i=0;i<obj1->v.size();i++){
        v1Squared+=obj1->v[i];
        v2Squared+=obj2->v[i];

        dV.push_back(obj2->v[i]-obj1->v[i]);
        dVSquared+=dV[i]*dV[i];
    }
    // 6/8/2023 - Get the inital velocity magnitudes
    double v1i=sqrt(v1Squared);
    double v2i=sqrt(v2Squared);

    // 6/8/2023 - Normalize the direction vector
    for(int i=0;i<dV.size();i++){
        dV[i]/=dVSquared;
    }

    // 6/8/2023 - Get the inital impulse vectors
    //double p1i=v1i*obj1->m;
    //double p2i=v2i*obj2->m;

    // Initialize the final impulse variable vectors
    // NOPE - multiply the MAGNITUDE of the impulse by the normalized DIRECTION vector.
    //std::vector<double> p1fV;
    //std::vector<double> p2fV;

    // Set the impulse variables
    // 6/8/2023 - do it OUTSIDE - ONLY ONCE.
    //double pf=(((((m1i*v1i+m2i*v2i)/m2f)+(v2i-v1i)*c)/(1+(m1f/m2f)))-v1i)*m1f;
    //double p2f=(((((m2i*v2i+m1i*v1i)/m1f)+(v1i-v2i)*c)/(1+(m2f/m1f)))-v2i)*m2f;
    double pf=((m1i*v1i+m2i*v2i)+(m1i*restitution*(v1i-v2i)))/(m1i+m2i)*m1f;


    // Change the linear impulse by the retrieved impulse
    // Using Euler method because simplicity
    for(int i=0;i<dV.size();i++){
        //obj1->linImp[i]+=p1fV[i];
        //obj2->linImp[i]+=p2fV[i];
        //obj1->p[i]+=p1fV[i]*deltaTime;
        //obj2->p[i]+=p2fV[i]*deltaTime;
        //std::cout<<" "<<dV[i]*pf;
        obj1->linImp[i]+=dV[i]*pf;
        obj2->linImp[i]-=dV[i]*pf;
        //std::cout<<obj1
    }
}


// deltaTime is not here -6/7/2023
void elasticCollide(ObjectNd* obj1, ObjectNd* obj2){
    collide(obj1,obj2,1.0f,0.01);
}

void inelasticCollide(ObjectNd* obj1, ObjectNd* obj2){
    collide(obj1,obj2,0.0f,0.01);
}

