#include "mainwindow.h"
#include "gitapiresponse.h"
#include "gcommitnode.h"
#include "gitinitdialog.h"
#include "gitadddialog.h"
#include "gitcommitdialog.h"
#include "gitcheckoutdialog.h"
#include "gitopenrepodialog.h"
#include "gitmergedialog.h"
#include "gitrevertdialog.h"
#include "gitbranchdialog.h"
#include "gitpushdialog.h"
#include "gitpulldialog.h"
#include "ui_mainwindow.h"
#include "gcommitnode.h"
#include "QGraphicsRectItem"
#include "ggraphicsscene.h"
#include "gitapi.h"
#include <string>
#include "QTextEdit"
#include "QString"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow) {

    ui->setupUi(this);

    // Instantiate a graphics view for this scene
    QGraphicsView *canvas = ui->graphicsView;
    this->scene= new GGraphicsScene(this);
    canvas->setDragMode(QGraphicsView::ScrollHandDrag);
    canvas->setScene(scene);

    // TODO: Update SLOT!
    connect(this, SIGNAL(refreshCanvas()), scene, SLOT(notifyRepoChange()));

    //populates InfoWindow fields with placeholder text
    infoWindowInit();
}

MainWindow::~MainWindow() {
    delete ui;
}



/* Tool Bar Actions */
void MainWindow::on_actionGitInit_triggered()
{
    GitInitDialog dialog;
    dialog.path = this->repoPath;
    dialog.setModal(true);
    dialog.exec();
    /*
    if(dialog.Accepted){
      emit refreshCanvas();
    }
    */
}


void MainWindow::on_actionGitMerge_triggered()
{
  GitMergeDialog dialog;
  dialog.path = this->repoPath;
  dialog.assembleSelector();
  dialog.setModal(true);
  dialog.exec();
  /*
  if(dialog.Accepted){
    emit refreshCanvas();
  }
  */
}

void MainWindow::on_actionGitAdd_triggered()
{
  GitAddDialog dialog;
  dialog.path = this->repoPath;
  dialog.setModal(true);
  dialog.exec();
}

void MainWindow::on_actionGitStatus_triggered()
{

}

void MainWindow::on_actionGitCommit_triggered()
{
  GitCommitDialog dialog;
  dialog.path = this->repoPath;
  dialog.setModal(true);
  dialog.exec();
  /*
  if(dialog.Accepted){
    emit refreshCanvas();
  }
  */
}

void MainWindow::on_actionGitBranch_triggered()
{
  GitBranchDialog dialog;
  dialog.path = this->repoPath;
  dialog.setModal(true);
  dialog.exec();
}

void MainWindow::on_actionGitRevert_triggered()
{
  GitRevertDialog dialog;
  dialog.setModal(true);
  dialog.exec();
  /*
  if(dialog.Accepted){
    emit refreshCanvas();
  }
  */
}

void MainWindow::on_actionGitPush_triggered()
{
  GitPushDialog dialog;
  dialog.setModal(true);
  dialog.exec();
}

void MainWindow::on_actionGitPull_triggered()
{
  GitPullDialog dialog;
  dialog.setModal(true);
  dialog.exec();
  /*
  if(dialog.Accepted){
    emit refreshCanvas();
  }
  */
}

void MainWindow::on_actionGitCheckout_triggered()
{
  GitCheckoutDialog dialog;
  dialog.path = this->repoPath;
  dialog.assembleSelector();
  dialog.setModal(true);
  dialog.exec();
}

void MainWindow::on_actionRefresh_triggered()
{
    emit refreshCanvas();
}

void MainWindow::on_actionOpenRepo_triggered()
{
    GitOpenRepoDialog dialog;
    dialog.scene = this->scene;
    dialog.path = this->repoPath;
    dialog.setModal(true);
    dialog.exec();
}

/* Menu File */

void MainWindow::on_actionOpen_triggered()
{
  on_actionOpenRepo_triggered();
}

/* Menu Git Actions*/
void MainWindow::on_actionGit_Init_triggered()
{
  on_actionGitInit_triggered();
}

void MainWindow::on_actionGit_Add_triggered()
{
  on_actionGitAdd_triggered();
}

void MainWindow::on_actionGit_Commit_triggered()
{
  on_actionGitCommit_triggered();
}

void MainWindow::on_actionGit_Merge_triggered()
{
  on_actionGitMerge_triggered();
}

void MainWindow::on_actionGit_Branch_triggered()
{
  on_actionGitBranch_triggered();
}

void MainWindow::on_actionGit_Status_triggered()
{

}

void MainWindow::on_actionGit_Revert_triggered()
{
  on_actionGitRevert_triggered();
}

void MainWindow::on_actionGit_Push_triggered()
{
  on_actionGitPush_triggered();
}

void MainWindow::on_actionGit_Pull_triggered()
{
  on_actionGitPull_triggered();
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

/* Info Panel Actions*/

void MainWindow::on_UpdateButton_clicked()
{
    //changes latest commit message. All you, Nick; I don't know the appropriate git command for that
  string newMessage = ui->commitMessageTextEdit->toPlainText().toStdString();
  if(newMessage.empty())
    return;
  //GitApi::modifyCommit(newMessage); //or something like this
}

void MainWindow::infoWindowInit()
/* This function populates the infowindow with placeholder data upon opening*/
{

 ui->ProjectLineEdit->setPlaceholderText("project");

 ui->BranchLineEdit->setPlaceholderText("branch");

 ui->PathTextEdit->setPlaceholderText("path");

 ui->commitMessageTextEdit->setPlaceholderText("Commit Info");


 ui->TimeLineEdit->setPlaceholderText("Time");

 ui->DateLineEdit->setPlaceholderText("Date");

 ui->AuthorLineEdit->setPlaceholderText("Author");

}

void MainWindow::updateInfoWindow(GCommitNode *selectedNode)
/* This function takes in a pointer to the GCommitNode the user selected, extracts the info, and updates the UI*/
{


  QString projectName= repoPath->section('/', -1);

  ui->ProjectLineEdit->setText(projectName);

  ui->PathTextEdit->setText(*(this->repoPath));


  // ui->BranchLineEdit->setText();


  QString commitTxtMessage = QString::fromStdString(selectedNode->getMessage());

     ui->commitMessageTextEdit->setText(commitTxtMessage);

     ui->TimeLineEdit->setText(selectedNode->getDateAndTime().toString("h:m ap"));

     ui->DateLineEdit->setText(selectedNode->getDateAndTime().toString("ddd MMMM d yyyy"));

     ui->AuthorLineEdit->setText(selectedNode->getAuthor().getName());

}
