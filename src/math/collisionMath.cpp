


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

// The header file works -6/10/2023
#include "collisionmath.h"
//collisionMath.cpp 5/8/2023
#include "../data/objectnd.h"


#include <iostream>
// Include the double invSqrt(double n); method -6/10/20923
#include "invsqrt.h"

// 5/15/2023
// (the coefficient of) restitution should be between 0 and 1, 
// 0 is inelastic, 1 is elastic
void collide(ObjectNd* obj1, ObjectNd* obj2, double restitution, double deltaTime){
    // 5/24/2023
    // the initial masses
    // pointers are really nice
    // looks at the memory address (pointer) of both objects
    // and gets the masses from them
    double m1i=obj1->m;
    double m2i=obj2->m;
    // The final mass is equal to the starting mass.
    //double m1f=m1i;
    //double m2f=m2i;
    // Get initial velocity vectors
    std::vector<double> v1iV=obj1->v;
    std::vector<double> v2iV=obj2->v;

    // 6/8/2023 - Get the sum of the velocity components squared for square rooting
    double v1Squared=0;
    double v2Squared=0;
    // 6/8/2023 - Get the direction vector from the first object to the second object
    std::vector<double> dV;
    double dVSquared=0;

    // Calculate the initial velocities and the squared distance magnitude
    for(int i=0;i<obj1->v.size();i++){
        // The sqared magnitude is the sum of the SQUARED components.
        v1Squared+=obj1->v[i]*obj1->v[i];
        v2Squared+=obj2->v[i]*obj2->v[i];
        
        dV.push_back(obj2->p[i]-obj1->p[i]);
        dVSquared+=dV[i]*dV[i];
    }
    // 6/8/2023 - Get the inital velocity magnitudes
    double v1i=sqrt(v1Squared);
    double v2i=sqrt(v2Squared);

    //double invDist=invSqrt(dVSquared);
    double dist=sqrt(dVSquared);
    // 6/8/2023 - Normalize the direction vector
    for(int i=0;i<dV.size();i++){
        //dV[i]*=invDist;
        dV[i]/=dist;
    }

    // 6/8/2023 - Get the inital impulse vectors
    //double p1i=v1i*obj1->m;
    //double p2i=v2i*obj2->m;

    // Initialize the final impulse variable vectors
    // NOPE - multiply the MAGNITUDE of the impulse by the normalized DIRECTION vector.

    // Set the impulse variables
    // 6/8/2023 - do it OUTSIDE - ONLY ONCE.
    // 6/10/2023 - it's a CHANGE in the impulse variable
    //double pf=(((m1i*v1i+m2i*v2i)+(m1i*restitution*(v1i-v2i)))/(m1i+m2i)*-v1i)*m1i;
    double v1f=((m1i*v1i+m2i*v2i)+(m2i*restitution*(v2i-v1i)))/(m2i-m1i);
    //double pf=((((m1i*v1i+m2i*v2i)+(m1i*restitution*(v2i-v1i)))/(m2i+m1i))-v1i)*m1i;
    double pf=(v1f-v1i)*m1i;

    // Change the linear impulse by the retrieved impulse
    // Using Euler method because simplicity
    // Velocities are updated outside this method using the object's linear impulse variables
    // by doing linImp*mass for each component and adding that to the velocities. 
    // The velocities are then added to the positions. This is done every frame.
    for(int i=0;i<dV.size();i++){
        // Multiply the MAGNITUDE of the impulse by the normalized DIRECTION vector.
        double newImp=dV[i]*pf;
        obj1->linImp[i]+=newImp;
        obj2->linImp[i]-=newImp;
    }
}


// deltaTime is not here -6/7/2023
void elasticCollide(ObjectNd* obj1, ObjectNd* obj2){
    collide(obj1,obj2,1.0f,0.01);
}

void inelasticCollide(ObjectNd* obj1, ObjectNd* obj2){
    collide(obj1,obj2,0.0f,0.01);
}

