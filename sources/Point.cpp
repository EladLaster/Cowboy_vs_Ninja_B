#include <stdio.h>
#include <iostream>
#include <cmath>
#include "Point.hpp"

using namespace std;

namespace ariel{
    
    Point::Point(double x_point, double y_point){
        this->x_point=x_point;
        this->y_point=y_point;
    }
    double Point::get_x(){
        return this->x_point;
    }
    double Point::get_y(){
        return this->y_point;
    }
    double Point::distance(Point other){
        double dx=this->x_point-other.x_point;
        double dy=this->y_point-other.y_point;
        return sqrt(dx*dx+dy*dy);
    }
    string Point::print(){
        return "(" + to_string(x_point) + ", " + to_string(y_point) + ")";
    }
    
    Point Point::moveTowards(Point src, Point dest, double dist){
    if (dist<0)     
        throw invalid_argument("distance cannot be smaller than 0");
    double dx = dest.get_x() - src.get_x();
    double dy = dest.get_y() - src.get_y();
    double new_dist= sqrt(dx * dx + dy * dy);
    if (new_dist <= dist) 
        return dest;
    double rat = dist / new_dist;
    double new_x =src.get_x() + rat * dx;
    double new_y =src.get_y() + rat * dy;
    
    return Point(new_x, new_y);
    }
}