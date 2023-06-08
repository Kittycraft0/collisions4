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
    // Initialize the final impulse variable vectors
    std::vector<double> p1fV;
    std::vector<double> p2fV;
    // Calculate the final impulses
    // For loops are used here to allow for use for any number of dimensions
    for(int i=0;i<v1iV.size();i++){
        // Get the initial vectors
        double v1i=v1iV[i];
        double v2i=v2iV[i];
        // Set the impulse variables
        //double p1f=(((((m1i*v1i+m2i*v2i)/m2f)+(v2i-v1i)*c)/(1+(m1f/m2f)))-v1i)*m1f;
        //double p2f=(((((m2i*v2i+m1i*v1i)/m1f)+(v1i-v2i)*c)/(1+(m2f/m1f)))-v2i)*m2f;
        // Set them in the final returned vector

        //double v1f=((m1i*v1i+m2i*v2i)+(m2i*restitution*(v2i-v1i)))/(m1i+m2i);
        //double v2f=((m1i*v1i+m2i*v2i)+(m1i*restitution*(v1i-v2i)))/(m1i+m2i);
        double vf=((m1i*v1i+m2i*v2i)+(m1i*restitution*(v1i-v2i)))/(m1i+m2i);
        
        //double v1f=m1i*m21+m1f*m2f+m2f*restitution*(v2f-v2i)
        //double v1f=((m1i*v1i+m2i*v2i)+(m2i*restitution*(v2i-v1i)))/(m1i+m2i);

        // Calculate the final impulses
        double p1f=m1i*(vf-v1i);
        double p2f=m2i*(-vf-v2i);

        p1fV.push_back(p1f);
        p2fV.push_back(p2f);

       
    }

    // Change the linear impulse by the retrieved impulse
    // Using Euler method because simplicity
    for(int i=0;i<p1fV.size();i++){
        obj1->linImp[i]+=p1fV[i];
        obj2->linImp[i]+=p2fV[i];
        //obj1->p[i]+=p1fV[i]*deltaTime;
        //obj2->p[i]+=p2fV[i]*deltaTime;
    }
}


// deltaTime is not here -6/7/2023
void elasticCollide(ObjectNd* obj1, ObjectNd* obj2){
    collide(obj1,obj2,1.0f,0.01);
}

void inelasticCollide(ObjectNd* obj1, ObjectNd* obj2){
    collide(obj1,obj2,0.0f,0.01);
}

