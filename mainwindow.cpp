 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gcommitnode.h"
#include "QGraphicsRectItem"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Instantiate a graphics view for this scene
    QGraphicsView *canvas = ui->Canvas;
    this->scene= new QGraphicsScene(this);
    canvas->setScene(scene);
}

MainWindow::~MainWindow() {
    delete ui;
}



void MainWindow::on_pushButton_2_clicked() {

    GCommitNode *node = new GCommitNode(0);
    GCommitNode *node2 = new GCommitNode(0);


    this->scene->addItem(node);
    this->scene->addItem(node2);

}
