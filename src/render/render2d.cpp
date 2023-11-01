// 6/5/2023
// render2d.cpp
#include "render2d.h"

// 6/5/2023
// Render all of the objects as circles regardless of model
void render2dAsCircles(Data* data){
    // For every object
    for(ObjectNd* obj:data->objects){
        // Initialize the rendered object
        sf::CircleShape sfModel;
        // Set the size
        sfModel.setRadius(obj->radius);
        // Set the color//9/6/2023 the word "color" looks weird now, why so many 'o's
        sf::Color color=sf::Color(0,255,255*obj->m/5);
        //sfModel.setFillColor(sf::Color::Green);
        sfModel.setFillColor(color);
        // Set the position
        //sfModel.setPosition(sf::Vector2f(obj->p[0]-obj->radius,-(obj->p[1]-obj->radius)));
        sfModel.setPosition(sf::Vector2f(obj->p[0]-obj->radius,-obj->p[1]-obj->radius));
        // Set the origin
        sfModel.setOrigin(
            -(int)data->window->getSize().x/2,
            -(int)data->window->getSize().y/2
        );
        // Draw the object
        data->window->draw(sfModel);
    }
}

// 6/7/2023 same as before but now with squares instead of circles
void render2dAsSquares(Data* data){
    // For every object
    for(ObjectNd* obj:data->objects){
        // Initialize the rendered object
        sf::RectangleShape sfModel;
        // Set the size
        sfModel.setSize(sf::Vector2f(2.f,2.f));
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