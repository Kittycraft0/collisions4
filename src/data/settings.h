// settings.h
// 5/9/2023 the settings
#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>
#include <vector>

class Settings{
public:
    int d;
    int numObjects;
    int windowWidth;
    int windowHeight;
    //remember the std:: for strings
    int windowX;
    int windowY;
    std::string windowName;
    bool showWireframe;
    bool showBoundingBox;
    float maxSimplificationDistance;
    std::string shaderPath;
    std::string texturePath;
    std::string modelPath;
    double G;
    double restitution;
    double objectSpawnMargin;
    std::vector<double> globalGravity;

    // 6/1/2023
    // constructor
    Settings();

    // 6/23/2023 Long seeds are better maybe??? More options???
    unsigned long long int seed;

    // 10/26/2023 border corner coordinates
    std::vector<int> border1;
    std::vector<int> border2;
};

void dataTest3(int n);

#endif //SETTINGS_H