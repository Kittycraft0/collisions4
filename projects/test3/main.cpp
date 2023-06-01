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
    std::cout << "THE TEST DID THE THING!!!?...\n";
    //sf::RenderWindow* window=initWindow();
    //sf::RenderWindow* window=initWindow(data);
    //printANumberNow();
    //sf::RenderWindow* window = initWindow();
    //giveMeANumberNow();
    mathTest1(3);
    data->dataTest2(7);
    std::cout<<"The inverse square root of 5 is "<<invSqrt(5.0f)<<"\n";
    mathTest2(3);
    dataTest1(3);
    mathTest2(4);
    //why did it just start working? alright... well thanks???
    //The below works...
    //printTheNumberRightNowww(2013);
    //somethingggnoww(7);
    //What
    dataTest3(60606060);
    // wow ok long int man
    gameTest1(70798613);

    //YESSS!!! I WAS MISSING A LINE...
    renderTest1();

    data->initObjects(7);
    sf::RenderWindow* window=initWindow();

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window->close();
                //if(!loggedFramerate){
                //    std::cout<<totalFramerate/n;
                //}
            }
        }
    }
    return(0);
}
