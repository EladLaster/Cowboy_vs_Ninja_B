#ifndef YOUNGNINJA_H
#define YOUNGNINJA_H

#include "Ninja.hpp"
#include "Character.hpp"

const int YOUNG_NINJA_SPEED = 14;
const int YOUNG_NINJA_HEALTH = 100;

namespace ariel {
    class YoungNinja : public Ninja {

    public:
        
        YoungNinja (string name, Point location) :Ninja(std::move(name), YOUNG_NINJA_HEALTH, location,YOUNG_NINJA_SPEED) {}
    };
    };
#endif 