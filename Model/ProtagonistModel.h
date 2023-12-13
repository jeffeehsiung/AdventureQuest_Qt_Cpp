#ifndef PROTAGONISTMODEL_H
#define PROTAGONISTMODEL_H

#include <memory>
#include "Entity.h"

class ProtagonistModel : public Entity {
    Q_OBJECT
    public:
        explicit ProtagonistModel(std::unique_ptr<Protagonist> protagonist); // Constructor declaration

        void attack() override;
        void takeDamage(float damage) override;
        coordinate getPosition() const override;
        void setPosition(coordinate position) override;
        void move(int deltaX, int deltaY) override;

        // Additional functionalities specific to ProtagonistModel
        int getHealth() const;
        void setHealth(float health);
        int getEnergy() const;
        void setEnergy(float energy);
        std::string serialize() const;

    public slots:
        void onPosChanged(int x, int y);
        void onHealthChanged(int h);
        void oneEnergyChanged(int e);

    private:
        std::unique_ptr<Protagonist> protagonist;
};

#endif // PROTAGONISTMODEL_H
