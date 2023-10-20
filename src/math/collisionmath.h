//collisionmath.h
#ifndef COLLISIONMATH_H
#define COLLISIONMATH_H

#include "../data/objectnd.h"

void collide(ObjectNd* obj1, ObjectNd* obj2,double restitution,double deltaTime);
void elasticCollide(ObjectNd* obj1, ObjectNd* obj2);
void inelasticCollide(ObjectNd* obj1, ObjectNd* obj2);
void collide2(ObjectNd* obj1, ObjectNd* obj2,double restitution,double deltaTime);
void collide3(ObjectNd* obj1, ObjectNd* obj2,double restitution,double deltaTime);
void collide4(ObjectNd* obj1, ObjectNd* obj2,double restitution,double deltaTime);


#endif