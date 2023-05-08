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
#include "objectNd.h"
#include "modeldata.h"

class Model;
class Settings;

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



/*class ObjectNd{
public:
    int modelID;
    std::vector<float> p;
    std::vector<float> v;
    float m;
    std::vector<float> scale;
};*/



class Settings{
public:
    int windowWidth;
    int windowHeight;
    //remember the std:: for strings
    std::string windowName;
    bool showWireframe;
    bool showBoundingBox;
    float maxSimplificationDistance;
    std::string shaderPath;
    std::string texturePath;
};

Data initData();

#endif
