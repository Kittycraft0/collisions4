//collisionmath.h
#ifndef COLLISIONMATH_H
#define COLLISIONMATH_H

#include "../data/objectnd.h"

void collide(ObjectNd* obj1, ObjectNd* obj2,double restitution);
void elasticCollide(ObjectNd* obj1, ObjectNd* obj2);
void inelasticCollide(ObjectNd* obj1, ObjectNd* obj2);


#endif