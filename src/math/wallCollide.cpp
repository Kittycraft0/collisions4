// 9/5/2023
// wallCollide.cpp
#include "wallCollide.h"
#include <cmath>
#include "../data/settings.h"
#include <vector>
#include <iostream>

void wallCollide(ObjectNd* obj, int width, int height){
    if(obj->p[0]-obj->radius<=-width/4){
        obj->v[0]=1*abs(obj->v[0]);
        obj->linDisp[0]+=-width/4+obj->radius-obj->p[0];
    }
    if(obj->p[0]+obj->radius>=width/4){
        obj->v[0]=-1*abs(obj->v[0]);
        obj->linDisp[0]+=+width/4-obj->radius-obj->p[0];
    }
    if(obj->p[1]-obj->radius<=-height/4){
        obj->v[1]=1*abs(obj->v[1]);
        obj->linDisp[1]+=-height/4+obj->radius-obj->p[1];
    }
    if(obj->p[1]+obj->radius>=height/4){
        obj->v[1]=-1*abs(obj->v[1]);
        obj->linDisp[1]+=+height/4-obj->radius-obj->p[1];
    }
}

void wallCollide(ObjectNd* obj, int x1, int y1, int x2, int y2){

}

// 10/26/2023 better wallCollide method
void wallCollide(ObjectNd* obj,std::vector<int> border1,std::vector<int> border2){
    // border1 is top left (most negative values) 
    // while border2 is top right (most positive values)
    //std::cout<<obj->p.size();
    for(int i=0;i<obj->p.size();i++){
        //std::cout<<i;
        if(obj->p[i]-obj->radius<=border1[i]){
            obj->v[i]=1*abs(obj->v[i]);
            // physics says that when preserving energy, the final velocity should be equal to the 
            // square root of the initial velocity squared (in the direction or not? probably not as 
            // that is not in the direction of the collision) plus two times the gravity times 
            // (final height - initial height)
            // sqrt(obj->v[i]*obj->v[i]+2*g*(h1-h2))
            obj->v[i]=0;
            obj->linDisp[i]+=border1[i]+obj->radius-obj->p[i];
        }
        if(obj->p[i]+obj->radius>=border2[i]){
            obj->v[i]=-1*abs(obj->v[i]);
            obj->linDisp[i]+=border2[i]-obj->radius-obj->p[i];
        }
    }
}

// 10/26/2023 better energy preserving wallCollide method
void wallCollide(ObjectNd* obj,std::vector<int> border1,std::vector<int> border2,std::vector<double> g){
    // border1 is top left (most negative values) 
    // while border2 is top right (most positive values)
    //std::cout<<obj->p.size();
    for(int i=0;i<obj->p.size();i++){
        //std::cout<<i;
        if(obj->p[i]-obj->radius<=border1[i]){
            //obj->v[i]=1*abs(obj->v[i]);
            // physics says that when preserving energy, the final velocity should be equal to the 
            // square root of the initial velocity squared (in the direction or not? probably not as 
            // that is not in the direction of the collision) plus two times the gravity times 
            // (final height - initial height)
            // sqrt(obj->v[i]*obj->v[i]+2*g*(h1-h2))
            double pf=border1[i]+obj->radius;
            obj->v[i]=1*sqrt(abs(obj->v[i]*obj->v[i]+2*g[i]*(obj->p[i]-pf)))*0;
            obj->linDisp[i]+=border1[i]+obj->radius-obj->p[i];
        }
        if(obj->p[i]+obj->radius>=border2[i]){
            //obj->v[i]=-1*abs(obj->v[i]);
            double pf=border2[i]-obj->radius;
            obj->v[i]=-1*sqrt(abs(obj->v[i]*obj->v[i]+2*g[i]*(obj->p[i]-pf)))*0;
            obj->linDisp[i]+=border2[i]-obj->radius-obj->p[i];
        }
    }
}