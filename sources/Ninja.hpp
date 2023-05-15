#pragma once
#include "Character.hpp"

namespace ariel{
    class Ninja : public Character{
        int velocity;

        public:
            Ninja(string, Point, int, int);
            void move(Character*);
            void slash(Character*);
            string print() override;
    };

    class OldNinja : public Ninja{
        public:
            OldNinja(string, Point); // velocity = 8, hitPoints = 150
    };

    class YoungNinja : public Ninja{
        public:
            YoungNinja(string, Point); // velocity = 14, hitPoints = 100
    };

    class TrainedNinja : public Ninja{
        public:
            TrainedNinja(string, Point); // velocity = 12, hitPoints = 120
    };
}