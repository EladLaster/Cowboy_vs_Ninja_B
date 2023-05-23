#include <stdio.h>
#include <iostream>
#include "Cowboy.hpp"

using namespace std;

namespace ariel{


    Cowboy::Cowboy(string name,Point location):Character(name,location,110),num_of_bullets(6){}

    void Cowboy:: shoot(Character *other){
        if(other==nullptr) 
            throw invalid_argument ("error: enemey can't be null");
        if(this == other) 
            throw runtime_error ("error: can't shoot myself");
        if(!(this->isAlive()) || !(other->isAlive()))
            throw runtime_error ("error: me or enemy - already dead");
        if(this->hasboolets()){
            this->num_of_bullets--;
            other->hit(10);
        }
    }
    void Cowboy:: reload(){
        if(!(this->isAlive()))
            throw runtime_error("error: im already dead");
        this->num_of_bullets=6;
    }
    bool Cowboy:: hasboolets(){
        return this->num_of_bullets>0;
    }
    string Cowboy:: print(){
        return "C " + Character::print();
    }
}
