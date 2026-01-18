#ifndef PARTICLE_H
#define PARTICLE_H

class Particle {
private:

    double position;
    double velocity;
    double acceleration;
    double mass;

public:


    Particle(double pos, double vel, double acc, double m);

    void update(double dt);

    double getKineticEnergy(Particle& p) const;
    double getPosition() const;
    void setPosition(double pos);
    double getVelocity() const;
    void setVelocity(double vel);
    
};

#endif