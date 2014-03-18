 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gcommitnode.h"
#include "QGraphicsRectItem"
#include "greposcene.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow) {

    ui->setupUi(this);

    this->repoScene = new GRepoScene(this->centralWidget());
    ui->graphicsView->setScene(this->repoScene);

    GCommitNode *node = new GCommitNode(0);


    this->repoScene->addItem(node);

}

MainWindow::~MainWindow() {
    delete ui;
}



