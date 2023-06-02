/*
ChatGPT 5/8/2023:

to make a method that increases the inputted value by 1:

void increaseByOne(int* value) {
    (*value)++; // dereference the pointer to modify the value it points to
}

int main() {
    int myValue = 5;
    increaseByOne(&myValue); // pass a pointer to myValue
    cout << myValue << endl; // prints 6
    return 0;
}
this is why c++ is nice. i can use pointers here
*/

#include "collisionmath.h"
//collisionMath.cpp 5/8/2023
#include "../data/objectnd.h"


// 5/15/2023
// (the coefficient of) restitution should be between 0 and 1, 
// 0 is inelastic, 1 is elastic
void collide(ObjectNd* obj1, ObjectNd* obj2, float restitution){
    // 5/24/2023
    // the initial masses
    // pointers are really nice
    float m1i=(*obj1).m;
    float m2i=(*obj2).m;
    // The final mass is equal to the starting mass.
    float m1f=m1i;
    float m2f=m2i;
    // Get coefficient of restitution
    float c=restitution;
    // Get initial velocity vectors
    std::vector<float> v1iV=(*obj1).v;
    std::vector<float> v2iV=(*obj2).v;
    // Initialize the final impulse variable vectors
    std::vector<float> p1fV;
    std::vector<float> p2fV;
    // Calculate the final impulses
    for(int i=0;i<v1iV.size();i++){
        // Get the initial vectors
        float v1i=v1iV[i];
        float v2i=v2iV[i];
        // Set the impulse variables
        float p1f=(((((m1i*v1i+m2i*v2i)/m2f)+(v2i-v1i)*c)/(1+(m1f/m2f)))-v1i)*m1f;
        float p2f=(((((m2i*v2i+m1i*v1i)/m1f)+(v1i-v2i)*c)/(1+(m2f/m1f)))-v2i)*m2f;
        p1fV.push_back(p1f);
        p2fV.push_back(p2f);
    }
    // Change the linear impulse by the retrieved impulse
    for(int i=0;i<p1fV.size();i++){
        (*obj1).linImp[i]+=p1fV[i];
        (*obj2).linImp[i]+=p2fV[i];
    }
}

void elasticCollide(ObjectNd* obj1, ObjectNd* obj2){
    collide(obj1,obj2,1.0f);
}

void inelasticCollide(ObjectNd* obj1, ObjectNd* obj2){
    collide(obj1,obj2,0.0f);
}

