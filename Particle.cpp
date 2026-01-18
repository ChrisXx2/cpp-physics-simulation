#include "Particle.h"
#include <cmath>

Particle::Particle(double pos, double vel, double acc, double m)
    : position(pos), velocity(vel), acceleration(acc), mass(m) {}

void Particle::update(double dt) {
    velocity += acceleration * dt;
    position += velocity * dt;
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
    position = pos;
}

void Particle::setVelocity(double vel) {
    velocity = vel;
}