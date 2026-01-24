#ifndef PARTICLE_H
#define PARTICLE_H

class Particle {
private:
    double positionX;
    double positionY;

    double velocityX;
    double terminalVelocityX;
    double velocityY;
    double terminalVelocityY;

    double ForceX;
    double ForceY;

    double mass;
    double cross_sectional_Area;

public:
    
    Particle(double posX, double posY, double velX, double terminalVelX, 
             double velY, double terminalVelY, double m, double CArea);

    void update(double dt, double g, double dragCoeff, double atmDensity);
    void initialize(double dt, double g);
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
    double getTerminalVelocityX() const;
    double getVelocityY() const;
    double getTerminalVelocityY() const;
    void setVelocity(double velX, double velY);
    void setTerminalVelocity(double velX, double dt, double g, double dragCoeff, double atmDensity);
};

#endif