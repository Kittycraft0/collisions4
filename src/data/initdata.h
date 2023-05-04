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

class ModelData;
class Object3d;
class Model;
class Settings;

class Data{
public:
    ModelData modelData;
    std::vector<Object3d> objects;
    Settings settings;
};

class ModelData{
public:
    std::vector<std::string> modelNames;
    std::vector<Model> models;
};

class Object3d{
public:
    int modelID;
    std::vector<float> p;
    std::vector<float> v;
    float m;
    std::vector<float> scale;
};

class Model{
public:
    std::vector<std::vector<float>> points;
    std::vector<std::vector<int>> faces;
    std::vector<int> colors;
};

class Settings{
public:
    int windowWidth;
    int windowHeight;
    bool showWireframe;
    bool showBoundingBox;
    float maxSimplificationDistance;
    std::string shaderPath;
    std::string texturePath;
};

Data initData();

#endif
