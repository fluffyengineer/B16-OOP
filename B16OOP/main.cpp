class Mass {
    
public:
    
    
private :
    
    double position, mass;
    
    double velocity;
    
    double acceleration;
    
public:
    
    void setInitialConditions(double initialPosition,double initialVelocity,double initialAcc){
        position = initialPosition;
        velocity = initialVelocity;
        acceleration = initialAcc;
        
    }
    
    void applyForce(double force, double timestep){
        
        acceleration = force / mass;
        
        velocity = velocity + acceleration * timestep;
        
        position = position + velocity*timestep;
    }
    
    
        
    double getPosition(){
        
            return position;
    }

    
};


class Spring {
    
private:
    
    double stiffness;
    
    Mass left;
    Mass right;

public:
    
    void setLeft(Mass mass){
        left = mass;
    }
    
    void setRight(Mass mass){
        right = mass;
    }
    
    double getForce(){

       return stiffness * (left.getPosition() - right.getPosition());
        
    };
    
};




class World {
    
    vector <Mass> Masses;
    vector <Spring> Springs;
    
    attachSprings(Masses,Springs);  //This will just tell each spring which mass is Left and Right
    
    initialConditions(vector<Mass> Masses); //This will run through all the masses and set their initial conditions
    double time;

    
    void updateWorld(); //Here, we will set a timestep, and then get the force from the springs, and then move the masses. Loop is : Position -> Force -> Acceleration -> Velocity -> Position

};



//updateWorld(){
//    
//    t = t+1;
//    
//    for spring:Springs   //Iterator : may not go from 1 - end,
//        
//        double f = spring.getForce //because we don't
//        
//        spring.getMass(left)
//        applyForce(spring.getForce);
//    
//    
//    spring.getMass(right)
//    applyForce(spring.getForce);
//    
//}
//
//getForce(){
//    stiffness*(left.getPos() - right.getPos());
//}




//Linear Mass Spring Sys



#include <iostream>
#include <vector>
using namespace std;

int main{
    
    //overload << operators
    
    for(int i=0; i<1000;i++){
        
        cout << w << endl;
        hgjg
        hk
        
        
        
        }
        
        
    // friend osstream& operator<<(std::ostream &output, const World &C)

 // for the spring, the output is the "-" times the length

    }
    
