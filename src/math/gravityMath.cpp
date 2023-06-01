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
    // float dx=(*obj2).p.at(0)-(*obj1).p.at(0);
    // float dy=(*obj2).p.at(1)-(*obj1).p.at(1);
    // distance vector
    std::vector<float> dv;
    // squared sum for inverse rooting
    float sqSum=0;
    for(int i=0;i<(*obj1).p.size();i++){
        dv.push_back((*obj2).p.at(i)-(*obj1).p.at(i));
        sqSum+=dv.at(i)*dv.at(i);
    }
    //inverted root of the sum of the d's squared
    float d=invSqrt(sqSum);
    
    // 5/14/2023 outer ear infections suck
    // magnitude of impulse
    float m=(*obj1).mass*(*obj2).mass*d*d*G;

    // add to the impulse
    for(int i=0;i<(*obj1).p.size();i++){
        float impulse=dv.at(i)/m;
        (*obj1).linImp.at(i)+=impulse;
        (*obj2).linImp.at(i)-=impulse;
    }
    // :( -5/16/2023
    //(*obj1).linImp+=dv/m;
    //(*obj2).linImp-=dv/m;
    
};
#include <iostream>
void somethingggnoww(float n){
    std::cout<<n;
}