#pragma once
#include "Iteam.hpp"

namespace ariel{
    class Team2 : public virtual Iteam{
        // up tp 10 fighters
        std::vector<Character*> team; 
        Character* leader;

        public:
            Team2(Character*);
            // ~Team2();
            void add(Character* character) override;
            void attack(Iteam* enemy_team) override;
            int stillAlive() override;
            void print() override;
    };
}