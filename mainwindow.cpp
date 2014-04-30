#include "mainwindow.h"
#include "gitinitdialog.h"
#include "gitadddialog.h"
#include "gitcommitdialog.h"
#include "gitmergedialog.h"
#include "gitrevertdialog.h"
#include "gitbranchdialog.h"
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



/* Tool Bar Actions */
void MainWindow::on_actionGitInit_triggered()
{
    GitInitDialog GIdialog;
    GIdialog.setModal(true);
    GIdialog.exec();
    std::string path = "~/Desktop/GitTest";
    GitApi::gitInit(path);
}


void MainWindow::on_actionGitMerge_triggered()
{
  GitMergeDialog GMdialog;
  GMdialog.setModal(true);
  GMdialog.exec();
}

void MainWindow::on_actionGitAdd_triggered()
{
  GitAddDialog GAdialog;
  GAdialog.setModal(true);
  GAdialog.exec();
}

void MainWindow::on_actionGitStatus_triggered()
{

}

void MainWindow::on_actionGitCommit_triggered()
{
  GitCommitDialog GCdialog;
  GCdialog.setModal(true);
  GCdialog.exec();
}

void MainWindow::on_actionGitBranch_triggered()
{
  GitBranchDialog GBdialog;
  GBdialog.setModal(true);
  GBdialog.exec();
}

void MainWindow::on_actionGitRevert_triggered()
{
  GitRevertDialog GRdialog;
  GRdialog.setModal(true);
  GRdialog.exec();
}


/* Menu Git Actions*/
void MainWindow::on_actionGit_Init_triggered()
{

}

void MainWindow::on_actionGit_Add_triggered()
{

}

void MainWindow::on_actionGit_Commit_triggered()
{

}

void MainWindow::on_actionGit_Merge_triggered()
{

}

void MainWindow::on_actionGit_Branch_triggered()
{

}

void MainWindow::on_actionGit_Status_triggered()
{

}

void MainWindow::on_actionGit_Revert_triggered()
{

}

void MainWindow::on_actionGitPush_triggered()
{

}

void MainWindow::on_actionGitPull_triggered()
{

}

/* Menu Help Actions */
void MainWindow::on_actionCurrent_Version_triggered()
{

}

void MainWindow::on_actionAbout_us_triggered()
{

}

/* Menu VCS Actions */
void MainWindow::on_actionGitHub_triggered()
{

}

void MainWindow::on_actionBitBucket_triggered()
{

}
