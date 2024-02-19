// gravityMath.cpp
#include "gravitymath.h"
// 5/11/2023
#include "invsqrt.h"
#include <vector>

void gravity(ObjectNd* obj1, ObjectNd* obj2, double G){
    // distance vector
    std::vector<double> dv;
    // squared sum for inverse rooting
    double sqSum=0;
    for(int i=0;i<obj1->p.size();i++){
        dv.push_back(obj2->p[i]+obj2->linDisp[i]-obj1->p[i]-obj1->linDisp[i]);
        sqSum+=dv[i]*dv[i];
    }
    
    if(sqSum!=0){
    // Inverted root of the sum of the d's squared
        double d=invSqrt(sqSum);
        
        // 5/14/2023
        // magnitude of impulse
        double m=obj1->m*obj2->m*d*d*G*d; // multiply a third d in there for more accurate results

        // add to the impulse
        for(int i=0;i<obj1->p.size();i++){
            // 6/7/2023 changed division to multiplication
            double impulse=dv.at(i)*m;
            obj1->linForce[i]+=impulse;
            obj2->linForce[i]-=impulse;
        }
    }
};
#include <iostream>
void mathTest2(float n){
    std::cout<<n;
}

// 11/01/2023 better method
void gravity2(ObjectNd* obj1, ObjectNd* obj2, double G){
    std::vector<double> normal;
    double distanceSquared=0;
    for(int i=0;i<obj1->p.size();i++){
        normal.push_back(obj2->p[i]-obj1->p[i]);
        distanceSquared+=normal[i]*normal[i];
    }
    double invDist=invSqrt(distanceSquared);
    // inverse distance squared
    double invDistSquared=1/distanceSquared;
    // define the force of attraction as G*m1*m2/r^2
    double forceOfAttraction=
        G // G
        *obj1->m // *m1
        *obj2->m // *m2
        *invDistSquared; // /r^2
    // give the forces
    for(int i=0;i<obj1->p.size();i++){
        normal[i]*=invDist; // normalize the normal...
        obj1->linForce[i]+=normal[i]*forceOfAttraction;
        obj2->linForce[i]-=normal[i]*forceOfAttraction;
    }
}

// 11/02/2023 [to the above gravity2 method] - much better... however, energy is still not conserved...
// i will now go read the wikipedia page for elipses...
// progress - 
// 11/02/2023 - found "barycenter" - seems to be center of mass, also seems to 
// be one of the focal points of the two elipses?
// found two-body problem
// found Kepler problem
// found amazing picture: 
// https://upload.wikimedia.org/wikipedia/commons/thumb/e/e0/
// Cat_demonstrating_static_cling_with_styrofoam_peanuts.jpg
// /310px-Cat_demonstrating_static_cling_with_styrofoam_peanuts.jpg
// weirdly the energy likes staying like below 60000 for two objects at the current settings...
// 11/03/2023 - AP Physics C Mechanics FAQ final yesterday, Mechanics MCQ final today
// 11/03/2023 - found Kepler's laws oh planetary motion wikipedia page, reading up on those

// 11/08/2023 - got like 55/90 on the ap physics c mechanics final, got an ap score of a 5/5 lol
// 11/08/2023 - asked chatgpt some questions, then found this image:
// https://www.researchgate.net/profile/Harry-Varvoglis/publication/252503394
// /figure/fig3/AS:667713391300608@1536206686009/Definition-of-true-v-eccentric-E-and-mean-M-anomaly.png
// it is very useful for actually telling me what stuff is

// 11/13/2023 - finding an expert on this subject is very hard to do... i asked my AP Physics C teacher 
// for help
// - learned that the "partial derivatives" of the components are in an imaginary space
// such that if you square any component then the result is the negative magnitude
// - learned that the partial momentum with respect to position is imaginary (not complex!!!?)
// using things like i-hat and j-hat and k-hat and just let me generalize it to n-hat
// 0=dp/dt=
// sqrt(sum(d)(n=1)((partial derivative of P in component n
// /partial derivative of position in component n)^2))
// 0=dp/dt=
// sqrt(sum(d)(n=1)((∂Pn/∂n)^2))
// ∂ is the symbol for partial derivatives
// what is a partial derivative?
// - was told that i need to use legrange transforms (whatever those are???)
// time to read the wikipedia page for it, get distracted multiple times, and then read it over
// over and over again until i actually absorb some critical information!

// 1/8/2024 - i did a thing
// the math is actually too complicated to implement practically
// i mean i could but i haven't even really gotten half way there yet
// but i did evaluate an integral that is probably kinda static
// the result is an absolutely massive equation though


// 2/2/2024 - just keep the energy constant...?
void gravity3(ObjectNd* obj1, ObjectNd* obj2, double G){
    // i said "just", but i'm not sure if it's really "just" that simple, though...
    // add the force and then add the displacement in here?
    // or like directly change the velocity?
    // maybe even like don't output any forces at all and just change the 
    // position and velocity directly...?
    // 2/4/2024 - 8:24 AM CST, Friday
    // overall goal: conserve energy in gravitational interraction
    // how can this be done?

    // E_ki+E_pi=E_kf+E_pf
    // get the direction of the final speed by doing the thing. . .
    // could you do like final velocity minus inital velocity, unit vector of that, and multiply by
    // final speed minus initial speed?

    // this most likely will not work well at all, but i guess why not try...?
    // funny -i think  my comments here might take up more lines than the second iteration of code
    // as a whole

    // 2 (/) 2 (/) 2 (0) 2 (4)
    // 2     2     2     2
    // 2 2 2 2
    // 2222
    // 2 2 2 2
    // 2/2/2024
    // it lines up, crazy!!! 
    // ...

    // 2/2/2024 - copied from gravity2 and then modified
    // 8:44 AM CST - i just deleted it
    
    // oh hey a new dumb idea - 
    // save the initial mechanical energy of each orb and then at the end of the frame
    // iterate through them all and modify the magnitue of their velocity such that the 
    // final kinetic energy plus the final potential energy equals that of the 
    // initial kinetic energy plus the final kinetic energy...
    // you know what? that's a formualted idea that i can actually put in, i think i'll try that...
}

// 2/2/2024
// set the potential and kinetic energies of the objects
// in the reference frame of the world space...?
// also, at this point it could just even be two separate methods...
// 2/2/2024
void setEnergy(ObjectNd* obj,std::vector<ObjectNd*> objects,double G){
    // get the kinetic energy
    // get the sum of the velocity components squared
    double velocityComponentsSquared=0;
    for(int i=0;i<obj->v.size();i++){
        velocityComponentsSquared+=obj->v[i]*obj->v[i];
    }

    // i just copy/pasted the old kinetic energy code and sorta formatted the whole thing to be
    // identical to see what was wrong and i had just
    // forgotten to multiply the orb energies by their mass...
    // it's gone now but it's still funny that i did that...
    // although honestly i think it's a good strategy for bug finding,
    // being comparing to old code

    // the velocity doesn't need to be squared here because it is already squared
    // it's also just the speed squared as well
    obj->lastKineticEnergy=0.5*obj->m*velocityComponentsSquared;


    // get the potential energy
    obj->lastPotentialEnergy=0;
    // cycle through all pairs of object that include the selected object
    for(int i=0;i<objects.size();i++){
        // check to make sure it's not the same object because sometimes lazy idk
        if(objects[i]!=obj){
            double posSumSquared=0;
            for(int j=0;j<obj->p.size();j++){
                // the order doesn't matter
                posSumSquared+=pow(obj->p[j]-objects[i]->p[j],2);
            }
            // if this is undefined then ree idk
            double invDist=invSqrt(posSumSquared);
            // remember negative because the equation for
            // gravitational potential energy does funny things
            // "add" to the lastPotentialEnergy variable in the object!
            // there could be optimization here by "adding" this to objects[i] as well
            // and recurse from the currently selected index plus 1, but eh idk
            obj->lastPotentialEnergy+=-G*obj->m*objects[i]->m*invDist;
        }
    }
}

// 2/5/2024 here's a note i wrote on 2/3/2024:
// "Gravity loop, displacement loop, THEN velocity loop?"
// i'll write like the gravity loop and the velocity loop here i guess idk
// the potential energy setter thingy above doesn't factor in forces so it can be before
// the gravity loop or after it, it doesn't matter as long as it is before
// the velocity setting loop
// the displacement loop is already built in, normally at the end of each frame
// now should i correct the velocities before or after the displacement by the velocities?
// WAIT - NO, THAT WOULD SORT OF BREAK STUFF - IT WOULD HAVE TO BE AFTER
// correct the velocities AFTER the displacemenet by the new velocities inflicted upon by the forces
// however, what happens if the new velocity is faster than terminal velocity? does it then
// put a negative number in a square root? i don't think so, as it isn't getting the velocity,
// it's setting it...
// velocity correction loop
// assumes a system of only the orbs - no external things whatsoever...
// or else things will get broken...
// also assumes that the current lastPotentialEnergy and lastKineticEnergy properties of the objects
// were last updated BEFORE the velocity and displacement changes
// 2/5/2024
void correctVelocities(std::vector<ObjectNd*> objects,double G){
    // get the initial total energies...
    std::vector<double> initialEnergies;
    for(int i=0;i<objects.size();i++){
        initialEnergies.push_back(objects[i]->lastPotentialEnergy+objects[i]->lastKineticEnergy);
    }
    // reset the energies
    for(int i=0;i<objects.size();i++){
        setEnergy(objects[i],objects,G);
    }
   
    for(int i=0;i<objects.size();i++){
        // get the magnitude of the object velocity vector
        // OVER AN HOUR WASTED BECAUSE I FORGOT TO SET IT INITIALLY TO 0...
        double velocitySquareSum=0;
        for(int j=0;j<objects[i]->v.size();j++){
            velocitySquareSum+=objects[i]->v[j]*objects[i]->v[j];
        }
        // multipliable thing to get the magnitude
        double velocityInverseMagnitude=invSqrt(velocitySquareSum);
        
        // get the old potential energy
        // the old total energy must be from before the velocity and displacement changes
        //double oldTotalEnergy=objects[i]->lastPotentialEnergy+objects[i]->lastKineticEnergy;
        double oldTotalEnergy=initialEnergies[i];
        // get the new potential energy
        //setEnergy(objects[i],objects,G);

        // the final kinetic energy equals the total initial energy minus the final potential energy
        // E_kf=E_i-E_pf=(1/2)*m*v_f^2
        // v_f=sqrt((2/m)*(E_i-E_pf)) <-- this is the speed, multiply by the normalized component
        // the math looks correct... https://www.desmos.com/calculator/naoznlz2lw
        // get the new speed
        double newSpeed=sqrt(2*(oldTotalEnergy-objects[i]->lastPotentialEnergy/2)/objects[i]->m);
        //double newSpeed=1000;

        // update the velocities
        for(int j=0;j<objects[i]->v.size();j++){
            // normalize the object velocity vector component
            // remember to multiply by the inverse...
            double normVelComponent=objects[i]->v[j]*velocityInverseMagnitude;
            // set the velocity to the normalized velocity component times the true speed
            objects[i]->v[j]=normVelComponent*newSpeed;
        }
    }

    // oh boy thanks over an hour used up to find this one trivial mistake...
    /*        double velocitySquareSum;
    for(int i=0;i<objects.size();i++){
        //objects[i]->v[0]=30;
        
        velocitySquareSum=0;
        for(int j=0;j<objects[i]->v.size();j++){
            velocitySquareSum+=objects[i]->v[j]*objects[i]->v[j];
        }
        double speed=30;
        for(int j=0;j<objects[i]->v.size();j++){
            objects[i]->v[j]=speed*objects[i]->v[j]*invSqrt(velocitySquareSum);
        }
        
    }*/
}

// trying it again cuz idk it's not being good
// 2/14/2024
void correctVelocities2(std::vector<ObjectNd*> objects,double G){
    // get the initial total energies...
    std::vector<double> initialEnergies;
    for(int i=0;i<objects.size();i++){
        initialEnergies.push_back(objects[i]->lastPotentialEnergy+objects[i]->lastKineticEnergy);
    }
    // reset the energies
    for(int i=0;i<objects.size();i++){
        setEnergy(objects[i],objects,G);
    }
    
    for(int i=0;i<objects.size();i++){
        
        // get the magnitude of the object velocity vector
        double velocitySquareSum=0;
        for(int j=0;j<objects[i]->v.size();j++){
            velocitySquareSum+=objects[i]->v[j]*objects[i]->v[j];
        }
        // multipliable thing to get the magnitude
        double velocityInverseMagnitude=invSqrt(velocitySquareSum);
        

        // get the old potential energy
        // the old total energy must be from before the velocity and displacement changes
        //double oldTotalEnergy=objects[i]->lastPotentialEnergy+objects[i]->lastKineticEnergy;
        double oldTotalEnergy=initialEnergies[i];
        // get the new potential energy
        //setEnergy(objects[i],objects,G);

        // the final kinetic energy equals the total initial energy minus the final potential energy
        // E_kf=E_i-E_pf=(1/2)*m*v_f^2
        // v_f=sqrt((2/m)*(E_i-E_pf)) <-- this is the speed, multiply by the normalized component
        // the math looks correct... https://www.desmos.com/calculator/naoznlz2lw
        // get the new speed
        double newSpeed=0.5*sqrt(2*(oldTotalEnergy-objects[i]->lastPotentialEnergy/2)/objects[i]->m);
        //double newSpeed=1000;

        // update the velocities
        for(int j=0;j<objects[i]->v.size();j++){
            // normalize the object velocity vector component
            // remember to multiply by the inverse...
            double normVelComponent=objects[i]->v[j]*velocityInverseMagnitude;
            // set the velocity to the normalized velocity component times the true speed
            objects[i]->v[j]=normVelComponent*newSpeed;
        }
    }
}

// 2/16/2024
// maybe actually IDENTIFY THE PROBLEMS FIRST...
// i really did just waste a good 4-6 months because i never actually took the time to actually
// try and identify the true problem...
// the TRUE problem is drift. I think my above two (...?) solutions don't work
// because they don't actually stop the drift, they just make the velocity smaller after the drift,
// thus making said object now be slower in the orbit,
// as well as not anymore conserving momentum, (maybe the momentum could have been split
// up with the objects the objects giving said object energy by the ratio of the energy given 
// to said object by the other object over the total energy given to the object? eh it probably 
// wouldn't do too much good idk)
// thus changing the orbit to be more elliptical (?)
// of which then it falls (?)
// but then it gets artificially faster as it falls because of the thing
// and then it like just isn't perfect and it makes and compounds errors over time
// leading to some really weird behavior


// https://scicomp.stackexchange.com/questions/29149/
// what-does-symplectic-mean-in-reference-to-numerical-integrators-and-does-scip/29154#29154

// so i guess the solution is to use a "simplectic integrator" that conserves energy,
// one of maybe even the first solutions i heard...?

// oh yeah - also, the angular momentum is conserved as well, if that means anything...
// i guess it remains constant maybe...? at least with a 2-body system where one object has an 
// extremely large mass?


// 2/16/2024
// here is something totally irrelevant:
// let's say you put someone in a room and ask them a whole bunch of questions.
// this is an experiment
// the experimental groups have the recurring question "does your head hurt?"
// sprinkled into the questions at varying frequencies,
// while the control grou does not ever ask "does your head hurt?".
// i wonder if this would eventually make the person's head hurt depending on frequency
// because their mind is thinking about it and there may be some sort of 
// placebo-esque effect going on.
// could one apply the results into not repeatedly asking if a person has a problem
// such that you don't cause them pain, if the conclusion is that asking more
// gives more pain?
// things to wonder...

// 2/19/2024
// i just looked up what kerbal space program used, because frankly 
// (second time using frank again today here what), that has always sort of been the final goal
// however now that i looked at it, 
// https://en.wikipedia.org/wiki/Kerbal_Space_Program
// #:~:text=The%20game%20simulates%20orbits%20using,physics%20engine%20to%20be%20rewritten.
// "Implementing full n-body physics would require the entire physics engine to be rewritten."

// this is kind of sad but i personally want an n-body simulation because...
// why do i want it again?
// oh yeah - because it is cool
// i dunno why really to be completely honest...
// should i just move onto rasterization?
// thanks, 4 months, for teaching me that realistic gravitational simulations are impractical...
