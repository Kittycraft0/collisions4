// 5/4/2023
#ifndef INITDATAAA_H
#define INITDATAAA_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "objectnd.h"
#include "modeldata.h"
#include "settings.h"
#include "fonts.h"
#include "drawText.h"

//6/2/2023
#include "../render/initWindow.h"

// 6/6/2023 moved from initData.cpp to initdata.h here
//constructed here 4/5/2023
#include <vector>
#include <string>

// 5/30/2023
#include <iostream>


class Data{
public:
    ModelData* modelData;
    // 5/8/2023 chatgpt "oh noo that breaks encapsulation" [below] well whatever idk
    // since it is public
    // 6/6/2023 chatgpt was right about the fact that 
    // it would be a real pain to make happen...
    std::vector<ObjectNd*> objects;
    Settings* settings;
    sf::RenderWindow* window;

    DrawText* drawText;
    
    
    // unused
    void initObjects(int num, int d);
    void dataTest2(int num);
    void initObjects(int num);

    // 6/6/2023 real constructor
    Data();

    // 6/23/2023 random number generator
    std::mt19937* gen;
    // 6/23/2023 clock
    sf::Clock* clock;
    // 6/23/2023 fonts
    Fonts* fonts;
};
void dataTest1(int num);

#endif
