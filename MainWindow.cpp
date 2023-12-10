#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    centralWidget(new QWidget(this)),
    startButton(new QPushButton("Start", this)),
    pauseButton(new QPushButton("Pause", this)),
    quitButton(new QPushButton("Quit", this)),
    // energySlider(new QSlider(Qt::Horizontal, this)),
    // healthSlider(new QSlider(Qt::Horizontal, this)),
    animationDelaySlider(new QSlider(Qt::Horizontal, this)),
    // heightFactorSlider(new QSlider(Qt::Horizontal, this)),
    heuristicWeightFactorSlider(new QSlider(Qt::Horizontal, this)),
    // energyLabel(new QLabel("Energy", this)),
    // healthLabel(new QLabel("Health", this)),
    animationDelayLabel(new QLabel("Animation delay", this)),
    // heightFactorLabel(new QLabel("Height factor", this)),
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
    textualMessageWidget->setReadOnly(true);
    textualMessageWidget->setStyleSheet("background-color: white;");
    textualMessageWidget->setFixedHeight(100);

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
    controlLayout->addStretch(1); // Push the remaining elements to the right
    controlLayout->addWidget(playerNumberLabel);
    controlLayout->addWidget(playerNumberComboBox);
    controlLayout->addWidget(difficultyLevelLabel);
    controlLayout->addWidget(difficultyLevelComboBox);
    // controlLayout->addWidget(energyLabel);
    // controlLayout->addWidget(energySlider);
    // controlLayout->addWidget(healthLabel);
    // controlLayout->addWidget(healthSlider);
    controlLayout->addWidget(animationDelayLabel);
    controlLayout->addWidget(animationDelaySlider);
    // controlLayout->addWidget(heightFactorLabel);
    // controlLayout->addWidget(heightFactorSlider);
    controlLayout->addWidget(heuristicWeightFactorLabel);
    controlLayout->addWidget(heuristicWeightFactorSlider);

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
}

void MainWindow::onViewTabChanged(int index)
{
    if (index == 0) {
        gameController->switchTo2DView();
    } else if (index == 1) {
        gameController->switchToTextView();
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
    setFocusPolicy(Qt::StrongFocus);
    switch (event->key()) {
    case Qt::Key_W:
        gameController->onUpArrowPressed();
        break;
    case Qt::Key_S:
        gameController->onDownArrowPressed();
        break;
    case Qt::Key_A:
        gameController->onLeftArrowPressed();
        break;
    case Qt::Key_D:
        gameController->onRightArrowPressed();
        break;
    default:
        QMainWindow::keyPressEvent(event);
    }
}
