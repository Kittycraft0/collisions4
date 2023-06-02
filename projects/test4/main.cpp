// 5/30/2023
#include <iostream>
//#include "../../src/data/initdata.h"
//#include "../../src/data/modeldata.h"
//#include "../../src/data/modelnd.h"
//#include "../../src/data/objectnd.h"
//#include "../../src/data/settings.h"
#include "../../src/src.h"
//#include "../../src/render/initWindow.h"

int main() {
    Data* data=new Data();

    data->initObjects(7);
    //sf::RenderWindow* window=initWindow(data);

    while (data->window.isOpen())
    {
        sf::Event event;
        while (data->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                data->window.close();
                //if(!loggedFramerate){
                //    std::cout<<totalFramerate/n;
                //}
            }

            
        }
    }
    return(0);
}
