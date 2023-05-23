#ifndef NINJA_H
#define NINJA_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include "Character.hpp"
#include "Point.hpp"

namespace ariel{
class Ninja : public Character{
        int speed;

    public:
        Ninja (string name,int health,Point location,int speed);
        void move(Character* other);
        void slash(Character* other);
        int get_speed();
        string print() override;
};
}
#endif