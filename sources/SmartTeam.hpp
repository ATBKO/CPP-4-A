#pragma once
#include "Iteam.hpp"

namespace ariel{
    class SmartTeam : public virtual Iteam{
        // up tp 10 fighters
        std::vector<Character*> team; 
        Character* leader;

        public:
        SmartTeam(Character*);
        // ~SmartTeam();
        void add(Character* character) override;
        void attack(Iteam* enemy_team) override;
        int stillAlive() override;
        void print() override;
        vector<Character*> getEnemy(SmartTeam*);
    };
}