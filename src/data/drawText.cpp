// text.cpp
// 11/01/2023
#include "drawText.h"

// 11/01/2023 oh hey here's the final answer i found in objectnd.cpp:
// 6/6/2023 what the why is this REQUIRED IN HERE!?
// IS C++ ON SOMETHING
// Note: it can't be moved to the header file without breaking things.
// And yet the initWindow method worked...? WHY!??
#include "initdata.h"

DrawText::DrawText(Data* data){
    // arbitrary number that seems to look nice
    this->textSize=24;
    this->line=0;
    this->data=data;
}

void DrawText::reset(){
    this->line=0;
}
// 11/01/2023 what
// 11/01/2023 the write method
// (where's the left method?)
void DrawText::write(char temp[256]){
    //data->settings;

    // 11/01/2023 copy pasted from main.cpp
        // 10/11/2023
        // copy/paste from above then modified for my purposes
        // Text on screen
        // energy
        // 4/18/2023 - copy/pasted/modified on 6/23/2023
        // draw the fps text
        sf::Text sfText;
        
        //char temp[256];
        //sprintf(temp, "Total kinetic energy: %d", (int)totalKineticEnergy);
        // llu unsigned long long (int)? cool
        //sprintf(temp, "Total kinetic energy: %lli", (long long int)totalKineticEnergy);
        //sprintf(temp,text);
        sfText.setString(temp);
        sfText.setFont(this->data->fonts->comicMono);
        sfText.setCharacterSize(this->textSize);
        sfText.setFillColor(sf::Color::Red);
        // Set the origin to the right side of the text
        sfText.setOrigin(sfText.getLocalBounds().width,-this->line*this->textSize);
        // Set the position to the right side of the window
        sfText.setPosition(this->data->window->getSize().x, 0);
        this->data->window->draw(sfText);
        
        this->line+=1;
}


/**/