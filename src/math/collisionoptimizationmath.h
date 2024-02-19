// collisionoptimizationmath.h
// 2/19/2024
#ifndef COLLISIONOPTIMIZATIONMATH_H
#define COLLISIONOPTIMIZATIONMATH_H

#include "../data/objectnd.h"
#include "collisionmath.h"

//void collide(ObjectNd* obj1, ObjectNd* obj2,double restitution,double deltaTime);
//void elasticCollide(ObjectNd* obj1, ObjectNd* obj2);
//void inelasticCollide(ObjectNd* obj1, ObjectNd* obj2);
//void collide2(ObjectNd* obj1, ObjectNd* obj2,double restitution,double deltaTime);
//void collide3(ObjectNd* obj1, ObjectNd* obj2,double restitution,double deltaTime);
//void collide4(ObjectNd* obj1, ObjectNd* obj2,double restitution,double deltaTime);
//void collide4(ObjectNd* obj1, ObjectNd* obj2,double restitution);
void baseCollide(std::vector<ObjectNd*> objects, double restitution);
void nTreeOpimizedCollide(std::vector<ObjectNd*> objects, double restitution);

//void separateOrbs(ObjectNd* obj1, ObjectNd* obj2);

#endif //COLLISIONOPTIMIZATIONMATH_H