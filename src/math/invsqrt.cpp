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

// 6/10/2023 double variant from stackoverflow:
// https://stackoverflow.com/questions/11644441/fast-inverse-square-root-on-x64
#include <cstdint>

double invSqrt(double n){
    double y=n;
    double x2=y*0.5;
    std::int64_t i=*(std::int64_t*)&y;
    // The magic number is for doubles is from https://cs.uwaterloo.ca/~m32rober/rsqrt.pdf
    i=0x5fe6eb50c7b537a9-(i>>1);
    y=*(double*)&i;
    y=y*(1.5-(x2*y*y));   // 1st iteration
    // y=y*(1.5-(x2*y*y));   // 2nd iteration, this can be removed
    return y;
}

#include <iostream>
void mathTest1(float n){
    std::cout<<n;
}