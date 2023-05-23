#ifndef TEAM2_HPP
#define TEAM2_HPP
#include "Character.hpp"
#include "Team.hpp"
namespace ariel{
    class Team2: public Team{

        public:
        Team2(Character *leader): Team(leader){}
        void attack(Team *enemyTeam) override;
        void print() override;
    };
};
 #endif