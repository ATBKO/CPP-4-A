#include "SmartTeam.hpp"

namespace ariel{
    SmartTeam::SmartTeam(Character* leader_) : Iteam(leader_){
        
    }

    // SmartTeam::~SmartTeam(){}

    void SmartTeam::add(Character* character){

    }

    void SmartTeam::attack(Iteam* enemy_team){

    }

    int SmartTeam::stillAlive(){
        return ((this)->team.size());
    }

    void SmartTeam::print(){

    }

    vector<Character*> SmartTeam::getEnemy(SmartTeam* enemy){
        return enemy->team;
    }


}