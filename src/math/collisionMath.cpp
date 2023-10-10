


/*
    6/2/2023
    Some quick lessons to better understand the code:
    
    1.
    If you see a * between the data type and the variable name like so:
    float* number=3;
    Just read it as float numbers=3;
    Forget the star, as the star is making a pointer, and it functions
    sort of like as if it wasn't there.

    2.
    If you see a * right before the variable name in expressions,
    then it is dereferencing the pointer, 
    or reading the data at the memory address.
    For simplicity, just pretend it's not there. For example:
    float m1i=(*obj1).m;
    Read it as the following:
    float m1i=obj1.m;

    3.
    Some data types in the code here are objects.
    Objects typically have properties (of which in this case I set)
    such as position, velocity, mass, etc.
    You can read the following:
    obj1.m
    as getting the objects mass. In physics talk, it would be:
    m sub 1
    being the mass of the first object.

    4. read std::vector<float> as making a vector

    5. read vector[number] as getting the number'th component of the vector

    6. push_back() adds a new component to the vector (they start empty)
    7. .size() returns the number of components of the vector
*/

// The header file works -6/10/2023
#include "collisionmath.h"
//collisionMath.cpp 5/8/2023
#include "../data/objectnd.h"


#include <iostream>
// Include the double invSqrt(double n); method -6/10/20923
#include "invsqrt.h"

// 5/15/2023
// (the coefficient of) restitution should be between 0 and 1, 
// 0 is inelastic, 1 is elastic
void collide(ObjectNd* obj1, ObjectNd* obj2, double restitution, double deltaTime){
    // 5/24/2023
    // the initial masses
    // pointers are really nice
    // looks at the memory address (pointer) of both objects
    // and gets the masses from them
    double m1i=obj1->m;
    double m2i=obj2->m;
    // The final mass is equal to the starting mass.
    //double m1f=m1i;
    //double m2f=m2i;
    // Get initial velocity vectors
    std::vector<double> v1iV=obj1->v;
    std::vector<double> v2iV=obj2->v;

    // 6/8/2023 - Get the sum of the velocity components squared for square rooting
    double v1Squared=0;
    double v2Squared=0;
    // 6/8/2023 - Get the direction vector from the first object to the second object
    std::vector<double> distV;
    double distSquared=0;

    // Calculate the initial velocities and the squared distance magnitude
    for(int i=0;i<obj1->v.size();i++){
        // The sqared magnitude is the sum of the SQUARED components.
        v1Squared+=obj1->v[i]*obj1->v[i];
        v2Squared+=obj2->v[i]*obj2->v[i];
        
        distV.push_back(obj2->p[i]-obj1->p[i]);
        distSquared+=distV[i]*distV[i];
    }
    // 6/8/2023 - Get the inital velocity magnitudes
    double v1i=sqrt(v1Squared);
    double v2i=sqrt(v2Squared);

    //double invDist=invSqrt(distSquared);
    double dist=sqrt(distSquared);
    // 6/8/2023 - Normalize the direction vector
    for(int i=0;i<distV.size();i++){
        //dV[i]*=invDist;
        distV[i]/=dist;
    }

    // 6/8/2023 - Get the inital impulse vectors
    //double p1i=v1i*obj1->m;
    //double p2i=v2i*obj2->m;

    // Initialize the final impulse variable vectors
    // NOPE - multiply the MAGNITUDE of the impulse by the normalized DIRECTION vector.

    // Set the impulse variables
    // 6/8/2023 - do it OUTSIDE - ONLY ONCE.
    // 6/10/2023 - it's a CHANGE in the impulse variable
    //double pf=(((m1i*v1i+m2i*v2i)+(m1i*restitution*(v1i-v2i)))/(m1i+m2i)*-v1i)*m1i;
    double v1f=((m1i*v1i+m2i*v2i)+(m2i*restitution*(v2i-v1i)))/(m2i+m1i);
    //double pf=((((m1i*v1i+m2i*v2i)+(m1i*restitution*(v2i-v1i)))/(m2i+m1i))-v1i)*m1i;
    double pf=abs((v1f-v1i)*m1i);

    // Change the linear impulse by the retrieved impulse
    // Using Euler method because simplicity
    // Velocities are updated outside this method using the object's linear impulse variables
    // by doing linImp*mass for each component and adding that to the velocities. 
    // The velocities are then added to the positions. This is done every frame.
    for(int i=0;i<distV.size();i++){
        // Multiply the MAGNITUDE of the impulse by the normalized DIRECTION vector.
        double newImp=distV[i]*pf;
        obj1->linImp[i]-=newImp;
        obj2->linImp[i]+=newImp;
    }

    // 6/23/2023 displace them so they are no longer colliding
    // 6/23/2023 redundant collision check because you never know???
    /*if(dist<obj1->radius+obj2->radius){
        double adjust=obj1->radius+obj2->radius-dist;
        double massSum=obj1->m+obj2->m;
        for(int i=0;i<obj1->p.size();i++){
            obj1->linDisp[i]+=-distV[i]*((massSum-obj1->m)/massSum);
            obj2->linDisp[i]+=distV[i]*((massSum-obj2->m)/massSum);
        }
        // Adjust the position with the amount correlating 
        // to it's amount of mass compared to the other because why not maybe
    }*/

    // 6/23/2023 what is the size of a long double
    //std::cout << "Size of long double: " << sizeof(long double) * 8 << " bits" << std::endl;
    // wow 128 bits that is crazy long wow ok
    
}


// deltaTime is not here -6/7/2023
void elasticCollide(ObjectNd* obj1, ObjectNd* obj2){
    collide(obj1,obj2,1.0f,0.01);
}

void inelasticCollide(ObjectNd* obj1, ObjectNd* obj2){
    collide(obj1,obj2,0.0f,0.01);
}

// 9/18/2023 what
void collide2(ObjectNd* obj1, ObjectNd* obj2, double restitution, double deltaTime){
    // 5/24/2023
    // the initial masses
    double m1i=obj1->m;
    double m2i=obj2->m;
    // Get initial velocity vectors
    std::vector<double> v1iV=obj1->v;
    std::vector<double> v2iV=obj2->v;

    // 6/8/2023 - Get the sum of the velocity components squared for square rooting
    // Calculate the initial velocities and the squared distance magnitude
    // The sqared magnitude is the sum of the SQUARED components.
    double v1Squared=obj1->v[0]*obj1->v[0]+obj1->v[1]*obj1->v[1];
    double v2Squared=obj2->v[0]*obj2->v[0]+obj2->v[1]*obj2->v[1];
    // 6/8/2023 - Get the direction vector from the first object to the second object
    std::vector<double> distV={(obj2->p[0]-obj1->p[0]),(obj2->p[1]-obj1->p[1])};
    //double distSquared=distV[0]*distV[0]+distV[1]*distV[1];
    double velSquared=pow(obj2->v[0]-obj1->v[0],2)+pow(obj2->v[1]-obj1->v[1],2);
    double distSquared=pow(obj2->p[0]-obj1->p[0],2)+pow(obj2->p[1]-obj1->p[1],2);

    // 6/8/2023 - Get the inital velocity magnitudes
    double v1i=sqrt(v1Squared);
    double v2i=sqrt(v2Squared);
    
    //double invDist=invSqrt(distSquared);
    double dist=sqrt(distSquared);
    
    // 6/8/2023 - Normalize the direction vector
    // (delta x over distance, delta y over distance, a better word for distance here might be magnitude)
    distV={(obj2->p[0]-obj1->p[0])/dist,(obj2->p[1]-obj1->p[1])/dist};

    // 6/8/2023 - Get the inital impulse vectors
    //double p1i=v1i*obj1->m;
    //double p2i=v2i*obj2->m;

    // Initialize the final impulse variable vectors
    // NOPE - multiply the MAGNITUDE of the impulse by the normalized DIRECTION vector.

    // Set the impulse variables
    // 6/8/2023 - do it OUTSIDE - ONLY ONCE.
    // 6/10/2023 - it's a CHANGE in the impulse variable
    //double pf=(((m1i*v1i+m2i*v2i)+(m1i*restitution*(v1i-v2i)))/(m1i+m2i)*-v1i)*m1i;
    // 9/18/2023 - changed - to +
    double v1f=(
        m1i*v1i+
        m2i*v2i+
        m2i*restitution*(v2i-v1i)
        )/(m2i+m1i);
    double v2f=(
        m1i*v1i+
        m2i*v2i+
        m1i*restitution*(v1i-v2i)
        )/(m2i+m1i);
    //double pf=((((m1i*v1i+m2i*v2i)+(m1i*restitution*(v2i-v1i)))/(m2i+m1i))-v1i)*m1i;
    //double pf1=abs((v1f-v1i)*m1i);
    //double pf2=abs((v2f-v2i)*m2i);
    double pf1=(v1f-v1i)*m1i;
    double pf2=(v2f-v2i)*m2i;

    // Change the linear impulse by the retrieved impulse
    // Using Euler method because simplicity
    // Velocities are updated outside this method using the object's linear impulse variables
    // by doing linImp*mass for each component and adding that to the velocities. 
    // The velocities are then added to the positions. This is done once per collision.
    // 9/18/2023 DIVIDED BY DELTATIME.
    //obj1->linImp[0]-=distV[0]*pf1;
    //obj1->linImp[1]-=distV[1]*pf1;

    //obj2->linImp[0]+=distV[0]*pf2;
    //obj2->linImp[1]+=distV[1]*pf2;
    
    obj1->v[0]=-distV[0]*v1f;
    obj1->v[1]=-distV[1]*v1f;

    obj2->v[0]=distV[0]*v2f;
    obj2->v[1]=distV[1]*v2f;
    std::cout<<
    v1i-v1f<<" "<<v2i-v2f<<" "<<(obj1->linImp[0])<<" "<<(obj1->linImp[1])<<" "
    <<(obj2->linImp[0])<<" "<<(obj2->linImp[1]);
    std::cout<<"\n";

    // 6/23/2023 displace them so they are no longer colliding
    // 6/23/2023 redundant collision check because you never know???
    /*if(dist<obj1->radius+obj2->radius){
        double adjust=obj1->radius+obj2->radius-dist;
        double massSum=obj1->m+obj2->m;
        for(int i=0;i<obj1->p.size();i++){
            obj1->linDisp[i]+=-distV[i]*((massSum-obj1->m)/massSum);
            obj2->linDisp[i]+=distV[i]*((massSum-obj2->m)/massSum);
        }
        // Adjust the position with the amount correlating 
        //  to it's amount of mass compared to the other because why not maybe
    }*/

    // 6/23/2023 what is the size of a long double
    //std::cout << "Size of long double: " << sizeof(long double) * 8 << " bits" << std::endl;
    // wow 128 bits that is crazy long wow ok
    
}

// 10/09/2023 I DID THE MATHEMATICS NOW FOR MULTIPLE DIMENSIONS.
void collide3(ObjectNd* obj1, ObjectNd* obj2, double restitution, double deltaTime){
    // Desmos graph: https://www.desmos.com/calculator/pwb0tfbmwe

    // The normal between the two objects is the difference between their components (obj2.v-obj1.v)
    std::vector<double> normal;
    
    // The momentum vectors of the two objects
    std::vector<double> p1;
    std::vector<double> p2;

    // The dot products of both momentums on the normal
    double dotProduct1=0;
    double dotProduct2=0;

    // Get the magnitude of the normal
    double normalComponentSquareSum=0;

    // Assemble the normal and the normal magnitude and the momentum vectors
    for(int i=0;i<obj1->v.size();i++){
        // Get the momentum components by multiplying the velocity components by the mass
        p1.push_back(obj1->v[i]*obj1->m);
        p2.push_back(obj2->v[i]*obj2->m);
        // Push back the components to the normal vector
        //dumb
        //normal.push_back(p2[i]-p1[i]);
        normal.push_back(obj2->p[i]-obj1->p[i]);
        // Push back the sum of the produt of the normal 
        // and the momentums to the respective dot products
        dotProduct1+=p1[i]*normal[i];
        dotProduct2+=p2[i]*normal[i];

        normalComponentSquareSum+=normal[i]*normal[i];
    }

    // Get the inverse of the normal's magnitude (or distance), 
    // because that is the only one really used here
    std::cout<<"inverse square root of 4: "<<invSqrt((double)4.0f)<<"\n";
    double invNormalMagnitude=invSqrt(normalComponentSquareSum);
    std::cout<<"normal components squared sum: "<<
    normalComponentSquareSum<<"\ninv square root of that: "<<invNormalMagnitude
    <<"\none over that: "<<1/invNormalMagnitude<<
    "\nsquare root of the original: "<<sqrt(normalComponentSquareSum)<<"\n";


    // The unit vector of the normal vector
    std::vector<double> unitNormal;
    // Get the unit vector of the normal vector
    for(int i=0;i<obj1->v.size();i++){
        unitNormal.push_back(normal[i]*invNormalMagnitude);
    }
    
    // Amount of momentum from the first object in the direction of the normal vector
    // Taking the dot product of the first momentum and dividing it by only the magnitude of the normal
    double p1xi=dotProduct1*invNormalMagnitude;
    double p2xi=-dotProduct2*invNormalMagnitude;

    //The magnitudes of the initial velocities in the normal direction
    double v1xi=p1xi/obj1->m;
    double v2xi=p2xi/obj2->m;

    // The extreme equation; the change in momentum (in the normal direction)
    double p1dx=obj1->m*(p1xi+p2xi+obj2->m*restitution*(v2xi-v1xi))/(obj1->m+obj2->m)-p1xi;

    // bector lol
    // The final changes in momentum (momentum  change final 1/2)
    std::vector<double> pcf1;
    std::vector<double> pcf2;
    for(int i=0;i<obj1->v.size();i++){
        pcf1.push_back(-unitNormal[i]*(2*p1xi+p1dx));
        pcf2.push_back(unitNormal[i]*(2*p2xi-p1dx));
        obj1->linImp[i]+=pcf1[i];
        obj2->linImp[i]+=pcf2[i];
        //obj1->v[i]=pcf1[i]/obj1->m;
        //obj2->v[i]=pcf1[i]/obj2->m;
    }

    //std::vector<double> normal=obj2->v-obj1->v;

    // 10/10/2023 copy/paste then modified
    // because i guess it's actually REALLY WRONG!? very strange
    // 6/23/2023 displace them so they are no longer colliding
    // 6/23/2023 redundant collision check because you never know???
    double dist=1/invNormalMagnitude;
    std::cout<<"distance: "<<dist;
    std::cout<<"sum of radii: "<<obj1->radius+obj2->radius;
    if(dist<obj1->radius+obj2->radius){
        // the distance to adjust outwards by - r1+r2-distance
        double adjust=obj1->radius+obj2->radius-dist;
        // the sum of the masses for allocating which object gets displaced more
        double massSum=obj1->m+obj2->m;
        for(int i=0;i<obj1->p.size();i++){
            double distV=obj2->v[i]-obj1->v[i];
            //obj1->linDisp[i]+=-distV*((massSum-obj1->m)/massSum);
            // reverse the signs for some weird orbiting thing 
            // where the radius is the sphere of influence idk
            obj1->linDisp[i]+=+unitNormal[i]*(massSum-obj1->m)/massSum;
            //obj2->linDisp[i]+=distV*((massSum-obj2->m)/massSum);
            obj2->linDisp[i]+=unitNormal[i]*(massSum-obj2->m)/massSum;
            //std::cout<<unitNormal[i];
            //obj1->linDisp[i]+=unitNormal[i]*5;
            //obj2->linDisp[i]+=-unitNormal[i]*5;
        }
        // Adjust the position with the amount correlating to it's 
        // amount of mass compared to the other because why not maybe
    }
}