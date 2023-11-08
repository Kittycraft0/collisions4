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
    for(int i=0;i<obj1->p.size();i++){
        dv.push_back(obj2->p[i]+obj2->linDisp[i]-obj1->p[i]-obj1->linDisp[i]);
        sqSum+=dv[i]*dv[i];
    }
    
    if(sqSum!=0){
    // Inverted root of the sum of the d's squared
        double d=invSqrt(sqSum);
        
        // 5/14/2023
        // magnitude of impulse
        double m=obj1->m*obj2->m*d*d*G*d; // multiply a third d in there for more accurate results

        // add to the impulse
        for(int i=0;i<obj1->p.size();i++){
            // 6/7/2023 changed division to multiplication
            double impulse=dv.at(i)*m;
            obj1->linForce[i]+=impulse;
            obj2->linForce[i]-=impulse;
        }
    }
};
#include <iostream>
void mathTest2(float n){
    std::cout<<n;
}

// 11/01/2023 better method
void gravity2(ObjectNd* obj1, ObjectNd* obj2, double G){
    std::vector<double> normal;
    double distanceSquared=0;
    for(int i=0;i<obj1->p.size();i++){
        normal.push_back(obj2->p[i]-obj1->p[i]);
        distanceSquared+=normal[i]*normal[i];
    }
    double invDist=invSqrt(distanceSquared);
    // inverse distance squared
    double invDistSquared=1/distanceSquared;
    // define the force of attraction as G*m1*m2/r^2
    double forceOfAttraction=
        G // G
        *obj1->m // *m1
        *obj2->m // *m2
        *invDistSquared; // /r^2
    // give the forces
    for(int i=0;i<obj1->p.size();i++){
        normal[i]*=invDist; // normalize the normal...
        obj1->linForce[i]+=normal[i]*forceOfAttraction;
        obj2->linForce[i]-=normal[i]*forceOfAttraction;
    }
}

// 11/02/2023 [to the above gravity2 method] - much better... however, energy is still not conserved...
// i will now go read the wikipedia page for elipses...
// progress - 
// 11/02/2023 - found "barycenter" - seems to be center of mass, also seems to 
// be one of the focal points of the two elipses?
// found two-body problem
// found Kepler problem
// found amazing picture: 
// https://upload.wikimedia.org/wikipedia/commons/thumb/e/e0/
// Cat_demonstrating_static_cling_with_styrofoam_peanuts.jpg
// /310px-Cat_demonstrating_static_cling_with_styrofoam_peanuts.jpg
// weirdly the energy likes staying like below 60000 for two objects at the current settings...
// 11/03/2023 - AP Physics C Mechanics FAQ final yesterday, Mechanics MCQ final today
// 11/03/2023 - found Kepler's laws oh planetary motion wikipedia page, reading up on those
// 11/08/2023 - got like 55/90 on the ap physics c mechanics final, got an ap score of a 5/5 lol
// 11/08/2023 - asked chatgpt some questions, then found this image:
// https://www.researchgate.net/profile/Harry-Varvoglis/publication/252503394
// /figure/fig3/AS:667713391300608@1536206686009/Definition-of-true-v-eccentric-E-and-mean-M-anomaly.png
// it is very useful for actually telling me what stuff is