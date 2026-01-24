#include "world.h"

#include <iostream>
#include <vector>
#include <stdexcept>

World::World(double gravity, double dragCoefficient, double atmosphericDensity) : gravity(gravity), dragCoefficient(dragCoefficient), atmosphericDensity(atmosphericDensity) {};

double World::getGravity() const {
    return gravity;
};

double World::getAtmosphericDensity() const {
    return atmosphericDensity;
};
double World::getDragCoefficient() const {
    return dragCoefficient;
};