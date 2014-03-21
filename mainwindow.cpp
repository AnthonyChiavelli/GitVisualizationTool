 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gcommitnode.h"
#include "QGraphicsRectItem"
#include "ggraphicsscene.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Instantiate a graphics view for this scene
    QGraphicsView *canvas = ui->graphicsView;
    this->scene= new GGraphicsScene(this);
    canvas->setScene(scene);

    //Test stuff
    GCommitNode *node = new GCommitNode(0);

    this->scene->addItem(node);
}

MainWindow::~MainWindow() {
    delete ui;
}



