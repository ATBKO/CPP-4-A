#include "Character.hpp"

namespace ariel{
    Character::Character(){}
    Character::Character(string name_, Point location_, int hitPoints_){
        (this)->location = location_;
        (this)->name = name_;
        (this)->hitPoints = hitPoints_;

    }

    bool Character::isAlive(){
        return true;
    }

    double Character::distance(Character* other){
        return (this)->location.distance(other->location);
    }

    void Character::hit(int points){

    }

    string Character::getName(){
        return (this)->name;
    }

    Point Character::getLocation(){
        return (this)->location;
    }


}