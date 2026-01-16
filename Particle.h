#ifndef PARTICLE_H
#define PARTICLE_H

struct Particle {
    double position;
    double velocity;
    double acceleration;
    double mass;

    Particle(double pos, double vel, double acc, double m);

    double kineticEnergy(Particle& p) const;
};

void update(Particle& p, double dt);


#endif