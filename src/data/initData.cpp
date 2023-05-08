//constructed here 4/5/2023
#include <vector>
#include <string>

/*//4/5/2023
class Data{
    private:
    public:
        int yes=0;
};*/

// Some run stuffs

/*//3/23/2023
//finally using tab size 4... thanks code.org for teaching me the wrong way...
struct data{
    struct modelData{
        std::vector<string> modelNames; // model names for easy reference
        std::vector<Model> models; //model struct
    };
};*/

//3/23/2023 1:25 PM CST Thursday
//5/8/2023 - Data should be defined like a solid block of data
// ...
// with like tethers to the repeated, 
// multiply-defied (is that even a word? probably not in this context...)
// objects such as the models and rendered objects themselves
class Data{public:
    ModelData modelData;
    // calling it Object3d because just "Object" may interfere with something
    std::vector<ObjectNd*> objects;
    Settings settings;
};

// 5/8/2023 the object should be a solid block of data
class ObjectNd{public:
    int modelID; // index of model in data.modelData.models
    //position
    std::vector<float> p;
    //velocity
    std::vector<float> v;
    //mass
    float m;
    //the scale, default of one in every dimension
    std::vector<float> scale;
};

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


Data initData(){
    Data data;
    return(data);
}



















