#ifndef WORLD_H
#define WORLD_H

class World {
private:
    double gravity;
    double dragCoefficient;

public:
    World(double gravity, double dragCoefficient);

    double getGravity() const;
    double getDragCoefficient() const;

    void applyGlobalForces(double m, double fX, double fY) const;
};

#endif