// gravitymath.h
// 5/11/2023
#ifndef GRAVITYMATH_H
#define GRAVITYMATH_H
// The gravity math!
// DONE: find old name I used
// and now I will soon be taking the AP Physics 1 test... Hope I do well!
// Without my tungsten cube... Hahahahaha
// Oh... The gravity method in the Javascript 
// 3d engine was just called "gravity"... Wow...
// Also, I guess I can replace old todo's with "DONE"! Nice!

#include "../data/objectnd.h"

void gravity(ObjectNd* obj1, ObjectNd* obj2, double G);
//void gravity(ObjectNd obj1, ObjectNd obj2);
// 11/01/2023 second gravity function
// i still carry around my tungsten cube
// i got a 4/5 on the ap physics 1 test
// i am now in ap physics C
void gravity2(ObjectNd* obj1, ObjectNd* obj2, double G);

// 2/2/2024
// ap physics has ended, i am sad, so now i view ap physics 2 on kahn academy while at work if there
// are no more customers present because my schedule couldn't fit it in without replacing spanish 1,
// of which i need to not need to take it in college...
void gravity2(ObjectNd* obj1, ObjectNd* obj2, double G);

// 2/2/2024 cringe imperfect energy
void setEnergy(ObjectNd* obj, double G);


void mathTest2(float n);


#endif //GRAVITYMATH_H