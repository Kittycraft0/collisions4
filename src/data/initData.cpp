//5/24/2023 don't forget
#include "initdata.h"



//3/23/2023 1:25 PM CST Thursday

// 6/1/2023
// define data constructor
// this is all confusing here but OKAY!!!?
Data::Data(){
    this->settings=new Settings();
    //window=0;
    //sf::RenderWindow* 
    // keyword cool
    // really? wow I can do that on the start as well? ok nice
    this->window=initWindow(this);
    this->modelData=new ModelData(settings->modelPath);
    //initObjects(settings)
    //this->objects=0;
    // 5/11/2023
    for(int i=0;i<settings->numObjects;i++){
        //ObjectNd* obj=new ObjectNd(settings->d);
        // added this-> at 6/5/2023
        //this->objects.push_back(obj);
        this->objects.push_back(new ObjectNd(settings->d,this));
    }
    std::cout<<"\nWindow width from the data constructor: "<<this->settings->windowWidth;
}


// 5/11/2023
void Data::initObjects(int num, int d){
    for(int i=0;i<settings->numObjects;i++){
        ObjectNd* obj=new ObjectNd(d,this);
        // added this-> at 6/5/2023
        this->objects.push_back(obj);
    }
};

void dataTest1(int num){
    std::cout<<num;
}

void Data::dataTest2(int num){
    std::cout<<num;
}