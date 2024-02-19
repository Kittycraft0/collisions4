


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
#include "collisionoptimizationmath.h"
//collisionMath.cpp 5/8/2023
#include "../data/objectnd.h"


#include <iostream>
// Include the double invSqrt(double n); method -6/10/20923
#include "invsqrt.h"

// 5/15/2023
// (the coefficient of) restitution should be between 0 and 1, 
// 0 is inelastic, 1 is elastic
//void collide(ObjectNd* obj1, ObjectNd* obj2, double restitution, double deltaTime);


// deltaTime is not here -6/7/2023
//void elasticCollide(ObjectNd* obj1, ObjectNd* obj2);

//void inelasticCollide(ObjectNd* obj1, ObjectNd* obj2);

// 9/18/2023 what
//void collide2(ObjectNd* obj1, ObjectNd* obj2, double restitution, double deltaTime)

// 10/09/2023 I DID THE MATHEMATICS NOW FOR MULTIPLE DIMENSIONS.
//void collide3(ObjectNd* obj1, ObjectNd* obj2, double restitution, double deltaTime);

// 10/20/2023 - I did the mathematics once again, but now this time i am near certain that it is accurate
//void collide4(ObjectNd* obj1, ObjectNd* obj2, double restitution, double deltaTime);


// new method 10/31/2023
//void separateOrbs(ObjectNd* obj1, ObjectNd* obj2);


// 2/19/2024
void baseCollide(std::vector<ObjectNd*> objects, double restitution){
    for(int i=0;i<objects.size();i++){
        //objects[i]->linDisp[0]+=1;
        for(int j=i+1;j<objects.size();j++){
            //float dist=sqrt(pow(2,2)+pow(2,2));

            // copied from graviyMath.cpp at 6/7/2023
            // distance vector
            std::vector<double> dv;
            // squared sum for inverse rooting
            double sqSum=0;
            for(int k=0;k<(objects[i])->p.size();k++){
                dv.push_back((objects[j])->p[k]-(objects[i])->p[k]);
                sqSum+=dv.at(k)*dv.at(k);
            }
            double dist=sqrt(sqSum);
            // abs for magnitude is not needed due to squaring
            if(dist<objects[i]->radius+objects[j]->radius){
                //std::cout<<"Collision between "<<i<<" and "<<j<<"\n";
                //separateOrbs(data->objects[i],data->objects[j]);
                collide4(
                    objects[i],
                    objects[j],
                    restitution//,
                    //deltaTime
                );
            }
        }
    }    
}

// 2/19/2024
void nTreeOpimizedCollide(std::vector<ObjectNd*> objects, double restitution){
    
}