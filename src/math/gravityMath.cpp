// gravityMath.cpp
#include "gravitymath.h"
// 5/11/2023
#include "invsqrt.h"
#include <vector>
//void gravity(ObjectNd obj1, ObjectNd obj2){
//
//};

//oh does it auto-import!? the more you know!!!
void gravity(ObjectNd* obj1, ObjectNd* obj2, float G){
    float dx=*obj2.p.at(0)-*obj1.p.at(0);
    float dy=*obj2.p.at(1)-*obj1.p.at(1);
    // distance vector
    std::vector<float> dv;
    // squared sum for inverse rooting
    float sqSum=0;
    for(int i=0;i<obj1.p.size();i++){
        dv.push_back(obj2.p.at(i)-obj1.p.at(i));
        sqSum+=dv.at(i)*dv.at(i);
    }
    //inverted root of the sum of the d's squared
    float d=invSqrt(sqSum);
    float m=0;
};