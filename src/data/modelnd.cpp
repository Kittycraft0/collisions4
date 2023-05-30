// modelnd.cpp
#include "modelnd.h"
// 5/8/2023 defining the model of n dimensions

// 5/8/2023 was probably defined like 2 months ago from now with everything else
// but now i am just putting here that this should indeed be just a solid block
// of data. just like my 1kg tungsten cube lol
/*class ModelNd{public:
    // list of arbitrary size containing lists of i guess 3 values each
    std::vector<std::vector<float>> points;
    // list of arbitrary size containing lists of arbitrary size with values replresenting indeces in the points list
    std::vector<std::vector<int>> faces;
    // list with each index corresponding to an index in the faces variable
    // ints get 32 bits, so 8 bits to red, green, blue, and alpha
    // why seperate them when their defaults are already out of 255?
    
    //4/5/2023
    // color: red*2^24+green*2^16+blue*2^8+alpha*2^0
    // c=r*2^24+g*2^16+b*2^8+a*2^0;
    // red: first 8 bits: color/(2^24)
    // r=c/2^24;
    // green: second 8 bits:
    // g=mod(c,2^24)/2^16;
    // blue: third 8 bits: 
    // b=mod(c,2^16)/2^8;
    // alpha: fourth 8 bits: 
    // a=mod(c,2^8)
    
    std::vector<int> colors;
};
*/

// check initData.cpp for method implementation? -5/30/2023