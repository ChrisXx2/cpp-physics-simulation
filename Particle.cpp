#include "Particle.h"

Particle::Particle(double pos, double vel, double acc)
    : position(pos), velocity(vel), acceleration(acc) {}

void update(Particle& p, double dt) {
    p.velocity += p.acceleration * dt;
    p.position += p.velocity * dt;
}
