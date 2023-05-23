#include "Team2.hpp"
#include <cstddef>

namespace ariel {

void Team2::attack(Team* other) {
    
    if(other==nullptr) 
        throw invalid_argument ("error: other team can't be null");
    if(this == other) 
        throw runtime_error ("error: can't attack myself");
    if(this->stillAlive()==0|| other->stillAlive()==0)
        throw runtime_error ("error: my team or other team - already dead");

    setLeader();
    Character* victim=chooseVictim(*other);
    
    for(size_t i = 0; i < this->getTeam().size(); i++){
            if(this->getTeam()[i]->isAlive() && victim->isAlive()){
                if (Cowboy* temp_cowboy = dynamic_cast<Cowboy*>(this->getTeam()[i])) {
                    if (temp_cowboy->hasboolets()) 
                        temp_cowboy->shoot(victim);
                    
                    else    
                        temp_cowboy->reload();  
                }
                else if(Ninja* temp_ninja = dynamic_cast<Ninja*>(this->getTeam()[i])){
                    temp_ninja = dynamic_cast<Ninja*>(this->getTeam()[i]);
                    if (temp_ninja->isAlive()) {
                        double temp_dist=temp_ninja->getLocation().distance(victim->getLocation());
                        if (temp_dist < 1) 
                            temp_ninja->slash(victim);
                       
                        else 
                            temp_ninja->move(victim);
                    } 
                }
            }
            if (this->stillAlive() == 0 || other->stillAlive() == 0) 
                    return;
                if(!(victim->isAlive()))
                    victim = chooseVictim(*other); 
                if (!other->getLeader()->isAlive()) 
                    other->setLeader();
        }
    }
    
void Team2::print(){
    cout<<stillAlive()<<endl;
        cout << "Team :" << endl;
        for (size_t i = 0; i < this->getTeam().size(); i++) {
            if(this->getTeam()[i]->isAlive())
                cout << this->getTeam()[i]->print() << endl;
        }
    }
}