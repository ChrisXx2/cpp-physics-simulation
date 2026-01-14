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
    Particle lemon(0.0, 5.0, -9.81);
    double dt = 0.1;

    for (int i = 0; i < 20; i++) {
        update(ball, dt);
        update(lemon, dt);
        std::cout << "t = " << i * dt
                  << " | ball's position = " << ball.position
                  << " | ball's velocity = " << ball.velocity
                  << " | "
                  << " | lemon's position = " << lemon.position
                  << " | lemon's velocity = " << lemon.velocity
                  << std::endl;
    }

    return 0;
}
