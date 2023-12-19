#include "ProtagonistModel.h"

ProtagonistModel::ProtagonistModel(std::unique_ptr<Protagonist> protagonist)
    : protagonist(std::move(protagonist)) {
    connect(this->protagonist.get(), &Protagonist::posChanged, this, &ProtagonistModel::onPosChanged);
    connect(this->protagonist.get(), &Protagonist::healthChanged, this, &ProtagonistModel::onHealthChanged);
    connect(this->protagonist.get(), &Protagonist::energyChanged, this, &ProtagonistModel::oneEnergyChanged);
}

void ProtagonistModel::attack() {
    status = ATTACK;
    float damage = 1.0f;
    QTimer::singleShot(100, this, [this, damage]() {
        this->takeDamage(damage);
    });
}

void ProtagonistModel::takeDamage(float damage) {
    if (protagonist) {
        status = HURT;
        QTimer::singleShot(100, this, [this, damage]() {
            float currentHealth = protagonist->getHealth();
            float newHealth = currentHealth - damage;
            newHealth = std::max(0.0f, newHealth);
            setHealth(newHealth);
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
    QTimer::singleShot(100, this, [this]() {status = IDLE;});
    QTimer::singleShot(100, this, [this]() {status = IDLE;});
}

void ProtagonistModel::onHealthChanged(int h){
    if(h <= 0){
        status = DYING;
        qDebug() << "Your health is 0!";
    }
}

void ProtagonistModel::oneEnergyChanged(int e){
    if(e <= 0){
        status = DYING;
        qDebug() << "your energy is 0!";
    }

}


