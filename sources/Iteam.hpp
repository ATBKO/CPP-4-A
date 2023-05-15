#pragma once
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include <vector>
using namespace std;

namespace ariel{
    class Iteam{
        Character* leader;

        public:
            Iteam(Character* leader_) : leader(leader_){}
            
            virtual void add(Character*) = 0;
            virtual void attack(Iteam*) = 0;
            virtual int stillAlive() = 0;
            virtual void print() = 0;

            virtual ~Iteam() = default; // destructor
            Iteam(const Iteam&) = delete; // Copy constructor
            Iteam& operator=(const Iteam&) = delete; // Copy assignment operator
            Iteam(Iteam&&) = delete; // Move constructor
            Iteam& operator=(Iteam&&) = delete; // Move assignment operator
    };
}