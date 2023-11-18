#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
  {
  ui->setupUi(this);
  QGraphicsScene * scene = new QGraphicsScene(this);
  ui->graphicsView->setScene(scene);
  auto rect = scene->addRect(10, 50, 50, 120);
  scene->addPixmap(QPixmap(":/images/qtlogo.jpg"));
  rect->setZValue(1.1);
  rect->setFlag(QGraphicsItem::ItemIsMovable, true);
  }

MainWindow::~MainWindow()
  {
  delete ui;
  //I don't need to delete scene or rect since everything what derives from QObject has also a parent
  //when the toplevel QObject (ui in this case) is deleted, all its children will also be deleted
  //So there is no urgent need to work with smart pointers for all QObject derived stuff you use
  }

void MainWindow::zoomIn()
  {
  ui->graphicsView->scale(1.1, 1.1);
  }

void MainWindow::on_actionSave_triggered()
{
  QImage brol(512, 512, QImage::Format_RGB32);
  QPainter saved(&brol);
  ui->graphicsView->render(&saved);
  brol.save("./test.png");
}


void MainWindow::on_pushButton_2_clicked()
{
    QTimer * loop = new QTimer();
    loop->setInterval(500);
    connect(loop, SIGNAL(timeout()), this, SLOT(zoomIn()));
    loop->start();
}
