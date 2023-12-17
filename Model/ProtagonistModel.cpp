#include "ProtagonistModel.h"

ProtagonistModel::ProtagonistModel(std::unique_ptr<Protagonist> protagonist)
    : protagonist(std::move(protagonist)) {
    connect(this->protagonist.get(), &Protagonist::posChanged, this, &ProtagonistModel::onPosChanged);
    connect(this->protagonist.get(), &Protagonist::healthChanged, this, &ProtagonistModel::onHealthChanged);
    connect(this->protagonist.get(), &Protagonist::energyChanged, this, &ProtagonistModel::oneEnergyChanged);
}

void ProtagonistModel::attack() {
    status = ATTACK;
    qDebug() << "your start attack timer status: " << status;
    float damage = 1.0f;
    // Using a lambda function as the slot
    QTimer::singleShot(300, this, [this, damage]() {
        this->takeDamage(damage);
    });
}

void ProtagonistModel::takeDamage(float damage) {
    if (protagonist) {
        status = HURT;
        qDebug() << "your take damage status: " << status;
        // Schedule the following block to be executed after 300 ms
        QTimer::singleShot(100, this, [this, damage]() {
            float currentHealth = protagonist->getHealth();
            float newHealth = currentHealth - damage;
            newHealth = std::max(0.0f, newHealth);
            protagonist->setHealth(newHealth);
        });
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
    status = MOVING;
    protagonist->setXPos(protagonist->getXPos() + deltaX);
    protagonist->setYPos(protagonist->getYPos() + deltaY);
}

int ProtagonistModel::getHealth() const {
    return protagonist->getHealth();
}

void ProtagonistModel::setHealth(float health) {
    protagonist->setHealth(health);
}

int ProtagonistModel::getEnergy() const {
    return protagonist->getEnergy();
}

void ProtagonistModel::setEnergy(float energy) {
    protagonist->setEnergy(energy);
}

std::string ProtagonistModel::serialize() const {
    // Serialize the current status of the protagonist.
    return protagonist->serialize();
}

void ProtagonistModel::onPosChanged(int x, int y){
//    QTimer::singleShot(100, this, [this]() {qDebug() << "your position changed status: " << status;});
}

void ProtagonistModel::onHealthChanged(int h){
    if(h <= 0){
        status = DYING;
        QTimer::singleShot(100, this, [this]() {qDebug() << "You died!";});
    }
    qDebug() << "your status: " << status;
}
void ProtagonistModel::oneEnergyChanged(int e){
    if(e <= 0){
        qDebug() << "your status after energy changed: " << status;
    }

}


