#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ui_mainwindow.h"
#include "ggraphicsscene.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionGitInit_triggered();

private:
    Ui::MainWindow *ui;
    GGraphicsScene *scene;

};

#endif // MAINWINDOW_H
