#ifndef TEAM_H
#define TEAM_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Cowboy.hpp"

using namespace std;

namespace ariel{

class Team {

        Character * leader;
        vector<Character*> team;

    public:

        Team(Character * leader);
        void add(Character * other);
        virtual void attack(Team * other);
        int stillAlive();
        virtual void print();
        void setLeader();
        Character* chooseVictim(Team& other);
        vector<Character*>& getTeam();
        Character* getLeader ();
        virtual ~Team(){
        for(size_t i=0; i<this->team.size();i++){
            delete this->team[i];
        }
        };
        //Tidy required
        Team (Team&) = delete; 
        Team (Team&&) noexcept = delete; 
        Team& operator = (const Team&) = delete; 
        Team& operator = (Team&&) noexcept = delete; 
};

}
#endif