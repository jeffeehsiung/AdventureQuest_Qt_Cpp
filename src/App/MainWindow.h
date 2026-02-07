#ifndef AQ_APP_MAINWINDOW_H
#define AQ_APP_MAINWINDOW_H

#include "Core/Types.h"
#include "App/GameController.h"
#include "Renderer/HUD.h"
#include "Renderer/TouchOverlay.h"
#include "Platform/PlatformConfig.h"

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

namespace AQ {

// MainWindow is the top-level application window.
// On desktop: shows control panel, tabbed views, and status bar.
// On iOS: shows full-screen game view with touch overlay and compact HUD.

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;

private slots:
    void onStartClicked();
    void onPauseClicked();
    void onAutoPlayClicked();
    void onQuitClicked();
    void onViewReady(QWidget* view);
    void onStatusUpdated(int health, float energy);
    void onGameWon();
    void onGameLost();
    void onAutoPlayDone();
    void onTextMessage(const QString& text);

private:
    void setupDesktopUI();
    void setupMobileUI();
    Difficulty selectedDifficulty() const;

    GameController* controller_;
    HUD* hud_ = nullptr;

    // Desktop UI
    QWidget* centralWidget_ = nullptr;
    QTabWidget* viewTabs_ = nullptr;
    QWidget* graphicsTab_ = nullptr;
    QTextEdit* messageWidget_ = nullptr;

    QPushButton* startBtn_ = nullptr;
    QPushButton* pauseBtn_ = nullptr;
    QPushButton* autoPlayBtn_ = nullptr;
    QPushButton* quitBtn_ = nullptr;

    QComboBox* difficultyCombo_ = nullptr;
    QComboBox* playerCountCombo_ = nullptr;
    QSlider* heuristicSlider_ = nullptr;

    // Mobile UI
    TouchOverlay* touchOverlay_ = nullptr;

    bool isPaused_ = false;
};

} // namespace AQ

#endif // AQ_APP_MAINWINDOW_H
