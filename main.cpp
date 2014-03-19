#include "mainwindow.h"
#include <QApplication>
#include <QtGui>
#include <QtCore>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    window.setWindowTitle("Gitty Up, Bitch!");

    window.show();
    return a.exec();
}
