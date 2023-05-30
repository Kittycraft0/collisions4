//5/24/2023 don't forget
#include "initdata.h"

//constructed here 4/5/2023
#include <vector>
#include <string>

#include "modeldata.h"
#include "objectnd.h"
#include "settings.h"

//3/23/2023 1:25 PM CST Thursday
//5/8/2023 - Data should be defined like a solid block of data
// ...
// with like tethers to the repeated, 
// multiply-defied (is that even a word? probably not in this context...)
// objects such as the models and rendered objects themselves
/*class Data{
    public:
    ModelData modelData;
    // calling it Object3d because just "Object" may interfere with something
    std::vector<ObjectNd*> objects;
    Settings settings;
    
    // 5/11/2023
    void initObjects(int num){
        for(int i=0;i<settings.numObjects;i++){
            ObjectNd* obj=new ObjectNd();
            objects.push_back(obj);
        }
    };
};*/

// 5/11/2023
void Data::initObjects(int num){
    for(int i=0;i<settings.numObjects;i++){
        ObjectNd* obj=new ObjectNd();
        objects.push_back(obj);
    }
};

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








/*Data initData(){
    Data data;
    return(data);
}*/



















