#include "Team.hpp"

namespace ariel{
    Team::Team(Character* leader_) : Iteam(leader_) {
        (this)->leader = leader_;
        (this)->add(leader_);
    }

    // Team::~Team(){}

    void Team::add(Character* character){

    }

    void Team::attack(Iteam* enemy_team){

    }

    int Team::stillAlive(){
        return ((this)->cowboy_team.size() + (this)->ninja_team.size());
    }

    void Team::print(){

    }


}