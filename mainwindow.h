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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digit_pressed();
    void dotBtnPressed();
    void unaryOpPressed();
    void clearBtnPressed();
    void equalBtnPressed();
    void binaryOpPressed();
};
#endif // MAINWINDOW_H
