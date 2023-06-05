// 5/30/2023
#include <iostream>
//#include "../../src/data/initdata.h"
//#include "../../src/data/modeldata.h"
//#include "../../src/data/modelnd.h"
//#include "../../src/data/objectnd.h"
//#include "../../src/data/settings.h"
#include "../../src/src.h"
//#include "../../src/render/initWindow.h"

#include <SFML/Graphics.hpp>


int main() {
    Data* data=new Data();

    //data->initObjects(7, 2);
    //sf::RenderWindow* window=initWindow(data);
    //system.out.println("this isn't java");
    // hey my first "Segmenation fault (core dumped)"
    std::cout<<"\nsecond object's first coordinate: "<<(data->objects[1]->p[0]);
    std::cout<<"\nsecond object's second coordinate: "<<(data->objects[1]->p[1]);
    std::cout<<"\nnumber of objects: "<<(data->objects.size())<<"\n";

    // ok the window can be accessed nice
    data->window->setTitle("Changed window!");
    // what?
    data->window->clear(sf::Color::White);
    

    
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
        // watch out for memory leaks!
        //render2dAsCircles(data);

        // chatgpt 6/5/2023
        // Create a rectangle shape
        sf::RectangleShape rectangle(sf::Vector2f(200, 100));
        rectangle.setFillColor(sf::Color::Red);
        rectangle.setPosition(300, 250);
        data->window->draw(rectangle);

        // oh it needs this ok... bye bye 30 minutes!
        data->window->display();
    }

    // thanks for the reminder, ChatGPT
    delete data;

    return(0);
}
