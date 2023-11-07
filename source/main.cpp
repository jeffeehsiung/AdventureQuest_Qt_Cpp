// main.cpp
#include <QApplication>
#include <QMainWindow>
#include <iostream>
#include "../headers/GameModel.h"
#include "../headers/GameView.h"
#include "../headers/GameController.h"

int main(int argc, char *argv[]) {
    std::cout << "Starting game..." << std::endl;

    QApplication app(argc, argv);

    // initialize the main window to hold the game
    QMainWindow window;
    window.setFixedSize(800, 600);
    window.setWindowTitle("Maze Game");
    window.show();
    // initialize the game model, view, and controller
    GameModel *model = new GameModel();
    model->createWorld("assets/world_images/maze1.png", 10, 5, 0.25); // Example usage

    GameView *view = new GameView(model);
    view->setParent(&window);

    GameController *controller = new GameController(model, view);
    controller->setParent(&window);

    // Set the GameView instance as the central widget of the QMainWindow
    window.setCentralWidget(view);

    // Set the QGraphicsScene from the GameModel to the GameView
    view->setScene(model->getScene());

    view->show();

    return app.exec();
}
