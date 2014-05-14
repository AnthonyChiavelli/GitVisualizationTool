#include "mainwindow.h"
#include "gitapiresponse.h"
#include "gcommitnode.h"
#include "gitinitdialog.h"
#include "gitadddialog.h"
#include "gitcommitdialog.h"
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

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow) {

    ui->setupUi(this);

    // Instantiate a graphics view for this scene
    QGraphicsView *canvas = ui->graphicsView;
    this->scene= new GGraphicsScene(this);
    canvas->setDragMode(QGraphicsView::ScrollHandDrag);
    canvas->setScene(scene);

    // TODO: Update SLOT!
    connect(this, SIGNAL(refreshCanvas()), scene, SLOT(notifyRepoChange()));


}

MainWindow::~MainWindow() {
    delete ui;
}



/* Tool Bar Actions */
void MainWindow::on_actionGitInit_triggered()
{
    GitInitDialog GIdialog;
    GIdialog.path = this->repoPath;
    GIdialog.setModal(true);
    GIdialog.exec();
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
  GAdialog.path = this->repoPath;
  GAdialog.setModal(true);
  GAdialog.exec();
}

void MainWindow::on_actionGitStatus_triggered()
{

}

void MainWindow::on_actionGitCommit_triggered()
{
  GitCommitDialog GCdialog;
  GCdialog.path = this->repoPath;
  GCdialog.setModal(true);
  GCdialog.exec();
}

void MainWindow::on_actionGitBranch_triggered()
{
  GitBranchDialog GBdialog;
  GBdialog.repoPath = this->repoPath;
  GBdialog.setModal(true);
  GBdialog.exec();
}

void MainWindow::on_actionGitRevert_triggered()
{
  GitRevertDialog GRdialog;
  GRdialog.setModal(true);
  GRdialog.exec();
}

void MainWindow::on_actionGitPush_triggered()
{
  GitPushDialog GPdialog;
  GPdialog.setModal(true);
  GPdialog.exec();
}

void MainWindow::on_actionGitPull_triggered()
{
  GitPullDialog GPdialog;
  GPdialog.setModal(true);
  GPdialog.exec();
}

void MainWindow::on_actionRefresh_triggered()
{
    emit refreshCanvas();
}

void MainWindow::on_actionOpenRepo_triggered()
{
    GitOpenRepoDialog OpenRepo;
    OpenRepo.scene = this->scene;
    OpenRepo.path = this->repoPath;
    OpenRepo.setModal(true);
    OpenRepo.exec();
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
  string newMessage = ui->commitMessageTxt->toPlainText().toStdString();
  if(newMessage.empty())
    return;
  //GitApi::modifyCommit(newMessage); //or something like this
}

void MainWindow::infoWindowInit()
/* This function takes in a pointer to the GCommitNode the user selected, extracts the info, and updates the UI*/
{

 ui->ProjectLineEdit->setPlaceholderText("some project");

 ui->BranchLineEdit->setPlaceholderText("some branch");

 //ui->CommitMessageEditor->setText(selectedNode->getMessage());

// GitAPIResponse response = GitApi::gitStatus("/home/nrosato/Development/GitVisualizationTool");
// ui->GitStatusTextBrowser->setPlaceholderText(response.getMessage());


 ui->TimeLineEdit->setPlaceholderText("Time");

 ui->DateLineEdit->setPlaceholderText("Date");

 ui->AuthorLineEdit->setPlaceholderText("Author");

}

void MainWindow::updateInfoWindow(GCommitNode *selectedNode)
/* This function takes in a pointer to the GCommitNode the user selected, extracts the info, and updates the UI*/
{

 ui->ProjectLineEdit->setText("some project");

 ui->BranchLineEdit->setText("some branch");

 //ui->CommitMessageEditor->setText(selectedNode->getMessage());

// GitAPIResponse response = GitApi::gitStatus("/home/nrosato/Development/GitVisualizationTool");
// ui->GitStatusTextBrowser->setPlaceholderText(response.getMessage());


 ui->TimeLineEdit->setText(selectedNode->getDateAndTime().toString("hh:mm:ss.zzz"));

 ui->DateLineEdit->setText(selectedNode->getDateAndTime().toString("hh:mm:ss.zzz"));

 ui->AuthorLineEdit->setText(selectedNode->getAuthor().getName());

}
