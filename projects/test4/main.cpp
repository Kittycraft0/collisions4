// 5/30/2023
#include <iostream>

#include "../../src/src.h"



int main() {
    // Initialize data 6/5/2023
    Data* data=new Data();

    data->objects[1]->p[0]+=30;
    data->objects[1]->p[1]+=30;

    std::cout<<"\nsecond object's first coordinate: "<<(data->objects[1]->p[0]);
    std::cout<<"\nsecond object's second coordinate: "<<(data->objects[1]->p[1]);
    std::cout<<"\nnumber of objects: "<<(data->objects.size())<<"\n";

    // what?
    data->window->clear(sf::Color::Black);
    

    
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

        // chatgpt 6/5/2023
        // Create a rectangle shape
        sf::RectangleShape rectangle(sf::Vector2f(200, 100));
        rectangle.setFillColor(sf::Color::Red);
        rectangle.setPosition(300, 250);
        data->window->draw(rectangle);


        // Render the circles
        render2dAsCircles(data);

        // Display changes
        data->window->display();
    }

    // De-allocate memory, wiping it foreverrrrr
    delete data;

    return(0);
}
