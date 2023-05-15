#pragma once
#include "Point.hpp"
#include <string>
using namespace std;

namespace ariel {
    class Character{
        Point location;
        int hitPoints; // 110 - for cowboy
        string name;

        public:
            Character();
            Character(string, Point, int);

            virtual ~Character() = default; // destructor
            Character(const Character&) = delete; // Copy constructor
            Character& operator=(const Character&) = delete; // Copy assignment operator
            Character(Character&&) = delete; // Move constructor
            Character& operator=(Character&&) = delete; // Move assignment operator


            // for both ninja & cowboy
            bool isAlive();
            double distance(Character*);
            void hit(int);
            string getName();
            Point getLocation();
            virtual string print()=0;
            
    };

}