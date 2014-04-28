#include "mainwindow.h"
#include "gitinitdialog.h"
#include "gitadddialog.h"
#include "ui_mainwindow.h"
#include "gcommitnode.h"
#include "QGraphicsRectItem"
#include "ggraphicsscene.h"
#include "gitapi.h"
#include <string>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow) {

    ui->setupUi(this);

    // Instantiate a graphics view for this scene
    QGraphicsView *canvas = ui->graphicsView;
    this->scene= new GGraphicsScene(this);
    canvas->setScene(scene);

//    //Test stuff
//    GCommitNode *node1 = new GCommitNode(1, 0, 0);
//    GCommitNode *node2 = new GCommitNode(2, 2, 0);
//    GCommitNode *node3 = new GCommitNode(3, 3, 0);
//    GCommitNode *node4 = new GCommitNode(4, 4, 0);


//    this->scene->addItem(node1);
//    this->scene->addItem(node2);
//    this->scene->addItem(node3);
//    this->scene->addItem(node4);
}

MainWindow::~MainWindow() {
    delete ui;
}




void MainWindow::on_actionGitInit_triggered()
{
    GitInitDialog GIdialog;
    GIdialog.setModal(true);
    GIdialog.exec();
    std::string path = "/home/nrosato/Desktop/GitTest";
    GitApi::gitInit(path);
}

void MainWindow::on_actionGitAdd_triggered(){
    GitAddDialog GAdialog;
    GAdialog.setModal(true);
    GIdialog.exec();
}


