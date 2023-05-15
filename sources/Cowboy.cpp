#include "Cowboy.hpp"

namespace ariel{
    Cowboy::Cowboy(string name, Point location) : Character(name, location, 110){
        (this)->bulets = 6;
    }

    void Cowboy::shoot(Character* enemy){

    }

    bool Cowboy::hasboolets(){
        return false;
    }

    void Cowboy::reload(){

    }

    string Cowboy::print(){
        return "";
    }
}