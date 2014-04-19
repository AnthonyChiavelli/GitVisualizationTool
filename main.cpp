#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}


//void test_GIT_API(){

//    std::string path = "/home";
//    gitAPI::gitInit(path);

//}
