// text.h
// 11/01/2023

#ifndef TEXT_H
#define TEXT_H

//#include <string>


// incldue the sfml graphics of course
#include <SFML/Graphics.hpp>

//#include "data.h"
// oh hey i found a nice note in objectnd.h:
// Data class - NO INCLUDE STATEMENT FOR DATA, JUST ONLY THIS
class Data;

// class for drawing text so i don't spam my main function with like literally the exact same thing
// over and over again
class DrawText{
public:
    int textSize;
    int line;
    Data* data;
    DrawText(Data* data);
    void write(char temp[256]);
    void reset();

};

#endif //TEXT_H