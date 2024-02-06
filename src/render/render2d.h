// 6/5/2023
// render2d.h
#ifndef RENDER_2D
#define RENDER_2D

// no semicolons for includes
#include "../data/initdata.h"
#include "../data/objectnd.h"

// remember this...
#include <SFML/Graphics.hpp>

class Data;

void render2dAsCircles(Data* data);
// squares 6/7/2023
void render2dAsSquares(Data* data);
// colored 2/5/2024
void render2dAsCirclesColoredIndex(Data* data);

#endif //RENDER_2D