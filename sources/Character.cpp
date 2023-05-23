#include "Character.hpp"
#include <stdexcept>
#include <string>
using namespace ariel;
using namespace std;

Character::Character(const string& name, Point location, int health):name(name),location(location),health(health),inTeam(0){}

bool Character:: isAlive() const{
    if (health > 0)
        return true;
    return false;
}
double Character:: distance(Character* other){
    return location.distance(other->location);
}

void Character:: hit(int hurt_point){
    if(hurt_point < 0) 
        throw invalid_argument ("error: wrong hurt_point input");
    if(isAlive()){
        if (hurt_point >= health) {
            health = 0;
        }
        else
            health = health - hurt_point;  
    }
}
string Character::getName() const{
    return this->name;
}
Point Character::getLocation()const{
    return this->location;
}
int Character :: getHealth () const {
    return this->health;
}
void Character :: setLocation (Point location) { 
   this->location = location;
}
void Character :: setInteam(){
    this->inTeam=1;
}
int Character :: getInteam() const{
    return this->inTeam;
}
string Character::print(){
        return "name: "+name + ", health: "+to_string(health)  + ", Locatin: " + location.print();
    }

 