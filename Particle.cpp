#include "Particle.h"
#include <cmath>
#include <stdexcept>

Particle::Particle(double pos, double vel, double acc, double m)
    : position(pos), velocity(vel), acceleration(acc), mass(m) {}

void Particle::update(double dt) {
    velocity += acceleration * dt;
    position += velocity * dt;
}

bool Particle::isValid(double value) const {
    return std::isfinite(value);
}

double Particle::getKineticEnergy() const {
    return 0.5 * mass * pow(velocity, 2);
}

double Particle::getPosition() const {
    return position;
}

double Particle::getVelocity() const {
    return velocity;
}

void Particle::setPosition(double pos) {
    if (!isValid(pos)) {
        throw std::invalid_argument("Invalid position");
    }
    position = pos;
}

void Particle::setVelocity(double vel) {
    if (!isValid(vel)) {
        throw std::invalid_argument("Invalid velocity");
    }
    velocity = vel;
}