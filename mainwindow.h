#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


enum AppColors
{
    COLOR_BACKGROUND_1 = 0x00303030,
    COLOR_BACKGROUND_2 = 0x00000000,
};


enum TipDuration
{
    MOMENTAL = 1000,
    NORMAL   = 3000,
    LONG     = 9000,
};


namespace Ui
{
    class MainWindow;
}


class MainWindow:
        public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
