/*//invsqrt.h
#ifndef INITDATA_H
#define INITDATA_H

float invSqrt(float n);

#endif
*/

// 5/4/2023
// chatgpt made the following:
#ifndef MYHEADER_H
#define MYHEADER_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "objectnd.h"
#include "modeldata.h"
#include "settings.h"

//6/2/2023
#include "../render/initWindow.h"


class Data{
public:
    ModelData* modelData;
    // 5/8/2023 chatgpt "oh noo that breaks encapsulation" [below] well whatever idk
    // since it is public
    // i guess encapsulation could be implemented later??? probably not but
    // eh whatever
    std::vector<ObjectNd*> objects;
    Settings* settings;
    sf::RenderWindow* window;
    Data();
    // 6/5/2023 why did this issue not immediately show???
    // be sure to check other header files to match when adding dimensionality
    // or really just any other parameters...
    void initObjects(int num, int d);
    void dataTest2(int num);
    // 6//2023 constructor
    //void Data();
    // oh wait it doesn't exist here it is just inherent or whatever well ok then
    // wait no what
    //void render2d(int cameraIndex);
};
void dataTest1(int num);
// 5/30/2023
//void giveMeANumberNow();

//Data Data::initData();


//void initObjects(int num);

#endif
