#include "ProtagonistModel.h"

ProtagonistModel::ProtagonistModel(std::unique_ptr<Protagonist> protagonist)
    : protagonist(std::move(protagonist)) {
    connect(this->protagonist.get(), &Protagonist::posChanged, this, &ProtagonistModel::onPosChanged);
    connect(this->protagonist.get(), &Protagonist::healthChanged, this, &ProtagonistModel::onHealthChanged);
    connect(this->protagonist.get(), &Protagonist::energyChanged, this, &ProtagonistModel::oneEnergyChanged);
}

void ProtagonistModel::attack() {
    status = ATTACK;
    qDebug() << "your status: " << status;
    float damage = 1.0f;
    takeDamage(damage);
}

void ProtagonistModel::takeDamage(float damage) {
    if (protagonist) {
        float currentHealth = protagonist->getHealth();
        float newHealth = currentHealth - damage;
        status = HURT;
        qDebug() << "your status: " << status;
        newHealth = std::max(0.0f, newHealth);
        protagonist->setHealth(newHealth);
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
    QTimer::singleShot(500, this, [this]() {
        status = IDLE;
    });
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
    QTimer::singleShot(500, this, [this]() {
        status = IDLE;
    });
    qDebug() << "your status: " << status;
}

void ProtagonistModel::onHealthChanged(int h){
    if(h == 0){
        status = DYING;
        qDebug() << "You died!";
    }
    QTimer::singleShot(500, this, [this]() {
        status = IDLE;
    });
    qDebug() << "your status: " << status;
}
void ProtagonistModel::oneEnergyChanged(int e){
    if(e == 0){
        status = DYING;
        qDebug() << "You died!";
    }
    QTimer::singleShot(500, this, [this]() {
        status = IDLE;
    });
    qDebug() << "your status: " << status;
}


