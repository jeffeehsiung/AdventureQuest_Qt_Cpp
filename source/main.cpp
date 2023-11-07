#include <QApplication>
#include "../headers/GameModel.h"
#include "../headers/GameView.h"
#include "../headers/GameController.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Instantiate the MVC components
    GameModel *model = new GameModel();
    GameView *view = new GameView(model);
    new GameController(model, view); // Controller is allocated on the heap and doesn't need to be assigned to a variable

    // Configure the view
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();

    // Start the application's event loop
    return app.exec();
}
