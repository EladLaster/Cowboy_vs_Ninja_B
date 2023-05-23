#ifndef TRAINEDNINJA_H
#define TRAINEDNINJA_H

#include "Ninja.hpp"
#include "Character.hpp"

const int TRAINED_NINJA_SPEED = 12;
const int TRAINED_NINJA_HEALTH = 120;

namespace ariel {
    class TrainedNinja : public Ninja {
    public:
        
        TrainedNinja (string name, Point location) :Ninja(std::move(name), TRAINED_NINJA_HEALTH,location,TRAINED_NINJA_SPEED) {}
    };
}
#endif 