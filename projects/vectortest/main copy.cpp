// 4/25/2023 - I am now 18! Wow! Not a factorial. Coding at 6:19 PM CST.

//finally works alright! -3/13/2023
//now to finally start coding after, what, 3 months?. finally...
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <random>
#include <cmath>
//#include "../../src/src.h"

struct Obj{
    sf::RectangleShape model;
    //velocity in meters per second or pixels per second
    sf::Vector2f vel;
    //mass in kilograms
    float mass;
};

int main()
{
    // added 6/19/2023
    std::cout<<"RUNNING THE MAIN.CPP OF THE 1!!!\n";
    // added 6/20/2023 to suppress "Failed to set DirectInput device axis mode: 1"
    sf::err().rdbuf(NULL);
    
    // the normal G
    // const double G = 6.67430e-11; // gravitational constant in m^3 kg^-1 s^-2
    // G is arbitrary and can be whatever you want - constants are funny like that
    const double G=1;
    // the coeffecient of restitution!
    float restitution=1;

    // wall sizes
    std::vector<int> walls={0,0,800,500};

    // 5/4/2023
    // window size
    std::vector<int> windowSize={800,800};

    // Initialize the window
    sf::RenderWindow window(sf::VideoMode(windowSize[0], windowSize[1]), "Collisions \"4\"!", sf::Style::Default);
    
    // seconds multiplier, such that this many simulated seconds pass every second
    //currently set to a day -3/14/2023
    //now a week
    //float timeMultiplier=60.f*60.f*24.f*7.f;
    //now one second per every second...
    float timeMultiplier=1;

    // create 10 circles with random positions and velocities
    std::random_device rd;
    std::mt19937 gen(rd());
    //std::uniform_int_distribution<> posDistX(0, window.getSize().x);
    //std::uniform_int_distribution<> posDistY(0, window.getSize().y);
    std::uniform_int_distribution<> posDistX(walls[0], walls[2]);
    std::uniform_int_distribution<> posDistY(walls[1], walls[3]);
    std::uniform_real_distribution<> velDist(-100.f, 100.f);
    int numBalls=50;

    // Initialize squares
    std::vector<Obj> orbs(numBalls);

    //3/14/2023 pi day!
    //for (int i = 0; i < orbs.size(); i++) {
    for(auto& orb : orbs){
        orb.model.setSize(sf::Vector2f(10.f,10.f));
        orb.model.setPosition(sf::Vector2f(posDistX(gen), posDistY(gen)));
        //orb.vel=sf::Vector2f(velDist(gen), velDist(gen));
        //orb.mass=100;
        // number such that there is an acceleration of 1 m/s^2 at a radius of 10
        //orb.mass=149828446430000;
        orb.mass=100;
        orb.vel.x=velDist(gen);
        orb.vel.y=velDist(gen);
        //orb.vel=sf::Vector2f(velDist(gen),velDist(gen));
        //orbs.push_back(sf::RectangleShape());
        //orbs[i].setSize(sf::Vector2f(10.f,10.f));
        //orbs[i].setPosition(sf::Vector2f(posDistX(gen), posDistY(gen)));
        //velocities.push_back(sf::Vector2f(velDist(gen), velDist(gen)));
    }

    sf::CircleShape shape(10.f);
    shape.setFillColor(sf::Color::Green);
    sf::Clock clock;
    int n=0;
    float totalFramerate=0;
    bool loggedFramerate=false;
    float latestTotalEnergy=0;

    // load comic sans
    sf::Font comicSans;
    //why does this need the "../"!? -4/6/2023 thanks stackoverflow... finally...
    if (!comicSans.loadFromFile("../assets/fonts/comicsans.ttf")) {
        // handle error
        std::cout<<"\nNO comicSans FONT :(\n";
    }
    // load monospace comic sans -4/6/2023
    sf::Font comicMono;
    //why does this need the "../"!? -4/6/2023 thanks stackoverflow... finally...
    if (!comicMono.loadFromFile("../assets/fonts/comicmono.ttf")) {
        // handle error
        std::cout<<"\nNO comicMono FONT :(\n";
    }
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
                if(!loggedFramerate){
                    std::cout<<totalFramerate/n;
                }
            }
        }
        //make n go up -4/6/2023
        n+=1;

        float spf=clock.restart().asSeconds();
        float deltaTime=spf*timeMultiplier;
        //std::cout<<1/deltaTime;

        float speed=1.f;
        float movement=deltaTime*speed;
        shape.move(0,speed);
        window.clear();
        
        // calculate orb forces on each other -3/14/2023
        // in newtons -3/14/2023
        // initialize the forces list -4/18/2023
        std::vector<sf::Vector2f> forces;
        for(int i=0;i<orbs.size();i++){
            forces.push_back({0.f,0.f});
        }
        // for every orb
        for(int i=0;i<orbs.size();i++){
            //forces[i];

            // gravity for said orbs
            /*for(int j=i+1;j<orbs.size();j++){
                // get the positions
                sf::Vector2f pos1=orbs[i].model.getPosition();
                sf::Vector2f pos2=orbs[j].model.getPosition();
                //float dist=sqrt(pow(pos1.x-pos2.x,2)+pow(pos1.y-pos2.y,2));
                // get the distance in component values
                float dx=pos1.x-pos2.x;
                float dy=pos1.y-pos2.y;
                // inverted distance squared?
                float invDistSquared=1/(dx*dx+dy*dy);
                // get the distance
                float invDist=fastInvSqrt(dx*dx+dy*dy);
                // newton's gravitational formula thing
                float force=(orbs[i].mass*orbs[j].mass*G)*invDistSquared;//(invDist*invDist);
                // get the component vectors of the forces
                //float fx=dx*invDist*force;
                //float fy=dy*invDist*force;
                sf::Vector2f fg={dx*invDist*force,dy*invDist*force};
                // append the forces to the net forces list
                forces[i]-=fg;
                forces[j]+=fg;
            }*/
            
            // collisions with said orbs -4/18/2023
            for(int j=i+1;j<orbs.size();j++){
                // check if colliding
                // extreme optimizations can and should be made here eventually
                sf::Vector2f oip=orbs[i].model.getPosition();
                sf::Vector2f ojp=orbs[j].model.getPosition();
                //float dx=ojp.x-oip.x;
                //float dy=ojp.y-oip.y;
                // YAY OVERLOADED OPERATORS HAHAHAHAH THE BENIFITS OF C PLUS PLUS AM I RIGHT YESSSS
                sf::Vector2f d=ojp-oip;
                sf::Vector2f sizei=orbs[i].model.getSize();
                sf::Vector2f sizej=orbs[j].model.getSize();
                float maxDistX=sizej.x+sizei.x;
                float maxDistY=sizej.y+sizei.y;
                sf::Vector2f maxDist=sizej+sizei;
                bool xMet=abs(d.x)<abs(maxDist.x);
                bool yMet=abs(d.y)<abs(maxDist.y);
                //bool pMet=abs(d)<abs(maxDist);
                if(xMet&&yMet){
                    Obj oi=orbs[i];
                    Obj oj=orbs[j];
                    // momentums!
                    sf::Vector2f mi=oi.mass*oi.vel;
                    sf::Vector2f mj=oj.mass*oj.vel;
                    // the reciprical of the sums of the two masses
                    float divMass=1/(oi.mass+oj.mass);
                    // calculate the impulse
                    // hHAHAHAHAHA YESSS FOUR LIENS ALL INTO ONE BECAUSE OF VECTOR OVERLOADING YESSS
                    sf::Vector2f impulse=(mi+mj-oj.mass*restitution*(oi.vel-oj.vel))*oi.mass/(oi.mass+oj.mass)-mi;
                    //float impulseY=0;
                    // assume equal and opposite reaction means negative impulse
                    // adjust forces!!!
                    forces[i]+=impulse;
                    forces[j]-=impulse;
                }
            }
//gagh
            // wall collisions -4/19/2023
            Obj oi=orbs[i];
            sf::Vector2f oip=oi.model.getPosition();
            //std::cout<<oip.x<<" ";
            sf::Vector2f wallSize={800,500};
            if(oip.x>wallSize.x||oip.y>wallSize.y||oip.x<0||oip.y<0){
                if(oip.x>walls[2]){
                    forces[i].x-=abs(oi.mass*oi.vel.x*(1+restitution));
                }
                if(oip.x<walls[0]){
                    forces[i].x+=abs(oi.mass*oi.vel.x*(1+restitution));
                }
                if(oip.y>walls[3]){
                    forces[i].y-=abs(oi.mass*oi.vel.y*(1+restitution));
                }
                if(oip.y<walls[1]){
                    forces[i].y+=abs(oi.mass*oi.vel.y*(1+restitution));
                }
            }

        }
        // determine acceleration due to forces and act upon it
        for(int i=0;i<orbs.size();i++){
            //using dampingFactor is basically the 
            //exact same thing as making timeMultiplier 
            //a smaller number - don't use it. If it were used,
            //it would be multiplied to the force added to the velocity.
            //float dampingFactor=0.99f;
            // F=ma
            // F/m=a
            // remember that when applying acceleration to velocity there needs to be
            // a multiplicaton of deltaTime
            // no need to save the acceleration when it just gets immediately added to
            // the velocity and used for like literally nothing else anyways
            orbs[i].vel+=forces[i]/orbs[i].mass*deltaTime;
        }
        
        // for every orb move it by the velocity and render it
        for(auto& orb : orbs){
            //orbs[i].move(velocities[i]*deltaTime);
            orb.model.move(orb.vel*deltaTime);
            window.draw(orb.model);
        }

        // fun experiment -4/6/2023:
        // get total energy!
        float getTotalEnergy=true;
        if(getTotalEnergy){
            float totalEnergy=0;
            for(int i=0;i<orbs.size();i++){
                for(int j=i+1;j<orbs.size();j++){
                    // get the distance
                    float vx=orbs[i].vel.x-orbs[j].vel.x;
                    float vy=orbs[i].vel.y-orbs[j].vel.y;
                    float invV=1/sqrt(vx*vx+vy*vy);
                    //float invV=1/sqrt(vx*vx+vy*vy);
                    float vSquared=1/(vx*vx+vy*vy);
                    
                    // potential energy
                    totalEnergy+=G*(orbs[i].mass+orbs[j].mass)*invV;
                    
                    // kinetic energy
                    // reference frame is world
                    //totalEnergy+=0.5*(orbs[i].mass+orbs[j].mass)*vSquared;
                }
            }
            latestTotalEnergy=totalEnergy;
            //std::cout<<n<<" ";
            //std::cout<<n%60<<" ";
            /*if(n%60==1){
                std::cout<<totalEnergy<<" ";

                
            }*/
        }
        sf::Text energyText;

        //if (!energyText.loadFromFile("arial.ttf")){
        //    // error...
        //}
        //
        // from https://en.sfml-dev.org/forums/index.php?topic=7561.0
        // -4/6/2023
        char temp[256];
        sprintf(temp, "%f", latestTotalEnergy);
        energyText.setString(temp);
        energyText.setFont(comicMono);
        energyText.setCharacterSize(24);
        energyText.setFillColor(sf::Color::Red);
        //
        // right align text from ChatGPT -4/6/2023
        // Set the origin to the right side of the text
        energyText.setOrigin(energyText.getLocalBounds().width, 0);
        //
        // Set the position to the right side of the window
        energyText.setPosition(window.getSize().x, 0);
        //
        // draw the text!
        window.draw(energyText);

        // 4/18/2023
        // draw the fps text
        sf::Text fpsText;
        
        //temp[256];RedRed
        sprintf(temp, "%f", 1/spf);
        fpsText.setString(temp);
        fpsText.setFont(comicMono);
        fpsText.setCharacterSize(24);
        fpsText.setFillColor(sf::Color::Red);
        // right align text from ChatGPT -4/6/2023
        // Set the origin to the right side of the text
        fpsText.setOrigin(fpsText.getLocalBounds().width,-24);
        // Set the position to the right side of the window
        fpsText.setPosition(window.getSize().x, 0);
        window.draw(fpsText);

        //draw the window!
        window.draw(shape);
        window.display();
        totalFramerate+=1/spf;
        n++;
    }

    return 0;
}


