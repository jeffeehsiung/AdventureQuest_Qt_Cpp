#include "mainwindow.h"
#include "ui_mainwindow.h"  //the result of the ui compiler.
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QPainter>
#include <QTimer>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) //to integrate the ui form into main window and utilize singal and slot library @/Users/jeffeehsiung/Desktop/Toledo/advance programming/lab/build-mario_world-Qt_6_5_3_for_macOS-Debug
{
    ui->setupUi(this);
    QGraphicsScene* scene = new QGraphicsScene(this);   // view to show the scene container
    ui->graphicsView->setScene(scene);
    auto rect = scene->addRect(10, 50, 50, 120);    // generate and place a rectangle in the scene
    scene->addPixmap(QPixmap(":/images/qtlogo.jpg"));   // do not define os/pc specific path but include the images in the .pro definition.
    rect->setZValue(1.1);   // 2.5D view that rect will have higher z value resembling the visual priority
    rect->setFlag(QGraphicsItem::ItemIsMovable, true);  // allow click and drag
}

MainWindow::~MainWindow()
{
    delete ui; // clean up ui
}


void MainWindow::zoomIn(){
    ui->graphicsView->scale(1.1, 1.1);
}

void MainWindow::on_action(){
    QImage brol(512, 512, QImage::Format_RGB32);
    QPainter saved(&brol);  // use this image to paint
    ui->graphicsView->render(&saved);
    brol.save("./test.png");
}

void MainWindow::on_pushButton_clicked()
{
    QTimer* loop = new QTimer();
    loop->setInterval(500);
    connect(loop, SIGNAL(timeout()), this, SLOT(zoomIn()));
    loop->start();
}

