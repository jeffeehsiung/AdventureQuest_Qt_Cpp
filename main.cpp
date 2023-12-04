#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Main function or similar initialization code
    MainWindow mainWindow;
    mainWindow.show();
    return a.exec();
}
