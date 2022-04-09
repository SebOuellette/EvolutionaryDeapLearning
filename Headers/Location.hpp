#pragma once

#include <cmath>

class Location {
private:
    float x;
    float y;
public:
    Location();
    Location(float, float);
    Location(float);  //initial constructor for location
    float getX();
    float getY();
    void setX(float);
    void setY(float);

    void move(Location);
    void move(float, float);

    float distance(Location);
};