// 5/30/2023
#include <iostream>

#include "../../src/src.h"



int main() {
    
    // added 6/23/2023 to suppress "Failed to set DirectInput device axis mode: 1"
    sf::err().rdbuf(NULL);

    // Initialize data 6/5/2023
    Data* data=new Data();
    
    // TESTING - REMOVE LATER PLEASE - 10/25/2023
    //data->objects[0]->p[0]=20;
    //data->objects[1]->p[0]=-20;
    //data->objects[0]->v[0]=-5;
    //data->objects[1]->v[0]=5;

    std::cout<<"\nObject positions:\n";
    // 6/23/2023
    for(ObjectNd* obj:data->objects){
        std::cout<<obj->p[0]<<", ";
        std::cout<<obj->p[1]<<"\n";
    }

    //data->objects[1]->p[0]+=30;
    //data->objects[1]->p[1]+=30;

    std::cout<<"\nStarted!";

    // what?
    data->window->clear(sf::Color::Black);
    
    // 6/7/2023 start the clock
    double timeMultiplier=1;
    // 6/23/2023 - now in data
    //sf::Clock clock;
    
    // 6/8/2023 n
    int n=0;
    
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

        bool doGlobalGravity=true;
        bool doMove=false;
        bool doGravity=false;
        bool doCollide=true;
        bool doWallCollide=true;

        // 6/7/2023 get deltaTime
        float spf=data->clock->restart().asSeconds();
        double deltaTime=spf*timeMultiplier;

        // 10/25/2023
        if(doGlobalGravity){
            for(int i=0;i<data->objects.size();i++){
                // acceleration of 1 "meter" per second squared?
                // 10/26/2023 mathematically, L=-1*m*g*t
                data->objects[i]->linImp[1]+=
                    -1 // -1
                    *data->objects[i]->m // m
                    *data->settings->globalGravity // g
                    *deltaTime; // t
            }
        }

        // 6/6/2023 Gravity
        if(doGravity)
        for(int i=0;i<data->settings->numObjects;i++){
            for(int j=i+1;j<data->settings->numObjects;j++){
                gravity(data->objects[i],data->objects[j],data->settings->G);
            }
        }

        // 6/8/2023 test of the rendering speed
        if(doMove)
        if(n==1){
            for(ObjectNd* obj:data->objects){
                for(int i=0;i<obj->v.size();i++){
                    obj->v[i]+=10;
                }
            }
        }
        
        // 9/5/2023
        // Wall collisions
        if(doWallCollide){
            for(ObjectNd* obj:data->objects){
                //wallCollide(obj,data->settings->windowWidth,data->settings->windowHeight);
                wallCollide(obj,data->settings->border1,
                    data->settings->border2,data->settings->globalGravity);
            }
        }

        // 6/7/2023
        // Collisions
        if(doCollide)
        for(int i=0;i<data->settings->numObjects;i++){
            //data->objects[i]->linDisp[0]+=1;
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
                    //std::cout<<"Collision between "<<i<<" and "<<j<<"\n";
                    collide4(
                        data->objects[i],
                        data->objects[j],
                        data->settings->restitution,
                        deltaTime
                    );
                }else{
                    //std::cout<<"nope";
                }
            }
        }

        // 6/6/2023
        // update the object positions!
        for(ObjectNd* obj:data->objects){
            obj->update(deltaTime);
        }




        // Clear the window
        data->window->clear();
        
        // Render the circles
        render2dAsCircles(data);
        //render2dAsSquares(data);



        // 6/7/2023 Calculate center of mass of the system*?
        std::vector<double> centerOfMass;
        double totalMass=0;
        for(int i=0;i<data->objects[0]->p.size();i++){
            centerOfMass.push_back(0);
        }
        for(ObjectNd* obj:data->objects){
            for(int i=0;i<obj->p.size();i++){
                centerOfMass[i]+=obj->p[i]*obj->m;
            }
            // 6/8/2023 - last day of school - remember its just m!
            totalMass+=obj->m;
        }
        for(int i=0;i<centerOfMass.size();i++){
            centerOfMass[i]/=totalMass;
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
        com.setPosition(sf::Vector2f(centerOfMass[0],-centerOfMass[1]));
        // Set the origin
        com.setOrigin(
            -(int)data->window->getSize().x/2,
            -(int)data->window->getSize().y/2
        );
        //std::cout<<centerOfMass[0]<<" ";
        // Draw the object
        data->window->draw(com);






        // Text on screen
        // FPS
        // 4/18/2023 - copy/pasted/modified on 6/23/2023
        // draw the fps text
        sf::Text fpsText;
        
        char temp[256];
        //temp[256];RedRed
        sprintf(temp, "%f", 1/spf);
        fpsText.setString(temp);
        fpsText.setFont(data->fonts->comicMono);
        fpsText.setCharacterSize(24);
        fpsText.setFillColor(sf::Color::Red);
        // right align text from ChatGPT -4/6/2023
        // Set the origin to the right side of the text
        fpsText.setOrigin(fpsText.getLocalBounds().width,-24);
        // Set the position to the right side of the window
        fpsText.setPosition(data->window->getSize().x, 0);
        data->window->draw(fpsText);

        // 10/11/2023
        // Calculate the total energy in the system
        double totalKineticEnergy=0;
        double totalPotentialEnergy=0;
        for(int i=0;i<data->objects.size();i++){
            double speedSquared=0;
            for(int j=0;j<data->objects[i]->v.size();j++){
                speedSquared+=data->objects[i]->v[j]*data->objects[i]->v[j];
            }
            totalKineticEnergy+=0.5*data->objects[i]->m*speedSquared;
            if(doGlobalGravity){
                // m*g*h
                totalPotentialEnergy+=
                    data->objects[i]->m // m
                    *data->settings->globalGravity // g
                    *(data->objects[i]->p[1]
                    -data->settings->border1[1]-data->objects[i]->radius); // h from hitting ground
                //std::cout
                //    <<"Object y: "<<data->objects[1]->p[1]
                //    <<"\nBorder2 position: "<<data->settings->border1[1]<<"\n";
            }
        }
        // 10/11/2023
        // copy/paste from above then modified for my purposes
        // Text on screen
        // energy
        // 4/18/2023 - copy/pasted/modified on 6/23/2023
        // draw the fps text
        sf::Text energyText;
        //sprintf(temp, "Total kinetic energy: %d", (int)totalKineticEnergy);
        // llu unsigned long long (int)? cool
        sprintf(temp, "Total kinetic energy: %llu", (unsigned long long int)totalKineticEnergy);
        energyText.setString(temp);
        energyText.setFont(data->fonts->comicMono);
        energyText.setCharacterSize(24);
        energyText.setFillColor(sf::Color::Red);
        // Set the origin to the right side of the text
        energyText.setOrigin(energyText.getLocalBounds().width,-48);
        // Set the position to the right side of the window
        energyText.setPosition(data->window->getSize().x, 0);
        data->window->draw(energyText);

        // 10/26/2023
        // draw potential energy text and total energy text
        // potential global gravitational energy
        sprintf(temp, "Total potential energy: %llu", (unsigned long long int)totalPotentialEnergy);
        sf::Text potentialEnergyText;
        potentialEnergyText.setString(temp);
        potentialEnergyText.setFont(data->fonts->comicMono);
        potentialEnergyText.setCharacterSize(24);
        potentialEnergyText.setFillColor(sf::Color::Red);
        // Set the origin to the right side of the text
        potentialEnergyText.setOrigin(potentialEnergyText.getLocalBounds().width,-72);
        // Set the position to the right side of the window
        potentialEnergyText.setPosition(data->window->getSize().x, 0);
        data->window->draw(potentialEnergyText);
        // total energy
        //unsigned long long int tke=(unsigned long long int)totalKineticEnergy;
        //unsigned long long int tpe=(unsigned long long int)totalPotentialEnergy;
        //unsigned long long int te=tke+tpe;
        unsigned long long int totalEnergy=
            (unsigned long long int)totalKineticEnergy
            +(unsigned long long int)totalPotentialEnergy;
        sprintf(temp, "Total energy: %llu", totalEnergy);
        sf::Text totalEnergyText;
        totalEnergyText.setString(temp);
        totalEnergyText.setFont(data->fonts->comicMono);
        totalEnergyText.setCharacterSize(24);
        totalEnergyText.setFillColor(sf::Color::Red);
        // Set the origin to the right side of the text
        totalEnergyText.setOrigin(totalEnergyText.getLocalBounds().width,-96);
        // Set the position to the right side of the window
        totalEnergyText.setPosition(data->window->getSize().x, 0);
        data->window->draw(totalEnergyText);

        // n.
        n++;

        // Display changes
        data->window->display();
    }

    // De-allocate memory, wiping it foreverrrrr
    delete data;

    return(0);
}
