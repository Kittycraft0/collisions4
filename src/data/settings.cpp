// settings.cpp
#include "settings.h"
// 5/9/2023
// the settings script
// TODO: get settings from a text file or something
#include <string>

//4/5/2023
/*class Settings{public:
    // just put like whatever you want here - booleans, integers, floats, etc.
    // all of the arbitrary values should be defined here
    // chatgpt says the following as some examples:
    // The width and height of the application window
    // The number of vertices to use for rendering models
    // The maximum distance between vertices when simplifying models
    // The file paths for shaders and textures used in rendering
    // The default camera position and rotation
    // Whether to show debug information, such as wireframes or bounding boxes
//public:
    int windowWidth=800;
    int windowHeight=800;
    int windowX=200;
    int windowY=200;
    std::string windowName="Physics simulation";
    bool showWireframe;
    bool showBoundingBox;
    float maxSimplificationDistance;
    std::string shaderPath;
    std::string texturePath;
    
    // 5/11/2023 boop tungsten
    int numObjects=10;
};*/
#include <iostream>
void dataTest3(int n){
    std::cout<<n;
}

// 6/1/2023
// Set all the settings! Sorry for the lack of a text file.
// Feeling pressured on time, even though I have like a week of school left.
// I sure hope I work on this next year!
#include <cmath>
Settings::Settings(){
    // number of dimensions
    this->d=2;
    // number of objects
    this->numObjects=3;
    // minimumn distance from the edge that objects should spawn with
    this->objectSpawnMargin=200;

    // 6/23/2023 set the project seed
    this->seed=69420;
    // constants
    this->G=1000*7/(this->numObjects*sqrt(this->numObjects));
    this->restitution=1;

    // 10/25/2023
    // global gravity in meters per second squared
    // ap exam said g is 10, bit slow though
    this->globalGravity=100;
    

    // window
    this->windowWidth=800;
    this->windowHeight=400;
    // 6/6/2023 - it automatically puts itself back up at the top
    this->windowX=200;
    this->windowY=50;
    this->windowName="Physics simulation";

    // physics border corners as coordinates
    // 4 dimensions beecaue why not
    this->border1={-120,-90,-100,-100};
    this->border2={120,90,100,100};
    
    this->showWireframe=false;
    this->modelPath="assets/models";

}