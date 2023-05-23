#ifndef OLDNINJA_H
#define OLDNINJA_H

#include "Ninja.hpp"
#include "Character.hpp"

const int OLD_NINJA_SPEED = 8;
const int OLD_NINJA_HEALTH = 150;

namespace ariel {
    class OldNinja : public Ninja {
    public:
        OldNinja(string name, Point location): Ninja(std::move(name), OLD_NINJA_HEALTH,location,OLD_NINJA_SPEED){}
        };
    }


#endif