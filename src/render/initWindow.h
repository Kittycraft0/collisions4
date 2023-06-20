//5/5/2023 return of the FIFTH!!!

#ifndef INITWINDOW_H
#define INITWINDOW_H

#include <SFML/Graphics.hpp>
//what??? what is even needed here...? not sure...
// classes and methods you FOOL 5/24/2023

// thing
#include "../data/initdata.h"
#include "../src.h"

//chatgpt: add this! oh, the error says it's redundant? thank remove it!
//class Data{
//
//}

// thing that gets filled in later?
// ADD THIS TO EVERYTHING. IT FIXES EVERYTHING.
class Data;

//sf::RenderWindow* initWindow(Data* data);
sf::RenderWindow* initWindow(Data* data);
sf::RenderWindow* initWindow();
sf::RenderWindow* initWindow(std::string name,int width,int height,int x,int y);
// aparently someone thought eggs were dairy

void renderTest1();

#endif //INITWINDIW_H