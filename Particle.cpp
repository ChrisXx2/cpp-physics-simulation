#include "Particle.h"
#include <cmath>
#include <stdexcept>

Particle::Particle(
    double posX, 
    double posY, 
    double velX, 
    double velY, 
    double fX, 
    double fY, 
    double m, 
    double CArea
) : positionX(posX), positionY(posY), velocityX(velX), velocityY(velY), ForceX(fX), ForceY(fY), mass(m), cross_sectional_Area(CArea) {}

void Particle::update(double dt, double g) {
    double accelerationX = ForceX / mass;
    double accelerationY = ForceY / mass;
    velocityX += accelerationX * dt;
    velocityY += (accelerationY + g) * dt;
    positionX += velocityX * dt;
    positionY += velocityY * dt;
}

bool Particle::isValid(double value) const {
    return std::isfinite(value);
}

void Particle::applyForceX(double f) {
    ForceX += f;
}

void Particle::applyForceY(double f) {
    ForceY += f;
}

void Particle::clearForceX() {
    ForceX = 0;
}

void Particle::clearForceY() {
    ForceY = 0;
}

double Particle::getKineticEnergy() const {
    return 0.5 * mass * (pow(velocityX, 2) + pow(velocityY, 2));
}

double Particle::getPositionX() const {
    return positionX;
}

double Particle::getPositionY() const {
    return positionY;
}

double Particle::getVelocityX() const {
    return velocityX;
}

double Particle::getVelocityY() const {
    return velocityY;
}

void Particle::setPosition(double posX, double posY) {
    if (!isValid(posX) || !isValid(posY)) {
        throw std::invalid_argument("Invalid position");
    }
    positionX = posX;
    positionY = posY;
}

void Particle::setVelocity(double velX, double velY) {
    if (!isValid(velX) || !isValid(velY)) {
        throw std::invalid_argument("Invalid velocity");
    }
    velocityX = velX;
    velocityY = velY;
}