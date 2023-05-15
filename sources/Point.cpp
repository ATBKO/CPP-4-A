#include "Point.hpp"
#include <iostream>
#include <cmath>
using namespace std;

namespace ariel{
    Point::Point(){
        (this)->x = 0;
        (this)->y = 0; 
    }

    Point::Point(double x_, double y_){
        (this)->x = x_;
        (this)->y = y_; 
    }

    double Point::distance(Point p){
        return (sqrt(pow((this->x - p.x), 2)+pow((this->y - p.y), 2)));
    }

    void Point::print(){
        cout << "[" << x << ", " << y << "]" <<endl;
    }

    Point Point::moveTowards(Point p){
        return (*this);
    }
}
