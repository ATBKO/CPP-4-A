#pragma once
#include "Character.hpp"

namespace ariel{
    class Cowboy : public Character{
        int bulets;

        public:
            Cowboy(string, Point);
            void shoot(Character*); // lose 10 hits
            bool hasboolets();
            void reload();
            string print() override;
    };
}