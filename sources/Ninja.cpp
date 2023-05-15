#include "Ninja.hpp"

namespace ariel{
    Ninja::Ninja(string name, Point location, int hitPoints_, int velocity_) : Character(name, location, hitPoints_){
        (this)->velocity = velocity_;
    }
    
    void Ninja::move(Character* enemy){

    }

    void Ninja::slash(Character* enemy){

    }

    string Ninja::print(){
        return "";
    }


    OldNinja::OldNinja(string name, Point location) : Ninja(name, location, 150, 8){

    }

    YoungNinja::YoungNinja(string name, Point location) : Ninja(name, location, 100, 14){

    }

    TrainedNinja::TrainedNinja(string name, Point location) : Ninja(name, location, 120, 12){
        
    }
}