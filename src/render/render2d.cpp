// 6/5/2023
// render2d.cpp
#include "render2d.h"
// no semicolons after the incldue


void render2dAsCircles(Data* data){
    for(ObjectNd* obj:data->objects){
        sf::RectangleShape sfModel;
        sfModel.setFillColor(sf::Color::Green);
        sfModel.setPosition(sf::Vector2f(obj->p[0],obj->p[1]));
        data->window->draw(sfModel);
        
    }
    // prevent memory leaks???
    //delete data;

    // test
    sf::CircleShape shape(10.f);
    shape.setFillColor(sf::Color::Green);
    shape.move(0,30);
    data->window->draw(shape);
    data->window->clear(sf::Color::White);
    //std::cout<<"spam";
}