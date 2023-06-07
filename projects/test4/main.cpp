// 5/30/2023
#include <iostream>

#include "../../src/src.h"



int main() {
    // Initialize data 6/5/2023
    Data* data=new Data();

    //data->objects[1]->p[0]+=30;
    //data->objects[1]->p[1]+=30;

    std::cout<<"\nsecond object's first coordinate: "<<(data->objects[1]->p[0]);
    std::cout<<"\nsecond object's second coordinate: "<<(data->objects[1]->p[1]);
    std::cout<<"\nnumber of objects: "<<(data->objects.size())<<"\n";

    // what?
    data->window->clear(sf::Color::Black);
    
    // 6/7/2023 start the clock
    double timeMultiplier=1;
    sf::Clock clock;
    
    while (data->window->isOpen())
    {
        sf::Event event;
        while (data->window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                data->window->close();
                //if(!loggedFramerate){
                //    std::cout<<totalFramerate/n;
                //}
            }
            // 6/5/2023
            // no code goes here really
        }

        // 6/7/2023 get deltaTime
        float spf=clock.restart().asSeconds();
        double deltaTime=spf*timeMultiplier;

        std::cout<<"deltaTime: "<<deltaTime<<" ";

        // 6/6/2023 Gravity
        for(int i=0;i<data->settings->numObjects;i++){
            for(int j=i+1;j<data->settings->numObjects;j++){
                gravity(data->objects[i],data->objects[j],data->settings->G);
            }
        }


        // 6/6/2023
        // update the object positions!
        for(ObjectNd* obj:data->objects){
            obj->update(deltaTime);
            //std::cout<<"x: "<<obj->p[0]<<" ";
            //std::cout<<"y: "<<obj->p[1]<<" ";
        }


        // Clear the window
        data->window->clear();
        
        // Render the circles
        render2dAsCircles(data);

        // Display changes
        data->window->display();
    }

    // De-allocate memory, wiping it foreverrrrr
    delete data;

    return(0);
}
