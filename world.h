#ifndef WORLD_H
#define WORLD_H

class World {
private:
    double gravity;
    double dragCoefficient;
    double atmosphericDensity;

public:
    World(double gravity, double dragCoefficient, double atmosphericDensity);

    double getGravity() const;
    double getDragCoefficient() const;
    double getAtmosphericDensity() const;
};

#endif