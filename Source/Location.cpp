#include "../Headers/Location.hpp"

Location::Location() {
    this->x = 0;
    this->y = 0;
}

Location::Location(float initX, float initY) {
    this->x = initX;
    this->y = initY;
}

Location::Location(float init) {
    this->x = init;
    this->y = init;
}

float Location::getX() {
    return this->x;
}

float Location::getY() {
    return this->y;
}

void Location::move(Location offset) {
    this->move(offset.getX(), offset.getY());
} 

void Location::move(float xOffset, float yOffset) {
    this->x += xOffset;
    this->y += yOffset;
}

void Location::setX(float x) {
    this->x = x;
}

void Location::setY(float y) {
    this->y = y;
}

float Location::distance(Location secondLocation) {

    return sqrt(powf(secondLocation.getX() - this->getX(), 2.f) + powf(secondLocation.getY() - this->getY(), 2.f));
}

bool Location::operator==(Location b) {
    return this->x == round(b.x) && this->y == round(b.y);
} 