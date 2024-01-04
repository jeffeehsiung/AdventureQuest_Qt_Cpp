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
#include <QKeyEvent>
#include <QMessageBox>
#include "Controller/GameController.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void displayView(QWidget* view);
    void updateHealthDisplay();
    void updateEnergyDisplay();

private:
    QWidget *centralWidget;
    QPushButton *startButton;
    QPushButton *pauseButton;
    QPushButton *quitButton;
    QVector<QLabel*> healthLabels;
    QLabel *energyLabel;
    QLabel *energyValueLabel;
    QSlider *animationDelaySlider;
    QSlider *heuristicWeightFactorSlider;
    QLabel *animationDelayLabel;
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

protected:
    void keyPressEvent(QKeyEvent *event) override;
    bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
    void onStartButtonClicked();
    void onPauseButtonClicked();
    void onAutoPlayButtonClicked();
    void onQuitButtonClicked();
    void onViewTabChanged(int index);
    void onViewUpdateRequested(QWidget* view);
    void displayText(const QString& text);
};

#endif // MAINWINDOW_H
