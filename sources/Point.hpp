#pragma once

namespace ariel {
    class Point{
        double x;
        double y;

        public:
            Point();
            Point(double, double);
            double distance(Point);
            void print();
            Point moveTowards(Point);
    };

}