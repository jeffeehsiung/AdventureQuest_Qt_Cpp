#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT //moc transformer ( qobjects from q language to c++)

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots: // not plain c++
    void zoomIn();  // will be connected to slots
    void on_action();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui; // to access the ui form that is compiled by the auto compiler uic
};
#endif // MAINWINDOW_H
