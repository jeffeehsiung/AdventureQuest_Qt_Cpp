#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
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
    void displayView(QWidget* view);

private:
    QWidget *centralWidget;
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

    GameController* gameController;

    void setupUI();

signals:


private slots:
    void onStartButtonClicked();
    void onPauseButtonClicked();
    void onAutoPlayButtonClicked();
    void onQuitButtonClicked();
    void onViewTabChanged(int index);
    void onViewUpdateRequested(QWidget* view);
};

#endif // MAINWINDOW_H
