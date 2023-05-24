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


void elasticCollide(ObjectNd* obj1, ObjectNd* obj2){
    collide(obj1,obj2,1);
}

void inelasticCollide(ObjectNd* obj1, ObjectNd* obj2){
    collide(obj1,obj2,0);
}

// 5/15/2023
// (the coefficient of) restitution should be between 0 and 1, 
// 0 is inelastic, 1 is elastic
void collide(ObjectNd* obj1, ObjectNd* obj2, float restitution){
    // 5/24/2023
    
}