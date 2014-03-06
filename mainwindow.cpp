#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gcommitnode.h"
#include "QGraphicsRectItem"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
//    GCommitNode *node = new GCommitNode(0);


//    canvas->scene()->addItem((QGraphicsItem *) node);
//    node->setPos(0,0);
//    node->setVisible(true);
//    node->update();

//    QGraphicsRectItem * fooQGRectItem = new QGraphicsRectItem(QRect(0,0,30,60));
//    fooQGRectItem->setPen(QPen(Qt::blue, 5));
//    fooQGRectItem->setBrush(Qt::blue);
//    canvas->scene()->addItem(fooQGRectItem);
//    fooQGRectItem->setPos(0,0);
//    fooQGRectItem->setZValue(5);
//    fooQGRectItem->setVisible(true);
//    fooQGRectItem->update();
}

void MainWindow::on_pushButton_2_clicked()
{

    GCommitNode *node = new GCommitNode(0);


    QGraphicsView *canvas = ui->Canvas;
    QGraphicsScene *scene= new QGraphicsScene(this);

    canvas->setScene(scene);
    QGraphicsRectItem * fooQGRectItem = new QGraphicsRectItem(QRect(0,0,30,60));
    fooQGRectItem->setPen(QPen(Qt::blue, 5));
    fooQGRectItem->setBrush(Qt::blue);
    fooQGRectItem->setFlag(QGraphicsItem::ItemIsMovable, true);
    node->setFlag(QGraphicsItem::ItemIsMovable, true);

    scene->addItem(node);
    scene->addItem(fooQGRectItem);
    //fooQGRectItem->setPos(0,0);
//    fooQGRectItem->setZValue(5);
    //fooQGRectItem->setVisible(true);
   // fooQGRectItem->update();
}
