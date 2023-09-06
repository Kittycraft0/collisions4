// 9/5/2023
// wallCollide.cpp
#include "wallCollide.h"
#include <cmath>

void wallCollide(ObjectNd* obj, int width, int height){
    if(obj->p[0]<=-width/4){
        obj->v[0]=1*abs(obj->v[0]);
    }
    if(obj->p[0]>=width/4){
        obj->v[0]=-1*abs(obj->v[0]);
    }
    if(obj->p[1]<=-height/4){
        obj->v[1]=1*abs(obj->v[1]);
    }
    if(obj->p[1]>=height/4){
        obj->v[1]=-1*abs(obj->v[1]);
    }
}

void wallCollide(ObjectNd* obj, int x1, int y1, int x2, int y2){

}