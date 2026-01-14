#include <iostream>

void update(double& position, double& velocity, double acceleration, double dt) {
    velocity += acceleration * dt;
    position += velocity * dt;
}

int main() {
    double position = 0.0;
    double velocity = 10.0;
    double acceleration = -9.81;
    double dt = 0.1;

    for (int step = 0; step < 20; step++) {
        update(position, velocity, acceleration, dt);

        std::cout << "t = " << step * dt
                  << " | position = " << position
                  << " | velocity = " << velocity
                  << std::endl;
    }

    return 0;
}
