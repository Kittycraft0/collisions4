// settings.h
// 5/9/2023 the settings
#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

class Settings{
public:
    int windowWidth;
    int windowHeight;
    //remember the std:: for strings
    int windowX;
    int windowY;
    std::string windowName;
    std::string windowName;
    bool showWireframe;
    bool showBoundingBox;
    float maxSimplificationDistance;
    std::string shaderPath;
    std::string texturePath;
    int numObjects;
};


#endif //SETTINGS_H