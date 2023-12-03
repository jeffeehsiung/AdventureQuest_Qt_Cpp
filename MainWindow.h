//#ifndef MAINWINDOW_H
//#define MAINWINDOW_H

//#include <QMainWindow>
//#include <QGraphicsView>
//#include <QPushButton>
//#include <QSlider>
//#include <QLabel>
//#include <QComboBox>
//#include <QTextEdit>
//#include <QTabWidget>
//#include "Controller/GameController.h"

//class MainWindow : public QMainWindow
//{
//    Q_OBJECT

//public:
//    explicit MainWindow(QWidget *parent = nullptr);
//    ~MainWindow();

//private:
//    GameController *gameController;
//    QWidget *centralWidget;
//    QTabWidget *viewTabs;
//    QGraphicsView *graphicsView, *textualView;
//    QPushButton *startButton, *pauseButton, *quitButton, *autoPlayButton;
//    QComboBox *playerNumberComboBox, *difficultyLevelComboBox;
//    QTextEdit *graphicsMessageWidget, *textualMessageWidget;
//    bool isGamePaused;

//    void setupUI();
//    void updateButtonStates();

//private slots:
//    void onStartButtonClicked();
//    void onPauseButtonClicked();
//    void onAutoPlayButtonClicked();
//    void onQuitButtonClicked();
//    void onViewTabChanged(int index);
//};

//#endif // MAINWINDOW_H


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QTextEdit>
#include <QComboBox>
#include <QTabWidget>

#include "Controller/GameController.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QGraphicsView *textualView;
    QPushButton *startButton;
    QPushButton *pauseButton;
    QPushButton *quitButton;
    QSlider *energySlider;
    QSlider *healthSlider;
    QSlider *animationDelaySlider;
    QSlider *heightFactorSlider;
    QSlider *heuristicWeightFactorSlider;
    QLabel *energyLabel;
    QLabel *healthLabel;
    QLabel *animationDelayLabel;
    QLabel *heightFactorLabel;
    QLabel *heuristicWeightFactorLabel;
    QTabWidget *viewTabs;
    QWidget *graphicsTab;
    QWidget *textualTab;
    QPushButton *autoPlayButton;
    QComboBox *playerNumberComboBox;
    QComboBox *difficultyLevelComboBox;
    QLabel *playerNumberLabel;
    QLabel *difficultyLevelLabel;
    QTextEdit *graphicsMessageWidget;
    QTextEdit *textualMessageWidget;

    bool isGamePaused;

    GameController *gameController;

    void setupUI();

private slots:
    void onStartButtonClicked();
    void onPauseButtonClicked();
    void onAutoPlayButtonClicked();
    void onQuitButtonClicked();
    void onViewTabChanged(int index);
};

#endif // MAINWINDOW_H
