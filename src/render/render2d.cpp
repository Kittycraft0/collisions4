// 6/5/2023
// render2d.cpp
#include "render.h";

#include "../data/initdata.h";
#include "../data/objectnd.h";

void renderAsCircles(Data* data){
    for(ObjectNd* obj:data->objects){
        sf::RectangleShape sfModel;
        sfModel.setFillColor(sf::Color::Green);
        sfModel.setPosition(sf::Vector2f(obj->p[0],obj->p[1]));
        data->window->draw(sfModel);
    }
}