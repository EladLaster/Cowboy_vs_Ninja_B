#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include "Point.hpp"
using namespace std;
namespace ariel{
    class Character{

            int health;
            string name;
            Point location;
            int inTeam;
        public:

            Character(const string& name, Point location, int health);
            bool isAlive() const;
            double distance(Character* other);
            void hit(int hurt_point);
            string getName() const;
            Point getLocation() const;  
            int getHealth() const;
            int getInteam() const;
            void setLocation (Point);
            void setInteam();
            virtual ~Character() = default;
            virtual string print();
            
        
            //Tidy required   
            Character (Character&); 
            Character(Character&& ) noexcept; 
            Character& operator = (const Character&); 
            Character& operator = (Character&&) noexcept;
    
   
    }; 
};
#endif