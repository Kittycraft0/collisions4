//invsqrt.cpp
#include "invsqrt.h"

//file invsqrt.cpp created 3/15/2023
//tutorialspoint 3/14/2023
float invSqrt(float n) {
    const float threehalfs=1.5F;
    float y=n;
    long i=*(long*)&y;
    i=0x5f3759df-(i>>1);
    y=*(float*)&i;
    y=y*(threehalfs-((n*0.5F)*y*y));
    return y;
}
#include <iostream>
void mathTest1(float n){
    std::cout<<n;
}