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
    //data->objects[0]->v[0]=0;
    //data->objects[1]->v[0]=0;

    std::cout<<"\nObject positions:\n";
    // 6/23/2023
    for(ObjectNd* obj:data->objects){
        std::cout<<obj->p[0]<<", ";
        std::cout<<obj->p[1]<<"\n";
    }

    //data->objects[1]->p[0]+=30;
    //data->objects[1]->p[1]+=30;
    std::cout<<"object 0 initial velociy: "<<data->objects[0]->v[0];

    std::cout<<"\nStarted!";

    // what?
    data->window->clear(sf::Color::Black);
    
    // 6/7/2023 start the clock
    double timeMultiplier=data->settings->timeMultiplier;
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
        bool doGravity=true;
        bool doSeparateOrbs=true;
        bool doCollide=true;
        bool doWallCollide=true;
        bool forceDeltaTime=false;
        //double forcedDeltaTime=0.01666f;
        double forcedDeltaTime=0.01f;

        // 6/7/2023 get deltaTime
        float spf=data->clock->restart().asSeconds();
        double deltaTime=spf*timeMultiplier;
        //std::cout<<spf;
        if(forceDeltaTime){
            deltaTime=forcedDeltaTime*timeMultiplier;
        }

        // 10/25/2023
        if(doGlobalGravity){
            for(int i=0;i<data->objects.size();i++){
                for(int j=0;j<data->objects[i]->p.size();j++){
                    // acceleration of 1 "meter" per second squared?
                    // 10/26/2023 mathematically, L=-1*m*g*t
                    //data->objects[i]->linImp[j]+=
                    //    //-1 // -1 //no just have it negative in settings
                    //    data->objects[i]->m // m
                    //    *data->settings->globalGravity[j] // g
                    //    *deltaTime; // t
                    // 11/01/2023 - mathematically, F=ma --> F=mg
                    data->objects[i]->linForce[j]+=
                        data->objects[i]->m // m
                        *data->settings->globalGravity[j]; // g
                    
                }
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
                    data->settings->border2,data->settings->globalGravity,
                    data->settings->wallRestitution);
            }
        }

        // 10/26/2023
        if(doSeparateOrbs){
            // Separate the orbs
            // Does not conserve energy (or does it somehow???); how would one even do that anyways?
            // 10/31/2023 OHH IT CONSERVES ENERGY BECAUSE ENERGY OF THE CENTER OF MASS REMAINS CONSTANT
            // THAT'S WHY I GOT THE CENTER OF MASS EQUATION FROM THE POTENTIAL ENERGY EQUATIONS
            // OHHHHH SO I AM ALREADY DOING IT CORRECTLY THAT IS GOOD.
            // Separate the two while presering the location of the center of mass
            // 10/27/2023
            // For every object pair
            for(int i=0;i<data->objects.size();i++){
                for(int j=i+1;j<data->objects.size();j++){

                // 10/31/2023 copied from below collisions check
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
                        separateOrbs(data->objects[i],data->objects[j]);
                    }
                }
            }
        }
        
        // 6/6/2023 Gravity
        if(doGravity)
        for(int i=0;i<data->settings->numObjects;i++){
            for(int j=i+1;j<data->settings->numObjects;j++){
                gravity2(data->objects[i],data->objects[j],data->settings->G);
            }
        }

        // 6/7/2023
        // Collisions
        if(doCollide){
        for(int i=0;i<data->objects.size();i++){
            //data->objects[i]->linDisp[0]+=1;
            for(int j=i+1;j<data->objects.size();j++){
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
                    //separateOrbs(data->objects[i],data->objects[j]);
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
        }

        // 6/6/2023
        // update the object positions!
        for(ObjectNd* obj:data->objects){
            obj->update(deltaTime);
        }

        // 2/5/2024 - correct the object velocities
        //correctVelocities(data->objects,data->settings->G);



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
        // radius of com circle
        int comRadius=3;
        // Set the size
        com.setRadius(comRadius);
        // Set the color
        com.setFillColor(sf::Color::Red);
        // Set the position
        com.setPosition(sf::Vector2f(centerOfMass[0]-comRadius,-centerOfMass[1]-comRadius));
        // Set the origin
        com.setOrigin(
            -(int)data->window->getSize().x/2,
            -(int)data->window->getSize().y/2
        );
        //std::cout<<centerOfMass[0]<<" ";
        // Draw the object
        data->window->draw(com);



        
        // 10/11/2023
        // Calculate the total energy in the system
        double totalKineticEnergy=0;
        double totalGlobalPotentialEnergy=0;
        double totalOrbToOrbPotentialEnergy=0; //oh noo not the potition what is a potition
        for(int i=0;i<data->objects.size();i++){
            // Calculate the kinetic energy
            double speedSquared=0;
            for(int j=0;j<data->objects[i]->v.size();j++){
                speedSquared+=data->objects[i]->v[j]*data->objects[i]->v[j];
            }
            totalKineticEnergy+=0.5*data->objects[i]->m*speedSquared;
            // Calculate the global gravitational potential energy
            if(doGlobalGravity){
                for(int j=0;j<data->objects[i]->p.size();j++){
                    // m*g*h
                    totalGlobalPotentialEnergy+=
                        -1* // gravity is negative or something (AS IN THE ORIGINAL EQUATION)
                        data->objects[i]->m // m
                        *data->settings->globalGravity[j] // g
                        *(data->objects[i]->p[j]
                        -data->settings->border1[j]-data->objects[i]->radius); // h from hitting ground
                }
            }
            // orb-to-orb gravity
            if(doGravity){
                // for every object-on-object interaction
                for(int j=i+1;j<data->objects.size();j++){
                    double componentDistSumSquared=0;
                    for(int k=0;k<data->objects[i]->p.size();k++){
                        //std::cout<<k;
                        //std::cout<<data->objects[j]->p[k];
                        // x2-x1
                        double componentDist=data->objects[j]->p[k]-data->objects[i]->p[k];
                        // (x2-x1)^2
                        componentDistSumSquared+=componentDist*componentDist;
                        //std::cout<<componentDist;
                        //std::cout<<" "<<componentDistSumSquared;
                    }
                    //don't do int...
                    //DON'T DO INT
                    // get the inverse distance
                    double invDist=invSqrt(componentDistSumSquared);
                    //std::cout<<invDist;
                    //double invDist=1/sqrt(
                    //    (data->objects[j]->p[0]-data->objects[i]->p[0])*
                    //    (data->objects[j]->p[0]-data->objects[i]->p[0])+
                    //    (data->objects[j]->p[1]-data->objects[i]->p[1])*
                    //    (data->objects[j]->p[1]-data->objects[i]->p[1]));

                    // U sub G = G*m1*m2/r
                    totalOrbToOrbPotentialEnergy+=
                        -1 // NEGATIVE ONE (as is in the ORIGINAL EQUATION)
                        *data->settings->G // G
                        *data->objects[i]->m // *m1
                        *data->objects[j]->m // *m2
                        *invDist; // /r
                    //std::cout<<" invDist: "<<invDist;
                    //std::cout<<" total orb potential energy: "<<totalOrbToOrbPotentialEnergy;
                    //std::cout<<" "<<data->settings->G;
                }
            }
        }
        //std::cout<<" total orb potential energy: "<<totalOrbToOrbPotentialEnergy;
        
        
        data->drawText->reset();

        
        // Text on screen
        // FPS
        // 4/18/2023 - copy/pasted/modified on 6/23/2023
        // draw the fps text
        
        char temp[256];
        //temp[256];RedRed
        sprintf(temp, "FPS: %f", (1/spf));
        data->drawText->write(temp);
        
        


        // total energy
        //unsigned long long int tke=(unsigned long long int)totalKineticEnergy;
        //unsigned long long int tpe=(unsigned long long int)totalPotentialEnergy;
        //unsigned long long int te=tke+tpe;
        long long int totalEnergy=
            (long long int)totalKineticEnergy
            +(long long int)totalGlobalPotentialEnergy
            +(long long int)totalOrbToOrbPotentialEnergy;
        sprintf(temp, "Total energy: %lli", totalEnergy);
        data->drawText->write(temp);
        
        // 2/2/2024 - see if the new method as of 2/2/2024 works idk
        double totalPotentialEnergy1=0;
        double totalKineticEnergy1=0;
        for(int i=0;i<data->objects.size();i++){
            setEnergy(data->objects[i],data->objects,data->settings->G);
            totalPotentialEnergy1+=data->objects[i]->lastPotentialEnergy;
            totalKineticEnergy1+=data->objects[i]->lastKineticEnergy;
        }
        long long int totalEnergy1=
            (long long int)totalKineticEnergy1
            +(long long int)totalPotentialEnergy1/2;
        
        // 10/26/2023
        // draw potential energy text and total energy text
        // potential global gravitational energy
        sprintf(temp, "Total global potential energy0: %lli", (long long int)totalGlobalPotentialEnergy);
        data->drawText->write(temp);
        
        // 2/5/2024 what
        sprintf(temp, "Total potential energy0: %lli", (long long int)totalOrbToOrbPotentialEnergy);
        data->drawText->write(temp);
        // why does it need to be half?
        sprintf(temp, "Total Potential Energy1: %lli", (long long int)totalPotentialEnergy1/2);
        data->drawText->write(temp);
        
        // 10/11/2023 copy/paste from above then modified for my purposes
        // 4/18/2023 - copy/pasted/modified on 6/23/2023
        // llu unsigned long long (int)? cool
        
        sprintf(temp, "Total kinetic energy0: %lli", (long long int)totalKineticEnergy);
        data->drawText->write(temp);
        sprintf(temp, "Total Kinetic Energy1: %lli", (long long int)totalKineticEnergy1);
        data->drawText->write(temp);
        
        // 11/01/2023
        // potential orb-to-orb gravitational potential energy text
        //sprintf(temp, "Total orb potential energy0: %lli", (long long int)totalOrbToOrbPotentialEnergy);
        //data->drawText->write(temp);
        // 2/5/2024
        sprintf(temp, "Total energy0: %lli", totalEnergy);
        data->drawText->write(temp);
        sprintf(temp, "Total energy1: %lli", totalEnergy1);
        data->drawText->write(temp);

        // n.
        n++;

        // Display changes
        data->window->display();
    }

    // De-allocate memory, wiping it foreverrrrr
    delete data;
    // 2/2/2024 while it was obvious at the time of writing
    // and it is obvious when you look at it
    // and this is ruining the above's joke,
    // the above could be replaced with something that saves
    // the contents of the data object to a file
    // so the data could be loaded later
    // so you could continue where you left off
    // but i really just wanted to put a date around here
    // but even though the above was probably made like back around 5/??/2023
    // and i'm stretching this joke too far
    // and with the double first word line pair things here

    return(0);
}
