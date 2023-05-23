#include <stdio.h>
#include <iostream>
#include <string>
#include <limits>
#include "Point.hpp"
#include "Character.hpp"
#include "Team.hpp"

using namespace std;
namespace ariel{
int i=0;
    Team::Team(Character * leader):leader(leader){
        if(leader->getInteam()) 
            throw runtime_error ("error: im already in a team");
        if(leader==nullptr) 
            throw invalid_argument ("error: im can't be null");
        if(!leader->isAlive()) 
            throw invalid_argument ("error: im already dead");
        add(leader);
        leader->setInteam();
    }

    void Team ::add(Character * character){
    if(character->getInteam()) 
            throw runtime_error ("error: im already in a team");
    if(character==nullptr)  
        throw invalid_argument ("error: im can't be null");
    if(!character->isAlive()) 
        throw invalid_argument ("error: im already dead");
    if(this->team.size()==10)
        throw runtime_error("error: team can have no more than 10 characters");

    team.push_back(character);
    character->setInteam();
    }
    
    vector<Character*>& Team::getTeam() {
        return this->team;
    }
    Character* Team::getLeader (){
        return this->leader;
    }

    void Team ::attack(Team * other){
        
        if(other==nullptr) 
            throw invalid_argument ("error: other team can't be null");
        if(this == other) 
            throw runtime_error ("error: can't attack myself");
        if(this->stillAlive()==0|| other->stillAlive()==0)
            throw runtime_error ("error: my team or other team - already dead");
        
        setLeader();
        Character* victim=chooseVictim(*other);
        
            for(size_t i = 0; i < this->team.size(); i++){
                if(this->team[i]->isAlive() && victim->isAlive()){
                    if (Cowboy* temp_cowboy = dynamic_cast<Cowboy*>(this->team[i])) {
                        if (temp_cowboy->hasboolets()) 
                            temp_cowboy->shoot(victim);
                        
                        else
                            temp_cowboy->reload();
                        }
                    } 
                if (this->stillAlive() == 0 || other->stillAlive() == 0) 
                    return;
                if(!(victim->isAlive()))
                    victim = chooseVictim(*other); 
                if (!other->leader->isAlive()) 
                    other->setLeader();
                }

            for(size_t i = 0; i < this->team.size(); i++){
                if(this->team[i]->isAlive() && victim->isAlive()){
                    if (Ninja* temp_ninja = dynamic_cast<Ninja*>(this->team[i])) {
                        double temp_dist=temp_ninja->getLocation().distance(victim->getLocation());
                        if (temp_dist < 1) 
                            temp_ninja->slash(victim);
                        
                        else 
                            temp_ninja->move(victim);
                        }  
                    }
                if (this->stillAlive() == 0 || other->stillAlive() == 0) 
                    return;
                if(!(victim->isAlive()))
                    victim = chooseVictim(*other); 
                if (!other->leader->isAlive()) 
                    other->setLeader();
                }
        }   

    int Team ::stillAlive(){
        int count = 0;
        for (size_t i = 0; i < team.size(); i++) {
            if (team[i]->isAlive()) {
                count++;
            }
        }
        return count;
    }
    void Team ::print() {
        cout<<stillAlive()<<endl;
        cout << "Team :" << endl;
        for (size_t i = 0; i < team.size(); i++) {
            if(team[i]->isAlive()){
                if(Cowboy* temp_cowboy = dynamic_cast<Cowboy*>(this->team[i])) {
                cout <<temp_cowboy->print() << endl;
                }
            }
        }
        for (size_t i = 0; i < team.size(); i++) {
            if(team[i]->isAlive()){
                if (Ninja* temp_ninja = dynamic_cast<Ninja*>(this->team[i])) {
                cout <<temp_ninja->print() << endl;
                }
            }
        }
    }
    Character* Team::chooseVictim(Team& other){
        Character* victim = nullptr;
        double min_dist = numeric_limits<double>::max();
        for (size_t i = 0; i < other.team.size(); i++) {
            if(other.team[i]->isAlive()){
                double new_dist=this->leader->getLocation().distance(other.team[i]->getLocation());
                if(new_dist<min_dist){
                    min_dist=new_dist;
                    victim=other.team[i];
                }
            }
        }
        return victim;
    } 
    void Team::setLeader() {
    if (!this->leader->isAlive()) {
        Character* newLeader = nullptr;
        double minDistance = std::numeric_limits<double>::max();
        for (size_t i = 0; i < team.size(); i++) {
            if (team[i] != leader && team[i]->isAlive()) {
                double distance = leader->getLocation().distance(team[i]->getLocation());
                if (distance < minDistance) {
                    minDistance = distance;
                    newLeader = team[i];
                }
            }
        }
        
        leader = newLeader;
    }
}
}