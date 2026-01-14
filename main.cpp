#include <iostream>

struct Particle {
    double position;
    double velocity;
    double acceleration;

    Particle(double pos, double vel, double acc)
        : position(pos), velocity(vel), acceleration(acc) {}
};

void update(Particle& particle, double dt) {
    particle.velocity += particle.acceleration * dt;
    particle.position += particle.velocity * dt;
}

int main() {
    Particle ball(0.0, 10.0, -9.81);
    double dt = 0.1;

    for (int step = 0; step < 20; step++) {
        update(ball, dt);
        std::cout << "t = " << step * dt
                  << " | position = " << ball.position
                  << " | velocity = " << ball.velocity
                  << std::endl;
    }

    return 0;
}
