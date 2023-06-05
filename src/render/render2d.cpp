// 6/5/2023
// render2d.cpp
#include "render2d.h"
// no semicolons after the incldue

// 6/5/2023
// render all of the objects as circles regardless of model
void render2dAsCircles(Data* data){
    for(ObjectNd* obj:data->objects){
        sf::RectangleShape sfModel;
        sfModel.setSize(sf::Vector2f(10.f,10.f));
        sfModel.setFillColor(sf::Color::Green);
        sfModel.setPosition(sf::Vector2f(obj->p[0],obj->p[1]));
        //sfModel.setOrigin(-(data->window->getSize().x)/64,0);
        //std::cout<<data->window->getSize().x;
        // wow an unsigned int divided by a negative number is 0 
        // weird but interesting i guess
        //std::cout<<(data->window->getSize().x)/(-2)<<" ";
        //std::cout<<((int)data->window->getSize().x)/(-2)<<" ";
        //sfModel.setOrigin(-100,0);
        sfModel.setOrigin(
            -(int)data->window->getSize().x/2,
            -(int)data->window->getSize().y/2
        );
        data->window->draw(sfModel);
        
        
    }
    // prevent memory leaks???
    //delete data;
    // hahaha no that causes a seg fault!
}