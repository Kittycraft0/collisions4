// 6/5/2023
// render2d.cpp
#include "render2d.h"

// 6/5/2023
// Render all of the objects as circles regardless of model
void render2dAsCircles(Data* data){
    // For every object
    for(ObjectNd* obj:data->objects){
        // Initialize the rendered object
        sf::RectangleShape sfModel;
        // Set the size
        sfModel.setSize(sf::Vector2f(10.f,10.f));
        // Set the color
        sfModel.setFillColor(sf::Color::Green);
        // Set the position
        sfModel.setPosition(sf::Vector2f(obj->p[0],obj->p[1]));
        // Set the origin
        sfModel.setOrigin(
            -(int)data->window->getSize().x/2,
            -(int)data->window->getSize().y/2
        );
        // Draw the object
        data->window->draw(sfModel);
    }
}