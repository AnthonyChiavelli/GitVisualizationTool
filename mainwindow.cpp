 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gcommitnode.h"
#include "QGraphicsRectItem"
#include "greposcene.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow) {

    ui->setupUi(this);

    this->repoScene = new GRepoScene(this->centralWidget());
    ui->graphicsView->setScene(this->repoScene);
    this->repoScene->attachRootCommitNode(new GCommitNode(0));
    this->repoScene->renderScene();


}

MainWindow::~MainWindow() {
    delete ui;
}



