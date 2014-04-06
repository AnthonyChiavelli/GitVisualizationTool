 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gcommitnode.h"
#include "QGraphicsRectItem"
#include "ggraphicsscene.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Instantiate a graphics view for this scene
    QGraphicsView *canvas = ui->Canvas;
    this->scene= new GGraphicsScene(this);
    canvas->setScene(scene);
}

MainWindow::~MainWindow() {
    delete ui;
}



void MainWindow::on_pushButton_2_clicked() {

    GCommitNode *node = new GCommitNode(0);

    this->scene->addItem(node);

}
