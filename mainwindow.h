#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include "GameView.h" // Replace with the correct path if necessary

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setupViews();

private:
    QGraphicsView* graphicsView;            // Pointer to a QGraphicsView
    // GameView* viewController;     // Pointer to a GameViewController
    Ui::MainWindow* ui;                     // Pointer to the UI class for MainWindow
};

#endif // MAINWINDOW_H
