/*// 5/30/2023
#include <iostream>
//#include "../src"
#include "data/initdata.h"

int main(){
    Data data=new Data();
    std::cout<<3;
}*/

//chatgpt test
#include <iostream>
#include "../../src/data/initdata.h"
#include "../../src/data/modeldata.h"
#include "../../src/data/modelnd.h"
#include "../../src/data/objectnd.h"
#include "../../src/data/settings.h"

int main() {
    // Test the data library
    //initData::initObjects(5);
    //modelData::loadModel("model1");
    //ModelNd* model = modelData::getModel("model1");
    //model->print();

    // Test the objectnd library
    //ObjectNd object(1, 2, 3);
    //ObjectNd object(1, 2, 3);
    //object.move(4, 5, 6);
    //object.print();

    // Test the settings library
    //Settings::setWindowWidth(800);
    //Settings::setWindowHeight(600);
    //std::cout << "Window Width: " << Settings::getWindowWidth() << std::endl;
    //std::cout << "Window Height: " << Settings::getWindowHeight() << std::endl;
    //std::cout << "Window Height: " << Settings::getWindowHeight() << std::endl;
    
    Data* data=new Data();
    std::cout << "THE TEST DID THE THING\n";
    return 0;
}
