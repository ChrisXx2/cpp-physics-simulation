#include "Particle.h"
#include <cmath>
#include <stdexcept>

Particle::Particle(
    double posX, 
    double posY, 
    double velX,
    double terminalVelX,
    double velY,
    double terminalVelY,
    double m, 
    double CArea
) : positionX(posX), positionY(posY), velocityX(velX), terminalVelocityX(terminalVelX), 
    velocityY(velY), terminalVelocityY(terminalVelY), ForceX(0.0), ForceY(0.0), 
    mass(m), cross_sectional_Area(CArea) {
    
    if (mass <= 0) {
        throw std::invalid_argument("Mass must be positive");
    }
    if (CArea <= 0) {
        throw std::invalid_argument("Cross-sectional area must be positive");
    }
}

void Particle::initialize(double dt, double g) {
    velocityX += (ForceX / mass) * dt;
    velocityY += (g + (ForceY / mass)) * dt;
}

void Particle::update(double dt, double g, double dragCoeff, double atmDensity) {
    velocityX -= (dragCoeff * atmDensity * cross_sectional_Area * velocityX * std::abs(velocityX) / (2.0 * mass)) * dt;
    
    if (terminalVelocityY == 0.0) {
        terminalVelocityY = std::sqrt((2.0 * mass * g) / (atmDensity * cross_sectional_Area * dragCoeff));
    }
    
    double dragForceY = 0.5 * dragCoeff * atmDensity * cross_sectional_Area * velocityY * std::abs(velocityY);
    double netAccelY = g - (dragForceY / mass);
    velocityY += netAccelY * dt;
    
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
    return 0.5 * mass * (std::pow(velocityX, 2) + std::pow(velocityY, 2));
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

double Particle::getTerminalVelocityX() const {
    return terminalVelocityX;
}

double Particle::getTerminalVelocityY() const {
    return terminalVelocityY;
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

void Particle::setTerminalVelocity(double velX, double dt, double g, double dragCoeff, double atmDensity) {
    if (!isValid(velX)) {
        throw std::invalid_argument("Invalid velocity");
    }
    terminalVelocityX = std::sqrt((2.0 * mass * std::abs(velX / dt)) / (atmDensity * cross_sectional_Area * dragCoeff));
    terminalVelocityY = std::sqrt((2.0 * mass * g) / (atmDensity * cross_sectional_Area * dragCoeff));
}