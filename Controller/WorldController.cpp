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
    worlds.push_back(std::make_unique<WorldModel>(map, nrOfEnemies, nrOfHealthpacks, pRatio, true));
    worlds.push_back(std::make_unique<WorldModel>(map, nrOfEnemies + 3, nrOfHealthpacks, pRatio, false));
    currentWorld = std::move(worlds[0]); // Transfer ownership
//    autoplay();
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
    return currentWorld->protagonists.size();
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
    playerReachedExit();
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
    playerReachedExit();
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
    playerReachedExit();
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
//        qDebug() << "tile value: "<< currentWorld->getTiles().at(newY*currentWorld->getCols()+newX)->getValue();
    }
    playerReachedExit();
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

void WorldController::playerReachedExit() {

    if (currentWorld->getProtagonists()[0]->getPosition() == currentWorld->getExit()) {
        // Ensure that the next world exists
        if (worlds.size() > 1 && worlds[1]) {
            auto protagonist = std::move(currentWorld->removeProtagonists());

            // Update the protagonist's position to the start position of the new world
            coordinate newStartPos = worlds[1]->getStart();
            for (auto& prot : protagonist) {
                prot->setPosition(newStartPos);
            }

            currentWorld = std::move(worlds[1]); // Transfer ownership to the next world
            currentWorld->addProtagonist(std::move(protagonist));

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

coordinate WorldController::getStart()
{
    return currentWorld->getStart();
}

coordinate WorldController::getExit()
{
    return currentWorld->getStart();
}

const std::vector<std::unique_ptr<WorldModel>>& WorldController::getWorlds() const {
    return worlds;
}

const WorldModel& WorldController::getCurrentWorld() const {
    if (!currentWorld) {
        throw std::runtime_error("Current world is not initialized.");
    }
    return *currentWorld;
}



//void WorldController::autoplay(){
//   Comparator<node> comparator = [](const node& a, const node& b) {
//        return (a.f) > (b.f);  // Assuming you want the node with the lowest 'f' value on top
//   };
//   qDebug() << "start Pos: " << currentWorld->getStart().getXPos() << " "<< currentWorld->getStart().getYPos();
//   qDebug() << "exit Pos: " << currentWorld->getExit().getXPos() << " "<< currentWorld->getExit().getYPos();
//   PathFinder<node,coordinate> pathFinder(currentWorld->nodes, currentWorld->getStartValue(), currentWorld->getExitValue(), comparator, this->getRows(), 0);

//   std::vector<int> result = pathFinder.A_star();
//   qDebug() << "Path to destination:";
//   for (int move : result) {
//        qDebug() << move << "path";
//   }
//}








