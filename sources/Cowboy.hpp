#ifndef COWBOY_H
#define COWBOY_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include "Character.hpp"
#include "Point.hpp"

namespace ariel{
class Cowboy : public Character{

    int num_of_bullets;

    public:
        Cowboy(string name,Point location);
        void shoot(Character * other);
        void reload();
        bool hasboolets();
        string print() override;
};
}
#endif