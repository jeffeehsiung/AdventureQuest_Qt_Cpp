#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <iostream>
#include "WorldModel.h"
#include "WorldController.h"
#include "WorldView.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //make q application then make main window.

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "mario_world_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    std::cout << "Starting game..." << std::endl;

    // initialize the main window to hold the game
    MainWindow window;
    window.setFixedSize(800, 600);
    window.setWindowTitle("Maze Game");
    window.show();
    // initialize the game model, view, and controller
    WorldModel *model = new WorldModel();
    model->createWorld("assets/world_images/maze1.png", 10, 5, 0.25); // Example usage

    WorldView *view = new WorldView(model);
    view->setParent(&window);

    WorldController *controller = new WorldController(model, view);
    controller->setParent(&window);

    // Set the GameView instance as the central widget of the QMainWindow
    window.setCentralWidget(view);

    // Set the QGraphicsScene from the GameModel to the GameView
    view->setScene(model->getScene());

    view->show();

    window.show();
    return a.exec();    // enter the q-event loop
}
