//5/5/2023 return of the FIFTH!!!

#ifndef INITWINDOW_H
#define INITWINDOW_H

#include <SFML/Graphics.hpp>
//what??? what is even needed here...? not sure...
// classes and methods you FOOL 5/24/2023

// thing
#include "../data/initdata.h"

sf::RenderWindow* initWindow();
sf::RenderWindow* initWindow(std::string name,int width,int height,int x,int y);
sf::RenderWindow* initWindow(Data* data);
// aparently someone thought eggs were dairy

void renderTest1();

#endif //INITWINDIW_H