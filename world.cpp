#include "world.h"

#include <iostream>
#include <vector>
#include <stdexcept>

World::World(double gravity, double dragCoefficient) : gravity(gravity), dragCoefficient(dragCoefficient) {};

double World::getGravity() const {
    return gravity;
};

double World::getDragCoefficient() const {
    return dragCoefficient;
};

void World::applyGlobalForces(double m, double fX, double fY) const {
    fY += (gravity * m) + (dragCoefficient * fY);
};