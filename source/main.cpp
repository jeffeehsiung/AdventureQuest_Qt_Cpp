// main.cpp
#include <QApplication>
#include <iostream>
#include "../headers/GameModel.h"
#include "../headers/GameView.h"
#include "../headers/GameController.h"

int main(int argc, char *argv[]) {
    std::cout << "Starting game..." << std::endl;

    QApplication app(argc, argv);

    GameModel *model = new GameModel();
    model->createWorld("assets/world_images/maze1.png", 10, 5, 0.25); // Example usage

    GameView *view = new GameView(model);
    GameController *controller = new GameController(model, view);

    view->show();

    return app.exec();
}
