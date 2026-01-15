#ifndef PARTICLE_H
#define PARTICLE_H

struct Particle {
    double position;
    double velocity;
    double acceleration;

    Particle(double pos, double vel, double acc);
};

void update(Particle& p, double dt);

#endif