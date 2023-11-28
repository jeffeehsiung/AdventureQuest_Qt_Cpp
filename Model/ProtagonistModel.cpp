#include "ProtagonistModel.h"

ProtagonistModel::ProtagonistModel(Protagonist* protagonist) : protagonist(protagonist) {}

void ProtagonistModel::attack() {
    // Protagonist's attack implementation
}

void ProtagonistModel::takeDamage(float damage) {
    if (protagonist) {
        // Get current health
        float currentHealth = protagonist->getHealth();

        // Calculate new health after taking damage
        float newHealth = currentHealth - damage;

        // Ensure new health is not less than zero
        newHealth = std::max(0.0f, newHealth);

        // Update Protagonist's health
        protagonist->setHealth(newHealth);

        // Additional logic can be added here as needed
    }
}

coordinate ProtagonistModel::getPosition() const {
    return {protagonist->getXPos(), protagonist->getYPos()};
}

void ProtagonistModel::setPosition(coordinate position) {
    protagonist->setXPos(position.xCoordinate);
    protagonist->setYPos(position.yCoordinate);
}

void ProtagonistModel::move(int deltaX, int deltaY) {
    protagonist->setXPos(protagonist->getXPos() + deltaX);
    protagonist->setYPos(protagonist->getYPos() + deltaY);
}
