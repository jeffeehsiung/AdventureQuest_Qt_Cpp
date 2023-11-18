#ifndef PROTAGONISTMODEL_H
#define PROTAGONISTMODEL_H

#include "world.h" // Include the World header file

class ProtagonistModel : public Protagonist {
    // Inherits all public and protected members from Protagonist

public:
    explicit ProtagonistModel(QObject *parent = nullptr) : Protagonist(parent) {
        // Constructor code specific to ProtagonistModel
    }

    // Additional methods specific to the ProtagonistModel
};

#endif // PROTAGONISTMODEL_H
