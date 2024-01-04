#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    centralWidget(new QWidget(this)),
    startButton(new QPushButton("Start", this)),
    pauseButton(new QPushButton("Pause", this)),
    quitButton(new QPushButton("Quit", this)),
    animationDelaySlider(new QSlider(Qt::Horizontal, this)),
    heuristicWeightFactorSlider(new QSlider(Qt::Horizontal, this)),
    animationDelayLabel(new QLabel("Animation delay", this)),
    heuristicWeightFactorLabel(new QLabel("Heuristic weight factor", this)),
    viewTabs(new QTabWidget(this)),
    graphicsTab(new QWidget(this)),
    textualTab(new QWidget(this)),
    autoPlayButton(new QPushButton("Auto Play", this)),
    playerNumberComboBox(new QComboBox(this)),
    difficultyLevelComboBox(new QComboBox(this)),
    playerNumberLabel(new QLabel("Number of Players", this)),
    difficultyLevelLabel(new QLabel("Difficulty Level", this)),
    graphicsMessageWidget(new QTextEdit(this)),
    textualMessageWidget(new QTextEdit(this)),
    isGamePaused(false),
    gameController(new GameController(this))
{
    setCentralWidget(centralWidget);
    setupUI();

    pauseButton->setEnabled(false);
    pauseButton->setStyleSheet("background-color: grey;");
    autoPlayButton->setEnabled(false);
    autoPlayButton->setStyleSheet("background-color: grey;");
    quitButton->setEnabled(false);
    quitButton->setStyleSheet("background-color: grey;");

    /** UI connections to MainWindow */
    connect(startButton, &QPushButton::clicked, this, &MainWindow::onStartButtonClicked);
    connect(pauseButton, &QPushButton::clicked, this, &MainWindow::onPauseButtonClicked);
    connect(autoPlayButton, &QPushButton::clicked, this, &MainWindow::onAutoPlayButtonClicked);
    connect(quitButton, &QPushButton::clicked, this, &MainWindow::onQuitButtonClicked);
    connect(viewTabs, &QTabWidget::currentChanged, this, &MainWindow::onViewTabChanged);

    /** MainWindow connections to GameController */
    connect(gameController, &GameController::viewUpdateRequested, this, &MainWindow::onViewUpdateRequested);
    connect(gameController, &GameController::sendTextToGUI, this, &MainWindow::displayText);
}


MainWindow::~MainWindow() {
    delete gameController;
}


void MainWindow::setupUI()
{
    // Set the window title
    setWindowTitle("MainWindow");

    // Initialize the player number combo box
    playerNumberComboBox->addItem("1");
    playerNumberComboBox->addItem("2");

    // Initialize the difficulty level combo box
    difficultyLevelComboBox->addItem("Easy");
    difficultyLevelComboBox->addItem("Medium");
    difficultyLevelComboBox->addItem("Hard");

    QVBoxLayout *graphicsLayout = new QVBoxLayout();
    QVBoxLayout *textualLayout = new QVBoxLayout();

    // Add a widget for game messages in the graphics tab
    graphicsMessageWidget->setReadOnly(true);
    graphicsMessageWidget->setStyleSheet("background-color: white;");
    graphicsMessageWidget->setFixedHeight(100);

    viewTabs->addTab(graphicsTab, "Graphics");

    graphicsLayout->addWidget(graphicsMessageWidget);
    graphicsTab->setLayout(graphicsLayout);


    // Add a widget for game messages in the textual tab
    textualMessageWidget->setReadOnly(false);
    textualMessageWidget->setStyleSheet("background-color: white;");
    textualMessageWidget->setFixedHeight(100);
    textualMessageWidget->setPlaceholderText("> Type command here and press Enter...");
    textualMessageWidget->installEventFilter(this);

    viewTabs->addTab(textualTab, "Textual");

    textualLayout->addWidget(textualMessageWidget);
    textualTab->setLayout(textualLayout);

    // Set up the controls
    startButton->setFixedSize(100, 30);
    quitButton->setFixedSize(100, 30);
    pauseButton->setFixedSize(100, 30);
    autoPlayButton->setFixedSize(100, 30);

    // Main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->addWidget(viewTabs);

    // Control layout
    QHBoxLayout *controlLayout = new QHBoxLayout();
    controlLayout->addWidget(startButton);
    controlLayout->addWidget(pauseButton);
    controlLayout->addWidget(autoPlayButton);
    controlLayout->addWidget(quitButton);
    
    controlLayout->addWidget(playerNumberLabel);
    controlLayout->addWidget(playerNumberComboBox);
    controlLayout->addWidget(difficultyLevelLabel);
    controlLayout->addWidget(difficultyLevelComboBox);
    controlLayout->addWidget(animationDelayLabel);
    controlLayout->addWidget(animationDelaySlider);
    controlLayout->addWidget(heuristicWeightFactorLabel);
    controlLayout->addWidget(heuristicWeightFactorSlider);

    controlLayout->addStretch(1); // Push the remaining elements to the right

    const int maxHealth = 5;
    const int maxEnergy = 100;
    const QSize heartSize(20, 20);
    const QSize energySize(3, 3);

    for (int i = 0; i < maxHealth; ++i) {
        QLabel* healthLabel = new QLabel(this);
        QPixmap heartPixmap(":/images/healthpack/Idle/2.png");
        healthLabel->setPixmap(heartPixmap.scaled(heartSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        healthLabels.append(healthLabel);
        controlLayout->addWidget(healthLabel);
    }

    for (int i = 0; i < maxEnergy; ++i) {
        QLabel* energyLabel = new QLabel(this);
        QPixmap starPixmap(":/images/tiles/Idle/00.png");
        energyLabel->setPixmap(starPixmap.scaled(energySize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        energyLabels.append(energyLabel);
        controlLayout->addWidget(energyLabel);
    }

    // Add control layout to the main layout
    mainLayout->addLayout(controlLayout);

    // Set the central widget layout
    centralWidget->setLayout(mainLayout);
}

void MainWindow::onStartButtonClicked()
{
    QString numberOfPlayers = playerNumberComboBox->currentText();
    QString difficultyLevel = difficultyLevelComboBox->currentText();

    QString message = QString("Game started with %1 players and level of difficulty: %2")
                          .arg(numberOfPlayers, difficultyLevel);

    graphicsMessageWidget->append(message);
    textualMessageWidget->append(message);

    startButton->setEnabled(false);
    startButton->setStyleSheet("background-color: grey;");

    pauseButton->setEnabled(true);
    pauseButton->setStyleSheet("");

    autoPlayButton->setEnabled(true);
    autoPlayButton->setStyleSheet("");

    quitButton->setEnabled(true);
    quitButton->setStyleSheet("");

    playerNumberComboBox->setEnabled(false);
    playerNumberComboBox->setStyleSheet("background-color: grey;");

    difficultyLevelComboBox->setEnabled(false);
    difficultyLevelComboBox->setStyleSheet("background-color: grey;");

    // Interact with game controller
    gameController->readGameStarted(true);
    gameController->readGamePaused(false);
    gameController->readGameAutoplayed(false);
    gameController->readGameNumberOfPlayers(numberOfPlayers);
    gameController->readGameDifficultyLevel(difficultyLevel);
    gameController->initializeWorld();
}

void MainWindow::onPauseButtonClicked()
{
    if (isGamePaused) {
        graphicsMessageWidget->append("Game unpaused!");
        textualMessageWidget->append("Game unpaused!");
        pauseButton->setText("Pause");
        autoPlayButton->setEnabled(true);
        autoPlayButton->setStyleSheet("");
        isGamePaused = false;
    } else {
        graphicsMessageWidget->append("Game paused!");
        textualMessageWidget->append("Game paused!");
        pauseButton->setText("Unpause");
        autoPlayButton->setEnabled(false);
        autoPlayButton->setStyleSheet("background-color: grey;");
        isGamePaused = true;
    }
    gameController->readGamePaused(isGamePaused);
    gameController->printAllGameInfo();
}

void MainWindow::onAutoPlayButtonClicked()
{
    graphicsMessageWidget->append("Auto playing...");
    textualMessageWidget->append("Auto playing...");
    gameController->readGameAutoplayed(true);
    gameController->printAllGameInfo();
}

void MainWindow::onQuitButtonClicked()
{
    graphicsMessageWidget->append("Game exited!");
    textualMessageWidget->append("Game exited!");

    startButton->setEnabled(true);
    startButton->setStyleSheet("");

    pauseButton->setText("Pause");
    pauseButton->setEnabled(false);
    pauseButton->setStyleSheet("background-color: grey;");
    isGamePaused = false;
    gameController->readGamePaused(isGamePaused);

    autoPlayButton->setEnabled(false);
    autoPlayButton->setStyleSheet("background-color: grey;");
    gameController->readGameAutoplayed(false);

    quitButton->setEnabled(false);
    quitButton->setStyleSheet("background-color: grey;");
    gameController->readGameStarted(false);

    playerNumberComboBox->setEnabled(true);
    playerNumberComboBox->setStyleSheet("");
    gameController->readGameNumberOfPlayers("0");

    difficultyLevelComboBox->setEnabled(true);
    difficultyLevelComboBox->setStyleSheet("");
    gameController->readGameDifficultyLevel("Not Selected");

    gameController->printAllGameInfo();

    gameController->setGameOver();
    startButton->setText("Exit");
}

void MainWindow::onViewTabChanged(int index)
{
    if (index == 0) {
        gameController->switchTo2DView();
    } else if (index == 1) {
        textualMessageWidget->clear();
        gameController->switchToTextView();
        textualMessageWidget->setFocus();
    }
}

void MainWindow::onViewUpdateRequested(QWidget* view) {
    displayView(view);
}

void MainWindow::displayView(QWidget* view) {
    if (!viewTabs || viewTabs->count() == 0) {
        return;
    }

    QWidget* currentTab = viewTabs->currentWidget();

    if (currentTab) {
        QLayout* layout = currentTab->layout();
        layout->addWidget(view);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (!gameController->isGameOver()) {
        // Handle movement keys only when the game is not over
        switch (event->key()) {
        case Qt::Key_W: gameController->onUpArrowPressed(); break;
        case Qt::Key_S: gameController->onDownArrowPressed(); break;
        case Qt::Key_A: gameController->onLeftArrowPressed(); break;
        case Qt::Key_D: gameController->onRightArrowPressed(); break;
        default: QMainWindow::keyPressEvent(event); break;
        }
        updateHealthDisplay();
        updateEnergyDisplay();
    } else {
        QMainWindow::keyPressEvent(event);
    }
}


void MainWindow::updateHealthDisplay() {
    int currentHealth = gameController->getHealth1();
    if (currentHealth == 0) {
        gameController->setGameOver();
        QMessageBox::information(this, "Game Over", "DIE! YOU'VE GOT NOTHING! YOU LOSE!");
    }
    for (int i = 0; i < healthLabels.size(); ++i) {
        if (i < currentHealth) {
            healthLabels[i]->setVisible(true);
        } else {
            healthLabels[i]->setVisible(false);
        }
    }
}

void MainWindow::updateEnergyDisplay() {
    int currentEnergy = gameController->getEnergy1();
    for (int i = 0; i < energyLabels.size(); ++i) {
        if (i < currentEnergy) {
            energyLabels[i]->setVisible(true);
        } else {
            energyLabels[i]->setVisible(false);
        }
    }
}

void MainWindow::displayText(const QString& text) {
    graphicsMessageWidget->append(text);

    QString currentText = textualMessageWidget->toPlainText();
    textualMessageWidget->setPlainText(currentText + "\n" + text);
    QTextCursor cursor = textualMessageWidget->textCursor();
    cursor.movePosition(QTextCursor::End);
    textualMessageWidget->setTextCursor(cursor);
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event) {
    if (watched == textualMessageWidget && event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return) {
            // Handle the Enter key press
            QString command = textualMessageWidget->toPlainText().trimmed();
            gameController->processCommand(command);
            textualMessageWidget->clear();
            return true; // indicate that the event was handled
        }
    }
    // Call base class method for default processing
    return QMainWindow::eventFilter(watched, event);
}
