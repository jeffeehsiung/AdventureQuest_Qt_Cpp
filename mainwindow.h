#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
  {
    Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

  public slots:
    void zoomIn();

private slots:
    void on_actionSave_triggered();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
  };

#endif // MAINWINDOW_H
