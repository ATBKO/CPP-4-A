#pragma once
#include "Iteam.hpp"

namespace ariel{
    class Team : public virtual Iteam{
        // up tp 10 fighters
        std::vector<Cowboy*> cowboy_team; 
        std::vector<Ninja*> ninja_team;
        Character* leader;

        public:
        Team(Character*);
        // ~Team() override;
        void add(Character* character) override;
        void attack(Iteam* enemy_team) override;
        int stillAlive() override;
        void print() override;
    };
}