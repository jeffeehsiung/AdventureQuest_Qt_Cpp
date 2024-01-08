#include "Controller/WorldController.h"

WorldController::WorldController(){
    // Basic initializations, if any
}
void WorldController::createWorld(QString map, int gameNumberOfPlayers, int gameDifficultyIdx, float pRatio) {

    /**
     * given gameDifficultyIdx assign the number of healthpacks
    */
    int nrOfHealthpacks = 0;
    int nrOfEnemies = 0;
    switch (gameDifficultyIdx)
    {
    case 1:
        nrOfHealthpacks = 5;
        nrOfEnemies = 8;
        break;
    case 2:
        nrOfHealthpacks = 3;
        nrOfEnemies = 15;
        break;
    case 3:
        nrOfHealthpacks = 1;
        nrOfEnemies = 30;
        break;
    default:
        break;
    }
    difficultyIdx = gameDifficultyIdx;
    if(firstWorld){
        worlds.push_back(std::make_unique<WorldModel>(map, nrOfEnemies, nrOfHealthpacks, pRatio, true));
        firstWorld = false;
    }
    else{
        worlds.push_back(std::make_unique<WorldModel>(map, nrOfEnemies+3, nrOfHealthpacks, pRatio, false));
    }
    currentWorld = worlds[0];
    qDebug() << "Nearest Healthpack: " << currentWorld->findNearestHealthPack().getXPos() << " " << currentWorld->findNearestHealthPack().getYPos();
    qDebug() << "Nearest Enemy: " << currentWorld->findNearestEnemy().getXPos() << " " << currentWorld->findNearestEnemy().getYPos();
    qDebug() << "Nearest PEnemy: " << currentWorld->findNearestPEnemy().getXPos() << " " << currentWorld->findNearestPEnemy().getYPos();
    qDebug() << "Nearest XEnemy: " << currentWorld->findNearestXEnemy().getXPos() << " " << currentWorld->findNearestXEnemy().getYPos();
}

/**
 * size of world
 */
int WorldController::getRows() const
{
    return currentWorld->getRows();
}

int WorldController::getCols() const
{
    return currentWorld->getCols();
}

/**
 * getter and setters
 * */

// New method to access the map of tiles

int WorldController::getNumOfProtagonists() const
{
    /** return the size of protagonist vector */
    return currentWorld->getProtagonists().size();
}

int WorldController::getDifficultyIdx() const
{
    return difficultyIdx;
}


/**
 * defeated functions
 */

void WorldController::deleteEnemy(coordinate coord)
{
    currentWorld->deleteEnemy(coord);
}

void WorldController::deletePsnTile(coordinate coord)
{
    currentWorld->deletePsnTile(coord);
}



void WorldController::onUpArrowPressed() {

    // Get the current position of the protagonist
    coordinate currentPosition = currentWorld->getProtagonists()[0]->getPosition();
    // Calculate the new position
    int newX = currentPosition.xCoordinate;
    int newY = currentPosition.yCoordinate - 1;
    // Clamp the new position to ensure it's within the world boundaries
    if ((newX <= (currentWorld->getCols() -1)) && (newY <= (currentWorld->getRows() -1)) && (newY >= 0) ){
        // Move the protagonist up
        currentWorld->getProtagonists()[0]->move(0, -1);
        currentPosition = currentWorld->getProtagonists()[0]->getPosition();
        if (currentWorld->isEnemy(currentPosition)) {
            onEncounterEnemy();
        }
        else if (currentWorld->isHealthPack(currentPosition)) {
            onEncounterHealthPack();
        }
        else if (currentWorld->isPEnemy(currentPosition)){
            onEncounterPEnemy();
        }
        else if (currentWorld->isXEnemy(currentPosition)){
            onEncounterXEnemy();
        }
        else if(currentWorld->isAffectedTiles(currentPosition)){
            onEncounterAffectedTiles();
        }
        //        qDebug() << "tile value: "<< currentWorld->getTiles().at(newY*currentWorld->getCols()+newX)->getValue();
        emit updateprotagonistPosition(0);
    }
}

void WorldController::onDownArrowPressed() {

    // Get the current position of the protagonist
    coordinate currentPosition = currentWorld->getProtagonists()[0]->getPosition();
    // Calculate the new position
    int newX = currentPosition.xCoordinate;
    int newY = currentPosition.yCoordinate + 1;
    // Clamp the new position to ensure it's within the world boundaries
    if ((newX <= (currentWorld->getCols() -1)) && (newY <= (currentWorld->getRows() -1)) && (newY >= 0)){
        // Move the protagonist down
        currentWorld->getProtagonists()[0]->move(0, 1); // Assuming the first protagonist in the vector
        currentPosition = currentWorld->getProtagonists()[0]->getPosition();
        if (currentWorld->isEnemy(currentPosition)) {
            onEncounterEnemy();
        }
        else if (currentWorld->isHealthPack(currentPosition)) {
            onEncounterHealthPack();
        }
        else if (currentWorld->isPEnemy(currentPosition)){
            onEncounterPEnemy();
        }
        else if (currentWorld->isXEnemy(currentPosition)){
            onEncounterXEnemy();
        }
        else if(currentWorld->isAffectedTiles(currentPosition)){
            onEncounterAffectedTiles();
        }
        emit updateprotagonistPosition(0);
        //        qDebug() << "tile value: "<< currentWorld->getTiles().at(newY*currentWorld->getCols()+newX)->getValue();
    }
}

void WorldController::onLeftArrowPressed() {
    // Get the current position of the protagonist
    coordinate currentPosition = currentWorld->getProtagonists()[0]->getPosition();
    // Calculate the new position
    int newX = currentPosition.xCoordinate - 1;
    int newY = currentPosition.yCoordinate;
    // Clamp the new position to ensure it's within the world boundaries
    if ((newX >= 0) && (newX <= (currentWorld->getCols() -1)) && (newY <= (currentWorld->getRows() -1))){
        // Move the protagonist left
        currentWorld->getProtagonists()[0]->move(-1, 0); // Assuming the first protagonist in the vector
        currentPosition = currentWorld->getProtagonists()[0]->getPosition();
        if (currentWorld->isEnemy(currentPosition)) {
            onEncounterEnemy();
        }
        else if (currentWorld->isHealthPack(currentPosition)) {
            onEncounterHealthPack();
        }
        else if (currentWorld->isPEnemy(currentPosition)){
            onEncounterPEnemy();
        }
        else if (currentWorld->isXEnemy(currentPosition)){
            onEncounterXEnemy();
        }
        else if(currentWorld->isAffectedTiles(currentPosition)){
            onEncounterAffectedTiles();
        }
        emit updateprotagonistPosition(0);
        //        qDebug() << "tile value: "<< currentWorld->getTiles().at(newY*currentWorld->getCols()+newX)->getValue();
    }
}

void WorldController::onRightArrowPressed() {
    // Get the current position of the protagonist
    coordinate currentPosition = currentWorld->getProtagonists()[0]->getPosition();
    // Calculate the new position
    int newX = currentPosition.xCoordinate + 1;
    int newY = currentPosition.yCoordinate;
    // Clamp the new position to ensure it's within the world boundaries
    if ((newX >= 0) && (newX <= (currentWorld->getCols() -1)) && (newY <= (currentWorld->getRows() -1))){
        // Move the protagonist right
        currentWorld->getProtagonists()[0]->move(1, 0); // Assuming the first protagonist in the vector
        currentPosition = currentWorld->getProtagonists()[0]->getPosition();
        if (currentWorld->isEnemy(currentPosition)) {
            onEncounterEnemy();
        }
        else if (currentWorld->isHealthPack(currentPosition)) {
            onEncounterHealthPack();
        }
        else if (currentWorld->isPEnemy(currentPosition)){
            onEncounterPEnemy();
        }
        else if (currentWorld->isXEnemy(currentPosition)){
            onEncounterXEnemy();
        }
        else if(currentWorld->isAffectedTiles(currentPosition)){
            onEncounterAffectedTiles();
        }
        emit updateprotagonistPosition(0);
        qDebug() << "tile value: "<< currentWorld->getTiles().at(newY*currentWorld->getCols()+newX)->getValue();
    }

}

void WorldController::onEncounterEnemy() {
    qDebug() << "Encountered an enemy!" << "\n";
    if (currentWorld->getProtagonists()[0]->getHealth() > 0) {
        currentWorld->getProtagonists()[0]->attack();
        currentWorld->currentEnemy->attack();
    }
    else {
        currentWorld->getProtagonists()[0]->setHealth(0);
        qDebug() << "You died!" << "\n";
    }
    autoplay();
}

void WorldController::onEncounterHealthPack() {
    qDebug() << "Encountered a health pack!" << "\n";
    if (currentWorld->getProtagonists()[0]->getHealth() < 5) {
        currentWorld->getProtagonists()[0]->setHealth(currentWorld->getProtagonists()[0]->getHealth() + 1);
        currentWorld->removeHealthpack(currentWorld->getProtagonists()[0]->getPosition());
    }
    else {
        qDebug() << "Health is full!" << "\n";
    }
}

void WorldController::onEncounterPEnemy() {
    qDebug() << "Encountered an penemy!" << "\n";
    if (currentWorld->getProtagonists()[0]->getHealth() > 0) {
        currentWorld->getProtagonists()[0]->attack();
        currentWorld->currentPEnemy->attack();
        currentWorld->setAffectedTiles(false, currentWorld->currentPEnemy->getPoisonLevel());
    }
    else {
        currentWorld->getProtagonists()[0]->setHealth(0);
    };
}

void WorldController::onEncounterXEnemy() {
    qDebug() << "Encountered an XEnemy!" << "\n";
    auto& protagonist = currentWorld->getProtagonists()[0];
    if (protagonist->getHealth() > 0) {
        protagonist->attack();
        float damage = 10.0f;
        currentWorld->currentXEnemy->takeDamage(damage);
        currentWorld->setAffectedTiles(true, currentWorld->currentXEnemy->getThunderLevel());
    } else {
        protagonist->setHealth(0);
    }
}


void WorldController::onEncounterAffectedTiles(){
    qDebug() << "Encountered a affected tile!" << "\n";
    if (currentWorld->getProtagonists()[0]->getHealth() > 0) {
        float damage = 0.2f;
        currentWorld->getProtagonists()[0]->takeDamage(damage);
        qDebug() << "Health: " << currentWorld->getProtagonists()[0]->getHealth() << "\n";
    }
    else {
        currentWorld->getProtagonists()[0]->setHealth(0);
    }
}


void WorldController::moveProtagonist(Direction direction) {
    // Get the current position of the protagonist
    coordinate currentPosition = currentWorld->getProtagonists()[0]->getPosition();

    // Calculate the new position based on direction
    int newX = currentPosition.xCoordinate;
    int newY = currentPosition.yCoordinate;

    switch (direction) {
    case UP:    newY--; break;
    case DOWN:  newY++; break;
    case LEFT:  newX--; break;
    case RIGHT: newX++; break;
    }

    // Clamp the new position to ensure it's within the world boundaries
    if (newX >= 0 && newX < currentWorld->getCols() && newY >= 0 && newY < currentWorld->getRows()) {
        // Move the protagonist
        currentWorld->getProtagonists()[0]->move(newX - currentPosition.xCoordinate, newY - currentPosition.yCoordinate);

        // Perform checks after movement
        if (currentWorld->getProtagonists()[0]->getEnergy() > 0) {
            currentWorld->getProtagonists()[0]->setEnergy(currentWorld->getProtagonists()[0]->getEnergy() - currentWorld->valueEnergyComsumingTiles(currentWorld->getProtagonists()[0]->getPosition()));
        }
        // if (currentWorld->isEnergyRestoringTiles(currentWorld->getProtagonists()[0]->getPosition())) {
        //     if (currentWorld->getProtagonists()[0]->getEnergy() > 0 && currentWorld->getProtagonists()[0]->getEnergy() < 100) {
        //         currentWorld->getProtagonists()[0]->setEnergy(currentWorld->getProtagonists()[0]->getEnergy() + 30);
        //         if (currentWorld->getProtagonists()[0]->getEnergy() > 100) {
        //             currentWorld->getProtagonists()[0]->setEnergy(100);
        //         }
        //     }
        //     currentWorld->setEnergyRestoringTilesZero(currentWorld->getProtagonists()[0]->getPosition());
        // }
        // if (currentWorld->isEnergyBoostTiles(currentWorld->getProtagonists()[0]->getPosition())) {
        //     if (currentWorld->getProtagonists()[0]->getEnergy() > 0 && currentWorld->getProtagonists()[0]->getEnergy() < 100) {
        //         currentWorld->getProtagonists()[0]->setEnergy(currentWorld->getProtagonists()[0]->getEnergy() + 100);
        //         if (currentWorld->getProtagonists()[0]->getEnergy() > 100) {
        //             currentWorld->getProtagonists()[0]->setEnergy(100);
        //         }
        //     }
        //     currentWorld->setEnergyRestoringTilesZero(currentWorld->getProtagonists()[0]->getPosition());
        // }
        // if (currentWorld->isEnergyHealthBoostTiles(currentWorld->getProtagonists()[0]->getPosition())) {
        //     qDebug() << "Encountered a energy health boost tile!!!!!" << "\n";
        //     if (currentWorld->getProtagonists()[0]->getEnergy() > 0 && currentWorld->getProtagonists()[0]->getEnergy() < 100) {
        //         currentWorld->getProtagonists()[0]->setEnergy(currentWorld->getProtagonists()[0]->getEnergy() + 100);
        //         if (currentWorld->getProtagonists()[0]->getEnergy() > 100) {
        //             currentWorld->getProtagonists()[0]->setEnergy(100);
        //         }
        //     }
        //     if (currentWorld->getProtagonists()[0]->getHealth() > 0 && currentWorld->getProtagonists()[0]->getHealth() < 5) {
        //         currentWorld->getProtagonists()[0]->setHealth(currentWorld->getProtagonists()[0]->getHealth() + 5);
        //     }
        //     // currentWorld->setEnergyRestoringTilesZero(currentWorld->getProtagonists()[0]->getPosition());
        // }
        int tempEnemy = flagEnemy;
        flagEnemy = currentWorld->getEnemies().size() - currentWorld->getEnemyCounts();
        if (tempEnemy != flagEnemy) {
            currentWorld->getProtagonists()[0]->setEnergy(currentWorld->getProtagonists()[0]->getEnergy() + 10);
            if (currentWorld->getProtagonists()[0]->getEnergy() > 100) {
                currentWorld->getProtagonists()[0]->setEnergy(100);
            }
        }

        int tempPEnemy = flagPEnemy;
        flagPEnemy = currentWorld->getPEnemies().size() - currentWorld->getPEnemyCounts();
        if (tempPEnemy != flagPEnemy) {
            currentWorld->getProtagonists()[0]->setEnergy(currentWorld->getProtagonists()[0]->getEnergy() + 30);
            if (currentWorld->getProtagonists()[0]->getEnergy() > 100) {
                currentWorld->getProtagonists()[0]->setEnergy(100);
            }
        }

        int tempXEnemy = flagXEnemy;
        flagXEnemy = currentWorld->getXEnemies().size() - currentWorld->getXEnemyCounts();
        if (tempXEnemy != flagXEnemy) {
            currentWorld->getProtagonists()[0]->setEnergy(currentWorld->getProtagonists()[0]->getEnergy() + 50);
            if (currentWorld->getProtagonists()[0]->getEnergy() > 100) {
                currentWorld->getProtagonists()[0]->setEnergy(100);
            }
            currentWorld->getProtagonists()[0]->setHealth(currentWorld->getProtagonists()[0]->getHealth() + 5);
            if (currentWorld->getProtagonists()[0]->getHealth() > 5) {
                currentWorld->getProtagonists()[0]->setHealth(5);
            }
        }

        currentPosition = currentWorld->getProtagonists()[0]->getPosition();
        handleEncounters(currentPosition);

        emit updateprotagonistPosition(0);
    }
    playerReachedExit();

}

void WorldController::moveProtagonist(int x, int y) {
    // Clamp the new position to ensure it's within the world boundaries
    if (x >= 0 && x < currentWorld->getCols() && y >= 0 && y < currentWorld->getRows()) {
        // Move the protagonist
        currentWorld->getProtagonists()[0]->move(x, y);

        // Perform checks after movement
        coordinate currentPosition = currentWorld->getProtagonists()[0]->getPosition();
        handleEncounters(currentPosition);

        emit updateprotagonistPosition(0);
    }
}

void WorldController::handleEncounters(const coordinate& position) {
    if (currentWorld->isEnemy(position)) {
        onEncounterEnemy();
    } else if (currentWorld->isHealthPack(position)) {
        onEncounterHealthPack();
    } else if (currentWorld->isPEnemy(position)) {
        onEncounterPEnemy();
    } else if (currentWorld->isXEnemy(position)) {
        onEncounterXEnemy();
    } else if (currentWorld->isAffectedTiles(position)) {
        onEncounterAffectedTiles();
    }
}


void WorldController::playerReachedExit() {

    if (currentWorld->getProtagonists()[0]->getPosition() == currentWorld->getExit()) {
        // Ensure that the next world exists
        if (worlds.size() > 1) {
            auto it = std::find(worlds.begin(), worlds.end(), currentWorld);
            size_t position = 0;
            if (it != worlds.end()) {
                // Calculate the position/index of currentWorld in the vector
                position = std::distance(worlds.begin(), it);
                qDebug() << "Current world is at position " << position;
                if(position >= 4){
                    //WINGAME
                }
            } else {
                qDebug() << "Current world not found in the vector!";
            }

            auto protagonists = currentWorld->removeProtagonists();
            // Update the protagonist's position to the start position of the new world
            coordinate newStartPos = worlds[position + 1]->getStart();
            for (auto& prot : protagonists) {
                prot->setPosition(newStartPos);
            }

            currentWorld = worlds[position + 1]; // Transfer ownership to the next world
            currentWorld->addProtagonist(std::move(protagonists));

            emit updateLevel();
            emit updateprotagonistPosition(0);
            qDebug() << "LevelSwitched!" << "\n";
        } else {
            // Handle the case where the next world does not exist
            qDebug() << "Next world does not exist!";
        }
    }
    else if(currentWorld->getProtagonists()[0]->getPosition() == currentWorld->getStart()) {
        // Ensure that the next world exists
        if (worlds.size() > 1) {
            auto it = std::find(worlds.begin(), worlds.end(), currentWorld);
            size_t position = 0;
            if (it != worlds.end()) {
               // Calculate the position/index of currentWorld in the vector
                position = std::distance(worlds.begin(), it);
                qDebug() << "Current world is at position " << position;
                if(position == 0){
                return;
                }
            }    else {
                qDebug() << "Current world not found in the vector!";
            }

            auto protagonists = currentWorld->removeProtagonists();
            // Update the protagonist's position to the start position of the new world
            coordinate newStartPos = worlds[position - 1]->getExit();

            for (auto& prot : protagonists) {
                prot->setPosition(newStartPos);
            }

            currentWorld = worlds[position - 1]; // Transfer ownership to the next world
            currentWorld->addProtagonist(std::move(protagonists));

            emit updateLevel();
            emit updateprotagonistPosition(0);
            qDebug() << "LevelSwitched!" << "\n";
        } else {
            // Handle the case where the next world does not exist
            qDebug() << "Next world does not exist!";
        }
   }
}


/**
 * start and exit position functions
 */


const std::vector<std::shared_ptr<WorldModel>>& WorldController::getWorlds() const {
    return worlds;
}

const WorldModel& WorldController::getCurrentWorld() const {
    if (!currentWorld) {
        throw std::runtime_error("Current world is not initialized.");
    }
    return *currentWorld;
}



void WorldController::autoplay(){
   Comparator<node> comparator = [](const node& a, const node& b) {
        return (a.f) > (b.f);  // Assuming you want the node with the lowest 'f' value on top
   };
   qDebug() << "start Pos: " << currentWorld->getStart().getXPos() << " "<< currentWorld->getStart().getYPos();
   qDebug() << "exit Pos: " << currentWorld->getExit().getXPos() << " "<< currentWorld->getExit().getYPos();
   PathFinder<node,coordinate> pathFinder(currentWorld->nodes, currentWorld->getProtagonists()[0]->getPositionValue(), currentWorld->getExitValue(), comparator, this->getRows(), 0);

   std::vector<int> result = pathFinder.A_star();
   qDebug() << "Path to destination:" << result;
   for (int move : result) {
        qDebug() << move << "path";
        switch(move){
            case 0:
                moveProtagonistWithDelay(UP);
                break;
            case 1:
                moveProtagonistWithDelay(RIGHT);
                moveProtagonistWithDelay(UP);
                break;
            case 2:
                moveProtagonistWithDelay(RIGHT);
                break;
            case 3:
                moveProtagonistWithDelay(RIGHT);
                moveProtagonistWithDelay(DOWN);
                break;
            case 4:
                moveProtagonistWithDelay(DOWN);
                break;
            case 5:
                moveProtagonistWithDelay(DOWN);
                moveProtagonistWithDelay(LEFT);
                break;
            case 6:
                moveProtagonistWithDelay(LEFT);
                break;
            case 7:
                moveProtagonistWithDelay(LEFT);
                moveProtagonistWithDelay(UP);
                break;
            default:
                // Handle unexpected move values
                break;
        }
   }
}

void WorldController::moveProtagonistWithDelay(Direction direction) {
   moveProtagonist(direction);

   // Introduce a delay using QTimer
   QTimer timer;
   connect(&timer, &QTimer::timeout, [&]() {
       // Code to be executed after the delay
       timer.stop();  // Stop the timer after the delay
   });

   // Set the delay time (adjust as needed, 1000 = 1 second)
   timer.start(500);  // 1000 milliseconds = 1 second
   QEventLoop loop;
   connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
   loop.exec();
}









