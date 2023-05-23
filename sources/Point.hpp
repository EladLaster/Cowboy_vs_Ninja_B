#ifndef POINT_H
#define POINT_H

#include <stdio.h>
#include <iostream>

using namespace std;

namespace ariel{

class Point{
    
        double x_point;
        double y_point;
    public:
      
        Point(double x_point,double y_point);
        double get_x();
        double get_y();
        double distance(Point other);
        string print();
        static Point moveTowards(Point src,Point dest, double dist);
};
}

#endif