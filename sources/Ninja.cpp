#include <stdio.h>
#include <iostream>
#include "Ninja.hpp"

using namespace std;

namespace ariel{

    Ninja::Ninja(string name, int health, Point location, int speed):Character(name,location,health),speed(speed){}

    void Ninja::move(Character * other) {
        if(other==nullptr) 
            throw invalid_argument ("error: enemey can't be null");
        setLocation(Point::moveTowards(this->getLocation(), other->getLocation(), this->speed));
    }

    void Ninja::slash(Character * other) {
        if(other==nullptr) 
            throw invalid_argument ("error: enemey can't be null");
        if(this == other) 
            throw runtime_error ("error: can't slash myself");   
        if(!(this->isAlive()) || !(other->isAlive())) 
            throw runtime_error ("error: me or enemy - already dead");
        if (this->getLocation().distance(other->getLocation()) < 1) 
            other->hit(40);  
    }

    int Ninja::get_speed(){
        return this->speed;
    }
    string Ninja::print(){
        return "N " + Character::print();
    }
}