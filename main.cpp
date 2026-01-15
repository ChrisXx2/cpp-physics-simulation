#include <iostream>
#include <vector>
#include "Particle.h"

int main() {
    std::vector<Particle> particles;

    particles.emplace_back(0.0, 10.0, -9.81);
    particles.emplace_back(5.0, 5.0, -9.81);
    particles.emplace_back(-3.0, 15.0, -9.81);

    double dt = 0.1;

    for (int i = 0; i < 20; i++) {
        std::cout << "t = " << i * dt << std::endl;

        for (Particle& p : particles) {
            update(p, dt);
            std::cout << "  position = " << p.position << " || "
                      << " velocity = " << p.velocity
                      << std::endl;
        }
    }

    return 0;
}