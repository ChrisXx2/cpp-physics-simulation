#include <iostream>
#include <vector>
#include <cmath>
#include "Particle.h"

int main() {
    std::vector<Particle> particles;

    const double dt = 0.1;
    const double g = 9.81;
    const double m = 1.0;

    std::cout << "Enter number of particles: ";
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        particles.emplace_back(0.0, 0.0, g, m);
    }

    double x = 0.0;
    double v = 0.0;

    int defaultPos = 0;
    int defaultVel = 0;

    for (size_t i = 0; i < particles.size(); i++) {
    
        Particle& p = particles[i];



        if (defaultPos == 1 && defaultVel == 1) {
            p.setPosition(x);
            p.setVelocity(v);
            continue;
        }

        if (defaultPos == 0) {
            std::cout << "Enter initial position for particle " << i + 1 << ": ";
            std::cin >> x;
            p.setPosition(x);
            std::cout << "Do you want to make it the default position? (1 for yes / 0 for no): ";
            std::cin >> defaultPos;
        }

        if (defaultVel == 0) {
            std::cout << "Enter initial velocity for particle " << i + 1 << ": ";
            std::cin >> v;
            p.setVelocity(v);
            std::cout << "Do you want to make it the default velocity? (1 for yes / 0 for no): ";
            std::cin >> defaultVel;
        }
    }

    for (int i = 0; i < 20; i++) {
        std::cout << "t = " << i * dt << std::endl;
        
        for (size_t i = 0; i < particles.size(); i++) {
        Particle& p = particles[i];
            std::cout << "Particle " << (&p - &particles[0]) << ": " <<std::endl
                      << " position = " << p.getPosition() << " || "
                      << " velocity = " << p.getVelocity() << " || "
                      << " kinetic energy = " << p.getKineticEnergy() << " || "
                      << std::endl;
            p.update(dt);
        }
        
    }

    return 0;
}