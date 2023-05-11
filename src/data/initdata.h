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


class Data{
public:
    ModelData modelData;
    // 5/8/2023 chatgpt "oh noo that breaks encapsulation" [below] well whatever idk
    // since it is public
    // i guess encapsulation could be implemented later??? probably not but
    // eh whatever
    std::vector<ObjectNd*> objects;
    Settings settings;
    sf::RenderWindow window;
};

Data initData();

void initObjects(int num);

#endif
