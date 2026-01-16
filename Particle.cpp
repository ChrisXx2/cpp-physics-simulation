#include "Particle.h"
#include <cmath>

Particle::Particle(double pos, double vel, double acc, double m)
    : position(pos), velocity(vel), acceleration(acc), mass(m) {}

void update(Particle& p, double dt) {
    p.velocity += p.acceleration * dt;
    p.position += p.velocity * dt;
}

double Particle::kineticEnergy(Particle& p) const {
    return 0.5 * p.mass * pow(p.velocity, 2);
}