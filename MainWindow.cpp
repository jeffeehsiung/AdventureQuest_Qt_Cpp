#include "MainWindow.h"

/** for testing */
#include "View/Game2DView.h"
#include "View/GameTextView.h"
#include "Controller/ViewController.h"
#include "Model/TileModel.h"
#include "Model/ProtagonistModel.h"
#include "Model/EnemyModel.h"
#include "Model/world.h"
/** above include is for testing */

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    centralWidget(new QWidget(this)),
    graphicsView(new QGraphicsView(this)),
    textualView(new QGraphicsView(this)),
    startButton(new QPushButton("Start", this)),
    pauseButton(new QPushButton("Pause", this)),
    quitButton(new QPushButton("Quit", this)),
    energySlider(new QSlider(Qt::Horizontal, this)),
    healthSlider(new QSlider(Qt::Horizontal, this)),
    animationDelaySlider(new QSlider(Qt::Horizontal, this)),
    heightFactorSlider(new QSlider(Qt::Horizontal, this)),
    heuristicWeightFactorSlider(new QSlider(Qt::Horizontal, this)),
    energyLabel(new QLabel("Energy", this)),
    healthLabel(new QLabel("Health", this)),
    animationDelayLabel(new QLabel("Animation delay", this)),
    heightFactorLabel(new QLabel("Height factor", this)),
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
    isGamePaused(false)
{
/** for testing only. haven't tried */
    // Create a vector of EnemyModel pointers
    std::vector<EnemyModel*> enemyModels;
    // Create a vector of TileModel pointers
    std::vector<TileModel*> tileModels;
    // Create a vector of ProtagonistModel pointers
    std::vector<ProtagonistModel*> protagonistModels;
    // Manually create and initialize enemy models
    // For example:
    EnemyModel* enemyModel1 = new EnemyModel(new Enemy(1, 2, 50.0f));
    EnemyModel* enemyModel2 = new EnemyModel(new Enemy(3, 4, 60.0f));
    enemyModels.push_back(enemyModel1);
    enemyModels.push_back(enemyModel2);
    // Manually create and initialize tile models
    // For example:
//    TileModel* tileModel1 = new TileModel(std::make_unique<Tile>(0, 0, 0.5f));
//    TileModel* tileModel2 = new TileModel(std::make_unique<Tile>(1, 1, 0.7f));
//    tileModels.push_back(tileModel1);
//    tileModels.push_back(tileModel2);
    // Manually create and initialize protagonist models
    // For example:
    ProtagonistModel* protagonistModel = new ProtagonistModel(new Protagonist());
    protagonistModels.push_back(protagonistModel);
    QGraphicsScene* scene = new QGraphicsScene(this);
    Game2DView* game2DView = new Game2DView(scene);
    ViewController<Game2DView> viewController( enemyModels, tileModels, protagonistModels);
/***/

    setupUI();
    setCentralWidget(centralWidget);
    pauseButton->setEnabled(false);
    pauseButton->setStyleSheet("background-color: grey;");
    autoPlayButton->setEnabled(false);
    autoPlayButton->setStyleSheet("background-color: grey;");
    quitButton->setEnabled(false);
    quitButton->setStyleSheet("background-color: grey;");

    connect(startButton, &QPushButton::clicked, this, &MainWindow::onStartButtonClicked);
    connect(pauseButton, &QPushButton::clicked, this, &MainWindow::onPauseButtonClicked);
    connect(autoPlayButton, &QPushButton::clicked, this, &MainWindow::onAutoPlayButtonClicked);
    connect(quitButton, &QPushButton::clicked, this, &MainWindow::onQuitButtonClicked);
}


MainWindow::~MainWindow()
{
    // Destructor
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

    // Set up the graphics view on the first tab
    graphicsView->setStyleSheet("background-color: black;");
//    QGraphicsScene *graphicsScene = new QGraphicsScene(this);
//    graphicsView->setScene(graphicsScene);
    QVBoxLayout *graphicsLayout = new QVBoxLayout();
    graphicsLayout->addWidget(graphicsView);

    // Set up the textual view on the second tab
    textualView->setStyleSheet("background-color: orange;");
    QGraphicsScene *textualScene = new QGraphicsScene(this);
    textualView->setScene(textualScene);
    QVBoxLayout *textualLayout = new QVBoxLayout();
    textualLayout->addWidget(textualView);

    // Add a widget for game messages in the graphics tab
    graphicsMessageWidget->setReadOnly(true);
    graphicsMessageWidget->setStyleSheet("background-color: white;");
    graphicsMessageWidget->setFixedHeight(100);
    graphicsLayout->addWidget(graphicsMessageWidget);
    graphicsTab->setLayout(graphicsLayout);
    viewTabs->addTab(graphicsTab, "Graphics");

    // Add a widget for game messages in the textual tab
    textualMessageWidget->setReadOnly(true);
    textualMessageWidget->setStyleSheet("background-color: white;");
    textualMessageWidget->setFixedHeight(100);
    textualLayout->addWidget(textualMessageWidget);
    textualTab->setLayout(textualLayout);
    viewTabs->addTab(textualTab, "Textual");

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
    controlLayout->addWidget(energyLabel);
    controlLayout->addWidget(energySlider);
    controlLayout->addWidget(healthLabel);
    controlLayout->addWidget(healthSlider);
    controlLayout->addWidget(animationDelayLabel);
    controlLayout->addWidget(animationDelaySlider);
    controlLayout->addWidget(heightFactorLabel);
    controlLayout->addWidget(heightFactorSlider);
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
}

void MainWindow::onAutoPlayButtonClicked()
{
    graphicsMessageWidget->append("Auto playing...");
    textualMessageWidget->append("Auto playing...");
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

    autoPlayButton->setEnabled(false);
    autoPlayButton->setStyleSheet("background-color: grey;");

    quitButton->setEnabled(false);
    quitButton->setStyleSheet("background-color: grey;");

    playerNumberComboBox->setEnabled(true);
    playerNumberComboBox->setStyleSheet("");

    difficultyLevelComboBox->setEnabled(true);
    difficultyLevelComboBox->setStyleSheet("");
}
