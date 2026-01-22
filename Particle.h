#ifndef PARTICLE_H
#define PARTICLE_H

class Particle {
private:

    double positionX;
    double positionY;

    double velocityX;
    double velocityY;

    double ForceX;
    double ForceY;

    double mass;
    double cross_sectional_Area;

public:


    Particle(double posX, double posY, double velX, double velY, double fX, double fY, double m, double CArea);

    void update(double dt, double g);
    bool isValid(double value) const;

    double getKineticEnergy() const;
    void applyForceX(double f);
    void applyForceY(double f);
    void clearForceX();
    void clearForceY();

    double getPositionX() const;
    double getPositionY() const;
    void setPosition(double posX, double posY);
    double getVelocityX() const;
    double getVelocityY() const;
    void setVelocity(double velX, double velY);
    
};

#endif