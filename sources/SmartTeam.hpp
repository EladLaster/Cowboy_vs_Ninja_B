#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include "Character.hpp"
#include "Team.hpp"

namespace ariel{
    class SmartTeam: public Team{

        public:
        SmartTeam(Character *leader): Team(leader){}
        void attack(Team *enemyTeam) override;
        void print() override;
    };
};
 #endif