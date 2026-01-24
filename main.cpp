#include <iostream>
#include <vector>
#include <cmath>
#include "Particle.h"
#include "world.h"
#include <limits>
#include <stdexcept>

int main() {
    std::cout << "Console Particle Physics Simulation\n"
              << "-----------------------------------\n"
              << "Enter the world parameters:\n"
              << std::endl;
    
    std::cout << "Enter gravity (m/s^2): ";
    double gravity;
    std::cin >> gravity;
    
    std::cout << "Enter drag coefficient: ";
    double dragCoefficient;
    std::cin >> dragCoefficient;

    World earth(gravity, dragCoefficient, 1.225);
    std::vector<Particle> particles;

    const double dt = 0.1;
    const double g = earth.getGravity();
    const double dc = earth.getDragCoefficient();
    const double m = 1.0;

    std::cout << "Enter number of particles: ";
    int n;
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
        try {
            particles.emplace_back(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, m, 1.0);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error creating particle: " << e.what() << std::endl;
            --i;
            continue;
        }
    }

    double x = 0.0;
    double y = 0.0;
    double fx = 0.0;
    double fy = 0.0;

    int defaultPos = 0;
    int defaultForce = 0;

    for (size_t i = 0; i < particles.size(); i++) {
        Particle& p = particles[i];

        if (defaultPos == 1 && defaultForce == 1) {
            p.setPosition(x, y);
            p.applyForceX(fx);
            p.applyForceY(fy);
            p.initialize(dt, g);
            continue;
        }

        if (defaultPos == 0) {
            std::cout << "Enter initial x position for particle " << i + 1 << ": ";
            std::cin >> x;
            std::cout << "Enter initial y position for particle " << i + 1 << ": ";
            std::cin >> y;
            p.setPosition(x, y);
            std::cout << "Do you want to make it the default position? (1 for yes / 0 for no): ";
            std::cin >> defaultPos;
        } else {
            p.setPosition(x, y);
        }

        if (defaultForce == 0) {
            std::cout << "Enter initial applied force on the x-axis for particle " << i + 1 << ": ";
            std::cin >> fx;
            std::cout << "Enter initial applied force on the y-axis for particle " << i + 1 << ": ";
            std::cin >> fy;
            p.applyForceX(fx);
            p.applyForceY(fy);
            std::cout << "Do you want to make them the default forces? (1 for yes / 0 for no): ";
            std::cin >> defaultForce;
        } else {
            p.applyForceX(fx);
            p.applyForceY(fy);
        }

        p.initialize(dt, g);
    }
    
    for (int step = 0; step < 20; step++) {
        std::cout << "\n-----------------------------------\n";
        std::cout << "Simulation state at t = " << step * dt << " seconds:\n";
        std::cout << "t = " << step * dt << " seconds || "
                  << "gravity = " << g << " m/s^2 || "
                  << "drag coefficient = " << dc << " ||\n"
                  << std::endl;

        for (size_t i = 0; i < particles.size(); i++) {
            Particle& p = particles[i];
            std::cout << "Particle " << i << ": " << std::endl
                      << " position x = " << p.getPositionX() << " || "
                      << " position y = " << p.getPositionY() << " || "
                      << " velocity x = " << p.getVelocityX() << " || "
                      << " velocity y = " << p.getVelocityY() << " || "
                      << " kinetic energy = " << p.getKineticEnergy() << " || "
                      << std::endl;
            p.update(dt, g, dc, earth.getAtmosphericDensity());
        }
    }
    
    std::cout << "\nPress Enter to exit...";
    std::cin.ignore();
    std::cin.get();
    
    return 0;
}