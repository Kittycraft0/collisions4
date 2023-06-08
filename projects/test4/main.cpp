// 5/30/2023
#include <iostream>

#include "../../src/src.h"



int main() {
    // Initialize data 6/5/2023
    Data* data=new Data();

    //data->objects[1]->p[0]+=30;
    //data->objects[1]->p[1]+=30;

    std::cout<<"\nsecond object's first coordinate: "<<(data->objects[1]->p[0]);
    std::cout<<"\nsecond object's second coordinate: "<<(data->objects[1]->p[1]);
    std::cout<<"\nnumber of objects: "<<(data->objects.size())<<"\n";

    // what?
    data->window->clear(sf::Color::Black);
    
    // 6/7/2023 start the clock
    double timeMultiplier=1;
    sf::Clock clock;
    
    while (data->window->isOpen())
    {
        sf::Event event;
        while (data->window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                data->window->close();
                //if(!loggedFramerate){
                //    std::cout<<totalFramerate/n;
                //}
            }
            // 6/5/2023
            // no code goes here really
        }

        // 6/7/2023 get deltaTime
        float spf=clock.restart().asSeconds();
        double deltaTime=spf*timeMultiplier;


        // 6/6/2023 Gravity
        for(int i=0;i<data->settings->numObjects;i++){
            for(int j=i+1;j<data->settings->numObjects;j++){
                gravity(data->objects[i],data->objects[j],data->settings->G);
            }
        }

        // 6/7/2023
        // Collisions
        /*for(int i=0;i<data->settings->numObjects;i++){
            for(int j=i+1;j<data->settings->numObjects;j++){
                //float dist=sqrt(pow(2,2)+pow(2,2));

                // copied from graviyMath.cpp at 6/7/2023
                // distance vector
                std::vector<double> dv;
                // squared sum for inverse rooting
                double sqSum=0;
                for(int k=0;k<(data->objects[i])->p.size();k++){
                    dv.push_back((data->objects[j])->p[k]-(data->objects[i])->p[k]);
                    sqSum+=dv.at(k)*dv.at(k);
                }
                double dist=sqrt(sqSum);
                // abs for magnitude is not needed due to squaring
                if(dist<data->objects[i]->radius+data->objects[j]->radius){
                    collide(
                        data->objects[i],
                        data->objects[j],
                        data->settings->restitution,
                        deltaTime
                    );
                }
            }
        }*/


        // 6/6/2023
        // update the object positions!
        for(ObjectNd* obj:data->objects){
            obj->update(deltaTime);
            //std::cout<<"x: "<<obj->p[0]<<" ";
            //std::cout<<"y: "<<obj->p[1]<<" ";
        }




        // Clear the window
        data->window->clear();
        
        // Render the circles
        render2dAsCircles(data);



        // 6/7/2023 Calculate center of mass of systemfd
        std::vector<double> centerOfMass;
        for(int i=0;i<data->objects[0]->p.size();i++){
            centerOfMass.push_back(0);
        }
        for(ObjectNd* obj:data->objects){
            for(int i=0;i<obj->p.size();i++){
                centerOfMass[i]+=obj->p[i];
            }
        }
        for(int i=0;i<centerOfMass.size();i++){
            centerOfMass[i]/=data->objects.size();
        }
        // Draw the center of mass of the system
        // Copied and modified from render/render2d.cpp
        // Initialize the rendered object
        sf::CircleShape com;
        // Set the size
        com.setRadius(10);
        // Set the color
        com.setFillColor(sf::Color::Red);
        // Set the position
        com.setPosition(sf::Vector2f(centerOfMass[0],centerOfMass[1]));
        // Set the origin
        com.setOrigin(
            -(int)data->window->getSize().x/2,
            -(int)data->window->getSize().y/2
        );
        //std::cout<<centerOfMass[0]<<" ";
        // Draw the object
        data->window->draw(com);



        // Display changes
        data->window->display();
    }

    // De-allocate memory, wiping it foreverrrrr
    delete data;

    return(0);
}
