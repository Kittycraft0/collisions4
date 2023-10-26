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


// 10/26/2023 beter wallCollide method
void wallCollide(ObjectNd* obj,std::vector<int> border1,std::vector<int> border2){
    // border1 is top left (most negative values) 
    // while border2 is top right (most positive values)
    //std::cout<<obj->p.size();
    for(int i=0;i<obj->p.size();i++){
        //std::cout<<i;
        if(obj->p[i]-obj->radius<=border1[i]){
            obj->v[i]=1*abs(obj->v[0]);
            obj->linDisp[i]+=border1[i]+obj->radius-obj->p[i];
        }
        if(obj->p[i]+obj->radius>=border2[i]){
            obj->v[i]=-1*abs(obj->v[0]);
            obj->linDisp[i]+=border2[i]-obj->radius-obj->p[i];
        }
    }
}