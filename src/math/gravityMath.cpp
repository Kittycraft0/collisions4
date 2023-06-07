// gravityMath.cpp
#include "gravitymath.h"
// 5/11/2023
#include "invsqrt.h"
#include <vector>

void gravity(ObjectNd* obj1, ObjectNd* obj2, double G){
    // distance vector
    std::vector<double> dv;
    // squared sum for inverse rooting
    double sqSum=0;
    for(int i=0;i<(*obj1).p.size();i++){
        dv.push_back((*obj2).p.at(i)-(*obj1).p.at(i));
        sqSum+=dv.at(i)*dv.at(i);
    }
    //inverted root of the sum of the d's squared
    double d=invSqrt(sqSum);
    
    // 5/14/2023
    // magnitude of impulse
    double m=(*obj1).m*(*obj2).m*d*d*G;

    // add to the impulse
    for(int i=0;i<(*obj1).p.size();i++){
        // 6/7/2023 changed division to multiplication
        double impulse=dv.at(i)*m;
        (*obj1).linImp.at(i)+=impulse;
        (*obj2).linImp.at(i)-=impulse;
    }
};
#include <iostream>
void mathTest2(float n){
    std::cout<<n;
}