#include <iostream>
#include <vector>

struct Particle {
    double position;
    double velocity;
    double acceleration;

    Particle(double pos, double vel, double acc)
        : position(pos), velocity(vel), acceleration(acc) {}
};

void update(Particle& p, double dt) {
    p.velocity += p.acceleration * dt;
    p.position += p.velocity * dt;
}

int main() {
    std::vector<Particle> particles;

    particles.emplace_back(0.0, 10.0, -9.81);
    particles.emplace_back(5.0, 5.0, -9.81);
    particles.emplace_back(-3.0, 15.0, -9.81);

    double dt = 0.1;

    for (int step = 0; step < 20; step++) {
        std::cout << "t = " << step * dt << std::endl;

        for (Particle& p : particles) {
            update(p, dt);
            std::cout << "  position = " << p.position
                      << " velocity = " << p.velocity
                      << std::endl;
        }
    }

    return 0;
}