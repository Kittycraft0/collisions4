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

}

void inelasticCollide(float n){

}

void collide(float n){

}