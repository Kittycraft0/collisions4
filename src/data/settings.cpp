// settings.cpp
#include "settings.h"
// 5/9/2023
// the settings script
// TODO: get settings from a text file or something
#include <string>

//4/5/2023
class Settings{public:
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
    int windowWidth;
    int windowHeight;
    bool showWireframe;
    bool showBoundingBox;
    float maxSimplificationDistance;
    std::string shaderPath;
    std::string texturePath;
};