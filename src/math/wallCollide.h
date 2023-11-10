// 9/5/2023
// wallCollide.h
#ifndef WALLCOLLIDE_H
#define WALLCOLLIDE_H

#include "../data/objectnd.h"

void wallCollide(ObjectNd* obj, int width, int height);
void wallCollide(ObjectNd* obj, int x1, int y1, int x2, int y2);
void wallCollide(ObjectNd* obj,std::vector<int> border1,std::vector<int> border2);
void wallCollide(ObjectNd* obj,std::vector<int> border1,std::vector<int> border2,std::vector<double> g);
void wallCollide(ObjectNd* obj,std::vector<int> border1,std::vector<int> border2,std::vector<double> g,double wallRestitution);

#endif // WALLCOLLIDE_H