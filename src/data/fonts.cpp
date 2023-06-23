
// 6/23/2023
// fonts.cpp
#include "fonts.h"


Fonts::Fonts(){
    // 6/23/2023 - copy pasted from test1's main.cpp

    // load comic sans
    sf::Font comicSans;
    //why does this need the "../"!? -4/6/2023 thanks stackoverflow... finally...
    if (!comicSans.loadFromFile("../assets/fonts/comicsans.ttf")) {
        // handle error
        std::cout<<"\nNO comicSans FONT :(\n";
    }
    this->comicSans=comicSans;

    // load monospace comic sans -4/6/2023
    sf::Font comicMono;
    //why does this need the "../"!? -4/6/2023 thanks stackoverflow... finally...
    if (!comicMono.loadFromFile("../assets/fonts/comicmono.ttf")) {
        // handle error
        std::cout<<"\nNO comicMono FONT :(\n";
    }
    this->comicMono=comicMono;
}