#include "App/MainWindow.h"
#include <QApplication>
#include <QScreen>

namespace AQ {

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , controller_(new GameController(this))
{
    setWindowTitle("AdventureQuest");

    controller_->initializeScene(this);

    // Connect controller signals
    connect(controller_, &GameController::viewReady, this, &MainWindow::onViewReady);
    connect(controller_, &GameController::statusUpdated, this, &MainWindow::onStatusUpdated);
    connect(controller_, &GameController::gameWon, this, &MainWindow::onGameWon);
    connect(controller_, &GameController::gameLost, this, &MainWindow::onGameLost);
    connect(controller_, &GameController::autoPlayDone, this, &MainWindow::onAutoPlayDone);
    connect(controller_, &GameController::textMessage, this, &MainWindow::onTextMessage);

    if (PlatformConfig::isMobile) {
        setupMobileUI();
    } else {
        setupDesktopUI();
    }
}

MainWindow::~MainWindow() = default;

void MainWindow::setupDesktopUI() {
    centralWidget_ = new QWidget(this);
    setCentralWidget(centralWidget_);

    auto* mainLayout = new QVBoxLayout(centralWidget_);

    // View tabs
    viewTabs_ = new QTabWidget(this);
    graphicsTab_ = new QWidget(this);
    auto* graphicsLayout = new QVBoxLayout(graphicsTab_);
    graphicsLayout->setContentsMargins(0, 0, 0, 0);

    // Message widget
    messageWidget_ = new QTextEdit(this);
    messageWidget_->setReadOnly(true);
    messageWidget_->setFixedHeight(80);
    messageWidget_->setStyleSheet("background-color: #1a1a2e; color: #e0e0e0; font-family: monospace;");

    graphicsLayout->addWidget(messageWidget_);
    viewTabs_->addTab(graphicsTab_, "Game");
    mainLayout->addWidget(viewTabs_);

    // Control bar
    auto* controlLayout = new QHBoxLayout();

    startBtn_ = new QPushButton("Start", this);
    pauseBtn_ = new QPushButton("Pause", this);
    autoPlayBtn_ = new QPushButton("Auto Play", this);
    quitBtn_ = new QPushButton("Quit", this);

    startBtn_->setFixedSize(90, 32);
    pauseBtn_->setFixedSize(90, 32);
    autoPlayBtn_->setFixedSize(90, 32);
    quitBtn_->setFixedSize(90, 32);

    pauseBtn_->setEnabled(false);
    autoPlayBtn_->setEnabled(false);
    quitBtn_->setEnabled(false);

    // Difficulty & player count
    playerCountCombo_ = new QComboBox(this);
    playerCountCombo_->addItems({"1", "2"});

    difficultyCombo_ = new QComboBox(this);
    difficultyCombo_->addItems({"Easy", "Medium", "Hard"});

    heuristicSlider_ = new QSlider(Qt::Horizontal, this);
    heuristicSlider_->setRange(100, 200);
    heuristicSlider_->setValue(100);

    controlLayout->addWidget(startBtn_);
    controlLayout->addWidget(pauseBtn_);
    controlLayout->addWidget(autoPlayBtn_);
    controlLayout->addWidget(quitBtn_);
    controlLayout->addWidget(new QLabel("Players:", this));
    controlLayout->addWidget(playerCountCombo_);
    controlLayout->addWidget(new QLabel("Difficulty:", this));
    controlLayout->addWidget(difficultyCombo_);
    controlLayout->addWidget(new QLabel("A* Weight:", this));
    controlLayout->addWidget(heuristicSlider_);

    // HUD
    hud_ = new HUD(this);
    controlLayout->addWidget(hud_);
    controlLayout->addStretch();

    mainLayout->addLayout(controlLayout);

    // Connections
    connect(startBtn_, &QPushButton::clicked, this, &MainWindow::onStartClicked);
    connect(pauseBtn_, &QPushButton::clicked, this, &MainWindow::onPauseClicked);
    connect(autoPlayBtn_, &QPushButton::clicked, this, &MainWindow::onAutoPlayClicked);
    connect(quitBtn_, &QPushButton::clicked, this, &MainWindow::onQuitClicked);
    connect(heuristicSlider_, &QSlider::valueChanged, this, [this](int val) {
        controller_->gameState().setHeuristicWeight(static_cast<float>(val) / 100.0f);
    });

    // Style
    setStyleSheet(
        "QMainWindow { background-color: #0f0f23; }"
        "QPushButton { background-color: #1a1a3e; color: #e0e0e0; border: 1px solid #333366; "
        "  border-radius: 4px; padding: 4px 8px; }"
        "QPushButton:hover { background-color: #2a2a5e; }"
        "QPushButton:disabled { background-color: #0a0a1a; color: #555; }"
        "QComboBox { background-color: #1a1a3e; color: #e0e0e0; border: 1px solid #333366; }"
        "QLabel { color: #c0c0c0; }"
        "QTabWidget::pane { border: 1px solid #333366; background: #0f0f23; }"
        "QTabBar::tab { background: #1a1a3e; color: #c0c0c0; padding: 6px 12px; }"
        "QTabBar::tab:selected { background: #2a2a5e; color: white; }"
    );

    resize(1024, 768);
}

void MainWindow::setupMobileUI() {
    centralWidget_ = new QWidget(this);
    setCentralWidget(centralWidget_);

    auto* layout = new QVBoxLayout(centralWidget_);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    // Compact HUD at top
    hud_ = new HUD(this);
    hud_->setCompactMode(true);
    hud_->setFixedHeight(40);
    hud_->setStyleSheet("background-color: rgba(0,0,0,0.6);");
    layout->addWidget(hud_);

    // Game scene fills the rest
    auto* scene = controller_->gameScene();
    if (scene) {
        layout->addWidget(scene, 1);
    }

    // Touch overlay
    touchOverlay_ = new TouchOverlay(this);
    touchOverlay_->setActionCallback([this](InputAction action) {
        controller_->handleAction(action);
    });

    // Start button overlay
    startBtn_ = new QPushButton("START", this);
    startBtn_->setStyleSheet(
        "QPushButton { background-color: rgba(80,120,200,0.8); color: white; "
        "font-size: 24px; font-weight: bold; border-radius: 20px; padding: 20px 40px; }");

    connect(startBtn_, &QPushButton::clicked, this, [this]() {
        controller_->startGame(Difficulty::Easy, 1);
        startBtn_->hide();
        touchOverlay_->show();
        touchOverlay_->raise();
    });

    // Full screen on mobile
    showFullScreen();
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    if (controller_->gameState().isGameOver()) {
        QMainWindow::keyPressEvent(event);
        return;
    }

    switch (event->key()) {
        case Qt::Key_W: case Qt::Key_Up:
            controller_->handleAction(InputAction::MoveUp); break;
        case Qt::Key_S: case Qt::Key_Down:
            controller_->handleAction(InputAction::MoveDown); break;
        case Qt::Key_A: case Qt::Key_Left:
            controller_->handleAction(InputAction::MoveLeft); break;
        case Qt::Key_D: case Qt::Key_Right:
            controller_->handleAction(InputAction::MoveRight); break;
        case Qt::Key_Space:
            controller_->handleAction(InputAction::Attack); break;
        case Qt::Key_E:
            controller_->handleAction(InputAction::TakeItem); break;
        default:
            QMainWindow::keyPressEvent(event); break;
    }
}

void MainWindow::resizeEvent(QResizeEvent* event) {
    QMainWindow::resizeEvent(event);
    if (touchOverlay_) {
        touchOverlay_->setGeometry(rect());
    }
    if (startBtn_ && startBtn_->isVisible()) {
        startBtn_->move((width() - startBtn_->width()) / 2,
                        (height() - startBtn_->height()) / 2);
    }
}

Difficulty MainWindow::selectedDifficulty() const {
    if (!difficultyCombo_) return Difficulty::Easy;
    switch (difficultyCombo_->currentIndex()) {
        case 0: return Difficulty::Easy;
        case 1: return Difficulty::Medium;
        case 2: return Difficulty::Hard;
        default: return Difficulty::Easy;
    }
}

void MainWindow::onStartClicked() {
    int players = playerCountCombo_ ? playerCountCombo_->currentText().toInt() : 1;
    controller_->startGame(selectedDifficulty(), players);

    if (startBtn_) { startBtn_->setEnabled(false); }
    if (pauseBtn_) { pauseBtn_->setEnabled(true); }
    if (autoPlayBtn_) { autoPlayBtn_->setEnabled(true); }
    if (quitBtn_) { quitBtn_->setEnabled(true); }
    if (playerCountCombo_) { playerCountCombo_->setEnabled(false); }
    if (difficultyCombo_) { difficultyCombo_->setEnabled(false); }

    if (messageWidget_) {
        messageWidget_->append(
            QString("Game started! Difficulty: %1, Players: %2")
                .arg(difficultyCombo_->currentText())
                .arg(players));
    }
}

void MainWindow::onPauseClicked() {
    if (isPaused_) {
        controller_->resumeGame();
        pauseBtn_->setText("Pause");
        autoPlayBtn_->setEnabled(true);
        isPaused_ = false;
        if (messageWidget_) messageWidget_->append("Game resumed.");
    } else {
        controller_->pauseGame();
        pauseBtn_->setText("Resume");
        autoPlayBtn_->setEnabled(false);
        isPaused_ = true;
        if (messageWidget_) messageWidget_->append("Game paused.");
    }
}

void MainWindow::onAutoPlayClicked() {
    if (messageWidget_) messageWidget_->append("Auto-playing...");
    if (autoPlayBtn_) autoPlayBtn_->setEnabled(false);
    if (pauseBtn_) pauseBtn_->setEnabled(false);
    if (quitBtn_) quitBtn_->setEnabled(false);
    controller_->autoPlay();
}

void MainWindow::onQuitClicked() {
    controller_->quitGame();

    if (startBtn_) { startBtn_->setEnabled(true); }
    if (pauseBtn_) { pauseBtn_->setEnabled(false); pauseBtn_->setText("Pause"); }
    if (autoPlayBtn_) { autoPlayBtn_->setEnabled(false); }
    if (quitBtn_) { quitBtn_->setEnabled(false); }
    if (playerCountCombo_) { playerCountCombo_->setEnabled(true); }
    if (difficultyCombo_) { difficultyCombo_->setEnabled(true); }

    isPaused_ = false;
    if (messageWidget_) messageWidget_->append("Game ended.");
}

void MainWindow::onViewReady(QWidget* view) {
    if (graphicsTab_ && graphicsTab_->layout()) {
        graphicsTab_->layout()->addWidget(view);
    }
}

void MainWindow::onStatusUpdated(int health, float energy) {
    if (hud_) hud_->updateStatus(health, energy);
}

void MainWindow::onGameWon() {
    QMessageBox::information(this, "Victory", "You conquered all five worlds! You win!");
    if (autoPlayBtn_) autoPlayBtn_->setEnabled(false);
}

void MainWindow::onGameLost() {
    QMessageBox::information(this, "Defeat", "You have fallen! Game Over.");
    if (autoPlayBtn_) autoPlayBtn_->setEnabled(false);
}

void MainWindow::onAutoPlayDone() {
    if (!controller_->gameState().isGameOver()) {
        if (autoPlayBtn_) autoPlayBtn_->setEnabled(true);
        if (pauseBtn_) pauseBtn_->setEnabled(true);
        if (quitBtn_) quitBtn_->setEnabled(true);
    }
}

void MainWindow::onTextMessage(const QString& text) {
    if (messageWidget_) messageWidget_->append(text);
}

} // namespace AQ
