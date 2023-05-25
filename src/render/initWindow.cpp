//4/5/2023
//5/5/2023 wow it's been a month hahahaha...
#include "initWindow.h"

// 5/24/2023
#include <SFML/Graphics.hpp>
#include <string>
#include "../data/initdata.h"

// Method for the lazy
sf::RenderWindow* initWindow(){
    // Get arbitrary values to use
    std::string defaultName="Collisions \"4\"!";
    int defaultWidth=800;
    int defaultHeight=800;
    int defaultX=200;
    int defaultY=200;
    //sf::RenderWindow window(sf::VideoMode(windowSize[0], windowSize[1]), "Collisions \"4\"!", sf::Style::Default);
    //sf::RenderWindow window(sf::VideoMode(defaultWidth,defaultHeight),defaultName,sf::Style::Default);
    sf::RenderWindow* window=initWindow(defaultName,defaultWidth,defaultHeight,defaultX,defaultY);
    return(window);
}
// Remember to round inputs!
sf::RenderWindow* initWindow(std::string name,int width,int height,int x,int y){
    sf::RenderWindow* window=new sf::RenderWindow(sf::VideoMode(width,height),name,sf::Style::Default);
    window->setPosition(sf::Vector2i(x,y));
    return(window);
}

// Using data - generally the best option
sf::RenderWindow* initWindow(Data* data){
    // Get the windows values from data.settings
    std::string defaultName=data->settings.windowName;
    int defaultWidth=data->settings.windowWidth;
    int defaultHeight=data->settings.windowHeight;
    int defaultX=data->settings.windowX;
    int defaultY=data->settings.windowY;

    //int windowWidth=800;
    //int windowHeight=800;
    //int windowX=200;
    //int windowY=200;
    //std::string windowName="Physics simulation";
    
    sf::RenderWindow* window=initWindow(defaultName,defaultWidth,defaultHeight,defaultX,defaultY);
    return(window);
}